// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREVERT_H
#define GITREVERT_H
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
#include "../include/commit.h"
#include "../include/revert_options.h"
#include "../include/index.h"
#include "../include/merge_options.h"

class GitRevert : public
  Napi::ObjectWrap<GitRevert>
{
   public:
    GitRevert(const GitRevert &) = delete;
    GitRevert(GitRevert &&) = delete;
    GitRevert &operator=(const GitRevert &) = delete;
    GitRevert &operator=(GitRevert &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

              
  private:


    struct RevertBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_commit * commit;
      const git_revert_options * given_opts;
     };
    class RevertWorker : public nodegit::AsyncWorker {
      public:
        RevertWorker(
            RevertBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRevert:Revert", cleanupHandles)
          , baton(_baton) {};
        RevertWorker(const RevertWorker &) = delete;
        RevertWorker(RevertWorker &&) = delete;
        RevertWorker &operator=(const RevertWorker &) = delete;
        RevertWorker &operator=(RevertWorker &&) = delete;
        ~RevertWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RevertBaton *baton;
    };
     static Napi::Value Revert(const Napi::CallbackInfo& info);
 
    struct CommitBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      git_repository * repo;
      git_commit * revert_commit;
      git_commit * our_commit;
      unsigned int mainline;
      const git_merge_options * merge_options;
     };
    class CommitWorker : public nodegit::AsyncWorker {
      public:
        CommitWorker(
            CommitBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRevert:Commit", cleanupHandles)
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
     static Napi::Value Commit(const Napi::CallbackInfo& info);
 };

#endif
