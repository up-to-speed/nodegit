// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITCHERRYPICKOPTIONS_H
#define GITCHERRYPICKOPTIONS_H
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

  #include "../include/merge_options.h"
  #include "../include/checkout_options.h"
 class GitCherrypickOptions;
class ConfigurableGitCherrypickOptions;
 
struct GitCherrypickOptionsTraits {
  typedef GitCherrypickOptions cppClass;
  typedef git_cherrypick_options cType;
  typedef ConfigurableGitCherrypickOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_cherrypick_options **dest, git_cherrypick_options *src) {
     throw std::runtime_error("duplicate called on GitCherrypickOptions which cannot be duplicated");
   }

  static std::string className() { return "GitCherrypickOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_cherrypick_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitCherrypickOptions : public nodegit::ConfigurableClassWrapper<GitCherrypickOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitCherrypickOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitCherrypickOptions();

  ConfigurableGitCherrypickOptions(const ConfigurableGitCherrypickOptions &) = delete;
  ConfigurableGitCherrypickOptions(ConfigurableGitCherrypickOptions &&) = delete;
  ConfigurableGitCherrypickOptions &operator=(const ConfigurableGitCherrypickOptions &) = delete;
  ConfigurableGitCherrypickOptions &operator=(ConfigurableGitCherrypickOptions &&) = delete;

         
private:
  ConfigurableGitCherrypickOptions(nodegit::Context *nodegitContext);
  ConfigurableGitCherrypickOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

             
};

#endif
