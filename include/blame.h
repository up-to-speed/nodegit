// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITBLAME_H
#define GITBLAME_H
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

#include "../include/blame_hunk.h"
#include "../include/blame_line.h"
#include "../include/repository.h"
#include "../include/blame_options.h"
// Forward declaration.
struct git_blame {
};
class GitBlame;
 
struct GitBlameTraits {
  typedef GitBlame cppClass;
  typedef git_blame cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_blame **dest, git_blame *src) {
     throw std::runtime_error("duplicate called on GitBlame which cannot be duplicated");
   }

  static std::string className() { return "GitBlame"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_blame *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_blame_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitBlame : public
  NodeGitWrapper<GitBlameTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitBlameTraits>;
   public:
    GitBlame(const GitBlame &) = delete;
    GitBlame(GitBlame &&) = delete;
    GitBlame &operator=(const GitBlame &) = delete;
    GitBlame &operator=(GitBlame &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                              GitBlame(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitBlameTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitBlame cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitBlame();

  private:


    struct BufferBaton {
      int error_code;
      const git_error* error;
      git_blame * out;
      git_blame * base;
      const char * buffer;
      size_t buffer_len;
     };
    class BufferWorker : public nodegit::AsyncWorker {
      public:
        BufferWorker(
            BufferBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlame:Buffer", cleanupHandles)
          , baton(_baton) {};
        BufferWorker(const BufferWorker &) = delete;
        BufferWorker(BufferWorker &&) = delete;
        BufferWorker &operator=(const BufferWorker &) = delete;
        BufferWorker &operator=(BufferWorker &&) = delete;
        ~BufferWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        BufferBaton *baton;
    };
    Napi::Value Buffer(const Napi::CallbackInfo& info);
     Napi::Value GetHunkByindex(const Napi::CallbackInfo& info);
     Napi::Value GetHunkByline(const Napi::CallbackInfo& info);
     Napi::Value GetHunkCount(const Napi::CallbackInfo& info);
     Napi::Value HunkByindex(const Napi::CallbackInfo& info);
     Napi::Value HunkByline(const Napi::CallbackInfo& info);
     Napi::Value Hunkcount(const Napi::CallbackInfo& info);
     Napi::Value LineByindex(const Napi::CallbackInfo& info);
     Napi::Value Linecount(const Napi::CallbackInfo& info);
 
    struct FileBaton {
      int error_code;
      const git_error* error;
      git_blame * out;
      git_repository * repo;
      const char * path;
      git_blame_options * options;
     };
    class FileWorker : public nodegit::AsyncWorker {
      public:
        FileWorker(
            FileBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlame:File", cleanupHandles)
          , baton(_baton) {};
        FileWorker(const FileWorker &) = delete;
        FileWorker(FileWorker &&) = delete;
        FileWorker &operator=(const FileWorker &) = delete;
        FileWorker &operator=(FileWorker &&) = delete;
        ~FileWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FileBaton *baton;
    };
     static Napi::Value File(const Napi::CallbackInfo& info);
 };

#endif
