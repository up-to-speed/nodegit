// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITHASHSIG_H
#define GITHASHSIG_H
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
#include <git2/sys/hashsig.h>
}

#include "../include/typedefs.h"

class GitHashsig;
 
struct GitHashsigTraits {
  typedef GitHashsig cppClass;
  typedef git_hashsig cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_hashsig **dest, git_hashsig *src) {
     throw std::runtime_error("duplicate called on GitHashsig which cannot be duplicated");
   }

  static std::string className() { return "GitHashsig"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_hashsig *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_hashsig_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitHashsig : public
  NodeGitWrapper<GitHashsigTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitHashsigTraits>;
   public:
    GitHashsig(const GitHashsig &) = delete;
    GitHashsig(GitHashsig &&) = delete;
    GitHashsig &operator=(const GitHashsig &) = delete;
    GitHashsig &operator=(GitHashsig &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                    GitHashsig(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitHashsigTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitHashsig cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitHashsig();

  private:

    Napi::Value Compare(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_hashsig * out;
      const char * buf;
      size_t buflen;
      git_hashsig_option_t opts;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitHashsig:Create", cleanupHandles)
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
 
    struct CreateFromfileBaton {
      int error_code;
      const git_error* error;
      git_hashsig * out;
      const char * path;
      git_hashsig_option_t opts;
     };
    class CreateFromfileWorker : public nodegit::AsyncWorker {
      public:
        CreateFromfileWorker(
            CreateFromfileBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitHashsig:CreateFromfile", cleanupHandles)
          , baton(_baton) {};
        CreateFromfileWorker(const CreateFromfileWorker &) = delete;
        CreateFromfileWorker(CreateFromfileWorker &&) = delete;
        CreateFromfileWorker &operator=(const CreateFromfileWorker &) = delete;
        CreateFromfileWorker &operator=(CreateFromfileWorker &&) = delete;
        ~CreateFromfileWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateFromfileBaton *baton;
    };
     static Napi::Value CreateFromfile(const Napi::CallbackInfo& info);
 };

#endif
