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
#include "../include/describe_options.h"
#include "bungit_wrapper.cc"

 
using namespace std;

 
ConfigurableGitDescribeOptions::ConfigurableGitDescribeOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitDescribeOptionsTraits>(nodegitContext)
{
     git_describe_options  wrappedValue = GIT_DESCRIBE_OPTIONS_INIT;
    this->raw = (git_describe_options*) malloc(sizeof(git_describe_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_describe_options ));
 }

ConfigurableGitDescribeOptions::~ConfigurableGitDescribeOptions() {
              free((void*)this->raw->pattern);
       }

nodegit::ConfigurableClassWrapper<GitDescribeOptionsTraits>::v8ConversionResult ConfigurableGitDescribeOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitDescribeOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitDescribeOptions> output(new ConfigurableGitDescribeOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "maxCandidatesTags");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to maxCandidatesTags"
              };
            }

            output->raw->max_candidates_tags = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "describeStrategy");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to describeStrategy"
              };
            }

            output->raw->describe_strategy = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          output->raw->pattern = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "pattern");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to pattern"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->pattern = strdup(utf8String.c_str());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "onlyFollowFirstParent");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to onlyFollowFirstParent"
              };
            }

            output->raw->only_follow_first_parent = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "showCommitOidAsFallback");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to showCommitOidAsFallback"
              };
            }

            output->raw->show_commit_oid_as_fallback = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

             
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitDescribeOptionsTraits>;
