// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITTREEUPDATE_H
#define GITTREEUPDATE_H
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

  #include "../include/oid.h"
 class GitTreeUpdate;
class ConfigurableGitTreeUpdate;
 
struct GitTreeUpdateTraits {
  typedef GitTreeUpdate cppClass;
  typedef git_tree_update cType;
  typedef ConfigurableGitTreeUpdate configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_tree_update **dest, git_tree_update *src) {
     throw std::runtime_error("duplicate called on GitTreeUpdate which cannot be duplicated");
   }

  static std::string className() { return "GitTreeUpdate"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_tree_update *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitTreeUpdate : public nodegit::ConfigurableClassWrapper<GitTreeUpdateTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitTreeUpdateTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitTreeUpdate();

  ConfigurableGitTreeUpdate(const ConfigurableGitTreeUpdate &) = delete;
  ConfigurableGitTreeUpdate(ConfigurableGitTreeUpdate &&) = delete;
  ConfigurableGitTreeUpdate &operator=(const ConfigurableGitTreeUpdate &) = delete;
  ConfigurableGitTreeUpdate &operator=(ConfigurableGitTreeUpdate &&) = delete;

         
private:
  ConfigurableGitTreeUpdate(nodegit::Context *nodegitContext);
  ConfigurableGitTreeUpdate() = delete;
  Napi::Reference<Napi::Value> promiseError;

            
};

#endif
