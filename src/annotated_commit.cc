// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/annotated_commit.h"
#include "bungit_wrapper.cc"

  #include "../include/repository.h"
  #include "../include/oid.h"
  #include "../include/reference.h"
 
#include <iostream>

using namespace std;

  GitAnnotatedCommit::~GitAnnotatedCommit() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                               }

  void GitAnnotatedCommit::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "AnnotatedCommit", {
           StaticMethod("fromFetchhead", &GitAnnotatedCommit::FromFetchhead, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("fromRef", &GitAnnotatedCommit::FromRef, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("fromRevspec", &GitAnnotatedCommit::FromRevspec, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("id", &GitAnnotatedCommit::Id, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("lookup", &GitAnnotatedCommit::Lookup, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("ref", &GitAnnotatedCommit::Ref, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitAnnotatedCommit::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitAnnotatedCommit::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitAnnotatedCommit::Template", constructor_template);
    target.Set(Napi::String::New(env, "AnnotatedCommit"), constructor_template);
  }

 
/*
  * @param Repository repo
   * @param String branch_name
   * @param String remote_url
   * @param Oid id
    * @param AnnotatedCommit callback
   */
Napi::Value GitAnnotatedCommit::FromFetchhead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String branch_name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String remote_url is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3
    || (!info[3].IsObject() && !info[3].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FromFetchheadBaton* baton = new FromFetchheadBaton();

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
  const char * from_branch_name = NULL;

  std::string branch_name = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_branch_name = (const char *) malloc(branch_name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_branch_name, branch_name.c_str(), branch_name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_branch_name) + branch_name.length()), 0, 1);
// end convert_from_v8 block
          baton->branch_name = from_branch_name;
// start convert_from_v8 block
  const char * from_remote_url = NULL;

  std::string remote_url = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_remote_url = (const char *) malloc(remote_url.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_remote_url, remote_url.c_str(), remote_url.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_remote_url) + remote_url.length()), 0, 1);
// end convert_from_v8 block
          baton->remote_url = from_remote_url;
// start convert_from_v8 block
  const git_oid * from_id = NULL;
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

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[3].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->id = from_id;
            baton->idNeedsFree = info[3].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FromFetchheadWorker *worker = new FromFetchheadWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("branch_name", info[1]);
            worker->Reference("remote_url", info[2]);
              worker->Reference<GitOid>("id", info[3]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitAnnotatedCommit::FromFetchheadWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->branch_name
          ,baton->remote_url
          ,baton->id
  );

  return lockMaster;
}

void GitAnnotatedCommit::FromFetchheadWorker::Execute() {
  git_error_clear();

    int result = git_annotated_commit_from_fetchhead(
&baton->out,baton->repo,baton->branch_name,baton->remote_url,baton->id  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitAnnotatedCommit::FromFetchheadWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.fromFetchhead"));
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

      git_annotated_commit_free(baton->out);
      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

void GitAnnotatedCommit::FromFetchheadWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitAnnotatedCommit::New(
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
        err = Napi::Error::New(env, "Method fromFetchhead has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.fromFetchhead"));
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
        Napi::Object err = Napi::Error::New(env, "Method fromFetchhead has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.fromFetchhead"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_annotated_commit_free(baton->out);
  }

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Reference ref
    * @param AnnotatedCommit callback
   */
Napi::Value GitAnnotatedCommit::FromRef(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Reference ref is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FromRefBaton* baton = new FromRefBaton();

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
  const git_reference * from_ref = NULL;
from_ref = Napi::ObjectWrap<GitRefs>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->ref = from_ref;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FromRefWorker *worker = new FromRefWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitRefs>("ref", info[1]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitAnnotatedCommit::FromRefWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->ref
  );

  return lockMaster;
}

void GitAnnotatedCommit::FromRefWorker::Execute() {
  git_error_clear();

    int result = git_annotated_commit_from_ref(
&baton->out,baton->repo,baton->ref  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitAnnotatedCommit::FromRefWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.fromRef"));
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

      git_annotated_commit_free(baton->out);

  delete baton;
}

void GitAnnotatedCommit::FromRefWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitAnnotatedCommit::New(
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
        err = Napi::Error::New(env, "Method fromRef has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.fromRef"));
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
        Napi::Object err = Napi::Error::New(env, "Method fromRef has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.fromRef"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_annotated_commit_free(baton->out);
  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param String revspec
    * @param AnnotatedCommit callback
   */
Napi::Value GitAnnotatedCommit::FromRevspec(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String revspec is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FromRevspecBaton* baton = new FromRevspecBaton();

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
  const char * from_revspec = NULL;

  std::string revspec = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_revspec = (const char *) malloc(revspec.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_revspec, revspec.c_str(), revspec.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_revspec) + revspec.length()), 0, 1);
// end convert_from_v8 block
          baton->revspec = from_revspec;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FromRevspecWorker *worker = new FromRevspecWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("revspec", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitAnnotatedCommit::FromRevspecWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->revspec
  );

  return lockMaster;
}

void GitAnnotatedCommit::FromRevspecWorker::Execute() {
  git_error_clear();

    int result = git_annotated_commit_from_revspec(
&baton->out,baton->repo,baton->revspec  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitAnnotatedCommit::FromRevspecWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.fromRevspec"));
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

      git_annotated_commit_free(baton->out);

  delete baton;
}

void GitAnnotatedCommit::FromRevspecWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitAnnotatedCommit::New(
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
        err = Napi::Error::New(env, "Method fromRevspec has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.fromRevspec"));
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
        Napi::Object err = Napi::Error::New(env, "Method fromRevspec has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.fromRevspec"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_annotated_commit_free(baton->out);
  }


  delete baton;
}

   
/*
     * @return Oid  result    */
Napi::Value GitAnnotatedCommit::Id(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_annotated_commit_id(
          Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
  * @param Repository repo
   * @param Oid id
    * @param AnnotatedCommit callback
   */
Napi::Value GitAnnotatedCommit::Lookup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  LookupBaton* baton = new LookupBaton();

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
  const git_oid * from_id = NULL;
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

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->id = from_id;
            baton->idNeedsFree = info[1].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  LookupWorker *worker = new LookupWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitOid>("id", info[1]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitAnnotatedCommit::LookupWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->id
  );

  return lockMaster;
}

void GitAnnotatedCommit::LookupWorker::Execute() {
  git_error_clear();

    int result = git_annotated_commit_lookup(
&baton->out,baton->repo,baton->id  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitAnnotatedCommit::LookupWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.lookup"));
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

      git_annotated_commit_free(baton->out);
      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

void GitAnnotatedCommit::LookupWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitAnnotatedCommit::New(
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
        err = Napi::Error::New(env, "Method lookup has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.lookup"));
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
        Napi::Object err = Napi::Error::New(env, "Method lookup has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "AnnotatedCommit.lookup"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_annotated_commit_free(baton->out);
  }

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

   
/*
     * @return String  result    */
Napi::Value GitAnnotatedCommit::Ref(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_annotated_commit_ref(
          Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
template class NodeGitWrapper<GitAnnotatedCommitTraits>;
 