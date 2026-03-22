// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITWORKTREEPRUNEOPTIONS_H
#define GITWORKTREEPRUNEOPTIONS_H
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

 class GitWorktreePruneOptions;
class ConfigurableGitWorktreePruneOptions;
 
struct GitWorktreePruneOptionsTraits {
  typedef GitWorktreePruneOptions cppClass;
  typedef git_worktree_prune_options cType;
  typedef ConfigurableGitWorktreePruneOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_worktree_prune_options **dest, git_worktree_prune_options *src) {
     throw std::runtime_error("duplicate called on GitWorktreePruneOptions which cannot be duplicated");
   }

  static std::string className() { return "GitWorktreePruneOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_worktree_prune_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitWorktreePruneOptions : public nodegit::ConfigurableClassWrapper<GitWorktreePruneOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitWorktreePruneOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitWorktreePruneOptions();

  ConfigurableGitWorktreePruneOptions(const ConfigurableGitWorktreePruneOptions &) = delete;
  ConfigurableGitWorktreePruneOptions(ConfigurableGitWorktreePruneOptions &&) = delete;
  ConfigurableGitWorktreePruneOptions &operator=(const ConfigurableGitWorktreePruneOptions &) = delete;
  ConfigurableGitWorktreePruneOptions &operator=(ConfigurableGitWorktreePruneOptions &&) = delete;

     
private:
  ConfigurableGitWorktreePruneOptions(nodegit::Context *nodegitContext);
  ConfigurableGitWorktreePruneOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

       
};

#endif
