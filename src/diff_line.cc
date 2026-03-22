// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff_line.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitDiffLine::~GitDiffLine() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffLine::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "DiffLine", {
         InstanceMethod("origin", &GitDiffLine::Origin, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("oldLineno", &GitDiffLine::OldLineno, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("newLineno", &GitDiffLine::NewLineno, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("numLines", &GitDiffLine::NumLines, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("contentLen", &GitDiffLine::ContentLen, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("contentOffset", &GitDiffLine::ContentOffset, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("content", &GitDiffLine::Content, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitDiffLine::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitDiffLine::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitDiffLine::Template", constructor_template);
    target.Set(Napi::String::New(env, "DiffLine"), constructor_template);
  }

      // start field block
    Napi::Value GitDiffLine::Origin(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           origin =
          Napi::ObjectWrap<GitDiffLine>::Unwrap(info.This().As<Napi::Object>())->GetValue()->origin;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  origin);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffLine::OldLineno(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           old_lineno =
          Napi::ObjectWrap<GitDiffLine>::Unwrap(info.This().As<Napi::Object>())->GetValue()->old_lineno;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  old_lineno);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffLine::NewLineno(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           new_lineno =
          Napi::ObjectWrap<GitDiffLine>::Unwrap(info.This().As<Napi::Object>())->GetValue()->new_lineno;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  new_lineno);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffLine::NumLines(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           num_lines =
          Napi::ObjectWrap<GitDiffLine>::Unwrap(info.This().As<Napi::Object>())->GetValue()->num_lines;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  num_lines);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffLine::ContentLen(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           content_len =
          Napi::ObjectWrap<GitDiffLine>::Unwrap(info.This().As<Napi::Object>())->GetValue()->content_len;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  content_len);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffLine::ContentOffset(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_off_t
           content_offset =
          Napi::ObjectWrap<GitDiffLine>::Unwrap(info.This().As<Napi::Object>())->GetValue()->content_offset;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  content_offset);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffLine::Content(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           content =
          Napi::ObjectWrap<GitDiffLine>::Unwrap(info.This().As<Napi::Object>())->GetValue()->content;
 // start convert_to_v8 block
  if (content){
       v8ConversionSlot = Napi::String::New(env, content);
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
template class NodeGitWrapper<GitDiffLineTraits>;
 