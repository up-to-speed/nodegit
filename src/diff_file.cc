// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff_file.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
 
#include <iostream>

using namespace std;

  GitDiffFile::~GitDiffFile() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffFile::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "DiffFile", {
         InstanceMethod("id", &GitDiffFile::Id, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("path", &GitDiffFile::Path, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("size", &GitDiffFile::Size, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("flags", &GitDiffFile::Flags, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("mode", &GitDiffFile::Mode, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("idAbbrev", &GitDiffFile::IdAbbrev, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitDiffFile::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitDiffFile::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitDiffFile::Template", constructor_template);
    target.Set(Napi::String::New(env, "DiffFile"), constructor_template);
  }

      // start field block
    Napi::Value GitDiffFile::Id(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid
*            id =
          &
           Napi::ObjectWrap<GitDiffFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->id;
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
    Napi::Value GitDiffFile::Path(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           path =
          Napi::ObjectWrap<GitDiffFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->path;
 // start convert_to_v8 block
  if (path){
       v8ConversionSlot = Napi::String::New(env, path);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffFile::Size(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_object_size_t
           size =
          Napi::ObjectWrap<GitDiffFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->size;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  size);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffFile::Flags(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            uint32_t
           flags =
          Napi::ObjectWrap<GitDiffFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->flags;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  flags);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffFile::Mode(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            uint16_t
           mode =
          Napi::ObjectWrap<GitDiffFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->mode;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  mode);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitDiffFile::IdAbbrev(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            uint16_t
           id_abbrev =
          Napi::ObjectWrap<GitDiffFile>::Unwrap(info.This().As<Napi::Object>())->GetValue()->id_abbrev;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  id_abbrev);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitDiffFileTraits>;
 