// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITDIFFFINDOPTIONS_H
#define GITDIFFFINDOPTIONS_H
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

 class GitDiffFindOptions;
class ConfigurableGitDiffFindOptions;
 
struct GitDiffFindOptionsTraits {
  typedef GitDiffFindOptions cppClass;
  typedef git_diff_find_options cType;
  typedef ConfigurableGitDiffFindOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_find_options **dest, git_diff_find_options *src) {
     throw std::runtime_error("duplicate called on GitDiffFindOptions which cannot be duplicated");
   }

  static std::string className() { return "GitDiffFindOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_find_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitDiffFindOptions : public nodegit::ConfigurableClassWrapper<GitDiffFindOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitDiffFindOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitDiffFindOptions();

  ConfigurableGitDiffFindOptions(const ConfigurableGitDiffFindOptions &) = delete;
  ConfigurableGitDiffFindOptions(ConfigurableGitDiffFindOptions &&) = delete;
  ConfigurableGitDiffFindOptions &operator=(const ConfigurableGitDiffFindOptions &) = delete;
  ConfigurableGitDiffFindOptions &operator=(ConfigurableGitDiffFindOptions &&) = delete;

               
private:
  ConfigurableGitDiffFindOptions(nodegit::Context *nodegitContext);
  ConfigurableGitDiffFindOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                      
};

#endif
