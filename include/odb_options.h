// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITODBOPTIONS_H
#define GITODBOPTIONS_H
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

class GitOdbOptions;
 
struct GitOdbOptionsTraits {
  typedef GitOdbOptions cppClass;
  typedef git_odb_options cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_odb_options **dest, git_odb_options *src) {
     throw std::runtime_error("duplicate called on GitOdbOptions which cannot be duplicated");
   }

  static std::string className() { return "GitOdbOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_odb_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitOdbOptions : public
  NodeGitWrapper<GitOdbOptionsTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitOdbOptionsTraits>;
   public:
    GitOdbOptions(const GitOdbOptions &) = delete;
    GitOdbOptions(GitOdbOptions &&) = delete;
    GitOdbOptions &operator=(const GitOdbOptions &) = delete;
    GitOdbOptions &operator=(GitOdbOptions &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitOdbOptions(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitOdbOptionsTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitOdbOptions cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitOdbOptions();

  private:

    Napi::Value Version(const Napi::CallbackInfo& info);
    Napi::Value OidType(const Napi::CallbackInfo& info);
};

#endif
