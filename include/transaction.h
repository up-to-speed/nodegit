// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITTRANSACTION_H
#define GITTRANSACTION_H
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
#include "../include/reflog.h"
#include "../include/signature.h"
#include "../include/oid.h"
// Forward declaration.
struct git_transaction {
};
class GitTransaction;
 
struct GitTransactionTraits {
  typedef GitTransaction cppClass;
  typedef git_transaction cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_transaction **dest, git_transaction *src) {
     throw std::runtime_error("duplicate called on GitTransaction which cannot be duplicated");
   }

  static std::string className() { return "GitTransaction"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_transaction *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_transaction_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitTransaction : public
  NodeGitWrapper<GitTransactionTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitTransactionTraits>;
   public:
    GitTransaction(const GitTransaction &) = delete;
    GitTransaction(GitTransaction &&) = delete;
    GitTransaction &operator=(const GitTransaction &) = delete;
    GitTransaction &operator=(GitTransaction &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                       GitTransaction(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitTransactionTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitTransaction cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitTransaction();

  private:

    Napi::Value Commit(const Napi::CallbackInfo& info);
     Napi::Value LockRef(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_transaction * out;
      git_repository * repo;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTransaction:Create", cleanupHandles)
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
     Napi::Value SetReflog(const Napi::CallbackInfo& info);
     Napi::Value SetSymbolicTarget(const Napi::CallbackInfo& info);
     Napi::Value SetTarget(const Napi::CallbackInfo& info);
 };

#endif
