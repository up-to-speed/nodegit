// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITEMAILCREATEOPTIONS_H
#define GITEMAILCREATEOPTIONS_H
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

  #include "../include/diff_options.h"
  #include "../include/diff_find_options.h"
 class GitEmailCreateOptions;
class ConfigurableGitEmailCreateOptions;
 
struct GitEmailCreateOptionsTraits {
  typedef GitEmailCreateOptions cppClass;
  typedef git_email_create_options cType;
  typedef ConfigurableGitEmailCreateOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_email_create_options **dest, git_email_create_options *src) {
     throw std::runtime_error("duplicate called on GitEmailCreateOptions which cannot be duplicated");
   }

  static std::string className() { return "GitEmailCreateOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_email_create_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitEmailCreateOptions : public nodegit::ConfigurableClassWrapper<GitEmailCreateOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitEmailCreateOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitEmailCreateOptions();

  ConfigurableGitEmailCreateOptions(const ConfigurableGitEmailCreateOptions &) = delete;
  ConfigurableGitEmailCreateOptions(ConfigurableGitEmailCreateOptions &&) = delete;
  ConfigurableGitEmailCreateOptions &operator=(const ConfigurableGitEmailCreateOptions &) = delete;
  ConfigurableGitEmailCreateOptions &operator=(ConfigurableGitEmailCreateOptions &&) = delete;

               
private:
  ConfigurableGitEmailCreateOptions(nodegit::Context *nodegitContext);
  ConfigurableGitEmailCreateOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                      
};

#endif
