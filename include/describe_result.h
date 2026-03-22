// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDESCRIBERESULT_H
#define GITDESCRIBERESULT_H
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
struct git_describe_result {
};
class GitDescribeResult;
 
struct GitDescribeResultTraits {
  typedef GitDescribeResult cppClass;
  typedef git_describe_result cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_describe_result **dest, git_describe_result *src) {
     throw std::runtime_error("duplicate called on GitDescribeResult which cannot be duplicated");
   }

  static std::string className() { return "GitDescribeResult"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_describe_result *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDescribeResult : public
  NodeGitWrapper<GitDescribeResultTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDescribeResultTraits>;
   public:
    GitDescribeResult(const GitDescribeResult &) = delete;
    GitDescribeResult(GitDescribeResult &&) = delete;
    GitDescribeResult &operator=(const GitDescribeResult &) = delete;
    GitDescribeResult &operator=(GitDescribeResult &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitDescribeResult(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDescribeResultTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDescribeResult cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDescribeResult();

  private:

};

#endif
