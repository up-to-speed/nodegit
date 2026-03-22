// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITWORKTREE_H
#define GITWORKTREE_H
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

#include "../include/git_buf_converter.h"
#include "../include/repository.h"
#include "../include/worktree_add_options.h"
#include "../include/buf.h"
#include "../include/worktree_prune_options.h"
#include "../include/strarray.h"
// Forward declaration.
struct git_worktree {
};
class GitWorktree;
 
struct GitWorktreeTraits {
  typedef GitWorktree cppClass;
  typedef git_worktree cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_worktree **dest, git_worktree *src) {
     throw std::runtime_error("duplicate called on GitWorktree which cannot be duplicated");
   }

  static std::string className() { return "GitWorktree"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_worktree *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_worktree_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitWorktree : public
  NodeGitWrapper<GitWorktreeTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitWorktreeTraits>;
   public:
    GitWorktree(const GitWorktree &) = delete;
    GitWorktree(GitWorktree &&) = delete;
    GitWorktree &operator=(const GitWorktree &) = delete;
    GitWorktree &operator=(GitWorktree &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                     GitWorktree(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitWorktreeTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitWorktree cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitWorktree();

  private:


    struct AddBaton {
      int error_code;
      const git_error* error;
      git_worktree * out;
      git_repository * repo;
      const char * name;
      const char * path;
      const git_worktree_add_options * opts;
     };
    class AddWorker : public nodegit::AsyncWorker {
      public:
        AddWorker(
            AddBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitWorktree:Add", cleanupHandles)
          , baton(_baton) {};
        AddWorker(const AddWorker &) = delete;
        AddWorker(AddWorker &&) = delete;
        AddWorker &operator=(const AddWorker &) = delete;
        AddWorker &operator=(AddWorker &&) = delete;
        ~AddWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddBaton *baton;
    };
     static Napi::Value Add(const Napi::CallbackInfo& info);
     Napi::Value IsLocked(const Napi::CallbackInfo& info);
 
    struct IsPrunableBaton {
      int error_code;
      const git_error* error;
      git_worktree * wt;
      git_worktree_prune_options * opts;
        int result;
     };
    class IsPrunableWorker : public nodegit::AsyncWorker {
      public:
        IsPrunableWorker(
            IsPrunableBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitWorktree:IsPrunable", cleanupHandles)
          , baton(_baton) {};
        IsPrunableWorker(const IsPrunableWorker &) = delete;
        IsPrunableWorker(IsPrunableWorker &&) = delete;
        IsPrunableWorker &operator=(const IsPrunableWorker &) = delete;
        IsPrunableWorker &operator=(IsPrunableWorker &&) = delete;
        ~IsPrunableWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        IsPrunableBaton *baton;
    };
    Napi::Value IsPrunable(const Napi::CallbackInfo& info);
 
    struct ListBaton {
      int error_code;
      const git_error* error;
      git_strarray * out;
      git_repository * repo;
     };
    class ListWorker : public nodegit::AsyncWorker {
      public:
        ListWorker(
            ListBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitWorktree:List", cleanupHandles)
          , baton(_baton) {};
        ListWorker(const ListWorker &) = delete;
        ListWorker(ListWorker &&) = delete;
        ListWorker &operator=(const ListWorker &) = delete;
        ListWorker &operator=(ListWorker &&) = delete;
        ~ListWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ListBaton *baton;
    };
     static Napi::Value List(const Napi::CallbackInfo& info);
     Napi::Value Lock(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_worktree * out;
      git_repository * repo;
      const char * name;
     };
    class LookupWorker : public nodegit::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitWorktree:Lookup", cleanupHandles)
          , baton(_baton) {};
        LookupWorker(const LookupWorker &) = delete;
        LookupWorker(LookupWorker &&) = delete;
        LookupWorker &operator=(const LookupWorker &) = delete;
        LookupWorker &operator=(LookupWorker &&) = delete;
        ~LookupWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        LookupBaton *baton;
    };
     static Napi::Value Lookup(const Napi::CallbackInfo& info);
     Napi::Value Name(const Napi::CallbackInfo& info);
 
    struct OpenFromRepositoryBaton {
      int error_code;
      const git_error* error;
      git_worktree * out;
      git_repository * repo;
     };
    class OpenFromRepositoryWorker : public nodegit::AsyncWorker {
      public:
        OpenFromRepositoryWorker(
            OpenFromRepositoryBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitWorktree:OpenFromRepository", cleanupHandles)
          , baton(_baton) {};
        OpenFromRepositoryWorker(const OpenFromRepositoryWorker &) = delete;
        OpenFromRepositoryWorker(OpenFromRepositoryWorker &&) = delete;
        OpenFromRepositoryWorker &operator=(const OpenFromRepositoryWorker &) = delete;
        OpenFromRepositoryWorker &operator=(OpenFromRepositoryWorker &&) = delete;
        ~OpenFromRepositoryWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OpenFromRepositoryBaton *baton;
    };
     static Napi::Value OpenFromRepository(const Napi::CallbackInfo& info);
     Napi::Value Path(const Napi::CallbackInfo& info);
 
    struct PruneBaton {
      int error_code;
      const git_error* error;
      git_worktree * wt;
      git_worktree_prune_options * opts;
     };
    class PruneWorker : public nodegit::AsyncWorker {
      public:
        PruneWorker(
            PruneBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitWorktree:Prune", cleanupHandles)
          , baton(_baton) {};
        PruneWorker(const PruneWorker &) = delete;
        PruneWorker(PruneWorker &&) = delete;
        PruneWorker &operator=(const PruneWorker &) = delete;
        PruneWorker &operator=(PruneWorker &&) = delete;
        ~PruneWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        PruneBaton *baton;
    };
    Napi::Value Prune(const Napi::CallbackInfo& info);
     Napi::Value Unlock(const Napi::CallbackInfo& info);
     Napi::Value Validate(const Napi::CallbackInfo& info);
 };

#endif
