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
#include "../include/clone_options.h"
#include "bungit_wrapper.cc"

  #include "../include/checkout_options.h"
  #include "../include/fetch_options.h"
 
using namespace std;

 
ConfigurableGitCloneOptions::ConfigurableGitCloneOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitCloneOptionsTraits>(nodegitContext)
{
     git_clone_options  wrappedValue = GIT_CLONE_OPTIONS_INIT;
    this->raw = (git_clone_options*) malloc(sizeof(git_clone_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_clone_options ));
 }

ConfigurableGitCloneOptions::~ConfigurableGitCloneOptions() {
                  free((void*)this->raw->checkout_branch);
       }

nodegit::ConfigurableClassWrapper<GitCloneOptionsTraits>::v8ConversionResult ConfigurableGitCloneOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitCloneOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitCloneOptions> output(new ConfigurableGitCloneOptions(nodegitContext));

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
          {
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "fetchOpts");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitFetchOptions::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set fetchOpts: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->fetch_opts = *child->GetValue();
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "bare");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to bare"
              };
            }

            output->raw->bare = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "local");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to local"
              };
            }

            output->raw->local = static_cast<git_clone_local_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          output->raw->checkout_branch = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "checkoutBranch");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to checkoutBranch"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->checkout_branch = strdup(utf8String.c_str());
          }
        }
          output->raw->repository_cb_payload = (void *)output.get();
          output->raw->remote_cb_payload = (void *)output.get();
    
  return {
    output
  };
}

                 
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitCloneOptionsTraits>;
