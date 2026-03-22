// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/buf.h"
#include "bungit_wrapper.cc"

  #include "../include/git_buf_converter.h"
 
#include <iostream>

using namespace std;

  GitBuf::~GitBuf() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                     }

  void GitBuf::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Buf", {
          InstanceMethod("containsNul", &GitBuf::ContainsNul, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("dispose", &GitBuf::Dispose, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("grow", &GitBuf::Grow, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("isBinary", &GitBuf::IsBinary, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("set", &GitBuf::Set, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
           InstanceMethod("ptr", &GitBuf::Ptr, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("reserved", &GitBuf::Reserved, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("size", &GitBuf::Size, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitBuf::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitBuf::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitBuf::Template", constructor_template);
    target.Set(Napi::String::New(env, "Buf"), constructor_template);
  }

  
/*
     * @return Number  result    */
Napi::Value GitBuf::ContainsNul(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_buf_contains_nul(
          Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     */
Napi::Value GitBuf::Dispose(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

    git_buf_dispose(
          Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

      return scope.Escape(env.Undefined());
  }
}
   
/*
   * @param Number target_size
     */
Napi::Value GitBuf::Grow(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number target_size is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_target_size;
      from_target_size = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_buf_grow(
          Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_target_size
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
      return scope.Escape(env.Undefined());
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitBuf::IsBinary(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_buf_is_binary(
          Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Buffer data
   * @param Number datalen
     */
Napi::Value GitBuf::Set(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Buffer data is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number datalen is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const void * from_data = NULL;

  from_data = info[0].As<Napi::Buffer<char>>().Data();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_datalen;
      from_datalen = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_data
    );

 int result =     git_buf_set(
          Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_data
,          from_datalen
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
      return scope.Escape(env.Undefined());
  }
}
       // start field block
    Napi::Value GitBuf::Ptr(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char *
           ptr =
          Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()->ptr;
 // start convert_to_v8 block
  if (ptr){
       v8ConversionSlot = Napi::String::New(env, ptr);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitBuf::Reserved(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           reserved =
          Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()->reserved;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  reserved);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitBuf::Size(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           size =
          Napi::ObjectWrap<GitBuf>::Unwrap(info.This().As<Napi::Object>())->GetValue()->size;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  size);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitBufTraits>;
 