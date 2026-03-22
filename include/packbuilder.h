// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITPACKBUILDER_H
#define GITPACKBUILDER_H
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
#include "../include/revwalk.h"
#include "../include/repository.h"
// Forward declaration.
struct git_packbuilder {
};
class GitPackbuilder;
 
struct GitPackbuilderTraits {
  typedef GitPackbuilder cppClass;
  typedef git_packbuilder cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_packbuilder **dest, git_packbuilder *src) {
     throw std::runtime_error("duplicate called on GitPackbuilder which cannot be duplicated");
   }

  static std::string className() { return "GitPackbuilder"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_packbuilder *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_packbuilder_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitPackbuilder : public
  NodeGitWrapper<GitPackbuilderTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitPackbuilderTraits>;
   public:
    GitPackbuilder(const GitPackbuilder &) = delete;
    GitPackbuilder(GitPackbuilder &&) = delete;
    GitPackbuilder &operator=(const GitPackbuilder &) = delete;
    GitPackbuilder &operator=(GitPackbuilder &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                               GitPackbuilder(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitPackbuilderTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitPackbuilder cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitPackbuilder();

  private:

    Napi::Value Hash(const Napi::CallbackInfo& info);
 
    struct InsertBaton {
      int error_code;
      const git_error* error;
      git_packbuilder * pb;
      const git_oid * id;
      bool idNeedsFree;
      const char * name;
     };
    class InsertWorker : public nodegit::AsyncWorker {
      public:
        InsertWorker(
            InsertBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitPackbuilder:Insert", cleanupHandles)
          , baton(_baton) {};
        InsertWorker(const InsertWorker &) = delete;
        InsertWorker(InsertWorker &&) = delete;
        InsertWorker &operator=(const InsertWorker &) = delete;
        InsertWorker &operator=(InsertWorker &&) = delete;
        ~InsertWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        InsertBaton *baton;
    };
    Napi::Value Insert(const Napi::CallbackInfo& info);
 
    struct InsertCommitBaton {
      int error_code;
      const git_error* error;
      git_packbuilder * pb;
      const git_oid * id;
      bool idNeedsFree;
     };
    class InsertCommitWorker : public nodegit::AsyncWorker {
      public:
        InsertCommitWorker(
            InsertCommitBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitPackbuilder:InsertCommit", cleanupHandles)
          , baton(_baton) {};
        InsertCommitWorker(const InsertCommitWorker &) = delete;
        InsertCommitWorker(InsertCommitWorker &&) = delete;
        InsertCommitWorker &operator=(const InsertCommitWorker &) = delete;
        InsertCommitWorker &operator=(InsertCommitWorker &&) = delete;
        ~InsertCommitWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        InsertCommitBaton *baton;
    };
    Napi::Value InsertCommit(const Napi::CallbackInfo& info);
 
    struct InsertRecurBaton {
      int error_code;
      const git_error* error;
      git_packbuilder * pb;
      const git_oid * id;
      bool idNeedsFree;
      const char * name;
     };
    class InsertRecurWorker : public nodegit::AsyncWorker {
      public:
        InsertRecurWorker(
            InsertRecurBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitPackbuilder:InsertRecur", cleanupHandles)
          , baton(_baton) {};
        InsertRecurWorker(const InsertRecurWorker &) = delete;
        InsertRecurWorker(InsertRecurWorker &&) = delete;
        InsertRecurWorker &operator=(const InsertRecurWorker &) = delete;
        InsertRecurWorker &operator=(InsertRecurWorker &&) = delete;
        ~InsertRecurWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        InsertRecurBaton *baton;
    };
    Napi::Value InsertRecur(const Napi::CallbackInfo& info);
     Napi::Value InsertTree(const Napi::CallbackInfo& info);
 
    struct InsertWalkBaton {
      int error_code;
      const git_error* error;
      git_packbuilder * pb;
      git_revwalk * walk;
     };
    class InsertWalkWorker : public nodegit::AsyncWorker {
      public:
        InsertWalkWorker(
            InsertWalkBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitPackbuilder:InsertWalk", cleanupHandles)
          , baton(_baton) {};
        InsertWalkWorker(const InsertWalkWorker &) = delete;
        InsertWalkWorker(InsertWalkWorker &&) = delete;
        InsertWalkWorker &operator=(const InsertWalkWorker &) = delete;
        InsertWalkWorker &operator=(InsertWalkWorker &&) = delete;
        ~InsertWalkWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        InsertWalkBaton *baton;
    };
    Napi::Value InsertWalk(const Napi::CallbackInfo& info);
     Napi::Value Name(const Napi::CallbackInfo& info);
      static Napi::Value Create(const Napi::CallbackInfo& info);
     Napi::Value ObjectCount(const Napi::CallbackInfo& info);
     Napi::Value SetThreads(const Napi::CallbackInfo& info);
     Napi::Value Written(const Napi::CallbackInfo& info);
 };

#endif
