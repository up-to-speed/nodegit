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
#include "../include/submodule_update_options.h"
#include "bungit_wrapper.cc"

  #include "../include/checkout_options.h"
  #include "../include/fetch_options.h"
 
using namespace std;

 
ConfigurableGitSubmoduleUpdateOptions::ConfigurableGitSubmoduleUpdateOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitSubmoduleUpdateOptionsTraits>(nodegitContext)
{
     git_submodule_update_options  wrappedValue = GIT_SUBMODULE_UPDATE_OPTIONS_INIT;
    this->raw = (git_submodule_update_options*) malloc(sizeof(git_submodule_update_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_submodule_update_options ));
 }

ConfigurableGitSubmoduleUpdateOptions::~ConfigurableGitSubmoduleUpdateOptions() {
         }

nodegit::ConfigurableClassWrapper<GitSubmoduleUpdateOptionsTraits>::v8ConversionResult ConfigurableGitSubmoduleUpdateOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitSubmoduleUpdateOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitSubmoduleUpdateOptions> output(new ConfigurableGitSubmoduleUpdateOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "allowFetch");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to allowFetch"
              };
            }

            output->raw->allow_fetch = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

         
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitSubmoduleUpdateOptionsTraits>;
