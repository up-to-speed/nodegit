// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff_binary.h"
#include "bungit_wrapper.cc"

  #include "../include/diff_binary_file.h"
 
#include <iostream>

using namespace std;

  GitDiffBinary::~GitDiffBinary() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffBinary::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "DiffBinary", {
         InstanceMethod("containsData", &GitDiffBinary::ContainsData, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("oldFile", &GitDiffBinary::OldFile, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("newFile", &GitDiffBinary::NewFile, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitDiffBinary::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitDiffBinary::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitDiffBinary::Template", constructor_template);
    target.Set(Napi::String::New(env, "DiffBinary"), constructor_template);
  }

      // start field block
    Napi::Value GitDiffBinary::ContainsData(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           contains_data =
          Napi::ObjectWrap<GitDiffBinary>::Unwrap(info.This().As<Napi::Object>())->GetValue()->contains_data;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  contains_data);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffBinary::OldFile(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_diff_binary_file
*            old_file =
          &
           Napi::ObjectWrap<GitDiffBinary>::Unwrap(info.This().As<Napi::Object>())->GetValue()->old_file;
 // start convert_to_v8 block
    if (old_file != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitDiffBinaryFile::New(
        env,
        old_file,
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
    Napi::Value GitDiffBinary::NewFile(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_diff_binary_file
*            new_file =
          &
           Napi::ObjectWrap<GitDiffBinary>::Unwrap(info.This().As<Napi::Object>())->GetValue()->new_file;
 // start convert_to_v8 block
    if (new_file != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitDiffBinaryFile::New(
        env,
        new_file,
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
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitDiffBinaryTraits>;
 