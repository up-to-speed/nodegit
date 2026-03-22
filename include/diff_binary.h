// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFFBINARY_H
#define GITDIFFBINARY_H
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

#include "../include/diff_binary_file.h"
class GitDiffBinary;
 
struct GitDiffBinaryTraits {
  typedef GitDiffBinary cppClass;
  typedef git_diff_binary cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_binary **dest, git_diff_binary *src) {
     throw std::runtime_error("duplicate called on GitDiffBinary which cannot be duplicated");
   }

  static std::string className() { return "GitDiffBinary"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_binary *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiffBinary : public
  NodeGitWrapper<GitDiffBinaryTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffBinaryTraits>;
   public:
    GitDiffBinary(const GitDiffBinary &) = delete;
    GitDiffBinary(GitDiffBinary &&) = delete;
    GitDiffBinary &operator=(const GitDiffBinary &) = delete;
    GitDiffBinary &operator=(GitDiffBinary &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitDiffBinary(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffBinaryTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiffBinary cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiffBinary();

  private:

    Napi::Value ContainsData(const Napi::CallbackInfo& info);
    Napi::Value OldFile(const Napi::CallbackInfo& info);
    Napi::Value NewFile(const Napi::CallbackInfo& info);
};

#endif
