// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITOIDSHORTEN_H
#define GITOIDSHORTEN_H
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

// Forward declaration.
struct git_oid_shorten {
};
class GitOidShorten;
 
struct GitOidShortenTraits {
  typedef GitOidShorten cppClass;
  typedef git_oid_shorten cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_oid_shorten **dest, git_oid_shorten *src) {
     throw std::runtime_error("duplicate called on GitOidShorten which cannot be duplicated");
   }

  static std::string className() { return "GitOidShorten"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_oid_shorten *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_oid_shorten_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitOidShorten : public
  NodeGitWrapper<GitOidShortenTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitOidShortenTraits>;
   public:
    GitOidShorten(const GitOidShorten &) = delete;
    GitOidShorten(GitOidShorten &&) = delete;
    GitOidShorten &operator=(const GitOidShorten &) = delete;
    GitOidShorten &operator=(GitOidShorten &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

            GitOidShorten(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitOidShortenTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitOidShorten cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitOidShorten();

  private:

    Napi::Value Add(const Napi::CallbackInfo& info);
      static Napi::Value Create(const Napi::CallbackInfo& info);
 };

#endif
