// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/configmap.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitConfigmap::~GitConfigmap() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitConfigmap::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Configmap", {
         InstanceMethod("type", &GitConfigmap::Type, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("strMatch", &GitConfigmap::StrMatch, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("mapValue", &GitConfigmap::MapValue, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitConfigmap::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitConfigmap::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitConfigmap::Template", constructor_template);
    target.Set(Napi::String::New(env, "Configmap"), constructor_template);
  }

      // start field block
    Napi::Value GitConfigmap::Type(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_configmap_t
           type =
          Napi::ObjectWrap<GitConfigmap>::Unwrap(info.This().As<Napi::Object>())->GetValue()->type;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  type);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitConfigmap::StrMatch(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           str_match =
          Napi::ObjectWrap<GitConfigmap>::Unwrap(info.This().As<Napi::Object>())->GetValue()->str_match;
 // start convert_to_v8 block
  if (str_match){
       v8ConversionSlot = Napi::String::New(env, str_match);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitConfigmap::MapValue(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           map_value =
          Napi::ObjectWrap<GitConfigmap>::Unwrap(info.This().As<Napi::Object>())->GetValue()->map_value;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  map_value);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitConfigmapTraits>;
 