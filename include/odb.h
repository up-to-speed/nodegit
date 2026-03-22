// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITODB_H
#define GITODB_H
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

#include "../include/mempack.h"
#include "../include/oid.h"
#include "../include/odb_object.h"
#include "../include/commit_graph.h"
#include "../include/odb_backend.h"
// Forward declaration.
struct git_odb {
};
class GitOdb;
 
struct GitOdbTraits {
  typedef GitOdb cppClass;
  typedef git_odb cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_odb **dest, git_odb *src) {
     throw std::runtime_error("duplicate called on GitOdb which cannot be duplicated");
   }

  static std::string className() { return "GitOdb"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_odb *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_odb_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitOdb : public
  NodeGitWrapper<GitOdbTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitOdbTraits>;
   public:
    GitOdb(const GitOdb &) = delete;
    GitOdb(GitOdb &&) = delete;
    GitOdb &operator=(const GitOdb &) = delete;
    GitOdb &operator=(GitOdb &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                 GitOdb(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitOdbTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitOdb cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitOdb();

  private:


    struct AddDiskAlternateBaton {
      int error_code;
      const git_error* error;
      git_odb * odb;
      const char * path;
     };
    class AddDiskAlternateWorker : public nodegit::AsyncWorker {
      public:
        AddDiskAlternateWorker(
            AddDiskAlternateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitOdb:AddDiskAlternate", cleanupHandles)
          , baton(_baton) {};
        AddDiskAlternateWorker(const AddDiskAlternateWorker &) = delete;
        AddDiskAlternateWorker(AddDiskAlternateWorker &&) = delete;
        AddDiskAlternateWorker &operator=(const AddDiskAlternateWorker &) = delete;
        AddDiskAlternateWorker &operator=(AddDiskAlternateWorker &&) = delete;
        ~AddDiskAlternateWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddDiskAlternateBaton *baton;
    };
    Napi::Value AddDiskAlternate(const Napi::CallbackInfo& info);
     Napi::Value ExistsExt(const Napi::CallbackInfo& info);
 
    struct ExistsPrefixBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_odb * db;
      const git_oid * short_id;
      bool short_idNeedsFree;
      size_t len;
     };
    class ExistsPrefixWorker : public nodegit::AsyncWorker {
      public:
        ExistsPrefixWorker(
            ExistsPrefixBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitOdb:ExistsPrefix", cleanupHandles)
          , baton(_baton) {};
        ExistsPrefixWorker(const ExistsPrefixWorker &) = delete;
        ExistsPrefixWorker(ExistsPrefixWorker &&) = delete;
        ExistsPrefixWorker &operator=(const ExistsPrefixWorker &) = delete;
        ExistsPrefixWorker &operator=(ExistsPrefixWorker &&) = delete;
        ~ExistsPrefixWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ExistsPrefixBaton *baton;
    };
    Napi::Value ExistsPrefix(const Napi::CallbackInfo& info);
 
    struct HashBaton {
      int error_code;
      const git_error* error;
      git_oid * oid;
      const void * data;
      size_t len;
      git_object_t object_type;
     };
    class HashWorker : public nodegit::AsyncWorker {
      public:
        HashWorker(
            HashBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitOdb:Hash", cleanupHandles)
          , baton(_baton) {};
        HashWorker(const HashWorker &) = delete;
        HashWorker(HashWorker &&) = delete;
        HashWorker &operator=(const HashWorker &) = delete;
        HashWorker &operator=(HashWorker &&) = delete;
        ~HashWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        HashBaton *baton;
    };
     static Napi::Value Hash(const Napi::CallbackInfo& info);
 
    struct HashfileBaton {
      int error_code;
      const git_error* error;
      git_oid * oid;
      bool oidNeedsFree;
      const char * path;
      git_object_t object_type;
     };
    class HashfileWorker : public nodegit::AsyncWorker {
      public:
        HashfileWorker(
            HashfileBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitOdb:Hashfile", cleanupHandles)
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
     static Napi::Value Hashfile(const Napi::CallbackInfo& info);
 
    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_odb * odb_out;
      const char * objects_dir;
     };
    class OpenWorker : public nodegit::AsyncWorker {
      public:
        OpenWorker(
            OpenBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitOdb:Open", cleanupHandles)
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
 
    struct OdbReadBaton {
      int error_code;
      const git_error* error;
      git_odb_object * obj;
      git_odb * db;
      const git_oid * id;
      bool idNeedsFree;
        int result;
     };
    class OdbReadWorker : public nodegit::AsyncWorker {
      public:
        OdbReadWorker(
            OdbReadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitOdb:OdbRead", cleanupHandles)
          , baton(_baton) {};
        OdbReadWorker(const OdbReadWorker &) = delete;
        OdbReadWorker(OdbReadWorker &&) = delete;
        OdbReadWorker &operator=(const OdbReadWorker &) = delete;
        OdbReadWorker &operator=(OdbReadWorker &&) = delete;
        ~OdbReadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OdbReadBaton *baton;
    };
    Napi::Value OdbRead(const Napi::CallbackInfo& info);
     Napi::Value ReadPrefix(const Napi::CallbackInfo& info);
     Napi::Value SetCommitGraph(const Napi::CallbackInfo& info);
 
    struct WriteBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_odb * odb;
      const void * data;
      size_t len;
      git_object_t type;
     };
    class WriteWorker : public nodegit::AsyncWorker {
      public:
        WriteWorker(
            WriteBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitOdb:Write", cleanupHandles)
          , baton(_baton) {};
        WriteWorker(const WriteWorker &) = delete;
        WriteWorker(WriteWorker &&) = delete;
        WriteWorker &operator=(const WriteWorker &) = delete;
        WriteWorker &operator=(WriteWorker &&) = delete;
        ~WriteWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        WriteBaton *baton;
    };
    Napi::Value Write(const Napi::CallbackInfo& info);
     Napi::Value WriteMultiPackIndex(const Napi::CallbackInfo& info);
 
    struct AddMempackBackendBaton {
      int error_code;
      const git_error* error;
      git_odb * odb;
      git_odb_backend * backend;
      int priority;
     };
    class AddMempackBackendWorker : public nodegit::AsyncWorker {
      public:
        AddMempackBackendWorker(
            AddMempackBackendBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitOdb:AddMempackBackend", cleanupHandles)
          , baton(_baton) {};
        AddMempackBackendWorker(const AddMempackBackendWorker &) = delete;
        AddMempackBackendWorker(AddMempackBackendWorker &&) = delete;
        AddMempackBackendWorker &operator=(const AddMempackBackendWorker &) = delete;
        AddMempackBackendWorker &operator=(AddMempackBackendWorker &&) = delete;
        ~AddMempackBackendWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddMempackBackendBaton *baton;
    };
    Napi::Value AddMempackBackend(const Napi::CallbackInfo& info);
 };

#endif
