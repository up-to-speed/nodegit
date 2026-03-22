// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff_parse_options.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitDiffParseOptions::~GitDiffParseOptions() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffParseOptions::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "DiffParseOptions", {
         InstanceMethod("version", &GitDiffParseOptions::Version, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("oidType", &GitDiffParseOptions::OidType, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitDiffParseOptions::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitDiffParseOptions::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitDiffParseOptions::Template", constructor_template);
    target.Set(Napi::String::New(env, "DiffParseOptions"), constructor_template);
  }

      // start field block
    Napi::Value GitDiffParseOptions::Version(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           version =
          Napi::ObjectWrap<GitDiffParseOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->version;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  version);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffParseOptions::OidType(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid_t
           oid_type =
          Napi::ObjectWrap<GitDiffParseOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->oid_type;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  oid_type);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitDiffParseOptionsTraits>;
 