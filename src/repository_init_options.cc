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
#include "../include/repository_init_options.h"
#include "bungit_wrapper.cc"

 
using namespace std;

 
ConfigurableGitRepositoryInitOptions::ConfigurableGitRepositoryInitOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitRepositoryInitOptionsTraits>(nodegitContext)
{
     git_repository_init_options  wrappedValue = GIT_REPOSITORY_INIT_OPTIONS_INIT;
    this->raw = (git_repository_init_options*) malloc(sizeof(git_repository_init_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_repository_init_options ));
 }

ConfigurableGitRepositoryInitOptions::~ConfigurableGitRepositoryInitOptions() {
              free((void*)this->raw->workdir_path);
          free((void*)this->raw->description);
          free((void*)this->raw->template_path);
          free((void*)this->raw->initial_head);
          free((void*)this->raw->origin_url);
   }

nodegit::ConfigurableClassWrapper<GitRepositoryInitOptionsTraits>::v8ConversionResult ConfigurableGitRepositoryInitOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitRepositoryInitOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitRepositoryInitOptions> output(new ConfigurableGitRepositoryInitOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "mode");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to mode"
              };
            }

            output->raw->mode = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          output->raw->workdir_path = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "workdirPath");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to workdirPath"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->workdir_path = strdup(utf8String.c_str());
          }
        }
          output->raw->description = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "description");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to description"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->description = strdup(utf8String.c_str());
          }
        }
          output->raw->template_path = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "templatePath");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to templatePath"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->template_path = strdup(utf8String.c_str());
          }
        }
          output->raw->initial_head = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "initialHead");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to initialHead"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->initial_head = strdup(utf8String.c_str());
          }
        }
          output->raw->origin_url = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "originUrl");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to originUrl"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->origin_url = strdup(utf8String.c_str());
          }
        }
    
  return {
    output
  };
}

                 
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitRepositoryInitOptionsTraits>;
