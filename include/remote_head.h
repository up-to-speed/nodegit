// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREMOTEHEAD_H
#define GITREMOTEHEAD_H
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

#include "../include/functions/free.h"
#include "../include/oid.h"
class GitRemoteHead;
 
struct GitRemoteHeadTraits {
  typedef GitRemoteHead cppClass;
  typedef git_remote_head cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_remote_head **dest, git_remote_head *src) {
     throw std::runtime_error("duplicate called on GitRemoteHead which cannot be duplicated");
   }

  static std::string className() { return "GitRemoteHead"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_remote_head *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_remote_head_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRemoteHead : public
  NodeGitWrapper<GitRemoteHeadTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRemoteHeadTraits>;
   public:
    GitRemoteHead(const GitRemoteHead &) = delete;
    GitRemoteHead(GitRemoteHead &&) = delete;
    GitRemoteHead &operator=(const GitRemoteHead &) = delete;
    GitRemoteHead &operator=(GitRemoteHead &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitRemoteHead(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRemoteHeadTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRemoteHead cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRemoteHead();

  private:

    Napi::Value Local(const Napi::CallbackInfo& info);
    Napi::Value Oid(const Napi::CallbackInfo& info);
    Napi::Value Loid(const Napi::CallbackInfo& info);
    Napi::Value Name(const Napi::CallbackInfo& info);
    Napi::Value SymrefTarget(const Napi::CallbackInfo& info);
};

#endif
