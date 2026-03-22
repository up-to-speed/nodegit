// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/attr_options.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
 
#include <iostream>

using namespace std;

  GitAttrOptions::~GitAttrOptions() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitAttrOptions::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "AttrOptions", {
         InstanceMethod("version", &GitAttrOptions::Version, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("flags", &GitAttrOptions::Flags, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("commitId", &GitAttrOptions::CommitId, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("attrCommitId", &GitAttrOptions::AttrCommitId, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitAttrOptions::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitAttrOptions::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitAttrOptions::Template", constructor_template);
    target.Set(Napi::String::New(env, "AttrOptions"), constructor_template);
  }

      // start field block
    Napi::Value GitAttrOptions::Version(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           version =
          Napi::ObjectWrap<GitAttrOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->version;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  version);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitAttrOptions::Flags(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           flags =
          Napi::ObjectWrap<GitAttrOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->flags;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  flags);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitAttrOptions::CommitId(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid *
            commit_id =
           Napi::ObjectWrap<GitAttrOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->commit_id;
 // start convert_to_v8 block
    if (commit_id != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        commit_id,
        true
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitAttrOptions::AttrCommitId(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid
*            attr_commit_id =
          &
           Napi::ObjectWrap<GitAttrOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->attr_commit_id;
 // start convert_to_v8 block
    if (attr_commit_id != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        attr_commit_id,
        true
          , owners
       );
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
template class NodeGitWrapper<GitAttrOptionsTraits>;
 