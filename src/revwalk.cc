// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/revwalk.h"
#include "bungit_wrapper.cc"

  #include "../include/commit.h"
  #include "../include/functions/copy.h"
  #include "../include/oid.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;

  GitRevwalk::~GitRevwalk() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                           }

  void GitRevwalk::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Revwalk", {
          InstanceMethod("hide", &GitRevwalk::Hide, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("hideGlob", &GitRevwalk::HideGlob, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("hideHead", &GitRevwalk::HideHead, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("hideRef", &GitRevwalk::HideRef, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("create", &GitRevwalk::Create, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("next", &GitRevwalk::Next, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("push", &GitRevwalk::Push, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("pushGlob", &GitRevwalk::PushGlob, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("pushHead", &GitRevwalk::PushHead, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("pushRange", &GitRevwalk::PushRange, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("pushRef", &GitRevwalk::PushRef, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("repository", &GitRevwalk::Repository, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("reset", &GitRevwalk::Reset, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("simplifyFirstParent", &GitRevwalk::SimplifyFirstParent, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("sorting", &GitRevwalk::Sorting, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("commitWalk", &GitRevwalk::CommitWalk, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("fastWalk", &GitRevwalk::FastWalk, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("fileHistoryWalk", &GitRevwalk::FileHistoryWalk, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitRevwalk::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitRevwalk::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitRevwalk::Template", constructor_template);
    target.Set(Napi::String::New(env, "Revwalk"), constructor_template);
  }

  
/*
   * @param Oid commit_id
     * @return Number  result    */
Napi::Value GitRevwalk::Hide(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid commit_id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
// start convert_from_v8 block
  const git_oid * from_commit_id = NULL;
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

    from_commit_id = oidOut;
  }
  else {
from_commit_id = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_commit_id
    );

 int result =     git_revwalk_hide(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_commit_id
    );

      if (info[0].IsString()) {
        free((void *)from_commit_id);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String glob
     * @return Number  result    */
Napi::Value GitRevwalk::HideGlob(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String glob is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_glob = NULL;

  std::string glob = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_glob = (const char *) malloc(glob.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_glob, glob.c_str(), glob.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_glob) + glob.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_glob
    );

 int result =     git_revwalk_hide_glob(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_glob
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
Napi::Value GitRevwalk::HideHead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_revwalk_hide_head(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String refname
     * @return Number  result    */
Napi::Value GitRevwalk::HideRef(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String refname is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_refname = NULL;

  std::string refname = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_refname = (const char *) malloc(refname.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_refname, refname.c_str(), refname.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_refname) + refname.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
    );

 int result =     git_revwalk_hide_ref(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_refname
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
     * @return Revwalk out    */
Napi::Value GitRevwalk::Create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

      git_revwalk * out = 0;
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

 int result =     git_revwalk_new(
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
      Napi::Array owners = Napi::Array::New(env, 0);
          owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_revwalk_repository(out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitRevwalk::New(
        env,
        out,
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
     * @param Oid callback
   */
Napi::Value GitRevwalk::Next(const Napi::CallbackInfo& info) {
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

      baton->out = (git_oid *)malloc(sizeof(git_oid ));
        baton->walk = Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  NextWorker *worker = new NextWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRevwalk>("walk", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRevwalk::NextWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->walk
  );

  return lockMaster;
}

void GitRevwalk::NextWorker::Execute() {
  git_error_clear();

    int result = git_revwalk_next(
baton->out,baton->walk  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRevwalk::NextWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Revwalk.next"));
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

void GitRevwalk::NextWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method next has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Revwalk.next"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Revwalk.next"));
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
     * @return Number  result    */
Napi::Value GitRevwalk::Push(const Napi::CallbackInfo& info) {
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
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_id
    );

 int result =     git_revwalk_push(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
   * @param String glob
     * @return Number  result    */
Napi::Value GitRevwalk::PushGlob(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String glob is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_glob = NULL;

  std::string glob = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_glob = (const char *) malloc(glob.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_glob, glob.c_str(), glob.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_glob) + glob.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_glob
    );

 int result =     git_revwalk_push_glob(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_glob
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
Napi::Value GitRevwalk::PushHead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_revwalk_push_head(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String range
     * @return Number  result    */
Napi::Value GitRevwalk::PushRange(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String range is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_range = NULL;

  std::string range = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_range = (const char *) malloc(range.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_range, range.c_str(), range.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_range) + range.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_range
    );

 int result =     git_revwalk_push_range(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_range
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String refname
     * @return Number  result    */
Napi::Value GitRevwalk::PushRef(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String refname is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_refname = NULL;

  std::string refname = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_refname = (const char *) malloc(refname.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_refname, refname.c_str(), refname.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_refname) + refname.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
    );

 int result =     git_revwalk_push_ref(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_refname
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
Napi::Value GitRevwalk::Repository(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 git_repository * result =     git_revwalk_repository(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return Number  result    */
Napi::Value GitRevwalk::Reset(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_revwalk_reset(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
Napi::Value GitRevwalk::SimplifyFirstParent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_revwalk_simplify_first_parent(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Number sort_mode
     * @return Number  result    */
Napi::Value GitRevwalk::Sorting(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number sort_mode is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  unsigned int from_sort_mode;
      from_sort_mode = (unsigned int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_revwalk_sorting(
          Napi::ObjectWrap<GitRevwalk>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_sort_mode
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
        #define SET_ON_OBJECT(obj, field, data) obj.Set(field, data)

Napi::Object signatureToJavascript(Napi::Env env, const git_signature *signature) {
  Napi::Object signatureObject = Napi::Object::New(env);
  SET_ON_OBJECT(signatureObject, "name", Napi::String::New(env, signature->name));
  SET_ON_OBJECT(signatureObject, "email", Napi::String::New(env, signature->email));
  SET_ON_OBJECT(signatureObject, "date", Napi::Number::New(env, signature->when.time * 1000));
  std::stringstream fullSignature;
  fullSignature << signature->name << " <" << signature << ">";
  SET_ON_OBJECT(signatureObject, "full", Napi::String::New(env, fullSignature.str()));
  return signatureObject;
}

#include <iostream>
class CommitModel {
public:
  CommitModel(git_commit *commit, bool fetchSignature):
    commit(commit),
    fetchSignature(fetchSignature),
    signature({ 0, 0, 0 }),
    signedData({ 0, 0, 0 })
  {
    if (fetchSignature) {
      const int error = git_commit_extract_signature(
        &signature,
        &signedData,
        git_commit_owner(commit),
        const_cast<git_oid *>(git_commit_id(commit)),
        NULL
      );
      if (error != GIT_ENOTFOUND) {
        assert(error == GIT_OK);
      }
    }

    const size_t parentCount = git_commit_parentcount(commit);
    parentIds.reserve(parentCount);
    for (size_t parentIndex = 0; parentIndex < parentCount; ++parentIndex) {
      parentIds.push_back(git_oid_tostr_s(git_commit_parent_id(commit, parentIndex)));
    }
  }

  CommitModel(const CommitModel &) = delete;
  CommitModel(CommitModel &&) = delete;
  CommitModel &operator=(const CommitModel &) = delete;
  CommitModel &operator=(CommitModel &&) = delete;

  Napi::Value toJavascript(Napi::Env env) {
    if (!fetchSignature) {
      Napi::Value commitObject = GitCommit::New(
        env,
        commit,
        true,
        GitRepository::New(
          env,
          git_commit_owner(commit),
          true
        ).As<Napi::Object>()
      );
      commit = NULL;
      return commitObject;
    }

    Napi::Object commitModel = Napi::Object::New(env);
    SET_ON_OBJECT(commitModel, "sha", Napi::String::New(env, git_oid_tostr_s(git_commit_id(commit))));
    SET_ON_OBJECT(commitModel, "message", Napi::String::New(env, git_commit_message(commit)));
    SET_ON_OBJECT(commitModel, "author", signatureToJavascript(env, git_commit_author(commit)));
    SET_ON_OBJECT(commitModel, "committer", signatureToJavascript(env, git_commit_committer(commit)));

    size_t parentCount = parentIds.size();
    Napi::Array parents = Napi::Array::New(env, parentCount);
    for (size_t parentIndex = 0; parentIndex < parentCount; ++parentIndex) {
      parents.Set((uint32_t)parentIndex, Napi::String::New(env, parentIds[parentIndex]));
    }
    SET_ON_OBJECT(commitModel, "parents", parents);

    if (signature.size != 0 || signedData.size != 0) {
      Napi::Object gpgSignature = Napi::Object::New(env);
      if (signature.size != 0) {
        SET_ON_OBJECT(gpgSignature, "signature", Napi::String::New(env, signature.ptr));
      } else {
        SET_ON_OBJECT(gpgSignature, "signature", env.Null());
      }

      if (signedData.size != 0) {
        SET_ON_OBJECT(gpgSignature, "signedData", Napi::String::New(env, signedData.ptr));
      } else {
        SET_ON_OBJECT(gpgSignature, "signedData", env.Null());
      }

      SET_ON_OBJECT(commitModel, "gpgSignature", gpgSignature);
    }

    return commitModel;
  }

  ~CommitModel() {
    git_buf_dispose(&signature);
    git_buf_dispose(&signedData);
    if (commit) {
      git_commit_free(commit);
    }
  }

private:
  git_commit *commit;
  bool fetchSignature;
  git_buf signature, signedData;
  std::vector<std::string> parentIds;
};

Napi::Value GitRevwalk::CommitWalk(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Max count is required and must be a number.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() >= 3 && !info[1].IsNull() && !info[1].IsUndefined() && !info[1].IsObject()) {
    Napi::Error::New(env, "Options must be an object, null, or undefined.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CommitWalkBaton* baton = new CommitWalkBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->max_count = info[0].As<Napi::Number>().Uint32Value();
  std::vector<CommitModel *> *out = new std::vector<CommitModel *>;
  out->reserve(baton->max_count);
  baton->out = static_cast<void *>(out);
  if (info.Length() == 3 && info[1].IsObject()) {
    Napi::Object options = info[1].As<Napi::Object>();
    Napi::String propName = Napi::String::New(env, "returnPlainObjects");
    if (options.Has(propName)) {
      baton->returnPlainObjects = options.Get(propName).ToBoolean().Value();
    } else {
      baton->returnPlainObjects = false;
    }
  } else {
    baton->returnPlainObjects = false;
  }
  baton->walk = GitRevwalk::Unwrap(info.This().As<Napi::Object>())->GetValue();
  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  CommitWalkWorker *worker = new CommitWalkWorker(baton, std::move(callback), cleanupHandles);
  worker->Reference<GitRevwalk>("commitWalk", info.This().As<Napi::Object>());

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRevwalk::CommitWalkWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true);
  return lockMaster;
}

void GitRevwalk::CommitWalkWorker::Execute() {
  giterr_clear();

  std::vector<CommitModel *> *out = static_cast<std::vector<CommitModel *> *>(baton->out);
  for (int i = 0; i < baton->max_count; i++) {
    git_oid next_commit_id;
    baton->error_code = git_revwalk_next(&next_commit_id, baton->walk);

    if (baton->error_code == GIT_ITEROVER) {
      baton->error_code = GIT_OK;
      return;
    }

    if (baton->error_code != GIT_OK) {
      if (giterr_last() != NULL) {
        baton->error = git_error_dup(giterr_last());
      }

      while (out->size()) {
        delete out->back();
        out->pop_back();
      }

      delete out;
      baton->out = NULL;

      return;
    }

    git_commit *commit;
    baton->error_code = git_commit_lookup(&commit, git_revwalk_repository(baton->walk), &next_commit_id);

    if (baton->error_code != GIT_OK) {
      if (giterr_last() != NULL) {
        baton->error = git_error_dup(giterr_last());
      }

      while (out->size()) {
        delete out->back();
        out->pop_back();
      }

      delete out;
      baton->out = NULL;

      return;
    }

    out->push_back(new CommitModel(commit, baton->returnPlainObjects));
  }
}

void GitRevwalk::CommitWalkWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  auto out = static_cast<std::vector<CommitModel *> *>(baton->out);
  while (out->size()) {
    delete out->back();
    out->pop_back();
  }

  delete out;

  delete baton;
}

void GitRevwalk::CommitWalkWorker::HandleOKCallback() {
  Napi::Env env = Env();
  if (baton->out != NULL) {
    std::vector<CommitModel *> *out = static_cast<std::vector<CommitModel *> *>(baton->out);
    const unsigned int size = out->size();
    Napi::Array result = Napi::Array::New(env, size);
    for (unsigned int i = 0; i < size; i++) {
      CommitModel *commitModel = out->at(i);
      result.Set(
        i,
        commitModel->toJavascript(env)
      );
      delete commitModel;
    }

    delete out;

    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  } else if (baton->error) {
    napi_value argv[1] = {
      Napi::Error::New(env, baton->error->message).Value()
    };
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  } else if (baton->error_code < 0) {
    Napi::Object err = Napi::Error::New(env, "Revwalk commitWalk has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Revwalk.commitWalk"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  } else {
    callback.Call({});
  }

  delete baton;
}

        Napi::Value GitRevwalk::FastWalk(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Max count is required and must be a number.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FastWalkBaton* baton = new FastWalkBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->max_count = info[0].As<Napi::Number>().Uint32Value();
  baton->out = new std::vector<git_oid*>;
  baton->out->reserve(baton->max_count);
  baton->walk = GitRevwalk::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  FastWalkWorker *worker = new FastWalkWorker(baton, std::move(callback), cleanupHandles);
  worker->Reference<GitRevwalk>("fastWalk", info.This().As<Napi::Object>());

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRevwalk::FastWalkWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true);
  return lockMaster;
}

void GitRevwalk::FastWalkWorker::Execute()
{
  for (int i = 0; i < baton->max_count; i++)
  {
    git_oid *nextCommit = (git_oid *)malloc(sizeof(git_oid));
    git_error_clear();
    baton->error_code = git_revwalk_next(nextCommit, baton->walk);

    if (baton->error_code != GIT_OK)
    {
      // We couldn't get a commit out of the revwalk. It's either in
      // an error state or there aren't anymore commits in the revwalk.
      free(nextCommit);

      if (baton->error_code != GIT_ITEROVER) {
        baton->error = git_error_dup(git_error_last());

        while(!baton->out->empty())
        {
          // part of me wants to #define shoot free so we can take the
          // baton out back and shoot the oids
          git_oid *oidToFree = baton->out->back();
          free(oidToFree);
          baton->out->pop_back();
        }

        delete baton->out;

        baton->out = NULL;
      }
      else {
        baton->error_code = GIT_OK;
      }

      break;
    }

    baton->out->push_back(nextCommit);
  }
}

void GitRevwalk::FastWalkWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  while(!baton->out->empty()) {
    free(baton->out->back());
    baton->out->pop_back();
  }

  delete baton->out;

  delete baton;
}

void GitRevwalk::FastWalkWorker::HandleOKCallback()
{
  Napi::Env env = Env();
  if (baton->out != NULL)
  {
    unsigned int size = baton->out->size();
    Napi::Array result = Napi::Array::New(env, size);
    for (unsigned int i = 0; i < size; i++) {
      result.Set(i, GitOid::New(env, baton->out->at(i), true));
    }

    delete baton->out;

    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  }
  else
  {
    if (baton->error)
    {
      Napi::Object err;
      if (baton->error->message) {
        err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
      } else {
        err = Napi::Error::New(env, "Method fastWalk has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set("errno", Napi::Number::New(env, baton->error_code));
      err.Set("errorFunction", Napi::String::New(env, "Revwalk.fastWalk"));
      napi_value argv[1] = {
        err
      };
      callback.Call(env.Undefined(), 1, argv);
      if (baton->error->message)
      {
        free((void *)baton->error->message);
      }

      free((void *)baton->error);
    }
    else if (baton->error_code < 0)
    {
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

      if (!callbackFired)
      {
        Napi::Object err = Napi::Error::New(env, "Method next has thrown an error.").Value().As<Napi::Object>();
        err.Set("errno", Napi::Number::New(env, baton->error_code));
        err.Set("errorFunction", Napi::String::New(env, "Revwalk.fastWalk"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    }
    else
    {
      callback.Call({});
    }
  }

  delete baton;
}

        // Note: commit is not owned by this class (must be freed elsewhere)
class FileHistoryEvent {
public:
  FileHistoryEvent(
    git_delta_t inputType,
    bool inputExistsInCurrentTree,
    bool inputIsMergeCommit,
    git_commit *inputCommit,
    const char *inputFrom,
    const char *inputTo
  ):
    type(inputType),
    existsInCurrentTree(inputExistsInCurrentTree),
    isMergeCommit(inputIsMergeCommit),
    from(inputFrom == NULL ? NULL : strdup(inputFrom)),
    to(inputTo == NULL ? NULL : strdup(inputTo)),
    commit(inputCommit)
  {
    if (inputCommit != NULL) {
      const int error = git_commit_dup(&commit, inputCommit);
      assert(error == GIT_OK);
    }
  }

  FileHistoryEvent(const FileHistoryEvent &) = delete;
  FileHistoryEvent(FileHistoryEvent &&) = delete;
  FileHistoryEvent &operator=(const FileHistoryEvent &) = delete;
  FileHistoryEvent &operator=(FileHistoryEvent &&) = delete;

  ~FileHistoryEvent() {
    if (commit != NULL) {
      git_commit_free(commit);
    }

    if(from != NULL) {
      free((void *)from);
    }

    if(to != NULL) {
      free((void *)to);
    }
  }

  Napi::Value toJavascript(Napi::Env env) {
    Napi::Object historyEntry = Napi::Object::New(env);
    Napi::Array owners = Napi::Array::New(env, 0);
    owners.Set(
      owners.Length(),
      GitRepository::New(
        env,
        git_commit_owner(commit),
        true
      ).As<Napi::Object>()
    );
    historyEntry.Set("commit", GitCommit::New(env, commit, true, owners));
    commit = NULL;
    historyEntry.Set("status", Napi::Number::New(env, type));
    historyEntry.Set("isMergeCommit", Napi::Boolean::New(env, isMergeCommit));
    if (type == GIT_DELTA_RENAMED) {
      if (from != NULL) {
        historyEntry.Set("oldName", Napi::String::New(env, from));
      }
      if (to != NULL) {
        historyEntry.Set("newName", Napi::String::New(env, to));
      }
    }
    return historyEntry;
  }

  static int buildHistoryEvent(
    FileHistoryEvent **fileHistoryEvent,
    git_repository *repo,
    git_commit *currentCommit,
    git_tree *currentTree,
    git_tree *parentTree,
    const char *filePath
  ) {
    int errorCode;
    git_tree_entry *currentEntry;
    if (git_tree_entry_bypath(&currentEntry, currentTree, filePath) != GIT_OK) {
      currentEntry = NULL;
    }
    git_tree_entry *parentEntry;
    if (git_tree_entry_bypath(&parentEntry, parentTree, filePath) != GIT_OK) {
      parentEntry = NULL;
    }

    if (!currentEntry && !parentEntry) {
      *fileHistoryEvent = new FileHistoryEvent(GIT_DELTA_UNMODIFIED, false, false, currentCommit, NULL, NULL);
      return GIT_OK;
    }

    // The filePath was added
    if (currentEntry && !parentEntry) {
      git_diff *diff;
      if ((errorCode = git_diff_tree_to_tree(&diff, repo, parentTree, currentTree, NULL)) != GIT_OK) {
        git_tree_entry_free(currentEntry);
        return errorCode;
      }
      if ((errorCode = git_diff_find_similar(diff, NULL)) != GIT_OK) {
        git_diff_free(diff);
        git_tree_entry_free(currentEntry);
        return errorCode;
      }
      const size_t numDeltas = git_diff_num_deltas(diff);
      for (size_t i = 0; i < numDeltas; ++i) {
        const git_diff_delta *delta = git_diff_get_delta(diff, i);
        if (delta->new_file.path != NULL && std::strcmp(delta->new_file.path, filePath) == 0) {
          if (delta->status == GIT_DELTA_RENAMED
            || (delta->old_file.path != NULL && std::strcmp(delta->old_file.path, filePath) != 0)) {
            *fileHistoryEvent = new FileHistoryEvent(
              GIT_DELTA_RENAMED,
              true,
              false,
              currentCommit,
              delta->old_file.path,
              delta->new_file.path
            );
            git_diff_free(diff);
            git_tree_entry_free(currentEntry);
            return GIT_OK;
          }
          break;
        }
      }
      git_diff_free(diff);
      git_tree_entry_free(currentEntry);

      *fileHistoryEvent = new FileHistoryEvent(GIT_DELTA_ADDED, true, false, currentCommit, NULL, NULL);
      return GIT_OK;
    }

    // The filePath was deleted
    if (!currentEntry && parentEntry) {
      git_diff *diff;
      if ((errorCode = git_diff_tree_to_tree(&diff, repo, parentTree, currentTree, NULL)) != GIT_OK) {
        git_tree_entry_free(parentEntry);
        return errorCode;
      }
      if ((errorCode = git_diff_find_similar(diff, NULL)) != GIT_OK) {
        git_diff_free(diff);
        git_tree_entry_free(parentEntry);
        return errorCode;
      }
      const size_t numDeltas = git_diff_num_deltas(diff);
      for (size_t i = 0; i < numDeltas; ++i) {
        const git_diff_delta *delta = git_diff_get_delta(diff, i);
        if (delta->old_file.path != NULL && std::strcmp(delta->old_file.path, filePath) == 0) {
          if (delta->status == GIT_DELTA_RENAMED
            || (delta->new_file.path != NULL && std::strcmp(delta->new_file.path, filePath) != 0)) {
            *fileHistoryEvent = new FileHistoryEvent(
              GIT_DELTA_RENAMED,
              false,
              false,
              currentCommit,
              delta->old_file.path,
              delta->new_file.path
            );
            git_diff_free(diff);
            git_tree_entry_free(parentEntry);
            return GIT_OK;
          }
          break;
        }
      }
      git_diff_free(diff);
      git_tree_entry_free(parentEntry);

      *fileHistoryEvent =  new FileHistoryEvent(GIT_DELTA_DELETED, false, false, currentCommit, NULL, NULL);
      return GIT_OK;
    }

    if (git_oid_cmp(git_tree_entry_id(currentEntry), git_tree_entry_id(parentEntry)) != 0
        || git_tree_entry_filemode(currentEntry) != git_tree_entry_filemode(parentEntry)
    ) {
      git_tree_entry_free(parentEntry);
      git_tree_entry_free(currentEntry);
      *fileHistoryEvent = new FileHistoryEvent(GIT_DELTA_MODIFIED, true, false, currentCommit, NULL, NULL);
      return GIT_OK;
    }

    *fileHistoryEvent = new FileHistoryEvent(GIT_DELTA_UNMODIFIED, true, false, currentCommit, NULL, NULL);
    git_tree_entry_free(parentEntry);
    git_tree_entry_free(currentEntry);
    return GIT_OK;
  }

  git_delta_t type;
  bool existsInCurrentTree, isMergeCommit;
  const char *from, *to;
  git_commit *commit;
};

Napi::Value GitRevwalk::FileHistoryWalk(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "File path to get the history is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Max count is required and must be a number.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FileHistoryWalkBaton* baton = new FileHistoryWalkBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  std::string from_js_file_path = info[0].As<Napi::String>().Utf8Value();
  baton->file_path = strdup(from_js_file_path.c_str());
  baton->max_count = info[1].As<Napi::Number>().Uint32Value();
  baton->out = new std::vector<void *>;
  baton->out->reserve(baton->max_count);
  baton->walk = GitRevwalk::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  FileHistoryWalkWorker *worker = new FileHistoryWalkWorker(baton, std::move(callback), cleanupHandles);
  worker->Reference<GitRevwalk>("fileHistoryWalk", info.This().As<Napi::Object>());

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRevwalk::FileHistoryWalkWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true);
  return lockMaster;
}

void GitRevwalk::FileHistoryWalkWorker::Execute()
{
  git_repository *repo = git_revwalk_repository(baton->walk);
  git_oid currentOid;
  git_error_clear();
  for (
    unsigned int revwalkIterations = 0;
    revwalkIterations < baton->max_count && (baton->error_code = git_revwalk_next(&currentOid, baton->walk)) == GIT_OK;
    ++revwalkIterations
  ) {
    git_commit *currentCommit;
    if ((baton->error_code = git_commit_lookup(&currentCommit, repo, &currentOid)) != GIT_OK) {
      break;
    }

    git_tree *currentTree;
    if ((baton->error_code = git_commit_tree(&currentTree, currentCommit)) != GIT_OK) {
      git_commit_free(currentCommit);
      break;
    }

    const unsigned int parentCount = git_commit_parentcount(currentCommit);
    if (parentCount == 0) {
      git_tree_entry* entry;
      if (git_tree_entry_bypath(&entry, currentTree, baton->file_path) == GIT_OK) {
        baton->out->push_back(new FileHistoryEvent(GIT_DELTA_ADDED, false, false, currentCommit, NULL, NULL));
        git_tree_entry_free(entry);
      }
      git_commit_free(currentCommit);
      git_tree_free(currentTree);
      continue;
    }

    if (parentCount == 1) {
      git_commit *parentCommit;
      if ((baton->error_code = git_commit_parent(&parentCommit, currentCommit, 0)) != GIT_OK) {
        git_commit_free(currentCommit);
        git_tree_free(currentTree);
        break;
      }

      git_tree *parentTree;
      if ((baton->error_code = git_commit_tree(&parentTree, parentCommit)) != GIT_OK) {
        git_commit_free(currentCommit);
        git_commit_free(parentCommit);
        git_tree_free(currentTree);
        break;
      }


      FileHistoryEvent *fileHistoryEvent;
      if ((baton->error_code = FileHistoryEvent::buildHistoryEvent(
        &fileHistoryEvent,
        repo,
        currentCommit,
        currentTree,
        parentTree,
        baton->file_path
      )) != GIT_OK) {
        git_commit_free(currentCommit);
        git_commit_free(parentCommit);
        git_tree_free(currentTree);
        git_tree_free(parentTree);
        break;
      }

      if (fileHistoryEvent->type != GIT_DELTA_UNMODIFIED) {
        baton->out->push_back(fileHistoryEvent);
      }

      git_commit_free(currentCommit);
      git_commit_free(parentCommit);
      git_tree_free(currentTree);
      git_tree_free(parentTree);
      continue;
    }

    std::pair<bool, unsigned int> firstMatchingParentIndex(false, 0);
    bool fileExistsInCurrent = false, fileExistsInSomeParent = false;
    for (unsigned int parentIndex = 0; parentIndex < parentCount; ++parentIndex) {
      git_commit *parentCommit;
      if ((baton->error_code = git_commit_parent(&parentCommit, currentCommit, parentIndex)) != GIT_OK) {
        break;
      }

      git_tree *parentTree;
      if ((baton->error_code = git_commit_tree(&parentTree, parentCommit)) != GIT_OK) {
        git_commit_free(parentCommit);
        break;
      }

      FileHistoryEvent *fileHistoryEvent;
      if ((baton->error_code = FileHistoryEvent::buildHistoryEvent(
        &fileHistoryEvent,
        repo,
        currentCommit,
        currentTree,
        parentTree,
        baton->file_path
      )) != GIT_OK) {
        git_tree_free(parentTree);
        git_commit_free(parentCommit);
        break;
      }

      switch (fileHistoryEvent->type) {
        case GIT_DELTA_ADDED: {
          fileExistsInCurrent = true;
          break;
        }
        case GIT_DELTA_MODIFIED: {
          fileExistsInCurrent = true;
          fileExistsInSomeParent = true;
          break;
        }
        case GIT_DELTA_DELETED: {
          fileExistsInSomeParent = true;
          break;
        }
        case GIT_DELTA_RENAMED: {
          if (fileHistoryEvent->existsInCurrentTree) {
            fileExistsInCurrent = true;
          } else {
            fileExistsInSomeParent = true;
          }
          break;
        }
        case GIT_DELTA_UNMODIFIED: {
          if (fileHistoryEvent->existsInCurrentTree) {
            fileExistsInCurrent = true;
            fileExistsInSomeParent = true;
          }
          firstMatchingParentIndex = std::make_pair(true, parentIndex);
          break;
        }
        default: {
          break;
        }
      }

      delete fileHistoryEvent;
      git_commit_free(parentCommit);
      git_tree_free(parentTree);

     if (firstMatchingParentIndex.first) {
        break;
      }
    }

    if (baton->error_code != GIT_OK) {
      git_tree_free(currentTree);
      git_commit_free(currentCommit);
      break;
    }

    if (!firstMatchingParentIndex.first) {
      assert(fileExistsInCurrent || fileExistsInSomeParent);
      git_delta_t mergeType = GIT_DELTA_UNREADABLE; // It will never result in this case because of the assertion above.
      if (fileExistsInCurrent && fileExistsInSomeParent) {
        mergeType = GIT_DELTA_MODIFIED;
      } else if (fileExistsInCurrent) {
        mergeType = GIT_DELTA_ADDED;
      } else if (fileExistsInSomeParent) {
        mergeType = GIT_DELTA_DELETED;
      }

      FileHistoryEvent *fileHistoryEvent = new FileHistoryEvent(
        mergeType,
        mergeType != GIT_DELTA_DELETED,
        true,
        currentCommit,
        NULL,
        NULL
      );
      baton->out->push_back(fileHistoryEvent);
      git_tree_free(currentTree);
      git_commit_free(currentCommit);
      continue;
    }

    assert(firstMatchingParentIndex.first);
    for (unsigned int parentIndex = 0; parentIndex < parentCount; ++parentIndex) {
      if (parentIndex == firstMatchingParentIndex.second) {
        continue;
      }

      const git_oid *parentOid = git_commit_parent_id(currentCommit, parentIndex);
      assert(parentOid != NULL);
      git_revwalk_hide(baton->walk, parentOid);
    }
    git_commit_free(currentCommit);
    git_tree_free(currentTree);
  }

  if (baton->error_code != GIT_OK && baton->error_code != GIT_ITEROVER) {
    // Something went wrong in our loop, discard everything in the async worker
    for (unsigned int i = 0; i < baton->out->size(); ++i) {
      delete static_cast<FileHistoryEvent *>(baton->out->at(i));
    }
    delete baton->out;
    baton->out = NULL;
    baton->error = git_error_dup(git_error_last());
  }
  free((void *)baton->file_path);
  baton->file_path = NULL;
}

void GitRevwalk::FileHistoryWalkWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  for (unsigned int i = 0; i < baton->out->size(); ++i) {
    delete static_cast<FileHistoryEvent *>(baton->out->at(i));
  }

  delete baton->out;

  free((void *)baton->file_path);

  delete baton;
}

void GitRevwalk::FileHistoryWalkWorker::HandleOKCallback()
{
  Napi::Env env = Env();
  if (baton->out != NULL) {
    const unsigned int size = baton->out->size();
    Napi::Array result = Napi::Array::New(env, size);
    for (unsigned int i = 0; i < size; i++) {
      FileHistoryEvent *batonResult = static_cast<FileHistoryEvent *>(baton->out->at(i));
      result.Set(i, batonResult->toJavascript(env));
      delete batonResult;
    }

    result.Set("reachedEndOfHistory", Napi::Boolean::New(env, baton->error_code == GIT_ITEROVER));

    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);

    delete baton->out;
    return;
  }

  if (baton->error) {
    Napi::Object err;
    if (baton->error->message) {
      err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
    } else {
      err = Napi::Error::New(env, "Method fileHistoryWalk has thrown an error.").Value().As<Napi::Object>();
    }
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Revwalk.fileHistoryWalk"));
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
    Napi::Object err = Napi::Error::New(env, "Method next has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Revwalk.fileHistoryWalk"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
    return;
  }

  callback.Call({});

  delete baton;
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitRevwalkTraits>;
 