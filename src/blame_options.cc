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
#include "../include/blame_options.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
 
using namespace std;

 
ConfigurableGitBlameOptions::ConfigurableGitBlameOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitBlameOptionsTraits>(nodegitContext)
{
     git_blame_options  wrappedValue = GIT_BLAME_OPTIONS_INIT;
    this->raw = (git_blame_options*) malloc(sizeof(git_blame_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_blame_options ));
 }

ConfigurableGitBlameOptions::~ConfigurableGitBlameOptions() {
               }

nodegit::ConfigurableClassWrapper<GitBlameOptionsTraits>::v8ConversionResult ConfigurableGitBlameOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitBlameOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitBlameOptions> output(new ConfigurableGitBlameOptions(nodegitContext));

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

            output->raw->flags = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "minMatchCharacters");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to minMatchCharacters"
              };
            }

            output->raw->min_match_characters = static_cast<uint16_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
            {
            Napi::Value maybeOid = nodegit::safeGetField(inputObj, "newestCommit");
            if (!maybeOid.IsUndefined() && !maybeOid.IsNull()) {
              if (maybeOid.IsString()) {
                std::string oidString = maybeOid.As<Napi::String>().Utf8Value();
                if (git_oid_fromstr(&output->raw->newest_commit, oidString.c_str()) != GIT_OK) {
                  return {
                    git_error_last()->message
                  };
                }
              } else if (maybeOid.IsObject()) {
                if (git_oid_cpy(&output->raw->newest_commit, Napi::ObjectWrap<GitOid>::Unwrap(maybeOid.As<Napi::Object>())->GetValue()) != GIT_OK) {
                  return {
                    git_error_last()->message
                  };
                }
              } else {
                return {
                  "Must pass String or NodeGit.Oid to newestCommit"
                };
              }
            }
          }
             {
            Napi::Value maybeOid = nodegit::safeGetField(inputObj, "oldestCommit");
            if (!maybeOid.IsUndefined() && !maybeOid.IsNull()) {
              if (maybeOid.IsString()) {
                std::string oidString = maybeOid.As<Napi::String>().Utf8Value();
                if (git_oid_fromstr(&output->raw->oldest_commit, oidString.c_str()) != GIT_OK) {
                  return {
                    git_error_last()->message
                  };
                }
              } else if (maybeOid.IsObject()) {
                if (git_oid_cpy(&output->raw->oldest_commit, Napi::ObjectWrap<GitOid>::Unwrap(maybeOid.As<Napi::Object>())->GetValue()) != GIT_OK) {
                  return {
                    git_error_last()->message
                  };
                }
              } else {
                return {
                  "Must pass String or NodeGit.Oid to oldestCommit"
                };
              }
            }
          }
            {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "minLine");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to minLine"
              };
            }

            output->raw->min_line = static_cast<size_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "maxLine");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to maxLine"
              };
            }

            output->raw->max_line = static_cast<size_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

               
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitBlameOptionsTraits>;
