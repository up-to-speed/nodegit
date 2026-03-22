// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/pathspec_match_list.h"
#include "bungit_wrapper.cc"

  #include "../include/diff_delta.h"
 
#include <iostream>

using namespace std;

  GitPathspecMatchList::~GitPathspecMatchList() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                     }

  void GitPathspecMatchList::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "PathspecMatchList", {
          InstanceMethod("diffEntry", &GitPathspecMatchList::DiffEntry, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("entry", &GitPathspecMatchList::Entry, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("entrycount", &GitPathspecMatchList::Entrycount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("failedEntry", &GitPathspecMatchList::FailedEntry, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("failedEntrycount", &GitPathspecMatchList::FailedEntrycount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitPathspecMatchList::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitPathspecMatchList::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitPathspecMatchList::Template", constructor_template);
    target.Set(Napi::String::New(env, "PathspecMatchList"), constructor_template);
  }

  
/*
   * @param Number pos
     * @return DiffDelta  result    */
Napi::Value GitPathspecMatchList::DiffEntry(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number pos is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_pos;
      from_pos = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_diff_delta * result =     git_pathspec_match_list_diff_entry(
          Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_pos
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitDiffDelta::New(
        env,
        result,
        false
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Number pos
     * @return String  result    */
Napi::Value GitPathspecMatchList::Entry(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number pos is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_pos;
      from_pos = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_pathspec_match_list_entry(
          Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_pos
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
  if (result){
       v8ConversionSlot = Napi::String::New(env, result);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitPathspecMatchList::Entrycount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_pathspec_match_list_entrycount(
          Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Number pos
     * @return String  result    */
Napi::Value GitPathspecMatchList::FailedEntry(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number pos is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_pos;
      from_pos = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_pathspec_match_list_failed_entry(
          Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_pos
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
  if (result){
       v8ConversionSlot = Napi::String::New(env, result);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitPathspecMatchList::FailedEntrycount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_pathspec_match_list_failed_entrycount(
          Napi::ObjectWrap<GitPathspecMatchList>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitPathspecMatchListTraits>;
 