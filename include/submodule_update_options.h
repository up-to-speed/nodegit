// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITSUBMODULEUPDATEOPTIONS_H
#define GITSUBMODULEUPDATEOPTIONS_H
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
  #include "../include/fetch_options.h"
 class GitSubmoduleUpdateOptions;
class ConfigurableGitSubmoduleUpdateOptions;
 
struct GitSubmoduleUpdateOptionsTraits {
  typedef GitSubmoduleUpdateOptions cppClass;
  typedef git_submodule_update_options cType;
  typedef ConfigurableGitSubmoduleUpdateOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_submodule_update_options **dest, git_submodule_update_options *src) {
     throw std::runtime_error("duplicate called on GitSubmoduleUpdateOptions which cannot be duplicated");
   }

  static std::string className() { return "GitSubmoduleUpdateOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_submodule_update_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitSubmoduleUpdateOptions : public nodegit::ConfigurableClassWrapper<GitSubmoduleUpdateOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitSubmoduleUpdateOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitSubmoduleUpdateOptions();

  ConfigurableGitSubmoduleUpdateOptions(const ConfigurableGitSubmoduleUpdateOptions &) = delete;
  ConfigurableGitSubmoduleUpdateOptions(ConfigurableGitSubmoduleUpdateOptions &&) = delete;
  ConfigurableGitSubmoduleUpdateOptions &operator=(const ConfigurableGitSubmoduleUpdateOptions &) = delete;
  ConfigurableGitSubmoduleUpdateOptions &operator=(ConfigurableGitSubmoduleUpdateOptions &&) = delete;

         
private:
  ConfigurableGitSubmoduleUpdateOptions(nodegit::Context *nodegitContext);
  ConfigurableGitSubmoduleUpdateOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

             
};

#endif
