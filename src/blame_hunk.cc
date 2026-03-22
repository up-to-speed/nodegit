// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/blame_hunk.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
  #include "../include/signature.h"
 
#include <iostream>

using namespace std;

  GitBlameHunk::~GitBlameHunk() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitBlameHunk::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "BlameHunk", {
         InstanceMethod("linesInHunk", &GitBlameHunk::LinesInHunk, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("finalCommitId", &GitBlameHunk::FinalCommitId, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("finalStartLineNumber", &GitBlameHunk::FinalStartLineNumber, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("finalSignature", &GitBlameHunk::FinalSignature, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("finalCommitter", &GitBlameHunk::FinalCommitter, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("origCommitId", &GitBlameHunk::OrigCommitId, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("origPath", &GitBlameHunk::OrigPath, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("origStartLineNumber", &GitBlameHunk::OrigStartLineNumber, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("origSignature", &GitBlameHunk::OrigSignature, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("origCommitter", &GitBlameHunk::OrigCommitter, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("summary", &GitBlameHunk::Summary, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitBlameHunk::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitBlameHunk::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitBlameHunk::Template", constructor_template);
    target.Set(Napi::String::New(env, "BlameHunk"), constructor_template);
  }

      // start field block
    Napi::Value GitBlameHunk::LinesInHunk(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            int
           lines_in_hunk =
          Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->lines_in_hunk;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  lines_in_hunk);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitBlameHunk::FinalCommitId(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid
*            final_commit_id =
          &
           Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->final_commit_id;
 // start convert_to_v8 block
    if (final_commit_id != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        final_commit_id,
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
    Napi::Value GitBlameHunk::FinalStartLineNumber(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           final_start_line_number =
          Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->final_start_line_number;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  final_start_line_number);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitBlameHunk::FinalSignature(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_signature *
            final_signature =
           Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->final_signature;
 // start convert_to_v8 block
    if (final_signature != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitSignature::New(
        env,
        final_signature,
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
    Napi::Value GitBlameHunk::FinalCommitter(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_signature *
            final_committer =
           Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->final_committer;
 // start convert_to_v8 block
    if (final_committer != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitSignature::New(
        env,
        final_committer,
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
    Napi::Value GitBlameHunk::OrigCommitId(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_oid
*            orig_commit_id =
          &
           Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->orig_commit_id;
 // start convert_to_v8 block
    if (orig_commit_id != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitOid::New(
        env,
        orig_commit_id,
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
    Napi::Value GitBlameHunk::OrigPath(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           orig_path =
          Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->orig_path;
 // start convert_to_v8 block
  if (orig_path){
       v8ConversionSlot = Napi::String::New(env, orig_path);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitBlameHunk::OrigStartLineNumber(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           orig_start_line_number =
          Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->orig_start_line_number;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  orig_start_line_number);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitBlameHunk::OrigSignature(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_signature *
            orig_signature =
           Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->orig_signature;
 // start convert_to_v8 block
    if (orig_signature != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitSignature::New(
        env,
        orig_signature,
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
    Napi::Value GitBlameHunk::OrigCommitter(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_signature *
            orig_committer =
           Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->orig_committer;
 // start convert_to_v8 block
    if (orig_committer != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitSignature::New(
        env,
        orig_committer,
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
    Napi::Value GitBlameHunk::Summary(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           summary =
          Napi::ObjectWrap<GitBlameHunk>::Unwrap(info.This().As<Napi::Object>())->GetValue()->summary;
 // start convert_to_v8 block
  if (summary){
       v8ConversionSlot = Napi::String::New(env, summary);
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
template class NodeGitWrapper<GitBlameHunkTraits>;
 