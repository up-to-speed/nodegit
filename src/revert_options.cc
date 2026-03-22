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
#include "../include/revert_options.h"
#include "bungit_wrapper.cc"

  #include "../include/merge_options.h"
  #include "../include/checkout_options.h"
 
using namespace std;

 
ConfigurableGitRevertOptions::ConfigurableGitRevertOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitRevertOptionsTraits>(nodegitContext)
{
     git_revert_options  wrappedValue = GIT_REVERT_OPTIONS_INIT;
    this->raw = (git_revert_options*) malloc(sizeof(git_revert_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_revert_options ));
 }

ConfigurableGitRevertOptions::~ConfigurableGitRevertOptions() {
         }

nodegit::ConfigurableClassWrapper<GitRevertOptionsTraits>::v8ConversionResult ConfigurableGitRevertOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitRevertOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitRevertOptions> output(new ConfigurableGitRevertOptions(nodegitContext));

  // unpack the data into the correct fields
         {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "version");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to version"
              };
            }

            output->raw->version = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "mainline");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to mainline"
              };
            }

            output->raw->mainline = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          {
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "mergeOpts");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitMergeOptions::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set mergeOpts: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->merge_opts = *child->GetValue();
          }
        }
          {
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "checkoutOpts");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitCheckoutOptions::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set checkoutOpts: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->checkout_opts = *child->GetValue();
          }
        }
    
  return {
    output
  };
}

         
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitRevertOptionsTraits>;
