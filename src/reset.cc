// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/reset.h"
#include "bungit_wrapper.cc"

  #include "../include/str_array_converter.h"
  #include "../include/repository.h"
  #include "../include/object.h"
  #include "../include/checkout_options.h"
  #include "../include/strarray.h"
  #include "../include/annotated_commit.h"
 
#include <iostream>

using namespace std;

 
  void GitReset::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

      Napi::Function object = Napi::Function::New(env, Reset);
         object.Set("reset", Napi::Function::New(env, Reset));
         object.Set("default", Napi::Function::New(env, Default));
         object.Set("fromAnnotated", Napi::Function::New(env, FromAnnotated));
  
    target.Set(
      Napi::String::New(env, "Reset"),
      object
    );
  }

 
/*
 * @param Repository repo
   * @param Object target
   * @param Number reset_type
   * @param CheckoutOptions checkout_opts
     */
Napi::Value GitReset::Reset(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Object target is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number reset_type is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ResetBaton* baton = new ResetBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const git_object * from_target = NULL;
from_target = Napi::ObjectWrap<GitObject>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->target = from_target;
// start convert_from_v8 block
  git_reset_t from_reset_type;
      from_reset_type = (git_reset_t)  (int) info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->reset_type = from_reset_type;
          if (info[3].IsNull() || info[3].IsUndefined()) {
            baton->checkout_opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitCheckoutOptions::fromJavascript(nodegitContext, info[3]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["checkout_opts"] = convertedObject;
            baton->checkout_opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ResetWorker *worker = new ResetWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitObject>("target", info[1]);
             worker->Reference("reset_type", info[2]);
            worker->Reference("checkout_opts", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitReset::ResetWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->target
          ,baton->checkout_opts
  );

  return lockMaster;
}

void GitReset::ResetWorker::Execute() {
  git_error_clear();

    int result = git_reset(
baton->repo,baton->target,baton->reset_type,baton->checkout_opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitReset::ResetWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Reset.reset"));
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


  delete baton;
}

void GitReset::ResetWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value result = env.Undefined();
          
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
        err = Napi::Error::New(env, "Method reset has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Reset.reset"));
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
        Napi::Object err = Napi::Error::New(env, "Method reset has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Reset.reset"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }


  delete baton;
}

  
/*
 * @param Repository repo
   * @param Object target
   * @param Strarray pathspecs
     */
Napi::Value GitReset::Default(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !(info[2].ToBoolean().Value())) {
    Napi::Error::New(env, "Array, String Object, or string pathspecs is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  DefaultBaton* baton = new DefaultBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const git_object * from_target = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsObject()) {
from_target = Napi::ObjectWrap<GitObject>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
  else {
    from_target = 0;
  }
// end convert_from_v8 block
          baton->target = from_target;
// start convert_from_v8 block
  const git_strarray * from_pathspecs = NULL;

  from_pathspecs = StrArrayConverter::Convert(info[2]);
// end convert_from_v8 block
          baton->pathspecs = from_pathspecs;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  DefaultWorker *worker = new DefaultWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitObject>("target", info[1]);
             worker->Reference("pathspecs", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitReset::DefaultWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->target
          ,baton->pathspecs
  );

  return lockMaster;
}

void GitReset::DefaultWorker::Execute() {
  git_error_clear();

    int result = git_reset_default(
baton->repo,baton->target,baton->pathspecs  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitReset::DefaultWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Reset.default"));
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


  delete baton;
}

void GitReset::DefaultWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value result = env.Undefined();
       
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
        err = Napi::Error::New(env, "Method default has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Reset.default"));
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
        Napi::Object err = Napi::Error::New(env, "Method default has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Reset.default"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }


  delete baton;
}

  
/*
 * @param Repository repo
   * @param AnnotatedCommit target
   * @param Number reset_type
   * @param CheckoutOptions checkout_opts
     */
Napi::Value GitReset::FromAnnotated(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "AnnotatedCommit target is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number reset_type is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FromAnnotatedBaton* baton = new FromAnnotatedBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const git_annotated_commit * from_target = NULL;
from_target = Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->target = from_target;
// start convert_from_v8 block
  git_reset_t from_reset_type;
      from_reset_type = (git_reset_t)  (int) info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->reset_type = from_reset_type;
          if (info[3].IsNull() || info[3].IsUndefined()) {
            baton->checkout_opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitCheckoutOptions::fromJavascript(nodegitContext, info[3]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["checkout_opts"] = convertedObject;
            baton->checkout_opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FromAnnotatedWorker *worker = new FromAnnotatedWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitAnnotatedCommit>("target", info[1]);
             worker->Reference("reset_type", info[2]);
            worker->Reference("checkout_opts", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitReset::FromAnnotatedWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->target
          ,baton->checkout_opts
  );

  return lockMaster;
}

void GitReset::FromAnnotatedWorker::Execute() {
  git_error_clear();

    int result = git_reset_from_annotated(
baton->repo,baton->target,baton->reset_type,baton->checkout_opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitReset::FromAnnotatedWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Reset.fromAnnotated"));
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


  delete baton;
}

void GitReset::FromAnnotatedWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value result = env.Undefined();
          
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
        err = Napi::Error::New(env, "Method fromAnnotated has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Reset.fromAnnotated"));
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
        Napi::Object err = Napi::Error::New(env, "Method fromAnnotated has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Reset.fromAnnotated"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }


  delete baton;
}

     