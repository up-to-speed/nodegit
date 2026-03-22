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
#include "../include/checkout_options.h"
#include "bungit_wrapper.cc"

  #include "../include/diff_file.h"
  #include "../include/strarray.h"
  #include "../include/tree.h"
  #include "../include/index.h"
  #include "../include/checkout_perfdata.h"
 
using namespace std;

 
ConfigurableGitCheckoutOptions::ConfigurableGitCheckoutOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitCheckoutOptionsTraits>(nodegitContext)
{
     git_checkout_options  wrappedValue = GIT_CHECKOUT_OPTIONS_INIT;
    this->raw = (git_checkout_options*) malloc(sizeof(git_checkout_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_checkout_options ));
 }

ConfigurableGitCheckoutOptions::~ConfigurableGitCheckoutOptions() {
                              if (this->raw->paths.count) {
          for (size_t i = 0; i < this->raw->paths.count; ++i) {
            free(this->raw->paths.strings[i]);
          }
          free(this->raw->paths.strings);
        }
              free((void*)this->raw->target_directory);
          free((void*)this->raw->ancestor_label);
          free((void*)this->raw->our_label);
          free((void*)this->raw->their_label);
              if (this->raw->disabled_filters.count) {
          for (size_t i = 0; i < this->raw->disabled_filters.count; ++i) {
            free(this->raw->disabled_filters.strings[i]);
          }
          free(this->raw->disabled_filters.strings);
        }
   }

nodegit::ConfigurableClassWrapper<GitCheckoutOptionsTraits>::v8ConversionResult ConfigurableGitCheckoutOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitCheckoutOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitCheckoutOptions> output(new ConfigurableGitCheckoutOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "checkoutStrategy");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to checkoutStrategy"
              };
            }

            output->raw->checkout_strategy = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "disableFilters");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to disableFilters"
              };
            }

            output->raw->disable_filters = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "dirMode");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to dirMode"
              };
            }

            output->raw->dir_mode = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "fileMode");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to fileMode"
              };
            }

            output->raw->file_mode = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "fileOpenFlags");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to fileOpenFlags"
              };
            }

            output->raw->file_open_flags = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "notifyFlags");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to notifyFlags"
              };
            }

            output->raw->notify_flags = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
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
            output->raw->notify_cb = (git_checkout_notify_cb)notifyCb_cppCallback;
          }
        }
          output->raw->notify_payload = (void *)output.get();
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "progressCb");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to progressCb"
              };
            }

            std::unique_ptr<Napi::FunctionReference> callback;
            uint32_t throttle = 100 ;
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
            output->raw->progress_cb = (git_checkout_progress_cb)progressCb_cppCallback;
          }
        }
          output->raw->progress_payload = (void *)output.get();
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
              {
            Napi::Value maybeObject = nodegit::safeGetField(inputObj, "baseline");
            if (!maybeObject.IsUndefined() && !maybeObject.IsNull()) {
              if (!maybeObject.IsObject()) {
                return {
                  "Must pass NodeGit.Tree to baseline"
                };
              }

              Napi::Object objectValue = maybeObject.As<Napi::Object>();
              output->raw->baseline = Napi::ObjectWrap<GitTree>::Unwrap(objectValue)->GetValue();
              output->baseline.Reset(objectValue);
            }
          }
              {
            Napi::Value maybeObject = nodegit::safeGetField(inputObj, "baselineIndex");
            if (!maybeObject.IsUndefined() && !maybeObject.IsNull()) {
              if (!maybeObject.IsObject()) {
                return {
                  "Must pass NodeGit.Index to baselineIndex"
                };
              }

              Napi::Object objectValue = maybeObject.As<Napi::Object>();
              output->raw->baseline_index = Napi::ObjectWrap<GitIndex>::Unwrap(objectValue)->GetValue();
              output->baselineIndex.Reset(objectValue);
            }
          }
           output->raw->target_directory = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "targetDirectory");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to targetDirectory"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->target_directory = strdup(utf8String.c_str());
          }
        }
          output->raw->ancestor_label = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "ancestorLabel");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to ancestorLabel"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->ancestor_label = strdup(utf8String.c_str());
          }
        }
          output->raw->our_label = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "ourLabel");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to ourLabel"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->our_label = strdup(utf8String.c_str());
          }
        }
          output->raw->their_label = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "theirLabel");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to theirLabel"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->their_label = strdup(utf8String.c_str());
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "perfdataCb");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to perfdataCb"
              };
            }

            std::unique_ptr<Napi::FunctionReference> callback;
            uint32_t throttle = 100 ;
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

            output->perfdataCb.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->perfdata_cb = (git_checkout_perfdata_cb)perfdataCb_cppCallback;
          }
        }
          output->raw->perfdata_payload = (void *)output.get();
            output->raw->disabled_filters.count = 0;
          output->raw->disabled_filters.strings = nullptr;

          {
            Napi::Value maybeStrarray = nodegit::safeGetField(inputObj, "disabledFilters");
            if (!maybeStrarray.IsUndefined() && !maybeStrarray.IsNull()) {
              if (maybeStrarray.IsArray()) {
                Napi::Array strarrayValue = maybeStrarray.As<Napi::Array>();
                // validate the StrArray is indeed a list of strings
                for (uint32_t i = 0; i < strarrayValue.Length(); ++i) {
                  // TODO confirm that sparse array at least boils down to undefined
                  Napi::Value arrayValue = strarrayValue.Get(i);
                  if (!arrayValue.IsString()) {
                    return {
                      "Must pass String or Array of strings to disabledFilters"
                    };
                  }
                }

                StrArrayConverter::ConvertInto(&output->raw->disabled_filters, strarrayValue);
              } else if (maybeStrarray.IsString()) {
                Napi::String strarrayValue = maybeStrarray.As<Napi::String>();
                StrArrayConverter::ConvertInto(&output->raw->disabled_filters, strarrayValue);
              } else {
                return {
                  "Must pass String or Array of strings to disabledFilters"
                };
              }
            }
          }
     
  return {
    output
  };
}

                    ConfigurableGitCheckoutOptions* ConfigurableGitCheckoutOptions::notifyCb_getInstanceFromBaton(NotifyCbBaton* baton) {
           return static_cast<ConfigurableGitCheckoutOptions*>(baton->
                   payload
  );
       }

      int ConfigurableGitCheckoutOptions::notifyCb_cppCallback (
          git_checkout_notify_t why,           const char * path,           const git_diff_file * baseline,           const git_diff_file * target,           const git_diff_file * workdir,           void * payload        ) {
        NotifyCbBaton *baton =
          new NotifyCbBaton(1);

          baton->why = why;
          baton->path = path;
          baton->baseline = baseline;
          baton->target = target;
          baton->workdir = workdir;
          baton->payload = payload;
 
        ConfigurableGitCheckoutOptions* instance = notifyCb_getInstanceFromBaton(baton);

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

      void ConfigurableGitCheckoutOptions::notifyCb_cancelAsync(void *untypedBaton) {
        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(untypedBaton);
          baton->result = 0;
         baton->Done();
      }

      void ConfigurableGitCheckoutOptions::notifyCb_async(void *untypedBaton) {
        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(untypedBaton);
        ConfigurableGitCheckoutOptions* instance = notifyCb_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->notifyCb.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

                 Napi::Value argv[5] = {
               Napi::Number::New(env, (int)baton->why)
 ,               baton->path == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->path)
 ,               GitDiffFile::New(env, baton->baseline, false)
 ,               GitDiffFile::New(env, baton->target, false)
 ,               GitDiffFile::New(env, baton->workdir, false)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[5];
          for (int _i = 0; _i < 5; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->notifyCb.GetCallback()->Call(env.Undefined(), 5, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitCheckoutOptions::notifyCb_promiseCompleted)) {
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

      void ConfigurableGitCheckoutOptions::notifyCb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
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
               ConfigurableGitCheckoutOptions* instance = static_cast<ConfigurableGitCheckoutOptions*>(baton->     payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
          ConfigurableGitCheckoutOptions* ConfigurableGitCheckoutOptions::progressCb_getInstanceFromBaton(ProgressCbBaton* baton) {
           return static_cast<ConfigurableGitCheckoutOptions*>(baton->
                 payload
  );
       }

      void ConfigurableGitCheckoutOptions::progressCb_cppCallback (
          const char * path,           size_t completed_steps,           size_t total_steps,           void * payload        ) {
        ProgressCbBaton *baton =
          new ProgressCbBaton();

          baton->path = path;
          baton->completed_steps = completed_steps;
          baton->total_steps = total_steps;
          baton->payload = payload;
 
        ConfigurableGitCheckoutOptions* instance = progressCb_getInstanceFromBaton(baton);

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            delete baton;
          } else if (instance->progressCb.WillBeThrottled()) {
            delete baton;
          } else if (instance->progressCb.ShouldWaitForResult()) {
            baton->ExecuteAsync(progressCb_async, progressCb_cancelAsync);
            delete baton;
          } else {
            baton->ExecuteAsync(progressCb_async, progressCb_cancelAsync, nodegit::deleteBaton);
          }
          return;
       }

      void ConfigurableGitCheckoutOptions::progressCb_cancelAsync(void *untypedBaton) {
        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(untypedBaton);
         baton->Done();
      }

      void ConfigurableGitCheckoutOptions::progressCb_async(void *untypedBaton) {
        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(untypedBaton);
        ConfigurableGitCheckoutOptions* instance = progressCb_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->progressCb.HasCallback()) {
           baton->Done();
          return;
        }

               Napi::Value argv[3] = {
               baton->path == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->path)
 ,               // HACK: size_t needs explicit cast
              Napi::Number::New(env, (unsigned int)baton->completed_steps)
 ,               // HACK: size_t needs explicit cast
              Napi::Number::New(env, (unsigned int)baton->total_steps)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[3];
          for (int _i = 0; _i < 3; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->progressCb.GetCallback()->Call(env.Undefined(), 3, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitCheckoutOptions::progressCb_promiseCompleted)) {
          return;
        }

          baton->Done();
       }

      void ConfigurableGitCheckoutOptions::progressCb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        ProgressCbBaton* baton = static_cast<ProgressCbBaton*>(_baton);
          baton->Done();
       }
                        ConfigurableGitCheckoutOptions* ConfigurableGitCheckoutOptions::perfdataCb_getInstanceFromBaton(PerfdataCbBaton* baton) {
           return static_cast<ConfigurableGitCheckoutOptions*>(baton->
               payload
  );
       }

      void ConfigurableGitCheckoutOptions::perfdataCb_cppCallback (
          const git_checkout_perfdata * perfdata,           void * payload        ) {
        PerfdataCbBaton *baton =
          new PerfdataCbBaton();

          baton->perfdata = perfdata;
          baton->payload = payload;
 
        ConfigurableGitCheckoutOptions* instance = perfdataCb_getInstanceFromBaton(baton);

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            delete baton;
          } else if (instance->perfdataCb.WillBeThrottled()) {
            delete baton;
          } else if (instance->perfdataCb.ShouldWaitForResult()) {
            baton->ExecuteAsync(perfdataCb_async, perfdataCb_cancelAsync);
            delete baton;
          } else {
            baton->ExecuteAsync(perfdataCb_async, perfdataCb_cancelAsync, nodegit::deleteBaton);
          }
          return;
       }

      void ConfigurableGitCheckoutOptions::perfdataCb_cancelAsync(void *untypedBaton) {
        PerfdataCbBaton* baton = static_cast<PerfdataCbBaton*>(untypedBaton);
         baton->Done();
      }

      void ConfigurableGitCheckoutOptions::perfdataCb_async(void *untypedBaton) {
        PerfdataCbBaton* baton = static_cast<PerfdataCbBaton*>(untypedBaton);
        ConfigurableGitCheckoutOptions* instance = perfdataCb_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->perfdataCb.HasCallback()) {
           baton->Done();
          return;
        }

             Napi::Value argv[1] = {
               GitCheckoutPerfdata::New(env, baton->perfdata, false)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[1];
          for (int _i = 0; _i < 1; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->perfdataCb.GetCallback()->Call(env.Undefined(), 1, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitCheckoutOptions::perfdataCb_promiseCompleted)) {
          return;
        }

          baton->Done();
       }

      void ConfigurableGitCheckoutOptions::perfdataCb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        PerfdataCbBaton* baton = static_cast<PerfdataCbBaton*>(_baton);
          baton->Done();
       }
       
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitCheckoutOptionsTraits>;
