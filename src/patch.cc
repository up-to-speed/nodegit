// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/patch.h"
#include "bungit_wrapper.cc"

  #include "../include/convenient_patch.h"
  #include "../include/blob.h"
  #include "../include/diff_options.h"
  #include "../include/diff.h"
  #include "../include/diff_delta.h"
  #include "../include/diff_hunk.h"
  #include "../include/diff_line.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;

  GitPatch::~GitPatch() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                          }

  void GitPatch::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Patch", {
           StaticMethod("fromBlobs", &GitPatch::FromBlobs, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("fromDiff", &GitPatch::FromDiff, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getDelta", &GitPatch::GetDelta, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getHunk", &GitPatch::GetHunk, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getLineInHunk", &GitPatch::GetLineInHunk, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("lineStats", &GitPatch::LineStats, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("numHunks", &GitPatch::NumHunks, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("numLinesInHunk", &GitPatch::NumLinesInHunk, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("owner", &GitPatch::Owner, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("size", &GitPatch::Size, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("convenientFromDiff", &GitPatch::ConvenientFromDiff, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitPatch::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitPatch::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitPatch::Template", constructor_template);
    target.Set(Napi::String::New(env, "Patch"), constructor_template);
  }

 
/*
  * @param Blob old_blob
   * @param String old_as_path
   * @param Blob new_blob
   * @param String new_as_path
   * @param DiffOptions opts
    * @param Patch callback
   */
Napi::Value GitPatch::FromBlobs(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FromBlobsBaton* baton = new FromBlobsBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const git_blob * from_old_blob = NULL;
    if ((info.Length() - 1) > 0 && info[0].IsObject()) {
from_old_blob = Napi::ObjectWrap<GitBlob>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
  else {
    from_old_blob = 0;
  }
// end convert_from_v8 block
          baton->old_blob = from_old_blob;
// start convert_from_v8 block
  const char * from_old_as_path = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsString()) {

  std::string old_as_path = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_old_as_path = (const char *) malloc(old_as_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_old_as_path, old_as_path.c_str(), old_as_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_old_as_path) + old_as_path.length()), 0, 1);
  }
  else {
    from_old_as_path = 0;
  }
// end convert_from_v8 block
          baton->old_as_path = from_old_as_path;
// start convert_from_v8 block
  const git_blob * from_new_blob = NULL;
    if ((info.Length() - 1) > 2 && info[2].IsObject()) {
from_new_blob = Napi::ObjectWrap<GitBlob>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
  else {
    from_new_blob = 0;
  }
// end convert_from_v8 block
          baton->new_blob = from_new_blob;
// start convert_from_v8 block
  const char * from_new_as_path = NULL;
    if ((info.Length() - 1) > 3 && info[3].IsString()) {

  std::string new_as_path = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_new_as_path = (const char *) malloc(new_as_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_new_as_path, new_as_path.c_str(), new_as_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_new_as_path) + new_as_path.length()), 0, 1);
  }
  else {
    from_new_as_path = 0;
  }
// end convert_from_v8 block
          baton->new_as_path = from_new_as_path;
          if (info[4].IsNull() || info[4].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitDiffOptions::fromJavascript(nodegitContext, info[4]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FromBlobsWorker *worker = new FromBlobsWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitBlob>("old_blob", info[0]);
             worker->Reference("old_as_path", info[1]);
              worker->Reference<GitBlob>("new_blob", info[2]);
             worker->Reference("new_as_path", info[3]);
            worker->Reference("opts", info[4]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitPatch::FromBlobsWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->old_blob
          ,baton->old_as_path
          ,baton->new_blob
          ,baton->new_as_path
          ,baton->opts
  );

  return lockMaster;
}

void GitPatch::FromBlobsWorker::Execute() {
  git_error_clear();

    int result = git_patch_from_blobs(
&baton->out,baton->old_blob,baton->old_as_path,baton->new_blob,baton->new_as_path,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitPatch::FromBlobsWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.fromBlobs"));
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

      git_patch_free(baton->out);

  delete baton;
}

void GitPatch::FromBlobsWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
          owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_patch_owner(baton->out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitPatch::New(
        env,
        baton->out,
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
        err = Napi::Error::New(env, "Method fromBlobs has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.fromBlobs"));
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
        Napi::Object err = Napi::Error::New(env, "Method fromBlobs has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.fromBlobs"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_patch_free(baton->out);
  }


  delete baton;
}

  
/*
  * @param Diff diff
   * @param Number idx
    * @param Patch callback
   */
Napi::Value GitPatch::FromDiff(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Diff diff is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number idx is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FromDiffBaton* baton = new FromDiffBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_diff * from_diff = NULL;
from_diff = Napi::ObjectWrap<GitDiff>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->diff = from_diff;
// start convert_from_v8 block
  size_t from_idx;
      from_idx = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->idx = from_idx;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FromDiffWorker *worker = new FromDiffWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitDiff>("diff", info[0]);
             worker->Reference("idx", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitPatch::FromDiffWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->diff
  );

  return lockMaster;
}

void GitPatch::FromDiffWorker::Execute() {
  git_error_clear();

    int result = git_patch_from_diff(
&baton->out,baton->diff,baton->idx  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitPatch::FromDiffWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.fromDiff"));
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

      git_patch_free(baton->out);

  delete baton;
}

void GitPatch::FromDiffWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("diff").As<Napi::Object>());
            owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_patch_owner(baton->out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitPatch::New(
        env,
        baton->out,
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
        err = Napi::Error::New(env, "Method fromDiff has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.fromDiff"));
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
        Napi::Object err = Napi::Error::New(env, "Method fromDiff has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.fromDiff"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_patch_free(baton->out);
  }


  delete baton;
}

   
/*
     * @return DiffDelta  result    */
Napi::Value GitPatch::GetDelta(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_diff_delta * result =     git_patch_get_delta(
          Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
          v8ConversionSlot = GitDiffDelta::New(
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
     * @param Number hunk_idx
    * @param DiffHunk callback
  * @param Number callback
   */
Napi::Value GitPatch::GetHunk(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number hunk_idx is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  GetHunkBaton* baton = new GetHunkBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->lines_in_hunk = (size_t *)malloc(sizeof(size_t ));
        baton->patch = Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  size_t from_hunk_idx;
      from_hunk_idx = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->hunk_idx = from_hunk_idx;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  GetHunkWorker *worker = new GetHunkWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitPatch>("patch", info.This().As<Napi::Object>());
           worker->Reference("hunk_idx", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitPatch::GetHunkWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->lines_in_hunk
          ,baton->patch
  );

  return lockMaster;
}

void GitPatch::GetHunkWorker::Execute() {
  git_error_clear();

    int result = git_patch_get_hunk(
&baton->out,baton->lines_in_hunk,baton->patch,baton->hunk_idx  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitPatch::GetHunkWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.getHunk"));
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

void GitPatch::GetHunkWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
      Napi::Object result = Napi::Object::New(env);
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("patch").As<Napi::Object>());
             v8ConversionSlot = GitDiffHunk::New(
        env,
        baton->out,
        false
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "hunk"), v8ConversionSlot);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->lines_in_hunk);
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "linesInHunk"), v8ConversionSlot);
         
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
        err = Napi::Error::New(env, "Method getHunk has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.getHunk"));
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
        Napi::Object err = Napi::Error::New(env, "Method getHunk has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.getHunk"));
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
    * @param Number hunk_idx
   * @param Number line_of_hunk
    * @param DiffLine callback
   */
Napi::Value GitPatch::GetLineInHunk(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number hunk_idx is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number line_of_hunk is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  GetLineInHunkBaton* baton = new GetLineInHunkBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->patch = Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  size_t from_hunk_idx;
      from_hunk_idx = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->hunk_idx = from_hunk_idx;
// start convert_from_v8 block
  size_t from_line_of_hunk;
      from_line_of_hunk = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->line_of_hunk = from_line_of_hunk;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  GetLineInHunkWorker *worker = new GetLineInHunkWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitPatch>("patch", info.This().As<Napi::Object>());
           worker->Reference("hunk_idx", info[0]);
            worker->Reference("line_of_hunk", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitPatch::GetLineInHunkWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->patch
  );

  return lockMaster;
}

void GitPatch::GetLineInHunkWorker::Execute() {
  git_error_clear();

    int result = git_patch_get_line_in_hunk(
&baton->out,baton->patch,baton->hunk_idx,baton->line_of_hunk  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitPatch::GetLineInHunkWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.getLineInHunk"));
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

void GitPatch::GetLineInHunkWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("patch").As<Napi::Object>());
             v8ConversionSlot = GitDiffLine::New(
        env,
        baton->out,
        false
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
        err = Napi::Error::New(env, "Method getLineInHunk has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.getLineInHunk"));
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
        Napi::Object err = Napi::Error::New(env, "Method getLineInHunk has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Patch.getLineInHunk"));
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
        * @return Number total_context    * @return Number total_additions    * @return Number total_deletions    */
Napi::Value GitPatch::LineStats(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

      size_t total_context = 0;
      size_t total_additions = 0;
      size_t total_deletions = 0;

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_patch_line_stats(
&          total_context
,&          total_additions
,&          total_deletions
,          Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
        Napi::Object toReturn = Napi::Object::New(env);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  total_context);
  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "total_context"), v8ConversionSlot);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  total_additions);
  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "total_additions"), v8ConversionSlot);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  total_deletions);
  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "total_deletions"), v8ConversionSlot);
        return scope.Escape(toReturn);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitPatch::NumHunks(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_patch_num_hunks(
          Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Number hunk_idx
     * @return Number  result    */
Napi::Value GitPatch::NumLinesInHunk(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number hunk_idx is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_hunk_idx;
      from_hunk_idx = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_patch_num_lines_in_hunk(
          Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_hunk_idx
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Repository  result    */
Napi::Value GitPatch::Owner(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 git_repository * result =     git_patch_owner(
          Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitRepository::New(
        env,
        result,
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
   * @param Number include_context
   * @param Number include_hunk_headers
   * @param Number include_file_headers
     * @return Number  result    */
Napi::Value GitPatch::Size(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number include_context is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number include_hunk_headers is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number include_file_headers is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  int from_include_context;
      from_include_context = (int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_include_hunk_headers;
      from_include_hunk_headers = (int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_include_file_headers;
      from_include_file_headers = (int)   info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_patch_size(
          Napi::ObjectWrap<GitPatch>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_include_context
,          from_include_hunk_headers
,          from_include_file_headers
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
        Napi::Value GitPatch::ConvenientFromDiff(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Diff diff is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ConvenientFromDiffBaton *baton = new ConvenientFromDiffBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->diff = GitDiff::Unwrap(info[0].As<Napi::Object>())->GetValue();

  if (info[1].IsArray()) {
    const Napi::Array indexesArray = info[1].As<Napi::Array>();
    const uint32_t numIndexes = indexesArray.Length();

    for (uint32_t i = 0; i < numIndexes; ++i) {
      Napi::Value value = indexesArray.Get(i);
      int idx = value.As<Napi::Number>().DoubleValue();
      baton->indexes.push_back(idx);
    }
  }

  baton->out = new std::vector<PatchData *>;
  baton->out->reserve(git_diff_num_deltas(baton->diff));

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  ConvenientFromDiffWorker *worker = new ConvenientFromDiffWorker(baton, std::move(callback), cleanupHandles);

  worker->Reference<GitDiff>("diff", info[0]);

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitPatch::ConvenientFromDiffWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->diff);
  return lockMaster;
}

void GitPatch::ConvenientFromDiffWorker::Execute() {
  git_error_clear();

  std::vector<git_patch *> patchesToBeFreed;

  if (baton->indexes.size() > 0) {
    for (int idx : baton->indexes) {
      git_patch *nextPatch;
      int result = git_patch_from_diff(&nextPatch, baton->diff, idx);

      if (result) {
        while (!patchesToBeFreed.empty())
        {
          git_patch_free(patchesToBeFreed.back());
          patchesToBeFreed.pop_back();
        }

        while (!baton->out->empty()) {
          PatchDataFree(baton->out->back());
          baton->out->pop_back();
        }

        baton->error_code = result;

        if (git_error_last()->klass != GIT_ERROR_NONE) {
          baton->error = git_error_dup(git_error_last());
        }

        delete baton->out;
        baton->out = NULL;

        return;
      }

      if (nextPatch != NULL) {
        baton->out->push_back(createFromRaw(nextPatch));
        patchesToBeFreed.push_back(nextPatch);
      }
    }
  } else {
    for (std::size_t i = 0; i < git_diff_num_deltas(baton->diff); ++i) {
      git_patch *nextPatch;
      int result = git_patch_from_diff(&nextPatch, baton->diff, i);

      if (result) {
        while (!patchesToBeFreed.empty())
        {
          git_patch_free(patchesToBeFreed.back());
          patchesToBeFreed.pop_back();
        }

        while (!baton->out->empty()) {
          PatchDataFree(baton->out->back());
          baton->out->pop_back();
        }

        baton->error_code = result;

        if (git_error_last()->klass != GIT_ERROR_NONE) {
          baton->error = git_error_dup(git_error_last());
        }

        delete baton->out;
        baton->out = NULL;

        return;
      }

      if (nextPatch != NULL) {
        baton->out->push_back(createFromRaw(nextPatch));
        patchesToBeFreed.push_back(nextPatch);
      }
    }
  }

  while (!patchesToBeFreed.empty())
  {
    git_patch_free(patchesToBeFreed.back());
    patchesToBeFreed.pop_back();
  }
}

void GitPatch::ConvenientFromDiffWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  while (!baton->out->empty()) {
    PatchDataFree(baton->out->back());
    baton->out->pop_back();
  }

  delete baton->out;

  delete baton;
}

void GitPatch::ConvenientFromDiffWorker::HandleOKCallback() {
  Napi::Env env = Env();
  if (baton->out != NULL) {
    unsigned int size = baton->out->size();
    Napi::Array result = Napi::Array::New(env, size);

    for (unsigned int i = 0; i < size; ++i) {
      result.Set(i, ConvenientPatch::New((void *)baton->out->at(i)));
    }

    delete baton->out;

    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);

    return;
  }

  if (baton->error) {
    Napi::Object err;
    if (baton->error->message) {
      err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
    } else {
      err = Napi::Error::New(env, "Method convenientFromDiff has thrown an error.").Value().As<Napi::Object>();
    }
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Patch.convenientFromDiff"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
    {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);

    return;
  }

  if (baton->error_code < 0) {
    Napi::Object err = Napi::Error::New(env, "method convenientFromDiff has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Patch.convenientFromDiff"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);

    return;
  }

  callback.Call({});
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitPatchTraits>;
 