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
#include "../include/describe_format_options.h"
#include "bungit_wrapper.cc"

 
using namespace std;

 
ConfigurableGitDescribeFormatOptions::ConfigurableGitDescribeFormatOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitDescribeFormatOptionsTraits>(nodegitContext)
{
     git_describe_format_options  wrappedValue = GIT_DESCRIBE_FORMAT_OPTIONS_INIT;
    this->raw = (git_describe_format_options*) malloc(sizeof(git_describe_format_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_describe_format_options ));
 }

ConfigurableGitDescribeFormatOptions::~ConfigurableGitDescribeFormatOptions() {
              free((void*)this->raw->dirty_suffix);
   }

nodegit::ConfigurableClassWrapper<GitDescribeFormatOptionsTraits>::v8ConversionResult ConfigurableGitDescribeFormatOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitDescribeFormatOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitDescribeFormatOptions> output(new ConfigurableGitDescribeFormatOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "abbreviatedSize");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to abbreviatedSize"
              };
            }

            output->raw->abbreviated_size = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "alwaysUseLongFormat");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to alwaysUseLongFormat"
              };
            }

            output->raw->always_use_long_format = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          output->raw->dirty_suffix = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "dirtySuffix");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to dirtySuffix"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->dirty_suffix = strdup(utf8String.c_str());
          }
        }
    
  return {
    output
  };
}

         
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitDescribeFormatOptionsTraits>;
