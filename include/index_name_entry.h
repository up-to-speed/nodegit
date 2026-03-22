// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITINDEXNAMEENTRY_H
#define GITINDEXNAMEENTRY_H
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
#include <git2/sys/index.h>
}

#include "../include/typedefs.h"

#include "../include/index.h"
class GitIndexNameEntry;
 
struct GitIndexNameEntryTraits {
  typedef GitIndexNameEntry cppClass;
  typedef git_index_name_entry cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_index_name_entry **dest, git_index_name_entry *src) {
     throw std::runtime_error("duplicate called on GitIndexNameEntry which cannot be duplicated");
   }

  static std::string className() { return "GitIndexNameEntry"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_index_name_entry *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitIndexNameEntry : public
  NodeGitWrapper<GitIndexNameEntryTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitIndexNameEntryTraits>;
   public:
    GitIndexNameEntry(const GitIndexNameEntry &) = delete;
    GitIndexNameEntry(GitIndexNameEntry &&) = delete;
    GitIndexNameEntry &operator=(const GitIndexNameEntry &) = delete;
    GitIndexNameEntry &operator=(GitIndexNameEntry &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                     GitIndexNameEntry(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitIndexNameEntryTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitIndexNameEntry cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitIndexNameEntry();

  private:

    Napi::Value Ancestor(const Napi::CallbackInfo& info);
    Napi::Value Ours(const Napi::CallbackInfo& info);
    Napi::Value Theirs(const Napi::CallbackInfo& info);

    struct AddBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const char * ancestor;
      const char * ours;
      const char * theirs;
     };
    class AddWorker : public nodegit::AsyncWorker {
      public:
        AddWorker(
            AddBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndexNameEntry:Add", cleanupHandles)
          , baton(_baton) {};
        AddWorker(const AddWorker &) = delete;
        AddWorker(AddWorker &&) = delete;
        AddWorker &operator=(const AddWorker &) = delete;
        AddWorker &operator=(AddWorker &&) = delete;
        ~AddWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddBaton *baton;
    };
     static Napi::Value Add(const Napi::CallbackInfo& info);
 
    struct ClearBaton {
      int error_code;
      const git_error* error;
      git_index * index;
     };
    class ClearWorker : public nodegit::AsyncWorker {
      public:
        ClearWorker(
            ClearBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndexNameEntry:Clear", cleanupHandles)
          , baton(_baton) {};
        ClearWorker(const ClearWorker &) = delete;
        ClearWorker(ClearWorker &&) = delete;
        ClearWorker &operator=(const ClearWorker &) = delete;
        ClearWorker &operator=(ClearWorker &&) = delete;
        ~ClearWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ClearBaton *baton;
    };
     static Napi::Value Clear(const Napi::CallbackInfo& info);
      static Napi::Value Entrycount(const Napi::CallbackInfo& info);
      static Napi::Value GetByIndex(const Napi::CallbackInfo& info);
 };

#endif
