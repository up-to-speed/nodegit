// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITINDEXERPROGRESS_H
#define GITINDEXERPROGRESS_H
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

class GitIndexerProgress;
 
struct GitIndexerProgressTraits {
  typedef GitIndexerProgress cppClass;
  typedef git_indexer_progress cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_indexer_progress **dest, git_indexer_progress *src) {
     throw std::runtime_error("duplicate called on GitIndexerProgress which cannot be duplicated");
   }

  static std::string className() { return "GitIndexerProgress"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_indexer_progress *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitIndexerProgress : public
  NodeGitWrapper<GitIndexerProgressTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitIndexerProgressTraits>;
   public:
    GitIndexerProgress(const GitIndexerProgress &) = delete;
    GitIndexerProgress(GitIndexerProgress &&) = delete;
    GitIndexerProgress &operator=(const GitIndexerProgress &) = delete;
    GitIndexerProgress &operator=(GitIndexerProgress &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitIndexerProgress(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitIndexerProgressTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitIndexerProgress cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitIndexerProgress();

  private:

    Napi::Value TotalObjects(const Napi::CallbackInfo& info);
    Napi::Value IndexedObjects(const Napi::CallbackInfo& info);
    Napi::Value ReceivedObjects(const Napi::CallbackInfo& info);
    Napi::Value LocalObjects(const Napi::CallbackInfo& info);
    Napi::Value TotalDeltas(const Napi::CallbackInfo& info);
    Napi::Value IndexedDeltas(const Napi::CallbackInfo& info);
    Napi::Value ReceivedBytes(const Napi::CallbackInfo& info);
};

#endif
