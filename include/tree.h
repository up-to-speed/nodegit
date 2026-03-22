// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITTREE_H
#define GITTREE_H
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
#include "../include/repository.h"
#include "../include/tree_update.h"
#include "../include/tree_entry.h"
// Forward declaration.
struct git_tree {
};
class GitTree;
 
struct GitTreeTraits {
  typedef GitTree cppClass;
  typedef git_tree cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_tree **dest, git_tree *src) {
     throw std::runtime_error("duplicate called on GitTree which cannot be duplicated");
   }

  static std::string className() { return "GitTree"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_tree *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_tree_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitTree : public
  NodeGitWrapper<GitTreeTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitTreeTraits>;
   public:
    GitTree(const GitTree &) = delete;
    GitTree(GitTree &&) = delete;
    GitTree &operator=(const GitTree &) = delete;
    GitTree &operator=(GitTree &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                              GitTree(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitTreeTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitTree cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitTree();

  private:


    struct CreateUpdatedBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      git_tree * baseline;
      size_t nupdates;
      git_tree_update * updates;
     };
    class CreateUpdatedWorker : public nodegit::AsyncWorker {
      public:
        CreateUpdatedWorker(
            CreateUpdatedBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTree:CreateUpdated", cleanupHandles)
          , baton(_baton) {};
        CreateUpdatedWorker(const CreateUpdatedWorker &) = delete;
        CreateUpdatedWorker(CreateUpdatedWorker &&) = delete;
        CreateUpdatedWorker &operator=(const CreateUpdatedWorker &) = delete;
        CreateUpdatedWorker &operator=(CreateUpdatedWorker &&) = delete;
        ~CreateUpdatedWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateUpdatedBaton *baton;
    };
    Napi::Value CreateUpdated(const Napi::CallbackInfo& info);
 
    struct DupBaton {
      int error_code;
      const git_error* error;
      git_tree * out;
      git_tree * source;
     };
    class DupWorker : public nodegit::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTree:Dup", cleanupHandles)
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
     Napi::Value EntryByid(const Napi::CallbackInfo& info);
     Napi::Value EntryByindex(const Napi::CallbackInfo& info);
     Napi::Value EntryByname(const Napi::CallbackInfo& info);
 
    struct EntryBypathBaton {
      int error_code;
      const git_error* error;
      git_tree_entry * out;
      const git_tree * root;
      const char * path;
     };
    class EntryBypathWorker : public nodegit::AsyncWorker {
      public:
        EntryBypathWorker(
            EntryBypathBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTree:EntryBypath", cleanupHandles)
          , baton(_baton) {};
        EntryBypathWorker(const EntryBypathWorker &) = delete;
        EntryBypathWorker(EntryBypathWorker &&) = delete;
        EntryBypathWorker &operator=(const EntryBypathWorker &) = delete;
        EntryBypathWorker &operator=(EntryBypathWorker &&) = delete;
        ~EntryBypathWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        EntryBypathBaton *baton;
    };
    Napi::Value EntryBypath(const Napi::CallbackInfo& info);
      static Napi::Value EntryCmp(const Napi::CallbackInfo& info);
     Napi::Value Entrycount(const Napi::CallbackInfo& info);
     Napi::Value Id(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_tree * out;
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
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTree:Lookup", cleanupHandles)
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
 
    struct LookupPrefixBaton {
      int error_code;
      const git_error* error;
      git_tree * out;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
      size_t len;
     };
    class LookupPrefixWorker : public nodegit::AsyncWorker {
      public:
        LookupPrefixWorker(
            LookupPrefixBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTree:LookupPrefix", cleanupHandles)
          , baton(_baton) {};
        LookupPrefixWorker(const LookupPrefixWorker &) = delete;
        LookupPrefixWorker(LookupPrefixWorker &&) = delete;
        LookupPrefixWorker &operator=(const LookupPrefixWorker &) = delete;
        LookupPrefixWorker &operator=(LookupPrefixWorker &&) = delete;
        ~LookupPrefixWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        LookupPrefixBaton *baton;
    };
     static Napi::Value LookupPrefix(const Napi::CallbackInfo& info);
     Napi::Value Owner(const Napi::CallbackInfo& info);
 
    struct GetAllFilepathsBaton {
      int error_code;
      const git_error* error;
      git_tree * tree;
      git_repository * repo;
      std::vector<std::string> * out;
     };
    class GetAllFilepathsWorker : public nodegit::AsyncWorker {
      public:
        GetAllFilepathsWorker(
            GetAllFilepathsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTree:GetAllFilepaths", cleanupHandles)
          , baton(_baton) {};
        GetAllFilepathsWorker(const GetAllFilepathsWorker &) = delete;
        GetAllFilepathsWorker(GetAllFilepathsWorker &&) = delete;
        GetAllFilepathsWorker &operator=(const GetAllFilepathsWorker &) = delete;
        GetAllFilepathsWorker &operator=(GetAllFilepathsWorker &&) = delete;
        ~GetAllFilepathsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetAllFilepathsBaton *baton;
    };
    Napi::Value GetAllFilepaths(const Napi::CallbackInfo& info);
 };

#endif
