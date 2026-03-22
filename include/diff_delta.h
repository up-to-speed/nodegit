// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFFDELTA_H
#define GITDIFFDELTA_H
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

#include "../include/diff_file.h"
class GitDiffDelta;
 
struct GitDiffDeltaTraits {
  typedef GitDiffDelta cppClass;
  typedef git_diff_delta cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_delta **dest, git_diff_delta *src) {
     throw std::runtime_error("duplicate called on GitDiffDelta which cannot be duplicated");
   }

  static std::string className() { return "GitDiffDelta"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_delta *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiffDelta : public
  NodeGitWrapper<GitDiffDeltaTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffDeltaTraits>;
   public:
    GitDiffDelta(const GitDiffDelta &) = delete;
    GitDiffDelta(GitDiffDelta &&) = delete;
    GitDiffDelta &operator=(const GitDiffDelta &) = delete;
    GitDiffDelta &operator=(GitDiffDelta &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitDiffDelta(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffDeltaTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiffDelta cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiffDelta();

  private:

    Napi::Value Status(const Napi::CallbackInfo& info);
    Napi::Value Flags(const Napi::CallbackInfo& info);
    Napi::Value Similarity(const Napi::CallbackInfo& info);
    Napi::Value Nfiles(const Napi::CallbackInfo& info);
    Napi::Value OldFile(const Napi::CallbackInfo& info);
    Napi::Value NewFile(const Napi::CallbackInfo& info);
};

#endif
