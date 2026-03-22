// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITODBBACKENDPACKOPTIONS_H
#define GITODBBACKENDPACKOPTIONS_H
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

class GitOdbBackendPackOptions;
 
struct GitOdbBackendPackOptionsTraits {
  typedef GitOdbBackendPackOptions cppClass;
  typedef git_odb_backend_pack_options cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_odb_backend_pack_options **dest, git_odb_backend_pack_options *src) {
     throw std::runtime_error("duplicate called on GitOdbBackendPackOptions which cannot be duplicated");
   }

  static std::string className() { return "GitOdbBackendPackOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_odb_backend_pack_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitOdbBackendPackOptions : public
  NodeGitWrapper<GitOdbBackendPackOptionsTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitOdbBackendPackOptionsTraits>;
   public:
    GitOdbBackendPackOptions(const GitOdbBackendPackOptions &) = delete;
    GitOdbBackendPackOptions(GitOdbBackendPackOptions &&) = delete;
    GitOdbBackendPackOptions &operator=(const GitOdbBackendPackOptions &) = delete;
    GitOdbBackendPackOptions &operator=(GitOdbBackendPackOptions &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitOdbBackendPackOptions(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitOdbBackendPackOptionsTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitOdbBackendPackOptions cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitOdbBackendPackOptions();

  private:

    Napi::Value Version(const Napi::CallbackInfo& info);
    Napi::Value OidType(const Napi::CallbackInfo& info);
};

#endif
