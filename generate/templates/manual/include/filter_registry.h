#ifndef GITFILTERREGISTRY_H
#define GITFILTERREGISTRY_H
#include <napi.h>
#include <string>
#include <utility>

#include "async_baton.h"
#include "async_worker.h"
#include "cleanup_handle.h"
#include "context.h"
#include "lock_master.h"
#include "bungit_wrapper.h"
#include "promise_completion.h"

extern "C" {
#include <git2.h>
}

#include "../include/typedefs.h"

#include "../include/filter.h"


class GitFilterRegistry : public Napi::ObjectWrap<GitFilterRegistry> {
   public:
    static void InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext);

  private:

    GitFilterRegistry(const Napi::CallbackInfo& info) : Napi::ObjectWrap<GitFilterRegistry>(info) {}

    static Napi::Value GitFilterRegister(const Napi::CallbackInfo& info);

    static Napi::Value GitFilterUnregister(const Napi::CallbackInfo& info);

    struct FilterRegisterBaton {
      const git_error *error;
      git_filter *filter;
      char *filter_name;
      int filter_priority;
      int error_code;
    };

    struct FilterUnregisterBaton {
      const git_error *error;
      char *filter_name;
      int error_code;
    };

    class RegisterWorker : public nodegit::AsyncWorker {
      public:
        RegisterWorker(FilterRegisterBaton *_baton, Napi::FunctionReference callback, std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles)
        : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:FilterRegistry:Register", cleanupHandles), baton(_baton) {};
        RegisterWorker(const RegisterWorker &) = delete;
        RegisterWorker(RegisterWorker &&) = delete;
        RegisterWorker &operator=(const RegisterWorker &) = delete;
        RegisterWorker &operator=(RegisterWorker &&) = delete;
        ~RegisterWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FilterRegisterBaton *baton;
    };

    class UnregisterWorker : public nodegit::AsyncWorker {
      public:
        UnregisterWorker(FilterUnregisterBaton *_baton, Napi::FunctionReference callback)
        : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:FilterRegistry:Unregister"), baton(_baton) {};
        UnregisterWorker(const UnregisterWorker &) = delete;
        UnregisterWorker(UnregisterWorker &&) = delete;
        UnregisterWorker &operator=(const UnregisterWorker &) = delete;
        UnregisterWorker &operator=(UnregisterWorker &&) = delete;
        ~UnregisterWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FilterUnregisterBaton *baton;
    };
};

#endif
