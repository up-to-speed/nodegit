// This is a generated file, modify: generate/templates/templates/struct_content.cc

// generated from struct_content.cc
#include <napi.h>
#include <string.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

extern "C" {
  #include <git2.h>
 }

#include <iostream>
#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/blob_filter_options.h"
#include "bungit_wrapper.cc"

 
using namespace std;

 
ConfigurableGitBlobFilterOptions::ConfigurableGitBlobFilterOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitBlobFilterOptionsTraits>(nodegitContext)
{
     git_blob_filter_options  wrappedValue = GIT_BLOB_FILTER_OPTIONS_INIT;
    this->raw = (git_blob_filter_options*) malloc(sizeof(git_blob_filter_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_blob_filter_options ));
 }

ConfigurableGitBlobFilterOptions::~ConfigurableGitBlobFilterOptions() {
     }

nodegit::ConfigurableClassWrapper<GitBlobFilterOptionsTraits>::v8ConversionResult ConfigurableGitBlobFilterOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitBlobFilterOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitBlobFilterOptions> output(new ConfigurableGitBlobFilterOptions(nodegitContext));

  // unpack the data into the correct fields
         {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "version");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to version"
              };
            }

            output->raw->version = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "flags");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to flags"
              };
            }

            output->raw->flags = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

     
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitBlobFilterOptionsTraits>;
