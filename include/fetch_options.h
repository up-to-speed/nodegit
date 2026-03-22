// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITFETCHOPTIONS_H
#define GITFETCHOPTIONS_H
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

  #include "../include/str_array_converter.h"
  #include "../include/remote_callbacks.h"
  #include "../include/proxy_options.h"
  #include "../include/strarray.h"
 class GitFetchOptions;
class ConfigurableGitFetchOptions;
 
struct GitFetchOptionsTraits {
  typedef GitFetchOptions cppClass;
  typedef git_fetch_options cType;
  typedef ConfigurableGitFetchOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_fetch_options **dest, git_fetch_options *src) {
     throw std::runtime_error("duplicate called on GitFetchOptions which cannot be duplicated");
   }

  static std::string className() { return "GitFetchOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_fetch_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitFetchOptions : public nodegit::ConfigurableClassWrapper<GitFetchOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitFetchOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitFetchOptions();

  ConfigurableGitFetchOptions(const ConfigurableGitFetchOptions &) = delete;
  ConfigurableGitFetchOptions(ConfigurableGitFetchOptions &&) = delete;
  ConfigurableGitFetchOptions &operator=(const ConfigurableGitFetchOptions &) = delete;
  ConfigurableGitFetchOptions &operator=(ConfigurableGitFetchOptions &&) = delete;

               
private:
  ConfigurableGitFetchOptions(nodegit::Context *nodegitContext);
  ConfigurableGitFetchOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                     
};

#endif
