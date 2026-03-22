// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREBASE_H
#define GITREBASE_H
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
#include "../include/repository.h"
#include "../include/annotated_commit.h"
#include "../include/rebase_options.h"
#include "../include/index.h"
#include "../include/rebase_operation.h"
// Forward declaration.
struct git_rebase {
};
class GitRebase;
 
struct GitRebaseTraits {
  typedef GitRebase cppClass;
  typedef git_rebase cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_rebase **dest, git_rebase *src) {
     throw std::runtime_error("duplicate called on GitRebase which cannot be duplicated");
   }

  static std::string className() { return "GitRebase"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_rebase *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_rebase_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRebase : public
  NodeGitWrapper<GitRebaseTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRebaseTraits>;
   public:
    GitRebase(const GitRebase &) = delete;
    GitRebase(GitRebase &&) = delete;
    GitRebase &operator=(const GitRebase &) = delete;
    GitRebase &operator=(GitRebase &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                               GitRebase(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRebaseTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRebase cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRebase();

  private:


    struct AbortBaton {
      int error_code;
      const git_error* error;
      git_rebase * rebase;
     };
    class AbortWorker : public nodegit::AsyncWorker {
      public:
        AbortWorker(
            AbortBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRebase:Abort", cleanupHandles)
          , baton(_baton) {};
        AbortWorker(const AbortWorker &) = delete;
        AbortWorker(AbortWorker &&) = delete;
        AbortWorker &operator=(const AbortWorker &) = delete;
        AbortWorker &operator=(AbortWorker &&) = delete;
        ~AbortWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AbortBaton *baton;
    };
    Napi::Value Abort(const Napi::CallbackInfo& info);
 
    struct CommitBaton {
      int error_code;
      const git_error* error;
      git_oid * id;
      git_rebase * rebase;
      const git_signature * author;
      const git_signature * committer;
      const char * message_encoding;
      const char * message;
     };
    class CommitWorker : public nodegit::AsyncWorker {
      public:
        CommitWorker(
            CommitBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRebase:Commit", cleanupHandles)
          , baton(_baton) {};
        CommitWorker(const CommitWorker &) = delete;
        CommitWorker(CommitWorker &&) = delete;
        CommitWorker &operator=(const CommitWorker &) = delete;
        CommitWorker &operator=(CommitWorker &&) = delete;
        ~CommitWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CommitBaton *baton;
    };
    Napi::Value Commit(const Napi::CallbackInfo& info);
     Napi::Value Finish(const Napi::CallbackInfo& info);
 
    struct InitBaton {
      int error_code;
      const git_error* error;
      git_rebase * out;
      git_repository * repo;
      const git_annotated_commit * branch;
      const git_annotated_commit * upstream;
      const git_annotated_commit * onto;
      const git_rebase_options * opts;
     };
    class InitWorker : public nodegit::AsyncWorker {
      public:
        InitWorker(
            InitBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRebase:Init", cleanupHandles)
          , baton(_baton) {};
        InitWorker(const InitWorker &) = delete;
        InitWorker(InitWorker &&) = delete;
        InitWorker &operator=(const InitWorker &) = delete;
        InitWorker &operator=(InitWorker &&) = delete;
        ~InitWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        InitBaton *baton;
    };
     static Napi::Value Init(const Napi::CallbackInfo& info);
     Napi::Value InmemoryIndex(const Napi::CallbackInfo& info);
 
    struct NextBaton {
      int error_code;
      const git_error* error;
      git_rebase_operation * operation;
      git_rebase * rebase;
     };
    class NextWorker : public nodegit::AsyncWorker {
      public:
        NextWorker(
            NextBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRebase:Next", cleanupHandles)
          , baton(_baton) {};
        NextWorker(const NextWorker &) = delete;
        NextWorker(NextWorker &&) = delete;
        NextWorker &operator=(const NextWorker &) = delete;
        NextWorker &operator=(NextWorker &&) = delete;
        ~NextWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        NextBaton *baton;
    };
    Napi::Value Next(const Napi::CallbackInfo& info);
     Napi::Value OntoId(const Napi::CallbackInfo& info);
     Napi::Value OntoName(const Napi::CallbackInfo& info);
 
    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_rebase * out;
      git_repository * repo;
      const git_rebase_options * opts;
     };
    class OpenWorker : public nodegit::AsyncWorker {
      public:
        OpenWorker(
            OpenBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRebase:Open", cleanupHandles)
          , baton(_baton) {};
        OpenWorker(const OpenWorker &) = delete;
        OpenWorker(OpenWorker &&) = delete;
        OpenWorker &operator=(const OpenWorker &) = delete;
        OpenWorker &operator=(OpenWorker &&) = delete;
        ~OpenWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OpenBaton *baton;
    };
     static Napi::Value Open(const Napi::CallbackInfo& info);
     Napi::Value OperationByindex(const Napi::CallbackInfo& info);
     Napi::Value OperationCurrent(const Napi::CallbackInfo& info);
     Napi::Value OperationEntrycount(const Napi::CallbackInfo& info);
     Napi::Value OrigHeadId(const Napi::CallbackInfo& info);
     Napi::Value OrigHeadName(const Napi::CallbackInfo& info);
 };

#endif
