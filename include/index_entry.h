// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITINDEXENTRY_H
#define GITINDEXENTRY_H
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

  #include "../include/index_time.h"
  #include "../include/oid.h"
 class GitIndexEntry;
class ConfigurableGitIndexEntry;
 
struct GitIndexEntryTraits {
  typedef GitIndexEntry cppClass;
  typedef git_index_entry cType;
  typedef ConfigurableGitIndexEntry configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_index_entry **dest, git_index_entry *src) {
     throw std::runtime_error("duplicate called on GitIndexEntry which cannot be duplicated");
   }

  static std::string className() { return "GitIndexEntry"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_index_entry *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
   class GitIndexEntry : public NodeGitWrapper<GitIndexEntryTraits> {
      // grant full access to base class
      friend class NodeGitWrapper<GitIndexEntryTraits>;

    public:
      GitIndexEntry(const Napi::CallbackInfo &info);
      GitIndexEntry(const GitIndexEntry &) = delete;
      GitIndexEntry(GitIndexEntry &&) = delete;
      GitIndexEntry &operator=(const GitIndexEntry &) = delete;
      GitIndexEntry &operator=(GitIndexEntry &&) = delete;
      ~GitIndexEntry();
      static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

    private:

      void ConstructFields();

              Napi::ObjectReference ctime;
  
          Napi::Value GetCtime(const Napi::CallbackInfo& info);
          void SetCtime(const Napi::CallbackInfo& info, const Napi::Value& value);

               Napi::ObjectReference mtime;
  
          Napi::Value GetMtime(const Napi::CallbackInfo& info);
          void SetMtime(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetDev(const Napi::CallbackInfo& info);
          void SetDev(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetIno(const Napi::CallbackInfo& info);
          void SetIno(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetMode(const Napi::CallbackInfo& info);
          void SetMode(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetUid(const Napi::CallbackInfo& info);
          void SetUid(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetGid(const Napi::CallbackInfo& info);
          void SetGid(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetFileSize(const Napi::CallbackInfo& info);
          void SetFileSize(const Napi::CallbackInfo& info, const Napi::Value& value);

               Napi::ObjectReference id;
  
          Napi::Value GetId(const Napi::CallbackInfo& info);
          void SetId(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetFlags(const Napi::CallbackInfo& info);
          void SetFlags(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetFlagsExtended(const Napi::CallbackInfo& info);
          void SetFlagsExtended(const Napi::CallbackInfo& info, const Napi::Value& value);

   
          Napi::Value GetPath(const Napi::CallbackInfo& info);
          void SetPath(const Napi::CallbackInfo& info, const Napi::Value& value);

    };
 
class ConfigurableGitIndexEntry : public nodegit::ConfigurableClassWrapper<GitIndexEntryTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitIndexEntryTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitIndexEntry();

  ConfigurableGitIndexEntry(const ConfigurableGitIndexEntry &) = delete;
  ConfigurableGitIndexEntry(ConfigurableGitIndexEntry &&) = delete;
  ConfigurableGitIndexEntry &operator=(const ConfigurableGitIndexEntry &) = delete;
  ConfigurableGitIndexEntry &operator=(ConfigurableGitIndexEntry &&) = delete;

                         
private:
  ConfigurableGitIndexEntry(nodegit::Context *nodegitContext);
  ConfigurableGitIndexEntry() = delete;
  Napi::Reference<Napi::Value> promiseError;

                                      
};

#endif
