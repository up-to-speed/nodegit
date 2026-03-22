// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITBLOBFILTEROPTIONS_H
#define GITBLOBFILTEROPTIONS_H
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

 class GitBlobFilterOptions;
class ConfigurableGitBlobFilterOptions;
 
struct GitBlobFilterOptionsTraits {
  typedef GitBlobFilterOptions cppClass;
  typedef git_blob_filter_options cType;
  typedef ConfigurableGitBlobFilterOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_blob_filter_options **dest, git_blob_filter_options *src) {
     throw std::runtime_error("duplicate called on GitBlobFilterOptions which cannot be duplicated");
   }

  static std::string className() { return "GitBlobFilterOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_blob_filter_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitBlobFilterOptions : public nodegit::ConfigurableClassWrapper<GitBlobFilterOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitBlobFilterOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitBlobFilterOptions();

  ConfigurableGitBlobFilterOptions(const ConfigurableGitBlobFilterOptions &) = delete;
  ConfigurableGitBlobFilterOptions(ConfigurableGitBlobFilterOptions &&) = delete;
  ConfigurableGitBlobFilterOptions &operator=(const ConfigurableGitBlobFilterOptions &) = delete;
  ConfigurableGitBlobFilterOptions &operator=(ConfigurableGitBlobFilterOptions &&) = delete;

     
private:
  ConfigurableGitBlobFilterOptions(nodegit::Context *nodegitContext);
  ConfigurableGitBlobFilterOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

       
};

#endif
