// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCONFIGENTRY_H
#define GITCONFIGENTRY_H
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
}

#include "../include/typedefs.h"

class GitConfigEntry;
 
struct GitConfigEntryTraits {
  typedef GitConfigEntry cppClass;
  typedef git_config_entry cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_config_entry **dest, git_config_entry *src) {
     throw std::runtime_error("duplicate called on GitConfigEntry which cannot be duplicated");
   }

  static std::string className() { return "GitConfigEntry"; };
  static const bool isSingleton = false;
  static const bool isFreeable = false;
  static void free(git_config_entry *raw) {
     throw std::runtime_error("free called on GitConfigEntry which cannot be freed");
   }
};

class GitConfigEntry : public
  NodeGitWrapper<GitConfigEntryTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitConfigEntryTraits>;
   public:
    GitConfigEntry(const GitConfigEntry &) = delete;
    GitConfigEntry(GitConfigEntry &&) = delete;
    GitConfigEntry &operator=(const GitConfigEntry &) = delete;
    GitConfigEntry &operator=(GitConfigEntry &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitConfigEntry(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitConfigEntryTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitConfigEntry cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitConfigEntry();

  private:

    Napi::Value Name(const Napi::CallbackInfo& info);
    Napi::Value Value(const Napi::CallbackInfo& info);
    Napi::Value Level(const Napi::CallbackInfo& info);
};

#endif
