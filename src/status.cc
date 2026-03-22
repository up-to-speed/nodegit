// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/diff.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/status.h"
#include "bungit_wrapper.cc"

  #include "../include/status_list.h"
  #include "../include/status_entry.h"
  #include "../include/repository.h"
  #include "../include/status_options.h"
 
#include <iostream>

using namespace std;

 
  void GitStatus::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

       Napi::Object object = Napi::Object::New(env);
         object.Set("byIndex", Napi::Function::New(env, Byindex));
         object.Set("file", Napi::Function::New(env, File));
         object.Set("foreach", Napi::Function::New(env, Foreach));
         object.Set("foreachExt", Napi::Function::New(env, ForeachExt));
         object.Set("shouldIgnore", Napi::Function::New(env, ShouldIgnore));
  
    target.Set(
      Napi::String::New(env, "Status"),
      object
    );
  }

  
/*
 * @param StatusList statuslist
   * @param Number idx
     * @return StatusEntry  result    */
Napi::Value GitStatus::Byindex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "StatusList statuslist is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number idx is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_status_list * from_statuslist = NULL;
from_statuslist = Napi::ObjectWrap<GitStatusList>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_idx;
      from_idx = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_statuslist
    );

 const git_status_entry * result =     git_status_byindex(
          from_statuslist
,          from_idx
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
             owners.Set(Napi::Number::New(env, owners.Length()), info[0].As<Napi::Object>());
             v8ConversionSlot = GitStatusEntry::New(
        env,
        result,
        false
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
  * @param Repository repo
   * @param String path
    * @param Number callback
   */
Napi::Value GitStatus::File(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FileBaton* baton = new FileBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->status_flags = (unsigned int *)malloc(sizeof(unsigned int ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_path = (const char *) malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_path, path.c_str(), path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
// end convert_from_v8 block
          baton->path = from_path;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FileWorker *worker = new FileWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("path", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitStatus::FileWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->status_flags
          ,baton->repo
          ,baton->path
  );

  return lockMaster;
}

void GitStatus::FileWorker::Execute() {
  git_error_clear();

    int result = git_status_file(
baton->status_flags,baton->repo,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitStatus::FileWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Status.file"));
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

void GitStatus::FileWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->status_flags);
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
        err = Napi::Error::New(env, "Method file has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Status.file"));
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
        Napi::Object err = Napi::Error::New(env, "Method file has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Status.file"));
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
   * @param StatusCb callback
   * @param Void payload
     */
Napi::Value GitStatus::Foreach(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsFunction()) {
    Napi::Error::New(env, "StatusCb callback is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ForeachBaton* baton = new ForeachBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

      Foreach_globalPayload* globalPayload = new Foreach_globalPayload;

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
        if (!info[1].IsFunction()) {
          baton->callback = NULL;
          globalPayload->callback = NULL;
        }
        else {
          baton->callback = Foreach_callback_cppCallback;
            globalPayload->callback = new Napi::FunctionReference();
            *(globalPayload->callback) = Napi::Persistent(info[1].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ForeachWorker *worker = new ForeachWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("payload", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitStatus::ForeachWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->payload
  );

  return lockMaster;
}

void GitStatus::ForeachWorker::Execute() {
  git_error_clear();

    int result = git_status_foreach(
baton->repo,baton->callback,baton->payload  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitStatus::ForeachWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Status.foreach"));
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

      delete (Foreach_globalPayload*)baton->payload;

  delete baton;
}

void GitStatus::ForeachWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method foreach has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Status.foreach"));
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
        Napi::Object err = Napi::Error::New(env, "Method foreach has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Status.foreach"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      delete (Foreach_globalPayload*)baton->payload;

  delete baton;
}


int GitStatus::Foreach_callback_cppCallback (
    const char * path,     unsigned int status_flags,     void * payload  ) {
  Foreach_CallbackBaton baton(0);

    baton.path = path;
    baton.status_flags = status_flags;
    baton.payload = payload;
 
  return baton.ExecuteAsync(Foreach_callback_async, Foreach_callback_cancelAsync);
}

void GitStatus::Foreach_callback_cancelAsync(void *untypedBaton) {
  Foreach_CallbackBaton* baton = static_cast<Foreach_CallbackBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitStatus::Foreach_callback_async(void *untypedBaton) {
  Foreach_CallbackBaton* baton = static_cast<Foreach_CallbackBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((Foreach_globalPayload*)baton->payload)->callback;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         Napi::String::New(env, baton->path)
 ,           Napi::Number::New(env, baton->status_flags)
    };

  Napi::Value result;
  bool callSucceeded = false;
  try {
    napi_value napi_argv[2];
    for (int _i = 0; _i < 2; _i++) {
      napi_argv[_i] = argv[_i];
    }
    result = callback->Call(env.Undefined(), 2, napi_argv);
    callSucceeded = !result.IsEmpty();
  } catch (const Napi::Error& e) {
    // exception occurred — result is invalid, don't forward
  }

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, Foreach_callback_promiseCompleted)) {
    return;
  }

    if (result.IsUndefined() || result.IsNull()) {
      baton->result = baton->defaultResult;
    }
    else if (!result.IsNull() && !result.IsUndefined()) {
       if (result.IsNumber()) {
        baton->result = result.As<Napi::Number>().Int32Value();
      }
      else {
        baton->result = baton->defaultResult;
      }
     }
    else {
      baton->result = baton->defaultResult;
    }
 
  baton->Done();
}

void GitStatus::Foreach_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  Foreach_CallbackBaton* baton = static_cast<Foreach_CallbackBaton*>(_baton);

  if (isFulfilled) {
      if (result.IsUndefined() || result.IsNull()) {
        baton->result = baton->defaultResult;
      }
      else if (!result.IsNull() && !result.IsUndefined()) {
         if (result.IsNumber()) {
          baton->result = result.As<Napi::Number>().Int32Value();
        }
        else {
          baton->result = baton->defaultResult;
        }
       }
      else {
        baton->result = baton->defaultResult;
      }
   }
  else {
    // promise was rejected
    GitStatus* instance = static_cast<GitStatus*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitStatus>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
  
/*
 * @param Repository repo
   * @param StatusOptions opts
   * @param StatusCb callback
   * @param Void payload
     */
Napi::Value GitStatus::ForeachExt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "StatusOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsFunction()) {
    Napi::Error::New(env, "StatusCb callback is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ForeachExtBaton* baton = new ForeachExtBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

      ForeachExt_globalPayload* globalPayload = new ForeachExt_globalPayload;

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
            {
            auto conversionResult = ConfigurableGitStatusOptions::fromJavascript(nodegitContext, info[1]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
         if (!info[2].IsFunction()) {
          baton->callback = NULL;
          globalPayload->callback = NULL;
        }
        else {
          baton->callback = ForeachExt_callback_cppCallback;
            globalPayload->callback = new Napi::FunctionReference();
            *(globalPayload->callback) = Napi::Persistent(info[2].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ForeachExtWorker *worker = new ForeachExtWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("opts", info[1]);
            worker->Reference("payload", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitStatus::ForeachExtWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->opts
          ,baton->payload
  );

  return lockMaster;
}

void GitStatus::ForeachExtWorker::Execute() {
  git_error_clear();

    int result = git_status_foreach_ext(
baton->repo,baton->opts,baton->callback,baton->payload  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitStatus::ForeachExtWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Status.foreachExt"));
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

      delete (ForeachExt_globalPayload*)baton->payload;

  delete baton;
}

void GitStatus::ForeachExtWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method foreachExt has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Status.foreachExt"));
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
        Napi::Object err = Napi::Error::New(env, "Method foreachExt has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Status.foreachExt"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      delete (ForeachExt_globalPayload*)baton->payload;

  delete baton;
}


int GitStatus::ForeachExt_callback_cppCallback (
    const char * path,     unsigned int status_flags,     void * payload  ) {
  ForeachExt_CallbackBaton baton(0);

    baton.path = path;
    baton.status_flags = status_flags;
    baton.payload = payload;
 
  return baton.ExecuteAsync(ForeachExt_callback_async, ForeachExt_callback_cancelAsync);
}

void GitStatus::ForeachExt_callback_cancelAsync(void *untypedBaton) {
  ForeachExt_CallbackBaton* baton = static_cast<ForeachExt_CallbackBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitStatus::ForeachExt_callback_async(void *untypedBaton) {
  ForeachExt_CallbackBaton* baton = static_cast<ForeachExt_CallbackBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((ForeachExt_globalPayload*)baton->payload)->callback;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         Napi::String::New(env, baton->path)
 ,           Napi::Number::New(env, baton->status_flags)
    };

  Napi::Value result;
  bool callSucceeded = false;
  try {
    napi_value napi_argv[2];
    for (int _i = 0; _i < 2; _i++) {
      napi_argv[_i] = argv[_i];
    }
    result = callback->Call(env.Undefined(), 2, napi_argv);
    callSucceeded = !result.IsEmpty();
  } catch (const Napi::Error& e) {
    // exception occurred — result is invalid, don't forward
  }

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ForeachExt_callback_promiseCompleted)) {
    return;
  }

    if (result.IsUndefined() || result.IsNull()) {
      baton->result = baton->defaultResult;
    }
    else if (!result.IsNull() && !result.IsUndefined()) {
       if (result.IsNumber()) {
        baton->result = result.As<Napi::Number>().Int32Value();
      }
      else {
        baton->result = baton->defaultResult;
      }
     }
    else {
      baton->result = baton->defaultResult;
    }
 
  baton->Done();
}

void GitStatus::ForeachExt_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  ForeachExt_CallbackBaton* baton = static_cast<ForeachExt_CallbackBaton*>(_baton);

  if (isFulfilled) {
      if (result.IsUndefined() || result.IsNull()) {
        baton->result = baton->defaultResult;
      }
      else if (!result.IsNull() && !result.IsUndefined()) {
         if (result.IsNumber()) {
          baton->result = result.As<Napi::Number>().Int32Value();
        }
        else {
          baton->result = baton->defaultResult;
        }
       }
      else {
        baton->result = baton->defaultResult;
      }
   }
  else {
    // promise was rejected
    GitStatus* instance = static_cast<GitStatus*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitStatus>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
   
/*
 * @param Number ignored
   * @param Repository repo
   * @param String path
     * @return Number  result    */
Napi::Value GitStatus::ShouldIgnore(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number ignored is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  int * from_ignored = NULL;
      *from_ignored = (int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_path = (const char *) malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_path, path.c_str(), path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_ignored
            ,
              from_repo
            ,
              from_path
    );

 int result =     git_status_should_ignore(
          from_ignored
,          from_repo
,          from_path
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
     