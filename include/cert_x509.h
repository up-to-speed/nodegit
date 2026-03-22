// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCERTX509_H
#define GITCERTX509_H
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

#include "../include/wrapper.h"
#include "node_buffer.h"
#include "../include/cert.h"
class GitCertX509;
 
struct GitCertX509Traits {
  typedef GitCertX509 cppClass;
  typedef git_cert_x509 cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_cert_x509 **dest, git_cert_x509 *src) {
     throw std::runtime_error("duplicate called on GitCertX509 which cannot be duplicated");
   }

  static std::string className() { return "GitCertX509"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_cert_x509 *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitCertX509 : public
  NodeGitWrapper<GitCertX509Traits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCertX509Traits>;
   public:
    GitCertX509(const GitCertX509 &) = delete;
    GitCertX509(GitCertX509 &&) = delete;
    GitCertX509 &operator=(const GitCertX509 &) = delete;
    GitCertX509 &operator=(GitCertX509 &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitCertX509(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCertX509Traits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCertX509 cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCertX509();

  private:

    Napi::Value Parent(const Napi::CallbackInfo& info);
    Napi::Value Data(const Napi::CallbackInfo& info);
    Napi::Value Len(const Napi::CallbackInfo& info);
};

#endif
