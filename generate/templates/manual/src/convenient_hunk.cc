#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
}

#include "../include/context.h"
#include "../include/functions/copy.h"
#include "../include/convenient_hunk.h"
#include "../include/diff_line.h"

using namespace std;

void HunkDataFree(HunkData *hunk) {
  while (!hunk->lines->empty()) {
    git_diff_line *line = hunk->lines->back();
    hunk->lines->pop_back();
    free((void *)line->content);
    free((void *)line);
  }
  delete hunk->lines;
  delete hunk;
}

ConvenientHunk::ConvenientHunk(const Napi::CallbackInfo& info) : Napi::ObjectWrap<ConvenientHunk>(info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsExternal()) {
    Napi::Error::New(env, "A new ConvenientHunk cannot be instantiated.").ThrowAsJavaScriptException();
    return;
  }

  this->hunk = static_cast<HunkData *>(info[0].As<Napi::External<void>>().Data());
}

ConvenientHunk::~ConvenientHunk() {
  HunkDataFree(this->hunk);
}

void ConvenientHunk::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
  Napi::Env env = target.Env();

  Napi::Function constructor_template = DefineClass(env, "ConvenientHunk", {
    InstanceMethod("size", &ConvenientHunk::Size, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    InstanceMethod("lines", &ConvenientHunk::Lines, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    InstanceMethod("oldStart", &ConvenientHunk::OldStart, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    InstanceMethod("oldLines", &ConvenientHunk::OldLines, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    InstanceMethod("newStart", &ConvenientHunk::NewStart, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    InstanceMethod("newLines", &ConvenientHunk::NewLines, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    InstanceMethod("headerLen", &ConvenientHunk::HeaderLen, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    InstanceMethod("header", &ConvenientHunk::Header, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
  });

  nodegitContext->SaveToPersistent("ConvenientHunk::Template", constructor_template);
  target.Set("ConvenientHunk", constructor_template);
}

Napi::Value ConvenientHunk::New(void *raw) {
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  Napi::Function constructor_template = nodegitContext->GetFromPersistent("ConvenientHunk::Template").As<Napi::Function>();
  Napi::Env env = constructor_template.Env();
  Napi::External<void> ext = Napi::External<void>::New(env, raw);
  return constructor_template.New({ ext });
}

HunkData *ConvenientHunk::GetValue() {
  return this->hunk;
}

size_t ConvenientHunk::GetSize() {
  return this->hunk->numLines;
}

Napi::Value ConvenientHunk::Size(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Number::New(env, ConvenientHunk::Unwrap(info.This().As<Napi::Object>())->GetSize());
}

Napi::Value ConvenientHunk::Lines(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() == 0 || !info[0].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  LinesBaton *baton = new LinesBaton();

  baton->hunk = ConvenientHunk::Unwrap(info.This().As<Napi::Object>())->GetValue();
  baton->lines = new std::vector<git_diff_line *>;
  baton->lines->reserve(baton->hunk->numLines);

  Napi::FunctionReference callback;
  callback.Reset(info[0].As<Napi::Function>(), 1);
  LinesWorker *worker = new LinesWorker(baton, std::move(callback));

  worker->Reference<ConvenientHunk>("hunk", info.This().As<Napi::Object>());

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster ConvenientHunk::LinesWorker::AcquireLocks() {
  return nodegit::LockMaster(true);
}

void ConvenientHunk::LinesWorker::Execute() {
  for (unsigned int i = 0; i < baton->hunk->numLines; ++i) {
    git_diff_line *storeLine = (git_diff_line *)malloc(sizeof(git_diff_line));
    storeLine->origin = baton->hunk->lines->at(i)->origin;
    storeLine->old_lineno = baton->hunk->lines->at(i)->old_lineno;
    storeLine->new_lineno = baton->hunk->lines->at(i)->new_lineno;
    storeLine->num_lines = baton->hunk->lines->at(i)->num_lines;
    storeLine->content_len = baton->hunk->lines->at(i)->content_len;
    storeLine->content_offset = baton->hunk->lines->at(i)->content_offset;
    storeLine->content = strdup(baton->hunk->lines->at(i)->content);
    baton->lines->push_back(storeLine);
  }
}

void ConvenientHunk::LinesWorker::HandleErrorCallback() {
  while (!baton->lines->empty()) {
    free(baton->lines->back());
    baton->lines->pop_back();
  }

  delete baton->lines;
}

void ConvenientHunk::LinesWorker::HandleOKCallback() {
  unsigned int size = baton->lines->size();
  Napi::Env env = Env();
  Napi::Array result = Napi::Array::New(env, size);

  for(unsigned int i = 0; i < size; ++i) {
    result.Set(i, GitDiffLine::New(env, baton->lines->at(i), true));
  }

  delete baton->lines;

  napi_value argv[2] = {
    env.Null(),
    result
  };
  callback.Call(env.Undefined(), 2, argv);

  delete baton;
}

Napi::Value ConvenientHunk::OldStart(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int old_start = ConvenientHunk::Unwrap(info.This().As<Napi::Object>())->GetValue()->hunk.old_start;
  return Napi::Number::New(env, old_start);
}


Napi::Value ConvenientHunk::OldLines(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int old_lines = ConvenientHunk::Unwrap(info.This().As<Napi::Object>())->GetValue()->hunk.old_lines;
  return Napi::Number::New(env, old_lines);
}

Napi::Value ConvenientHunk::NewStart(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int new_start = ConvenientHunk::Unwrap(info.This().As<Napi::Object>())->GetValue()->hunk.new_start;
  return Napi::Number::New(env, new_start);
}

Napi::Value ConvenientHunk::NewLines(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int new_lines = ConvenientHunk::Unwrap(info.This().As<Napi::Object>())->GetValue()->hunk.new_lines;
  return Napi::Number::New(env, new_lines);
}

Napi::Value ConvenientHunk::HeaderLen(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  size_t header_len = ConvenientHunk::Unwrap(info.This().As<Napi::Object>())->GetValue()->hunk.header_len;
  return Napi::Number::New(env, header_len);
}

Napi::Value ConvenientHunk::Header(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  char *header = ConvenientHunk::Unwrap(info.This().As<Napi::Object>())->GetValue()->hunk.header;
  if (header) {
    return Napi::String::New(env, header);
  } else {
    return env.Null();
  }
}

void ConvenientHunk::Reference() {
  Ref();
}

void ConvenientHunk::Unreference() {
  Unref();
}
