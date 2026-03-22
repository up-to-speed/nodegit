// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/remote_head.h"
#include "bungit_wrapper.cc"

  #include "../include/functions/free.h"
  #include "../include/oid.h"
 
#include <iostream>

using namespace std;

  GitRemoteHead::~GitRemoteHead() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitRemoteHead::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "RemoteHead", {
         InstanceMethod("local", &GitRemoteHead::Local, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("oid", &GitRemoteHead::Oid, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("loid", &GitRemoteHead::Loid, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("name", &GitRemoteHead::Name, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("symrefTarget", &GitRemoteHead::SymrefTarget, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitRemoteHead::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitRemoteHead::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitRemoteHead::Template", constructor_template);
    target.Set(Napi::String::New(env, "RemoteHead"), constructor_template);
  }

      // start field block
    Napi::Value GitRemoteHead::Local(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           local =
          Napi::ObjectWrap<GitRemoteHead>::Unwrap(info.This().As<Napi::Object>())->GetValue()->local;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  local);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitRemoteHead::Oid(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid
*            oid =
          &
           Napi::ObjectWrap<GitRemoteHead>::Unwrap(info.This().As<Napi::Object>())->GetValue()->oid;
 // start convert_to_v8 block
    if (oid != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        oid,
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
    Napi::Value GitRemoteHead::Loid(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid
*            loid =
          &
           Napi::ObjectWrap<GitRemoteHead>::Unwrap(info.This().As<Napi::Object>())->GetValue()->loid;
 // start convert_to_v8 block
    if (loid != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        loid,
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
    Napi::Value GitRemoteHead::Name(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char *
           name =
          Napi::ObjectWrap<GitRemoteHead>::Unwrap(info.This().As<Napi::Object>())->GetValue()->name;
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
    Napi::Value GitRemoteHead::SymrefTarget(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char *
           symref_target =
          Napi::ObjectWrap<GitRemoteHead>::Unwrap(info.This().As<Napi::Object>())->GetValue()->symref_target;
 // start convert_to_v8 block
  if (symref_target){
       v8ConversionSlot = Napi::String::New(env, symref_target);
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
template class NodeGitWrapper<GitRemoteHeadTraits>;
 