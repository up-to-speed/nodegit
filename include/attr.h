// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITATTR_H
#define GITATTR_H
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
#include "../include/attr_options.h"

class GitAttr : public
  Napi::ObjectWrap<GitAttr>
{
   public:
    GitAttr(const GitAttr &) = delete;
    GitAttr(GitAttr &&) = delete;
    GitAttr &operator=(const GitAttr &) = delete;
    GitAttr &operator=(GitAttr &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

               static int ForeachExt_callback_cppCallback (
      const char * name
      ,
       const char * value
      ,
       void * payload
      );

    static void ForeachExt_callback_cancelAsync(void *baton);
    static void ForeachExt_callback_async(void *baton);
    static void ForeachExt_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class ForeachExt_CallbackBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const char * name;
      const char * value;
      void * payload;
 

      ForeachExt_CallbackBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                                      
  private:

     static Napi::Value AddMacro(const Napi::CallbackInfo& info);
      static Napi::Value CacheFlush(const Napi::CallbackInfo& info);
 
    struct ForeachExtBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_attr_options * opts;
      const char * path;
      git_attr_foreach_cb callback;
      void * payload;
        int result;
     };
    class ForeachExtWorker : public nodegit::AsyncWorker {
      public:
        ForeachExtWorker(
            ForeachExtBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitAttr:ForeachExt", cleanupHandles)
          , baton(_baton) {};
        ForeachExtWorker(const ForeachExtWorker &) = delete;
        ForeachExtWorker(ForeachExtWorker &&) = delete;
        ForeachExtWorker &operator=(const ForeachExtWorker &) = delete;
        ForeachExtWorker &operator=(ForeachExtWorker &&) = delete;
        ~ForeachExtWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ForeachExtBaton *baton;
    };
     static Napi::Value ForeachExt(const Napi::CallbackInfo& info);
 
    struct GetBaton {
      int error_code;
      const git_error* error;
      const char * value_out;
      git_repository * repo;
      uint32_t flags;
      const char * path;
      const char * name;
     };
    class GetWorker : public nodegit::AsyncWorker {
      public:
        GetWorker(
            GetBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitAttr:Get", cleanupHandles)
          , baton(_baton) {};
        GetWorker(const GetWorker &) = delete;
        GetWorker(GetWorker &&) = delete;
        GetWorker &operator=(const GetWorker &) = delete;
        GetWorker &operator=(GetWorker &&) = delete;
        ~GetWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetBaton *baton;
    };
     static Napi::Value Get(const Napi::CallbackInfo& info);
      static Napi::Value GetExt(const Napi::CallbackInfo& info);
 
    struct GetManyBaton {
      int error_code;
      const git_error* error;
      const char * values_out;
      git_repository * repo;
      uint32_t flags;
      const char * path;
      size_t num_attr;
      const char ** names;
     };
    class GetManyWorker : public nodegit::AsyncWorker {
      public:
        GetManyWorker(
            GetManyBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitAttr:GetMany", cleanupHandles)
          , baton(_baton) {};
        GetManyWorker(const GetManyWorker &) = delete;
        GetManyWorker(GetManyWorker &&) = delete;
        GetManyWorker &operator=(const GetManyWorker &) = delete;
        GetManyWorker &operator=(GetManyWorker &&) = delete;
        ~GetManyWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetManyBaton *baton;
    };
     static Napi::Value GetMany(const Napi::CallbackInfo& info);
      static Napi::Value GetManyExt(const Napi::CallbackInfo& info);
      static Napi::Value Value(const Napi::CallbackInfo& info);
 
    struct ForeachExt_globalPayload {
      Napi::FunctionReference * callback;

      ForeachExt_globalPayload() {
        callback = NULL;
      }

      ForeachExt_globalPayload(const ForeachExt_globalPayload &) = delete;
      ForeachExt_globalPayload(ForeachExt_globalPayload &&) = delete;
      ForeachExt_globalPayload &operator=(const ForeachExt_globalPayload &) = delete;
      ForeachExt_globalPayload &operator=(ForeachExt_globalPayload &&) = delete;

      ~ForeachExt_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };
};

#endif
