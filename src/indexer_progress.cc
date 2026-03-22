// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/indexer_progress.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitIndexerProgress::~GitIndexerProgress() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitIndexerProgress::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "IndexerProgress", {
         InstanceMethod("totalObjects", &GitIndexerProgress::TotalObjects, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("indexedObjects", &GitIndexerProgress::IndexedObjects, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("receivedObjects", &GitIndexerProgress::ReceivedObjects, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("localObjects", &GitIndexerProgress::LocalObjects, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("totalDeltas", &GitIndexerProgress::TotalDeltas, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("indexedDeltas", &GitIndexerProgress::IndexedDeltas, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("receivedBytes", &GitIndexerProgress::ReceivedBytes, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitIndexerProgress::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitIndexerProgress::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitIndexerProgress::Template", constructor_template);
    target.Set(Napi::String::New(env, "IndexerProgress"), constructor_template);
  }

      // start field block
    Napi::Value GitIndexerProgress::TotalObjects(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           total_objects =
          Napi::ObjectWrap<GitIndexerProgress>::Unwrap(info.This().As<Napi::Object>())->GetValue()->total_objects;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  total_objects);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitIndexerProgress::IndexedObjects(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           indexed_objects =
          Napi::ObjectWrap<GitIndexerProgress>::Unwrap(info.This().As<Napi::Object>())->GetValue()->indexed_objects;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  indexed_objects);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitIndexerProgress::ReceivedObjects(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           received_objects =
          Napi::ObjectWrap<GitIndexerProgress>::Unwrap(info.This().As<Napi::Object>())->GetValue()->received_objects;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  received_objects);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitIndexerProgress::LocalObjects(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           local_objects =
          Napi::ObjectWrap<GitIndexerProgress>::Unwrap(info.This().As<Napi::Object>())->GetValue()->local_objects;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  local_objects);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitIndexerProgress::TotalDeltas(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           total_deltas =
          Napi::ObjectWrap<GitIndexerProgress>::Unwrap(info.This().As<Napi::Object>())->GetValue()->total_deltas;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  total_deltas);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitIndexerProgress::IndexedDeltas(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           indexed_deltas =
          Napi::ObjectWrap<GitIndexerProgress>::Unwrap(info.This().As<Napi::Object>())->GetValue()->indexed_deltas;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  indexed_deltas);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitIndexerProgress::ReceivedBytes(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           received_bytes =
          Napi::ObjectWrap<GitIndexerProgress>::Unwrap(info.This().As<Napi::Object>())->GetValue()->received_bytes;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  received_bytes);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitIndexerProgressTraits>;
 