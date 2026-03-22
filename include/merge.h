// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITMERGE_H
#define GITMERGE_H
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
#include "../include/annotated_commit.h"
#include "../include/merge_options.h"
#include "../include/checkout_options.h"
#include "../include/reference.h"
#include "../include/oid.h"
#include "../include/oidarray.h"
#include "../include/index.h"
#include "../include/commit.h"
#include "../include/tree.h"

class GitMerge : public
  Napi::ObjectWrap<GitMerge>
{
   public:
    GitMerge(const GitMerge &) = delete;
    GitMerge(GitMerge &&) = delete;
    GitMerge &operator=(const GitMerge &) = delete;
    GitMerge &operator=(GitMerge &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                  
  private:


    struct MergeBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_annotated_commit ** their_heads;
      size_t their_heads_len;
      git_merge_options * merge_opts;
      git_checkout_options * checkout_opts;
     };
    class MergeWorker : public nodegit::AsyncWorker {
      public:
        MergeWorker(
            MergeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMerge:Merge", cleanupHandles)
          , baton(_baton) {};
        MergeWorker(const MergeWorker &) = delete;
        MergeWorker(MergeWorker &&) = delete;
        MergeWorker &operator=(const MergeWorker &) = delete;
        MergeWorker &operator=(MergeWorker &&) = delete;
        ~MergeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        MergeBaton *baton;
    };
     static Napi::Value Merge(const Napi::CallbackInfo& info);
 
    struct AnalysisBaton {
      int error_code;
      const git_error* error;
      git_merge_analysis_t * analysis_out;
      git_merge_preference_t * preference_out;
      git_repository * repo;
      const git_annotated_commit ** their_heads;
      size_t their_heads_len;
     };
    class AnalysisWorker : public nodegit::AsyncWorker {
      public:
        AnalysisWorker(
            AnalysisBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMerge:Analysis", cleanupHandles)
          , baton(_baton) {};
        AnalysisWorker(const AnalysisWorker &) = delete;
        AnalysisWorker(AnalysisWorker &&) = delete;
        AnalysisWorker &operator=(const AnalysisWorker &) = delete;
        AnalysisWorker &operator=(AnalysisWorker &&) = delete;
        ~AnalysisWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AnalysisBaton *baton;
    };
     static Napi::Value Analysis(const Napi::CallbackInfo& info);
 
    struct AnalysisForRefBaton {
      int error_code;
      const git_error* error;
      git_merge_analysis_t * analysis_out;
      git_merge_preference_t * preference_out;
      git_repository * repo;
      git_reference * our_ref;
      const git_annotated_commit ** their_heads;
      size_t their_heads_len;
     };
    class AnalysisForRefWorker : public nodegit::AsyncWorker {
      public:
        AnalysisForRefWorker(
            AnalysisForRefBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMerge:AnalysisForRef", cleanupHandles)
          , baton(_baton) {};
        AnalysisForRefWorker(const AnalysisForRefWorker &) = delete;
        AnalysisForRefWorker(AnalysisForRefWorker &&) = delete;
        AnalysisForRefWorker &operator=(const AnalysisForRefWorker &) = delete;
        AnalysisForRefWorker &operator=(AnalysisForRefWorker &&) = delete;
        ~AnalysisForRefWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AnalysisForRefBaton *baton;
    };
     static Napi::Value AnalysisForRef(const Napi::CallbackInfo& info);
 
    struct BaseBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const git_oid * one;
      bool oneNeedsFree;
      const git_oid * two;
      bool twoNeedsFree;
     };
    class BaseWorker : public nodegit::AsyncWorker {
      public:
        BaseWorker(
            BaseBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMerge:Base", cleanupHandles)
          , baton(_baton) {};
        BaseWorker(const BaseWorker &) = delete;
        BaseWorker(BaseWorker &&) = delete;
        BaseWorker &operator=(const BaseWorker &) = delete;
        BaseWorker &operator=(BaseWorker &&) = delete;
        ~BaseWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        BaseBaton *baton;
    };
     static Napi::Value Base(const Napi::CallbackInfo& info);
 
    struct BasesBaton {
      int error_code;
      const git_error* error;
      git_oidarray * out;
      git_repository * repo;
      const git_oid * one;
      bool oneNeedsFree;
      const git_oid * two;
      bool twoNeedsFree;
     };
    class BasesWorker : public nodegit::AsyncWorker {
      public:
        BasesWorker(
            BasesBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMerge:Bases", cleanupHandles)
          , baton(_baton) {};
        BasesWorker(const BasesWorker &) = delete;
        BasesWorker(BasesWorker &&) = delete;
        BasesWorker &operator=(const BasesWorker &) = delete;
        BasesWorker &operator=(BasesWorker &&) = delete;
        ~BasesWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        BasesBaton *baton;
    };
     static Napi::Value Bases(const Napi::CallbackInfo& info);
 
    struct CommitsBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      git_repository * repo;
      const git_commit * our_commit;
      const git_commit * their_commit;
      const git_merge_options * opts;
     };
    class CommitsWorker : public nodegit::AsyncWorker {
      public:
        CommitsWorker(
            CommitsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMerge:Commits", cleanupHandles)
          , baton(_baton) {};
        CommitsWorker(const CommitsWorker &) = delete;
        CommitsWorker(CommitsWorker &&) = delete;
        CommitsWorker &operator=(const CommitsWorker &) = delete;
        CommitsWorker &operator=(CommitsWorker &&) = delete;
        ~CommitsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CommitsBaton *baton;
    };
     static Napi::Value Commits(const Napi::CallbackInfo& info);
 
    struct TreesBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      git_repository * repo;
      const git_tree * ancestor_tree;
      const git_tree * our_tree;
      const git_tree * their_tree;
      const git_merge_options * opts;
     };
    class TreesWorker : public nodegit::AsyncWorker {
      public:
        TreesWorker(
            TreesBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitMerge:Trees", cleanupHandles)
          , baton(_baton) {};
        TreesWorker(const TreesWorker &) = delete;
        TreesWorker(TreesWorker &&) = delete;
        TreesWorker &operator=(const TreesWorker &) = delete;
        TreesWorker &operator=(TreesWorker &&) = delete;
        ~TreesWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        TreesBaton *baton;
    };
     static Napi::Value Trees(const Napi::CallbackInfo& info);
 };

#endif
