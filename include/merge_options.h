// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITMERGEOPTIONS_H
#define GITMERGEOPTIONS_H
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

 class GitMergeOptions;
class ConfigurableGitMergeOptions;
 
struct GitMergeOptionsTraits {
  typedef GitMergeOptions cppClass;
  typedef git_merge_options cType;
  typedef ConfigurableGitMergeOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_merge_options **dest, git_merge_options *src) {
     throw std::runtime_error("duplicate called on GitMergeOptions which cannot be duplicated");
   }

  static std::string className() { return "GitMergeOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_merge_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitMergeOptions : public nodegit::ConfigurableClassWrapper<GitMergeOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitMergeOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitMergeOptions();

  ConfigurableGitMergeOptions(const ConfigurableGitMergeOptions &) = delete;
  ConfigurableGitMergeOptions(ConfigurableGitMergeOptions &&) = delete;
  ConfigurableGitMergeOptions &operator=(const ConfigurableGitMergeOptions &) = delete;
  ConfigurableGitMergeOptions &operator=(ConfigurableGitMergeOptions &&) = delete;

                 
private:
  ConfigurableGitMergeOptions(nodegit::Context *nodegitContext);
  ConfigurableGitMergeOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                        
};

#endif
