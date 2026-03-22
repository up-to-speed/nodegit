// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREMOTE_H
#define GITREMOTE_H
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
#include "../include/remote_head.h"
#include "../include/repository.h"
#include "../include/remote_callbacks.h"
#include "../include/proxy_options.h"
#include "../include/strarray.h"
#include "../include/remote_connect_options.h"
#include "../include/remote_create_options.h"
#include "../include/buf.h"
#include "../include/fetch_options.h"
#include "../include/refspec.h"
#include "../include/push_options.h"
#include "../include/indexer_progress.h"
// Forward declaration.
struct git_remote {
};
class GitRemote;
 
struct GitRemoteTraits {
  typedef GitRemote cppClass;
  typedef git_remote cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_remote **dest, git_remote *src) {
     throw std::runtime_error("duplicate called on GitRemote which cannot be duplicated");
   }

  static std::string className() { return "GitRemote"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_remote *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_remote_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRemote : public
  NodeGitWrapper<GitRemoteTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRemoteTraits>;
   public:
    GitRemote(const GitRemote &) = delete;
    GitRemote(GitRemote &&) = delete;
    GitRemote &operator=(const GitRemote &) = delete;
    GitRemote &operator=(GitRemote &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                                                                                                                                                GitRemote(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRemoteTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRemote cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRemote();

  private:

     static Napi::Value AddFetch(const Napi::CallbackInfo& info);
      static Napi::Value AddPush(const Napi::CallbackInfo& info);
     Napi::Value Autotag(const Napi::CallbackInfo& info);
 
    struct ConnectBaton {
      int error_code;
      const git_error* error;
      git_remote * remote;
      git_direction direction;
      const git_remote_callbacks * callbacks;
      const git_proxy_options * proxy_opts;
      const git_strarray * custom_headers;
     };
    class ConnectWorker : public nodegit::AsyncWorker {
      public:
        ConnectWorker(
            ConnectBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Connect", cleanupHandles)
          , baton(_baton) {};
        ConnectWorker(const ConnectWorker &) = delete;
        ConnectWorker(ConnectWorker &&) = delete;
        ConnectWorker &operator=(const ConnectWorker &) = delete;
        ConnectWorker &operator=(ConnectWorker &&) = delete;
        ~ConnectWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ConnectBaton *baton;
    };
    Napi::Value Connect(const Napi::CallbackInfo& info);
 
    struct ConnectExtBaton {
      int error_code;
      const git_error* error;
      git_remote * remote;
      git_direction direction;
      const git_remote_connect_options * opts;
        int result;
     };
    class ConnectExtWorker : public nodegit::AsyncWorker {
      public:
        ConnectExtWorker(
            ConnectExtBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:ConnectExt", cleanupHandles)
          , baton(_baton) {};
        ConnectExtWorker(const ConnectExtWorker &) = delete;
        ConnectExtWorker(ConnectExtWorker &&) = delete;
        ConnectExtWorker &operator=(const ConnectExtWorker &) = delete;
        ConnectExtWorker &operator=(ConnectExtWorker &&) = delete;
        ~ConnectExtWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ConnectExtBaton *baton;
    };
    Napi::Value ConnectExt(const Napi::CallbackInfo& info);
     Napi::Value Connected(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_remote * out;
      git_repository * repo;
      const char * name;
      const char * url;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Create", cleanupHandles)
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
 
    struct CreateAnonymousBaton {
      int error_code;
      const git_error* error;
      git_remote * out;
      git_repository * repo;
      const char * url;
     };
    class CreateAnonymousWorker : public nodegit::AsyncWorker {
      public:
        CreateAnonymousWorker(
            CreateAnonymousBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:CreateAnonymous", cleanupHandles)
          , baton(_baton) {};
        CreateAnonymousWorker(const CreateAnonymousWorker &) = delete;
        CreateAnonymousWorker(CreateAnonymousWorker &&) = delete;
        CreateAnonymousWorker &operator=(const CreateAnonymousWorker &) = delete;
        CreateAnonymousWorker &operator=(CreateAnonymousWorker &&) = delete;
        ~CreateAnonymousWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateAnonymousBaton *baton;
    };
     static Napi::Value CreateAnonymous(const Napi::CallbackInfo& info);
 
    struct CreateDetachedBaton {
      int error_code;
      const git_error* error;
      git_remote * out;
      const char * url;
     };
    class CreateDetachedWorker : public nodegit::AsyncWorker {
      public:
        CreateDetachedWorker(
            CreateDetachedBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:CreateDetached", cleanupHandles)
          , baton(_baton) {};
        CreateDetachedWorker(const CreateDetachedWorker &) = delete;
        CreateDetachedWorker(CreateDetachedWorker &&) = delete;
        CreateDetachedWorker &operator=(const CreateDetachedWorker &) = delete;
        CreateDetachedWorker &operator=(CreateDetachedWorker &&) = delete;
        ~CreateDetachedWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateDetachedBaton *baton;
    };
     static Napi::Value CreateDetached(const Napi::CallbackInfo& info);
 
    struct CreateWithFetchspecBaton {
      int error_code;
      const git_error* error;
      git_remote * out;
      git_repository * repo;
      const char * name;
      const char * url;
      const char * fetch;
     };
    class CreateWithFetchspecWorker : public nodegit::AsyncWorker {
      public:
        CreateWithFetchspecWorker(
            CreateWithFetchspecBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:CreateWithFetchspec", cleanupHandles)
          , baton(_baton) {};
        CreateWithFetchspecWorker(const CreateWithFetchspecWorker &) = delete;
        CreateWithFetchspecWorker(CreateWithFetchspecWorker &&) = delete;
        CreateWithFetchspecWorker &operator=(const CreateWithFetchspecWorker &) = delete;
        CreateWithFetchspecWorker &operator=(CreateWithFetchspecWorker &&) = delete;
        ~CreateWithFetchspecWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateWithFetchspecBaton *baton;
    };
     static Napi::Value CreateWithFetchspec(const Napi::CallbackInfo& info);
 
    struct CreateWithOptsBaton {
      int error_code;
      const git_error* error;
      git_remote * out;
      const char * url;
      const git_remote_create_options * opts;
     };
    class CreateWithOptsWorker : public nodegit::AsyncWorker {
      public:
        CreateWithOptsWorker(
            CreateWithOptsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:CreateWithOpts", cleanupHandles)
          , baton(_baton) {};
        CreateWithOptsWorker(const CreateWithOptsWorker &) = delete;
        CreateWithOptsWorker(CreateWithOptsWorker &&) = delete;
        CreateWithOptsWorker &operator=(const CreateWithOptsWorker &) = delete;
        CreateWithOptsWorker &operator=(CreateWithOptsWorker &&) = delete;
        ~CreateWithOptsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateWithOptsBaton *baton;
    };
     static Napi::Value CreateWithOpts(const Napi::CallbackInfo& info);
 
    struct DefaultBranchBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_remote * remote;
     };
    class DefaultBranchWorker : public nodegit::AsyncWorker {
      public:
        DefaultBranchWorker(
            DefaultBranchBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:DefaultBranch", cleanupHandles)
          , baton(_baton) {};
        DefaultBranchWorker(const DefaultBranchWorker &) = delete;
        DefaultBranchWorker(DefaultBranchWorker &&) = delete;
        DefaultBranchWorker &operator=(const DefaultBranchWorker &) = delete;
        DefaultBranchWorker &operator=(DefaultBranchWorker &&) = delete;
        ~DefaultBranchWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DefaultBranchBaton *baton;
    };
    Napi::Value DefaultBranch(const Napi::CallbackInfo& info);
 
    struct DeleteBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * name;
     };
    class DeleteWorker : public nodegit::AsyncWorker {
      public:
        DeleteWorker(
            DeleteBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Delete", cleanupHandles)
          , baton(_baton) {};
        DeleteWorker(const DeleteWorker &) = delete;
        DeleteWorker(DeleteWorker &&) = delete;
        DeleteWorker &operator=(const DeleteWorker &) = delete;
        DeleteWorker &operator=(DeleteWorker &&) = delete;
        ~DeleteWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DeleteBaton *baton;
    };
     static Napi::Value Delete(const Napi::CallbackInfo& info);
 
    struct DisconnectBaton {
      int error_code;
      const git_error* error;
      git_remote * remote;
     };
    class DisconnectWorker : public nodegit::AsyncWorker {
      public:
        DisconnectWorker(
            DisconnectBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Disconnect", cleanupHandles)
          , baton(_baton) {};
        DisconnectWorker(const DisconnectWorker &) = delete;
        DisconnectWorker(DisconnectWorker &&) = delete;
        DisconnectWorker &operator=(const DisconnectWorker &) = delete;
        DisconnectWorker &operator=(DisconnectWorker &&) = delete;
        ~DisconnectWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DisconnectBaton *baton;
    };
    Napi::Value Disconnect(const Napi::CallbackInfo& info);
 
    struct DownloadBaton {
      int error_code;
      const git_error* error;
      git_remote * remote;
      const git_strarray * refspecs;
      const git_fetch_options * opts;
     };
    class DownloadWorker : public nodegit::AsyncWorker {
      public:
        DownloadWorker(
            DownloadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Download", cleanupHandles)
          , baton(_baton) {};
        DownloadWorker(const DownloadWorker &) = delete;
        DownloadWorker(DownloadWorker &&) = delete;
        DownloadWorker &operator=(const DownloadWorker &) = delete;
        DownloadWorker &operator=(DownloadWorker &&) = delete;
        ~DownloadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DownloadBaton *baton;
    };
    Napi::Value Download(const Napi::CallbackInfo& info);
 
    struct DupBaton {
      int error_code;
      const git_error* error;
      git_remote * dest;
      git_remote * source;
     };
    class DupWorker : public nodegit::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Dup", cleanupHandles)
          , baton(_baton) {};
        DupWorker(const DupWorker &) = delete;
        DupWorker(DupWorker &&) = delete;
        DupWorker &operator=(const DupWorker &) = delete;
        DupWorker &operator=(DupWorker &&) = delete;
        ~DupWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DupBaton *baton;
    };
    Napi::Value Dup(const Napi::CallbackInfo& info);
 
    struct FetchBaton {
      int error_code;
      const git_error* error;
      git_remote * remote;
      const git_strarray * refspecs;
      const git_fetch_options * opts;
      const char * reflog_message;
     };
    class FetchWorker : public nodegit::AsyncWorker {
      public:
        FetchWorker(
            FetchBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Fetch", cleanupHandles)
          , baton(_baton) {};
        FetchWorker(const FetchWorker &) = delete;
        FetchWorker(FetchWorker &&) = delete;
        FetchWorker &operator=(const FetchWorker &) = delete;
        FetchWorker &operator=(FetchWorker &&) = delete;
        ~FetchWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FetchBaton *baton;
    };
    Napi::Value Fetch(const Napi::CallbackInfo& info);
 
    struct GetFetchRefspecsBaton {
      int error_code;
      const git_error* error;
      git_strarray * array;
      const git_remote * remote;
     };
    class GetFetchRefspecsWorker : public nodegit::AsyncWorker {
      public:
        GetFetchRefspecsWorker(
            GetFetchRefspecsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:GetFetchRefspecs", cleanupHandles)
          , baton(_baton) {};
        GetFetchRefspecsWorker(const GetFetchRefspecsWorker &) = delete;
        GetFetchRefspecsWorker(GetFetchRefspecsWorker &&) = delete;
        GetFetchRefspecsWorker &operator=(const GetFetchRefspecsWorker &) = delete;
        GetFetchRefspecsWorker &operator=(GetFetchRefspecsWorker &&) = delete;
        ~GetFetchRefspecsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetFetchRefspecsBaton *baton;
    };
    Napi::Value GetFetchRefspecs(const Napi::CallbackInfo& info);
 
    struct GetPushRefspecsBaton {
      int error_code;
      const git_error* error;
      git_strarray * array;
      const git_remote * remote;
     };
    class GetPushRefspecsWorker : public nodegit::AsyncWorker {
      public:
        GetPushRefspecsWorker(
            GetPushRefspecsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:GetPushRefspecs", cleanupHandles)
          , baton(_baton) {};
        GetPushRefspecsWorker(const GetPushRefspecsWorker &) = delete;
        GetPushRefspecsWorker(GetPushRefspecsWorker &&) = delete;
        GetPushRefspecsWorker &operator=(const GetPushRefspecsWorker &) = delete;
        GetPushRefspecsWorker &operator=(GetPushRefspecsWorker &&) = delete;
        ~GetPushRefspecsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetPushRefspecsBaton *baton;
    };
    Napi::Value GetPushRefspecs(const Napi::CallbackInfo& info);
     Napi::Value GetRefspec(const Napi::CallbackInfo& info);
      static Napi::Value IsValidName(const Napi::CallbackInfo& info);
 
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
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:List", cleanupHandles)
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
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_remote * out;
      git_repository * repo;
      const char * name;
     };
    class LookupWorker : public nodegit::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Lookup", cleanupHandles)
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
      static Napi::Value NameIsValid(const Napi::CallbackInfo& info);
     Napi::Value Owner(const Napi::CallbackInfo& info);
 
    struct PruneBaton {
      int error_code;
      const git_error* error;
      git_remote * remote;
      const git_remote_callbacks * callbacks;
     };
    class PruneWorker : public nodegit::AsyncWorker {
      public:
        PruneWorker(
            PruneBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Prune", cleanupHandles)
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
     Napi::Value PruneRefs(const Napi::CallbackInfo& info);
 
    struct PushBaton {
      int error_code;
      const git_error* error;
      git_remote * remote;
      const git_strarray * refspecs;
      const git_push_options * opts;
     };
    class PushWorker : public nodegit::AsyncWorker {
      public:
        PushWorker(
            PushBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Push", cleanupHandles)
          , baton(_baton) {};
        PushWorker(const PushWorker &) = delete;
        PushWorker(PushWorker &&) = delete;
        PushWorker &operator=(const PushWorker &) = delete;
        PushWorker &operator=(PushWorker &&) = delete;
        ~PushWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        PushBaton *baton;
    };
    Napi::Value Push(const Napi::CallbackInfo& info);
     Napi::Value Pushurl(const Napi::CallbackInfo& info);
     Napi::Value RefspecCount(const Napi::CallbackInfo& info);
 
    struct RenameBaton {
      int error_code;
      const git_error* error;
      git_strarray * problems;
      git_repository * repo;
      const char * name;
      const char * new_name;
     };
    class RenameWorker : public nodegit::AsyncWorker {
      public:
        RenameWorker(
            RenameBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Rename", cleanupHandles)
          , baton(_baton) {};
        RenameWorker(const RenameWorker &) = delete;
        RenameWorker(RenameWorker &&) = delete;
        RenameWorker &operator=(const RenameWorker &) = delete;
        RenameWorker &operator=(RenameWorker &&) = delete;
        ~RenameWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RenameBaton *baton;
    };
     static Napi::Value Rename(const Napi::CallbackInfo& info);
      static Napi::Value SetAutotag(const Napi::CallbackInfo& info);
     Napi::Value SetInstancePushurl(const Napi::CallbackInfo& info);
     Napi::Value SetInstanceUrl(const Napi::CallbackInfo& info);
      static Napi::Value SetPushurl(const Napi::CallbackInfo& info);
      static Napi::Value SetUrl(const Napi::CallbackInfo& info);
     Napi::Value Stats(const Napi::CallbackInfo& info);
     Napi::Value Stop(const Napi::CallbackInfo& info);
 
    struct UpdateTipsBaton {
      int error_code;
      const git_error* error;
      git_remote * remote;
      const git_remote_callbacks * callbacks;
      unsigned int update_flags;
      git_remote_autotag_option_t download_tags;
      const char * reflog_message;
     };
    class UpdateTipsWorker : public nodegit::AsyncWorker {
      public:
        UpdateTipsWorker(
            UpdateTipsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:UpdateTips", cleanupHandles)
          , baton(_baton) {};
        UpdateTipsWorker(const UpdateTipsWorker &) = delete;
        UpdateTipsWorker(UpdateTipsWorker &&) = delete;
        UpdateTipsWorker &operator=(const UpdateTipsWorker &) = delete;
        UpdateTipsWorker &operator=(UpdateTipsWorker &&) = delete;
        ~UpdateTipsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        UpdateTipsBaton *baton;
    };
    Napi::Value UpdateTips(const Napi::CallbackInfo& info);
 
    struct UploadBaton {
      int error_code;
      const git_error* error;
      git_remote * remote;
      const git_strarray * refspecs;
      const git_push_options * opts;
     };
    class UploadWorker : public nodegit::AsyncWorker {
      public:
        UploadWorker(
            UploadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:Upload", cleanupHandles)
          , baton(_baton) {};
        UploadWorker(const UploadWorker &) = delete;
        UploadWorker(UploadWorker &&) = delete;
        UploadWorker &operator=(const UploadWorker &) = delete;
        UploadWorker &operator=(UploadWorker &&) = delete;
        ~UploadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        UploadBaton *baton;
    };
    Napi::Value Upload(const Napi::CallbackInfo& info);
     Napi::Value Url(const Napi::CallbackInfo& info);
 
    struct ReferenceListBaton {
      int error_code;
      const git_error* error;
      std::vector<git_remote_head*> * out;
      git_remote * remote;
     };
    class ReferenceListWorker : public nodegit::AsyncWorker {
      public:
        ReferenceListWorker(
            ReferenceListBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRemote:ReferenceList", cleanupHandles)
          , baton(_baton) {};
        ReferenceListWorker(const ReferenceListWorker &) = delete;
        ReferenceListWorker(ReferenceListWorker &&) = delete;
        ReferenceListWorker &operator=(const ReferenceListWorker &) = delete;
        ReferenceListWorker &operator=(ReferenceListWorker &&) = delete;
        ~ReferenceListWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ReferenceListBaton *baton;
    };
    Napi::Value ReferenceList(const Napi::CallbackInfo& info);
 };

#endif
