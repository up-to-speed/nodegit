// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/commit_create_options.h"
#include "bungit_wrapper.cc"

  #include "../include/signature.h"
 
#include <iostream>

using namespace std;

  GitCommitCreateOptions::~GitCommitCreateOptions() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCommitCreateOptions::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "CommitCreateOptions", {
         InstanceMethod("version", &GitCommitCreateOptions::Version, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("allowEmptyCommit", &GitCommitCreateOptions::AllowEmptyCommit, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("author", &GitCommitCreateOptions::Author, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("committer", &GitCommitCreateOptions::Committer, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("messageEncoding", &GitCommitCreateOptions::MessageEncoding, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitCommitCreateOptions::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitCommitCreateOptions::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitCommitCreateOptions::Template", constructor_template);
    target.Set(Napi::String::New(env, "CommitCreateOptions"), constructor_template);
  }

      // start field block
    Napi::Value GitCommitCreateOptions::Version(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           version =
          Napi::ObjectWrap<GitCommitCreateOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->version;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  version);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCommitCreateOptions::AllowEmptyCommit(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           allow_empty_commit =
          Napi::ObjectWrap<GitCommitCreateOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->allow_empty_commit;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  allow_empty_commit);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitCommitCreateOptions::Author(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const git_signature *
            author =
           Napi::ObjectWrap<GitCommitCreateOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->author;
 // start convert_to_v8 block
    if (author != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitSignature::New(
        env,
        author,
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
    Napi::Value GitCommitCreateOptions::Committer(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const git_signature *
            committer =
           Napi::ObjectWrap<GitCommitCreateOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->committer;
 // start convert_to_v8 block
    if (committer != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitSignature::New(
        env,
        committer,
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
    Napi::Value GitCommitCreateOptions::MessageEncoding(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            const char *
           message_encoding =
          Napi::ObjectWrap<GitCommitCreateOptions>::Unwrap(info.This().As<Napi::Object>())->GetValue()->message_encoding;
 // start convert_to_v8 block
  if (message_encoding){
       v8ConversionSlot = Napi::String::New(env, message_encoding);
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
template class NodeGitWrapper<GitCommitCreateOptionsTraits>;
 