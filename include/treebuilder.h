// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITTREEBUILDER_H
#define GITTREEBUILDER_H
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

#include "../include/tree_entry.h"
#include "../include/oid.h"
#include "../include/repository.h"
#include "../include/tree.h"
// Forward declaration.
struct git_treebuilder {
};
class GitTreebuilder;
 
struct GitTreebuilderTraits {
  typedef GitTreebuilder cppClass;
  typedef git_treebuilder cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_treebuilder **dest, git_treebuilder *src) {
     throw std::runtime_error("duplicate called on GitTreebuilder which cannot be duplicated");
   }

  static std::string className() { return "GitTreebuilder"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_treebuilder *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_treebuilder_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitTreebuilder : public
  NodeGitWrapper<GitTreebuilderTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitTreebuilderTraits>;
   public:
    GitTreebuilder(const GitTreebuilder &) = delete;
    GitTreebuilder(GitTreebuilder &&) = delete;
    GitTreebuilder &operator=(const GitTreebuilder &) = delete;
    GitTreebuilder &operator=(GitTreebuilder &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                   GitTreebuilder(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitTreebuilderTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitTreebuilder cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitTreebuilder();

  private:

    Napi::Value Clear(const Napi::CallbackInfo& info);
     Napi::Value Entrycount(const Napi::CallbackInfo& info);
     Napi::Value Get(const Napi::CallbackInfo& info);
     Napi::Value Insert(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_treebuilder * out;
      git_repository * repo;
      const git_tree * source;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTreebuilder:Create", cleanupHandles)
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
     Napi::Value Remove(const Napi::CallbackInfo& info);
 
    struct WriteBaton {
      int error_code;
      const git_error* error;
      git_oid * id;
      git_treebuilder * bld;
     };
    class WriteWorker : public nodegit::AsyncWorker {
      public:
        WriteWorker(
            WriteBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTreebuilder:Write", cleanupHandles)
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
 };

#endif
