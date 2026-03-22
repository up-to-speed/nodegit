// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITBRANCH_H
#define GITBRANCH_H
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

#include "../include/buf.h"
#include "../include/reference.h"
#include "../include/repository.h"
#include "../include/commit.h"
#include "../include/annotated_commit.h"
#include "../include/buf.h"

class GitBranch : public
  Napi::ObjectWrap<GitBranch>
{
   public:
    GitBranch(const GitBranch &) = delete;
    GitBranch(GitBranch &&) = delete;
    GitBranch &operator=(const GitBranch &) = delete;
    GitBranch &operator=(GitBranch &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                        
  private:


    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * branch_name;
      const git_commit * target;
      int force;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBranch:Create", cleanupHandles)
          , baton(_baton) {};
        CreateWorker(const CreateWorker &) = delete;
        CreateWorker(CreateWorker &&) = delete;
        CreateWorker &operator=(const CreateWorker &) = delete;
        CreateWorker &operator=(CreateWorker &&) = delete;
        ~CreateWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateBaton *baton;
    };
     static Napi::Value Create(const Napi::CallbackInfo& info);
 
    struct CreateFromAnnotatedBaton {
      int error_code;
      const git_error* error;
      git_reference * ref_out;
      git_repository * repo;
      const char * branch_name;
      const git_annotated_commit * target;
      int force;
     };
    class CreateFromAnnotatedWorker : public nodegit::AsyncWorker {
      public:
        CreateFromAnnotatedWorker(
            CreateFromAnnotatedBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBranch:CreateFromAnnotated", cleanupHandles)
          , baton(_baton) {};
        CreateFromAnnotatedWorker(const CreateFromAnnotatedWorker &) = delete;
        CreateFromAnnotatedWorker(CreateFromAnnotatedWorker &&) = delete;
        CreateFromAnnotatedWorker &operator=(const CreateFromAnnotatedWorker &) = delete;
        CreateFromAnnotatedWorker &operator=(CreateFromAnnotatedWorker &&) = delete;
        ~CreateFromAnnotatedWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateFromAnnotatedBaton *baton;
    };
     static Napi::Value CreateFromAnnotated(const Napi::CallbackInfo& info);
      static Napi::Value Delete(const Napi::CallbackInfo& info);
      static Napi::Value IsCheckedOut(const Napi::CallbackInfo& info);
      static Napi::Value IsHead(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * branch_name;
      git_branch_t branch_type;
     };
    class LookupWorker : public nodegit::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBranch:Lookup", cleanupHandles)
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
 
    struct MoveBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_reference * branch;
      const char * new_branch_name;
      int force;
     };
    class MoveWorker : public nodegit::AsyncWorker {
      public:
        MoveWorker(
            MoveBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBranch:Move", cleanupHandles)
          , baton(_baton) {};
        MoveWorker(const MoveWorker &) = delete;
        MoveWorker(MoveWorker &&) = delete;
        MoveWorker &operator=(const MoveWorker &) = delete;
        MoveWorker &operator=(MoveWorker &&) = delete;
        ~MoveWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        MoveBaton *baton;
    };
     static Napi::Value Move(const Napi::CallbackInfo& info);
 
    struct NameBaton {
      int error_code;
      const git_error* error;
      const char * out;
      const git_reference * ref;
     };
    class NameWorker : public nodegit::AsyncWorker {
      public:
        NameWorker(
            NameBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBranch:Name", cleanupHandles)
          , baton(_baton) {};
        NameWorker(const NameWorker &) = delete;
        NameWorker(NameWorker &&) = delete;
        NameWorker &operator=(const NameWorker &) = delete;
        NameWorker &operator=(NameWorker &&) = delete;
        ~NameWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        NameBaton *baton;
    };
     static Napi::Value Name(const Napi::CallbackInfo& info);
      static Napi::Value NameIsValid(const Napi::CallbackInfo& info);
 
    struct RemoteNameBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_repository * repo;
      const char * refname;
     };
    class RemoteNameWorker : public nodegit::AsyncWorker {
      public:
        RemoteNameWorker(
            RemoteNameBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBranch:RemoteName", cleanupHandles)
          , baton(_baton) {};
        RemoteNameWorker(const RemoteNameWorker &) = delete;
        RemoteNameWorker(RemoteNameWorker &&) = delete;
        RemoteNameWorker &operator=(const RemoteNameWorker &) = delete;
        RemoteNameWorker &operator=(RemoteNameWorker &&) = delete;
        ~RemoteNameWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RemoteNameBaton *baton;
    };
     static Napi::Value RemoteName(const Napi::CallbackInfo& info);
 
    struct SetUpstreamBaton {
      int error_code;
      const git_error* error;
      git_reference * branch;
      const char * branch_name;
     };
    class SetUpstreamWorker : public nodegit::AsyncWorker {
      public:
        SetUpstreamWorker(
            SetUpstreamBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBranch:SetUpstream", cleanupHandles)
          , baton(_baton) {};
        SetUpstreamWorker(const SetUpstreamWorker &) = delete;
        SetUpstreamWorker(SetUpstreamWorker &&) = delete;
        SetUpstreamWorker &operator=(const SetUpstreamWorker &) = delete;
        SetUpstreamWorker &operator=(SetUpstreamWorker &&) = delete;
        ~SetUpstreamWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetUpstreamBaton *baton;
    };
     static Napi::Value SetUpstream(const Napi::CallbackInfo& info);
 
    struct UpstreamBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      const git_reference * branch;
     };
    class UpstreamWorker : public nodegit::AsyncWorker {
      public:
        UpstreamWorker(
            UpstreamBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBranch:Upstream", cleanupHandles)
          , baton(_baton) {};
        UpstreamWorker(const UpstreamWorker &) = delete;
        UpstreamWorker(UpstreamWorker &&) = delete;
        UpstreamWorker &operator=(const UpstreamWorker &) = delete;
        UpstreamWorker &operator=(UpstreamWorker &&) = delete;
        ~UpstreamWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        UpstreamBaton *baton;
    };
     static Napi::Value Upstream(const Napi::CallbackInfo& info);
      static Napi::Value UpstreamMerge(const Napi::CallbackInfo& info);
 
    struct UpstreamNameBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_repository * repo;
      const char * refname;
     };
    class UpstreamNameWorker : public nodegit::AsyncWorker {
      public:
        UpstreamNameWorker(
            UpstreamNameBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBranch:UpstreamName", cleanupHandles)
          , baton(_baton) {};
        UpstreamNameWorker(const UpstreamNameWorker &) = delete;
        UpstreamNameWorker(UpstreamNameWorker &&) = delete;
        UpstreamNameWorker &operator=(const UpstreamNameWorker &) = delete;
        UpstreamNameWorker &operator=(UpstreamNameWorker &&) = delete;
        ~UpstreamNameWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        UpstreamNameBaton *baton;
    };
     static Napi::Value UpstreamName(const Napi::CallbackInfo& info);
      static Napi::Value UpstreamRemote(const Napi::CallbackInfo& info);
 };

#endif
