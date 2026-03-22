// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFFPERFDATA_H
#define GITDIFFPERFDATA_H
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
#include <git2/sys/diff.h>
}

#include "../include/typedefs.h"

class GitDiffPerfdata;
 
struct GitDiffPerfdataTraits {
  typedef GitDiffPerfdata cppClass;
  typedef git_diff_perfdata cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_perfdata **dest, git_diff_perfdata *src) {
     throw std::runtime_error("duplicate called on GitDiffPerfdata which cannot be duplicated");
   }

  static std::string className() { return "GitDiffPerfdata"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_perfdata *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiffPerfdata : public
  NodeGitWrapper<GitDiffPerfdataTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffPerfdataTraits>;
   public:
    GitDiffPerfdata(const GitDiffPerfdata &) = delete;
    GitDiffPerfdata(GitDiffPerfdata &&) = delete;
    GitDiffPerfdata &operator=(const GitDiffPerfdata &) = delete;
    GitDiffPerfdata &operator=(GitDiffPerfdata &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitDiffPerfdata(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffPerfdataTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiffPerfdata cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiffPerfdata();

  private:

    Napi::Value StatCalls(const Napi::CallbackInfo& info);
    Napi::Value OidCalculations(const Napi::CallbackInfo& info);
};

#endif
