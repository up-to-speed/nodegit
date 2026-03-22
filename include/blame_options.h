// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITBLAMEOPTIONS_H
#define GITBLAMEOPTIONS_H
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
 class GitBlameOptions;
class ConfigurableGitBlameOptions;
 
struct GitBlameOptionsTraits {
  typedef GitBlameOptions cppClass;
  typedef git_blame_options cType;
  typedef ConfigurableGitBlameOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_blame_options **dest, git_blame_options *src) {
     throw std::runtime_error("duplicate called on GitBlameOptions which cannot be duplicated");
   }

  static std::string className() { return "GitBlameOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_blame_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitBlameOptions : public nodegit::ConfigurableClassWrapper<GitBlameOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitBlameOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitBlameOptions();

  ConfigurableGitBlameOptions(const ConfigurableGitBlameOptions &) = delete;
  ConfigurableGitBlameOptions(ConfigurableGitBlameOptions &&) = delete;
  ConfigurableGitBlameOptions &operator=(const ConfigurableGitBlameOptions &) = delete;
  ConfigurableGitBlameOptions &operator=(ConfigurableGitBlameOptions &&) = delete;

               
private:
  ConfigurableGitBlameOptions(nodegit::Context *nodegitContext);
  ConfigurableGitBlameOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                        
};

#endif
