// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCHECKOUTPERFDATA_H
#define GITCHECKOUTPERFDATA_H
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

class GitCheckoutPerfdata;
 
struct GitCheckoutPerfdataTraits {
  typedef GitCheckoutPerfdata cppClass;
  typedef git_checkout_perfdata cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_checkout_perfdata **dest, git_checkout_perfdata *src) {
     throw std::runtime_error("duplicate called on GitCheckoutPerfdata which cannot be duplicated");
   }

  static std::string className() { return "GitCheckoutPerfdata"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_checkout_perfdata *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitCheckoutPerfdata : public
  NodeGitWrapper<GitCheckoutPerfdataTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCheckoutPerfdataTraits>;
   public:
    GitCheckoutPerfdata(const GitCheckoutPerfdata &) = delete;
    GitCheckoutPerfdata(GitCheckoutPerfdata &&) = delete;
    GitCheckoutPerfdata &operator=(const GitCheckoutPerfdata &) = delete;
    GitCheckoutPerfdata &operator=(GitCheckoutPerfdata &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitCheckoutPerfdata(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCheckoutPerfdataTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCheckoutPerfdata cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCheckoutPerfdata();

  private:

    Napi::Value MkdirCalls(const Napi::CallbackInfo& info);
    Napi::Value StatCalls(const Napi::CallbackInfo& info);
    Napi::Value ChmodCalls(const Napi::CallbackInfo& info);
};

#endif
