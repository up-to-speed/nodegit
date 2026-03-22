// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREVWALK_H
#define GITREVWALK_H
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

#include "../include/commit.h"
#include "../include/functions/copy.h"
#include "../include/oid.h"
#include "../include/repository.h"
// Forward declaration.
struct git_revwalk {
};
class GitRevwalk;
 
struct GitRevwalkTraits {
  typedef GitRevwalk cppClass;
  typedef git_revwalk cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_revwalk **dest, git_revwalk *src) {
     throw std::runtime_error("duplicate called on GitRevwalk which cannot be duplicated");
   }

  static std::string className() { return "GitRevwalk"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_revwalk *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_revwalk_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRevwalk : public
  NodeGitWrapper<GitRevwalkTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRevwalkTraits>;
   public:
    GitRevwalk(const GitRevwalk &) = delete;
    GitRevwalk(GitRevwalk &&) = delete;
    GitRevwalk &operator=(const GitRevwalk &) = delete;
    GitRevwalk &operator=(GitRevwalk &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                             GitRevwalk(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRevwalkTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRevwalk cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRevwalk();

  private:

    Napi::Value Hide(const Napi::CallbackInfo& info);
     Napi::Value HideGlob(const Napi::CallbackInfo& info);
     Napi::Value HideHead(const Napi::CallbackInfo& info);
     Napi::Value HideRef(const Napi::CallbackInfo& info);
      static Napi::Value Create(const Napi::CallbackInfo& info);
 
    struct NextBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_revwalk * walk;
     };
    class NextWorker : public nodegit::AsyncWorker {
      public:
        NextWorker(
            NextBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRevwalk:Next", cleanupHandles)
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
     Napi::Value Push(const Napi::CallbackInfo& info);
     Napi::Value PushGlob(const Napi::CallbackInfo& info);
     Napi::Value PushHead(const Napi::CallbackInfo& info);
     Napi::Value PushRange(const Napi::CallbackInfo& info);
     Napi::Value PushRef(const Napi::CallbackInfo& info);
     Napi::Value Repository(const Napi::CallbackInfo& info);
     Napi::Value Reset(const Napi::CallbackInfo& info);
     Napi::Value SimplifyFirstParent(const Napi::CallbackInfo& info);
     Napi::Value Sorting(const Napi::CallbackInfo& info);
 
    struct CommitWalkBaton {
      int error_code;
      const git_error* error;
      int max_count;
      void * out;
      bool returnPlainObjects;
      git_revwalk * walk;
     };
    class CommitWalkWorker : public nodegit::AsyncWorker {
      public:
        CommitWalkWorker(
            CommitWalkBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRevwalk:CommitWalk", cleanupHandles)
          , baton(_baton) {};
        CommitWalkWorker(const CommitWalkWorker &) = delete;
        CommitWalkWorker(CommitWalkWorker &&) = delete;
        CommitWalkWorker &operator=(const CommitWalkWorker &) = delete;
        CommitWalkWorker &operator=(CommitWalkWorker &&) = delete;
        ~CommitWalkWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CommitWalkBaton *baton;
    };
    Napi::Value CommitWalk(const Napi::CallbackInfo& info);
 
    struct FastWalkBaton {
      int error_code;
      const git_error* error;
      int max_count;
      std::vector<git_oid*> * out;
      git_revwalk * walk;
     };
    class FastWalkWorker : public nodegit::AsyncWorker {
      public:
        FastWalkWorker(
            FastWalkBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRevwalk:FastWalk", cleanupHandles)
          , baton(_baton) {};
        FastWalkWorker(const FastWalkWorker &) = delete;
        FastWalkWorker(FastWalkWorker &&) = delete;
        FastWalkWorker &operator=(const FastWalkWorker &) = delete;
        FastWalkWorker &operator=(FastWalkWorker &&) = delete;
        ~FastWalkWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FastWalkBaton *baton;
    };
    Napi::Value FastWalk(const Napi::CallbackInfo& info);
 
    struct FileHistoryWalkBaton {
      int error_code;
      const git_error* error;
      const char * file_path;
      unsigned int max_count;
      std::vector<void *> * out;
      git_revwalk * walk;
     };
    class FileHistoryWalkWorker : public nodegit::AsyncWorker {
      public:
        FileHistoryWalkWorker(
            FileHistoryWalkBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRevwalk:FileHistoryWalk", cleanupHandles)
          , baton(_baton) {};
        FileHistoryWalkWorker(const FileHistoryWalkWorker &) = delete;
        FileHistoryWalkWorker(FileHistoryWalkWorker &&) = delete;
        FileHistoryWalkWorker &operator=(const FileHistoryWalkWorker &) = delete;
        FileHistoryWalkWorker &operator=(FileHistoryWalkWorker &&) = delete;
        ~FileHistoryWalkWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FileHistoryWalkBaton *baton;
    };
    Napi::Value FileHistoryWalk(const Napi::CallbackInfo& info);
 };

#endif
