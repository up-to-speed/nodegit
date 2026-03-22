// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCONFIGMAP_H
#define GITCONFIGMAP_H
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

class GitConfigmap;
 
struct GitConfigmapTraits {
  typedef GitConfigmap cppClass;
  typedef git_configmap cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_configmap **dest, git_configmap *src) {
     throw std::runtime_error("duplicate called on GitConfigmap which cannot be duplicated");
   }

  static std::string className() { return "GitConfigmap"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_configmap *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitConfigmap : public
  NodeGitWrapper<GitConfigmapTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitConfigmapTraits>;
   public:
    GitConfigmap(const GitConfigmap &) = delete;
    GitConfigmap(GitConfigmap &&) = delete;
    GitConfigmap &operator=(const GitConfigmap &) = delete;
    GitConfigmap &operator=(GitConfigmap &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitConfigmap(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitConfigmapTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitConfigmap cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitConfigmap();

  private:

    Napi::Value Type(const Napi::CallbackInfo& info);
    Napi::Value StrMatch(const Napi::CallbackInfo& info);
    Napi::Value MapValue(const Napi::CallbackInfo& info);
};

#endif
