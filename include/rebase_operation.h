// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREBASEOPERATION_H
#define GITREBASEOPERATION_H
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

#include "../include/oid.h"
class GitRebaseOperation;
 
struct GitRebaseOperationTraits {
  typedef GitRebaseOperation cppClass;
  typedef git_rebase_operation cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_rebase_operation **dest, git_rebase_operation *src) {
     throw std::runtime_error("duplicate called on GitRebaseOperation which cannot be duplicated");
   }

  static std::string className() { return "GitRebaseOperation"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_rebase_operation *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRebaseOperation : public
  NodeGitWrapper<GitRebaseOperationTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRebaseOperationTraits>;
   public:
    GitRebaseOperation(const GitRebaseOperation &) = delete;
    GitRebaseOperation(GitRebaseOperation &&) = delete;
    GitRebaseOperation &operator=(const GitRebaseOperation &) = delete;
    GitRebaseOperation &operator=(GitRebaseOperation &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitRebaseOperation(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRebaseOperationTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRebaseOperation cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRebaseOperation();

  private:

    Napi::Value Type(const Napi::CallbackInfo& info);
    Napi::Value Id(const Napi::CallbackInfo& info);
    Napi::Value Exec(const Napi::CallbackInfo& info);
};

#endif
