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
#include "../include/tree_update.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
 
using namespace std;

 
ConfigurableGitTreeUpdate::ConfigurableGitTreeUpdate(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitTreeUpdateTraits>(nodegitContext)
{
    this->raw = (git_tree_update*) malloc(sizeof(git_tree_update));
 }

ConfigurableGitTreeUpdate::~ConfigurableGitTreeUpdate() {
              free((void*)this->raw->path);
   }

nodegit::ConfigurableClassWrapper<GitTreeUpdateTraits>::v8ConversionResult ConfigurableGitTreeUpdate::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitTreeUpdate"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitTreeUpdate> output(new ConfigurableGitTreeUpdate(nodegitContext));

  // unpack the data into the correct fields
         {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "action");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to action"
              };
            }

            output->raw->action = static_cast<git_tree_update_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
            {
            Napi::Value maybeOid = nodegit::safeGetField(inputObj, "id");
            if (!maybeOid.IsUndefined() && !maybeOid.IsNull()) {
              if (maybeOid.IsString()) {
                std::string oidString = maybeOid.As<Napi::String>().Utf8Value();
                if (git_oid_fromstr(&output->raw->id, oidString.c_str()) != GIT_OK) {
                  return {
                    git_error_last()->message
                  };
                }
              } else if (maybeOid.IsObject()) {
                if (git_oid_cpy(&output->raw->id, Napi::ObjectWrap<GitOid>::Unwrap(maybeOid.As<Napi::Object>())->GetValue()) != GIT_OK) {
                  return {
                    git_error_last()->message
                  };
                }
              } else {
                return {
                  "Must pass String or NodeGit.Oid to id"
                };
              }
            }
          }
            {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "filemode");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to filemode"
              };
            }

            output->raw->filemode = static_cast<git_filemode_t>(maybeNumber.As<Napi::Number>().Int32Value());
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
    
  return {
    output
  };
}

         
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitTreeUpdateTraits>;
