// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITMEMPACK_H
#define GITMEMPACK_H
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
#include <git2/sys/mempack.h>
}

#include "../include/typedefs.h"

#include "../include/odb_backend.h"
class GitMempack;
 
struct GitMempackTraits {
  typedef GitMempack cppClass;
  typedef git_odb_backend cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_odb_backend **dest, git_odb_backend *src) {
     throw std::runtime_error("duplicate called on GitMempack which cannot be duplicated");
   }

  static std::string className() { return "GitMempack"; };
  static const bool isSingleton = false;
  static const bool isFreeable = false;
  static void free(git_odb_backend *raw) {
     throw std::runtime_error("free called on GitMempack which cannot be freed");
   }
};

class GitMempack : public
  NodeGitWrapper<GitMempackTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitMempackTraits>;
   public:
    GitMempack(const GitMempack &) = delete;
    GitMempack(GitMempack &&) = delete;
    GitMempack &operator=(const GitMempack &) = delete;
    GitMempack &operator=(GitMempack &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

           GitMempack(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitMempackTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitMempack cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitMempack();

  private:


    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_odb_backend * out;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMempack:Create", cleanupHandles)
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
 
    struct ResetBaton {
      int error_code;
      const git_error* error;
      git_odb_backend * backend;
     };
    class ResetWorker : public nodegit::AsyncWorker {
      public:
        ResetWorker(
            ResetBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMempack:Reset", cleanupHandles)
          , baton(_baton) {};
        ResetWorker(const ResetWorker &) = delete;
        ResetWorker(ResetWorker &&) = delete;
        ResetWorker &operator=(const ResetWorker &) = delete;
        ResetWorker &operator=(ResetWorker &&) = delete;
        ~ResetWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ResetBaton *baton;
    };
    Napi::Value Reset(const Napi::CallbackInfo& info);
 };

#endif
