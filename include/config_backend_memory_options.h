// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCONFIGBACKENDMEMORYOPTIONS_H
#define GITCONFIGBACKENDMEMORYOPTIONS_H
#include <napi.h>
#include <string>
#include <utility>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <sstream>

#include "async_baton.h"
#include "async_worker.h"
#include "cleanup_handle.h"
#include "context.h"
#include "lock_master.h"
#include "bungit_wrapper.h"
#include "promise_completion.h"
#include "reference_counter.h"
#include "worker_pool.h"

extern "C" {
#include <git2.h>
#include <git2/sys/errors.h>
#include <git2/sys/config.h>
}

#include "../include/typedefs.h"

class GitConfigBackendMemoryOptions;
 
struct GitConfigBackendMemoryOptionsTraits {
  typedef GitConfigBackendMemoryOptions cppClass;
  typedef git_config_backend_memory_options cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_config_backend_memory_options **dest, git_config_backend_memory_options *src) {
     throw std::runtime_error("duplicate called on GitConfigBackendMemoryOptions which cannot be duplicated");
   }

  static std::string className() { return "GitConfigBackendMemoryOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_config_backend_memory_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitConfigBackendMemoryOptions : public
  NodeGitWrapper<GitConfigBackendMemoryOptionsTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitConfigBackendMemoryOptionsTraits>;
   public:
    GitConfigBackendMemoryOptions(const GitConfigBackendMemoryOptions &) = delete;
    GitConfigBackendMemoryOptions(GitConfigBackendMemoryOptions &&) = delete;
    GitConfigBackendMemoryOptions &operator=(const GitConfigBackendMemoryOptions &) = delete;
    GitConfigBackendMemoryOptions &operator=(GitConfigBackendMemoryOptions &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitConfigBackendMemoryOptions(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitConfigBackendMemoryOptionsTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitConfigBackendMemoryOptions cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitConfigBackendMemoryOptions();

  private:

    Napi::Value Version(const Napi::CallbackInfo& info);
    Napi::Value BackendType(const Napi::CallbackInfo& info);
    Napi::Value OriginPath(const Napi::CallbackInfo& info);
};

#endif
