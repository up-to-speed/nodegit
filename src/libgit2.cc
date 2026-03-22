// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/libgit2.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

 
  void GitLibgit2::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

       Napi::Object object = Napi::Object::New(env);
         object.Set("featureBackend", Napi::Function::New(env, FeatureBackend));
         object.Set("features", Napi::Function::New(env, Features));
         object.Set("init", Napi::Function::New(env, Init));
         object.Set("opts", Napi::Function::New(env, Opts));
         object.Set("prerelease", Napi::Function::New(env, Prerelease));
         object.Set("shutdown", Napi::Function::New(env, Shutdown));
         object.Set("version", Napi::Function::New(env, Version));
  
    target.Set(
      Napi::String::New(env, "Libgit2"),
      object
    );
  }

  
/*
 * @param Number feature
     * @return String  result    */
Napi::Value GitLibgit2::FeatureBackend(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number feature is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_feature_t from_feature;
      from_feature = (git_feature_t)  (int) info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
    );

 const char * result =     git_libgit2_feature_backend(
          from_feature
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
   * @return Number  result    */
Napi::Value GitLibgit2::Features(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
    );

 int result =     git_libgit2_features(
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
Napi::Value GitLibgit2::Init(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
    );

 int result =     git_libgit2_init(
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
        Napi::Value GitLibgit2::Opts(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number option is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  const int from_option = (int)info[0].As<Napi::Number>().DoubleValue();

  git_error_clear();

  Napi::Value to = env.Undefined();
  switch (from_option) {
    // GET size_t
    case GIT_OPT_GET_MWINDOW_SIZE:
    case GIT_OPT_GET_MWINDOW_MAPPED_LIMIT:
    case GIT_OPT_GET_PACK_MAX_OBJECTS: {
      size_t option_value;
      if (git_libgit2_opts(from_option, &option_value)) {
        Napi::Error::New(env, "git_libgit2_opts failed").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      to = Napi::Number::New(env, option_value);
      break;
    }
    // GET int
    case GIT_OPT_GET_OWNER_VALIDATION: {
      int option_value;
      if (git_libgit2_opts(from_option, &option_value)) {
        Napi::Error::New(env, "git_libgit2_opts failed").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      to = Napi::Number::New(env, option_value);
      break;
    }
    // GET unsigned long
    case GIT_OPT_GET_WINDOWS_SHAREMODE: {
      unsigned long option_value;
      if (git_libgit2_opts(from_option, &option_value)) {
        Napi::Error::New(env, "git_libgit2_opts failed").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      to = Napi::Number::New(env, option_value);
      break;
    }
    // GET ssize_t
    case GIT_OPT_GET_CACHED_MEMORY: {
      ssize_t option_value;
      if (git_libgit2_opts(from_option, &option_value)) {
        Napi::Error::New(env, "git_libgit2_opts failed").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      to = Napi::Number::New(env, option_value);
      break;
    }
    // GET git_buf
    case GIT_OPT_GET_TEMPLATE_PATH:
    case GIT_OPT_GET_USER_AGENT: {
      git_buf option_value = { 0 };
      if (git_libgit2_opts(from_option, &option_value)) {
        Napi::Error::New(env, "git_libgit2_opts failed").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      to = Napi::String::New(env, option_value.ptr, option_value.size);
      git_buf_dispose(&option_value);
      break;
    }
    case GIT_OPT_GET_SEARCH_PATH: {
      git_buf option_value = { 0 };
      if (info.Length() < 2 || !info[1].IsNumber()) {
        Napi::Error::New(env, "Number option is required.").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      const int level = (int)info[1].As<Napi::Number>().DoubleValue();
      if (git_libgit2_opts(from_option, level, &option_value)) {
        Napi::Error::New(env, "git_libgit2_opts failed").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      to = Napi::String::New(env, option_value.ptr, option_value.size);
      git_buf_dispose(&option_value);
      break;
    }
    // SET int
    case GIT_OPT_ENABLE_CACHING:
    case GIT_OPT_ENABLE_STRICT_OBJECT_CREATION:
    case GIT_OPT_ENABLE_STRICT_SYMBOLIC_REF_CREATION:
    case GIT_OPT_ENABLE_OFS_DELTA:
    case GIT_OPT_ENABLE_FSYNC_GITDIR:
    case GIT_OPT_ENABLE_STRICT_HASH_VERIFICATION:
    case GIT_OPT_ENABLE_UNSAVED_INDEX_SAFETY:
    case GIT_OPT_DISABLE_PACK_KEEP_FILE_CHECKS:
    case GIT_OPT_SET_OWNER_VALIDATION: {
      if (info.Length() < 2 || !info[1].IsNumber()) {
        Napi::Error::New(env, "Number option is required.").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      const int option_arg = (int)info[1].As<Napi::Number>().DoubleValue();
      if (git_libgit2_opts(from_option, option_arg)) {
        Napi::Error::New(env, "git_libgit2_opts failed").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      break;
    }
    // SET size_t
    case GIT_OPT_SET_MWINDOW_SIZE:
    case GIT_OPT_SET_MWINDOW_MAPPED_LIMIT:
    case GIT_OPT_SET_PACK_MAX_OBJECTS: {
      if (info.Length() < 2 || !info[1].IsNumber()) {
        Napi::Error::New(env, "Number option is required.").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      const size_t option_arg = (size_t)info[1].As<Napi::Number>().DoubleValue();
      if (git_libgit2_opts(from_option, option_arg)) {
        Napi::Error::New(env, "git_libgit2_opts failed").ThrowAsJavaScriptException();
        return env.Undefined();
      }
      break;
    }
    default: {
      Napi::Error::New(env, "Unsupported option").ThrowAsJavaScriptException();
      return env.Undefined();
    }
  }

  return to;
}

   
/*
   * @return String  result    */
Napi::Value GitLibgit2::Prerelease(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
    );

 const char * result =     git_libgit2_prerelease(
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
   * @return Number  result    */
Napi::Value GitLibgit2::Shutdown(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
    );

 int result =     git_libgit2_shutdown(
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
 * @param Number major
   * @param Number minor
   * @param Number rev
     * @return Number  result    */
Napi::Value GitLibgit2::Version(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number major is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number minor is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number rev is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  int * from_major = NULL;
      *from_major = (int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
// start convert_from_v8 block
  int * from_minor = NULL;
      *from_minor = (int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
// start convert_from_v8 block
  int * from_rev = NULL;
      *from_rev = (int)   info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_major
            ,
              from_minor
            ,
              from_rev
    );

 int result =     git_libgit2_version(
          from_major
,          from_minor
,          from_rev
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
     