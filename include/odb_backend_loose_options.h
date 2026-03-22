// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITODBBACKENDLOOSEOPTIONS_H
#define GITODBBACKENDLOOSEOPTIONS_H
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

class GitOdbBackendLooseOptions;
 
struct GitOdbBackendLooseOptionsTraits {
  typedef GitOdbBackendLooseOptions cppClass;
  typedef git_odb_backend_loose_options cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_odb_backend_loose_options **dest, git_odb_backend_loose_options *src) {
     throw std::runtime_error("duplicate called on GitOdbBackendLooseOptions which cannot be duplicated");
   }

  static std::string className() { return "GitOdbBackendLooseOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_odb_backend_loose_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitOdbBackendLooseOptions : public
  NodeGitWrapper<GitOdbBackendLooseOptionsTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitOdbBackendLooseOptionsTraits>;
   public:
    GitOdbBackendLooseOptions(const GitOdbBackendLooseOptions &) = delete;
    GitOdbBackendLooseOptions(GitOdbBackendLooseOptions &&) = delete;
    GitOdbBackendLooseOptions &operator=(const GitOdbBackendLooseOptions &) = delete;
    GitOdbBackendLooseOptions &operator=(GitOdbBackendLooseOptions &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitOdbBackendLooseOptions(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitOdbBackendLooseOptionsTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitOdbBackendLooseOptions cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitOdbBackendLooseOptions();

  private:

    Napi::Value Version(const Napi::CallbackInfo& info);
    Napi::Value Flags(const Napi::CallbackInfo& info);
    Napi::Value CompressionLevel(const Napi::CallbackInfo& info);
    Napi::Value DirMode(const Napi::CallbackInfo& info);
    Napi::Value FileMode(const Napi::CallbackInfo& info);
    Napi::Value OidType(const Napi::CallbackInfo& info);
};

#endif
