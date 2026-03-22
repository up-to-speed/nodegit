// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/cert_hostkey.h"
#include "bungit_wrapper.cc"

  #include "../include/cert.h"
 
#include <iostream>

using namespace std;

  GitCertHostkey::~GitCertHostkey() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCertHostkey::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "CertHostkey", {
         InstanceMethod("parent", &GitCertHostkey::Parent, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("type", &GitCertHostkey::Type, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("hashMd5", &GitCertHostkey::HashMd5, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("hashSha1", &GitCertHostkey::HashSha1, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("hashSha256", &GitCertHostkey::HashSha256, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("rawType", &GitCertHostkey::RawType, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("hostkey", &GitCertHostkey::Hostkey, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("hostkeyLen", &GitCertHostkey::HostkeyLen, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitCertHostkey::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitCertHostkey::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitCertHostkey::Template", constructor_template);
    target.Set(Napi::String::New(env, "CertHostkey"), constructor_template);
  }

      // start field block
    Napi::Value GitCertHostkey::Parent(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_cert
*            parent =
          &
           Napi::ObjectWrap<GitCertHostkey>::Unwrap(info.This().As<Napi::Object>())->GetValue()->parent;
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
    Napi::Value GitCertHostkey::Type(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_cert_ssh_t
           type =
          Napi::ObjectWrap<GitCertHostkey>::Unwrap(info.This().As<Napi::Object>())->GetValue()->type;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  type);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCertHostkey::HashMd5(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

      char* hash_md5 = (char *)Napi::ObjectWrap<GitCertHostkey>::Unwrap(info.This().As<Napi::Object>())->GetValue()->hash_md5;
 // start convert_to_v8 block
  if (hash_md5){
      v8ConversionSlot = Napi::String::New(env, hash_md5, 16);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCertHostkey::HashSha1(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

      char* hash_sha1 = (char *)Napi::ObjectWrap<GitCertHostkey>::Unwrap(info.This().As<Napi::Object>())->GetValue()->hash_sha1;
 // start convert_to_v8 block
  if (hash_sha1){
      v8ConversionSlot = Napi::String::New(env, hash_sha1, 20);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCertHostkey::HashSha256(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

      char* hash_sha256 = (char *)Napi::ObjectWrap<GitCertHostkey>::Unwrap(info.This().As<Napi::Object>())->GetValue()->hash_sha256;
 // start convert_to_v8 block
  if (hash_sha256){
      v8ConversionSlot = Napi::String::New(env, hash_sha256, 32);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCertHostkey::RawType(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_cert_ssh_raw_type_t
           raw_type =
          Napi::ObjectWrap<GitCertHostkey>::Unwrap(info.This().As<Napi::Object>())->GetValue()->raw_type;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  raw_type);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCertHostkey::Hostkey(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           hostkey =
          Napi::ObjectWrap<GitCertHostkey>::Unwrap(info.This().As<Napi::Object>())->GetValue()->hostkey;
 // start convert_to_v8 block
  if (hostkey){
       v8ConversionSlot = Napi::String::New(env, hostkey);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCertHostkey::HostkeyLen(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           hostkey_len =
          Napi::ObjectWrap<GitCertHostkey>::Unwrap(info.This().As<Napi::Object>())->GetValue()->hostkey_len;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  hostkey_len);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitCertHostkeyTraits>;
 