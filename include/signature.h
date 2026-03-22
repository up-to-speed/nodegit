// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITSIGNATURE_H
#define GITSIGNATURE_H
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

#include "../include/time.h"
#include "../include/repository.h"
class GitSignature;
 
struct GitSignatureTraits {
  typedef GitSignature cppClass;
  typedef git_signature cType;
 
  static const bool isDuplicable = true;
  static void duplicate(git_signature **dest, git_signature *src) {
    git_signature_dup(dest, src);
   }

  static std::string className() { return "GitSignature"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_signature *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_signature_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitSignature : public
  NodeGitWrapper<GitSignatureTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitSignatureTraits>;
   public:
    GitSignature(const GitSignature &) = delete;
    GitSignature(GitSignature &&) = delete;
    GitSignature &operator=(const GitSignature &) = delete;
    GitSignature &operator=(GitSignature &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                              GitSignature(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitSignatureTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitSignature cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitSignature();

  private:

    Napi::Value Name(const Napi::CallbackInfo& info);
    Napi::Value Email(const Napi::CallbackInfo& info);
    Napi::Value When(const Napi::CallbackInfo& info);

    struct DefaultBaton {
      int error_code;
      const git_error* error;
      git_signature * out;
      git_repository * repo;
     };
    class DefaultWorker : public nodegit::AsyncWorker {
      public:
        DefaultWorker(
            DefaultBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSignature:Default", cleanupHandles)
          , baton(_baton) {};
        DefaultWorker(const DefaultWorker &) = delete;
        DefaultWorker(DefaultWorker &&) = delete;
        DefaultWorker &operator=(const DefaultWorker &) = delete;
        DefaultWorker &operator=(DefaultWorker &&) = delete;
        ~DefaultWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DefaultBaton *baton;
    };
     static Napi::Value Default(const Napi::CallbackInfo& info);
 
    struct DefaultFromEnvBaton {
      int error_code;
      const git_error* error;
      git_signature * author_out;
      git_signature * committer_out;
      git_repository * repo;
     };
    class DefaultFromEnvWorker : public nodegit::AsyncWorker {
      public:
        DefaultFromEnvWorker(
            DefaultFromEnvBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSignature:DefaultFromEnv", cleanupHandles)
          , baton(_baton) {};
        DefaultFromEnvWorker(const DefaultFromEnvWorker &) = delete;
        DefaultFromEnvWorker(DefaultFromEnvWorker &&) = delete;
        DefaultFromEnvWorker &operator=(const DefaultFromEnvWorker &) = delete;
        DefaultFromEnvWorker &operator=(DefaultFromEnvWorker &&) = delete;
        ~DefaultFromEnvWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DefaultFromEnvBaton *baton;
    };
     static Napi::Value DefaultFromEnv(const Napi::CallbackInfo& info);
 
    struct FromBufferBaton {
      int error_code;
      const git_error* error;
      git_signature * out;
      const char * buf;
     };
    class FromBufferWorker : public nodegit::AsyncWorker {
      public:
        FromBufferWorker(
            FromBufferBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitSignature:FromBuffer", cleanupHandles)
          , baton(_baton) {};
        FromBufferWorker(const FromBufferWorker &) = delete;
        FromBufferWorker(FromBufferWorker &&) = delete;
        FromBufferWorker &operator=(const FromBufferWorker &) = delete;
        FromBufferWorker &operator=(FromBufferWorker &&) = delete;
        ~FromBufferWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FromBufferBaton *baton;
    };
     static Napi::Value FromBuffer(const Napi::CallbackInfo& info);
      static Napi::Value Create(const Napi::CallbackInfo& info);
      static Napi::Value Now(const Napi::CallbackInfo& info);
 };

#endif
