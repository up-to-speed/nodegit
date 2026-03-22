// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/config_entry.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitConfigEntry::~GitConfigEntry() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitConfigEntry::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "ConfigEntry", {
         InstanceMethod("name", &GitConfigEntry::Name, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("value", &GitConfigEntry::Value, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("level", &GitConfigEntry::Level, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitConfigEntry::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitConfigEntry::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitConfigEntry::Template", constructor_template);
    target.Set(Napi::String::New(env, "ConfigEntry"), constructor_template);
  }

      // start field block
    Napi::Value GitConfigEntry::Name(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           name =
          Napi::ObjectWrap<GitConfigEntry>::Unwrap(info.This().As<Napi::Object>())->GetValue()->name;
 // start convert_to_v8 block
  if (name){
       v8ConversionSlot = Napi::String::New(env, name);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitConfigEntry::Value(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           value =
          Napi::ObjectWrap<GitConfigEntry>::Unwrap(info.This().As<Napi::Object>())->GetValue()->value;
 // start convert_to_v8 block
  if (value){
       v8ConversionSlot = Napi::String::New(env, value);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitConfigEntry::Level(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_config_level_t
           level =
          Napi::ObjectWrap<GitConfigEntry>::Unwrap(info.This().As<Napi::Object>())->GetValue()->level;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  level);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitConfigEntryTraits>;
 