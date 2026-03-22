// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/error.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitError::~GitError() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
     }

  void GitError::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Error", {
          InstanceMethod("last", &GitError::Last, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
           InstanceMethod("message", &GitError::Message, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("klass", &GitError::Klass, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitError::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitError::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitError::Template", constructor_template);
    target.Set(Napi::String::New(env, "Error"), constructor_template);
  }

  
/*
   * @return Error  result    */
Napi::Value GitError::Last(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
    );

 const git_error * result =     git_error_last(
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitError::New(
        env,
        result,
        false
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
       // start field block
    Napi::Value GitError::Message(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char *
           message =
          Napi::ObjectWrap<GitError>::Unwrap(info.This().As<Napi::Object>())->GetValue()->message;
 // start convert_to_v8 block
  if (message){
       v8ConversionSlot = Napi::String::New(env, message);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitError::Klass(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           klass =
          Napi::ObjectWrap<GitError>::Unwrap(info.This().As<Napi::Object>())->GetValue()->klass;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  klass);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitErrorTraits>;
 