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
#include "../include/remote_callbacks.h"
#include "bungit_wrapper.cc"

  #include "../include/credential.h"
  #include "../include/cert.h"
  #include "../include/indexer_progress.h"
  #include "../include/buf.h"
 
using namespace std;

 
ConfigurableGitRemoteCallbacks::ConfigurableGitRemoteCallbacks(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitRemoteCallbacksTraits>(nodegitContext)
{
     git_remote_callbacks  wrappedValue = GIT_REMOTE_CALLBACKS_INIT;
    this->raw = (git_remote_callbacks*) malloc(sizeof(git_remote_callbacks ));
    memcpy(this->raw, &wrappedValue, sizeof(git_remote_callbacks ));
 }

ConfigurableGitRemoteCallbacks::~ConfigurableGitRemoteCallbacks() {
                   }

nodegit::ConfigurableClassWrapper<GitRemoteCallbacksTraits>::v8ConversionResult ConfigurableGitRemoteCallbacks::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitRemoteCallbacks"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitRemoteCallbacks> output(new ConfigurableGitRemoteCallbacks(nodegitContext));

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
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "sidebandProgress");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to sidebandProgress"
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

            output->sidebandProgress.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->sideband_progress = (git_transport_message_cb)sidebandProgress_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "credentials");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to credentials"
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

            output->credentials.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->credentials = (git_credential_acquire_cb)credentials_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "certificateCheck");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to certificateCheck"
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

            output->certificateCheck.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->certificate_check = (git_transport_certificate_check_cb)certificateCheck_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "transferProgress");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to transferProgress"
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

            output->transferProgress.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->transfer_progress = (git_indexer_progress_cb)transferProgress_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "pushTransferProgress");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to pushTransferProgress"
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

            output->pushTransferProgress.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->push_transfer_progress = (git_push_transfer_progress_cb)pushTransferProgress_cppCallback;
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "pushUpdateReference");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to pushUpdateReference"
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

            output->pushUpdateReference.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->push_update_reference = (git_push_update_reference_cb)pushUpdateReference_cppCallback;
          }
        }
          output->raw->payload = (void *)output.get();
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "resolveUrl");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to resolveUrl"
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

            output->resolveUrl.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->resolve_url = (git_url_resolve_cb)resolveUrl_cppCallback;
          }
        }
    
  return {
    output
  };
}

        ConfigurableGitRemoteCallbacks* ConfigurableGitRemoteCallbacks::sidebandProgress_getInstanceFromBaton(SidebandProgressBaton* baton) {
           return static_cast<ConfigurableGitRemoteCallbacks*>(baton->
                payload
  );
       }

      int ConfigurableGitRemoteCallbacks::sidebandProgress_cppCallback (
          const char * str,           int len,           void * payload        ) {
        SidebandProgressBaton *baton =
          new SidebandProgressBaton(1);

          baton->str = str;
          baton->len = len;
          baton->payload = payload;
 
        ConfigurableGitRemoteCallbacks* instance = sidebandProgress_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->sidebandProgress.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->sidebandProgress.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(sidebandProgress_async, sidebandProgress_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(sidebandProgress_async, sidebandProgress_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitRemoteCallbacks::sidebandProgress_cancelAsync(void *untypedBaton) {
        SidebandProgressBaton* baton = static_cast<SidebandProgressBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitRemoteCallbacks::sidebandProgress_async(void *untypedBaton) {
        SidebandProgressBaton* baton = static_cast<SidebandProgressBaton*>(untypedBaton);
        ConfigurableGitRemoteCallbacks* instance = sidebandProgress_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->sidebandProgress.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

              Napi::Value argv[2] = {
               baton->str == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->str)
 ,                Napi::Number::New(env, baton->len)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[2];
          for (int _i = 0; _i < 2; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->sidebandProgress.GetCallback()->Call(env.Undefined(), 2, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitRemoteCallbacks::sidebandProgress_promiseCompleted)) {
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

      void ConfigurableGitRemoteCallbacks::sidebandProgress_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        SidebandProgressBaton* baton = static_cast<SidebandProgressBaton*>(_baton);
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
               ConfigurableGitRemoteCallbacks* instance = static_cast<ConfigurableGitRemoteCallbacks*>(baton->  payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitRemoteCallbacks* ConfigurableGitRemoteCallbacks::credentials_getInstanceFromBaton(CredentialsBaton* baton) {
           return static_cast<ConfigurableGitRemoteCallbacks*>(baton->
                  payload
  );
       }

      int ConfigurableGitRemoteCallbacks::credentials_cppCallback (
          git_credential ** credential,           const char * url,           const char * username_from_url,           unsigned int allowed_types,           void * payload        ) {
        CredentialsBaton *baton =
          new CredentialsBaton(1);

          baton->credential = credential;
          baton->url = url;
          baton->username_from_url = username_from_url;
          baton->allowed_types = allowed_types;
          baton->payload = payload;
 
        ConfigurableGitRemoteCallbacks* instance = credentials_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->credentials.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->credentials.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(credentials_async, credentials_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(credentials_async, credentials_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitRemoteCallbacks::credentials_cancelAsync(void *untypedBaton) {
        CredentialsBaton* baton = static_cast<CredentialsBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitRemoteCallbacks::credentials_async(void *untypedBaton) {
        CredentialsBaton* baton = static_cast<CredentialsBaton*>(untypedBaton);
        ConfigurableGitRemoteCallbacks* instance = credentials_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->credentials.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

               Napi::Value argv[3] = {
               baton->url == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->url)
 ,               baton->username_from_url == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->username_from_url)
 ,                Napi::Number::New(env, baton->allowed_types)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[3];
          for (int _i = 0; _i < 3; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->credentials.GetCallback()->Call(env.Undefined(), 3, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitRemoteCallbacks::credentials_promiseCompleted)) {
          return;
        }

             if (result.IsUndefined() || result.IsNull()) {
              baton->result = baton->defaultResult;
            }
            else if (!result.IsNull() && !result.IsUndefined()) {
                GitCredential* wrapper = Napi::ObjectWrap<GitCredential>::Unwrap(result.As<Napi::Object>());
                wrapper->selfFreeing = false;

                   *baton->credential = wrapper->GetValue();
                 baton->result = 0;
             }
            else {
              baton->result = baton->defaultResult;
            }
           baton->Done();
       }

      void ConfigurableGitRemoteCallbacks::credentials_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        CredentialsBaton* baton = static_cast<CredentialsBaton*>(_baton);
           if (isFulfilled) {
              if (result.IsUndefined() || result.IsNull()) {
                baton->result = baton->defaultResult;
              }
              else if (!result.IsNull() && !result.IsUndefined()) {
                  GitCredential* wrapper = Napi::ObjectWrap<GitCredential>::Unwrap(result.As<Napi::Object>());
                  wrapper->selfFreeing = false;

                     *baton->credential = wrapper->GetValue();
                   baton->result = 0;
               }
              else {
                baton->result = baton->defaultResult;
              }
           }
          else {
            // promise was rejected
               ConfigurableGitRemoteCallbacks* instance = static_cast<ConfigurableGitRemoteCallbacks*>(baton->    payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitRemoteCallbacks* ConfigurableGitRemoteCallbacks::certificateCheck_getInstanceFromBaton(CertificateCheckBaton* baton) {
           return static_cast<ConfigurableGitRemoteCallbacks*>(baton->
                 payload
  );
       }

      int ConfigurableGitRemoteCallbacks::certificateCheck_cppCallback (
          git_cert * cert,           int valid,           const char * host,           void * payload        ) {
        CertificateCheckBaton *baton =
          new CertificateCheckBaton(1);

          baton->cert = cert;
          baton->valid = valid;
          baton->host = host;
          baton->payload = payload;
 
        ConfigurableGitRemoteCallbacks* instance = certificateCheck_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->certificateCheck.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->certificateCheck.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(certificateCheck_async, certificateCheck_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(certificateCheck_async, certificateCheck_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitRemoteCallbacks::certificateCheck_cancelAsync(void *untypedBaton) {
        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitRemoteCallbacks::certificateCheck_async(void *untypedBaton) {
        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(untypedBaton);
        ConfigurableGitRemoteCallbacks* instance = certificateCheck_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->certificateCheck.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

               Napi::Value argv[3] = {
               GitCert::New(env, baton->cert, false)
 ,                Napi::Number::New(env, baton->valid)
 ,               baton->host == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->host)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[3];
          for (int _i = 0; _i < 3; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->certificateCheck.GetCallback()->Call(env.Undefined(), 3, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitRemoteCallbacks::certificateCheck_promiseCompleted)) {
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

      void ConfigurableGitRemoteCallbacks::certificateCheck_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(_baton);
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
               ConfigurableGitRemoteCallbacks* instance = static_cast<ConfigurableGitRemoteCallbacks*>(baton->   payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitRemoteCallbacks* ConfigurableGitRemoteCallbacks::transferProgress_getInstanceFromBaton(TransferProgressBaton* baton) {
           return static_cast<ConfigurableGitRemoteCallbacks*>(baton->
               payload
  );
       }

      int ConfigurableGitRemoteCallbacks::transferProgress_cppCallback (
          const git_indexer_progress * stats,           void * payload        ) {
        TransferProgressBaton *baton =
          new TransferProgressBaton(0);

          baton->stats = stats;
          baton->payload = payload;
 
        ConfigurableGitRemoteCallbacks* instance = transferProgress_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->transferProgress.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->transferProgress.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(transferProgress_async, transferProgress_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(transferProgress_async, transferProgress_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitRemoteCallbacks::transferProgress_cancelAsync(void *untypedBaton) {
        TransferProgressBaton* baton = static_cast<TransferProgressBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitRemoteCallbacks::transferProgress_async(void *untypedBaton) {
        TransferProgressBaton* baton = static_cast<TransferProgressBaton*>(untypedBaton);
        ConfigurableGitRemoteCallbacks* instance = transferProgress_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->transferProgress.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

             Napi::Value argv[1] = {
               GitIndexerProgress::New(env, baton->stats, false)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[1];
          for (int _i = 0; _i < 1; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->transferProgress.GetCallback()->Call(env.Undefined(), 1, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitRemoteCallbacks::transferProgress_promiseCompleted)) {
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

      void ConfigurableGitRemoteCallbacks::transferProgress_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        TransferProgressBaton* baton = static_cast<TransferProgressBaton*>(_baton);
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
               ConfigurableGitRemoteCallbacks* instance = static_cast<ConfigurableGitRemoteCallbacks*>(baton-> payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitRemoteCallbacks* ConfigurableGitRemoteCallbacks::pushTransferProgress_getInstanceFromBaton(PushTransferProgressBaton* baton) {
           return static_cast<ConfigurableGitRemoteCallbacks*>(baton->
                 payload
  );
       }

      int ConfigurableGitRemoteCallbacks::pushTransferProgress_cppCallback (
          unsigned int current,           unsigned int total,           size_t bytes,           void * payload        ) {
        PushTransferProgressBaton *baton =
          new PushTransferProgressBaton(0);

          baton->current = current;
          baton->total = total;
          baton->bytes = bytes;
          baton->payload = payload;
 
        ConfigurableGitRemoteCallbacks* instance = pushTransferProgress_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->pushTransferProgress.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->pushTransferProgress.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(pushTransferProgress_async, pushTransferProgress_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(pushTransferProgress_async, pushTransferProgress_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitRemoteCallbacks::pushTransferProgress_cancelAsync(void *untypedBaton) {
        PushTransferProgressBaton* baton = static_cast<PushTransferProgressBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitRemoteCallbacks::pushTransferProgress_async(void *untypedBaton) {
        PushTransferProgressBaton* baton = static_cast<PushTransferProgressBaton*>(untypedBaton);
        ConfigurableGitRemoteCallbacks* instance = pushTransferProgress_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->pushTransferProgress.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

               Napi::Value argv[3] = {
                Napi::Number::New(env, baton->current)
 ,                Napi::Number::New(env, baton->total)
 ,               // HACK: size_t needs explicit cast
              Napi::Number::New(env, (unsigned int)baton->bytes)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[3];
          for (int _i = 0; _i < 3; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->pushTransferProgress.GetCallback()->Call(env.Undefined(), 3, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitRemoteCallbacks::pushTransferProgress_promiseCompleted)) {
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

      void ConfigurableGitRemoteCallbacks::pushTransferProgress_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        PushTransferProgressBaton* baton = static_cast<PushTransferProgressBaton*>(_baton);
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
               ConfigurableGitRemoteCallbacks* instance = static_cast<ConfigurableGitRemoteCallbacks*>(baton->   payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitRemoteCallbacks* ConfigurableGitRemoteCallbacks::pushUpdateReference_getInstanceFromBaton(PushUpdateReferenceBaton* baton) {
           return static_cast<ConfigurableGitRemoteCallbacks*>(baton->
                data
  );
       }

      int ConfigurableGitRemoteCallbacks::pushUpdateReference_cppCallback (
          const char * refname,           const char * status,           void * data        ) {
        PushUpdateReferenceBaton *baton =
          new PushUpdateReferenceBaton(1);

          baton->refname = refname;
          baton->status = status;
          baton->data = data;
 
        ConfigurableGitRemoteCallbacks* instance = pushUpdateReference_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->pushUpdateReference.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->pushUpdateReference.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(pushUpdateReference_async, pushUpdateReference_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(pushUpdateReference_async, pushUpdateReference_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitRemoteCallbacks::pushUpdateReference_cancelAsync(void *untypedBaton) {
        PushUpdateReferenceBaton* baton = static_cast<PushUpdateReferenceBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitRemoteCallbacks::pushUpdateReference_async(void *untypedBaton) {
        PushUpdateReferenceBaton* baton = static_cast<PushUpdateReferenceBaton*>(untypedBaton);
        ConfigurableGitRemoteCallbacks* instance = pushUpdateReference_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->pushUpdateReference.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

              Napi::Value argv[3] = {
               baton->refname == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->refname)
 ,               baton->status == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->status)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[3];
          for (int _i = 0; _i < 3; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->pushUpdateReference.GetCallback()->Call(env.Undefined(), 3, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitRemoteCallbacks::pushUpdateReference_promiseCompleted)) {
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

      void ConfigurableGitRemoteCallbacks::pushUpdateReference_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        PushUpdateReferenceBaton* baton = static_cast<PushUpdateReferenceBaton*>(_baton);
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
               ConfigurableGitRemoteCallbacks* instance = static_cast<ConfigurableGitRemoteCallbacks*>(baton->  data  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
          ConfigurableGitRemoteCallbacks* ConfigurableGitRemoteCallbacks::resolveUrl_getInstanceFromBaton(ResolveUrlBaton* baton) {
           return static_cast<ConfigurableGitRemoteCallbacks*>(baton->
                 payload
  );
       }

      int ConfigurableGitRemoteCallbacks::resolveUrl_cppCallback (
          git_buf * url_resolved,           const char * url,           int direction,           void * payload        ) {
        ResolveUrlBaton *baton =
          new ResolveUrlBaton(-30);

          baton->url_resolved = url_resolved;
          baton->url = url;
          baton->direction = direction;
          baton->payload = payload;
 
        ConfigurableGitRemoteCallbacks* instance = resolveUrl_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->resolveUrl.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->resolveUrl.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(resolveUrl_async, resolveUrl_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(resolveUrl_async, resolveUrl_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitRemoteCallbacks::resolveUrl_cancelAsync(void *untypedBaton) {
        ResolveUrlBaton* baton = static_cast<ResolveUrlBaton*>(untypedBaton);
          baton->result = -30;
         baton->Done();
      }

      void ConfigurableGitRemoteCallbacks::resolveUrl_async(void *untypedBaton) {
        ResolveUrlBaton* baton = static_cast<ResolveUrlBaton*>(untypedBaton);
        ConfigurableGitRemoteCallbacks* instance = resolveUrl_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->resolveUrl.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

               Napi::Value argv[3] = {
               GitBuf::New(env, baton->url_resolved, false)
 ,               baton->url == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->url)
 ,                Napi::Number::New(env, baton->direction)
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[3];
          for (int _i = 0; _i < 3; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->resolveUrl.GetCallback()->Call(env.Undefined(), 3, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitRemoteCallbacks::resolveUrl_promiseCompleted)) {
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

      void ConfigurableGitRemoteCallbacks::resolveUrl_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        ResolveUrlBaton* baton = static_cast<ResolveUrlBaton*>(_baton);
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
               ConfigurableGitRemoteCallbacks* instance = static_cast<ConfigurableGitRemoteCallbacks*>(baton->   payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
   
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitRemoteCallbacksTraits>;
