// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCERTHOSTKEY_H
#define GITCERTHOSTKEY_H
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

#include "../include/cert.h"
class GitCertHostkey;
 
struct GitCertHostkeyTraits {
  typedef GitCertHostkey cppClass;
  typedef git_cert_hostkey cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_cert_hostkey **dest, git_cert_hostkey *src) {
     throw std::runtime_error("duplicate called on GitCertHostkey which cannot be duplicated");
   }

  static std::string className() { return "GitCertHostkey"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_cert_hostkey *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitCertHostkey : public
  NodeGitWrapper<GitCertHostkeyTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCertHostkeyTraits>;
   public:
    GitCertHostkey(const GitCertHostkey &) = delete;
    GitCertHostkey(GitCertHostkey &&) = delete;
    GitCertHostkey &operator=(const GitCertHostkey &) = delete;
    GitCertHostkey &operator=(GitCertHostkey &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitCertHostkey(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCertHostkeyTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCertHostkey cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCertHostkey();

  private:

    Napi::Value Parent(const Napi::CallbackInfo& info);
    Napi::Value Type(const Napi::CallbackInfo& info);
    Napi::Value HashMd5(const Napi::CallbackInfo& info);
    Napi::Value HashSha1(const Napi::CallbackInfo& info);
    Napi::Value HashSha256(const Napi::CallbackInfo& info);
    Napi::Value RawType(const Napi::CallbackInfo& info);
    Napi::Value Hostkey(const Napi::CallbackInfo& info);
    Napi::Value HostkeyLen(const Napi::CallbackInfo& info);
};

#endif
