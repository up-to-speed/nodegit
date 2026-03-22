// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITREPOSITORYINITOPTIONS_H
#define GITREPOSITORYINITOPTIONS_H
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

 class GitRepositoryInitOptions;
class ConfigurableGitRepositoryInitOptions;
 
struct GitRepositoryInitOptionsTraits {
  typedef GitRepositoryInitOptions cppClass;
  typedef git_repository_init_options cType;
  typedef ConfigurableGitRepositoryInitOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_repository_init_options **dest, git_repository_init_options *src) {
     throw std::runtime_error("duplicate called on GitRepositoryInitOptions which cannot be duplicated");
   }

  static std::string className() { return "GitRepositoryInitOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_repository_init_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitRepositoryInitOptions : public nodegit::ConfigurableClassWrapper<GitRepositoryInitOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitRepositoryInitOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitRepositoryInitOptions();

  ConfigurableGitRepositoryInitOptions(const ConfigurableGitRepositoryInitOptions &) = delete;
  ConfigurableGitRepositoryInitOptions(ConfigurableGitRepositoryInitOptions &&) = delete;
  ConfigurableGitRepositoryInitOptions &operator=(const ConfigurableGitRepositoryInitOptions &) = delete;
  ConfigurableGitRepositoryInitOptions &operator=(ConfigurableGitRepositoryInitOptions &&) = delete;

                 
private:
  ConfigurableGitRepositoryInitOptions(nodegit::Context *nodegitContext);
  ConfigurableGitRepositoryInitOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                         
};

#endif
