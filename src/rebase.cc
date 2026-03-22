// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/rebase.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
  #include "../include/signature.h"
  #include "../include/repository.h"
  #include "../include/annotated_commit.h"
  #include "../include/rebase_options.h"
  #include "../include/index.h"
  #include "../include/rebase_operation.h"
 
#include <iostream>

using namespace std;

  GitRebase::~GitRebase() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                             }

  void GitRebase::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Rebase", {
          InstanceMethod("abort", &GitRebase::Abort, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("commit", &GitRebase::Commit, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("finish", &GitRebase::Finish, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("init", &GitRebase::Init, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("inmemoryIndex", &GitRebase::InmemoryIndex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("next", &GitRebase::Next, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("ontoId", &GitRebase::OntoId, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("ontoName", &GitRebase::OntoName, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("open", &GitRebase::Open, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("operationByIndex", &GitRebase::OperationByindex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("operationCurrent", &GitRebase::OperationCurrent, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("operationEntrycount", &GitRebase::OperationEntrycount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("origHeadId", &GitRebase::OrigHeadId, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("origHeadName", &GitRebase::OrigHeadName, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitRebase::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitRebase::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitRebase::Template", constructor_template);
    target.Set(Napi::String::New(env, "Rebase"), constructor_template);
  }

 
/*
     */
Napi::Value GitRebase::Abort(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AbortBaton* baton = new AbortBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->rebase = Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  AbortWorker *worker = new AbortWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRebase>("rebase", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRebase::AbortWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->rebase
  );

  return lockMaster;
}

void GitRebase::AbortWorker::Execute() {
  git_error_clear();

    int result = git_rebase_abort(
baton->rebase  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRebase::AbortWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.abort"));
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

void GitRebase::AbortWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method abort has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.abort"));
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
        Napi::Object err = Napi::Error::New(env, "Method abort has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.abort"));
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
    * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
    * @param Oid callback
   */
Napi::Value GitRebase::Commit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Signature committer is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CommitBaton* baton = new CommitBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->id = (git_oid *)malloc(sizeof(git_oid ));
        baton->rebase = Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_signature * from_author = NULL;
    if ((info.Length() - 1) > 0 && info[0].IsObject()) {
from_author = Napi::ObjectWrap<GitSignature>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
  else {
    from_author = 0;
  }
// end convert_from_v8 block
          baton->author = from_author;
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Napi::ObjectWrap<GitSignature>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->committer = from_committer;
// start convert_from_v8 block
  const char * from_message_encoding = NULL;
    if ((info.Length() - 1) > 2 && info[2].IsString()) {

  std::string message_encoding = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message_encoding = (const char *) malloc(message_encoding.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message_encoding, message_encoding.c_str(), message_encoding.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message_encoding) + message_encoding.length()), 0, 1);
  }
  else {
    from_message_encoding = 0;
  }
// end convert_from_v8 block
          baton->message_encoding = from_message_encoding;
// start convert_from_v8 block
  const char * from_message = NULL;
    if ((info.Length() - 1) > 3 && info[3].IsString()) {

  std::string message = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message = (const char *) malloc(message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message, message.c_str(), message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message) + message.length()), 0, 1);
  }
  else {
    from_message = 0;
  }
// end convert_from_v8 block
          baton->message = from_message;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CommitWorker *worker = new CommitWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRebase>("rebase", info.This().As<Napi::Object>());
             worker->Reference<GitSignature>("author", info[0]);
               worker->Reference<GitSignature>("committer", info[1]);
             worker->Reference("message_encoding", info[2]);
            worker->Reference("message", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRebase::CommitWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->id
          ,baton->rebase
          ,baton->author
          ,baton->committer
          ,baton->message_encoding
          ,baton->message
  );

  return lockMaster;
}

void GitRebase::CommitWorker::Execute() {
  git_error_clear();

    int result = git_rebase_commit(
baton->id,baton->rebase,baton->author,baton->committer,baton->message_encoding,baton->message  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRebase::CommitWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.commit"));
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

void GitRebase::CommitWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->id != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        baton->id,
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
        err = Napi::Error::New(env, "Method commit has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.commit"));
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
        Napi::Object err = Napi::Error::New(env, "Method commit has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.commit"));
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
   * @param Signature signature
     * @return Number  result    */
Napi::Value GitRebase::Finish(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

// start convert_from_v8 block
  const git_signature * from_signature = NULL;
    if ((info.Length() - 1) > 0 && info[0].IsObject()) {
from_signature = Napi::ObjectWrap<GitSignature>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
  else {
    from_signature = 0;
  }
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_signature
    );

 int result =     git_rebase_finish(
          Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_signature
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
   * @param AnnotatedCommit branch
   * @param AnnotatedCommit upstream
   * @param AnnotatedCommit onto
   * @param RebaseOptions opts
    * @param Rebase callback
   */
Napi::Value GitRebase::Init(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "AnnotatedCommit branch is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  InitBaton* baton = new InitBaton();

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
  const git_annotated_commit * from_branch = NULL;
from_branch = Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->branch = from_branch;
// start convert_from_v8 block
  const git_annotated_commit * from_upstream = NULL;
    if ((info.Length() - 1) > 2 && info[2].IsObject()) {
from_upstream = Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
  else {
    from_upstream = 0;
  }
// end convert_from_v8 block
          baton->upstream = from_upstream;
// start convert_from_v8 block
  const git_annotated_commit * from_onto = NULL;
    if ((info.Length() - 1) > 3 && info[3].IsObject()) {
from_onto = Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(info[3].As<Napi::Object>())->GetValue();
  }
  else {
    from_onto = 0;
  }
// end convert_from_v8 block
          baton->onto = from_onto;
          if (info[4].IsNull() || info[4].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitRebaseOptions::fromJavascript(nodegitContext, info[4]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  InitWorker *worker = new InitWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitAnnotatedCommit>("branch", info[1]);
               worker->Reference<GitAnnotatedCommit>("upstream", info[2]);
               worker->Reference<GitAnnotatedCommit>("onto", info[3]);
             worker->Reference("opts", info[4]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRebase::InitWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->branch
          ,baton->upstream
          ,baton->onto
          ,baton->opts
  );

  return lockMaster;
}

void GitRebase::InitWorker::Execute() {
  git_error_clear();

    int result = git_rebase_init(
&baton->out,baton->repo,baton->branch,baton->upstream,baton->onto,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRebase::InitWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.init"));
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

      git_rebase_free(baton->out);

  delete baton;
}

void GitRebase::InitWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitRebase::New(
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
                    {
              auto objWrap = Napi::ObjectWrap<GitRebase>::Unwrap(result.As<Napi::Object>());
             objWrap->SaveCleanupHandle(cleanupHandles["opts"]);
          }
    
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
        err = Napi::Error::New(env, "Method init has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.init"));
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
        Napi::Object err = Napi::Error::New(env, "Method init has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.init"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_rebase_free(baton->out);
  }


  delete baton;
}

   
/*
 * @param Index index
       * @return Number  result    */
Napi::Value GitRebase::InmemoryIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Index index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_index ** from_index = NULL;
*from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_index
            ,
              Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_rebase_inmemory_index(
          from_index
,          Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
     * @param RebaseOperation callback
   */
Napi::Value GitRebase::Next(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  NextBaton* baton = new NextBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->rebase = Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  NextWorker *worker = new NextWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRebase>("rebase", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRebase::NextWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->rebase
  );

  return lockMaster;
}

void GitRebase::NextWorker::Execute() {
  git_error_clear();

    int result = git_rebase_next(
&baton->operation,baton->rebase  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRebase::NextWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.next"));
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

void GitRebase::NextWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->operation != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("rebase").As<Napi::Object>());
             v8ConversionSlot = GitRebaseOperation::New(
        env,
        baton->operation,
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
        err = Napi::Error::New(env, "Method next has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.next"));
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
        Napi::Object err = Napi::Error::New(env, "Method next has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.next"));
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
     * @return Oid  result    */
Napi::Value GitRebase::OntoId(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_rebase_onto_id(
          Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitOid::New(
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
     * @return String  result    */
Napi::Value GitRebase::OntoName(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_rebase_onto_name(
          Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
   * @param RebaseOptions opts
    * @param Rebase callback
   */
Napi::Value GitRebase::Open(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
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
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
          if (info[1].IsNull() || info[1].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitRebaseOptions::fromJavascript(nodegitContext, info[1]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  OpenWorker *worker = new OpenWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("opts", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRebase::OpenWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->opts
  );

  return lockMaster;
}

void GitRebase::OpenWorker::Execute() {
  git_error_clear();

    int result = git_rebase_open(
&baton->out,baton->repo,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRebase::OpenWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.open"));
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

      git_rebase_free(baton->out);

  delete baton;
}

void GitRebase::OpenWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitRebase::New(
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
              {
              auto objWrap = Napi::ObjectWrap<GitRebase>::Unwrap(result.As<Napi::Object>());
             objWrap->SaveCleanupHandle(cleanupHandles["opts"]);
          }
    
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
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.open"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Rebase.open"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_rebase_free(baton->out);
  }


  delete baton;
}

   
/*
   * @param Number idx
     * @return RebaseOperation  result    */
Napi::Value GitRebase::OperationByindex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number idx is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_idx;
      from_idx = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 git_rebase_operation * result =     git_rebase_operation_byindex(
          Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
            owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitRebaseOperation::New(
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
     * @return Number  result    */
Napi::Value GitRebase::OperationCurrent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_rebase_operation_current(
          Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
Napi::Value GitRebase::OperationEntrycount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_rebase_operation_entrycount(
          Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
Napi::Value GitRebase::OrigHeadId(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_rebase_orig_head_id(
          Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitOid::New(
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
     * @return String  result    */
Napi::Value GitRebase::OrigHeadName(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_rebase_orig_head_name(
          Napi::ObjectWrap<GitRebase>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitRebaseTraits>;
 