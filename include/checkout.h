// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCHECKOUT_H
#define GITCHECKOUT_H
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
#include "../include/checkout_options.h"
#include "../include/index.h"
#include "../include/object.h"

class GitCheckout : public
  Napi::ObjectWrap<GitCheckout>
{
   public:
    GitCheckout(const GitCheckout &) = delete;
    GitCheckout(GitCheckout &&) = delete;
    GitCheckout &operator=(const GitCheckout &) = delete;
    GitCheckout &operator=(GitCheckout &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

               
  private:


    struct HeadBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_checkout_options * opts;
     };
    class HeadWorker : public nodegit::AsyncWorker {
      public:
        HeadWorker(
            HeadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCheckout:Head", cleanupHandles)
          , baton(_baton) {};
        HeadWorker(const HeadWorker &) = delete;
        HeadWorker(HeadWorker &&) = delete;
        HeadWorker &operator=(const HeadWorker &) = delete;
        HeadWorker &operator=(HeadWorker &&) = delete;
        ~HeadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        HeadBaton *baton;
    };
     static Napi::Value Head(const Napi::CallbackInfo& info);
 
    struct IndexBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_index * index;
      const git_checkout_options * opts;
     };
    class IndexWorker : public nodegit::AsyncWorker {
      public:
        IndexWorker(
            IndexBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCheckout:Index", cleanupHandles)
          , baton(_baton) {};
        IndexWorker(const IndexWorker &) = delete;
        IndexWorker(IndexWorker &&) = delete;
        IndexWorker &operator=(const IndexWorker &) = delete;
        IndexWorker &operator=(IndexWorker &&) = delete;
        ~IndexWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        IndexBaton *baton;
    };
     static Napi::Value Index(const Napi::CallbackInfo& info);
 
    struct TreeBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_object * treeish;
      const git_checkout_options * opts;
     };
    class TreeWorker : public nodegit::AsyncWorker {
      public:
        TreeWorker(
            TreeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCheckout:Tree", cleanupHandles)
          , baton(_baton) {};
        TreeWorker(const TreeWorker &) = delete;
        TreeWorker(TreeWorker &&) = delete;
        TreeWorker &operator=(const TreeWorker &) = delete;
        TreeWorker &operator=(TreeWorker &&) = delete;
        ~TreeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        TreeBaton *baton;
    };
     static Napi::Value Tree(const Napi::CallbackInfo& info);
 };

#endif
