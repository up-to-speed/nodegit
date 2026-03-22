// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff_delta.h"
#include "bungit_wrapper.cc"

  #include "../include/diff_file.h"
 
#include <iostream>

using namespace std;

  GitDiffDelta::~GitDiffDelta() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffDelta::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "DiffDelta", {
         InstanceMethod("status", &GitDiffDelta::Status, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("flags", &GitDiffDelta::Flags, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("similarity", &GitDiffDelta::Similarity, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("nfiles", &GitDiffDelta::Nfiles, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("oldFile", &GitDiffDelta::OldFile, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("newFile", &GitDiffDelta::NewFile, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitDiffDelta::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitDiffDelta::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitDiffDelta::Template", constructor_template);
    target.Set(Napi::String::New(env, "DiffDelta"), constructor_template);
  }

      // start field block
    Napi::Value GitDiffDelta::Status(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_delta_t
           status =
          Napi::ObjectWrap<GitDiffDelta>::Unwrap(info.This().As<Napi::Object>())->GetValue()->status;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  status);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffDelta::Flags(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            uint32_t
           flags =
          Napi::ObjectWrap<GitDiffDelta>::Unwrap(info.This().As<Napi::Object>())->GetValue()->flags;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  flags);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffDelta::Similarity(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            uint16_t
           similarity =
          Napi::ObjectWrap<GitDiffDelta>::Unwrap(info.This().As<Napi::Object>())->GetValue()->similarity;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  similarity);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffDelta::Nfiles(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            uint16_t
           nfiles =
          Napi::ObjectWrap<GitDiffDelta>::Unwrap(info.This().As<Napi::Object>())->GetValue()->nfiles;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  nfiles);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffDelta::OldFile(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_diff_file
*            old_file =
          &
           Napi::ObjectWrap<GitDiffDelta>::Unwrap(info.This().As<Napi::Object>())->GetValue()->old_file;
 // start convert_to_v8 block
    if (old_file != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitDiffFile::New(
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
    Napi::Value GitDiffDelta::NewFile(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_diff_file
*            new_file =
          &
           Napi::ObjectWrap<GitDiffDelta>::Unwrap(info.This().As<Napi::Object>())->GetValue()->new_file;
 // start convert_to_v8 block
    if (new_file != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitDiffFile::New(
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
template class NodeGitWrapper<GitDiffDeltaTraits>;
 