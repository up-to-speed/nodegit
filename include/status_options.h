// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITSTATUSOPTIONS_H
#define GITSTATUSOPTIONS_H
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

  #include "../include/strarray.h"
 class GitStatusOptions;
class ConfigurableGitStatusOptions;
 
struct GitStatusOptionsTraits {
  typedef GitStatusOptions cppClass;
  typedef git_status_options cType;
  typedef ConfigurableGitStatusOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_status_options **dest, git_status_options *src) {
     throw std::runtime_error("duplicate called on GitStatusOptions which cannot be duplicated");
   }

  static std::string className() { return "GitStatusOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_status_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitStatusOptions : public nodegit::ConfigurableClassWrapper<GitStatusOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitStatusOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitStatusOptions();

  ConfigurableGitStatusOptions(const ConfigurableGitStatusOptions &) = delete;
  ConfigurableGitStatusOptions(ConfigurableGitStatusOptions &&) = delete;
  ConfigurableGitStatusOptions &operator=(const ConfigurableGitStatusOptions &) = delete;
  ConfigurableGitStatusOptions &operator=(ConfigurableGitStatusOptions &&) = delete;

         
private:
  ConfigurableGitStatusOptions(nodegit::Context *nodegitContext);
  ConfigurableGitStatusOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

            
};

#endif
