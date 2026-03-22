// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITINDEXCONFLICTITERATOR_H
#define GITINDEXCONFLICTITERATOR_H
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

#include "../include/index.h"
#include "../include/index_entry.h"
// Forward declaration.
struct git_index_conflict_iterator {
};
class GitIndexConflictIterator;
 
struct GitIndexConflictIteratorTraits {
  typedef GitIndexConflictIterator cppClass;
  typedef git_index_conflict_iterator cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_index_conflict_iterator **dest, git_index_conflict_iterator *src) {
     throw std::runtime_error("duplicate called on GitIndexConflictIterator which cannot be duplicated");
   }

  static std::string className() { return "GitIndexConflictIterator"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_index_conflict_iterator *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_index_conflict_iterator_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitIndexConflictIterator : public
  NodeGitWrapper<GitIndexConflictIteratorTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitIndexConflictIteratorTraits>;
   public:
    GitIndexConflictIterator(const GitIndexConflictIterator &) = delete;
    GitIndexConflictIterator(GitIndexConflictIterator &&) = delete;
    GitIndexConflictIterator &operator=(const GitIndexConflictIterator &) = delete;
    GitIndexConflictIterator &operator=(GitIndexConflictIterator &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

               GitIndexConflictIterator(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitIndexConflictIteratorTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitIndexConflictIterator cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitIndexConflictIterator();

  private:


    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_index_conflict_iterator * iterator_out;
      git_index * index;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndexConflictIterator:Create", cleanupHandles)
          , baton(_baton) {};
        CreateWorker(const CreateWorker &) = delete;
        CreateWorker(CreateWorker &&) = delete;
        CreateWorker &operator=(const CreateWorker &) = delete;
        CreateWorker &operator=(CreateWorker &&) = delete;
        ~CreateWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateBaton *baton;
    };
     static Napi::Value Create(const Napi::CallbackInfo& info);
     Napi::Value Next(const Napi::CallbackInfo& info);
 };

#endif
