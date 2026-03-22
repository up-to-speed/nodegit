// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITPATHSPEC_H
#define GITPATHSPEC_H
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

#include "../include/str_array_converter.h"
#include "../include/pathspec_match_list.h"
#include "../include/diff.h"
#include "../include/index.h"
#include "../include/tree.h"
#include "../include/repository.h"
#include "../include/strarray.h"
// Forward declaration.
struct git_pathspec {
};
class GitPathspec;
 
struct GitPathspecTraits {
  typedef GitPathspec cppClass;
  typedef git_pathspec cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_pathspec **dest, git_pathspec *src) {
     throw std::runtime_error("duplicate called on GitPathspec which cannot be duplicated");
   }

  static std::string className() { return "GitPathspec"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_pathspec *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_pathspec_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitPathspec : public
  NodeGitWrapper<GitPathspecTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitPathspecTraits>;
   public:
    GitPathspec(const GitPathspec &) = delete;
    GitPathspec(GitPathspec &&) = delete;
    GitPathspec &operator=(const GitPathspec &) = delete;
    GitPathspec &operator=(GitPathspec &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                      GitPathspec(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitPathspecTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitPathspec cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitPathspec();

  private:


    struct MatchDiffBaton {
      int error_code;
      const git_error* error;
      git_pathspec_match_list * out;
      git_diff * diff;
      uint32_t flags;
      git_pathspec * ps;
     };
    class MatchDiffWorker : public nodegit::AsyncWorker {
      public:
        MatchDiffWorker(
            MatchDiffBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitPathspec:MatchDiff", cleanupHandles)
          , baton(_baton) {};
        MatchDiffWorker(const MatchDiffWorker &) = delete;
        MatchDiffWorker(MatchDiffWorker &&) = delete;
        MatchDiffWorker &operator=(const MatchDiffWorker &) = delete;
        MatchDiffWorker &operator=(MatchDiffWorker &&) = delete;
        ~MatchDiffWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        MatchDiffBaton *baton;
    };
    Napi::Value MatchDiff(const Napi::CallbackInfo& info);
 
    struct MatchIndexBaton {
      int error_code;
      const git_error* error;
      git_pathspec_match_list * out;
      git_index * index;
      uint32_t flags;
      git_pathspec * ps;
     };
    class MatchIndexWorker : public nodegit::AsyncWorker {
      public:
        MatchIndexWorker(
            MatchIndexBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitPathspec:MatchIndex", cleanupHandles)
          , baton(_baton) {};
        MatchIndexWorker(const MatchIndexWorker &) = delete;
        MatchIndexWorker(MatchIndexWorker &&) = delete;
        MatchIndexWorker &operator=(const MatchIndexWorker &) = delete;
        MatchIndexWorker &operator=(MatchIndexWorker &&) = delete;
        ~MatchIndexWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        MatchIndexBaton *baton;
    };
    Napi::Value MatchIndex(const Napi::CallbackInfo& info);
 
    struct MatchTreeBaton {
      int error_code;
      const git_error* error;
      git_pathspec_match_list * out;
      git_tree * tree;
      uint32_t flags;
      git_pathspec * ps;
     };
    class MatchTreeWorker : public nodegit::AsyncWorker {
      public:
        MatchTreeWorker(
            MatchTreeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitPathspec:MatchTree", cleanupHandles)
          , baton(_baton) {};
        MatchTreeWorker(const MatchTreeWorker &) = delete;
        MatchTreeWorker(MatchTreeWorker &&) = delete;
        MatchTreeWorker &operator=(const MatchTreeWorker &) = delete;
        MatchTreeWorker &operator=(MatchTreeWorker &&) = delete;
        ~MatchTreeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        MatchTreeBaton *baton;
    };
    Napi::Value MatchTree(const Napi::CallbackInfo& info);
 
    struct MatchWorkdirBaton {
      int error_code;
      const git_error* error;
      git_pathspec_match_list * out;
      git_repository * repo;
      uint32_t flags;
      git_pathspec * ps;
     };
    class MatchWorkdirWorker : public nodegit::AsyncWorker {
      public:
        MatchWorkdirWorker(
            MatchWorkdirBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitPathspec:MatchWorkdir", cleanupHandles)
          , baton(_baton) {};
        MatchWorkdirWorker(const MatchWorkdirWorker &) = delete;
        MatchWorkdirWorker(MatchWorkdirWorker &&) = delete;
        MatchWorkdirWorker &operator=(const MatchWorkdirWorker &) = delete;
        MatchWorkdirWorker &operator=(MatchWorkdirWorker &&) = delete;
        ~MatchWorkdirWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        MatchWorkdirBaton *baton;
    };
    Napi::Value MatchWorkdir(const Napi::CallbackInfo& info);
     Napi::Value MatchesPath(const Napi::CallbackInfo& info);
      static Napi::Value Create(const Napi::CallbackInfo& info);
 };

#endif
