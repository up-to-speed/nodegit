// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITMERGEFILEINPUT_H
#define GITMERGEFILEINPUT_H
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

 class GitMergeFileInput;
class ConfigurableGitMergeFileInput;
 
struct GitMergeFileInputTraits {
  typedef GitMergeFileInput cppClass;
  typedef git_merge_file_input cType;
  typedef ConfigurableGitMergeFileInput configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_merge_file_input **dest, git_merge_file_input *src) {
     throw std::runtime_error("duplicate called on GitMergeFileInput which cannot be duplicated");
   }

  static std::string className() { return "GitMergeFileInput"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_merge_file_input *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitMergeFileInput : public nodegit::ConfigurableClassWrapper<GitMergeFileInputTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitMergeFileInputTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitMergeFileInput();

  ConfigurableGitMergeFileInput(const ConfigurableGitMergeFileInput &) = delete;
  ConfigurableGitMergeFileInput(ConfigurableGitMergeFileInput &&) = delete;
  ConfigurableGitMergeFileInput &operator=(const ConfigurableGitMergeFileInput &) = delete;
  ConfigurableGitMergeFileInput &operator=(ConfigurableGitMergeFileInput &&) = delete;

           
private:
  ConfigurableGitMergeFileInput(nodegit::Context *nodegitContext);
  ConfigurableGitMergeFileInput() = delete;
  Napi::Reference<Napi::Value> promiseError;

                
};

#endif
