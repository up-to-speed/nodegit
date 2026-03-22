// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFFSTATS_H
#define GITDIFFSTATS_H
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

#include "../include/buf.h"
// Forward declaration.
struct git_diff_stats {
};
class GitDiffStats;
 
struct GitDiffStatsTraits {
  typedef GitDiffStats cppClass;
  typedef git_diff_stats cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_stats **dest, git_diff_stats *src) {
     throw std::runtime_error("duplicate called on GitDiffStats which cannot be duplicated");
   }

  static std::string className() { return "GitDiffStats"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_stats *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_diff_stats_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiffStats : public
  NodeGitWrapper<GitDiffStatsTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffStatsTraits>;
   public:
    GitDiffStats(const GitDiffStats &) = delete;
    GitDiffStats(GitDiffStats &&) = delete;
    GitDiffStats &operator=(const GitDiffStats &) = delete;
    GitDiffStats &operator=(GitDiffStats &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                    GitDiffStats(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffStatsTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiffStats cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiffStats();

  private:

    Napi::Value FilesChanged(const Napi::CallbackInfo& info);
     Napi::Value Insertions(const Napi::CallbackInfo& info);
     Napi::Value Deletions(const Napi::CallbackInfo& info);
 
    struct DiffStatsToBufBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_diff_stats * stats;
      git_diff_stats_format_t format;
      size_t width;
     };
    class DiffStatsToBufWorker : public nodegit::AsyncWorker {
      public:
        DiffStatsToBufWorker(
            DiffStatsToBufBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiffStats:DiffStatsToBuf", cleanupHandles)
          , baton(_baton) {};
        DiffStatsToBufWorker(const DiffStatsToBufWorker &) = delete;
        DiffStatsToBufWorker(DiffStatsToBufWorker &&) = delete;
        DiffStatsToBufWorker &operator=(const DiffStatsToBufWorker &) = delete;
        DiffStatsToBufWorker &operator=(DiffStatsToBufWorker &&) = delete;
        ~DiffStatsToBufWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DiffStatsToBufBaton *baton;
    };
    Napi::Value DiffStatsToBuf(const Napi::CallbackInfo& info);
 };

#endif
