// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITSTASH_H
#define GITSTASH_H
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
#include "../include/stash_apply_options.h"
#include "../include/oid.h"
#include "../include/signature.h"
#include "../include/stash_save_options.h"

class GitStash : public
  Napi::ObjectWrap<GitStash>
{
   public:
    GitStash(const GitStash &) = delete;
    GitStash(GitStash &&) = delete;
    GitStash &operator=(const GitStash &) = delete;
    GitStash &operator=(GitStash &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

              static int Foreach_callback_cppCallback (
      size_t index
      ,
       const char * message
      ,
       const git_oid * stash_id
      ,
       void * payload
      );

    static void Foreach_callback_cancelAsync(void *baton);
    static void Foreach_callback_async(void *baton);
    static void Foreach_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class Foreach_CallbackBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      size_t index;
      const char * message;
      const git_oid * stash_id;
      void * payload;
 

      Foreach_CallbackBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                      
  private:


    struct ApplyBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      size_t index;
      const git_stash_apply_options * options;
     };
    class ApplyWorker : public nodegit::AsyncWorker {
      public:
        ApplyWorker(
            ApplyBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitStash:Apply", cleanupHandles)
          , baton(_baton) {};
        ApplyWorker(const ApplyWorker &) = delete;
        ApplyWorker(ApplyWorker &&) = delete;
        ApplyWorker &operator=(const ApplyWorker &) = delete;
        ApplyWorker &operator=(ApplyWorker &&) = delete;
        ~ApplyWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ApplyBaton *baton;
    };
     static Napi::Value Apply(const Napi::CallbackInfo& info);
 
    struct DropBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      size_t index;
     };
    class DropWorker : public nodegit::AsyncWorker {
      public:
        DropWorker(
            DropBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitStash:Drop", cleanupHandles)
          , baton(_baton) {};
        DropWorker(const DropWorker &) = delete;
        DropWorker(DropWorker &&) = delete;
        DropWorker &operator=(const DropWorker &) = delete;
        DropWorker &operator=(DropWorker &&) = delete;
        ~DropWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DropBaton *baton;
    };
     static Napi::Value Drop(const Napi::CallbackInfo& info);
 
    struct ForeachBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_stash_cb callback;
      void * payload;
     };
    class ForeachWorker : public nodegit::AsyncWorker {
      public:
        ForeachWorker(
            ForeachBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitStash:Foreach", cleanupHandles)
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
 
    struct PopBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      size_t index;
      const git_stash_apply_options * options;
     };
    class PopWorker : public nodegit::AsyncWorker {
      public:
        PopWorker(
            PopBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitStash:Pop", cleanupHandles)
          , baton(_baton) {};
        PopWorker(const PopWorker &) = delete;
        PopWorker(PopWorker &&) = delete;
        PopWorker &operator=(const PopWorker &) = delete;
        PopWorker &operator=(PopWorker &&) = delete;
        ~PopWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        PopBaton *baton;
    };
     static Napi::Value Pop(const Napi::CallbackInfo& info);
 
    struct SaveBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const git_signature * stasher;
      const char * message;
      uint32_t flags;
     };
    class SaveWorker : public nodegit::AsyncWorker {
      public:
        SaveWorker(
            SaveBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitStash:Save", cleanupHandles)
          , baton(_baton) {};
        SaveWorker(const SaveWorker &) = delete;
        SaveWorker(SaveWorker &&) = delete;
        SaveWorker &operator=(const SaveWorker &) = delete;
        SaveWorker &operator=(SaveWorker &&) = delete;
        ~SaveWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SaveBaton *baton;
    };
     static Napi::Value Save(const Napi::CallbackInfo& info);
 
    struct SaveWithOptsBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const git_stash_save_options * opts;
     };
    class SaveWithOptsWorker : public nodegit::AsyncWorker {
      public:
        SaveWithOptsWorker(
            SaveWithOptsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitStash:SaveWithOpts", cleanupHandles)
          , baton(_baton) {};
        SaveWithOptsWorker(const SaveWithOptsWorker &) = delete;
        SaveWithOptsWorker(SaveWithOptsWorker &&) = delete;
        SaveWithOptsWorker &operator=(const SaveWithOptsWorker &) = delete;
        SaveWithOptsWorker &operator=(SaveWithOptsWorker &&) = delete;
        ~SaveWithOptsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SaveWithOptsBaton *baton;
    };
     static Napi::Value SaveWithOpts(const Napi::CallbackInfo& info);
 
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
