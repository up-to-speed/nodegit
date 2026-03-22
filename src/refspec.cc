// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/refspec.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitRefspec::~GitRefspec() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                   }

  void GitRefspec::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Refspec", {
          InstanceMethod("direction", &GitRefspec::Direction, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("dst", &GitRefspec::Dst, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("dstMatches", &GitRefspec::DstMatches, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("force", &GitRefspec::Force, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("parse", &GitRefspec::Parse, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("src", &GitRefspec::Src, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("srcMatches", &GitRefspec::SrcMatches, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("srcMatchesNegative", &GitRefspec::SrcMatchesNegative, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("string", &GitRefspec::String, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitRefspec::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitRefspec::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitRefspec::Template", constructor_template);
    target.Set(Napi::String::New(env, "Refspec"), constructor_template);
  }

  
/*
     * @return Number  result    */
Napi::Value GitRefspec::Direction(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 git_direction result =     git_refspec_direction(
          Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return String  result    */
Napi::Value GitRefspec::Dst(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_refspec_dst(
          Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
   * @param String refname
     * @return Number  result    */
Napi::Value GitRefspec::DstMatches(const Napi::CallbackInfo& info) {
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
              Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
    );

 int result =     git_refspec_dst_matches(
          Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return Number  result    */
Napi::Value GitRefspec::Force(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_refspec_force(
          Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
  * @param String input
   * @param Number is_fetch
    * @param Refspec callback
   */
Napi::Value GitRefspec::Parse(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String input is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number is_fetch is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ParseBaton* baton = new ParseBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const char * from_input = NULL;

  std::string input = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_input = (const char *) malloc(input.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_input, input.c_str(), input.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_input) + input.length()), 0, 1);
// end convert_from_v8 block
          baton->input = from_input;
// start convert_from_v8 block
  int from_is_fetch;
      from_is_fetch = (int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->is_fetch = from_is_fetch;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ParseWorker *worker = new ParseWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("input", info[0]);
            worker->Reference("is_fetch", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRefspec::ParseWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->input
  );

  return lockMaster;
}

void GitRefspec::ParseWorker::Execute() {
  git_error_clear();

    int result = git_refspec_parse(
&baton->refspec,baton->input,baton->is_fetch  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRefspec::ParseWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Refspec.parse"));
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

      git_refspec_free(baton->refspec);

  delete baton;
}

void GitRefspec::ParseWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->refspec != NULL) {
        v8ConversionSlot = GitRefspec::New(
        env,
        baton->refspec,
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
        err = Napi::Error::New(env, "Method parse has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Refspec.parse"));
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
        Napi::Object err = Napi::Error::New(env, "Method parse has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Refspec.parse"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_refspec_free(baton->refspec);
  }


  delete baton;
}

   
/*
     * @return String  result    */
Napi::Value GitRefspec::Src(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_refspec_src(
          Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
   * @param String refname
     * @return Number  result    */
Napi::Value GitRefspec::SrcMatches(const Napi::CallbackInfo& info) {
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
              Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
    );

 int result =     git_refspec_src_matches(
          Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return Number  result    */
Napi::Value GitRefspec::SrcMatchesNegative(const Napi::CallbackInfo& info) {
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
              Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_refname
    );

 int result =     git_refspec_src_matches_negative(
          Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return String  result    */
Napi::Value GitRefspec::String(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_refspec_string(
          Napi::ObjectWrap<GitRefspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
template class NodeGitWrapper<GitRefspecTraits>;
 