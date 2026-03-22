// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/time.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitTime::~GitTime() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitTime::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Time", {
         InstanceMethod("time", &GitTime::Time, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("offset", &GitTime::Offset, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("sign", &GitTime::Sign, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitTime::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitTime::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitTime::Template", constructor_template);
    target.Set(Napi::String::New(env, "Time"), constructor_template);
  }

      // start field block
    Napi::Value GitTime::Time(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_time_t
           time =
          Napi::ObjectWrap<GitTime>::Unwrap(info.This().As<Napi::Object>())->GetValue()->time;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  time);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitTime::Offset(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           offset =
          Napi::ObjectWrap<GitTime>::Unwrap(info.This().As<Napi::Object>())->GetValue()->offset;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  offset);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitTime::Sign(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char
           sign =
          Napi::ObjectWrap<GitTime>::Unwrap(info.This().As<Napi::Object>())->GetValue()->sign;
 // start convert_to_v8 block
  if (sign){
      char convertToNullTerminated[2] = { sign, '\0' };
      v8ConversionSlot = Napi::String::New(env, convertToNullTerminated);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitTimeTraits>;
 