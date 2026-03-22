// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/checkout_perfdata.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitCheckoutPerfdata::~GitCheckoutPerfdata() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCheckoutPerfdata::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "CheckoutPerfdata", {
         InstanceMethod("mkdirCalls", &GitCheckoutPerfdata::MkdirCalls, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("statCalls", &GitCheckoutPerfdata::StatCalls, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("chmodCalls", &GitCheckoutPerfdata::ChmodCalls, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitCheckoutPerfdata::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitCheckoutPerfdata::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitCheckoutPerfdata::Template", constructor_template);
    target.Set(Napi::String::New(env, "CheckoutPerfdata"), constructor_template);
  }

      // start field block
    Napi::Value GitCheckoutPerfdata::MkdirCalls(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           mkdir_calls =
          Napi::ObjectWrap<GitCheckoutPerfdata>::Unwrap(info.This().As<Napi::Object>())->GetValue()->mkdir_calls;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  mkdir_calls);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCheckoutPerfdata::StatCalls(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           stat_calls =
          Napi::ObjectWrap<GitCheckoutPerfdata>::Unwrap(info.This().As<Napi::Object>())->GetValue()->stat_calls;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  stat_calls);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCheckoutPerfdata::ChmodCalls(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           chmod_calls =
          Napi::ObjectWrap<GitCheckoutPerfdata>::Unwrap(info.This().As<Napi::Object>())->GetValue()->chmod_calls;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  chmod_calls);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitCheckoutPerfdataTraits>;
 