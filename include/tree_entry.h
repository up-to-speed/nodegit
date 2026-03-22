// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITTREEENTRY_H
#define GITTREEENTRY_H
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
#include "../include/object.h"
#include "../include/repository.h"
// Forward declaration.
struct git_tree_entry {
};
class GitTreeEntry;
 
struct GitTreeEntryTraits {
  typedef GitTreeEntry cppClass;
  typedef git_tree_entry cType;
 
  static const bool isDuplicable = true;
  static void duplicate(git_tree_entry **dest, git_tree_entry *src) {
    git_tree_entry_dup(dest, src);
   }

  static std::string className() { return "GitTreeEntry"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_tree_entry *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_tree_entry_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitTreeEntry : public
  NodeGitWrapper<GitTreeEntryTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitTreeEntryTraits>;
   public:
    GitTreeEntry(const GitTreeEntry &) = delete;
    GitTreeEntry(GitTreeEntry &&) = delete;
    GitTreeEntry &operator=(const GitTreeEntry &) = delete;
    GitTreeEntry &operator=(GitTreeEntry &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                         GitTreeEntry(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitTreeEntryTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitTreeEntry cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitTreeEntry();

  private:

    Napi::Value Filemode(const Napi::CallbackInfo& info);
     Napi::Value FilemodeRaw(const Napi::CallbackInfo& info);
     Napi::Value Id(const Napi::CallbackInfo& info);
     Napi::Value Name(const Napi::CallbackInfo& info);
 
    struct ToObjectBaton {
      int error_code;
      const git_error* error;
      git_object * object_out;
      git_repository * repo;
      const git_tree_entry * entry;
     };
    class ToObjectWorker : public nodegit::AsyncWorker {
      public:
        ToObjectWorker(
            ToObjectBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTreeEntry:ToObject", cleanupHandles)
          , baton(_baton) {};
        ToObjectWorker(const ToObjectWorker &) = delete;
        ToObjectWorker(ToObjectWorker &&) = delete;
        ToObjectWorker &operator=(const ToObjectWorker &) = delete;
        ToObjectWorker &operator=(ToObjectWorker &&) = delete;
        ~ToObjectWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ToObjectBaton *baton;
    };
    Napi::Value ToObject(const Napi::CallbackInfo& info);
     Napi::Value Type(const Napi::CallbackInfo& info);
 };

#endif
