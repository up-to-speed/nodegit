// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFFLINE_H
#define GITDIFFLINE_H
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

class GitDiffLine;
 
struct GitDiffLineTraits {
  typedef GitDiffLine cppClass;
  typedef git_diff_line cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_line **dest, git_diff_line *src) {
     throw std::runtime_error("duplicate called on GitDiffLine which cannot be duplicated");
   }

  static std::string className() { return "GitDiffLine"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_line *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiffLine : public
  NodeGitWrapper<GitDiffLineTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffLineTraits>;
   public:
    GitDiffLine(const GitDiffLine &) = delete;
    GitDiffLine(GitDiffLine &&) = delete;
    GitDiffLine &operator=(const GitDiffLine &) = delete;
    GitDiffLine &operator=(GitDiffLine &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitDiffLine(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffLineTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiffLine cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiffLine();

  private:

    Napi::Value Origin(const Napi::CallbackInfo& info);
    Napi::Value OldLineno(const Napi::CallbackInfo& info);
    Napi::Value NewLineno(const Napi::CallbackInfo& info);
    Napi::Value NumLines(const Napi::CallbackInfo& info);
    Napi::Value ContentLen(const Napi::CallbackInfo& info);
    Napi::Value ContentOffset(const Napi::CallbackInfo& info);
    Napi::Value Content(const Napi::CallbackInfo& info);
};

#endif
