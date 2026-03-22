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
    #include <git2/sys/filter.h>
 }

#include <iostream>
#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/filter.h"
#include "bungit_wrapper.cc"

  #include "../include/filter_source.h"
  #include "../include/buf.h"
 
using namespace std;

 
ConfigurableGitFilter::ConfigurableGitFilter(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitFilterTraits>(nodegitContext)
{
     git_filter_extended  wrappedValue = GIT_FILTER_INIT;
    this->raw = (git_filter*) malloc(sizeof(git_filter_extended ));
    memcpy(this->raw, &wrappedValue, sizeof(git_filter_extended ));
 }

ConfigurableGitFilter::~ConfigurableGitFilter() {
          free((void*)this->raw->attributes);
           }

nodegit::ConfigurableClassWrapper<GitFilterTraits>::v8ConversionResult ConfigurableGitFilter::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitFilter"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitFilter> output(new ConfigurableGitFilter(nodegitContext));

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
          output->raw->attributes = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "attributes");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to attributes"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->attributes = strdup(utf8String.c_str());
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "initialize");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to initialize"
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

            output->initialize.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->initialize = (git_filter_init_fn)initialize_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "shutdown");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to shutdown"
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

            output->shutdown.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->shutdown = (git_filter_shutdown_fn)shutdown_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "check");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to check"
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

            output->check.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->check = (git_filter_check_fn)check_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "apply");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to apply"
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

            output->apply.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->apply = (git_filter_apply_fn)apply_cppCallback;
          }
        }
       ((git_filter_extended *)output->raw)->payload = (void *)output.get();
 
  return {
    output
  };
}

          ConfigurableGitFilter* ConfigurableGitFilter::initialize_getInstanceFromBaton(InitializeBaton* baton) {
          return static_cast<ConfigurableGitFilter*>(((git_filter_extended *)baton->self)->payload);
       }

      int ConfigurableGitFilter::initialize_cppCallback (
          git_filter * self        ) {
        InitializeBaton *baton =
          new InitializeBaton(0);

          baton->self = self;
 
        ConfigurableGitFilter* instance = initialize_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->initialize.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->initialize.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(initialize_async, initialize_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(initialize_async, initialize_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitFilter::initialize_cancelAsync(void *untypedBaton) {
        InitializeBaton* baton = static_cast<InitializeBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitFilter::initialize_async(void *untypedBaton) {
        InitializeBaton* baton = static_cast<InitializeBaton*>(untypedBaton);
        ConfigurableGitFilter* instance = initialize_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->initialize.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

           Napi::Value *argv = NULL;
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
          result = instance->initialize.GetCallback()->Call({});
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitFilter::initialize_promiseCompleted)) {
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

      void ConfigurableGitFilter::initialize_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        InitializeBaton* baton = static_cast<InitializeBaton*>(_baton);
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
              ConfigurableGitFilter* instance = static_cast<ConfigurableGitFilter*>(((git_filter_extended *)baton->self)->payload);
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitFilter* ConfigurableGitFilter::shutdown_getInstanceFromBaton(ShutdownBaton* baton) {
          return static_cast<ConfigurableGitFilter*>(((git_filter_extended *)baton->self)->payload);
       }

      void ConfigurableGitFilter::shutdown_cppCallback (
          git_filter * self        ) {
        ShutdownBaton *baton =
          new ShutdownBaton();

          baton->self = self;
 
        ConfigurableGitFilter* instance = shutdown_getInstanceFromBaton(baton);

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            delete baton;
          } else if (instance->shutdown.WillBeThrottled()) {
            delete baton;
          } else if (instance->shutdown.ShouldWaitForResult()) {
            baton->ExecuteAsync(shutdown_async, shutdown_cancelAsync);
            delete baton;
          } else {
            baton->ExecuteAsync(shutdown_async, shutdown_cancelAsync, nodegit::deleteBaton);
          }
          return;
       }

      void ConfigurableGitFilter::shutdown_cancelAsync(void *untypedBaton) {
        ShutdownBaton* baton = static_cast<ShutdownBaton*>(untypedBaton);
         baton->Done();
      }

      void ConfigurableGitFilter::shutdown_async(void *untypedBaton) {
        ShutdownBaton* baton = static_cast<ShutdownBaton*>(untypedBaton);
        ConfigurableGitFilter* instance = shutdown_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->shutdown.HasCallback()) {
           baton->Done();
          return;
        }

           Napi::Value *argv = NULL;
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
          result = instance->shutdown.GetCallback()->Call({});
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitFilter::shutdown_promiseCompleted)) {
          return;
        }

          baton->Done();
       }

      void ConfigurableGitFilter::shutdown_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        ShutdownBaton* baton = static_cast<ShutdownBaton*>(_baton);
          baton->Done();
       }
        ConfigurableGitFilter* ConfigurableGitFilter::check_getInstanceFromBaton(CheckBaton* baton) {
          return static_cast<ConfigurableGitFilter*>(((git_filter_extended *)baton->self)->payload);
       }

      int ConfigurableGitFilter::check_cppCallback (
          git_filter * self,           void ** payload,           const git_filter_source * src,           const char ** attr_values        ) {
        CheckBaton *baton =
          new CheckBaton(-30);

          baton->self = self;
          baton->payload = payload;
          baton->src = src;
          baton->attr_values = attr_values;
 
        ConfigurableGitFilter* instance = check_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->check.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->check.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(check_async, check_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(check_async, check_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitFilter::check_cancelAsync(void *untypedBaton) {
        CheckBaton* baton = static_cast<CheckBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitFilter::check_async(void *untypedBaton) {
        CheckBaton* baton = static_cast<CheckBaton*>(untypedBaton);
        ConfigurableGitFilter* instance = check_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->check.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

              Napi::Value argv[2] = {
               GitFilterSource::New(env, baton->src, false)
 ,               baton->attr_values == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env, * baton->attr_values)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[2];
          for (int _i = 0; _i < 2; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->check.GetCallback()->Call(env.Undefined(), 2, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitFilter::check_promiseCompleted)) {
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

      void ConfigurableGitFilter::check_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        CheckBaton* baton = static_cast<CheckBaton*>(_baton);
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
              ConfigurableGitFilter* instance = static_cast<ConfigurableGitFilter*>(((git_filter_extended *)baton->self)->payload);
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitFilter* ConfigurableGitFilter::apply_getInstanceFromBaton(ApplyBaton* baton) {
          return static_cast<ConfigurableGitFilter*>(((git_filter_extended *)baton->self)->payload);
       }

      int ConfigurableGitFilter::apply_cppCallback (
          git_filter * self,           void ** payload,           git_buf * to,           const git_buf * from,           const git_filter_source * src        ) {
        ApplyBaton *baton =
          new ApplyBaton(-30);

          baton->self = self;
          baton->payload = payload;
          baton->to = to;
          baton->from = from;
          baton->src = src;
 
        ConfigurableGitFilter* instance = apply_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->apply.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->apply.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(apply_async, apply_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(apply_async, apply_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitFilter::apply_cancelAsync(void *untypedBaton) {
        ApplyBaton* baton = static_cast<ApplyBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitFilter::apply_async(void *untypedBaton) {
        ApplyBaton* baton = static_cast<ApplyBaton*>(untypedBaton);
        ConfigurableGitFilter* instance = apply_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->apply.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

               Napi::Value argv[3] = {
               GitBuf::New(env, baton->to, false)
 ,               GitBuf::New(env, baton->from, false)
 ,               GitFilterSource::New(env, baton->src, false)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[3];
          for (int _i = 0; _i < 3; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->apply.GetCallback()->Call(env.Undefined(), 3, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitFilter::apply_promiseCompleted)) {
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

      void ConfigurableGitFilter::apply_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        ApplyBaton* baton = static_cast<ApplyBaton*>(_baton);
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
              ConfigurableGitFilter* instance = static_cast<ConfigurableGitFilter*>(((git_filter_extended *)baton->self)->payload);
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
   
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitFilterTraits>;
