// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITSUBMODULE_H
#define GITSUBMODULE_H
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
#include "../include/submodule_update_options.h"
#include "../include/oid.h"
#include "../include/buf.h"
// Forward declaration.
struct git_submodule {
};
class GitSubmodule;
 
struct GitSubmoduleTraits {
  typedef GitSubmodule cppClass;
  typedef git_submodule cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_submodule **dest, git_submodule *src) {
     throw std::runtime_error("duplicate called on GitSubmodule which cannot be duplicated");
   }

  static std::string className() { return "GitSubmodule"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_submodule *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_submodule_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitSubmodule : public
  NodeGitWrapper<GitSubmoduleTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitSubmoduleTraits>;
   public:
    GitSubmodule(const GitSubmodule &) = delete;
    GitSubmodule(GitSubmodule &&) = delete;
    GitSubmodule &operator=(const GitSubmodule &) = delete;
    GitSubmodule &operator=(GitSubmodule &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                  static int Foreach_callback_cppCallback (
      git_submodule * sm
      ,
       const char * name
      ,
       void * payload
      );

    static void Foreach_callback_cancelAsync(void *baton);
    static void Foreach_callback_async(void *baton);
    static void Foreach_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class Foreach_CallbackBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      git_submodule * sm;
      const char * name;
      void * payload;
 

      Foreach_CallbackBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                                                                                                          GitSubmodule(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitSubmoduleTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitSubmodule cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitSubmodule();

  private:


    struct AddFinalizeBaton {
      int error_code;
      const git_error* error;
      git_submodule * submodule;
     };
    class AddFinalizeWorker : public nodegit::AsyncWorker {
      public:
        AddFinalizeWorker(
            AddFinalizeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:AddFinalize", cleanupHandles)
          , baton(_baton) {};
        AddFinalizeWorker(const AddFinalizeWorker &) = delete;
        AddFinalizeWorker(AddFinalizeWorker &&) = delete;
        AddFinalizeWorker &operator=(const AddFinalizeWorker &) = delete;
        AddFinalizeWorker &operator=(AddFinalizeWorker &&) = delete;
        ~AddFinalizeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddFinalizeBaton *baton;
    };
    Napi::Value AddFinalize(const Napi::CallbackInfo& info);
 
    struct AddSetupBaton {
      int error_code;
      const git_error* error;
      git_submodule * out;
      git_repository * repo;
      const char * url;
      const char * path;
      int use_gitlink;
     };
    class AddSetupWorker : public nodegit::AsyncWorker {
      public:
        AddSetupWorker(
            AddSetupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:AddSetup", cleanupHandles)
          , baton(_baton) {};
        AddSetupWorker(const AddSetupWorker &) = delete;
        AddSetupWorker(AddSetupWorker &&) = delete;
        AddSetupWorker &operator=(const AddSetupWorker &) = delete;
        AddSetupWorker &operator=(AddSetupWorker &&) = delete;
        ~AddSetupWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddSetupBaton *baton;
    };
     static Napi::Value AddSetup(const Napi::CallbackInfo& info);
 
    struct AddToIndexBaton {
      int error_code;
      const git_error* error;
      git_submodule * submodule;
      int write_index;
     };
    class AddToIndexWorker : public nodegit::AsyncWorker {
      public:
        AddToIndexWorker(
            AddToIndexBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:AddToIndex", cleanupHandles)
          , baton(_baton) {};
        AddToIndexWorker(const AddToIndexWorker &) = delete;
        AddToIndexWorker(AddToIndexWorker &&) = delete;
        AddToIndexWorker &operator=(const AddToIndexWorker &) = delete;
        AddToIndexWorker &operator=(AddToIndexWorker &&) = delete;
        ~AddToIndexWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddToIndexBaton *baton;
    };
    Napi::Value AddToIndex(const Napi::CallbackInfo& info);
     Napi::Value Branch(const Napi::CallbackInfo& info);
 
    struct CloneBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      git_submodule * submodule;
      const git_submodule_update_options * opts;
     };
    class CloneWorker : public nodegit::AsyncWorker {
      public:
        CloneWorker(
            CloneBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Clone", cleanupHandles)
          , baton(_baton) {};
        CloneWorker(const CloneWorker &) = delete;
        CloneWorker(CloneWorker &&) = delete;
        CloneWorker &operator=(const CloneWorker &) = delete;
        CloneWorker &operator=(CloneWorker &&) = delete;
        ~CloneWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CloneBaton *baton;
    };
    Napi::Value Clone(const Napi::CallbackInfo& info);
 
    struct DupBaton {
      int error_code;
      const git_error* error;
      git_submodule * out;
      git_submodule * source;
     };
    class DupWorker : public nodegit::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Dup", cleanupHandles)
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
     Napi::Value FetchRecurseSubmodules(const Napi::CallbackInfo& info);
 
    struct ForeachBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_submodule_cb callback;
      void * payload;
     };
    class ForeachWorker : public nodegit::AsyncWorker {
      public:
        ForeachWorker(
            ForeachBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Foreach", cleanupHandles)
          , baton(_baton) {};
        ForeachWorker(const ForeachWorker &) = delete;
        ForeachWorker(ForeachWorker &&) = delete;
        ForeachWorker &operator=(const ForeachWorker &) = delete;
        ForeachWorker &operator=(ForeachWorker &&) = delete;
        ~ForeachWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ForeachBaton *baton;
    };
     static Napi::Value Foreach(const Napi::CallbackInfo& info);
     Napi::Value HeadId(const Napi::CallbackInfo& info);
     Napi::Value Ignore(const Napi::CallbackInfo& info);
     Napi::Value IndexId(const Napi::CallbackInfo& info);
 
    struct InitBaton {
      int error_code;
      const git_error* error;
      git_submodule * submodule;
      int overwrite;
     };
    class InitWorker : public nodegit::AsyncWorker {
      public:
        InitWorker(
            InitBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Init", cleanupHandles)
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
    Napi::Value Init(const Napi::CallbackInfo& info);
 
    struct LocationBaton {
      int error_code;
      const git_error* error;
      unsigned int * location_status;
      git_submodule * submodule;
     };
    class LocationWorker : public nodegit::AsyncWorker {
      public:
        LocationWorker(
            LocationBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Location", cleanupHandles)
          , baton(_baton) {};
        LocationWorker(const LocationWorker &) = delete;
        LocationWorker(LocationWorker &&) = delete;
        LocationWorker &operator=(const LocationWorker &) = delete;
        LocationWorker &operator=(LocationWorker &&) = delete;
        ~LocationWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        LocationBaton *baton;
    };
    Napi::Value Location(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_submodule * out;
      git_repository * repo;
      const char * name;
     };
    class LookupWorker : public nodegit::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Lookup", cleanupHandles)
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
 
    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_submodule * submodule;
     };
    class OpenWorker : public nodegit::AsyncWorker {
      public:
        OpenWorker(
            OpenBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Open", cleanupHandles)
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
    Napi::Value Open(const Napi::CallbackInfo& info);
     Napi::Value Owner(const Napi::CallbackInfo& info);
     Napi::Value Path(const Napi::CallbackInfo& info);
     Napi::Value Reload(const Napi::CallbackInfo& info);
 
    struct RepoInitBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const git_submodule * sm;
      int use_gitlink;
     };
    class RepoInitWorker : public nodegit::AsyncWorker {
      public:
        RepoInitWorker(
            RepoInitBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:RepoInit", cleanupHandles)
          , baton(_baton) {};
        RepoInitWorker(const RepoInitWorker &) = delete;
        RepoInitWorker(RepoInitWorker &&) = delete;
        RepoInitWorker &operator=(const RepoInitWorker &) = delete;
        RepoInitWorker &operator=(RepoInitWorker &&) = delete;
        ~RepoInitWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RepoInitBaton *baton;
    };
    Napi::Value RepoInit(const Napi::CallbackInfo& info);
 
    struct ResolveUrlBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_repository * repo;
      const char * url;
     };
    class ResolveUrlWorker : public nodegit::AsyncWorker {
      public:
        ResolveUrlWorker(
            ResolveUrlBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:ResolveUrl", cleanupHandles)
          , baton(_baton) {};
        ResolveUrlWorker(const ResolveUrlWorker &) = delete;
        ResolveUrlWorker(ResolveUrlWorker &&) = delete;
        ResolveUrlWorker &operator=(const ResolveUrlWorker &) = delete;
        ResolveUrlWorker &operator=(ResolveUrlWorker &&) = delete;
        ~ResolveUrlWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ResolveUrlBaton *baton;
    };
     static Napi::Value ResolveUrl(const Napi::CallbackInfo& info);
      static Napi::Value SetBranch(const Napi::CallbackInfo& info);
      static Napi::Value SetFetchRecurseSubmodules(const Napi::CallbackInfo& info);
 
    struct SetIgnoreBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * name;
      git_submodule_ignore_t ignore;
     };
    class SetIgnoreWorker : public nodegit::AsyncWorker {
      public:
        SetIgnoreWorker(
            SetIgnoreBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:SetIgnore", cleanupHandles)
          , baton(_baton) {};
        SetIgnoreWorker(const SetIgnoreWorker &) = delete;
        SetIgnoreWorker(SetIgnoreWorker &&) = delete;
        SetIgnoreWorker &operator=(const SetIgnoreWorker &) = delete;
        SetIgnoreWorker &operator=(SetIgnoreWorker &&) = delete;
        ~SetIgnoreWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetIgnoreBaton *baton;
    };
     static Napi::Value SetIgnore(const Napi::CallbackInfo& info);
 
    struct SetUpdateBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * name;
      git_submodule_update_t update;
     };
    class SetUpdateWorker : public nodegit::AsyncWorker {
      public:
        SetUpdateWorker(
            SetUpdateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:SetUpdate", cleanupHandles)
          , baton(_baton) {};
        SetUpdateWorker(const SetUpdateWorker &) = delete;
        SetUpdateWorker(SetUpdateWorker &&) = delete;
        SetUpdateWorker &operator=(const SetUpdateWorker &) = delete;
        SetUpdateWorker &operator=(SetUpdateWorker &&) = delete;
        ~SetUpdateWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetUpdateBaton *baton;
    };
     static Napi::Value SetUpdate(const Napi::CallbackInfo& info);
 
    struct SetUrlBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * name;
      const char * url;
     };
    class SetUrlWorker : public nodegit::AsyncWorker {
      public:
        SetUrlWorker(
            SetUrlBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:SetUrl", cleanupHandles)
          , baton(_baton) {};
        SetUrlWorker(const SetUrlWorker &) = delete;
        SetUrlWorker(SetUrlWorker &&) = delete;
        SetUrlWorker &operator=(const SetUrlWorker &) = delete;
        SetUrlWorker &operator=(SetUrlWorker &&) = delete;
        ~SetUrlWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetUrlBaton *baton;
    };
     static Napi::Value SetUrl(const Napi::CallbackInfo& info);
 
    struct StatusBaton {
      int error_code;
      const git_error* error;
      unsigned int * status;
      git_repository * repo;
      const char * name;
      git_submodule_ignore_t ignore;
     };
    class StatusWorker : public nodegit::AsyncWorker {
      public:
        StatusWorker(
            StatusBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Status", cleanupHandles)
          , baton(_baton) {};
        StatusWorker(const StatusWorker &) = delete;
        StatusWorker(StatusWorker &&) = delete;
        StatusWorker &operator=(const StatusWorker &) = delete;
        StatusWorker &operator=(StatusWorker &&) = delete;
        ~StatusWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        StatusBaton *baton;
    };
     static Napi::Value Status(const Napi::CallbackInfo& info);
 
    struct SyncBaton {
      int error_code;
      const git_error* error;
      git_submodule * submodule;
     };
    class SyncWorker : public nodegit::AsyncWorker {
      public:
        SyncWorker(
            SyncBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Sync", cleanupHandles)
          , baton(_baton) {};
        SyncWorker(const SyncWorker &) = delete;
        SyncWorker(SyncWorker &&) = delete;
        SyncWorker &operator=(const SyncWorker &) = delete;
        SyncWorker &operator=(SyncWorker &&) = delete;
        ~SyncWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SyncBaton *baton;
    };
    Napi::Value Sync(const Napi::CallbackInfo& info);
 
    struct UpdateBaton {
      int error_code;
      const git_error* error;
      git_submodule * submodule;
      int init;
      git_submodule_update_options * options;
     };
    class UpdateWorker : public nodegit::AsyncWorker {
      public:
        UpdateWorker(
            UpdateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSubmodule:Update", cleanupHandles)
          , baton(_baton) {};
        UpdateWorker(const UpdateWorker &) = delete;
        UpdateWorker(UpdateWorker &&) = delete;
        UpdateWorker &operator=(const UpdateWorker &) = delete;
        UpdateWorker &operator=(UpdateWorker &&) = delete;
        ~UpdateWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        UpdateBaton *baton;
    };
    Napi::Value Update(const Napi::CallbackInfo& info);
     Napi::Value UpdateStrategy(const Napi::CallbackInfo& info);
     Napi::Value Url(const Napi::CallbackInfo& info);
     Napi::Value WdId(const Napi::CallbackInfo& info);
 
    struct Foreach_globalPayload {
      Napi::FunctionReference * callback;

      Foreach_globalPayload() {
        callback = NULL;
      }

      Foreach_globalPayload(const Foreach_globalPayload &) = delete;
      Foreach_globalPayload(Foreach_globalPayload &&) = delete;
      Foreach_globalPayload &operator=(const Foreach_globalPayload &) = delete;
      Foreach_globalPayload &operator=(Foreach_globalPayload &&) = delete;

      ~Foreach_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };
};

#endif
