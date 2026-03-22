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
#include "../include/rebase_options.h"
#include "bungit_wrapper.cc"

  #include "../include/merge_options.h"
  #include "../include/checkout_options.h"
  #include "../include/oid.h"
  #include "../include/signature.h"
  #include "../include/tree.h"
 
using namespace std;

 
ConfigurableGitRebaseOptions::ConfigurableGitRebaseOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitRebaseOptionsTraits>(nodegitContext)
{
     git_rebase_options  wrappedValue = GIT_REBASE_OPTIONS_INIT;
    this->raw = (git_rebase_options*) malloc(sizeof(git_rebase_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_rebase_options ));
 }

ConfigurableGitRebaseOptions::~ConfigurableGitRebaseOptions() {
              free((void*)this->raw->rewrite_notes_ref);
           }

nodegit::ConfigurableClassWrapper<GitRebaseOptionsTraits>::v8ConversionResult ConfigurableGitRebaseOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitRebaseOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitRebaseOptions> output(new ConfigurableGitRebaseOptions(nodegitContext));

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
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "quiet");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to quiet"
              };
            }

            output->raw->quiet = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "inmemory");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to inmemory"
              };
            }

            output->raw->inmemory = static_cast<int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          output->raw->rewrite_notes_ref = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "rewriteNotesRef");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to rewriteNotesRef"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->rewrite_notes_ref = strdup(utf8String.c_str());
          }
        }
          {
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "mergeOptions");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitMergeOptions::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set mergeOptions: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->merge_options = *child->GetValue();
          }
        }
          {
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "checkoutOptions");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitCheckoutOptions::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set checkoutOptions: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->checkout_options = *child->GetValue();
          }
        }
          {
          Napi::Value maybeCallback = nodegit::safeGetField(inputObj, "commitCreateCb");
          if (!maybeCallback.IsUndefined() && !maybeCallback.IsNull()) {
            if (!maybeCallback.IsFunction() && !maybeCallback.IsObject()) {
              return {
                "Must pass Function or CallbackSpecifier to commitCreateCb"
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

            output->commitCreateCb.SetCallback(std::move(callback), throttle, waitForResult);
            output->raw->commit_create_cb = (git_commit_create_cb)commitCreateCb_cppCallback;
          }
        }
          output->raw->payload = (void *)output.get();
    
  return {
    output
  };
}

                  ConfigurableGitRebaseOptions* ConfigurableGitRebaseOptions::commitCreateCb_getInstanceFromBaton(CommitCreateCbBaton* baton) {
           return static_cast<ConfigurableGitRebaseOptions*>(baton->
                      payload
  );
       }

      int ConfigurableGitRebaseOptions::commitCreateCb_cppCallback (
          git_oid * out,           const git_signature * author,           const git_signature * committer,           const char * message_encoding,           const char * message,           const git_tree * tree,           size_t parent_count,           const git_oid ** parents,           void * payload        ) {
        CommitCreateCbBaton *baton =
          new CommitCreateCbBaton(-30);

          baton->out = out;
          baton->author = author;
          baton->committer = committer;
          baton->message_encoding = message_encoding;
          baton->message = message;
          baton->tree = tree;
          baton->parent_count = parent_count;
          baton->parents = parents;
          baton->payload = payload;
 
        ConfigurableGitRebaseOptions* instance = commitCreateCb_getInstanceFromBaton(baton);

           int result;

          if (instance->nodegitContext != nodegit::ThreadPool::GetCurrentContext()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->commitCreateCb.WillBeThrottled()) {
            result = baton->defaultResult;
            delete baton;
          } else if (instance->commitCreateCb.ShouldWaitForResult()) {
            result = baton->ExecuteAsync(commitCreateCb_async, commitCreateCb_cancelAsync);
            delete baton;
          } else {
            result = baton->defaultResult;
            baton->ExecuteAsync(commitCreateCb_async, commitCreateCb_cancelAsync, nodegit::deleteBaton);
          }
          return result;
       }

      void ConfigurableGitRebaseOptions::commitCreateCb_cancelAsync(void *untypedBaton) {
        CommitCreateCbBaton* baton = static_cast<CommitCreateCbBaton*>(untypedBaton);
          baton->result = -1;
         baton->Done();
      }

      void ConfigurableGitRebaseOptions::commitCreateCb_async(void *untypedBaton) {
        CommitCreateCbBaton* baton = static_cast<CommitCreateCbBaton*>(untypedBaton);
        ConfigurableGitRebaseOptions* instance = commitCreateCb_getInstanceFromBaton(baton);

        Napi::Env env = instance->nodegitContext->GetEnv();
        Napi::HandleScope scope(env);

        if (!instance->commitCreateCb.HasCallback()) {
            baton->result = baton->defaultResult; // no results acquired
           baton->Done();
          return;
        }

                Napi::Array _parents_array = Napi::Array::New(env, baton->parent_count);
          for(uint32_t i = 0; i < _parents_array.Length(); i++) {
            _parents_array.Set(i, GitOid::New(env, baton->parents[i], false));
          }
             Napi::Value argv[7] = {
               GitSignature::New(env, baton->author, false)
 ,               GitSignature::New(env, baton->committer, false)
 ,               baton->message_encoding == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->message_encoding)
 ,               baton->message == NULL
                ? Napi::String::New(env, "")
                : Napi::String::New(env,  baton->message)
 ,               GitTree::New(env, baton->tree, false)
 ,               // HACK: size_t needs explicit cast
              Napi::Number::New(env, (unsigned int)baton->parent_count)
 ,               _parents_array
            };
 
        Napi::Value result;
        bool callSucceeded = false;
        try {
           napi_value napi_argv[7];
          for (int _i = 0; _i < 7; _i++) {
            napi_argv[_i] = argv[_i];
          }
          result = instance->commitCreateCb.GetCallback()->Call(env.Undefined(), 7, napi_argv);
           callSucceeded = !result.IsEmpty();
        } catch (const Napi::Error& e) {
          // exception occurred — result is invalid, don't forward
        }

        if (callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, ConfigurableGitRebaseOptions::commitCreateCb_promiseCompleted)) {
          return;
        }

             if (result.IsUndefined() || result.IsNull()) {
              baton->result = baton->defaultResult;
            }
            else if (!result.IsNull() && !result.IsUndefined()) {
                GitOid* wrapper = Napi::ObjectWrap<GitOid>::Unwrap(result.As<Napi::Object>());
                wrapper->selfFreeing = false;

                  git_oid_cpy(baton->out, wrapper->GetValue());
                 baton->result = 0;
             }
            else {
              baton->result = baton->defaultResult;
            }
           baton->Done();
       }

      void ConfigurableGitRebaseOptions::commitCreateCb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
        Napi::Env env = result.Env();
        Napi::HandleScope scope(env);

        CommitCreateCbBaton* baton = static_cast<CommitCreateCbBaton*>(_baton);
           if (isFulfilled) {
              if (result.IsUndefined() || result.IsNull()) {
                baton->result = baton->defaultResult;
              }
              else if (!result.IsNull() && !result.IsUndefined()) {
                  GitOid* wrapper = Napi::ObjectWrap<GitOid>::Unwrap(result.As<Napi::Object>());
                  wrapper->selfFreeing = false;

                    git_oid_cpy(baton->out, wrapper->GetValue());
                   baton->result = 0;
               }
              else {
                baton->result = baton->defaultResult;
              }
           }
          else {
            // promise was rejected
               ConfigurableGitRebaseOptions* instance = static_cast<ConfigurableGitRebaseOptions*>(baton->        payload  );
             baton->SetCallbackError(result);
            baton->result = -1;
          }
          baton->Done();
       }
     
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitRebaseOptionsTraits>;
