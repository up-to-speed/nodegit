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
#include "../include/apply_options.h"
#include "bungit_wrapper.cc"

  #include "../include/diff_delta.h"
  #include "../include/diff_hunk.h"
 
using namespace std;

 
ConfigurableGitApplyOptions::ConfigurableGitApplyOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitApplyOptionsTraits>(nodegitContext)
{
     git_apply_options  wrappedValue = GIT_APPLY_OPTIONS_INIT;
    this->raw = (git_apply_options*) malloc(sizeof(git_apply_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_apply_options ));
 }

ConfigurableGitApplyOptions::~ConfigurableGitApplyOptions() {
         }

nodegit::ConfigurableClassWrapper<GitApplyOptionsTraits>::v8ConversionResult ConfigurableGitApplyOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitApplyOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitApplyOptions> output(new ConfigurableGitApplyOptions(nodegitContext));

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
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "deltaCb");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to deltaCb"
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

            output->deltaCb.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->delta_cb = (git_apply_delta_cb)deltaCb_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "hunkCb");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to hunkCb"
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

            output->hunkCb.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->hunk_cb = (git_apply_hunk_cb)hunkCb_cppCallback;
          }
        }
          output->raw->payload = (void *)output.get();
    
  return {
    output
  };
}

        ConfigurableGitApplyOptions* ConfigurableGitApplyOptions::deltaCb_getInstanceFromBaton(DeltaCbBaton* baton) {
           return static_cast<ConfigurableGitApplyOptions*>(baton->
               payload
  );
       }

      int ConfigurableGitApplyOptions::deltaCb_cppCallback (
          const git_diff_delta * delta,           void * payload        ) {
        DeltaCbBaton *baton =
          new DeltaCbBaton(1);

          baton->delta = delta;
          baton->payload = payload;
 
        ConfigurableGitApplyOptions* instance = deltaCb_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->deltaCb.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->deltaCb.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(deltaCb_async, deltaCb_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(deltaCb_async, deltaCb_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitApplyOptions::deltaCb_cancelAsync(void *untypedBaton) {
        DeltaCbBaton* baton = static_cast<DeltaCbBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitApplyOptions::deltaCb_async(void *untypedBaton) {
        DeltaCbBaton* baton = static_cast<DeltaCbBaton*>(untypedBaton);
        ConfigurableGitApplyOptions* instance = deltaCb_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->deltaCb.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

             Napi::Value argv[1] = {
               GitDiffDelta::New(env, baton->delta, false)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[1];
          for (int _i = 0; _i < 1; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->deltaCb.GetCallback()->Call(env.Undefined(), 1, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitApplyOptions::deltaCb_promiseCompleted)) {
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

      void ConfigurableGitApplyOptions::deltaCb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        DeltaCbBaton* baton = static_cast<DeltaCbBaton*>(_baton);
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
               ConfigurableGitApplyOptions* instance = static_cast<ConfigurableGitApplyOptions*>(baton-> payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitApplyOptions* ConfigurableGitApplyOptions::hunkCb_getInstanceFromBaton(HunkCbBaton* baton) {
           return static_cast<ConfigurableGitApplyOptions*>(baton->
               payload
  );
       }

      int ConfigurableGitApplyOptions::hunkCb_cppCallback (
          const git_diff_hunk * hunk,           void * payload        ) {
        HunkCbBaton *baton =
          new HunkCbBaton(1);

          baton->hunk = hunk;
          baton->payload = payload;
 
        ConfigurableGitApplyOptions* instance = hunkCb_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->hunkCb.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->hunkCb.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(hunkCb_async, hunkCb_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(hunkCb_async, hunkCb_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitApplyOptions::hunkCb_cancelAsync(void *untypedBaton) {
        HunkCbBaton* baton = static_cast<HunkCbBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitApplyOptions::hunkCb_async(void *untypedBaton) {
        HunkCbBaton* baton = static_cast<HunkCbBaton*>(untypedBaton);
        ConfigurableGitApplyOptions* instance = hunkCb_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->hunkCb.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

             Napi::Value argv[1] = {
               GitDiffHunk::New(env, baton->hunk, false)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[1];
          for (int _i = 0; _i < 1; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->hunkCb.GetCallback()->Call(env.Undefined(), 1, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitApplyOptions::hunkCb_promiseCompleted)) {
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

      void ConfigurableGitApplyOptions::hunkCb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        HunkCbBaton* baton = static_cast<HunkCbBaton*>(_baton);
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
               ConfigurableGitApplyOptions* instance = static_cast<ConfigurableGitApplyOptions*>(baton-> payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
     
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitApplyOptionsTraits>;
