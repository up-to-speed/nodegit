// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/oid.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitOid::~GitOid() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                      }

  void GitOid::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Oid", {
          InstanceMethod("cmp", &GitOid::Cmp, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("cpy", &GitOid::Cpy, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("equal", &GitOid::Equal, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("fromString", &GitOid::Fromstrp, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("isZero", &GitOid::IsZero, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("ncmp", &GitOid::Ncmp, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("strcmp", &GitOid::Strcmp, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("streq", &GitOid::Streq, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("tostrS", &GitOid::TostrS, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitOid::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitOid::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitOid::Template", constructor_template);
    target.Set(Napi::String::New(env, "Oid"), constructor_template);
  }

  
/*
   * @param Oid b
     * @return Number  result    */
Napi::Value GitOid::Cmp(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid b is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
// start convert_from_v8 block
  const git_oid * from_b = NULL;
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

    from_b = oidOut;
  }
  else {
from_b = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_b
    );

 int result =     git_oid_cmp(
          Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_b
    );

      if (info[0].IsString()) {
        free((void *)from_b);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
      * @return Oid out    */
Napi::Value GitOid::Cpy(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

      git_oid *out = (git_oid *)malloc(sizeof(git_oid));

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_oid_cpy(
          out
,          Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

      if (result != GIT_OK) {
          free(out);

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
        v8ConversionSlot = GitOid::New(
        env,
        out,
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
   * @param Oid b
     * @return Number  result    */
Napi::Value GitOid::Equal(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid b is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
// start convert_from_v8 block
  const git_oid * from_b = NULL;
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

    from_b = oidOut;
  }
  else {
from_b = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_b
    );

 int result =     git_oid_equal(
          Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_b
    );

      if (info[0].IsString()) {
        free((void *)from_b);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
  * @param String str
     * @return Oid out    */
Napi::Value GitOid::Fromstrp(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String str is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

      git_oid *out = (git_oid *)malloc(sizeof(git_oid));
// start convert_from_v8 block
  const char * from_str = NULL;

  std::string str = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_str = (const char *) malloc(str.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_str, str.c_str(), str.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_str) + str.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_str
    );

 int result =     git_oid_fromstrp(
          out
,          from_str
    );

      if (result != GIT_OK) {
          free(out);

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
        v8ConversionSlot = GitOid::New(
        env,
        out,
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
Napi::Value GitOid::IsZero(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_oid_is_zero(
          Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Oid b
   * @param Number len
     * @return Number  result    */
Napi::Value GitOid::Ncmp(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid b is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const git_oid * from_b = NULL;
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

    from_b = oidOut;
  }
  else {
from_b = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_len;
      from_len = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_b
    );

 int result =     git_oid_ncmp(
          Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_b
,          from_len
    );

      if (info[0].IsString()) {
        free((void *)from_b);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String str
     * @return Number  result    */
Napi::Value GitOid::Strcmp(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String str is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_str = NULL;

  std::string str = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_str = (const char *) malloc(str.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_str, str.c_str(), str.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_str) + str.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_str
    );

 int result =     git_oid_strcmp(
          Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_str
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String str
     * @return Number  result    */
Napi::Value GitOid::Streq(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String str is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_str = NULL;

  std::string str = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_str = (const char *) malloc(str.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_str, str.c_str(), str.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_str) + str.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_str
    );

 int result =     git_oid_streq(
          Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_str
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
Napi::Value GitOid::TostrS(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 char * result =     git_oid_tostr_s(
          Napi::ObjectWrap<GitOid>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
template class NodeGitWrapper<GitOidTraits>;
 