// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITSTASHSAVEOPTIONS_H
#define GITSTASHSAVEOPTIONS_H
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
  #include "../include/signature.h"
  #include "../include/strarray.h"
 class GitStashSaveOptions;
class ConfigurableGitStashSaveOptions;
 
struct GitStashSaveOptionsTraits {
  typedef GitStashSaveOptions cppClass;
  typedef git_stash_save_options cType;
  typedef ConfigurableGitStashSaveOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_stash_save_options **dest, git_stash_save_options *src) {
     throw std::runtime_error("duplicate called on GitStashSaveOptions which cannot be duplicated");
   }

  static std::string className() { return "GitStashSaveOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_stash_save_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitStashSaveOptions : public nodegit::ConfigurableClassWrapper<GitStashSaveOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitStashSaveOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitStashSaveOptions();

  ConfigurableGitStashSaveOptions(const ConfigurableGitStashSaveOptions &) = delete;
  ConfigurableGitStashSaveOptions(ConfigurableGitStashSaveOptions &&) = delete;
  ConfigurableGitStashSaveOptions &operator=(const ConfigurableGitStashSaveOptions &) = delete;
  ConfigurableGitStashSaveOptions &operator=(ConfigurableGitStashSaveOptions &&) = delete;

           
private:
  ConfigurableGitStashSaveOptions(nodegit::Context *nodegitContext);
  ConfigurableGitStashSaveOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                   Napi::ObjectReference stasher;
            
};

#endif
