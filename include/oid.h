// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITOID_H
#define GITOID_H
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

class GitOid;
 
struct GitOidTraits {
  typedef GitOid cppClass;
  typedef git_oid cType;
 
  static const bool isDuplicable = true;
  static void duplicate(git_oid **dest, git_oid *src) {
    git_oid *copy = (git_oid *)malloc(sizeof(git_oid));
    git_oid_cpy(copy, src);
    *dest = copy;
   }

  static std::string className() { return "GitOid"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_oid *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitOid : public
  NodeGitWrapper<GitOidTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitOidTraits>;
   public:
    GitOid(const GitOid &) = delete;
    GitOid(GitOid &&) = delete;
    GitOid &operator=(const GitOid &) = delete;
    GitOid &operator=(GitOid &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                        GitOid(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitOidTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitOid cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitOid();

  private:

    Napi::Value Cmp(const Napi::CallbackInfo& info);
     Napi::Value Cpy(const Napi::CallbackInfo& info);
     Napi::Value Equal(const Napi::CallbackInfo& info);
      static Napi::Value Fromstrp(const Napi::CallbackInfo& info);
     Napi::Value IsZero(const Napi::CallbackInfo& info);
     Napi::Value Ncmp(const Napi::CallbackInfo& info);
     Napi::Value Strcmp(const Napi::CallbackInfo& info);
     Napi::Value Streq(const Napi::CallbackInfo& info);
     Napi::Value TostrS(const Napi::CallbackInfo& info);
 };

#endif
