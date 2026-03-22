// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/transaction.h"
#include "bungit_wrapper.cc"

  #include "../include/repository.h"
  #include "../include/reflog.h"
  #include "../include/signature.h"
  #include "../include/oid.h"
 
#include <iostream>

using namespace std;

  GitTransaction::~GitTransaction() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                     }

  void GitTransaction::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Transaction", {
          InstanceMethod("commit", &GitTransaction::Commit, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("lockRef", &GitTransaction::LockRef, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("create", &GitTransaction::Create, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("remove", &GitTransaction::Remove, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setReflog", &GitTransaction::SetReflog, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setSymbolicTarget", &GitTransaction::SetSymbolicTarget, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setTarget", &GitTransaction::SetTarget, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitTransaction::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitTransaction::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitTransaction::Template", constructor_template);
    target.Set(Napi::String::New(env, "Transaction"), constructor_template);
  }

  
/*
     * @return Number  result    */
Napi::Value GitTransaction::Commit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_transaction_commit(
          Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
Napi::Value GitTransaction::LockRef(const Napi::CallbackInfo& info) {
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
              Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
    );

 int result =     git_transaction_lock_ref(
          Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
    * @param Transaction callback
   */
Napi::Value GitTransaction::Create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CreateBaton* baton = new CreateBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CreateWorker *worker = new CreateWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitTransaction::CreateWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
  );

  return lockMaster;
}

void GitTransaction::CreateWorker::Execute() {
  git_error_clear();

    int result = git_transaction_new(
&baton->out,baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitTransaction::CreateWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Transaction.create"));
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

      git_transaction_free(baton->out);

  delete baton;
}

void GitTransaction::CreateWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitTransaction::New(
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
        err = Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Transaction.create"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Transaction.create"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_transaction_free(baton->out);
  }


  delete baton;
}

   
/*
   * @param String refname
     * @return Number  result    */
Napi::Value GitTransaction::Remove(const Napi::CallbackInfo& info) {
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
              Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
    );

 int result =     git_transaction_remove(
          Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
   * @param String refname
   * @param Reflog reflog
     * @return Number  result    */
Napi::Value GitTransaction::SetReflog(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String refname is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Reflog reflog is required.").ThrowAsJavaScriptException();
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
// start convert_from_v8 block
  const git_reflog * from_reflog = NULL;
from_reflog = Napi::ObjectWrap<GitReflog>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
            ,
              from_reflog
    );

 int result =     git_transaction_set_reflog(
          Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_refname
,          from_reflog
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
   * @param String target
   * @param Signature sig
   * @param String msg
     * @return Number  result    */
Napi::Value GitTransaction::SetSymbolicTarget(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String refname is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String target is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Signature sig is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsString()) {
    Napi::Error::New(env, "String msg is required.").ThrowAsJavaScriptException();
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
// start convert_from_v8 block
  const char * from_target = NULL;

  std::string target = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_target = (const char *) malloc(target.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_target, target.c_str(), target.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_target) + target.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_sig = NULL;
from_sig = Napi::ObjectWrap<GitSignature>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_msg = NULL;

  std::string msg = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_msg = (const char *) malloc(msg.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_msg, msg.c_str(), msg.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_msg) + msg.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
            ,
              from_target
            ,
              from_sig
            ,
              from_msg
    );

 int result =     git_transaction_set_symbolic_target(
          Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_refname
,          from_target
,          from_sig
,          from_msg
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
   * @param Oid target
   * @param Signature sig
   * @param String msg
     * @return Number  result    */
Napi::Value GitTransaction::SetTarget(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String refname is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid target is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Signature sig is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsString()) {
    Napi::Error::New(env, "String msg is required.").ThrowAsJavaScriptException();
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
// start convert_from_v8 block
  const git_oid * from_target = NULL;
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

    from_target = oidOut;
  }
  else {
from_target = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_sig = NULL;
from_sig = Napi::ObjectWrap<GitSignature>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_msg = NULL;

  std::string msg = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_msg = (const char *) malloc(msg.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_msg, msg.c_str(), msg.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_msg) + msg.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
            ,
              from_target
            ,
              from_sig
            ,
              from_msg
    );

 int result =     git_transaction_set_target(
          Napi::ObjectWrap<GitTransaction>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_refname
,          from_target
,          from_sig
,          from_msg
    );

      if (info[1].IsString()) {
        free((void *)from_target);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitTransactionTraits>;
 