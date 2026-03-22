// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITINDEXREUCENTRY_H
#define GITINDEXREUCENTRY_H
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

#include "../include/oid.h"
#include "../include/index.h"
class GitIndexReucEntry;
 
struct GitIndexReucEntryTraits {
  typedef GitIndexReucEntry cppClass;
  typedef git_index_reuc_entry cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_index_reuc_entry **dest, git_index_reuc_entry *src) {
     throw std::runtime_error("duplicate called on GitIndexReucEntry which cannot be duplicated");
   }

  static std::string className() { return "GitIndexReucEntry"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_index_reuc_entry *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitIndexReucEntry : public
  NodeGitWrapper<GitIndexReucEntryTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitIndexReucEntryTraits>;
   public:
    GitIndexReucEntry(const GitIndexReucEntry &) = delete;
    GitIndexReucEntry(GitIndexReucEntry &&) = delete;
    GitIndexReucEntry &operator=(const GitIndexReucEntry &) = delete;
    GitIndexReucEntry &operator=(GitIndexReucEntry &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                      GitIndexReucEntry(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitIndexReucEntryTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitIndexReucEntry cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitIndexReucEntry();

  private:

    Napi::Value Mode(const Napi::CallbackInfo& info);
    Napi::Value Oid(const Napi::CallbackInfo& info);
    Napi::Value Path(const Napi::CallbackInfo& info);

    struct AddBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const char * path;
      int ancestor_mode;
      const git_oid * ancestor_id;
      bool ancestor_idNeedsFree;
      int our_mode;
      const git_oid * our_id;
      bool our_idNeedsFree;
      int their_mode;
      const git_oid * their_id;
      bool their_idNeedsFree;
     };
    class AddWorker : public nodegit::AsyncWorker {
      public:
        AddWorker(
            AddBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndexReucEntry:Add", cleanupHandles)
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
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndexReucEntry:Clear", cleanupHandles)
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
 
    struct FindBaton {
      int error_code;
      const git_error* error;
      size_t * at_pos;
      git_index * index;
      const char * path;
     };
    class FindWorker : public nodegit::AsyncWorker {
      public:
        FindWorker(
            FindBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndexReucEntry:Find", cleanupHandles)
          , baton(_baton) {};
        FindWorker(const FindWorker &) = delete;
        FindWorker(FindWorker &&) = delete;
        FindWorker &operator=(const FindWorker &) = delete;
        FindWorker &operator=(FindWorker &&) = delete;
        ~FindWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FindBaton *baton;
    };
     static Napi::Value Find(const Napi::CallbackInfo& info);
      static Napi::Value GetByIndex(const Napi::CallbackInfo& info);
      static Napi::Value GetByPath(const Napi::CallbackInfo& info);
 
    struct RemoveBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      size_t n;
     };
    class RemoveWorker : public nodegit::AsyncWorker {
      public:
        RemoveWorker(
            RemoveBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndexReucEntry:Remove", cleanupHandles)
          , baton(_baton) {};
        RemoveWorker(const RemoveWorker &) = delete;
        RemoveWorker(RemoveWorker &&) = delete;
        RemoveWorker &operator=(const RemoveWorker &) = delete;
        RemoveWorker &operator=(RemoveWorker &&) = delete;
        ~RemoveWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RemoveBaton *baton;
    };
     static Napi::Value Remove(const Napi::CallbackInfo& info);
 };

#endif
