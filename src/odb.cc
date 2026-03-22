// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/odb.h"
#include "bungit_wrapper.cc"

  #include "../include/mempack.h"
  #include "../include/oid.h"
  #include "../include/odb_object.h"
  #include "../include/commit_graph.h"
  #include "../include/odb_backend.h"
 
#include <iostream>

using namespace std;

  GitOdb::~GitOdb() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                               }

  void GitOdb::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Odb", {
          InstanceMethod("addDiskAlternate", &GitOdb::AddDiskAlternate, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("existsExt", &GitOdb::ExistsExt, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("existsPrefix", &GitOdb::ExistsPrefix, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("hash", &GitOdb::Hash, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("hashfile", &GitOdb::Hashfile, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("open", &GitOdb::Open, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("read", &GitOdb::OdbRead, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("readPrefix", &GitOdb::ReadPrefix, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setCommitGraph", &GitOdb::SetCommitGraph, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("write", &GitOdb::Write, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("writeMultiPackIndex", &GitOdb::WriteMultiPackIndex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("addMempackBackend", &GitOdb::AddMempackBackend, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitOdb::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitOdb::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitOdb::Template", constructor_template);
    target.Set(Napi::String::New(env, "Odb"), constructor_template);
  }

 
/*
   * @param String path
     */
Napi::Value GitOdb::AddDiskAlternate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AddDiskAlternateBaton* baton = new AddDiskAlternateBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->odb = Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue();
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
  AddDiskAlternateWorker *worker = new AddDiskAlternateWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitOdb>("odb", info.This().As<Napi::Object>());
           worker->Reference("path", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitOdb::AddDiskAlternateWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->odb
          ,baton->path
  );

  return lockMaster;
}

void GitOdb::AddDiskAlternateWorker::Execute() {
  git_error_clear();

    int result = git_odb_add_disk_alternate(
baton->odb,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitOdb::AddDiskAlternateWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.addDiskAlternate"));
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

void GitOdb::AddDiskAlternateWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method addDiskAlternate has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.addDiskAlternate"));
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
        Napi::Object err = Napi::Error::New(env, "Method addDiskAlternate has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.addDiskAlternate"));
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
   * @param Oid id
   * @param Number flags
     * @return Number  result    */
Napi::Value GitOdb::ExistsExt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number flags is required.").ThrowAsJavaScriptException();
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
// start convert_from_v8 block
  unsigned int from_flags;
      from_flags = (unsigned int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_id
    );

 int result =     git_odb_exists_ext(
          Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_id
,          from_flags
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
    * @param Oid short_id
   * @param Number len
    * @param Oid callback
   */
Napi::Value GitOdb::ExistsPrefix(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid short_id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ExistsPrefixBaton* baton = new ExistsPrefixBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_oid *)malloc(sizeof(git_oid ));
        baton->db = Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_oid * from_short_id = NULL;
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

    from_short_id = oidOut;
  }
  else {
from_short_id = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->short_id = from_short_id;
            baton->short_idNeedsFree = info[0].IsString();
// start convert_from_v8 block
  size_t from_len;
      from_len = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->len = from_len;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ExistsPrefixWorker *worker = new ExistsPrefixWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitOdb>("db", info.This().As<Napi::Object>());
             worker->Reference<GitOid>("short_id", info[0]);
             worker->Reference("len", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitOdb::ExistsPrefixWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->db
          ,baton->short_id
  );

  return lockMaster;
}

void GitOdb::ExistsPrefixWorker::Execute() {
  git_error_clear();

    int result = git_odb_exists_prefix(
baton->out,baton->db,baton->short_id,baton->len  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitOdb::ExistsPrefixWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.existsPrefix"));
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

      if (baton->short_idNeedsFree) {
        baton->short_idNeedsFree = false;
        free((void *)baton->short_id);
      }

  delete baton;
}

void GitOdb::ExistsPrefixWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method existsPrefix has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.existsPrefix"));
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
        Napi::Object err = Napi::Error::New(env, "Method existsPrefix has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.existsPrefix"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->short_idNeedsFree) {
        baton->short_idNeedsFree = false;
        free((void *)baton->short_id);
      }

  delete baton;
}

  
/*
  * @param Buffer data
   * @param Number len
   * @param Number object_type
    * @param Oid callback
   */
Napi::Value GitOdb::Hash(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "Buffer data is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number object_type is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  HashBaton* baton = new HashBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->oid = (git_oid *)malloc(sizeof(git_oid ));
// start convert_from_v8 block
  const void * from_data = NULL;

  std::string data = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_data = (const void *) malloc(data.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_data, data.c_str(), data.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_data) + data.length()), 0, 1);
// end convert_from_v8 block
          baton->data = from_data;
// start convert_from_v8 block
  size_t from_len;
      from_len = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->len = from_len;
// start convert_from_v8 block
  git_object_t from_object_type;
      from_object_type = (git_object_t)  (int) info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->object_type = from_object_type;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  HashWorker *worker = new HashWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("data", info[0]);
            worker->Reference("len", info[1]);
            worker->Reference("object_type", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitOdb::HashWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->oid
          ,baton->data
  );

  return lockMaster;
}

void GitOdb::HashWorker::Execute() {
  git_error_clear();

    int result = git_odb_hash(
baton->oid,baton->data,baton->len,baton->object_type  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitOdb::HashWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.hash"));
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

void GitOdb::HashWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->oid != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        baton->oid,
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
        err = Napi::Error::New(env, "Method hash has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.hash"));
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
        Napi::Object err = Napi::Error::New(env, "Method hash has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.hash"));
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
 * @param Oid oid
   * @param String path
   * @param Number object_type
     */
Napi::Value GitOdb::Hashfile(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid oid is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number object_type is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  HashfileBaton* baton = new HashfileBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_oid * from_oid = NULL;
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

    from_oid = oidOut;
  }
  else {
from_oid = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->oid = from_oid;
            baton->oidNeedsFree = info[0].IsString();
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
// start convert_from_v8 block
  git_object_t from_object_type;
      from_object_type = (git_object_t)  (int) info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->object_type = from_object_type;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  HashfileWorker *worker = new HashfileWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitOid>("oid", info[0]);
             worker->Reference("path", info[1]);
            worker->Reference("object_type", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitOdb::HashfileWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->oid
          ,baton->path
  );

  return lockMaster;
}

void GitOdb::HashfileWorker::Execute() {
  git_error_clear();

    int result = git_odb_hashfile(
baton->oid,baton->path,baton->object_type  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitOdb::HashfileWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.hashfile"));
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

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

void GitOdb::HashfileWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method hashfile has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.hashfile"));
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
        Napi::Object err = Napi::Error::New(env, "Method hashfile has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.hashfile"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

  
/*
  * @param String objects_dir
    * @param Odb callback
   */
Napi::Value GitOdb::Open(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String objects_dir is required.").ThrowAsJavaScriptException();
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
  const char * from_objects_dir = NULL;

  std::string objects_dir = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_objects_dir = (const char *) malloc(objects_dir.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_objects_dir, objects_dir.c_str(), objects_dir.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_objects_dir) + objects_dir.length()), 0, 1);
// end convert_from_v8 block
          baton->objects_dir = from_objects_dir;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  OpenWorker *worker = new OpenWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("objects_dir", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitOdb::OpenWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->objects_dir
  );

  return lockMaster;
}

void GitOdb::OpenWorker::Execute() {
  git_error_clear();

    int result = git_odb_open(
&baton->odb_out,baton->objects_dir  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitOdb::OpenWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.open"));
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

      git_odb_free(baton->odb_out);

  delete baton;
}

void GitOdb::OpenWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->odb_out != NULL) {
        v8ConversionSlot = GitOdb::New(
        env,
        baton->odb_out,
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
        err = Napi::Error::New(env, "Method open has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.open"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.open"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_odb_free(baton->odb_out);
  }


  delete baton;
}

  
/*
    * @param Oid id
    * @param OdbObject callback
   */
Napi::Value GitOdb::OdbRead(const Napi::CallbackInfo& info) {
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

  OdbReadBaton* baton = new OdbReadBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->db = Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue();
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
  OdbReadWorker *worker = new OdbReadWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitOdb>("db", info.This().As<Napi::Object>());
             worker->Reference<GitOid>("id", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitOdb::OdbReadWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->db
          ,baton->id
  );

  return lockMaster;
}

void GitOdb::OdbReadWorker::Execute() {
  git_error_clear();

    int result = git_odb_read(
&baton->obj,baton->db,baton->id  );


      baton->result = result;

}

void GitOdb::OdbReadWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.read"));
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

void GitOdb::OdbReadWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->obj != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("db").As<Napi::Object>());
             v8ConversionSlot = GitOdbObject::New(
        env,
        baton->obj,
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
        err = Napi::Error::New(env, "Method read has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.read"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.read"));
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
 * @param OdbObject obj
     * @param Oid short_id
   * @param Number len
     * @return Number  result    */
Napi::Value GitOdb::ReadPrefix(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "OdbObject obj is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid short_id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_odb_object ** from_obj = NULL;
*from_obj = Napi::ObjectWrap<GitOdbObject>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_oid * from_short_id = NULL;
  if (info[1].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[1].As<Napi::String>().Utf8Value();
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

    from_short_id = oidOut;
  }
  else {
from_short_id = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_len;
      from_len = (size_t)   info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_obj
            ,
              Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_short_id
    );

 int result =     git_odb_read_prefix(
          from_obj
,          Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_short_id
,          from_len
    );

      if (info[1].IsString()) {
        free((void *)from_short_id);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param CommitGraph cgraph
     * @return Number  result    */
Napi::Value GitOdb::SetCommitGraph(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "CommitGraph cgraph is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_commit_graph * from_cgraph = NULL;
from_cgraph = Napi::ObjectWrap<GitCommitGraph>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_cgraph
    );

 int result =     git_odb_set_commit_graph(
          Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_cgraph
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
    * @param Buffer data
   * @param Number len
   * @param Number type
    * @param Oid callback
   */
Napi::Value GitOdb::Write(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "Buffer data is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number type is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  WriteBaton* baton = new WriteBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_oid *)malloc(sizeof(git_oid ));
        baton->odb = Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const void * from_data = NULL;

  std::string data = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_data = (const void *) malloc(data.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_data, data.c_str(), data.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_data) + data.length()), 0, 1);
// end convert_from_v8 block
          baton->data = from_data;
// start convert_from_v8 block
  size_t from_len;
      from_len = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->len = from_len;
// start convert_from_v8 block
  git_object_t from_type;
      from_type = (git_object_t)  (int) info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->type = from_type;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  WriteWorker *worker = new WriteWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitOdb>("odb", info.This().As<Napi::Object>());
           worker->Reference("data", info[0]);
            worker->Reference("len", info[1]);
            worker->Reference("type", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitOdb::WriteWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->odb
          ,baton->data
  );

  return lockMaster;
}

void GitOdb::WriteWorker::Execute() {
  git_error_clear();

    int result = git_odb_write(
baton->out,baton->odb,baton->data,baton->len,baton->type  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitOdb::WriteWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.write"));
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

void GitOdb::WriteWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method write has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.write"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Odb.write"));
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
Napi::Value GitOdb::WriteMultiPackIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_odb_write_multi_pack_index(
          Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
        // Manual binding for git_odb_add_backend, exposed as Odb.prototype.addMempackBackend()
// The first argument (backend) must be a Mempack object wrapping a git_odb_backend*.

Napi::Value GitOdb::AddMempackBackend(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 3) {
    Napi::Error::New(env, "Backend, priority, and callback arguments are required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AddMempackBackendBaton *baton = new AddMempackBackendBaton();
  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->odb = Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  // Validate and extract git_odb_backend* from the Mempack wrapper
  if (!info[0].IsObject() || info[0].IsNull() || info[0].IsUndefined()) {
    delete baton;
    Napi::TypeError::New(env, "First argument must be a Mempack object.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  baton->backend = Napi::ObjectWrap<GitMempack>::Unwrap(info[0].As<Napi::Object>())->GetValue();

  // Priority is required and must be a number
  if (!info[1].IsNumber()) {
    delete baton;
    Napi::TypeError::New(env, "Second argument (priority) must be a number.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  baton->priority = info[1].As<Napi::Number>().Int32Value();

  Napi::FunctionReference callback;
  callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  AddMempackBackendWorker *worker = new AddMempackBackendWorker(baton, std::move(callback), cleanupHandles);

  worker->Reference<GitOdb>("odb", info.This().As<Napi::Object>());
  worker->Reference("backend", info[0]);

  // Store a reference from the backend to the ODB to prevent the ODB from
  // being garbage-collected while the backend is alive. This is critical
  // because after git_odb_add_backend, libgit2 owns the backend pointer and
  // will free it when the ODB is freed. If the ODB is GC'd first, the
  // backend's pointer becomes dangling.
  info[0].As<Napi::Object>().Set(
    Napi::String::New(env, "_parentOdb"), info.This());

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitOdb::AddMempackBackendWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->odb, baton->backend);
  return lockMaster;
}

void GitOdb::AddMempackBackendWorker::Execute() {
  git_error_clear();

  baton->error_code = git_odb_add_backend(baton->odb, baton->backend, baton->priority);

  if (baton->error_code != GIT_OK && git_error_last() != NULL && git_error_last()->klass != GIT_ERROR_NONE) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitOdb::AddMempackBackendWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  delete baton;
}

void GitOdb::AddMempackBackendWorker::HandleOKCallback() {
  Napi::Env env = Env();

  if (baton->error_code == GIT_OK) {
    napi_value argv[2] = {env.Null(), Napi::Number::New(env, baton->error_code)};
    callback.Call(env.Undefined(), 2, argv);
  } else if (baton->error) {
    Napi::Object err;
    if (baton->error->message) {
      err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
    } else {
      err = Napi::Error::New(env, "Method addMempackBackend has thrown an error.").Value().As<Napi::Object>();
    }
    err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
    err.Set(Napi::String::New(env, "errorFunction"),
             Napi::String::New(env, "Odb.addMempackBackend"));
    napi_value argv[1] = {err};
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
      free((void *)baton->error->message);
    free((void *)baton->error);
  } else if (baton->error_code < 0) {
    Napi::Object err =
        Napi::Error::New(env, "Method addMempackBackend has thrown an error.").Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errno"),
             Napi::Number::New(env, baton->error_code));
    err.Set(Napi::String::New(env, "errorFunction"),
             Napi::String::New(env, "Odb.addMempackBackend"));
    napi_value argv[1] = {err};
    callback.Call(env.Undefined(), 1, argv);
  } else {
    callback.Call({});
  }

  delete baton;
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitOdbTraits>;
 