// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITMAILMAP_H
#define GITMAILMAP_H
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
#include "../include/signature.h"
// Forward declaration.
struct git_mailmap {
};
class GitMailmap;
 
struct GitMailmapTraits {
  typedef GitMailmap cppClass;
  typedef git_mailmap cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_mailmap **dest, git_mailmap *src) {
     throw std::runtime_error("duplicate called on GitMailmap which cannot be duplicated");
   }

  static std::string className() { return "GitMailmap"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_mailmap *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_mailmap_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitMailmap : public
  NodeGitWrapper<GitMailmapTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitMailmapTraits>;
   public:
    GitMailmap(const GitMailmap &) = delete;
    GitMailmap(GitMailmap &&) = delete;
    GitMailmap &operator=(const GitMailmap &) = delete;
    GitMailmap &operator=(GitMailmap &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                    GitMailmap(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitMailmapTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitMailmap cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitMailmap();

  private:


    struct AddEntryBaton {
      int error_code;
      const git_error* error;
      git_mailmap * mm;
      const char * real_name;
      const char * real_email;
      const char * replace_name;
      const char * replace_email;
     };
    class AddEntryWorker : public nodegit::AsyncWorker {
      public:
        AddEntryWorker(
            AddEntryBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMailmap:AddEntry", cleanupHandles)
          , baton(_baton) {};
        AddEntryWorker(const AddEntryWorker &) = delete;
        AddEntryWorker(AddEntryWorker &&) = delete;
        AddEntryWorker &operator=(const AddEntryWorker &) = delete;
        AddEntryWorker &operator=(AddEntryWorker &&) = delete;
        ~AddEntryWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddEntryBaton *baton;
    };
    Napi::Value AddEntry(const Napi::CallbackInfo& info);
 
    struct FromBufferBaton {
      int error_code;
      const git_error* error;
      git_mailmap * out;
      const char * buf;
      size_t len;
     };
    class FromBufferWorker : public nodegit::AsyncWorker {
      public:
        FromBufferWorker(
            FromBufferBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMailmap:FromBuffer", cleanupHandles)
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
 
    struct FromRepositoryBaton {
      int error_code;
      const git_error* error;
      git_mailmap * out;
      git_repository * repo;
     };
    class FromRepositoryWorker : public nodegit::AsyncWorker {
      public:
        FromRepositoryWorker(
            FromRepositoryBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMailmap:FromRepository", cleanupHandles)
          , baton(_baton) {};
        FromRepositoryWorker(const FromRepositoryWorker &) = delete;
        FromRepositoryWorker(FromRepositoryWorker &&) = delete;
        FromRepositoryWorker &operator=(const FromRepositoryWorker &) = delete;
        FromRepositoryWorker &operator=(FromRepositoryWorker &&) = delete;
        ~FromRepositoryWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FromRepositoryBaton *baton;
    };
     static Napi::Value FromRepository(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_mailmap * out;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMailmap:Create", cleanupHandles)
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
 
    struct ResolveBaton {
      int error_code;
      const git_error* error;
      const char * real_name;
      const char * real_email;
      const git_mailmap * mm;
      const char * name;
      const char * email;
     };
    class ResolveWorker : public nodegit::AsyncWorker {
      public:
        ResolveWorker(
            ResolveBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMailmap:Resolve", cleanupHandles)
          , baton(_baton) {};
        ResolveWorker(const ResolveWorker &) = delete;
        ResolveWorker(ResolveWorker &&) = delete;
        ResolveWorker &operator=(const ResolveWorker &) = delete;
        ResolveWorker &operator=(ResolveWorker &&) = delete;
        ~ResolveWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ResolveBaton *baton;
    };
    Napi::Value Resolve(const Napi::CallbackInfo& info);
 
    struct ResolveSignatureBaton {
      int error_code;
      const git_error* error;
      git_signature * out;
      const git_mailmap * mm;
      const git_signature * sig;
     };
    class ResolveSignatureWorker : public nodegit::AsyncWorker {
      public:
        ResolveSignatureWorker(
            ResolveSignatureBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMailmap:ResolveSignature", cleanupHandles)
          , baton(_baton) {};
        ResolveSignatureWorker(const ResolveSignatureWorker &) = delete;
        ResolveSignatureWorker(ResolveSignatureWorker &&) = delete;
        ResolveSignatureWorker &operator=(const ResolveSignatureWorker &) = delete;
        ResolveSignatureWorker &operator=(ResolveSignatureWorker &&) = delete;
        ~ResolveSignatureWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ResolveSignatureBaton *baton;
    };
    Napi::Value ResolveSignature(const Napi::CallbackInfo& info);
 };

#endif
