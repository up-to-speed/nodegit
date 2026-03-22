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
#include "../include/proxy_options.h"
#include "bungit_wrapper.cc"

  #include "../include/credential.h"
  #include "../include/cert.h"
 
using namespace std;

 
ConfigurableGitProxyOptions::ConfigurableGitProxyOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitProxyOptionsTraits>(nodegitContext)
{
     git_proxy_options  wrappedValue = GIT_PROXY_OPTIONS_INIT;
    this->raw = (git_proxy_options*) malloc(sizeof(git_proxy_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_proxy_options ));
 }

ConfigurableGitProxyOptions::~ConfigurableGitProxyOptions() {
            free((void*)this->raw->url);
         }

nodegit::ConfigurableClassWrapper<GitProxyOptionsTraits>::v8ConversionResult ConfigurableGitProxyOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitProxyOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitProxyOptions> output(new ConfigurableGitProxyOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "type");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to type"
              };
            }

            output->raw->type = static_cast<git_proxy_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          output->raw->url = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "url");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to url"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->url = strdup(utf8String.c_str());
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
          output->raw->payload = (void *)output.get();
    
  return {
    output
  };
}

            ConfigurableGitProxyOptions* ConfigurableGitProxyOptions::credentials_getInstanceFromBaton(CredentialsBaton* baton) {
           return static_cast<ConfigurableGitProxyOptions*>(baton->
                  payload
  );
       }

      int ConfigurableGitProxyOptions::credentials_cppCallback (
          git_credential ** credential,           const char * url,           const char * username_from_url,           unsigned int allowed_types,           void * payload        ) {
        CredentialsBaton *baton =
          new CredentialsBaton(1);

          baton->credential = credential;
          baton->url = url;
          baton->username_from_url = username_from_url;
          baton->allowed_types = allowed_types;
          baton->payload = payload;
 
        ConfigurableGitProxyOptions* instance = credentials_getInstanceFromBaton(baton);

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

      void ConfigurableGitProxyOptions::credentials_cancelAsync(void *untypedBaton) {
        CredentialsBaton* baton = static_cast<CredentialsBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitProxyOptions::credentials_async(void *untypedBaton) {
        CredentialsBaton* baton = static_cast<CredentialsBaton*>(untypedBaton);
        ConfigurableGitProxyOptions* instance = credentials_getInstanceFromBaton(baton);

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

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitProxyOptions::credentials_promiseCompleted)) {
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

      void ConfigurableGitProxyOptions::credentials_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
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
               ConfigurableGitProxyOptions* instance = static_cast<ConfigurableGitProxyOptions*>(baton->    payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
        ConfigurableGitProxyOptions* ConfigurableGitProxyOptions::certificateCheck_getInstanceFromBaton(CertificateCheckBaton* baton) {
           return static_cast<ConfigurableGitProxyOptions*>(baton->
                 payload
  );
       }

      int ConfigurableGitProxyOptions::certificateCheck_cppCallback (
          git_cert * cert,           int valid,           const char * host,           void * payload        ) {
        CertificateCheckBaton *baton =
          new CertificateCheckBaton(1);

          baton->cert = cert;
          baton->valid = valid;
          baton->host = host;
          baton->payload = payload;
 
        ConfigurableGitProxyOptions* instance = certificateCheck_getInstanceFromBaton(baton);

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

      void ConfigurableGitProxyOptions::certificateCheck_cancelAsync(void *untypedBaton) {
        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitProxyOptions::certificateCheck_async(void *untypedBaton) {
        CertificateCheckBaton* baton = static_cast<CertificateCheckBaton*>(untypedBaton);
        ConfigurableGitProxyOptions* instance = certificateCheck_getInstanceFromBaton(baton);

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

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitProxyOptions::certificateCheck_promiseCompleted)) {
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

      void ConfigurableGitProxyOptions::certificateCheck_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
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
               ConfigurableGitProxyOptions* instance = static_cast<ConfigurableGitProxyOptions*>(baton->   payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
     
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitProxyOptionsTraits>;
