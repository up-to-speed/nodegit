// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITRESET_H
#define GITRESET_H
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

#include "../include/str_array_converter.h"
#include "../include/repository.h"
#include "../include/object.h"
#include "../include/checkout_options.h"
#include "../include/strarray.h"
#include "../include/annotated_commit.h"

class GitReset : public
  Napi::ObjectWrap<GitReset>
{
   public:
    GitReset(const GitReset &) = delete;
    GitReset(GitReset &&) = delete;
    GitReset &operator=(const GitReset &) = delete;
    GitReset &operator=(GitReset &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                  
  private:


    struct ResetBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_object * target;
      git_reset_t reset_type;
      const git_checkout_options * checkout_opts;
     };
    class ResetWorker : public nodegit::AsyncWorker {
      public:
        ResetWorker(
            ResetBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitReset:Reset", cleanupHandles)
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
     static Napi::Value Reset(const Napi::CallbackInfo& info);
 
    struct DefaultBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_object * target;
      const git_strarray * pathspecs;
     };
    class DefaultWorker : public nodegit::AsyncWorker {
      public:
        DefaultWorker(
            DefaultBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitReset:Default", cleanupHandles)
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
 
    struct FromAnnotatedBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_annotated_commit * target;
      git_reset_t reset_type;
      const git_checkout_options * checkout_opts;
     };
    class FromAnnotatedWorker : public nodegit::AsyncWorker {
      public:
        FromAnnotatedWorker(
            FromAnnotatedBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitReset:FromAnnotated", cleanupHandles)
          , baton(_baton) {};
        FromAnnotatedWorker(const FromAnnotatedWorker &) = delete;
        FromAnnotatedWorker(FromAnnotatedWorker &&) = delete;
        FromAnnotatedWorker &operator=(const FromAnnotatedWorker &) = delete;
        FromAnnotatedWorker &operator=(FromAnnotatedWorker &&) = delete;
        ~FromAnnotatedWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FromAnnotatedBaton *baton;
    };
     static Napi::Value FromAnnotated(const Napi::CallbackInfo& info);
 };

#endif
