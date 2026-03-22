// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFFFILE_H
#define GITDIFFFILE_H
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
class GitDiffFile;
 
struct GitDiffFileTraits {
  typedef GitDiffFile cppClass;
  typedef git_diff_file cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_file **dest, git_diff_file *src) {
     throw std::runtime_error("duplicate called on GitDiffFile which cannot be duplicated");
   }

  static std::string className() { return "GitDiffFile"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_file *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiffFile : public
  NodeGitWrapper<GitDiffFileTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffFileTraits>;
   public:
    GitDiffFile(const GitDiffFile &) = delete;
    GitDiffFile(GitDiffFile &&) = delete;
    GitDiffFile &operator=(const GitDiffFile &) = delete;
    GitDiffFile &operator=(GitDiffFile &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitDiffFile(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffFileTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiffFile cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiffFile();

  private:

    Napi::Value Id(const Napi::CallbackInfo& info);
    Napi::Value Path(const Napi::CallbackInfo& info);
    Napi::Value Size(const Napi::CallbackInfo& info);
    Napi::Value Flags(const Napi::CallbackInfo& info);
    Napi::Value Mode(const Napi::CallbackInfo& info);
    Napi::Value IdAbbrev(const Napi::CallbackInfo& info);
};

#endif
