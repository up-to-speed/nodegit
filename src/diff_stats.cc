// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff_stats.h"
#include "bungit_wrapper.cc"

  #include "../include/buf.h"
 
#include <iostream>

using namespace std;

  GitDiffStats::~GitDiffStats() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                  }

  void GitDiffStats::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "DiffStats", {
          InstanceMethod("filesChanged", &GitDiffStats::FilesChanged, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("insertions", &GitDiffStats::Insertions, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("deletions", &GitDiffStats::Deletions, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("toBuf", &GitDiffStats::DiffStatsToBuf, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitDiffStats::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitDiffStats::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitDiffStats::Template", constructor_template);
    target.Set(Napi::String::New(env, "DiffStats"), constructor_template);
  }

  
/*
     * @return Number  result    */
Napi::Value GitDiffStats::FilesChanged(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitDiffStats>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_diff_stats_files_changed(
          Napi::ObjectWrap<GitDiffStats>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitDiffStats::Insertions(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitDiffStats>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_diff_stats_insertions(
          Napi::ObjectWrap<GitDiffStats>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitDiffStats::Deletions(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitDiffStats>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_diff_stats_deletions(
          Napi::ObjectWrap<GitDiffStats>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
    * @param Number format
   * @param Number width
    * @param Buf callback
   */
Napi::Value GitDiffStats::DiffStatsToBuf(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number format is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number width is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  DiffStatsToBufBaton* baton = new DiffStatsToBufBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->stats = Napi::ObjectWrap<GitDiffStats>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  git_diff_stats_format_t from_format;
      from_format = (git_diff_stats_format_t)  (int) info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->format = from_format;
// start convert_from_v8 block
  size_t from_width;
      from_width = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->width = from_width;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  DiffStatsToBufWorker *worker = new DiffStatsToBufWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitDiffStats>("stats", info.This().As<Napi::Object>());
           worker->Reference("format", info[0]);
            worker->Reference("width", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiffStats::DiffStatsToBufWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->stats
  );

  return lockMaster;
}

void GitDiffStats::DiffStatsToBufWorker::Execute() {
  git_error_clear();

    int result = git_diff_stats_to_buf(
baton->out,baton->stats,baton->format,baton->width  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiffStats::DiffStatsToBufWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "DiffStats.toBuf"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }

  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

        git_buf_dispose(baton->out);
        free((void *)baton->out);

  delete baton;
}

void GitDiffStats::DiffStatsToBufWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
   if (baton->out) {
    v8ConversionSlot = Napi::String::New(env, baton->out->ptr, baton->out->size);
  }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
      Napi::Value result = v8ConversionSlot;
         
    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  } else {
    if (baton->error) {
      Napi::Object err;
      if (baton->error->message) {
        err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
      } else {
        err = Napi::Error::New(env, "Method toBuf has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "DiffStats.toBuf"));
      napi_value argv[1] = {
        err
      };
      callback.Call(env.Undefined(), 1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      bool callbackFired = false;
      if (!callbackErrorHandle.IsEmpty()) {
        Napi::Value maybeError = callbackErrorHandle.Value();
        if (!maybeError.IsNull() && !maybeError.IsUndefined()) {
          napi_value argv[1] = {
            maybeError
          };
          callback.Call(env.Undefined(), 1, argv);
          callbackFired = true;
        }
      }

      if (!callbackFired) {
        Napi::Object err = Napi::Error::New(env, "Method toBuf has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "DiffStats.toBuf"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

        git_buf_dispose(baton->out);
        free((void *)baton->out);

  delete baton;
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitDiffStatsTraits>;
 