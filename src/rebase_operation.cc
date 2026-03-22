// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/rebase_operation.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
 
#include <iostream>

using namespace std;

  GitRebaseOperation::~GitRebaseOperation() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitRebaseOperation::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "RebaseOperation", {
         InstanceMethod("type", &GitRebaseOperation::Type, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("id", &GitRebaseOperation::Id, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("exec", &GitRebaseOperation::Exec, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitRebaseOperation::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitRebaseOperation::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitRebaseOperation::Template", constructor_template);
    target.Set(Napi::String::New(env, "RebaseOperation"), constructor_template);
  }

      // start field block
    Napi::Value GitRebaseOperation::Type(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_rebase_operation_t
           type =
          Napi::ObjectWrap<GitRebaseOperation>::Unwrap(info.This().As<Napi::Object>())->GetValue()->type;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  type);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitRebaseOperation::Id(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const git_oid
*            id =
          &
           Napi::ObjectWrap<GitRebaseOperation>::Unwrap(info.This().As<Napi::Object>())->GetValue()->id;
 // start convert_to_v8 block
    if (id != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        id,
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
    Napi::Value GitRebaseOperation::Exec(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           exec =
          Napi::ObjectWrap<GitRebaseOperation>::Unwrap(info.This().As<Napi::Object>())->GetValue()->exec;
 // start convert_to_v8 block
  if (exec){
       v8ConversionSlot = Napi::String::New(env, exec);
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
template class NodeGitWrapper<GitRebaseOperationTraits>;
 