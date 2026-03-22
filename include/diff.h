// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFF_H
#define GITDIFF_H
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
#include <git2/sys/diff.h>
}

#include "../include/typedefs.h"

#include "../include/blob.h"
#include "../include/diff_options.h"
#include "../include/diff_delta.h"
#include "../include/diff_binary.h"
#include "../include/diff_hunk.h"
#include "../include/diff_line.h"
#include "../include/diff_find_options.h"
#include "../include/diff_stats.h"
#include "../include/repository.h"
#include "../include/index.h"
#include "../include/oid.h"
#include "../include/diff_patchid_options.h"
#include "../include/buf.h"
#include "../include/tree.h"
#include "../include/diff_perfdata.h"
// Forward declaration.
struct git_diff {
};
class GitDiff;
 
struct GitDiffTraits {
  typedef GitDiff cppClass;
  typedef git_diff cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff **dest, git_diff *src) {
     throw std::runtime_error("duplicate called on GitDiff which cannot be duplicated");
   }

  static std::string className() { return "GitDiff"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_diff_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiff : public
  NodeGitWrapper<GitDiffTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffTraits>;
   public:
    GitDiff(const GitDiff &) = delete;
    GitDiff(GitDiff &&) = delete;
    GitDiff &operator=(const GitDiff &) = delete;
    GitDiff &operator=(GitDiff &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

          static int BlobToBuffer_file_cb_cppCallback (
      const git_diff_delta * delta
      ,
       float progress
      ,
       void * payload
      );

    static void BlobToBuffer_file_cb_cancelAsync(void *baton);
    static void BlobToBuffer_file_cb_async(void *baton);
    static void BlobToBuffer_file_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class BlobToBuffer_FileCbBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const git_diff_delta * delta;
      float progress;
      void * payload;
 

      BlobToBuffer_FileCbBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
     static int BlobToBuffer_binary_cb_cppCallback (
      const git_diff_delta * delta
      ,
       const git_diff_binary * binary
      ,
       void * payload
      );

    static void BlobToBuffer_binary_cb_cancelAsync(void *baton);
    static void BlobToBuffer_binary_cb_async(void *baton);
    static void BlobToBuffer_binary_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class BlobToBuffer_BinaryCbBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const git_diff_delta * delta;
      const git_diff_binary * binary;
      void * payload;
 

      BlobToBuffer_BinaryCbBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
     static int BlobToBuffer_hunk_cb_cppCallback (
      const git_diff_delta * delta
      ,
       const git_diff_hunk * hunk
      ,
       void * payload
      );

    static void BlobToBuffer_hunk_cb_cancelAsync(void *baton);
    static void BlobToBuffer_hunk_cb_async(void *baton);
    static void BlobToBuffer_hunk_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class BlobToBuffer_HunkCbBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const git_diff_delta * delta;
      const git_diff_hunk * hunk;
      void * payload;
 

      BlobToBuffer_HunkCbBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
     static int BlobToBuffer_line_cb_cppCallback (
      const git_diff_delta * delta
      ,
       const git_diff_hunk * hunk
      ,
       const git_diff_line * line
      ,
       void * payload
      );

    static void BlobToBuffer_line_cb_cancelAsync(void *baton);
    static void BlobToBuffer_line_cb_async(void *baton);
    static void BlobToBuffer_line_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class BlobToBuffer_LineCbBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const git_diff_delta * delta;
      const git_diff_hunk * hunk;
      const git_diff_line * line;
      void * payload;
 

      BlobToBuffer_LineCbBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                                                                                         GitDiff(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiff cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiff();

  private:


    struct BlobToBufferBaton {
      int error_code;
      const git_error* error;
      const git_blob * old_blob;
      const char * old_as_path;
      const char * buffer;
      size_t buffer_len;
      const char * buffer_as_path;
      const git_diff_options * options;
      git_diff_file_cb file_cb;
      git_diff_binary_cb binary_cb;
      git_diff_hunk_cb hunk_cb;
      git_diff_line_cb line_cb;
      void * payload;
     };
    class BlobToBufferWorker : public nodegit::AsyncWorker {
      public:
        BlobToBufferWorker(
            BlobToBufferBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:BlobToBuffer", cleanupHandles)
          , baton(_baton) {};
        BlobToBufferWorker(const BlobToBufferWorker &) = delete;
        BlobToBufferWorker(BlobToBufferWorker &&) = delete;
        BlobToBufferWorker &operator=(const BlobToBufferWorker &) = delete;
        BlobToBufferWorker &operator=(BlobToBufferWorker &&) = delete;
        ~BlobToBufferWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        BlobToBufferBaton *baton;
    };
     static Napi::Value BlobToBuffer(const Napi::CallbackInfo& info);
 
    struct FindSimilarBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      const git_diff_find_options * options;
     };
    class FindSimilarWorker : public nodegit::AsyncWorker {
      public:
        FindSimilarWorker(
            FindSimilarBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:FindSimilar", cleanupHandles)
          , baton(_baton) {};
        FindSimilarWorker(const FindSimilarWorker &) = delete;
        FindSimilarWorker(FindSimilarWorker &&) = delete;
        FindSimilarWorker &operator=(const FindSimilarWorker &) = delete;
        FindSimilarWorker &operator=(FindSimilarWorker &&) = delete;
        ~FindSimilarWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FindSimilarBaton *baton;
    };
    Napi::Value FindSimilar(const Napi::CallbackInfo& info);
 
    struct FromBufferBaton {
      int error_code;
      const git_error* error;
      git_diff * out;
      const char * content;
      size_t content_len;
     };
    class FromBufferWorker : public nodegit::AsyncWorker {
      public:
        FromBufferWorker(
            FromBufferBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:FromBuffer", cleanupHandles)
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
     Napi::Value GetDelta(const Napi::CallbackInfo& info);
 
    struct GetStatsBaton {
      int error_code;
      const git_error* error;
      git_diff_stats * out;
      git_diff * diff;
     };
    class GetStatsWorker : public nodegit::AsyncWorker {
      public:
        GetStatsWorker(
            GetStatsBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:GetStats", cleanupHandles)
          , baton(_baton) {};
        GetStatsWorker(const GetStatsWorker &) = delete;
        GetStatsWorker(GetStatsWorker &&) = delete;
        GetStatsWorker &operator=(const GetStatsWorker &) = delete;
        GetStatsWorker &operator=(GetStatsWorker &&) = delete;
        ~GetStatsWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetStatsBaton *baton;
    };
    Napi::Value GetStats(const Napi::CallbackInfo& info);
 
    struct IndexToIndexBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_index * old_index;
      git_index * new_index;
      const git_diff_options * opts;
     };
    class IndexToIndexWorker : public nodegit::AsyncWorker {
      public:
        IndexToIndexWorker(
            IndexToIndexBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:IndexToIndex", cleanupHandles)
          , baton(_baton) {};
        IndexToIndexWorker(const IndexToIndexWorker &) = delete;
        IndexToIndexWorker(IndexToIndexWorker &&) = delete;
        IndexToIndexWorker &operator=(const IndexToIndexWorker &) = delete;
        IndexToIndexWorker &operator=(IndexToIndexWorker &&) = delete;
        ~IndexToIndexWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        IndexToIndexBaton *baton;
    };
     static Napi::Value IndexToIndex(const Napi::CallbackInfo& info);
 
    struct IndexToWorkdirBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_index * index;
      const git_diff_options * opts;
     };
    class IndexToWorkdirWorker : public nodegit::AsyncWorker {
      public:
        IndexToWorkdirWorker(
            IndexToWorkdirBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:IndexToWorkdir", cleanupHandles)
          , baton(_baton) {};
        IndexToWorkdirWorker(const IndexToWorkdirWorker &) = delete;
        IndexToWorkdirWorker(IndexToWorkdirWorker &&) = delete;
        IndexToWorkdirWorker &operator=(const IndexToWorkdirWorker &) = delete;
        IndexToWorkdirWorker &operator=(IndexToWorkdirWorker &&) = delete;
        ~IndexToWorkdirWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        IndexToWorkdirBaton *baton;
    };
     static Napi::Value IndexToWorkdir(const Napi::CallbackInfo& info);
     Napi::Value IsSortedIcase(const Napi::CallbackInfo& info);
 
    struct MergeBaton {
      int error_code;
      const git_error* error;
      git_diff * onto;
      const git_diff * from;
     };
    class MergeWorker : public nodegit::AsyncWorker {
      public:
        MergeWorker(
            MergeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:Merge", cleanupHandles)
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
    Napi::Value Merge(const Napi::CallbackInfo& info);
     Napi::Value NumDeltas(const Napi::CallbackInfo& info);
 
    struct PatchidBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_diff * diff;
      git_diff_patchid_options * opts;
     };
    class PatchidWorker : public nodegit::AsyncWorker {
      public:
        PatchidWorker(
            PatchidBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:Patchid", cleanupHandles)
          , baton(_baton) {};
        PatchidWorker(const PatchidWorker &) = delete;
        PatchidWorker(PatchidWorker &&) = delete;
        PatchidWorker &operator=(const PatchidWorker &) = delete;
        PatchidWorker &operator=(PatchidWorker &&) = delete;
        ~PatchidWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        PatchidBaton *baton;
    };
    Napi::Value Patchid(const Napi::CallbackInfo& info);
 
    struct ToBufBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_diff * diff;
      git_diff_format_t format;
     };
    class ToBufWorker : public nodegit::AsyncWorker {
      public:
        ToBufWorker(
            ToBufBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:ToBuf", cleanupHandles)
          , baton(_baton) {};
        ToBufWorker(const ToBufWorker &) = delete;
        ToBufWorker(ToBufWorker &&) = delete;
        ToBufWorker &operator=(const ToBufWorker &) = delete;
        ToBufWorker &operator=(ToBufWorker &&) = delete;
        ~ToBufWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ToBufBaton *baton;
    };
    Napi::Value ToBuf(const Napi::CallbackInfo& info);
 
    struct TreeToIndexBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_tree * old_tree;
      git_index * index;
      const git_diff_options * opts;
     };
    class TreeToIndexWorker : public nodegit::AsyncWorker {
      public:
        TreeToIndexWorker(
            TreeToIndexBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:TreeToIndex", cleanupHandles)
          , baton(_baton) {};
        TreeToIndexWorker(const TreeToIndexWorker &) = delete;
        TreeToIndexWorker(TreeToIndexWorker &&) = delete;
        TreeToIndexWorker &operator=(const TreeToIndexWorker &) = delete;
        TreeToIndexWorker &operator=(TreeToIndexWorker &&) = delete;
        ~TreeToIndexWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        TreeToIndexBaton *baton;
    };
     static Napi::Value TreeToIndex(const Napi::CallbackInfo& info);
 
    struct TreeToTreeBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_tree * old_tree;
      git_tree * new_tree;
      const git_diff_options * opts;
     };
    class TreeToTreeWorker : public nodegit::AsyncWorker {
      public:
        TreeToTreeWorker(
            TreeToTreeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:TreeToTree", cleanupHandles)
          , baton(_baton) {};
        TreeToTreeWorker(const TreeToTreeWorker &) = delete;
        TreeToTreeWorker(TreeToTreeWorker &&) = delete;
        TreeToTreeWorker &operator=(const TreeToTreeWorker &) = delete;
        TreeToTreeWorker &operator=(TreeToTreeWorker &&) = delete;
        ~TreeToTreeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        TreeToTreeBaton *baton;
    };
     static Napi::Value TreeToTree(const Napi::CallbackInfo& info);
 
    struct TreeToWorkdirBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_tree * old_tree;
      const git_diff_options * opts;
     };
    class TreeToWorkdirWorker : public nodegit::AsyncWorker {
      public:
        TreeToWorkdirWorker(
            TreeToWorkdirBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:TreeToWorkdir", cleanupHandles)
          , baton(_baton) {};
        TreeToWorkdirWorker(const TreeToWorkdirWorker &) = delete;
        TreeToWorkdirWorker(TreeToWorkdirWorker &&) = delete;
        TreeToWorkdirWorker &operator=(const TreeToWorkdirWorker &) = delete;
        TreeToWorkdirWorker &operator=(TreeToWorkdirWorker &&) = delete;
        ~TreeToWorkdirWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        TreeToWorkdirBaton *baton;
    };
     static Napi::Value TreeToWorkdir(const Napi::CallbackInfo& info);
 
    struct TreeToWorkdirWithIndexBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_tree * old_tree;
      const git_diff_options * opts;
     };
    class TreeToWorkdirWithIndexWorker : public nodegit::AsyncWorker {
      public:
        TreeToWorkdirWithIndexWorker(
            TreeToWorkdirWithIndexBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitDiff:TreeToWorkdirWithIndex", cleanupHandles)
          , baton(_baton) {};
        TreeToWorkdirWithIndexWorker(const TreeToWorkdirWithIndexWorker &) = delete;
        TreeToWorkdirWithIndexWorker(TreeToWorkdirWithIndexWorker &&) = delete;
        TreeToWorkdirWithIndexWorker &operator=(const TreeToWorkdirWithIndexWorker &) = delete;
        TreeToWorkdirWithIndexWorker &operator=(TreeToWorkdirWithIndexWorker &&) = delete;
        ~TreeToWorkdirWithIndexWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        TreeToWorkdirWithIndexBaton *baton;
    };
     static Napi::Value TreeToWorkdirWithIndex(const Napi::CallbackInfo& info);
     Napi::Value GetPerfdata(const Napi::CallbackInfo& info);
 
    struct BlobToBuffer_globalPayload {
      Napi::FunctionReference * file_cb;
      Napi::FunctionReference * binary_cb;
      Napi::FunctionReference * hunk_cb;
      Napi::FunctionReference * line_cb;

      BlobToBuffer_globalPayload() {
        file_cb = NULL;
        binary_cb = NULL;
        hunk_cb = NULL;
        line_cb = NULL;
      }

      BlobToBuffer_globalPayload(const BlobToBuffer_globalPayload &) = delete;
      BlobToBuffer_globalPayload(BlobToBuffer_globalPayload &&) = delete;
      BlobToBuffer_globalPayload &operator=(const BlobToBuffer_globalPayload &) = delete;
      BlobToBuffer_globalPayload &operator=(BlobToBuffer_globalPayload &&) = delete;

      ~BlobToBuffer_globalPayload() {
        if (file_cb != NULL) {
          delete file_cb;
        }
        if (binary_cb != NULL) {
          delete binary_cb;
        }
        if (hunk_cb != NULL) {
          delete hunk_cb;
        }
        if (line_cb != NULL) {
          delete line_cb;
        }
      }
    };
};

#endif
