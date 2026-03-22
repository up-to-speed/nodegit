// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/attr.h"
#include "bungit_wrapper.cc"

  #include "../include/repository.h"
  #include "../include/attr_options.h"
 
#include <iostream>

using namespace std;

 
  void GitAttr::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

       Napi::Object object = Napi::Object::New(env);
         object.Set("addMacro", Napi::Function::New(env, AddMacro));
         object.Set("cacheFlush", Napi::Function::New(env, CacheFlush));
         object.Set("foreachExt", Napi::Function::New(env, ForeachExt));
         object.Set("get", Napi::Function::New(env, Get));
         object.Set("getExt", Napi::Function::New(env, GetExt));
         object.Set("getMany", Napi::Function::New(env, GetMany));
         object.Set("getManyExt", Napi::Function::New(env, GetManyExt));
         object.Set("value", Napi::Function::New(env, Value));
  
    target.Set(
      Napi::String::New(env, "Attr"),
      object
    );
  }

  
/*
 * @param Repository repo
   * @param String name
   * @param String values
     * @return Number  result    */
Napi::Value GitAttr::AddMacro(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String values is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name = NULL;

  std::string name = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, name.c_str(), name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_values = NULL;

  std::string values = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_values = (const char *) malloc(values.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_values, values.c_str(), values.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_values) + values.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_repo
            ,
              from_name
            ,
              from_values
    );

 int result =     git_attr_add_macro(
          from_repo
,          from_name
,          from_values
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
 * @param Repository repo
     */
Napi::Value GitAttr::CacheFlush(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_repo
    );

 int result =     git_attr_cache_flush(
          from_repo
    );

      if (result != GIT_OK) {

        if (git_error_last()->klass != GIT_ERROR_NONE) {
          Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
          return env.Undefined();
        } else {
          Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
          return env.Undefined();
        }
      } // lock master scope end
      return scope.Escape(env.Undefined());
  }
}
  
/*
 * @param Repository repo
   * @param AttrOptions opts
   * @param String path
   * @param AttrForeachCb callback
   * @param Void payload
    * @param Number callback
   */
Napi::Value GitAttr::ForeachExt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "AttrOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsFunction()) {
    Napi::Error::New(env, "AttrForeachCb callback is required.").ThrowAsJavaScriptException();
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
// start convert_from_v8 block
  git_attr_options * from_opts = NULL;
from_opts = Napi::ObjectWrap<GitAttrOptions>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->opts = from_opts;
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
          baton->path = from_path;
        if (!info[3].IsFunction()) {
          baton->callback = NULL;
          globalPayload->callback = NULL;
        }
        else {
          baton->callback = ForeachExt_callback_cppCallback;
            globalPayload->callback = new Napi::FunctionReference();
            *(globalPayload->callback) = Napi::Persistent(info[3].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ForeachExtWorker *worker = new ForeachExtWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitAttrOptions>("opts", info[1]);
             worker->Reference("path", info[2]);
            worker->Reference("payload", info[4]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitAttr::ForeachExtWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->opts
          ,baton->path
          ,baton->payload
  );

  return lockMaster;
}

void GitAttr::ForeachExtWorker::Execute() {
  git_error_clear();

    int result = git_attr_foreach_ext(
baton->repo,baton->opts,baton->path,baton->callback,baton->payload  );


      baton->result = result;

}

void GitAttr::ForeachExtWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Attr.foreachExt"));
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

void GitAttr::ForeachExtWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  baton->result);
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
        err = Napi::Error::New(env, "Method foreachExt has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Attr.foreachExt"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Attr.foreachExt"));
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


int GitAttr::ForeachExt_callback_cppCallback (
    const char * name,     const char * value,     void * payload  ) {
  ForeachExt_CallbackBaton baton(1);

    baton.name = name;
    baton.value = value;
    baton.payload = payload;
 
  return baton.ExecuteAsync(ForeachExt_callback_async, ForeachExt_callback_cancelAsync);
}

void GitAttr::ForeachExt_callback_cancelAsync(void *untypedBaton) {
  ForeachExt_CallbackBaton* baton = static_cast<ForeachExt_CallbackBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitAttr::ForeachExt_callback_async(void *untypedBaton) {
  ForeachExt_CallbackBaton* baton = static_cast<ForeachExt_CallbackBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((ForeachExt_globalPayload*)baton->payload)->callback;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         Napi::String::New(env, baton->name)
 ,          Napi::String::New(env, baton->value)
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

void GitAttr::ForeachExt_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
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
    GitAttr* instance = static_cast<GitAttr*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitAttr>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
  
/*
  * @param Repository repo
   * @param Number flags
   * @param String path
   * @param String name
    * @param String callback
   */
Napi::Value GitAttr::Get(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number flags is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  GetBaton* baton = new GetBaton();

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
  uint32_t from_flags;
      from_flags = (uint32_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->flags = from_flags;
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
          baton->path = from_path;
// start convert_from_v8 block
  const char * from_name = NULL;

  std::string name = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, name.c_str(), name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
          baton->name = from_name;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  GetWorker *worker = new GetWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("flags", info[1]);
            worker->Reference("path", info[2]);
            worker->Reference("name", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitAttr::GetWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->path
          ,baton->name
  );

  return lockMaster;
}

void GitAttr::GetWorker::Execute() {
  git_error_clear();

    int result = git_attr_get(
&baton->value_out,baton->repo,baton->flags,baton->path,baton->name  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitAttr::GetWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Attr.get"));
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

void GitAttr::GetWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
  if (baton->value_out){
       v8ConversionSlot = Napi::String::New(env, baton->value_out);
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
        err = Napi::Error::New(env, "Method get has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Attr.get"));
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
        Napi::Object err = Napi::Error::New(env, "Method get has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Attr.get"));
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
 * @param String value_out
   * @param Repository repo
   * @param AttrOptions opts
   * @param String path
   * @param String name
     * @return Number  result    */
Napi::Value GitAttr::GetExt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String value_out is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "AttrOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4 || !info[4].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char ** from_value_out = NULL;

  std::string value_out = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_value_out = (const char **) malloc(value_out.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_value_out, value_out.c_str(), value_out.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_value_out) + value_out.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  git_attr_options * from_opts = NULL;
from_opts = Napi::ObjectWrap<GitAttrOptions>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_path = (const char *) malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_path, path.c_str(), path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name = NULL;

  std::string name = info[4].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, name.c_str(), name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_value_out
            ,
              from_repo
            ,
              from_opts
            ,
              from_path
            ,
              from_name
    );

 int result =     git_attr_get_ext(
          from_value_out
,          from_repo
,          from_opts
,          from_path
,          from_name
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
  * @param Repository repo
   * @param Number flags
   * @param String path
   * @param Number num_attr
   * @param String names
    * @param Array callback
   */
Napi::Value GitAttr::GetMany(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number flags is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsNumber()) {
    Napi::Error::New(env, "Number num_attr is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4 || !info[4].IsString()) {
    Napi::Error::New(env, "String names is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  GetManyBaton* baton = new GetManyBaton();

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
  uint32_t from_flags;
      from_flags = (uint32_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->flags = from_flags;
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
          baton->path = from_path;
// start convert_from_v8 block
  size_t from_num_attr;
      from_num_attr = (size_t)   info[3].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->num_attr = from_num_attr;
// start convert_from_v8 block
  const char ** from_names = NULL;

  std::string names = info[4].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_names = (const char **) malloc(names.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_names, names.c_str(), names.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_names) + names.length()), 0, 1);
// end convert_from_v8 block
          baton->names = from_names;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  GetManyWorker *worker = new GetManyWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("flags", info[1]);
            worker->Reference("path", info[2]);
            worker->Reference("num_attr", info[3]);
            worker->Reference("names", info[4]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitAttr::GetManyWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->path
  );

  return lockMaster;
}

void GitAttr::GetManyWorker::Execute() {
  git_error_clear();

    int result = git_attr_get_many(
&baton->values_out,baton->repo,baton->flags,baton->path,baton->num_attr,baton->names  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitAttr::GetManyWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Attr.getMany"));
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

void GitAttr::GetManyWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
  if (baton->values_out){
       v8ConversionSlot = Napi::String::New(env, baton->values_out);
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
        err = Napi::Error::New(env, "Method getMany has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Attr.getMany"));
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
        Napi::Object err = Napi::Error::New(env, "Method getMany has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Attr.getMany"));
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
 * @param String values_out
   * @param Repository repo
   * @param AttrOptions opts
   * @param String path
   * @param Number num_attr
   * @param String names
     * @return Number  result    */
Napi::Value GitAttr::GetManyExt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String values_out is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "AttrOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4 || !info[4].IsNumber()) {
    Napi::Error::New(env, "Number num_attr is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 5 || !info[5].IsString()) {
    Napi::Error::New(env, "String names is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char ** from_values_out = NULL;

  std::string values_out = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_values_out = (const char **) malloc(values_out.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_values_out, values_out.c_str(), values_out.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_values_out) + values_out.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  git_attr_options * from_opts = NULL;
from_opts = Napi::ObjectWrap<GitAttrOptions>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_path = (const char *) malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_path, path.c_str(), path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_num_attr;
      from_num_attr = (size_t)   info[4].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
// start convert_from_v8 block
  const char ** from_names = NULL;

  std::string names = info[5].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_names = (const char **) malloc(names.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_names, names.c_str(), names.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_names) + names.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_values_out
            ,
              from_repo
            ,
              from_opts
            ,
              from_path
            ,
              from_names
    );

 int result =     git_attr_get_many_ext(
          from_values_out
,          from_repo
,          from_opts
,          from_path
,          from_num_attr
,          from_names
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
 * @param String attr
     * @return Number  result    */
Napi::Value GitAttr::Value(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String attr is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_attr = NULL;

  std::string attr = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_attr = (const char *) malloc(attr.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_attr, attr.c_str(), attr.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_attr) + attr.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_attr
    );

 git_attr_value_t result =     git_attr_value(
          from_attr
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
     