// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFFBINARYFILE_H
#define GITDIFFBINARYFILE_H
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

class GitDiffBinaryFile;
 
struct GitDiffBinaryFileTraits {
  typedef GitDiffBinaryFile cppClass;
  typedef git_diff_binary_file cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_binary_file **dest, git_diff_binary_file *src) {
     throw std::runtime_error("duplicate called on GitDiffBinaryFile which cannot be duplicated");
   }

  static std::string className() { return "GitDiffBinaryFile"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_binary_file *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiffBinaryFile : public
  NodeGitWrapper<GitDiffBinaryFileTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffBinaryFileTraits>;
   public:
    GitDiffBinaryFile(const GitDiffBinaryFile &) = delete;
    GitDiffBinaryFile(GitDiffBinaryFile &&) = delete;
    GitDiffBinaryFile &operator=(const GitDiffBinaryFile &) = delete;
    GitDiffBinaryFile &operator=(GitDiffBinaryFile &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitDiffBinaryFile(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffBinaryFileTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiffBinaryFile cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiffBinaryFile();

  private:

    Napi::Value Type(const Napi::CallbackInfo& info);
    Napi::Value Data(const Napi::CallbackInfo& info);
    Napi::Value Datalen(const Napi::CallbackInfo& info);
    Napi::Value Inflatedlen(const Napi::CallbackInfo& info);
};

#endif
