// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/midx_writer.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

  GitMidxWriter::~GitMidxWriter() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitMidxWriter::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "MidxWriter", {
        StaticMethod("getSelfFreeingInstanceCount", &GitMidxWriter::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitMidxWriter::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitMidxWriter::Template", constructor_template);
    target.Set(Napi::String::New(env, "MidxWriter"), constructor_template);
  }

   // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitMidxWriterTraits>;
 