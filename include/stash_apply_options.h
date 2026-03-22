// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITSTASHAPPLYOPTIONS_H
#define GITSTASHAPPLYOPTIONS_H
#include <napi.h>
#include <string>
#include <utility>

#include "async_baton.h"
#include "async_worker.h"
#include "callback_wrapper.h"
#include "context.h"
#include "reference_counter.h"
#include "bungit_wrapper.h"
#include "configurable_class_wrapper.h"
#include "v8_helpers.h"

extern "C" {
  #include <git2.h>
  #include <git2/sys/errors.h>
 }

  #include "../include/checkout_options.h"
 class GitStashApplyOptions;
class ConfigurableGitStashApplyOptions;
 
struct GitStashApplyOptionsTraits {
  typedef GitStashApplyOptions cppClass;
  typedef git_stash_apply_options cType;
  typedef ConfigurableGitStashApplyOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_stash_apply_options **dest, git_stash_apply_options *src) {
     throw std::runtime_error("duplicate called on GitStashApplyOptions which cannot be duplicated");
   }

  static std::string className() { return "GitStashApplyOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_stash_apply_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitStashApplyOptions : public nodegit::ConfigurableClassWrapper<GitStashApplyOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitStashApplyOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitStashApplyOptions();

  ConfigurableGitStashApplyOptions(const ConfigurableGitStashApplyOptions &) = delete;
  ConfigurableGitStashApplyOptions(ConfigurableGitStashApplyOptions &&) = delete;
  ConfigurableGitStashApplyOptions &operator=(const ConfigurableGitStashApplyOptions &) = delete;
  ConfigurableGitStashApplyOptions &operator=(ConfigurableGitStashApplyOptions &&) = delete;

              static int progressCb_cppCallback (
            git_stash_apply_progress_t progress
              ,
             void * payload
          );

        static void progressCb_cancelAsync(void *baton);
        static void progressCb_async(void *baton);
        static void progressCb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
           class ProgressCbBaton : public nodegit::AsyncBatonWithResult<int> {
          public:
              git_stash_apply_progress_t progress;
              void * payload;
 
            ProgressCbBaton(const int &defaultResult)
              : nodegit::AsyncBatonWithResult<int>(defaultResult) {
              }
          };
         static ConfigurableGitStashApplyOptions * progressCb_getInstanceFromBaton (
          ProgressCbBaton *baton);
     
private:
  ConfigurableGitStashApplyOptions(nodegit::Context *nodegitContext);
  ConfigurableGitStashApplyOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                   CallbackWrapper progressCb;
       
};

#endif
