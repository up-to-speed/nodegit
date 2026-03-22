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
#include "../include/diff_find_options.h"
#include "bungit_wrapper.cc"

 
using namespace std;

 
ConfigurableGitDiffFindOptions::ConfigurableGitDiffFindOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitDiffFindOptionsTraits>(nodegitContext)
{
     git_diff_find_options  wrappedValue = GIT_DIFF_FIND_OPTIONS_INIT;
    this->raw = (git_diff_find_options*) malloc(sizeof(git_diff_find_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_diff_find_options ));
 }

ConfigurableGitDiffFindOptions::~ConfigurableGitDiffFindOptions() {
               }

nodegit::ConfigurableClassWrapper<GitDiffFindOptionsTraits>::v8ConversionResult ConfigurableGitDiffFindOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitDiffFindOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitDiffFindOptions> output(new ConfigurableGitDiffFindOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "renameThreshold");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to renameThreshold"
              };
            }

            output->raw->rename_threshold = static_cast<uint16_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "renameFromRewriteThreshold");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to renameFromRewriteThreshold"
              };
            }

            output->raw->rename_from_rewrite_threshold = static_cast<uint16_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "copyThreshold");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to copyThreshold"
              };
            }

            output->raw->copy_threshold = static_cast<uint16_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "breakRewriteThreshold");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to breakRewriteThreshold"
              };
            }

            output->raw->break_rewrite_threshold = static_cast<uint16_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "renameLimit");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to renameLimit"
              };
            }

            output->raw->rename_limit = static_cast<size_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

               
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitDiffFindOptionsTraits>;
