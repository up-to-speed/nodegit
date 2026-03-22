// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/blame_line.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitBlameLine::~GitBlameLine() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitBlameLine::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "BlameLine", {
         InstanceMethod("ptr", &GitBlameLine::Ptr, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("len", &GitBlameLine::Len, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitBlameLine::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitBlameLine::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitBlameLine::Template", constructor_template);
    target.Set(Napi::String::New(env, "BlameLine"), constructor_template);
  }

      // start field block
    Napi::Value GitBlameLine::Ptr(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           ptr =
          Napi::ObjectWrap<GitBlameLine>::Unwrap(info.This().As<Napi::Object>())->GetValue()->ptr;
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
    Napi::Value GitBlameLine::Len(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           len =
          Napi::ObjectWrap<GitBlameLine>::Unwrap(info.This().As<Napi::Object>())->GetValue()->len;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  len);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitBlameLineTraits>;
 