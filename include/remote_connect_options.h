// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITREMOTECONNECTOPTIONS_H
#define GITREMOTECONNECTOPTIONS_H
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
  #include "../include/remote_callbacks.h"
  #include "../include/proxy_options.h"
  #include "../include/strarray.h"
 class GitRemoteConnectOptions;
class ConfigurableGitRemoteConnectOptions;
 
struct GitRemoteConnectOptionsTraits {
  typedef GitRemoteConnectOptions cppClass;
  typedef git_remote_connect_options cType;
  typedef ConfigurableGitRemoteConnectOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_remote_connect_options **dest, git_remote_connect_options *src) {
     throw std::runtime_error("duplicate called on GitRemoteConnectOptions which cannot be duplicated");
   }

  static std::string className() { return "GitRemoteConnectOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_remote_connect_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitRemoteConnectOptions : public nodegit::ConfigurableClassWrapper<GitRemoteConnectOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitRemoteConnectOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitRemoteConnectOptions();

  ConfigurableGitRemoteConnectOptions(const ConfigurableGitRemoteConnectOptions &) = delete;
  ConfigurableGitRemoteConnectOptions(ConfigurableGitRemoteConnectOptions &&) = delete;
  ConfigurableGitRemoteConnectOptions &operator=(const ConfigurableGitRemoteConnectOptions &) = delete;
  ConfigurableGitRemoteConnectOptions &operator=(ConfigurableGitRemoteConnectOptions &&) = delete;

           
private:
  ConfigurableGitRemoteConnectOptions(nodegit::Context *nodegitContext);
  ConfigurableGitRemoteConnectOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                
};

#endif
