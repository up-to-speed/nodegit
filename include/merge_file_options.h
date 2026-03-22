// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITMERGEFILEOPTIONS_H
#define GITMERGEFILEOPTIONS_H
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

 class GitMergeFileOptions;
class ConfigurableGitMergeFileOptions;
 
struct GitMergeFileOptionsTraits {
  typedef GitMergeFileOptions cppClass;
  typedef git_merge_file_options cType;
  typedef ConfigurableGitMergeFileOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_merge_file_options **dest, git_merge_file_options *src) {
     throw std::runtime_error("duplicate called on GitMergeFileOptions which cannot be duplicated");
   }

  static std::string className() { return "GitMergeFileOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_merge_file_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitMergeFileOptions : public nodegit::ConfigurableClassWrapper<GitMergeFileOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitMergeFileOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitMergeFileOptions();

  ConfigurableGitMergeFileOptions(const ConfigurableGitMergeFileOptions &) = delete;
  ConfigurableGitMergeFileOptions(ConfigurableGitMergeFileOptions &&) = delete;
  ConfigurableGitMergeFileOptions &operator=(const ConfigurableGitMergeFileOptions &) = delete;
  ConfigurableGitMergeFileOptions &operator=(ConfigurableGitMergeFileOptions &&) = delete;

               
private:
  ConfigurableGitMergeFileOptions(nodegit::Context *nodegitContext);
  ConfigurableGitMergeFileOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                     
};

#endif
