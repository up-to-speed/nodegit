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
#include "../include/remote_create_options.h"
#include "bungit_wrapper.cc"

  #include "../include/repository.h"
 
using namespace std;

 
ConfigurableGitRemoteCreateOptions::ConfigurableGitRemoteCreateOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitRemoteCreateOptionsTraits>(nodegitContext)
{
     git_remote_create_options  wrappedValue = GIT_REMOTE_CREATE_OPTIONS_INIT;
    this->raw = (git_remote_create_options*) malloc(sizeof(git_remote_create_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_remote_create_options ));
 }

ConfigurableGitRemoteCreateOptions::~ConfigurableGitRemoteCreateOptions() {
            free((void*)this->raw->name);
          free((void*)this->raw->fetchspec);
     }

nodegit::ConfigurableClassWrapper<GitRemoteCreateOptionsTraits>::v8ConversionResult ConfigurableGitRemoteCreateOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitRemoteCreateOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitRemoteCreateOptions> output(new ConfigurableGitRemoteCreateOptions(nodegitContext));

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
            Napi::Value maybeObject = nodegit::safeGetField(inputObj, "repository");
            if (!maybeObject.IsUndefined() && !maybeObject.IsNull()) {
              if (!maybeObject.IsObject()) {
                return {
                  "Must pass NodeGit.Repository to repository"
                };
              }

              Napi::Object objectValue = maybeObject.As<Napi::Object>();
              output->raw->repository = Napi::ObjectWrap<GitRepository>::Unwrap(objectValue)->GetValue();
              output->repository.Reset(objectValue);
            }
          }
           output->raw->name = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "name");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to name"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->name = strdup(utf8String.c_str());
          }
        }
          output->raw->fetchspec = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "fetchspec");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to fetchspec"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->fetchspec = strdup(utf8String.c_str());
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

            output->raw->flags = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

           
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitRemoteCreateOptionsTraits>;
