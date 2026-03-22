// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREPOSITORY_H
#define GITREPOSITORY_H
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

#include "git2/sys/repository.h"
#include "../include/commit.h"
#include "../include/submodule.h"
#include "../include/remote.h"
#include "../include/commitarray.h"
#include "../include/config.h"
#include "../include/buf.h"
#include "../include/oid.h"
#include "../include/reference.h"
#include "../include/index.h"
#include "../include/repository_init_options.h"
#include "../include/odb.h"
#include "../include/worktree.h"
#include "../include/refdb.h"
#include "../include/annotated_commit.h"
// Forward declaration.
struct git_repository {
};
class GitRepository;
 
struct GitRepositoryTraits {
  typedef GitRepository cppClass;
  typedef git_repository cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_repository **dest, git_repository *src) {
     throw std::runtime_error("duplicate called on GitRepository which cannot be duplicated");
   }

  static std::string className() { return "GitRepository"; };
  static const bool isSingleton = true;
  static const bool isFreeable = true;
  static void free(git_repository *raw) {
    unsigned long referenceCount = 0;
    referenceCount = ReferenceCounter::decrementCountForPointer((void *)raw);
     if (referenceCount == 0) {
      ::git_repository_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRepository : public
  NodeGitWrapper<GitRepositoryTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRepositoryTraits>;
   public:
    GitRepository(const GitRepository &) = delete;
    GitRepository(GitRepository &&) = delete;
    GitRepository &operator=(const GitRepository &) = delete;
    GitRepository &operator=(GitRepository &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                         static int FetchheadForeach_callback_cppCallback (
      const char * refname
      ,
       const char * remote_url
      ,
       const git_oid * oid
      ,
       unsigned int is_merge
      ,
       void * payload
      );

    static void FetchheadForeach_callback_cancelAsync(void *baton);
    static void FetchheadForeach_callback_async(void *baton);
    static void FetchheadForeach_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class FetchheadForeach_CallbackBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const char * refname;
      const char * remote_url;
      const git_oid * oid;
      unsigned int is_merge;
      void * payload;
 

      FetchheadForeach_CallbackBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                                                                          static int MergeheadForeach_callback_cppCallback (
      const git_oid * oid
      ,
       void * payload
      );

    static void MergeheadForeach_callback_cancelAsync(void *baton);
    static void MergeheadForeach_callback_async(void *baton);
    static void MergeheadForeach_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class MergeheadForeach_CallbackBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const git_oid * oid;
      void * payload;
 

      MergeheadForeach_CallbackBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                                                                                                                    GitRepository(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRepositoryTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRepository cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRepository();

  private:


    struct CommitParentsBaton {
      int error_code;
      const git_error* error;
      git_commitarray * commits;
      git_repository * repo;
     };
    class CommitParentsWorker : public nodegit::AsyncWorker {
      public:
        CommitParentsWorker(
            CommitParentsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:CommitParents", cleanupHandles)
          , baton(_baton) {};
        CommitParentsWorker(const CommitParentsWorker &) = delete;
        CommitParentsWorker(CommitParentsWorker &&) = delete;
        CommitParentsWorker &operator=(const CommitParentsWorker &) = delete;
        CommitParentsWorker &operator=(CommitParentsWorker &&) = delete;
        ~CommitParentsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CommitParentsBaton *baton;
    };
    Napi::Value CommitParents(const Napi::CallbackInfo& info);
     Napi::Value Commondir(const Napi::CallbackInfo& info);
 
    struct ConfigBaton {
      int error_code;
      const git_error* error;
      git_config * out;
      git_repository * repo;
     };
    class ConfigWorker : public nodegit::AsyncWorker {
      public:
        ConfigWorker(
            ConfigBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Config", cleanupHandles)
          , baton(_baton) {};
        ConfigWorker(const ConfigWorker &) = delete;
        ConfigWorker(ConfigWorker &&) = delete;
        ConfigWorker &operator=(const ConfigWorker &) = delete;
        ConfigWorker &operator=(ConfigWorker &&) = delete;
        ~ConfigWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ConfigBaton *baton;
    };
    Napi::Value Config(const Napi::CallbackInfo& info);
     Napi::Value DetachHead(const Napi::CallbackInfo& info);
 
    struct DiscoverBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const char * start_path;
      int across_fs;
      const char * ceiling_dirs;
     };
    class DiscoverWorker : public nodegit::AsyncWorker {
      public:
        DiscoverWorker(
            DiscoverBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Discover", cleanupHandles)
          , baton(_baton) {};
        DiscoverWorker(const DiscoverWorker &) = delete;
        DiscoverWorker(DiscoverWorker &&) = delete;
        DiscoverWorker &operator=(const DiscoverWorker &) = delete;
        DiscoverWorker &operator=(DiscoverWorker &&) = delete;
        ~DiscoverWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DiscoverBaton *baton;
    };
     static Napi::Value Discover(const Napi::CallbackInfo& info);
 
    struct FetchheadForeachBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_repository_fetchhead_foreach_cb callback;
      void * payload;
     };
    class FetchheadForeachWorker : public nodegit::AsyncWorker {
      public:
        FetchheadForeachWorker(
            FetchheadForeachBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:FetchheadForeach", cleanupHandles)
          , baton(_baton) {};
        FetchheadForeachWorker(const FetchheadForeachWorker &) = delete;
        FetchheadForeachWorker(FetchheadForeachWorker &&) = delete;
        FetchheadForeachWorker &operator=(const FetchheadForeachWorker &) = delete;
        FetchheadForeachWorker &operator=(FetchheadForeachWorker &&) = delete;
        ~FetchheadForeachWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FetchheadForeachBaton *baton;
    };
    Napi::Value FetchheadForeach(const Napi::CallbackInfo& info);
     Napi::Value GetNamespace(const Napi::CallbackInfo& info);
 
    struct HashfileBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const char * path;
      git_object_t type;
      const char * as_path;
     };
    class HashfileWorker : public nodegit::AsyncWorker {
      public:
        HashfileWorker(
            HashfileBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Hashfile", cleanupHandles)
          , baton(_baton) {};
        HashfileWorker(const HashfileWorker &) = delete;
        HashfileWorker(HashfileWorker &&) = delete;
        HashfileWorker &operator=(const HashfileWorker &) = delete;
        HashfileWorker &operator=(HashfileWorker &&) = delete;
        ~HashfileWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        HashfileBaton *baton;
    };
    Napi::Value Hashfile(const Napi::CallbackInfo& info);
 
    struct HeadBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
     };
    class HeadWorker : public nodegit::AsyncWorker {
      public:
        HeadWorker(
            HeadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Head", cleanupHandles)
          , baton(_baton) {};
        HeadWorker(const HeadWorker &) = delete;
        HeadWorker(HeadWorker &&) = delete;
        HeadWorker &operator=(const HeadWorker &) = delete;
        HeadWorker &operator=(HeadWorker &&) = delete;
        ~HeadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        HeadBaton *baton;
    };
    Napi::Value Head(const Napi::CallbackInfo& info);
     Napi::Value HeadDetached(const Napi::CallbackInfo& info);
     Napi::Value HeadDetachedForWorktree(const Napi::CallbackInfo& info);
 
    struct HeadForWorktreeBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
     };
    class HeadForWorktreeWorker : public nodegit::AsyncWorker {
      public:
        HeadForWorktreeWorker(
            HeadForWorktreeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:HeadForWorktree", cleanupHandles)
          , baton(_baton) {};
        HeadForWorktreeWorker(const HeadForWorktreeWorker &) = delete;
        HeadForWorktreeWorker(HeadForWorktreeWorker &&) = delete;
        HeadForWorktreeWorker &operator=(const HeadForWorktreeWorker &) = delete;
        HeadForWorktreeWorker &operator=(HeadForWorktreeWorker &&) = delete;
        ~HeadForWorktreeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        HeadForWorktreeBaton *baton;
    };
    Napi::Value HeadForWorktree(const Napi::CallbackInfo& info);
     Napi::Value HeadUnborn(const Napi::CallbackInfo& info);
     Napi::Value Ident(const Napi::CallbackInfo& info);
 
    struct IndexBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      git_repository * repo;
     };
    class IndexWorker : public nodegit::AsyncWorker {
      public:
        IndexWorker(
            IndexBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Index", cleanupHandles)
          , baton(_baton) {};
        IndexWorker(const IndexWorker &) = delete;
        IndexWorker(IndexWorker &&) = delete;
        IndexWorker &operator=(const IndexWorker &) = delete;
        IndexWorker &operator=(IndexWorker &&) = delete;
        ~IndexWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        IndexBaton *baton;
    };
    Napi::Value Index(const Napi::CallbackInfo& info);
 
    struct InitBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * path;
      unsigned int is_bare;
     };
    class InitWorker : public nodegit::AsyncWorker {
      public:
        InitWorker(
            InitBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Init", cleanupHandles)
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
 
    struct InitExtBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * repo_path;
      git_repository_init_options * opts;
     };
    class InitExtWorker : public nodegit::AsyncWorker {
      public:
        InitExtWorker(
            InitExtBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:InitExt", cleanupHandles)
          , baton(_baton) {};
        InitExtWorker(const InitExtWorker &) = delete;
        InitExtWorker(InitExtWorker &&) = delete;
        InitExtWorker &operator=(const InitExtWorker &) = delete;
        InitExtWorker &operator=(InitExtWorker &&) = delete;
        ~InitExtWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        InitExtBaton *baton;
    };
     static Napi::Value InitExt(const Napi::CallbackInfo& info);
     Napi::Value IsBare(const Napi::CallbackInfo& info);
     Napi::Value IsEmpty(const Napi::CallbackInfo& info);
     Napi::Value IsShallow(const Napi::CallbackInfo& info);
     Napi::Value IsWorktree(const Napi::CallbackInfo& info);
 
    struct ItemPathBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_repository * repo;
      git_repository_item_t item;
     };
    class ItemPathWorker : public nodegit::AsyncWorker {
      public:
        ItemPathWorker(
            ItemPathBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:ItemPath", cleanupHandles)
          , baton(_baton) {};
        ItemPathWorker(const ItemPathWorker &) = delete;
        ItemPathWorker(ItemPathWorker &&) = delete;
        ItemPathWorker &operator=(const ItemPathWorker &) = delete;
        ItemPathWorker &operator=(ItemPathWorker &&) = delete;
        ~ItemPathWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ItemPathBaton *baton;
    };
    Napi::Value ItemPath(const Napi::CallbackInfo& info);
 
    struct MergeheadForeachBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_repository_mergehead_foreach_cb callback;
      void * payload;
     };
    class MergeheadForeachWorker : public nodegit::AsyncWorker {
      public:
        MergeheadForeachWorker(
            MergeheadForeachBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:MergeheadForeach", cleanupHandles)
          , baton(_baton) {};
        MergeheadForeachWorker(const MergeheadForeachWorker &) = delete;
        MergeheadForeachWorker(MergeheadForeachWorker &&) = delete;
        MergeheadForeachWorker &operator=(const MergeheadForeachWorker &) = delete;
        MergeheadForeachWorker &operator=(MergeheadForeachWorker &&) = delete;
        ~MergeheadForeachWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        MergeheadForeachBaton *baton;
    };
    Napi::Value MergeheadForeach(const Napi::CallbackInfo& info);
     Napi::Value MessageRemove(const Napi::CallbackInfo& info);
 
    struct OdbBaton {
      int error_code;
      const git_error* error;
      git_odb * out;
      git_repository * repo;
     };
    class OdbWorker : public nodegit::AsyncWorker {
      public:
        OdbWorker(
            OdbBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Odb", cleanupHandles)
          , baton(_baton) {};
        OdbWorker(const OdbWorker &) = delete;
        OdbWorker(OdbWorker &&) = delete;
        OdbWorker &operator=(const OdbWorker &) = delete;
        OdbWorker &operator=(OdbWorker &&) = delete;
        ~OdbWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OdbBaton *baton;
    };
    Napi::Value Odb(const Napi::CallbackInfo& info);
     Napi::Value OidType(const Napi::CallbackInfo& info);
 
    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * path;
     };
    class OpenWorker : public nodegit::AsyncWorker {
      public:
        OpenWorker(
            OpenBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Open", cleanupHandles)
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
 
    struct OpenBareBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * bare_path;
     };
    class OpenBareWorker : public nodegit::AsyncWorker {
      public:
        OpenBareWorker(
            OpenBareBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:OpenBare", cleanupHandles)
          , baton(_baton) {};
        OpenBareWorker(const OpenBareWorker &) = delete;
        OpenBareWorker(OpenBareWorker &&) = delete;
        OpenBareWorker &operator=(const OpenBareWorker &) = delete;
        OpenBareWorker &operator=(OpenBareWorker &&) = delete;
        ~OpenBareWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OpenBareBaton *baton;
    };
     static Napi::Value OpenBare(const Napi::CallbackInfo& info);
 
    struct OpenExtBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * path;
      unsigned int flags;
      const char * ceiling_dirs;
     };
    class OpenExtWorker : public nodegit::AsyncWorker {
      public:
        OpenExtWorker(
            OpenExtBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:OpenExt", cleanupHandles)
          , baton(_baton) {};
        OpenExtWorker(const OpenExtWorker &) = delete;
        OpenExtWorker(OpenExtWorker &&) = delete;
        OpenExtWorker &operator=(const OpenExtWorker &) = delete;
        OpenExtWorker &operator=(OpenExtWorker &&) = delete;
        ~OpenExtWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OpenExtBaton *baton;
    };
     static Napi::Value OpenExt(const Napi::CallbackInfo& info);
 
    struct OpenFromWorktreeBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      git_worktree * wt;
     };
    class OpenFromWorktreeWorker : public nodegit::AsyncWorker {
      public:
        OpenFromWorktreeWorker(
            OpenFromWorktreeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:OpenFromWorktree", cleanupHandles)
          , baton(_baton) {};
        OpenFromWorktreeWorker(const OpenFromWorktreeWorker &) = delete;
        OpenFromWorktreeWorker(OpenFromWorktreeWorker &&) = delete;
        OpenFromWorktreeWorker &operator=(const OpenFromWorktreeWorker &) = delete;
        OpenFromWorktreeWorker &operator=(OpenFromWorktreeWorker &&) = delete;
        ~OpenFromWorktreeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OpenFromWorktreeBaton *baton;
    };
     static Napi::Value OpenFromWorktree(const Napi::CallbackInfo& info);
     Napi::Value Path(const Napi::CallbackInfo& info);
 
    struct RefdbBaton {
      int error_code;
      const git_error* error;
      git_refdb * out;
      git_repository * repo;
     };
    class RefdbWorker : public nodegit::AsyncWorker {
      public:
        RefdbWorker(
            RefdbBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Refdb", cleanupHandles)
          , baton(_baton) {};
        RefdbWorker(const RefdbWorker &) = delete;
        RefdbWorker(RefdbWorker &&) = delete;
        RefdbWorker &operator=(const RefdbWorker &) = delete;
        RefdbWorker &operator=(RefdbWorker &&) = delete;
        ~RefdbWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RefdbBaton *baton;
    };
    Napi::Value Refdb(const Napi::CallbackInfo& info);
 
    struct SetHeadBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * refname;
     };
    class SetHeadWorker : public nodegit::AsyncWorker {
      public:
        SetHeadWorker(
            SetHeadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:SetHead", cleanupHandles)
          , baton(_baton) {};
        SetHeadWorker(const SetHeadWorker &) = delete;
        SetHeadWorker(SetHeadWorker &&) = delete;
        SetHeadWorker &operator=(const SetHeadWorker &) = delete;
        SetHeadWorker &operator=(SetHeadWorker &&) = delete;
        ~SetHeadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetHeadBaton *baton;
    };
    Napi::Value SetHead(const Napi::CallbackInfo& info);
     Napi::Value SetHeadDetached(const Napi::CallbackInfo& info);
     Napi::Value SetHeadDetachedFromAnnotated(const Napi::CallbackInfo& info);
     Napi::Value SetIdent(const Napi::CallbackInfo& info);
     Napi::Value SetNamespace(const Napi::CallbackInfo& info);
     Napi::Value SetWorkdir(const Napi::CallbackInfo& info);
     Napi::Value State(const Napi::CallbackInfo& info);
     Napi::Value StateCleanup(const Napi::CallbackInfo& info);
     Napi::Value Workdir(const Napi::CallbackInfo& info);
 
    struct WrapOdbBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      git_odb * odb;
     };
    class WrapOdbWorker : public nodegit::AsyncWorker {
      public:
        WrapOdbWorker(
            WrapOdbBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:WrapOdb", cleanupHandles)
          , baton(_baton) {};
        WrapOdbWorker(const WrapOdbWorker &) = delete;
        WrapOdbWorker(WrapOdbWorker &&) = delete;
        WrapOdbWorker &operator=(const WrapOdbWorker &) = delete;
        WrapOdbWorker &operator=(WrapOdbWorker &&) = delete;
        ~WrapOdbWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        WrapOdbBaton *baton;
    };
     static Napi::Value WrapOdb(const Napi::CallbackInfo& info);
 
    struct CleanupBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
     };
    class CleanupWorker : public nodegit::AsyncWorker {
      public:
        CleanupWorker(
            CleanupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Cleanup", cleanupHandles)
          , baton(_baton) {};
        CleanupWorker(const CleanupWorker &) = delete;
        CleanupWorker(CleanupWorker &&) = delete;
        CleanupWorker &operator=(const CleanupWorker &) = delete;
        CleanupWorker &operator=(CleanupWorker &&) = delete;
        ~CleanupWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CleanupBaton *baton;
    };
    Napi::Value Cleanup(const Napi::CallbackInfo& info);
 
    struct GetReferencesBaton {
      int error_code;
      const git_error* error;
      std::vector<git_reference *> * out;
      git_repository * repo;
     };
    class GetReferencesWorker : public nodegit::AsyncWorker {
      public:
        GetReferencesWorker(
            GetReferencesBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:GetReferences", cleanupHandles)
          , baton(_baton) {};
        GetReferencesWorker(const GetReferencesWorker &) = delete;
        GetReferencesWorker(GetReferencesWorker &&) = delete;
        GetReferencesWorker &operator=(const GetReferencesWorker &) = delete;
        GetReferencesWorker &operator=(GetReferencesWorker &&) = delete;
        ~GetReferencesWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetReferencesBaton *baton;
    };
    Napi::Value GetReferences(const Napi::CallbackInfo& info);
 
    struct GetSubmodulesBaton {
      int error_code;
      const git_error* error;
      std::vector<git_submodule *> * out;
      git_repository * repo;
     };
    class GetSubmodulesWorker : public nodegit::AsyncWorker {
      public:
        GetSubmodulesWorker(
            GetSubmodulesBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:GetSubmodules", cleanupHandles)
          , baton(_baton) {};
        GetSubmodulesWorker(const GetSubmodulesWorker &) = delete;
        GetSubmodulesWorker(GetSubmodulesWorker &&) = delete;
        GetSubmodulesWorker &operator=(const GetSubmodulesWorker &) = delete;
        GetSubmodulesWorker &operator=(GetSubmodulesWorker &&) = delete;
        ~GetSubmodulesWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetSubmodulesBaton *baton;
    };
    Napi::Value GetSubmodules(const Napi::CallbackInfo& info);
 
    struct GetRemotesBaton {
      int error_code;
      const git_error* error;
      std::vector<git_remote *> * out;
      git_repository * repo;
     };
    class GetRemotesWorker : public nodegit::AsyncWorker {
      public:
        GetRemotesWorker(
            GetRemotesBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:GetRemotes", cleanupHandles)
          , baton(_baton) {};
        GetRemotesWorker(const GetRemotesWorker &) = delete;
        GetRemotesWorker(GetRemotesWorker &&) = delete;
        GetRemotesWorker &operator=(const GetRemotesWorker &) = delete;
        GetRemotesWorker &operator=(GetRemotesWorker &&) = delete;
        ~GetRemotesWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetRemotesBaton *baton;
    };
    Napi::Value GetRemotes(const Napi::CallbackInfo& info);
 
    struct RefreshReferencesBaton {
      int error_code;
      const git_error* error;
      void * out;
      git_repository * repo;
     };
    class RefreshReferencesWorker : public nodegit::AsyncWorker {
      public:
        RefreshReferencesWorker(
            RefreshReferencesBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:RefreshReferences", cleanupHandles)
          , baton(_baton) {};
        RefreshReferencesWorker(const RefreshReferencesWorker &) = delete;
        RefreshReferencesWorker(RefreshReferencesWorker &&) = delete;
        RefreshReferencesWorker &operator=(const RefreshReferencesWorker &) = delete;
        RefreshReferencesWorker &operator=(RefreshReferencesWorker &&) = delete;
        ~RefreshReferencesWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RefreshReferencesBaton *baton;
    };
    Napi::Value RefreshReferences(const Napi::CallbackInfo& info);
     Napi::Value SetIndex(const Napi::CallbackInfo& info);
 
    struct StatisticsBaton {
      int error_code;
      const git_error* error;
      void * out;
      git_repository * repo;
     };
    class StatisticsWorker : public nodegit::AsyncWorker {
      public:
        StatisticsWorker(
            StatisticsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRepository:Statistics", cleanupHandles)
          , baton(_baton) {};
        StatisticsWorker(const StatisticsWorker &) = delete;
        StatisticsWorker(StatisticsWorker &&) = delete;
        StatisticsWorker &operator=(const StatisticsWorker &) = delete;
        StatisticsWorker &operator=(StatisticsWorker &&) = delete;
        ~StatisticsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        StatisticsBaton *baton;
    };
    Napi::Value Statistics(const Napi::CallbackInfo& info);
     Napi::Value SubmoduleCacheAll(const Napi::CallbackInfo& info);
     Napi::Value SubmoduleCacheClear(const Napi::CallbackInfo& info);
 
    struct FetchheadForeach_globalPayload {
      Napi::FunctionReference * callback;

      FetchheadForeach_globalPayload() {
        callback = NULL;
      }

      FetchheadForeach_globalPayload(const FetchheadForeach_globalPayload &) = delete;
      FetchheadForeach_globalPayload(FetchheadForeach_globalPayload &&) = delete;
      FetchheadForeach_globalPayload &operator=(const FetchheadForeach_globalPayload &) = delete;
      FetchheadForeach_globalPayload &operator=(FetchheadForeach_globalPayload &&) = delete;

      ~FetchheadForeach_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };

    struct MergeheadForeach_globalPayload {
      Napi::FunctionReference * callback;

      MergeheadForeach_globalPayload() {
        callback = NULL;
      }

      MergeheadForeach_globalPayload(const MergeheadForeach_globalPayload &) = delete;
      MergeheadForeach_globalPayload(MergeheadForeach_globalPayload &&) = delete;
      MergeheadForeach_globalPayload &operator=(const MergeheadForeach_globalPayload &) = delete;
      MergeheadForeach_globalPayload &operator=(MergeheadForeach_globalPayload &&) = delete;

      ~MergeheadForeach_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };
};

#endif
