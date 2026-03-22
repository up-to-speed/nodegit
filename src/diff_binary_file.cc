// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff_binary_file.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitDiffBinaryFile::~GitDiffBinaryFile() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffBinaryFile::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "DiffBinaryFile", {
         InstanceMethod("type", &GitDiffBinaryFile::Type, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("data", &GitDiffBinaryFile::Data, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("datalen", &GitDiffBinaryFile::Datalen, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("inflatedlen", &GitDiffBinaryFile::Inflatedlen, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitDiffBinaryFile::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitDiffBinaryFile::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitDiffBinaryFile::Template", constructor_template);
    target.Set(Napi::String::New(env, "DiffBinaryFile"), constructor_template);
  }

      // start field block
    Napi::Value GitDiffBinaryFile::Type(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_diff_binary_t
           type =
          Napi::ObjectWrap<GitDiffBinaryFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->type;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  type);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffBinaryFile::Data(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           data =
          Napi::ObjectWrap<GitDiffBinaryFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->data;
 // start convert_to_v8 block
  if (data){
       v8ConversionSlot = Napi::String::New(env, data);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffBinaryFile::Datalen(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           datalen =
          Napi::ObjectWrap<GitDiffBinaryFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->datalen;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  datalen);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffBinaryFile::Inflatedlen(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           inflatedlen =
          Napi::ObjectWrap<GitDiffBinaryFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->inflatedlen;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  inflatedlen);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitDiffBinaryFileTraits>;
 