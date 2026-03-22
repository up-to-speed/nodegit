// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITDIFFPATCHIDOPTIONS_H
#define GITDIFFPATCHIDOPTIONS_H
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

 class GitDiffPatchidOptions;
class ConfigurableGitDiffPatchidOptions;
 
struct GitDiffPatchidOptionsTraits {
  typedef GitDiffPatchidOptions cppClass;
  typedef git_diff_patchid_options cType;
  typedef ConfigurableGitDiffPatchidOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_patchid_options **dest, git_diff_patchid_options *src) {
     throw std::runtime_error("duplicate called on GitDiffPatchidOptions which cannot be duplicated");
   }

  static std::string className() { return "GitDiffPatchidOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_patchid_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitDiffPatchidOptions : public nodegit::ConfigurableClassWrapper<GitDiffPatchidOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitDiffPatchidOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitDiffPatchidOptions();

  ConfigurableGitDiffPatchidOptions(const ConfigurableGitDiffPatchidOptions &) = delete;
  ConfigurableGitDiffPatchidOptions(ConfigurableGitDiffPatchidOptions &&) = delete;
  ConfigurableGitDiffPatchidOptions &operator=(const ConfigurableGitDiffPatchidOptions &) = delete;
  ConfigurableGitDiffPatchidOptions &operator=(ConfigurableGitDiffPatchidOptions &&) = delete;

   
private:
  ConfigurableGitDiffPatchidOptions(nodegit::Context *nodegitContext);
  ConfigurableGitDiffPatchidOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

    
};

#endif
