// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/packbuilder.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
  #include "../include/revwalk.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;

  GitPackbuilder::~GitPackbuilder() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                             }

  void GitPackbuilder::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Packbuilder", {
          InstanceMethod("hash", &GitPackbuilder::Hash, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("insert", &GitPackbuilder::Insert, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("insertCommit", &GitPackbuilder::InsertCommit, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("insertRecur", &GitPackbuilder::InsertRecur, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("insertTree", &GitPackbuilder::InsertTree, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("insertWalk", &GitPackbuilder::InsertWalk, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("name", &GitPackbuilder::Name, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("create", &GitPackbuilder::Create, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("objectCount", &GitPackbuilder::ObjectCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setThreads", &GitPackbuilder::SetThreads, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("written", &GitPackbuilder::Written, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitPackbuilder::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitPackbuilder::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitPackbuilder::Template", constructor_template);
    target.Set(Napi::String::New(env, "Packbuilder"), constructor_template);
  }

  
/*
     * @return Oid  result    */
Napi::Value GitPackbuilder::Hash(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_packbuilder_hash(
          Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
   * @param Oid id
   * @param String name
     */
Napi::Value GitPackbuilder::Insert(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  InsertBaton* baton = new InsertBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->pb = Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_oid * from_id = NULL;
  if (info[0].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[0].As<Napi::String>().Utf8Value();
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(oidString.c_str())) != GIT_OK) {
      free(oidOut);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->id = from_id;
            baton->idNeedsFree = info[0].IsString();
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
          baton->name = from_name;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  InsertWorker *worker = new InsertWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitPackbuilder>("pb", info.This().As<Napi::Object>());
             worker->Reference<GitOid>("id", info[0]);
             worker->Reference("name", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitPackbuilder::InsertWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->pb
          ,baton->id
          ,baton->name
  );

  return lockMaster;
}

void GitPackbuilder::InsertWorker::Execute() {
  git_error_clear();

    int result = git_packbuilder_insert(
baton->pb,baton->id,baton->name  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitPackbuilder::InsertWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insert"));
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

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

void GitPackbuilder::InsertWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method insert has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insert"));
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
        Napi::Object err = Napi::Error::New(env, "Method insert has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insert"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

  
/*
   * @param Oid id
     */
Napi::Value GitPackbuilder::InsertCommit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  InsertCommitBaton* baton = new InsertCommitBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->pb = Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_oid * from_id = NULL;
  if (info[0].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[0].As<Napi::String>().Utf8Value();
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(oidString.c_str())) != GIT_OK) {
      free(oidOut);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->id = from_id;
            baton->idNeedsFree = info[0].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  InsertCommitWorker *worker = new InsertCommitWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitPackbuilder>("pb", info.This().As<Napi::Object>());
             worker->Reference<GitOid>("id", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitPackbuilder::InsertCommitWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->pb
          ,baton->id
  );

  return lockMaster;
}

void GitPackbuilder::InsertCommitWorker::Execute() {
  git_error_clear();

    int result = git_packbuilder_insert_commit(
baton->pb,baton->id  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitPackbuilder::InsertCommitWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insertCommit"));
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

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

void GitPackbuilder::InsertCommitWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method insertCommit has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insertCommit"));
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
        Napi::Object err = Napi::Error::New(env, "Method insertCommit has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insertCommit"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

  
/*
   * @param Oid id
   * @param String name
     */
Napi::Value GitPackbuilder::InsertRecur(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  InsertRecurBaton* baton = new InsertRecurBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->pb = Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_oid * from_id = NULL;
  if (info[0].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[0].As<Napi::String>().Utf8Value();
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(oidString.c_str())) != GIT_OK) {
      free(oidOut);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->id = from_id;
            baton->idNeedsFree = info[0].IsString();
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
          baton->name = from_name;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  InsertRecurWorker *worker = new InsertRecurWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitPackbuilder>("pb", info.This().As<Napi::Object>());
             worker->Reference<GitOid>("id", info[0]);
             worker->Reference("name", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitPackbuilder::InsertRecurWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->pb
          ,baton->id
          ,baton->name
  );

  return lockMaster;
}

void GitPackbuilder::InsertRecurWorker::Execute() {
  git_error_clear();

    int result = git_packbuilder_insert_recur(
baton->pb,baton->id,baton->name  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitPackbuilder::InsertRecurWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insertRecur"));
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

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

void GitPackbuilder::InsertRecurWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method insertRecur has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insertRecur"));
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
        Napi::Object err = Napi::Error::New(env, "Method insertRecur has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insertRecur"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

   
/*
   * @param Oid id
     * @return Number  result    */
Napi::Value GitPackbuilder::InsertTree(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
// start convert_from_v8 block
  const git_oid * from_id = NULL;
  if (info[0].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[0].As<Napi::String>().Utf8Value();
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(oidString.c_str())) != GIT_OK) {
      free(oidOut);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_id
    );

 int result =     git_packbuilder_insert_tree(
          Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_id
    );

      if (info[0].IsString()) {
        free((void *)from_id);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
   * @param Revwalk walk
     */
Napi::Value GitPackbuilder::InsertWalk(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Revwalk walk is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  InsertWalkBaton* baton = new InsertWalkBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->pb = Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  git_revwalk * from_walk = NULL;
from_walk = Napi::ObjectWrap<GitRevwalk>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->walk = from_walk;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  InsertWalkWorker *worker = new InsertWalkWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitPackbuilder>("pb", info.This().As<Napi::Object>());
             worker->Reference<GitRevwalk>("walk", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitPackbuilder::InsertWalkWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->pb
          ,baton->walk
  );

  return lockMaster;
}

void GitPackbuilder::InsertWalkWorker::Execute() {
  git_error_clear();

    int result = git_packbuilder_insert_walk(
baton->pb,baton->walk  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitPackbuilder::InsertWalkWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insertWalk"));
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

void GitPackbuilder::InsertWalkWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method insertWalk has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insertWalk"));
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
        Napi::Object err = Napi::Error::New(env, "Method insertWalk has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Packbuilder.insertWalk"));
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
     * @return String  result    */
Napi::Value GitPackbuilder::Name(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_packbuilder_name(
          Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
  * @param Repository repo
     * @return Packbuilder out    */
Napi::Value GitPackbuilder::Create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

      git_packbuilder * out = 0;
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

 int result =     git_packbuilder_new(
&          out
,          from_repo
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

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (out != NULL) {
        v8ConversionSlot = GitPackbuilder::New(
        env,
        out,
        true
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
Napi::Value GitPackbuilder::ObjectCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_packbuilder_object_count(
          Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Number n
     * @return Number  result    */
Napi::Value GitPackbuilder::SetThreads(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number n is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  unsigned int from_n;
      from_n = (unsigned int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 unsigned int result =     git_packbuilder_set_threads(
          Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_n
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
Napi::Value GitPackbuilder::Written(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_packbuilder_written(
          Napi::ObjectWrap<GitPackbuilder>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitPackbuilderTraits>;
 