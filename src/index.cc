// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/index.h"
#include "bungit_wrapper.cc"

  #include "../include/str_array_converter.h"
  #include "../include/index_entry.h"
  #include "../include/strarray.h"
  #include "../include/oid.h"
  #include "../include/tree.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;

  GitIndex::~GitIndex() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                                                 }

  void GitIndex::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Index", {
          InstanceMethod("add", &GitIndex::Add, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("addAll", &GitIndex::AddAll, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("addByPath", &GitIndex::AddBypath, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("caps", &GitIndex::Caps, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("checksum", &GitIndex::Checksum, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("clear", &GitIndex::Clear, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("conflictAdd", &GitIndex::ConflictAdd, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("conflictCleanup", &GitIndex::ConflictCleanup, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("conflictGet", &GitIndex::ConflictGet, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("conflictRemove", &GitIndex::ConflictRemove, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("entryIsConflict", &GitIndex::EntryIsConflict, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("entryStage", &GitIndex::EntryStage, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("entryCount", &GitIndex::Entrycount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("find", &GitIndex::Find, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("findPrefix", &GitIndex::FindPrefix, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getByIndex", &GitIndex::GetByindex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getByPath", &GitIndex::GetBypath, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("hasConflicts", &GitIndex::HasConflicts, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("create", &GitIndex::Create, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("open", &GitIndex::Open, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("path", &GitIndex::Path, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("read", &GitIndex::Read, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("readTree", &GitIndex::ReadTree, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("remove", &GitIndex::Remove, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("removeAll", &GitIndex::RemoveAll, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("removeByPath", &GitIndex::RemoveBypath, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("removeDirectory", &GitIndex::RemoveDirectory, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setCaps", &GitIndex::SetCaps, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setVersion", &GitIndex::SetVersion, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("updateAll", &GitIndex::UpdateAll, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("version", &GitIndex::Version, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("write", &GitIndex::Write, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("writeTree", &GitIndex::WriteTree, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("writeTreeTo", &GitIndex::WriteTreeTo, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitIndex::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitIndex::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitIndex::Template", constructor_template);
    target.Set(Napi::String::New(env, "Index"), constructor_template);
  }

 
/*
   * @param IndexEntry source_entry
     */
Napi::Value GitIndex::Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "IndexEntry source_entry is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AddBaton* baton = new AddBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
            {
            auto conversionResult = ConfigurableGitIndexEntry::fromJavascript(nodegitContext, info[0]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["source_entry"] = convertedObject;
            baton->source_entry = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  AddWorker *worker = new AddWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("source_entry", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::AddWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->source_entry
  );

  return lockMaster;
}

void GitIndex::AddWorker::Execute() {
  git_error_clear();

    int result = git_index_add(
baton->index,baton->source_entry  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::AddWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.add"));
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

void GitIndex::AddWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method add has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.add"));
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
        Napi::Object err = Napi::Error::New(env, "Method add has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.add"));
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
   * @param Strarray pathspec
   * @param Number flags
   * @param IndexMatchedPathCb callback
   * @param Void payload
     */
Napi::Value GitIndex::AddAll(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AddAllBaton* baton = new AddAllBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

      AddAll_globalPayload* globalPayload = new AddAll_globalPayload;

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_strarray * from_pathspec = NULL;

  from_pathspec = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
          baton->pathspec = from_pathspec;
// start convert_from_v8 block
  unsigned int from_flags;
    if ((info.Length() - 1) > 1 && info[1].IsNumber()) {
      from_flags = (unsigned int)   info[1].As<Napi::Number>().DoubleValue ();
  }
  else {
    from_flags = 0;
  }
// end convert_from_v8 block
          baton->flags = from_flags;
        if (!info[2].IsFunction()) {
          baton->callback = NULL;
          globalPayload->callback = NULL;
        }
        else {
          baton->callback = AddAll_callback_cppCallback;
            globalPayload->callback = new Napi::FunctionReference();
            *(globalPayload->callback) = Napi::Persistent(info[2].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  AddAllWorker *worker = new AddAllWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("pathspec", info[0]);
            worker->Reference("flags", info[1]);
            worker->Reference("payload", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::AddAllWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->pathspec
          ,baton->payload
  );

  return lockMaster;
}

void GitIndex::AddAllWorker::Execute() {
  git_error_clear();

    int result = git_index_add_all(
baton->index,baton->pathspec,baton->flags,baton->callback,baton->payload  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::AddAllWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.addAll"));
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

      delete (AddAll_globalPayload*)baton->payload;

  delete baton;
}

void GitIndex::AddAllWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method addAll has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.addAll"));
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
        Napi::Object err = Napi::Error::New(env, "Method addAll has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.addAll"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      delete (AddAll_globalPayload*)baton->payload;

  delete baton;
}


int GitIndex::AddAll_callback_cppCallback (
    const char * path,     const char * matched_pathspec,     void * payload  ) {
  AddAll_CallbackBaton baton(1);

    baton.path = path;
    baton.matched_pathspec = matched_pathspec;
    baton.payload = payload;
 
  return baton.ExecuteAsync(AddAll_callback_async, AddAll_callback_cancelAsync);
}

void GitIndex::AddAll_callback_cancelAsync(void *untypedBaton) {
  AddAll_CallbackBaton* baton = static_cast<AddAll_CallbackBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitIndex::AddAll_callback_async(void *untypedBaton) {
  AddAll_CallbackBaton* baton = static_cast<AddAll_CallbackBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((AddAll_globalPayload*)baton->payload)->callback;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         Napi::String::New(env, baton->path)
 ,          Napi::String::New(env, baton->matched_pathspec)
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

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, AddAll_callback_promiseCompleted)) {
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

void GitIndex::AddAll_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  AddAll_CallbackBaton* baton = static_cast<AddAll_CallbackBaton*>(_baton);

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
    GitIndex* instance = static_cast<GitIndex*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitIndex>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
  
/*
   * @param String path
     */
Napi::Value GitIndex::AddBypath(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AddBypathBaton* baton = new AddBypathBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
  AddBypathWorker *worker = new AddBypathWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("path", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::AddBypathWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->path
  );

  return lockMaster;
}

void GitIndex::AddBypathWorker::Execute() {
  git_error_clear();

    int result = git_index_add_bypath(
baton->index,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::AddBypathWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.addByPath"));
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

void GitIndex::AddBypathWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method addByPath has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.addByPath"));
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
        Napi::Object err = Napi::Error::New(env, "Method addByPath has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.addByPath"));
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
     * @return Number  result    */
Napi::Value GitIndex::Caps(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_index_caps(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Oid  result    */
Napi::Value GitIndex::Checksum(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_index_checksum(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        result,
        true
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
     */
Napi::Value GitIndex::Clear(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ClearBaton* baton = new ClearBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ClearWorker *worker = new ClearWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::ClearWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
  );

  return lockMaster;
}

void GitIndex::ClearWorker::Execute() {
  git_error_clear();

    int result = git_index_clear(
baton->index  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::ClearWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.clear"));
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

void GitIndex::ClearWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method clear has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.clear"));
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
        Napi::Object err = Napi::Error::New(env, "Method clear has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.clear"));
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
   * @param IndexEntry ancestor_entry
   * @param IndexEntry our_entry
   * @param IndexEntry their_entry
     */
Napi::Value GitIndex::ConflictAdd(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ConflictAddBaton* baton = new ConflictAddBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
          if (info[0].IsNull() || info[0].IsUndefined()) {
            baton->ancestor_entry = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitIndexEntry::fromJavascript(nodegitContext, info[0]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["ancestor_entry"] = convertedObject;
            baton->ancestor_entry = convertedObject->GetValue();
          }
           if (info[1].IsNull() || info[1].IsUndefined()) {
            baton->our_entry = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitIndexEntry::fromJavascript(nodegitContext, info[1]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["our_entry"] = convertedObject;
            baton->our_entry = convertedObject->GetValue();
          }
           if (info[2].IsNull() || info[2].IsUndefined()) {
            baton->their_entry = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitIndexEntry::fromJavascript(nodegitContext, info[2]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["their_entry"] = convertedObject;
            baton->their_entry = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ConflictAddWorker *worker = new ConflictAddWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("ancestor_entry", info[0]);
            worker->Reference("our_entry", info[1]);
            worker->Reference("their_entry", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::ConflictAddWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->ancestor_entry
          ,baton->our_entry
          ,baton->their_entry
  );

  return lockMaster;
}

void GitIndex::ConflictAddWorker::Execute() {
  git_error_clear();

    int result = git_index_conflict_add(
baton->index,baton->ancestor_entry,baton->our_entry,baton->their_entry  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::ConflictAddWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictAdd"));
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

void GitIndex::ConflictAddWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method conflictAdd has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictAdd"));
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
        Napi::Object err = Napi::Error::New(env, "Method conflictAdd has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictAdd"));
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
     */
Napi::Value GitIndex::ConflictCleanup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ConflictCleanupBaton* baton = new ConflictCleanupBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ConflictCleanupWorker *worker = new ConflictCleanupWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::ConflictCleanupWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
  );

  return lockMaster;
}

void GitIndex::ConflictCleanupWorker::Execute() {
  git_error_clear();

    int result = git_index_conflict_cleanup(
baton->index  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::ConflictCleanupWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictCleanup"));
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

void GitIndex::ConflictCleanupWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method conflictCleanup has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictCleanup"));
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
        Napi::Object err = Napi::Error::New(env, "Method conflictCleanup has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictCleanup"));
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
      * @param String path
    * @param IndexEntry callback
  * @param IndexEntry callback
  * @param IndexEntry callback
   */
Napi::Value GitIndex::ConflictGet(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ConflictGetBaton* baton = new ConflictGetBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
  ConflictGetWorker *worker = new ConflictGetWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("path", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::ConflictGetWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->path
  );

  return lockMaster;
}

void GitIndex::ConflictGetWorker::Execute() {
  git_error_clear();

    int result = git_index_conflict_get(
&baton->ancestor_out,&baton->our_out,&baton->their_out,baton->index,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::ConflictGetWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictGet"));
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

void GitIndex::ConflictGetWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
      Napi::Object result = Napi::Object::New(env);
// start convert_to_v8 block
    if (baton->ancestor_out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("index").As<Napi::Object>());
             v8ConversionSlot = GitIndexEntry::New(
        env,
        baton->ancestor_out,
        false
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "ancestor_out"), v8ConversionSlot);
// start convert_to_v8 block
    if (baton->our_out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("index").As<Napi::Object>());
             v8ConversionSlot = GitIndexEntry::New(
        env,
        baton->our_out,
        false
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "our_out"), v8ConversionSlot);
// start convert_to_v8 block
    if (baton->their_out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("index").As<Napi::Object>());
             v8ConversionSlot = GitIndexEntry::New(
        env,
        baton->their_out,
        false
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "their_out"), v8ConversionSlot);
              
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
        err = Napi::Error::New(env, "Method conflictGet has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictGet"));
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
        Napi::Object err = Napi::Error::New(env, "Method conflictGet has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictGet"));
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
   * @param String path
     */
Napi::Value GitIndex::ConflictRemove(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ConflictRemoveBaton* baton = new ConflictRemoveBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
  ConflictRemoveWorker *worker = new ConflictRemoveWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("path", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::ConflictRemoveWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->path
  );

  return lockMaster;
}

void GitIndex::ConflictRemoveWorker::Execute() {
  git_error_clear();

    int result = git_index_conflict_remove(
baton->index,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::ConflictRemoveWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictRemove"));
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

void GitIndex::ConflictRemoveWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method conflictRemove has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictRemove"));
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
        Napi::Object err = Napi::Error::New(env, "Method conflictRemove has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.conflictRemove"));
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
 * @param IndexEntry entry
     * @return Number  result    */
Napi::Value GitIndex::EntryIsConflict(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "IndexEntry entry is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const git_index_entry * from_entry = NULL;
from_entry = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_entry
    );

 int result =     git_index_entry_is_conflict(
          from_entry
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
 * @param IndexEntry entry
     * @return Number  result    */
Napi::Value GitIndex::EntryStage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "IndexEntry entry is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const git_index_entry * from_entry = NULL;
from_entry = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_entry
    );

 int result =     git_index_entry_stage(
          from_entry
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
Napi::Value GitIndex::Entrycount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_index_entrycount(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
    * @param String path
    * @param Number callback
   */
Napi::Value GitIndex::Find(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FindBaton* baton = new FindBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->at_pos = (size_t *)malloc(sizeof(size_t ));
        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
  FindWorker *worker = new FindWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("path", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::FindWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->at_pos
          ,baton->index
          ,baton->path
  );

  return lockMaster;
}

void GitIndex::FindWorker::Execute() {
  git_error_clear();

    int result = git_index_find(
baton->at_pos,baton->index,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::FindWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.find"));
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

void GitIndex::FindWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->at_pos);
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
        err = Napi::Error::New(env, "Method find has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.find"));
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
        Napi::Object err = Napi::Error::New(env, "Method find has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.find"));
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
    * @param String prefix
    * @param Number callback
   */
Napi::Value GitIndex::FindPrefix(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String prefix is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FindPrefixBaton* baton = new FindPrefixBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->at_pos = (size_t *)malloc(sizeof(size_t ));
        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_prefix = NULL;

  std::string prefix = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_prefix = (const char *) malloc(prefix.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_prefix, prefix.c_str(), prefix.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_prefix) + prefix.length()), 0, 1);
// end convert_from_v8 block
          baton->prefix = from_prefix;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FindPrefixWorker *worker = new FindPrefixWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("prefix", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::FindPrefixWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->at_pos
          ,baton->index
          ,baton->prefix
  );

  return lockMaster;
}

void GitIndex::FindPrefixWorker::Execute() {
  git_error_clear();

    int result = git_index_find_prefix(
baton->at_pos,baton->index,baton->prefix  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::FindPrefixWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.findPrefix"));
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

void GitIndex::FindPrefixWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->at_pos);
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
        err = Napi::Error::New(env, "Method findPrefix has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.findPrefix"));
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
        Napi::Object err = Napi::Error::New(env, "Method findPrefix has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.findPrefix"));
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
   * @param Number n
     * @return IndexEntry  result    */
Napi::Value GitIndex::GetByindex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number n is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_n;
      from_n = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_index_entry * result =     git_index_get_byindex(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_n
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitIndexEntry::New(
        env,
        result,
        false
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
   * @param String path
   * @param Number stage
     * @return IndexEntry  result    */
Napi::Value GitIndex::GetBypath(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
  int from_stage;
    if ((info.Length() - 1) > 1 && info[1].IsNumber()) {
      from_stage = (int)   info[1].As<Napi::Number>().DoubleValue ();
  }
  else {
    from_stage = 0;
  }
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_path
    );

 const git_index_entry * result =     git_index_get_bypath(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_path
,          from_stage
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitIndexEntry::New(
        env,
        result,
        false
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
     * @return Number  result    */
Napi::Value GitIndex::HasConflicts(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_index_has_conflicts(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
   * @param Index callback
   */
Napi::Value GitIndex::Create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CreateBaton* baton = new CreateBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;


  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CreateWorker *worker = new CreateWorker(baton, std::move(callback), cleanupHandles);


  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::CreateWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
  );

  return lockMaster;
}

void GitIndex::CreateWorker::Execute() {
  git_error_clear();

    int result = git_index_new(
&baton->index_out  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::CreateWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.create"));
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

      git_index_free(baton->index_out);

  delete baton;
}

void GitIndex::CreateWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->index_out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
          owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_index_owner(baton->index_out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitIndex::New(
        env,
        baton->index_out,
        true
          , owners
       );
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
        err = Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.create"));
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
        Napi::Object err = Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.create"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_index_free(baton->index_out);
  }


  delete baton;
}

  
/*
  * @param String index_path
    * @param Index callback
   */
Napi::Value GitIndex::Open(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String index_path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  OpenBaton* baton = new OpenBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const char * from_index_path = NULL;

  std::string index_path = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_index_path = (const char *) malloc(index_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_index_path, index_path.c_str(), index_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_index_path) + index_path.length()), 0, 1);
// end convert_from_v8 block
          baton->index_path = from_index_path;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  OpenWorker *worker = new OpenWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("index_path", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::OpenWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index_path
  );

  return lockMaster;
}

void GitIndex::OpenWorker::Execute() {
  git_error_clear();

    int result = git_index_open(
&baton->index_out,baton->index_path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::OpenWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.open"));
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

      git_index_free(baton->index_out);

  delete baton;
}

void GitIndex::OpenWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->index_out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
          owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_index_owner(baton->index_out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitIndex::New(
        env,
        baton->index_out,
        true
          , owners
       );
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
        err = Napi::Error::New(env, "Method open has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.open"));
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
        Napi::Object err = Napi::Error::New(env, "Method open has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.open"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_index_free(baton->index_out);
  }


  delete baton;
}

   
/*
     * @return String  result    */
Napi::Value GitIndex::Path(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_index_path(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
  if (result){
       v8ConversionSlot = Napi::String::New(env, result);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
   * @param Number force
     */
Napi::Value GitIndex::Read(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ReadBaton* baton = new ReadBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  int from_force;
    if ((info.Length() - 1) > 0 && info[0].IsNumber()) {
      from_force = (int)   info[0].As<Napi::Number>().DoubleValue ();
  }
  else {
    from_force = 0;
  }
// end convert_from_v8 block
          baton->force = from_force;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ReadWorker *worker = new ReadWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("force", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::ReadWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
  );

  return lockMaster;
}

void GitIndex::ReadWorker::Execute() {
  git_error_clear();

    int result = git_index_read(
baton->index,baton->force  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::ReadWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.read"));
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

void GitIndex::ReadWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method read has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.read"));
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
        Napi::Object err = Napi::Error::New(env, "Method read has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.read"));
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
   * @param Tree tree
     */
Napi::Value GitIndex::ReadTree(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Tree tree is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ReadTreeBaton* baton = new ReadTreeBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_tree * from_tree = NULL;
from_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->tree = from_tree;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ReadTreeWorker *worker = new ReadTreeWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
             worker->Reference<GitTree>("tree", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::ReadTreeWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->tree
  );

  return lockMaster;
}

void GitIndex::ReadTreeWorker::Execute() {
  git_error_clear();

    int result = git_index_read_tree(
baton->index,baton->tree  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::ReadTreeWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.readTree"));
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

void GitIndex::ReadTreeWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method readTree has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.readTree"));
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
        Napi::Object err = Napi::Error::New(env, "Method readTree has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.readTree"));
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
   * @param String path
   * @param Number stage
     */
Napi::Value GitIndex::Remove(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number stage is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  RemoveBaton* baton = new RemoveBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
  int from_stage;
      from_stage = (int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->stage = from_stage;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  RemoveWorker *worker = new RemoveWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("path", info[0]);
            worker->Reference("stage", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::RemoveWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->path
  );

  return lockMaster;
}

void GitIndex::RemoveWorker::Execute() {
  git_error_clear();

    int result = git_index_remove(
baton->index,baton->path,baton->stage  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::RemoveWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.remove"));
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

void GitIndex::RemoveWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method remove has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.remove"));
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
        Napi::Object err = Napi::Error::New(env, "Method remove has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.remove"));
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
   * @param Strarray pathspec
   * @param IndexMatchedPathCb callback
   * @param Void payload
     */
Napi::Value GitIndex::RemoveAll(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  RemoveAllBaton* baton = new RemoveAllBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

      RemoveAll_globalPayload* globalPayload = new RemoveAll_globalPayload;

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_strarray * from_pathspec = NULL;

  from_pathspec = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
          baton->pathspec = from_pathspec;
        if (!info[1].IsFunction()) {
          baton->callback = NULL;
          globalPayload->callback = NULL;
        }
        else {
          baton->callback = RemoveAll_callback_cppCallback;
            globalPayload->callback = new Napi::FunctionReference();
            *(globalPayload->callback) = Napi::Persistent(info[1].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  RemoveAllWorker *worker = new RemoveAllWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("pathspec", info[0]);
            worker->Reference("payload", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::RemoveAllWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->pathspec
          ,baton->payload
  );

  return lockMaster;
}

void GitIndex::RemoveAllWorker::Execute() {
  git_error_clear();

    int result = git_index_remove_all(
baton->index,baton->pathspec,baton->callback,baton->payload  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::RemoveAllWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.removeAll"));
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

      delete (RemoveAll_globalPayload*)baton->payload;

  delete baton;
}

void GitIndex::RemoveAllWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method removeAll has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.removeAll"));
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
        Napi::Object err = Napi::Error::New(env, "Method removeAll has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.removeAll"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      delete (RemoveAll_globalPayload*)baton->payload;

  delete baton;
}


int GitIndex::RemoveAll_callback_cppCallback (
    const char * path,     const char * matched_pathspec,     void * payload  ) {
  RemoveAll_CallbackBaton baton(1);

    baton.path = path;
    baton.matched_pathspec = matched_pathspec;
    baton.payload = payload;
 
  return baton.ExecuteAsync(RemoveAll_callback_async, RemoveAll_callback_cancelAsync);
}

void GitIndex::RemoveAll_callback_cancelAsync(void *untypedBaton) {
  RemoveAll_CallbackBaton* baton = static_cast<RemoveAll_CallbackBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitIndex::RemoveAll_callback_async(void *untypedBaton) {
  RemoveAll_CallbackBaton* baton = static_cast<RemoveAll_CallbackBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((RemoveAll_globalPayload*)baton->payload)->callback;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         Napi::String::New(env, baton->path)
 ,          Napi::String::New(env, baton->matched_pathspec)
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

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, RemoveAll_callback_promiseCompleted)) {
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

void GitIndex::RemoveAll_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  RemoveAll_CallbackBaton* baton = static_cast<RemoveAll_CallbackBaton*>(_baton);

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
    GitIndex* instance = static_cast<GitIndex*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitIndex>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
  
/*
   * @param String path
     */
Napi::Value GitIndex::RemoveBypath(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  RemoveBypathBaton* baton = new RemoveBypathBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
  RemoveBypathWorker *worker = new RemoveBypathWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("path", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::RemoveBypathWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->path
  );

  return lockMaster;
}

void GitIndex::RemoveBypathWorker::Execute() {
  git_error_clear();

    int result = git_index_remove_bypath(
baton->index,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::RemoveBypathWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.removeByPath"));
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

void GitIndex::RemoveBypathWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method removeByPath has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.removeByPath"));
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
        Napi::Object err = Napi::Error::New(env, "Method removeByPath has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.removeByPath"));
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
   * @param String dir
   * @param Number stage
     */
Napi::Value GitIndex::RemoveDirectory(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String dir is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number stage is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  RemoveDirectoryBaton* baton = new RemoveDirectoryBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_dir = NULL;

  std::string dir = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_dir = (const char *) malloc(dir.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_dir, dir.c_str(), dir.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_dir) + dir.length()), 0, 1);
// end convert_from_v8 block
          baton->dir = from_dir;
// start convert_from_v8 block
  int from_stage;
      from_stage = (int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->stage = from_stage;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  RemoveDirectoryWorker *worker = new RemoveDirectoryWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("dir", info[0]);
            worker->Reference("stage", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::RemoveDirectoryWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->dir
  );

  return lockMaster;
}

void GitIndex::RemoveDirectoryWorker::Execute() {
  git_error_clear();

    int result = git_index_remove_directory(
baton->index,baton->dir,baton->stage  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::RemoveDirectoryWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.removeDirectory"));
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

void GitIndex::RemoveDirectoryWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method removeDirectory has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.removeDirectory"));
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
        Napi::Object err = Napi::Error::New(env, "Method removeDirectory has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.removeDirectory"));
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
   * @param Number caps
     * @return Number  result    */
Napi::Value GitIndex::SetCaps(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number caps is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  int from_caps;
      from_caps = (int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_index_set_caps(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_caps
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Number version
     * @return Number  result    */
Napi::Value GitIndex::SetVersion(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number version is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  unsigned int from_version;
      from_version = (unsigned int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_index_set_version(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_version
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
   * @param Strarray pathspec
   * @param IndexMatchedPathCb callback
   * @param Void payload
     */
Napi::Value GitIndex::UpdateAll(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  UpdateAllBaton* baton = new UpdateAllBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

      UpdateAll_globalPayload* globalPayload = new UpdateAll_globalPayload;

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_strarray * from_pathspec = NULL;

  from_pathspec = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
          baton->pathspec = from_pathspec;
        if (!info[1].IsFunction()) {
          baton->callback = NULL;
          globalPayload->callback = NULL;
        }
        else {
          baton->callback = UpdateAll_callback_cppCallback;
            globalPayload->callback = new Napi::FunctionReference();
            *(globalPayload->callback) = Napi::Persistent(info[1].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  UpdateAllWorker *worker = new UpdateAllWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
           worker->Reference("pathspec", info[0]);
            worker->Reference("payload", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::UpdateAllWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->pathspec
          ,baton->payload
  );

  return lockMaster;
}

void GitIndex::UpdateAllWorker::Execute() {
  git_error_clear();

    int result = git_index_update_all(
baton->index,baton->pathspec,baton->callback,baton->payload  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::UpdateAllWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.updateAll"));
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

      delete (UpdateAll_globalPayload*)baton->payload;

  delete baton;
}

void GitIndex::UpdateAllWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method updateAll has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.updateAll"));
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
        Napi::Object err = Napi::Error::New(env, "Method updateAll has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.updateAll"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      delete (UpdateAll_globalPayload*)baton->payload;

  delete baton;
}


int GitIndex::UpdateAll_callback_cppCallback (
    const char * path,     const char * matched_pathspec,     void * payload  ) {
  UpdateAll_CallbackBaton baton(1);

    baton.path = path;
    baton.matched_pathspec = matched_pathspec;
    baton.payload = payload;
 
  return baton.ExecuteAsync(UpdateAll_callback_async, UpdateAll_callback_cancelAsync);
}

void GitIndex::UpdateAll_callback_cancelAsync(void *untypedBaton) {
  UpdateAll_CallbackBaton* baton = static_cast<UpdateAll_CallbackBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitIndex::UpdateAll_callback_async(void *untypedBaton) {
  UpdateAll_CallbackBaton* baton = static_cast<UpdateAll_CallbackBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((UpdateAll_globalPayload*)baton->payload)->callback;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         Napi::String::New(env, baton->path)
 ,          Napi::String::New(env, baton->matched_pathspec)
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

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, UpdateAll_callback_promiseCompleted)) {
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

void GitIndex::UpdateAll_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  UpdateAll_CallbackBaton* baton = static_cast<UpdateAll_CallbackBaton*>(_baton);

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
    GitIndex* instance = static_cast<GitIndex*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitIndex>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
   
/*
     * @return Number  result    */
Napi::Value GitIndex::Version(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 unsigned int result =     git_index_version(
          Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
     */
Napi::Value GitIndex::Write(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  WriteBaton* baton = new WriteBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  WriteWorker *worker = new WriteWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::WriteWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
  );

  return lockMaster;
}

void GitIndex::WriteWorker::Execute() {
  git_error_clear();

    int result = git_index_write(
baton->index  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::WriteWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.write"));
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

void GitIndex::WriteWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method write has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.write"));
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
        Napi::Object err = Napi::Error::New(env, "Method write has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.write"));
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
     * @param Oid callback
   */
Napi::Value GitIndex::WriteTree(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  WriteTreeBaton* baton = new WriteTreeBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_oid *)malloc(sizeof(git_oid ));
        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  WriteTreeWorker *worker = new WriteTreeWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::WriteTreeWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->index
  );

  return lockMaster;
}

void GitIndex::WriteTreeWorker::Execute() {
  git_error_clear();

    int result = git_index_write_tree(
baton->out,baton->index  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::WriteTreeWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.writeTree"));
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

void GitIndex::WriteTreeWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        baton->out,
        true
       );
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
        err = Napi::Error::New(env, "Method writeTree has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.writeTree"));
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
        Napi::Object err = Napi::Error::New(env, "Method writeTree has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.writeTree"));
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
    * @param Oid callback
   */
Napi::Value GitIndex::WriteTreeTo(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  WriteTreeToBaton* baton = new WriteTreeToBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_oid *)malloc(sizeof(git_oid ));
        baton->index = Napi::ObjectWrap<GitIndex>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  WriteTreeToWorker *worker = new WriteTreeToWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitIndex>("index", info.This().As<Napi::Object>());
             worker->Reference<GitRepository>("repo", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndex::WriteTreeToWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->index
          ,baton->repo
  );

  return lockMaster;
}

void GitIndex::WriteTreeToWorker::Execute() {
  git_error_clear();

    int result = git_index_write_tree_to(
baton->out,baton->index,baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndex::WriteTreeToWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.writeTreeTo"));
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

void GitIndex::WriteTreeToWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        baton->out,
        true
       );
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
        err = Napi::Error::New(env, "Method writeTreeTo has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.writeTreeTo"));
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
        Napi::Object err = Napi::Error::New(env, "Method writeTreeTo has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Index.writeTreeTo"));
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

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitIndexTraits>;
 