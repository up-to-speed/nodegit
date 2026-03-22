// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITBLAMEHUNK_H
#define GITBLAMEHUNK_H
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

#include "../include/oid.h"
#include "../include/signature.h"
class GitBlameHunk;
 
struct GitBlameHunkTraits {
  typedef GitBlameHunk cppClass;
  typedef git_blame_hunk cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_blame_hunk **dest, git_blame_hunk *src) {
     throw std::runtime_error("duplicate called on GitBlameHunk which cannot be duplicated");
   }

  static std::string className() { return "GitBlameHunk"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_blame_hunk *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitBlameHunk : public
  NodeGitWrapper<GitBlameHunkTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitBlameHunkTraits>;
   public:
    GitBlameHunk(const GitBlameHunk &) = delete;
    GitBlameHunk(GitBlameHunk &&) = delete;
    GitBlameHunk &operator=(const GitBlameHunk &) = delete;
    GitBlameHunk &operator=(GitBlameHunk &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitBlameHunk(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitBlameHunkTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitBlameHunk cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitBlameHunk();

  private:

    Napi::Value LinesInHunk(const Napi::CallbackInfo& info);
    Napi::Value FinalCommitId(const Napi::CallbackInfo& info);
    Napi::Value FinalStartLineNumber(const Napi::CallbackInfo& info);
    Napi::Value FinalSignature(const Napi::CallbackInfo& info);
    Napi::Value FinalCommitter(const Napi::CallbackInfo& info);
    Napi::Value OrigCommitId(const Napi::CallbackInfo& info);
    Napi::Value OrigPath(const Napi::CallbackInfo& info);
    Napi::Value OrigStartLineNumber(const Napi::CallbackInfo& info);
    Napi::Value OrigSignature(const Napi::CallbackInfo& info);
    Napi::Value OrigCommitter(const Napi::CallbackInfo& info);
    Napi::Value Summary(const Napi::CallbackInfo& info);
};

#endif
