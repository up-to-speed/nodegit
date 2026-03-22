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
#include "../include/merge_file_options.h"
#include "bungit_wrapper.cc"

 
using namespace std;

 
ConfigurableGitMergeFileOptions::ConfigurableGitMergeFileOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitMergeFileOptionsTraits>(nodegitContext)
{
     git_merge_file_options  wrappedValue = GIT_MERGE_FILE_OPTIONS_INIT;
    this->raw = (git_merge_file_options*) malloc(sizeof(git_merge_file_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_merge_file_options ));
 }

ConfigurableGitMergeFileOptions::~ConfigurableGitMergeFileOptions() {
          free((void*)this->raw->ancestor_label);
          free((void*)this->raw->our_label);
          free((void*)this->raw->their_label);
         }

nodegit::ConfigurableClassWrapper<GitMergeFileOptionsTraits>::v8ConversionResult ConfigurableGitMergeFileOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitMergeFileOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitMergeFileOptions> output(new ConfigurableGitMergeFileOptions(nodegitContext));

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
          output->raw->ancestor_label = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "ancestorLabel");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to ancestorLabel"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->ancestor_label = strdup(utf8String.c_str());
          }
        }
          output->raw->our_label = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "ourLabel");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to ourLabel"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->our_label = strdup(utf8String.c_str());
          }
        }
          output->raw->their_label = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "theirLabel");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to theirLabel"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->their_label = strdup(utf8String.c_str());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "favor");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to favor"
              };
            }

            output->raw->favor = static_cast<git_merge_file_favor_t>(maybeNumber.As<Napi::Number>().Int32Value());
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
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "markerSize");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to markerSize"
              };
            }

            output->raw->marker_size = static_cast<unsigned short>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

               
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitMergeFileOptionsTraits>;
