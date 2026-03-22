// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/push_update.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
 
#include <iostream>

using namespace std;

  GitPushUpdate::~GitPushUpdate() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitPushUpdate::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "PushUpdate", {
         InstanceMethod("srcRefname", &GitPushUpdate::SrcRefname, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("dstRefname", &GitPushUpdate::DstRefname, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("src", &GitPushUpdate::Src, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("dst", &GitPushUpdate::Dst, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitPushUpdate::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitPushUpdate::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitPushUpdate::Template", constructor_template);
    target.Set(Napi::String::New(env, "PushUpdate"), constructor_template);
  }

      // start field block
    Napi::Value GitPushUpdate::SrcRefname(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char *
           src_refname =
          Napi::ObjectWrap<GitPushUpdate>::Unwrap(info.This().As<Napi::Object>())->GetValue()->src_refname;
 // start convert_to_v8 block
  if (src_refname){
       v8ConversionSlot = Napi::String::New(env, src_refname);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitPushUpdate::DstRefname(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char *
           dst_refname =
          Napi::ObjectWrap<GitPushUpdate>::Unwrap(info.This().As<Napi::Object>())->GetValue()->dst_refname;
 // start convert_to_v8 block
  if (dst_refname){
       v8ConversionSlot = Napi::String::New(env, dst_refname);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitPushUpdate::Src(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid
*            src =
          &
           Napi::ObjectWrap<GitPushUpdate>::Unwrap(info.This().As<Napi::Object>())->GetValue()->src;
 // start convert_to_v8 block
    if (src != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        src,
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
    Napi::Value GitPushUpdate::Dst(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid
*            dst =
          &
           Napi::ObjectWrap<GitPushUpdate>::Unwrap(info.This().As<Napi::Object>())->GetValue()->dst;
 // start convert_to_v8 block
    if (dst != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        dst,
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
template class NodeGitWrapper<GitPushUpdateTraits>;
 