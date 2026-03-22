// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITOIDARRAY_H
#define GITOIDARRAY_H
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
class GitOidarray;
 
struct GitOidarrayTraits {
  typedef GitOidarray cppClass;
  typedef git_oidarray cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_oidarray **dest, git_oidarray *src) {
     throw std::runtime_error("duplicate called on GitOidarray which cannot be duplicated");
   }

  static std::string className() { return "GitOidarray"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_oidarray *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_oidarray_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitOidarray : public
  NodeGitWrapper<GitOidarrayTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitOidarrayTraits>;
   public:
    GitOidarray(const GitOidarray &) = delete;
    GitOidarray(GitOidarray &&) = delete;
    GitOidarray &operator=(const GitOidarray &) = delete;
    GitOidarray &operator=(GitOidarray &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

        GitOidarray(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitOidarrayTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitOidarray cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitOidarray();

  private:

    Napi::Value Ids(const Napi::CallbackInfo& info);
    Napi::Value Count(const Napi::CallbackInfo& info);
    Napi::Value Dispose(const Napi::CallbackInfo& info);
 };

#endif
