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
#include "../include/merge_file_input.h"
#include "bungit_wrapper.cc"

 
using namespace std;

 
ConfigurableGitMergeFileInput::ConfigurableGitMergeFileInput(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitMergeFileInputTraits>(nodegitContext)
{
     git_merge_file_input  wrappedValue = GIT_MERGE_FILE_INPUT_INIT;
    this->raw = (git_merge_file_input*) malloc(sizeof(git_merge_file_input ));
    memcpy(this->raw, &wrappedValue, sizeof(git_merge_file_input ));
 }

ConfigurableGitMergeFileInput::~ConfigurableGitMergeFileInput() {
          free((void*)this->raw->ptr);
            free((void*)this->raw->path);
     }

nodegit::ConfigurableClassWrapper<GitMergeFileInputTraits>::v8ConversionResult ConfigurableGitMergeFileInput::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitMergeFileInput"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitMergeFileInput> output(new ConfigurableGitMergeFileInput(nodegitContext));

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
          output->raw->ptr = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "ptr");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to ptr"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->ptr = strdup(utf8String.c_str());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "size");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to size"
              };
            }

            output->raw->size = static_cast<size_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          output->raw->path = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "path");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to path"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->path = strdup(utf8String.c_str());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "mode");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to mode"
              };
            }

            output->raw->mode = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

           
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitMergeFileInputTraits>;
