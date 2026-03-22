// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/status_entry.h"
#include "bungit_wrapper.cc"

  #include "../include/diff_delta.h"
 
#include <iostream>

using namespace std;

  GitStatusEntry::~GitStatusEntry() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitStatusEntry::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "StatusEntry", {
         InstanceMethod("status", &GitStatusEntry::Status, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("headToIndex", &GitStatusEntry::HeadToIndex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("indexToWorkdir", &GitStatusEntry::IndexToWorkdir, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitStatusEntry::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitStatusEntry::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitStatusEntry::Template", constructor_template);
    target.Set(Napi::String::New(env, "StatusEntry"), constructor_template);
  }

      // start field block
    Napi::Value GitStatusEntry::Status(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_status_t
           status =
          Napi::ObjectWrap<GitStatusEntry>::Unwrap(info.This().As<Napi::Object>())->GetValue()->status;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  status);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitStatusEntry::HeadToIndex(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_diff_delta *
            head_to_index =
           Napi::ObjectWrap<GitStatusEntry>::Unwrap(info.This().As<Napi::Object>())->GetValue()->head_to_index;
 // start convert_to_v8 block
    if (head_to_index != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitDiffDelta::New(
        env,
        head_to_index,
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
    Napi::Value GitStatusEntry::IndexToWorkdir(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_diff_delta *
            index_to_workdir =
           Napi::ObjectWrap<GitStatusEntry>::Unwrap(info.This().As<Napi::Object>())->GetValue()->index_to_workdir;
 // start convert_to_v8 block
    if (index_to_workdir != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitDiffDelta::New(
        env,
        index_to_workdir,
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
template class NodeGitWrapper<GitStatusEntryTraits>;
 