// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCERT_H
#define GITCERT_H
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

class GitCert;
 
struct GitCertTraits {
  typedef GitCert cppClass;
  typedef git_cert cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_cert **dest, git_cert *src) {
     throw std::runtime_error("duplicate called on GitCert which cannot be duplicated");
   }

  static std::string className() { return "GitCert"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_cert *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitCert : public
  NodeGitWrapper<GitCertTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCertTraits>;
   public:
    GitCert(const GitCert &) = delete;
    GitCert(GitCert &&) = delete;
    GitCert &operator=(const GitCert &) = delete;
    GitCert &operator=(GitCert &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitCert(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCertTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCert cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCert();

  private:

    Napi::Value CertType(const Napi::CallbackInfo& info);
};

#endif
