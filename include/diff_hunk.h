// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFFHUNK_H
#define GITDIFFHUNK_H
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

class GitDiffHunk;
 
struct GitDiffHunkTraits {
  typedef GitDiffHunk cppClass;
  typedef git_diff_hunk cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_hunk **dest, git_diff_hunk *src) {
     throw std::runtime_error("duplicate called on GitDiffHunk which cannot be duplicated");
   }

  static std::string className() { return "GitDiffHunk"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_hunk *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiffHunk : public
  NodeGitWrapper<GitDiffHunkTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffHunkTraits>;
   public:
    GitDiffHunk(const GitDiffHunk &) = delete;
    GitDiffHunk(GitDiffHunk &&) = delete;
    GitDiffHunk &operator=(const GitDiffHunk &) = delete;
    GitDiffHunk &operator=(GitDiffHunk &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitDiffHunk(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffHunkTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiffHunk cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiffHunk();

  private:

    Napi::Value OldStart(const Napi::CallbackInfo& info);
    Napi::Value OldLines(const Napi::CallbackInfo& info);
    Napi::Value NewStart(const Napi::CallbackInfo& info);
    Napi::Value NewLines(const Napi::CallbackInfo& info);
    Napi::Value HeaderLen(const Napi::CallbackInfo& info);
    Napi::Value Header(const Napi::CallbackInfo& info);
};

#endif
