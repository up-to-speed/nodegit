// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/oidarray.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
 
#include <iostream>

using namespace std;

  GitOidarray::~GitOidarray() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
      }

  void GitOidarray::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Oidarray", {
          InstanceMethod("dispose", &GitOidarray::Dispose, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
           InstanceMethod("ids", &GitOidarray::Ids, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("count", &GitOidarray::Count, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitOidarray::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitOidarray::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitOidarray::Template", constructor_template);
    target.Set(Napi::String::New(env, "Oidarray"), constructor_template);
  }

  
/*
     */
Napi::Value GitOidarray::Dispose(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitOidarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

    git_oidarray_dispose(
          Napi::ObjectWrap<GitOidarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

      return scope.Escape(env.Undefined());
  }
}
       // start field block
    Napi::Value GitOidarray::Ids(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid *
            ids =
           Napi::ObjectWrap<GitOidarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()->ids;
 // start convert_to_v8 block
    if (ids != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        ids,
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
    Napi::Value GitOidarray::Count(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           count =
          Napi::ObjectWrap<GitOidarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()->count;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  count);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitOidarrayTraits>;
 