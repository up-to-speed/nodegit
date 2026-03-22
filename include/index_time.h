// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITINDEXTIME_H
#define GITINDEXTIME_H
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

 class GitIndexTime;
class ConfigurableGitIndexTime;
 
struct GitIndexTimeTraits {
  typedef GitIndexTime cppClass;
  typedef git_index_time cType;
  typedef ConfigurableGitIndexTime configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_index_time **dest, git_index_time *src) {
     throw std::runtime_error("duplicate called on GitIndexTime which cannot be duplicated");
   }

  static std::string className() { return "GitIndexTime"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_index_time *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
   class GitIndexTime : public NodeGitWrapper<GitIndexTimeTraits> {
      // grant full access to base class
      friend class NodeGitWrapper<GitIndexTimeTraits>;

    public:
      GitIndexTime(const Napi::CallbackInfo &info);
      GitIndexTime(const GitIndexTime &) = delete;
      GitIndexTime(GitIndexTime &&) = delete;
      GitIndexTime &operator=(const GitIndexTime &) = delete;
      GitIndexTime &operator=(GitIndexTime &&) = delete;
      ~GitIndexTime();
      static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

    private:

      void ConstructFields();

  
          Napi::Value GetSeconds(const Napi::CallbackInfo& info);
          void SetSeconds(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetNanoseconds(const Napi::CallbackInfo& info);
          void SetNanoseconds(const Napi::CallbackInfo& info, const Napi::Value& value);

    };
 
class ConfigurableGitIndexTime : public nodegit::ConfigurableClassWrapper<GitIndexTimeTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitIndexTimeTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitIndexTime();

  ConfigurableGitIndexTime(const ConfigurableGitIndexTime &) = delete;
  ConfigurableGitIndexTime(ConfigurableGitIndexTime &&) = delete;
  ConfigurableGitIndexTime &operator=(const ConfigurableGitIndexTime &) = delete;
  ConfigurableGitIndexTime &operator=(ConfigurableGitIndexTime &&) = delete;

     
private:
  ConfigurableGitIndexTime(nodegit::Context *nodegitContext);
  ConfigurableGitIndexTime() = delete;
  Napi::Reference<Napi::Value> promiseError;

       
};

#endif
