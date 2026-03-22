// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCOMMITARRAY_H
#define GITCOMMITARRAY_H
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

class GitCommitarray;
 
struct GitCommitarrayTraits {
  typedef GitCommitarray cppClass;
  typedef git_commitarray cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_commitarray **dest, git_commitarray *src) {
     throw std::runtime_error("duplicate called on GitCommitarray which cannot be duplicated");
   }

  static std::string className() { return "GitCommitarray"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_commitarray *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitCommitarray : public
  NodeGitWrapper<GitCommitarrayTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCommitarrayTraits>;
   public:
    GitCommitarray(const GitCommitarray &) = delete;
    GitCommitarray(GitCommitarray &&) = delete;
    GitCommitarray &operator=(const GitCommitarray &) = delete;
    GitCommitarray &operator=(GitCommitarray &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

        GitCommitarray(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCommitarrayTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCommitarray cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCommitarray();

  private:

    Napi::Value Dispose(const Napi::CallbackInfo& info);
 };

#endif
