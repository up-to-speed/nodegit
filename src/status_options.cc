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
#include "../include/status_options.h"
#include "bungit_wrapper.cc"

  #include "../include/strarray.h"
 
using namespace std;

 
ConfigurableGitStatusOptions::ConfigurableGitStatusOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitStatusOptionsTraits>(nodegitContext)
{
     git_status_options  wrappedValue = GIT_STATUS_OPTIONS_INIT;
    this->raw = (git_status_options*) malloc(sizeof(git_status_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_status_options ));
 }

ConfigurableGitStatusOptions::~ConfigurableGitStatusOptions() {
              if (this->raw->pathspec.count) {
          for (size_t i = 0; i < this->raw->pathspec.count; ++i) {
            free(this->raw->pathspec.strings[i]);
          }
          free(this->raw->pathspec.strings);
        }
   }

nodegit::ConfigurableClassWrapper<GitStatusOptionsTraits>::v8ConversionResult ConfigurableGitStatusOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitStatusOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitStatusOptions> output(new ConfigurableGitStatusOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "show");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to show"
              };
            }

            output->raw->show = static_cast<git_status_show_t>(maybeNumber.As<Napi::Number>().Int32Value());
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

            output->raw->flags = static_cast<git_status_opt_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
            output->raw->pathspec.count = 0;
          output->raw->pathspec.strings = nullptr;

          {
            Napi::Value maybeStrarray = nodegit::safeGetField(inputObj, "pathspec");
            if (!maybeStrarray.IsUndefined() && !maybeStrarray.IsNull()) {
              if (maybeStrarray.IsArray()) {
                Napi::Array strarrayValue = maybeStrarray.As<Napi::Array>();
                // validate the StrArray is indeed a list of strings
                for (uint32_t i = 0; i < strarrayValue.Length(); ++i) {
                  // TODO confirm that sparse array at least boils down to undefined
                  Napi::Value arrayValue = strarrayValue.Get(i);
                  if (!arrayValue.IsString()) {
                    return {
                      "Must pass String or Array of strings to pathspec"
                    };
                  }
                }

                StrArrayConverter::ConvertInto(&output->raw->pathspec, strarrayValue);
              } else if (maybeStrarray.IsString()) {
                Napi::String strarrayValue = maybeStrarray.As<Napi::String>();
                StrArrayConverter::ConvertInto(&output->raw->pathspec, strarrayValue);
              } else {
                return {
                  "Must pass String or Array of strings to pathspec"
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
template class nodegit::ConfigurableClassWrapper<GitStatusOptionsTraits>;
