// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/branch_iterator.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitBranchIterator::~GitBranchIterator() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitBranchIterator::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "BranchIterator", {
        StaticMethod("getSelfFreeingInstanceCount", &GitBranchIterator::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitBranchIterator::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitBranchIterator::Template", constructor_template);
    target.Set(Napi::String::New(env, "BranchIterator"), constructor_template);
  }

   // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitBranchIteratorTraits>;
 