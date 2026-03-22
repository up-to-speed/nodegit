// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/index.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/index_reuc_entry.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
  #include "../include/index.h"
 
#include <iostream>

using namespace std;

  GitIndexReucEntry::~GitIndexReucEntry() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                    }

  void GitIndexReucEntry::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "IndexReucEntry", {
           StaticMethod("add", &GitIndexReucEntry::Add, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("clear", &GitIndexReucEntry::Clear, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("entryCount", &GitIndexReucEntry::Entrycount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("find", &GitIndexReucEntry::Find, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("getByIndex", &GitIndexReucEntry::GetByIndex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("getByPath", &GitIndexReucEntry::GetByPath, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("remove", &GitIndexReucEntry::Remove, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
           InstanceMethod("mode", &GitIndexReucEntry::Mode, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("oid", &GitIndexReucEntry::Oid, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("path", &GitIndexReucEntry::Path, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitIndexReucEntry::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitIndexReucEntry::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitIndexReucEntry::Template", constructor_template);
    target.Set(Napi::String::New(env, "IndexReucEntry"), constructor_template);
  }

 
/*
 * @param Index index
   * @param String path
   * @param Number ancestor_mode
   * @param Oid ancestor_id
   * @param Number our_mode
   * @param Oid our_id
   * @param Number their_mode
   * @param Oid their_id
     */
Napi::Value GitIndexReucEntry::Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Index index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number ancestor_mode is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3
    || (!info[3].IsObject() && !info[3].IsString())) {
    Napi::Error::New(env, "Oid ancestor_id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 4 || !info[4].IsNumber()) {
    Napi::Error::New(env, "Number our_mode is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 5
    || (!info[5].IsObject() && !info[5].IsString())) {
    Napi::Error::New(env, "Oid our_id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 6 || !info[6].IsNumber()) {
    Napi::Error::New(env, "Number their_mode is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 7
    || (!info[7].IsObject() && !info[7].IsString())) {
    Napi::Error::New(env, "Oid their_id is required.").ThrowAsJavaScriptException();
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

// start convert_from_v8 block
  git_index * from_index = NULL;
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->index = from_index;
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
  int from_ancestor_mode;
      from_ancestor_mode = (int)   info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->ancestor_mode = from_ancestor_mode;
// start convert_from_v8 block
  const git_oid * from_ancestor_id = NULL;
  if (info[3].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[3].As<Napi::String>().Utf8Value();
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

    from_ancestor_id = oidOut;
  }
  else {
from_ancestor_id = Napi::ObjectWrap<GitOid>::Unwrap(info[3].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->ancestor_id = from_ancestor_id;
            baton->ancestor_idNeedsFree = info[3].IsString();
// start convert_from_v8 block
  int from_our_mode;
      from_our_mode = (int)   info[4].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->our_mode = from_our_mode;
// start convert_from_v8 block
  const git_oid * from_our_id = NULL;
  if (info[5].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[5].As<Napi::String>().Utf8Value();
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

    from_our_id = oidOut;
  }
  else {
from_our_id = Napi::ObjectWrap<GitOid>::Unwrap(info[5].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->our_id = from_our_id;
            baton->our_idNeedsFree = info[5].IsString();
// start convert_from_v8 block
  int from_their_mode;
      from_their_mode = (int)   info[6].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->their_mode = from_their_mode;
// start convert_from_v8 block
  const git_oid * from_their_id = NULL;
  if (info[7].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[7].As<Napi::String>().Utf8Value();
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

    from_their_id = oidOut;
  }
  else {
from_their_id = Napi::ObjectWrap<GitOid>::Unwrap(info[7].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->their_id = from_their_id;
            baton->their_idNeedsFree = info[7].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  AddWorker *worker = new AddWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitIndex>("index", info[0]);
             worker->Reference("path", info[1]);
            worker->Reference("ancestor_mode", info[2]);
              worker->Reference<GitOid>("ancestor_id", info[3]);
             worker->Reference("our_mode", info[4]);
              worker->Reference<GitOid>("our_id", info[5]);
             worker->Reference("their_mode", info[6]);
              worker->Reference<GitOid>("their_id", info[7]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndexReucEntry::AddWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
          ,baton->path
          ,baton->ancestor_id
          ,baton->our_id
          ,baton->their_id
  );

  return lockMaster;
}

void GitIndexReucEntry::AddWorker::Execute() {
  git_error_clear();

    int result = git_index_reuc_add(
baton->index,baton->path,baton->ancestor_mode,baton->ancestor_id,baton->our_mode,baton->our_id,baton->their_mode,baton->their_id  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndexReucEntry::AddWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.add"));
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

      if (baton->ancestor_idNeedsFree) {
        baton->ancestor_idNeedsFree = false;
        free((void *)baton->ancestor_id);
      }
      if (baton->our_idNeedsFree) {
        baton->our_idNeedsFree = false;
        free((void *)baton->our_id);
      }
      if (baton->their_idNeedsFree) {
        baton->their_idNeedsFree = false;
        free((void *)baton->their_id);
      }

  delete baton;
}

void GitIndexReucEntry::AddWorker::HandleOKCallback() {
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
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.add"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.add"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->ancestor_idNeedsFree) {
        baton->ancestor_idNeedsFree = false;
        free((void *)baton->ancestor_id);
      }
      if (baton->our_idNeedsFree) {
        baton->our_idNeedsFree = false;
        free((void *)baton->our_id);
      }
      if (baton->their_idNeedsFree) {
        baton->their_idNeedsFree = false;
        free((void *)baton->their_id);
      }

  delete baton;
}

  
/*
 * @param Index index
     */
Napi::Value GitIndexReucEntry::Clear(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Index index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ClearBaton* baton = new ClearBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_index * from_index = NULL;
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->index = from_index;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ClearWorker *worker = new ClearWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitIndex>("index", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndexReucEntry::ClearWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
  );

  return lockMaster;
}

void GitIndexReucEntry::ClearWorker::Execute() {
  git_error_clear();

    int result = git_index_reuc_clear(
baton->index  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndexReucEntry::ClearWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.clear"));
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

void GitIndexReucEntry::ClearWorker::HandleOKCallback() {
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
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.clear"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.clear"));
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
 * @param Index index
     * @return Number  result    */
Napi::Value GitIndexReucEntry::Entrycount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Index index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_index * from_index = NULL;
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_index
    );

 size_t result =     git_index_reuc_entrycount(
          from_index
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
  * @param Index index
   * @param String path
    * @param Number callback
   */
Napi::Value GitIndexReucEntry::Find(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Index index is required.").ThrowAsJavaScriptException();
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

  FindBaton* baton = new FindBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->at_pos = (size_t *)malloc(sizeof(size_t ));
// start convert_from_v8 block
  git_index * from_index = NULL;
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->index = from_index;
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
  FindWorker *worker = new FindWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitIndex>("index", info[0]);
             worker->Reference("path", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndexReucEntry::FindWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->at_pos
          ,baton->index
          ,baton->path
  );

  return lockMaster;
}

void GitIndexReucEntry::FindWorker::Execute() {
  git_error_clear();

    int result = git_index_reuc_find(
baton->at_pos,baton->index,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndexReucEntry::FindWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.find"));
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

void GitIndexReucEntry::FindWorker::HandleOKCallback() {
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
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.find"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.find"));
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
 * @param Index index
   * @param Number n
     * @return IndexReucEntry  result    */
Napi::Value GitIndexReucEntry::GetByIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Index index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number n is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_index * from_index = NULL;
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_n;
      from_n = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_index
    );

 const git_index_reuc_entry * result =     git_index_reuc_get_byindex(
          from_index
,          from_n
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitIndexReucEntry::New(
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
 * @param Index index
   * @param String path
     * @return IndexReucEntry  result    */
Napi::Value GitIndexReucEntry::GetByPath(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Index index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_index * from_index = NULL;
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
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

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_index
            ,
              from_path
    );

 const git_index_reuc_entry * result =     git_index_reuc_get_bypath(
          from_index
,          from_path
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitIndexReucEntry::New(
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
 * @param Index index
   * @param Number n
     */
Napi::Value GitIndexReucEntry::Remove(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Index index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number n is required.").ThrowAsJavaScriptException();
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

// start convert_from_v8 block
  git_index * from_index = NULL;
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->index = from_index;
// start convert_from_v8 block
  size_t from_n;
      from_n = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->n = from_n;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  RemoveWorker *worker = new RemoveWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitIndex>("index", info[0]);
             worker->Reference("n", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndexReucEntry::RemoveWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
  );

  return lockMaster;
}

void GitIndexReucEntry::RemoveWorker::Execute() {
  git_error_clear();

    int result = git_index_reuc_remove(
baton->index,baton->n  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndexReucEntry::RemoveWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.remove"));
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

void GitIndexReucEntry::RemoveWorker::HandleOKCallback() {
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
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.remove"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexReucEntry.remove"));
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

       // start field block
    Napi::Value GitIndexReucEntry::Mode(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

           uint32_t *mode =
         Napi::ObjectWrap<GitIndexReucEntry>::Unwrap(info.This().As<Napi::Object>())->GetValue()->mode;
 // start convert_to_v8 block
    Napi::Array tmpArray = Napi::Array::New(env, 3);
    for (unsigned int i = 0; i < 3; i++) {
      Napi::Value element;
         element = Napi::Number::New(env,  mode[i]);
       tmpArray.Set(Napi::Number::New(env, i), element);
    }
    v8ConversionSlot = tmpArray;
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitIndexReucEntry::Oid(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

           git_oid *oid =
         Napi::ObjectWrap<GitIndexReucEntry>::Unwrap(info.This().As<Napi::Object>())->GetValue()->oid;
 // start convert_to_v8 block
     Napi::Array tmpArray = Napi::Array::New(env, 3);
    for (unsigned int i = 0; i < 3; i++) {
   if (&oid[i] != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        &oid[i],
        true
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
      tmpArray.Set(Napi::Number::New(env, i), v8ConversionSlot);
    }
    v8ConversionSlot = tmpArray;
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitIndexReucEntry::Path(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char *
           path =
          Napi::ObjectWrap<GitIndexReucEntry>::Unwrap(info.This().As<Napi::Object>())->GetValue()->path;
 // start convert_to_v8 block
  if (path){
       v8ConversionSlot = Napi::String::New(env, path);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitIndexReucEntryTraits>;
 