// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/commitarray.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitCommitarray::~GitCommitarray() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
      }

  void GitCommitarray::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Commitarray", {
          InstanceMethod("dispose", &GitCommitarray::Dispose, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitCommitarray::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitCommitarray::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitCommitarray::Template", constructor_template);
    target.Set(Napi::String::New(env, "Commitarray"), constructor_template);
  }

  
/*
     */
Napi::Value GitCommitarray::Dispose(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommitarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

    git_commitarray_dispose(
          Napi::ObjectWrap<GitCommitarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

      return scope.Escape(env.Undefined());
  }
}
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitCommitarrayTraits>;
 