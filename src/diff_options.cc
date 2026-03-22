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
#include "../include/diff_options.h"
#include "bungit_wrapper.cc"

  #include "../include/strarray.h"
  #include "../include/diff_delta.h"
 
using namespace std;

 
ConfigurableGitDiffOptions::ConfigurableGitDiffOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitDiffOptionsTraits>(nodegitContext)
{
     git_diff_options  wrappedValue = GIT_DIFF_OPTIONS_INIT;
    this->raw = (git_diff_options*) malloc(sizeof(git_diff_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_diff_options ));
 }

ConfigurableGitDiffOptions::~ConfigurableGitDiffOptions() {
              if (this->raw->pathspec.count) {
          for (size_t i = 0; i < this->raw->pathspec.count; ++i) {
            free(this->raw->pathspec.strings[i]);
          }
          free(this->raw->pathspec.strings);
        }
                          free((void*)this->raw->old_prefix);
          free((void*)this->raw->new_prefix);
   }

nodegit::ConfigurableClassWrapper<GitDiffOptionsTraits>::v8ConversionResult ConfigurableGitDiffOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitDiffOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitDiffOptions> output(new ConfigurableGitDiffOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "ignoreSubmodules");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to ignoreSubmodules"
              };
            }

            output->raw->ignore_submodules = static_cast<git_submodule_ignore_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
            output->raw->pathspec.count = 0;
          output->raw->pathspec.strings = nullptr;

          {
            Napi::Value maybeStrarray = nodegit::safeGetField(inputObj, "pathspec");
            if (!maybeStrarray.IsUndefined() && !maybeStrarray.IsNull()) {
              if (maybeStrarray.IsArray()) {
                Napi::Array strarrayValue = maybeStrarray.As<Napi::Array>();
                // validate the StrArray is indeed a list of strings
                for (uint32_t i = 0; i < strarrayValue.Length(); ++i) {
                  // TODO confirm that sparse array at least boils down to undefined
                  Napi::Value arrayValue = strarrayValue.Get(i);
                  if (!arrayValue.IsString()) {
                    return {
                      "Must pass String or Array of strings to pathspec"
                    };
                  }
                }

                StrArrayConverter::ConvertInto(&output->raw->pathspec, strarrayValue);
              } else if (maybeStrarray.IsString()) {
                Napi::String strarrayValue = maybeStrarray.As<Napi::String>();
                StrArrayConverter::ConvertInto(&output->raw->pathspec, strarrayValue);
              } else {
                return {
                  "Must pass String or Array of strings to pathspec"
                };
              }
            }
          }
           {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "notifyCb");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to notifyCb"
              };
            }

            std::unique_ptr<Napi::FunctionReference> callback;
            uint32_t throttle =  0 ;
            bool waitForResult = true;

            if (maybeCallback.IsFunction()) {
              callback.reset(new Napi::FunctionReference());
              *callback = Napi::Persistent(maybeCallback.As<Napi::Function>());
            } else {
              Napi::Object callbackSpecifier = maybeCallback.As<Napi::Object>();
              Napi::Value maybeCallback = nodegit::safeGetField(callbackSpecifier, "callback");
              if (maybeCallback.IsUndefined() || !maybeCallback.IsFunction()) {
                return {
                  "Must pass callback to CallbackSpecifier"
                };
              }

              callback.reset(new Napi::FunctionReference());
              *callback = Napi::Persistent(maybeCallback.As<Napi::Function>());

              Napi::Value maybeThrottle = nodegit::safeGetField(callbackSpecifier, "throttle");
              if (!maybeThrottle.IsUndefined() && !maybeThrottle.IsNull()) {
                if (!maybeThrottle.IsNumber()) {
                  return {
                    "Must pass zero or positive number as throttle to CallbackSpecifier"
                  };
                }

                throttle = maybeThrottle.As<Napi::Number>().Uint32Value();
              }

              Napi::Value maybeWaitForResult = nodegit::safeGetField(callbackSpecifier, "waitForResult");
              if (!maybeWaitForResult.IsUndefined() && !maybeWaitForResult.IsNull()) {
                if (!maybeWaitForResult.IsBoolean()) {
                  return {
                    "Must pass a boolean as waitForResult to callbackSpecifier"
                  };
                }

                waitForResult = maybeWaitForResult.As<Napi::Boolean>().Value();
              }
            }

            output->notifyCb.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->notify_cb = (git_diff_notify_cb)notifyCb_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "progressCb");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to progressCb"
              };
            }

            std::unique_ptr<Napi::FunctionReference> callback;
            uint32_t throttle =  0 ;
            bool waitForResult = true;

            if (maybeCallback.IsFunction()) {
              callback.reset(new Napi::FunctionReference());
              *callback = Napi::Persistent(maybeCallback.As<Napi::Function>());
            } else {
              Napi::Object callbackSpecifier = maybeCallback.As<Napi::Object>();
              Napi::Value maybeCallback = nodegit::safeGetField(callbackSpecifier, "callback");
              if (maybeCallback.IsUndefined() || !maybeCallback.IsFunction()) {
                return {
                  "Must pass callback to CallbackSpecifier"
                };
              }

              callback.reset(new Napi::FunctionReference());
              *callback = Napi::Persistent(maybeCallback.As<Napi::Function>());

              Napi::Value maybeThrottle = nodegit::safeGetField(callbackSpecifier, "throttle");
              if (!maybeThrottle.IsUndefined() && !maybeThrottle.IsNull()) {
                if (!maybeThrottle.IsNumber()) {
                  return {
                    "Must pass zero or positive number as throttle to CallbackSpecifier"
                  };
                }

                throttle = maybeThrottle.As<Napi::Number>().Uint32Value();
              }

              Napi::Value maybeWaitForResult = nodegit::safeGetField(callbackSpecifier, "waitForResult");
              if (!maybeWaitForResult.IsUndefined() && !maybeWaitForResult.IsNull()) {
                if (!maybeWaitForResult.IsBoolean()) {
                  return {
                    "Must pass a boolean as waitForResult to callbackSpecifier"
                  };
                }

                waitForResult = maybeWaitForResult.As<Napi::Boolean>().Value();
              }
            }

            output->progressCb.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->progress_cb = (git_diff_progress_cb)progressCb_cppCallback;
          }
        }
          output->raw->payload = (void *)output.get();
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "contextLines");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to contextLines"
              };
            }

            output->raw->context_lines = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "interhunkLines");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to interhunkLines"
              };
            }

            output->raw->interhunk_lines = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "oidType");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to oidType"
              };
            }

            output->raw->oid_type = static_cast<git_oid_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "idAbbrev");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to idAbbrev"
              };
            }

            output->raw->id_abbrev = static_cast<uint16_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "maxSize");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to maxSize"
              };
            }

            output->raw->max_size = static_cast<git_off_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          output->raw->old_prefix = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "oldPrefix");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to oldPrefix"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->old_prefix = strdup(utf8String.c_str());
          }
        }
          output->raw->new_prefix = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "newPrefix");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to newPrefix"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->new_prefix = strdup(utf8String.c_str());
          }
        }
    
  return {
    output
  };
}

              ConfigurableGitDiffOptions* ConfigurableGitDiffOptions::notifyCb_getInstanceFromBaton(NotifyCbBaton* baton) {
           return static_cast<ConfigurableGitDiffOptions*>(baton->
                 payload
  );
       }

      int ConfigurableGitDiffOptions::notifyCb_cppCallback (
          const git_diff * diff_so_far,           git_diff_delta * delta_to_add,           const char * matched_pathspec,           void * payload        ) {
        NotifyCbBaton *baton =
          new NotifyCbBaton(1);

          baton->diff_so_far = diff_so_far;
          baton->delta_to_add = delta_to_add;
          baton->matched_pathspec = matched_pathspec;
          baton->payload = payload;
 
        ConfigurableGitDiffOptions* instance = notifyCb_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->notifyCb.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->notifyCb.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(notifyCb_async, notifyCb_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(notifyCb_async, notifyCb_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitDiffOptions::notifyCb_cancelAsync(void *untypedBaton) {
        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitDiffOptions::notifyCb_async(void *untypedBaton) {
        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(untypedBaton);
        ConfigurableGitDiffOptions* instance = notifyCb_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->notifyCb.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

              Napi::Value argv[2] = {
               GitDiffDelta::New(env, baton->delta_to_add, false)
 ,               baton->matched_pathspec == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->matched_pathspec)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[2];
          for (int _i = 0; _i < 2; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->notifyCb.GetCallback()->Call(env.Undefined(), 2, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitDiffOptions::notifyCb_promiseCompleted)) {
          return;
        }

             if (result.IsUndefined() || result.IsNull()) {
              baton->result = baton->defaultResult;
            }
            else if (!result.IsNull() && !result.IsUndefined()) {
                 if (result.IsNumber()) {
                  baton->result = result.As<Napi::Number>().Int32Value();
                }
                else {
                  baton->result = baton->defaultResult;
                }
             }
            else {
              baton->result = baton->defaultResult;
            }
           baton->Done();
       }

      void ConfigurableGitDiffOptions::notifyCb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(_baton);
           if (isFulfilled) {
              if (result.IsUndefined() || result.IsNull()) {
                baton->result = baton->defaultResult;
              }
              else if (!result.IsNull() && !result.IsUndefined()) {
                   if (result.IsNumber()) {
                    baton->result = result.As<Napi::Number>().Int32Value();
                  }
                  else {
                    baton->result = baton->defaultResult;
                  }
               }
              else {
                baton->result = baton->defaultResult;
              }
           }
          else {
            // promise was rejected
               ConfigurableGitDiffOptions* instance = static_cast<ConfigurableGitDiffOptions*>(baton->   payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitDiffOptions* ConfigurableGitDiffOptions::progressCb_getInstanceFromBaton(ProgressCbBaton* baton) {
           return static_cast<ConfigurableGitDiffOptions*>(baton->
                 payload
  );
       }

      int ConfigurableGitDiffOptions::progressCb_cppCallback (
          const git_diff * diff_so_far,           const char * old_path,           const char * new_path,           void * payload        ) {
        ProgressCbBaton *baton =
          new ProgressCbBaton(1);

          baton->diff_so_far = diff_so_far;
          baton->old_path = old_path;
          baton->new_path = new_path;
          baton->payload = payload;
 
        ConfigurableGitDiffOptions* instance = progressCb_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->progressCb.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->progressCb.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(progressCb_async, progressCb_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(progressCb_async, progressCb_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitDiffOptions::progressCb_cancelAsync(void *untypedBaton) {
        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitDiffOptions::progressCb_async(void *untypedBaton) {
        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(untypedBaton);
        ConfigurableGitDiffOptions* instance = progressCb_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->progressCb.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

              Napi::Value argv[2] = {
               baton->old_path == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->old_path)
 ,               baton->new_path == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->new_path)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[2];
          for (int _i = 0; _i < 2; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->progressCb.GetCallback()->Call(env.Undefined(), 2, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitDiffOptions::progressCb_promiseCompleted)) {
          return;
        }

             if (result.IsUndefined() || result.IsNull()) {
              baton->result = baton->defaultResult;
            }
            else if (!result.IsNull() && !result.IsUndefined()) {
                 if (result.IsNumber()) {
                  baton->result = result.As<Napi::Number>().Int32Value();
                }
                else {
                  baton->result = baton->defaultResult;
                }
             }
            else {
              baton->result = baton->defaultResult;
            }
           baton->Done();
       }

      void ConfigurableGitDiffOptions::progressCb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(_baton);
           if (isFulfilled) {
              if (result.IsUndefined() || result.IsNull()) {
                baton->result = baton->defaultResult;
              }
              else if (!result.IsNull() && !result.IsUndefined()) {
                   if (result.IsNumber()) {
                    baton->result = result.As<Napi::Number>().Int32Value();
                  }
                  else {
                    baton->result = baton->defaultResult;
                  }
               }
              else {
                baton->result = baton->defaultResult;
              }
           }
          else {
            // promise was rejected
               ConfigurableGitDiffOptions* instance = static_cast<ConfigurableGitDiffOptions*>(baton->   payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
                   
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitDiffOptionsTraits>;
