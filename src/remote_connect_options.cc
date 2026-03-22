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
#include "../include/remote_connect_options.h"
#include "bungit_wrapper.cc"

  #include "../include/str_array_converter.h"
  #include "../include/remote_callbacks.h"
  #include "../include/proxy_options.h"
  #include "../include/strarray.h"
 
using namespace std;

 
ConfigurableGitRemoteConnectOptions::ConfigurableGitRemoteConnectOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitRemoteConnectOptionsTraits>(nodegitContext)
{
     git_remote_connect_options  wrappedValue = GIT_REMOTE_CONNECT_OPTIONS_INIT;
    this->raw = (git_remote_connect_options*) malloc(sizeof(git_remote_connect_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_remote_connect_options ));
 }

ConfigurableGitRemoteConnectOptions::~ConfigurableGitRemoteConnectOptions() {
                if (this->raw->custom_headers.count) {
          for (size_t i = 0; i < this->raw->custom_headers.count; ++i) {
            free(this->raw->custom_headers.strings[i]);
          }
          free(this->raw->custom_headers.strings);
        }
   }

nodegit::ConfigurableClassWrapper<GitRemoteConnectOptionsTraits>::v8ConversionResult ConfigurableGitRemoteConnectOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitRemoteConnectOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitRemoteConnectOptions> output(new ConfigurableGitRemoteConnectOptions(nodegitContext));

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
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "callbacks");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitRemoteCallbacks::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set callbacks: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->callbacks = *child->GetValue();
          }
        }
          {
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "proxyOpts");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitProxyOptions::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set proxyOpts: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->proxy_opts = *child->GetValue();
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "followRedirects");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to followRedirects"
              };
            }

            output->raw->follow_redirects = static_cast<git_remote_redirect_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
            output->raw->custom_headers.count = 0;
          output->raw->custom_headers.strings = nullptr;

          {
            Napi::Value maybeStrarray = nodegit::safeGetField(inputObj, "customHeaders");
            if (!maybeStrarray.IsUndefined() && !maybeStrarray.IsNull()) {
              if (maybeStrarray.IsArray()) {
                Napi::Array strarrayValue = maybeStrarray.As<Napi::Array>();
                // validate the StrArray is indeed a list of strings
                for (uint32_t i = 0; i < strarrayValue.Length(); ++i) {
                  // TODO confirm that sparse array at least boils down to undefined
                  Napi::Value arrayValue = strarrayValue.Get(i);
                  if (!arrayValue.IsString()) {
                    return {
                      "Must pass String or Array of strings to customHeaders"
                    };
                  }
                }

                StrArrayConverter::ConvertInto(&output->raw->custom_headers, strarrayValue);
              } else if (maybeStrarray.IsString()) {
                Napi::String strarrayValue = maybeStrarray.As<Napi::String>();
                StrArrayConverter::ConvertInto(&output->raw->custom_headers, strarrayValue);
              } else {
                return {
                  "Must pass String or Array of strings to customHeaders"
                };
              }
            }
          }
     
  return {
    output
  };
}

           
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitRemoteConnectOptionsTraits>;
