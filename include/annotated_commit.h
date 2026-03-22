// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITANNOTATEDCOMMIT_H
#define GITANNOTATEDCOMMIT_H
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

#include "../include/repository.h"
#include "../include/oid.h"
#include "../include/reference.h"
// Forward declaration.
struct git_annotated_commit {
};
class GitAnnotatedCommit;
 
struct GitAnnotatedCommitTraits {
  typedef GitAnnotatedCommit cppClass;
  typedef git_annotated_commit cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_annotated_commit **dest, git_annotated_commit *src) {
     throw std::runtime_error("duplicate called on GitAnnotatedCommit which cannot be duplicated");
   }

  static std::string className() { return "GitAnnotatedCommit"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_annotated_commit *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_annotated_commit_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitAnnotatedCommit : public
  NodeGitWrapper<GitAnnotatedCommitTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitAnnotatedCommitTraits>;
   public:
    GitAnnotatedCommit(const GitAnnotatedCommit &) = delete;
    GitAnnotatedCommit(GitAnnotatedCommit &&) = delete;
    GitAnnotatedCommit &operator=(const GitAnnotatedCommit &) = delete;
    GitAnnotatedCommit &operator=(GitAnnotatedCommit &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                 GitAnnotatedCommit(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitAnnotatedCommitTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitAnnotatedCommit cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitAnnotatedCommit();

  private:


    struct FromFetchheadBaton {
      int error_code;
      const git_error* error;
      git_annotated_commit * out;
      git_repository * repo;
      const char * branch_name;
      const char * remote_url;
      const git_oid * id;
      bool idNeedsFree;
     };
    class FromFetchheadWorker : public nodegit::AsyncWorker {
      public:
        FromFetchheadWorker(
            FromFetchheadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitAnnotatedCommit:FromFetchhead", cleanupHandles)
          , baton(_baton) {};
        FromFetchheadWorker(const FromFetchheadWorker &) = delete;
        FromFetchheadWorker(FromFetchheadWorker &&) = delete;
        FromFetchheadWorker &operator=(const FromFetchheadWorker &) = delete;
        FromFetchheadWorker &operator=(FromFetchheadWorker &&) = delete;
        ~FromFetchheadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FromFetchheadBaton *baton;
    };
     static Napi::Value FromFetchhead(const Napi::CallbackInfo& info);
 
    struct FromRefBaton {
      int error_code;
      const git_error* error;
      git_annotated_commit * out;
      git_repository * repo;
      const git_reference * ref;
     };
    class FromRefWorker : public nodegit::AsyncWorker {
      public:
        FromRefWorker(
            FromRefBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitAnnotatedCommit:FromRef", cleanupHandles)
          , baton(_baton) {};
        FromRefWorker(const FromRefWorker &) = delete;
        FromRefWorker(FromRefWorker &&) = delete;
        FromRefWorker &operator=(const FromRefWorker &) = delete;
        FromRefWorker &operator=(FromRefWorker &&) = delete;
        ~FromRefWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FromRefBaton *baton;
    };
     static Napi::Value FromRef(const Napi::CallbackInfo& info);
 
    struct FromRevspecBaton {
      int error_code;
      const git_error* error;
      git_annotated_commit * out;
      git_repository * repo;
      const char * revspec;
     };
    class FromRevspecWorker : public nodegit::AsyncWorker {
      public:
        FromRevspecWorker(
            FromRevspecBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitAnnotatedCommit:FromRevspec", cleanupHandles)
          , baton(_baton) {};
        FromRevspecWorker(const FromRevspecWorker &) = delete;
        FromRevspecWorker(FromRevspecWorker &&) = delete;
        FromRevspecWorker &operator=(const FromRevspecWorker &) = delete;
        FromRevspecWorker &operator=(FromRevspecWorker &&) = delete;
        ~FromRevspecWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FromRevspecBaton *baton;
    };
     static Napi::Value FromRevspec(const Napi::CallbackInfo& info);
     Napi::Value Id(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_annotated_commit * out;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
     };
    class LookupWorker : public nodegit::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitAnnotatedCommit:Lookup", cleanupHandles)
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
     Napi::Value Ref(const Napi::CallbackInfo& info);
 };

#endif
