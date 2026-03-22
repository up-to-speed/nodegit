// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITAPPLY_H
#define GITAPPLY_H
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
#include "../include/diff.h"
#include "../include/apply_options.h"
#include "../include/index.h"
#include "../include/tree.h"

class GitApply : public
  Napi::ObjectWrap<GitApply>
{
   public:
    GitApply(const GitApply &) = delete;
    GitApply(GitApply &&) = delete;
    GitApply &operator=(const GitApply &) = delete;
    GitApply &operator=(GitApply &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

              
  private:


    struct ApplyBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_diff * diff;
      git_apply_location_t location;
      const git_apply_options * options;
     };
    class ApplyWorker : public nodegit::AsyncWorker {
      public:
        ApplyWorker(
            ApplyBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitApply:Apply", cleanupHandles)
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
 
    struct ToTreeBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      git_repository * repo;
      git_tree * preimage;
      git_diff * diff;
      const git_apply_options * options;
     };
    class ToTreeWorker : public nodegit::AsyncWorker {
      public:
        ToTreeWorker(
            ToTreeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitApply:ToTree", cleanupHandles)
          , baton(_baton) {};
        ToTreeWorker(const ToTreeWorker &) = delete;
        ToTreeWorker(ToTreeWorker &&) = delete;
        ToTreeWorker &operator=(const ToTreeWorker &) = delete;
        ToTreeWorker &operator=(ToTreeWorker &&) = delete;
        ~ToTreeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ToTreeBaton *baton;
    };
     static Napi::Value ToTree(const Napi::CallbackInfo& info);
 };

#endif
