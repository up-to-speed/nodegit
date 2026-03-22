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
#include "../include/email_create_options.h"
#include "bungit_wrapper.cc"

  #include "../include/diff_options.h"
  #include "../include/diff_find_options.h"
 
using namespace std;

 
ConfigurableGitEmailCreateOptions::ConfigurableGitEmailCreateOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitEmailCreateOptionsTraits>(nodegitContext)
{
     git_email_create_options  wrappedValue = GIT_EMAIL_CREATE_OPTIONS_INIT;
    this->raw = (git_email_create_options*) malloc(sizeof(git_email_create_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_email_create_options ));
 }

ConfigurableGitEmailCreateOptions::~ConfigurableGitEmailCreateOptions() {
                free((void*)this->raw->subject_prefix);
       }

nodegit::ConfigurableClassWrapper<GitEmailCreateOptionsTraits>::v8ConversionResult ConfigurableGitEmailCreateOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitEmailCreateOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitEmailCreateOptions> output(new ConfigurableGitEmailCreateOptions(nodegitContext));

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
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "diffOpts");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitDiffOptions::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set diffOpts: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->diff_opts = *child->GetValue();
          }
        }
          {
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "diffFindOpts");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitDiffFindOptions::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set diffFindOpts: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->diff_find_opts = *child->GetValue();
          }
        }
          output->raw->subject_prefix = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "subjectPrefix");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to subjectPrefix"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->subject_prefix = strdup(utf8String.c_str());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "startNumber");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to startNumber"
              };
            }

            output->raw->start_number = static_cast<size_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "rerollNumber");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to rerollNumber"
              };
            }

            output->raw->reroll_number = static_cast<size_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

               
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitEmailCreateOptionsTraits>;
