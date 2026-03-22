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
#include "../include/stash_save_options.h"
#include "bungit_wrapper.cc"

  #include "../include/str_array_converter.h"
  #include "../include/signature.h"
  #include "../include/strarray.h"
 
using namespace std;

 
ConfigurableGitStashSaveOptions::ConfigurableGitStashSaveOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitStashSaveOptionsTraits>(nodegitContext)
{
     git_stash_save_options  wrappedValue = GIT_STASH_SAVE_OPTIONS_INIT;
    this->raw = (git_stash_save_options*) malloc(sizeof(git_stash_save_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_stash_save_options ));
 }

ConfigurableGitStashSaveOptions::~ConfigurableGitStashSaveOptions() {
              free((void*)this->raw->message);
          if (this->raw->paths.count) {
          for (size_t i = 0; i < this->raw->paths.count; ++i) {
            free(this->raw->paths.strings[i]);
          }
          free(this->raw->paths.strings);
        }
   }

nodegit::ConfigurableClassWrapper<GitStashSaveOptionsTraits>::v8ConversionResult ConfigurableGitStashSaveOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitStashSaveOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitStashSaveOptions> output(new ConfigurableGitStashSaveOptions(nodegitContext));

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
            Napi::Value maybeObject = nodegit::safeGetField(inputObj, "stasher");
            if (!maybeObject.IsUndefined() && !maybeObject.IsNull()) {
              if (!maybeObject.IsObject()) {
                return {
                  "Must pass NodeGit.Signature to stasher"
                };
              }

              Napi::Object objectValue = maybeObject.As<Napi::Object>();
              output->raw->stasher = Napi::ObjectWrap<GitSignature>::Unwrap(objectValue)->GetValue();
              output->stasher.Reset(objectValue);
            }
          }
           output->raw->message = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "message");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to message"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->message = strdup(utf8String.c_str());
          }
        }
            output->raw->paths.count = 0;
          output->raw->paths.strings = nullptr;

          {
            Napi::Value maybeStrarray = nodegit::safeGetField(inputObj, "paths");
            if (!maybeStrarray.IsUndefined() && !maybeStrarray.IsNull()) {
              if (maybeStrarray.IsArray()) {
                Napi::Array strarrayValue = maybeStrarray.As<Napi::Array>();
                // validate the StrArray is indeed a list of strings
                for (uint32_t i = 0; i < strarrayValue.Length(); ++i) {
                  // TODO confirm that sparse array at least boils down to undefined
                  Napi::Value arrayValue = strarrayValue.Get(i);
                  if (!arrayValue.IsString()) {
                    return {
                      "Must pass String or Array of strings to paths"
                    };
                  }
                }

                StrArrayConverter::ConvertInto(&output->raw->paths, strarrayValue);
              } else if (maybeStrarray.IsString()) {
                Napi::String strarrayValue = maybeStrarray.As<Napi::String>();
                StrArrayConverter::ConvertInto(&output->raw->paths, strarrayValue);
              } else {
                return {
                  "Must pass String or Array of strings to paths"
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
template class nodegit::ConfigurableClassWrapper<GitStashSaveOptionsTraits>;
