// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff_hunk.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitDiffHunk::~GitDiffHunk() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffHunk::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "DiffHunk", {
         InstanceMethod("oldStart", &GitDiffHunk::OldStart, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("oldLines", &GitDiffHunk::OldLines, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("newStart", &GitDiffHunk::NewStart, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("newLines", &GitDiffHunk::NewLines, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("headerLen", &GitDiffHunk::HeaderLen, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("header", &GitDiffHunk::Header, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitDiffHunk::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitDiffHunk::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitDiffHunk::Template", constructor_template);
    target.Set(Napi::String::New(env, "DiffHunk"), constructor_template);
  }

      // start field block
    Napi::Value GitDiffHunk::OldStart(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           old_start =
          Napi::ObjectWrap<GitDiffHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->old_start;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  old_start);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffHunk::OldLines(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           old_lines =
          Napi::ObjectWrap<GitDiffHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->old_lines;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  old_lines);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffHunk::NewStart(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           new_start =
          Napi::ObjectWrap<GitDiffHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->new_start;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  new_start);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffHunk::NewLines(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           new_lines =
          Napi::ObjectWrap<GitDiffHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->new_lines;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  new_lines);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffHunk::HeaderLen(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           header_len =
          Napi::ObjectWrap<GitDiffHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->header_len;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  header_len);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffHunk::Header(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char *
           header =
          Napi::ObjectWrap<GitDiffHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->header;
 // start convert_to_v8 block
  if (header){
       v8ConversionSlot = Napi::String::New(env, header);
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
template class NodeGitWrapper<GitDiffHunkTraits>;
 