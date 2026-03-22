// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREFLOG_H
#define GITREFLOG_H
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

#include "../include/oid.h"
#include "../include/signature.h"
#include "../include/repository.h"
#include "../include/reflog_entry.h"
// Forward declaration.
struct git_reflog {
};
class GitReflog;
 
struct GitReflogTraits {
  typedef GitReflog cppClass;
  typedef git_reflog cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_reflog **dest, git_reflog *src) {
     throw std::runtime_error("duplicate called on GitReflog which cannot be duplicated");
   }

  static std::string className() { return "GitReflog"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_reflog *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_reflog_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitReflog : public
  NodeGitWrapper<GitReflogTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitReflogTraits>;
   public:
    GitReflog(const GitReflog &) = delete;
    GitReflog(GitReflog &&) = delete;
    GitReflog &operator=(const GitReflog &) = delete;
    GitReflog &operator=(GitReflog &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                        GitReflog(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitReflogTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitReflog cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitReflog();

  private:

    Napi::Value Append(const Napi::CallbackInfo& info);
      static Napi::Value Delete(const Napi::CallbackInfo& info);
     Napi::Value Drop(const Napi::CallbackInfo& info);
     Napi::Value EntryByindex(const Napi::CallbackInfo& info);
     Napi::Value Entrycount(const Napi::CallbackInfo& info);
 
    struct ReadBaton {
      int error_code;
      const git_error* error;
      git_reflog * out;
      git_repository * repo;
      const char * name;
     };
    class ReadWorker : public nodegit::AsyncWorker {
      public:
        ReadWorker(
            ReadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitReflog:Read", cleanupHandles)
          , baton(_baton) {};
        ReadWorker(const ReadWorker &) = delete;
        ReadWorker(ReadWorker &&) = delete;
        ReadWorker &operator=(const ReadWorker &) = delete;
        ReadWorker &operator=(ReadWorker &&) = delete;
        ~ReadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ReadBaton *baton;
    };
     static Napi::Value Read(const Napi::CallbackInfo& info);
      static Napi::Value Rename(const Napi::CallbackInfo& info);
 
    struct WriteBaton {
      int error_code;
      const git_error* error;
      git_reflog * reflog;
     };
    class WriteWorker : public nodegit::AsyncWorker {
      public:
        WriteWorker(
            WriteBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitReflog:Write", cleanupHandles)
          , baton(_baton) {};
        WriteWorker(const WriteWorker &) = delete;
        WriteWorker(WriteWorker &&) = delete;
        WriteWorker &operator=(const WriteWorker &) = delete;
        WriteWorker &operator=(WriteWorker &&) = delete;
        ~WriteWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        WriteBaton *baton;
    };
    Napi::Value Write(const Napi::CallbackInfo& info);
 };

#endif
