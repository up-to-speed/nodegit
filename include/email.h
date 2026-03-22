// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITEMAIL_H
#define GITEMAIL_H
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
#include <git2/sys/email.h>
}

#include "../include/typedefs.h"

#include "../include/buf.h"
#include "../include/commit.h"
#include "../include/email_create_options.h"
#include "../include/diff.h"
#include "../include/oid.h"
#include "../include/signature.h"

class GitEmail : public
  Napi::ObjectWrap<GitEmail>
{
   public:
    GitEmail(const GitEmail &) = delete;
    GitEmail(GitEmail &&) = delete;
    GitEmail &operator=(const GitEmail &) = delete;
    GitEmail &operator=(GitEmail &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                 
  private:


    struct CreateFromCommitBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_commit * commit;
      const git_email_create_options * opts;
     };
    class CreateFromCommitWorker : public nodegit::AsyncWorker {
      public:
        CreateFromCommitWorker(
            CreateFromCommitBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitEmail:CreateFromCommit", cleanupHandles)
          , baton(_baton) {};
        CreateFromCommitWorker(const CreateFromCommitWorker &) = delete;
        CreateFromCommitWorker(CreateFromCommitWorker &&) = delete;
        CreateFromCommitWorker &operator=(const CreateFromCommitWorker &) = delete;
        CreateFromCommitWorker &operator=(CreateFromCommitWorker &&) = delete;
        ~CreateFromCommitWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateFromCommitBaton *baton;
    };
     static Napi::Value CreateFromCommit(const Napi::CallbackInfo& info);
 
    struct CreateFromDiffBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_diff * diff;
      size_t patch_idx;
      size_t patch_count;
      const git_oid * commit_id;
      bool commit_idNeedsFree;
      const char * summary;
      const char * body;
      const git_signature * author;
      git_email_create_options * opts;
     };
    class CreateFromDiffWorker : public nodegit::AsyncWorker {
      public:
        CreateFromDiffWorker(
            CreateFromDiffBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitEmail:CreateFromDiff", cleanupHandles)
          , baton(_baton) {};
        CreateFromDiffWorker(const CreateFromDiffWorker &) = delete;
        CreateFromDiffWorker(CreateFromDiffWorker &&) = delete;
        CreateFromDiffWorker &operator=(const CreateFromDiffWorker &) = delete;
        CreateFromDiffWorker &operator=(CreateFromDiffWorker &&) = delete;
        ~CreateFromDiffWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateFromDiffBaton *baton;
    };
     static Napi::Value CreateFromDiff(const Napi::CallbackInfo& info);
 };

#endif
