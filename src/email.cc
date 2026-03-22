// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/email.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/email.h"
#include "bungit_wrapper.cc"

  #include "../include/buf.h"
  #include "../include/commit.h"
  #include "../include/email_create_options.h"
  #include "../include/diff.h"
  #include "../include/oid.h"
  #include "../include/signature.h"
 
#include <iostream>

using namespace std;

 
  void GitEmail::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

       Napi::Object object = Napi::Object::New(env);
         object.Set("createFromCommit", Napi::Function::New(env, CreateFromCommit));
         object.Set("createFromDiff", Napi::Function::New(env, CreateFromDiff));
  
    target.Set(
      Napi::String::New(env, "Email"),
      object
    );
  }

 
/*
  * @param Commit commit
   * @param EmailCreateOptions opts
    * @param Buf callback
   */
Napi::Value GitEmail::CreateFromCommit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Commit commit is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "EmailCreateOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CreateFromCommitBaton* baton = new CreateFromCommitBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_commit * from_commit = NULL;
from_commit = Napi::ObjectWrap<GitCommit>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->commit = from_commit;
            {
            auto conversionResult = ConfigurableGitEmailCreateOptions::fromJavascript(nodegitContext, info[1]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CreateFromCommitWorker *worker = new CreateFromCommitWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitCommit>("commit", info[0]);
             worker->Reference("opts", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitEmail::CreateFromCommitWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->commit
          ,baton->opts
  );

  return lockMaster;
}

void GitEmail::CreateFromCommitWorker::Execute() {
  git_error_clear();

    int result = git_email_create_from_commit(
baton->out,baton->commit,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitEmail::CreateFromCommitWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Email.createFromCommit"));
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

void GitEmail::CreateFromCommitWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method createFromCommit has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Email.createFromCommit"));
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
        Napi::Object err = Napi::Error::New(env, "Method createFromCommit has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Email.createFromCommit"));
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

  
/*
  * @param Diff diff
   * @param Number patch_idx
   * @param Number patch_count
   * @param Oid commit_id
   * @param String summary
   * @param String body
   * @param Signature author
   * @param EmailCreateOptions opts
    * @param Buf callback
   */
Napi::Value GitEmail::CreateFromDiff(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Diff diff is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number patch_idx is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number patch_count is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3
    || (!info[3].IsObject() && !info[3].IsString())) {
    Napi::Error::New(env, "Oid commit_id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 4 || !info[4].IsString()) {
    Napi::Error::New(env, "String summary is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 5 || !info[5].IsString()) {
    Napi::Error::New(env, "String body is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 6 || !info[6].IsObject()) {
    Napi::Error::New(env, "Signature author is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 7 || !info[7].IsObject()) {
    Napi::Error::New(env, "EmailCreateOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CreateFromDiffBaton* baton = new CreateFromDiffBaton();

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
  size_t from_patch_idx;
      from_patch_idx = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->patch_idx = from_patch_idx;
// start convert_from_v8 block
  size_t from_patch_count;
      from_patch_count = (size_t)   info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->patch_count = from_patch_count;
// start convert_from_v8 block
  const git_oid * from_commit_id = NULL;
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

    from_commit_id = oidOut;
  }
  else {
from_commit_id = Napi::ObjectWrap<GitOid>::Unwrap(info[3].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->commit_id = from_commit_id;
            baton->commit_idNeedsFree = info[3].IsString();
// start convert_from_v8 block
  const char * from_summary = NULL;

  std::string summary = info[4].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_summary = (const char *) malloc(summary.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_summary, summary.c_str(), summary.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_summary) + summary.length()), 0, 1);
// end convert_from_v8 block
          baton->summary = from_summary;
// start convert_from_v8 block
  const char * from_body = NULL;

  std::string body = info[5].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_body = (const char *) malloc(body.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_body, body.c_str(), body.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_body) + body.length()), 0, 1);
// end convert_from_v8 block
          baton->body = from_body;
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Napi::ObjectWrap<GitSignature>::Unwrap(info[6].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->author = from_author;
            {
            auto conversionResult = ConfigurableGitEmailCreateOptions::fromJavascript(nodegitContext, info[7]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CreateFromDiffWorker *worker = new CreateFromDiffWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitDiff>("diff", info[0]);
             worker->Reference("patch_idx", info[1]);
            worker->Reference("patch_count", info[2]);
              worker->Reference<GitOid>("commit_id", info[3]);
             worker->Reference("summary", info[4]);
            worker->Reference("body", info[5]);
              worker->Reference<GitSignature>("author", info[6]);
             worker->Reference("opts", info[7]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitEmail::CreateFromDiffWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->diff
          ,baton->commit_id
          ,baton->summary
          ,baton->body
          ,baton->author
          ,baton->opts
  );

  return lockMaster;
}

void GitEmail::CreateFromDiffWorker::Execute() {
  git_error_clear();

    int result = git_email_create_from_diff(
baton->out,baton->diff,baton->patch_idx,baton->patch_count,baton->commit_id,baton->summary,baton->body,baton->author,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitEmail::CreateFromDiffWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Email.createFromDiff"));
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
      if (baton->commit_idNeedsFree) {
        baton->commit_idNeedsFree = false;
        free((void *)baton->commit_id);
      }

  delete baton;
}

void GitEmail::CreateFromDiffWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method createFromDiff has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Email.createFromDiff"));
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
        Napi::Object err = Napi::Error::New(env, "Method createFromDiff has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Email.createFromDiff"));
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
      if (baton->commit_idNeedsFree) {
        baton->commit_idNeedsFree = false;
        free((void *)baton->commit_id);
      }

  delete baton;
}

     