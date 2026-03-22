// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/cert_x509.h"
#include "bungit_wrapper.cc"

  #include "../include/wrapper.h"
  #include "node_buffer.h"
  #include "../include/cert.h"
 
#include <iostream>

using namespace std;

  GitCertX509::~GitCertX509() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCertX509::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "CertX509", {
         InstanceMethod("parent", &GitCertX509::Parent, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("data", &GitCertX509::Data, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("len", &GitCertX509::Len, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitCertX509::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitCertX509::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitCertX509::Template", constructor_template);
    target.Set(Napi::String::New(env, "CertX509"), constructor_template);
  }

      // start field block
    Napi::Value GitCertX509::Parent(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_cert
*            parent =
          &
           Napi::ObjectWrap<GitCertX509>::Unwrap(info.This().As<Napi::Object>())->GetValue()->parent;
 // start convert_to_v8 block
    if (parent != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitCert::New(
        env,
        parent,
        false
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
    Napi::Value GitCertX509::Data(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            void *
            data =
           Napi::ObjectWrap<GitCertX509>::Unwrap(info.This().As<Napi::Object>())->GetValue()->data;
 // start convert_to_v8 block
    if (data != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
         v8ConversionSlot = Wrapper::New(env, data);
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCertX509::Len(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           len =
          Napi::ObjectWrap<GitCertX509>::Unwrap(info.This().As<Napi::Object>())->GetValue()->len;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  len);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitCertX509Traits>;
 