// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/odb_backend_loose_options.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitOdbBackendLooseOptions::~GitOdbBackendLooseOptions() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitOdbBackendLooseOptions::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "OdbBackendLooseOptions", {
         InstanceMethod("version", &GitOdbBackendLooseOptions::Version, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("flags", &GitOdbBackendLooseOptions::Flags, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("compressionLevel", &GitOdbBackendLooseOptions::CompressionLevel, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("dirMode", &GitOdbBackendLooseOptions::DirMode, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("fileMode", &GitOdbBackendLooseOptions::FileMode, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("oidType", &GitOdbBackendLooseOptions::OidType, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitOdbBackendLooseOptions::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitOdbBackendLooseOptions::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitOdbBackendLooseOptions::Template", constructor_template);
    target.Set(Napi::String::New(env, "OdbBackendLooseOptions"), constructor_template);
  }

      // start field block
    Napi::Value GitOdbBackendLooseOptions::Version(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           version =
          Napi::ObjectWrap<GitOdbBackendLooseOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->version;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  version);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitOdbBackendLooseOptions::Flags(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            uint32_t
           flags =
          Napi::ObjectWrap<GitOdbBackendLooseOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->flags;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  flags);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitOdbBackendLooseOptions::CompressionLevel(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           compression_level =
          Napi::ObjectWrap<GitOdbBackendLooseOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->compression_level;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  compression_level);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitOdbBackendLooseOptions::DirMode(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           dir_mode =
          Napi::ObjectWrap<GitOdbBackendLooseOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->dir_mode;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  dir_mode);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitOdbBackendLooseOptions::FileMode(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           file_mode =
          Napi::ObjectWrap<GitOdbBackendLooseOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->file_mode;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  file_mode);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitOdbBackendLooseOptions::OidType(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid_t
           oid_type =
          Napi::ObjectWrap<GitOdbBackendLooseOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->oid_type;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  oid_type);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitOdbBackendLooseOptionsTraits>;
 