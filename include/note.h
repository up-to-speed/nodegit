// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITNOTE_H
#define GITNOTE_H
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

#include "../include/signature.h"
#include "../include/oid.h"
#include "../include/repository.h"
#include "../include/commit.h"
#include "../include/note_iterator.h"
#include "../include/buf.h"
// Forward declaration.
struct git_note {
};
class GitNote;
 
struct GitNoteTraits {
  typedef GitNote cppClass;
  typedef git_note cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_note **dest, git_note *src) {
     throw std::runtime_error("duplicate called on GitNote which cannot be duplicated");
   }

  static std::string className() { return "GitNote"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_note *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_note_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitNote : public
  NodeGitWrapper<GitNoteTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitNoteTraits>;
   public:
    GitNote(const GitNote &) = delete;
    GitNote(GitNote &&) = delete;
    GitNote &operator=(const GitNote &) = delete;
    GitNote &operator=(GitNote &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                       static int Foreach_note_cb_cppCallback (
      const git_oid * blob_id
      ,
       const git_oid * annotated_object_id
      ,
       void * payload
      );

    static void Foreach_note_cb_cancelAsync(void *baton);
    static void Foreach_note_cb_async(void *baton);
    static void Foreach_note_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class Foreach_NoteCbBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const git_oid * blob_id;
      const git_oid * annotated_object_id;
      void * payload;
 

      Foreach_NoteCbBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                            GitNote(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitNoteTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitNote cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitNote();

  private:

    Napi::Value Author(const Napi::CallbackInfo& info);
      static Napi::Value CommitCreate(const Napi::CallbackInfo& info);
 
    struct CommitIteratorNewBaton {
      int error_code;
      const git_error* error;
      git_note_iterator * out;
      git_commit * notes_commit;
     };
    class CommitIteratorNewWorker : public nodegit::AsyncWorker {
      public:
        CommitIteratorNewWorker(
            CommitIteratorNewBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitNote:CommitIteratorNew", cleanupHandles)
          , baton(_baton) {};
        CommitIteratorNewWorker(const CommitIteratorNewWorker &) = delete;
        CommitIteratorNewWorker(CommitIteratorNewWorker &&) = delete;
        CommitIteratorNewWorker &operator=(const CommitIteratorNewWorker &) = delete;
        CommitIteratorNewWorker &operator=(CommitIteratorNewWorker &&) = delete;
        ~CommitIteratorNewWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CommitIteratorNewBaton *baton;
    };
     static Napi::Value CommitIteratorNew(const Napi::CallbackInfo& info);
 
    struct CommitReadBaton {
      int error_code;
      const git_error* error;
      git_note * out;
      git_repository * repo;
      git_commit * notes_commit;
      const git_oid * oid;
      bool oidNeedsFree;
     };
    class CommitReadWorker : public nodegit::AsyncWorker {
      public:
        CommitReadWorker(
            CommitReadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitNote:CommitRead", cleanupHandles)
          , baton(_baton) {};
        CommitReadWorker(const CommitReadWorker &) = delete;
        CommitReadWorker(CommitReadWorker &&) = delete;
        CommitReadWorker &operator=(const CommitReadWorker &) = delete;
        CommitReadWorker &operator=(CommitReadWorker &&) = delete;
        ~CommitReadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CommitReadBaton *baton;
    };
     static Napi::Value CommitRead(const Napi::CallbackInfo& info);
 
    struct CommitRemoveBaton {
      int error_code;
      const git_error* error;
      git_oid * notes_commit_out;
      git_repository * repo;
      git_commit * notes_commit;
      const git_signature * author;
      const git_signature * committer;
      const git_oid * oid;
      bool oidNeedsFree;
     };
    class CommitRemoveWorker : public nodegit::AsyncWorker {
      public:
        CommitRemoveWorker(
            CommitRemoveBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitNote:CommitRemove", cleanupHandles)
          , baton(_baton) {};
        CommitRemoveWorker(const CommitRemoveWorker &) = delete;
        CommitRemoveWorker(CommitRemoveWorker &&) = delete;
        CommitRemoveWorker &operator=(const CommitRemoveWorker &) = delete;
        CommitRemoveWorker &operator=(CommitRemoveWorker &&) = delete;
        ~CommitRemoveWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CommitRemoveBaton *baton;
    };
     static Napi::Value CommitRemove(const Napi::CallbackInfo& info);
     Napi::Value Committer(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const char * notes_ref;
      const git_signature * author;
      const git_signature * committer;
      const git_oid * oid;
      bool oidNeedsFree;
      const char * note;
      int force;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitNote:Create", cleanupHandles)
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
 
    struct DefaultRefBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_repository * repo;
     };
    class DefaultRefWorker : public nodegit::AsyncWorker {
      public:
        DefaultRefWorker(
            DefaultRefBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitNote:DefaultRef", cleanupHandles)
          , baton(_baton) {};
        DefaultRefWorker(const DefaultRefWorker &) = delete;
        DefaultRefWorker(DefaultRefWorker &&) = delete;
        DefaultRefWorker &operator=(const DefaultRefWorker &) = delete;
        DefaultRefWorker &operator=(DefaultRefWorker &&) = delete;
        ~DefaultRefWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DefaultRefBaton *baton;
    };
     static Napi::Value DefaultRef(const Napi::CallbackInfo& info);
 
    struct ForeachBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * notes_ref;
      git_note_foreach_cb note_cb;
      void * payload;
     };
    class ForeachWorker : public nodegit::AsyncWorker {
      public:
        ForeachWorker(
            ForeachBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitNote:Foreach", cleanupHandles)
          , baton(_baton) {};
        ForeachWorker(const ForeachWorker &) = delete;
        ForeachWorker(ForeachWorker &&) = delete;
        ForeachWorker &operator=(const ForeachWorker &) = delete;
        ForeachWorker &operator=(ForeachWorker &&) = delete;
        ~ForeachWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ForeachBaton *baton;
    };
     static Napi::Value Foreach(const Napi::CallbackInfo& info);
     Napi::Value Id(const Napi::CallbackInfo& info);
     Napi::Value Message(const Napi::CallbackInfo& info);
 
    struct ReadBaton {
      int error_code;
      const git_error* error;
      git_note * out;
      git_repository * repo;
      const char * notes_ref;
      const git_oid * oid;
      bool oidNeedsFree;
     };
    class ReadWorker : public nodegit::AsyncWorker {
      public:
        ReadWorker(
            ReadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitNote:Read", cleanupHandles)
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
 
    struct RemoveBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * notes_ref;
      const git_signature * author;
      const git_signature * committer;
      const git_oid * oid;
      bool oidNeedsFree;
     };
    class RemoveWorker : public nodegit::AsyncWorker {
      public:
        RemoveWorker(
            RemoveBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitNote:Remove", cleanupHandles)
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
 
    struct Foreach_globalPayload {
      Napi::FunctionReference * note_cb;

      Foreach_globalPayload() {
        note_cb = NULL;
      }

      Foreach_globalPayload(const Foreach_globalPayload &) = delete;
      Foreach_globalPayload(Foreach_globalPayload &&) = delete;
      Foreach_globalPayload &operator=(const Foreach_globalPayload &) = delete;
      Foreach_globalPayload &operator=(Foreach_globalPayload &&) = delete;

      ~Foreach_globalPayload() {
        if (note_cb != NULL) {
          delete note_cb;
        }
      }
    };
};

#endif
