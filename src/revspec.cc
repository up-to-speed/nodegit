// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/revspec.h"
#include "bungit_wrapper.cc"

  #include "../include/object.h"
 
#include <iostream>

using namespace std;

  GitRevspec::~GitRevspec() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitRevspec::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Revspec", {
         InstanceMethod("from", &GitRevspec::From, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("to", &GitRevspec::To, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("flags", &GitRevspec::Flags, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitRevspec::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitRevspec::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitRevspec::Template", constructor_template);
    target.Set(Napi::String::New(env, "Revspec"), constructor_template);
  }

      // start field block
    Napi::Value GitRevspec::From(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_object *
            from =
           Napi::ObjectWrap<GitRevspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()->from;
 // start convert_to_v8 block
    if (from != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
         owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_object_owner(from),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitObject::New(
        env,
        from,
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
    Napi::Value GitRevspec::To(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            git_object *
            to =
           Napi::ObjectWrap<GitRevspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()->to;
 // start convert_to_v8 block
    if (to != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
         owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_object_owner(to),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitObject::New(
        env,
        to,
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
    Napi::Value GitRevspec::Flags(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            unsigned int
           flags =
          Napi::ObjectWrap<GitRevspec>::Unwrap(info.This().As<Napi::Object>())->GetValue()->flags;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  flags);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitRevspecTraits>;
 