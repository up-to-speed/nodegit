// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/mempack.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/mempack.h"
#include "bungit_wrapper.cc"

  #include "../include/odb_backend.h"
 
#include <iostream>

using namespace std;

  GitMempack::~GitMempack() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
         }

  void GitMempack::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Mempack", {
           StaticMethod("create", &GitMempack::Create, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("reset", &GitMempack::Reset, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitMempack::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitMempack::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitMempack::Template", constructor_template);
    target.Set(Napi::String::New(env, "Mempack"), constructor_template);
  }

       // Manual binding for git_mempack_new, exposed as Mempack.create()

Napi::Value GitMempack::Create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CreateBaton *baton = new CreateBaton();
  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->out = NULL;

  Napi::FunctionReference callback;
  callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  CreateWorker *worker = new CreateWorker(baton, std::move(callback), cleanupHandles);

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMempack::CreateWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true);
  return lockMaster;
}

void GitMempack::CreateWorker::Execute() {
  git_error_clear();

  baton->error_code = git_mempack_new(&baton->out);

  if (baton->error_code != GIT_OK && git_error_last() != NULL && git_error_last()->klass != GIT_ERROR_NONE) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitMempack::CreateWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  delete baton;
}

void GitMempack::CreateWorker::HandleOKCallback() {
  Napi::Env env = Env();

  if (baton->error_code == GIT_OK) {
    if (baton->out == NULL) {
      // This should never happen if error_code == GIT_OK
      napi_value argv[1] = {Napi::Error::New(env, "Mempack creation returned OK but produced no backend.").Value()};
      callback.Call(env.Undefined(), 1, argv);
      delete baton;
      return;
    }

    Napi::Value to = GitMempack::New(env, baton->out, false);
    napi_value argv[2] = {env.Null(), to};
    callback.Call(env.Undefined(), 2, argv);
  } else if (baton->error) {
    Napi::Object err;
    if (baton->error->message) {
      err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
    } else {
      err = Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
    }
    err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
    err.Set(Napi::String::New(env, "errorFunction"),
             Napi::String::New(env, "Mempack.create"));
    napi_value argv[1] = {err};
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
      free((void *)baton->error->message);
    free((void *)baton->error);
  } else if (baton->error_code < 0) {
    Napi::Object err =
        Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errno"),
             Napi::Number::New(env, baton->error_code));
    err.Set(Napi::String::New(env, "errorFunction"),
             Napi::String::New(env, "Mempack.create"));
    napi_value argv[1] = {err};
    callback.Call(env.Undefined(), 1, argv);
  } else {
    callback.Call({});
  }

  delete baton;
}

        // Manual binding for git_mempack_reset, exposed as Mempack.prototype.reset()

Napi::Value GitMempack::Reset(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ResetBaton *baton = new ResetBaton();
  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->backend = Napi::ObjectWrap<GitMempack>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback;
  callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  ResetWorker *worker = new ResetWorker(baton, std::move(callback), cleanupHandles);

  worker->Reference<GitMempack>("backend", info.This().As<Napi::Object>());

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMempack::ResetWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->backend);
  return lockMaster;
}

void GitMempack::ResetWorker::Execute() {
  git_error_clear();

  baton->error_code = git_mempack_reset(baton->backend);

  if (baton->error_code != GIT_OK && git_error_last() != NULL && git_error_last()->klass != GIT_ERROR_NONE) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitMempack::ResetWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  delete baton;
}

void GitMempack::ResetWorker::HandleOKCallback() {
  Napi::Env env = Env();
  napi_value argv[1] = {env.Null()};
  callback.Call(env.Undefined(), 1, argv);

  delete baton;
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitMempackTraits>;
 