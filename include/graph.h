// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITGRAPH_H
#define GITGRAPH_H
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
#include "../include/oid.h"

class GitGraph : public
  Napi::ObjectWrap<GitGraph>
{
   public:
    GitGraph(const GitGraph &) = delete;
    GitGraph(GitGraph &&) = delete;
    GitGraph &operator=(const GitGraph &) = delete;
    GitGraph &operator=(GitGraph &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                   
  private:


    struct AheadBehindBaton {
      int error_code;
      const git_error* error;
      size_t * ahead;
      size_t * behind;
      git_repository * repo;
      const git_oid * local;
      bool localNeedsFree;
      const git_oid * upstream;
      bool upstreamNeedsFree;
     };
    class AheadBehindWorker : public nodegit::AsyncWorker {
      public:
        AheadBehindWorker(
            AheadBehindBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitGraph:AheadBehind", cleanupHandles)
          , baton(_baton) {};
        AheadBehindWorker(const AheadBehindWorker &) = delete;
        AheadBehindWorker(AheadBehindWorker &&) = delete;
        AheadBehindWorker &operator=(const AheadBehindWorker &) = delete;
        AheadBehindWorker &operator=(AheadBehindWorker &&) = delete;
        ~AheadBehindWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AheadBehindBaton *baton;
    };
     static Napi::Value AheadBehind(const Napi::CallbackInfo& info);
 
    struct DescendantOfBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_oid * commit;
      bool commitNeedsFree;
      const git_oid * ancestor;
      bool ancestorNeedsFree;
     };
    class DescendantOfWorker : public nodegit::AsyncWorker {
      public:
        DescendantOfWorker(
            DescendantOfBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitGraph:DescendantOf", cleanupHandles)
          , baton(_baton) {};
        DescendantOfWorker(const DescendantOfWorker &) = delete;
        DescendantOfWorker(DescendantOfWorker &&) = delete;
        DescendantOfWorker &operator=(const DescendantOfWorker &) = delete;
        DescendantOfWorker &operator=(DescendantOfWorker &&) = delete;
        ~DescendantOfWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DescendantOfBaton *baton;
    };
     static Napi::Value DescendantOf(const Napi::CallbackInfo& info);
 
    struct ReachableFromAnyBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_oid * commit;
      bool commitNeedsFree;
      git_oid * descendant_array;
      size_t length;
     };
    class ReachableFromAnyWorker : public nodegit::AsyncWorker {
      public:
        ReachableFromAnyWorker(
            ReachableFromAnyBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitGraph:ReachableFromAny", cleanupHandles)
          , baton(_baton) {};
        ReachableFromAnyWorker(const ReachableFromAnyWorker &) = delete;
        ReachableFromAnyWorker(ReachableFromAnyWorker &&) = delete;
        ReachableFromAnyWorker &operator=(const ReachableFromAnyWorker &) = delete;
        ReachableFromAnyWorker &operator=(ReachableFromAnyWorker &&) = delete;
        ~ReachableFromAnyWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ReachableFromAnyBaton *baton;
    };
     static Napi::Value ReachableFromAny(const Napi::CallbackInfo& info);
 };

#endif
