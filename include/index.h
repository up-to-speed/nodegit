// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITINDEX_H
#define GITINDEX_H
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

#include "../include/str_array_converter.h"
#include "../include/index_entry.h"
#include "../include/strarray.h"
#include "../include/oid.h"
#include "../include/tree.h"
#include "../include/repository.h"
// Forward declaration.
struct git_index {
};
class GitIndex;
 
struct GitIndexTraits {
  typedef GitIndex cppClass;
  typedef git_index cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_index **dest, git_index *src) {
     throw std::runtime_error("duplicate called on GitIndex which cannot be duplicated");
   }

  static std::string className() { return "GitIndex"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_index *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_index_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitIndex : public
  NodeGitWrapper<GitIndexTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitIndexTraits>;
   public:
    GitIndex(const GitIndex &) = delete;
    GitIndex(GitIndex &&) = delete;
    GitIndex &operator=(const GitIndex &) = delete;
    GitIndex &operator=(GitIndex &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

           static int AddAll_callback_cppCallback (
      const char * path
      ,
       const char * matched_pathspec
      ,
       void * payload
      );

    static void AddAll_callback_cancelAsync(void *baton);
    static void AddAll_callback_async(void *baton);
    static void AddAll_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class AddAll_CallbackBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const char * path;
      const char * matched_pathspec;
      void * payload;
 

      AddAll_CallbackBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                                                                                                 static int RemoveAll_callback_cppCallback (
      const char * path
      ,
       const char * matched_pathspec
      ,
       void * payload
      );

    static void RemoveAll_callback_cancelAsync(void *baton);
    static void RemoveAll_callback_async(void *baton);
    static void RemoveAll_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class RemoveAll_CallbackBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const char * path;
      const char * matched_pathspec;
      void * payload;
 

      RemoveAll_CallbackBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                           static int UpdateAll_callback_cppCallback (
      const char * path
      ,
       const char * matched_pathspec
      ,
       void * payload
      );

    static void UpdateAll_callback_cancelAsync(void *baton);
    static void UpdateAll_callback_async(void *baton);
    static void UpdateAll_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
    class UpdateAll_CallbackBaton : public nodegit::AsyncBatonWithResult<int> {
    public:
      const char * path;
      const char * matched_pathspec;
      void * payload;
 

      UpdateAll_CallbackBaton(const int &defaultResult)
        : nodegit::AsyncBatonWithResult<int>(defaultResult) {
        }
    };
                        GitIndex(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitIndexTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitIndex cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitIndex();

  private:


    struct AddBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const git_index_entry * source_entry;
     };
    class AddWorker : public nodegit::AsyncWorker {
      public:
        AddWorker(
            AddBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:Add", cleanupHandles)
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
    Napi::Value Add(const Napi::CallbackInfo& info);
 
    struct AddAllBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const git_strarray * pathspec;
      unsigned int flags;
      git_index_matched_path_cb callback;
      void * payload;
     };
    class AddAllWorker : public nodegit::AsyncWorker {
      public:
        AddAllWorker(
            AddAllBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:AddAll", cleanupHandles)
          , baton(_baton) {};
        AddAllWorker(const AddAllWorker &) = delete;
        AddAllWorker(AddAllWorker &&) = delete;
        AddAllWorker &operator=(const AddAllWorker &) = delete;
        AddAllWorker &operator=(AddAllWorker &&) = delete;
        ~AddAllWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddAllBaton *baton;
    };
    Napi::Value AddAll(const Napi::CallbackInfo& info);
 
    struct AddBypathBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const char * path;
     };
    class AddBypathWorker : public nodegit::AsyncWorker {
      public:
        AddBypathWorker(
            AddBypathBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:AddBypath", cleanupHandles)
          , baton(_baton) {};
        AddBypathWorker(const AddBypathWorker &) = delete;
        AddBypathWorker(AddBypathWorker &&) = delete;
        AddBypathWorker &operator=(const AddBypathWorker &) = delete;
        AddBypathWorker &operator=(AddBypathWorker &&) = delete;
        ~AddBypathWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AddBypathBaton *baton;
    };
    Napi::Value AddBypath(const Napi::CallbackInfo& info);
     Napi::Value Caps(const Napi::CallbackInfo& info);
     Napi::Value Checksum(const Napi::CallbackInfo& info);
 
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
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:Clear", cleanupHandles)
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
    Napi::Value Clear(const Napi::CallbackInfo& info);
 
    struct ConflictAddBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const git_index_entry * ancestor_entry;
      const git_index_entry * our_entry;
      const git_index_entry * their_entry;
     };
    class ConflictAddWorker : public nodegit::AsyncWorker {
      public:
        ConflictAddWorker(
            ConflictAddBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:ConflictAdd", cleanupHandles)
          , baton(_baton) {};
        ConflictAddWorker(const ConflictAddWorker &) = delete;
        ConflictAddWorker(ConflictAddWorker &&) = delete;
        ConflictAddWorker &operator=(const ConflictAddWorker &) = delete;
        ConflictAddWorker &operator=(ConflictAddWorker &&) = delete;
        ~ConflictAddWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ConflictAddBaton *baton;
    };
    Napi::Value ConflictAdd(const Napi::CallbackInfo& info);
 
    struct ConflictCleanupBaton {
      int error_code;
      const git_error* error;
      git_index * index;
     };
    class ConflictCleanupWorker : public nodegit::AsyncWorker {
      public:
        ConflictCleanupWorker(
            ConflictCleanupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:ConflictCleanup", cleanupHandles)
          , baton(_baton) {};
        ConflictCleanupWorker(const ConflictCleanupWorker &) = delete;
        ConflictCleanupWorker(ConflictCleanupWorker &&) = delete;
        ConflictCleanupWorker &operator=(const ConflictCleanupWorker &) = delete;
        ConflictCleanupWorker &operator=(ConflictCleanupWorker &&) = delete;
        ~ConflictCleanupWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ConflictCleanupBaton *baton;
    };
    Napi::Value ConflictCleanup(const Napi::CallbackInfo& info);
 
    struct ConflictGetBaton {
      int error_code;
      const git_error* error;
      const git_index_entry * ancestor_out;
      const git_index_entry * our_out;
      const git_index_entry * their_out;
      git_index * index;
      const char * path;
     };
    class ConflictGetWorker : public nodegit::AsyncWorker {
      public:
        ConflictGetWorker(
            ConflictGetBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:ConflictGet", cleanupHandles)
          , baton(_baton) {};
        ConflictGetWorker(const ConflictGetWorker &) = delete;
        ConflictGetWorker(ConflictGetWorker &&) = delete;
        ConflictGetWorker &operator=(const ConflictGetWorker &) = delete;
        ConflictGetWorker &operator=(ConflictGetWorker &&) = delete;
        ~ConflictGetWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ConflictGetBaton *baton;
    };
    Napi::Value ConflictGet(const Napi::CallbackInfo& info);
 
    struct ConflictRemoveBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const char * path;
     };
    class ConflictRemoveWorker : public nodegit::AsyncWorker {
      public:
        ConflictRemoveWorker(
            ConflictRemoveBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:ConflictRemove", cleanupHandles)
          , baton(_baton) {};
        ConflictRemoveWorker(const ConflictRemoveWorker &) = delete;
        ConflictRemoveWorker(ConflictRemoveWorker &&) = delete;
        ConflictRemoveWorker &operator=(const ConflictRemoveWorker &) = delete;
        ConflictRemoveWorker &operator=(ConflictRemoveWorker &&) = delete;
        ~ConflictRemoveWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ConflictRemoveBaton *baton;
    };
    Napi::Value ConflictRemove(const Napi::CallbackInfo& info);
      static Napi::Value EntryIsConflict(const Napi::CallbackInfo& info);
      static Napi::Value EntryStage(const Napi::CallbackInfo& info);
     Napi::Value Entrycount(const Napi::CallbackInfo& info);
 
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
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:Find", cleanupHandles)
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
    Napi::Value Find(const Napi::CallbackInfo& info);
 
    struct FindPrefixBaton {
      int error_code;
      const git_error* error;
      size_t * at_pos;
      git_index * index;
      const char * prefix;
     };
    class FindPrefixWorker : public nodegit::AsyncWorker {
      public:
        FindPrefixWorker(
            FindPrefixBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:FindPrefix", cleanupHandles)
          , baton(_baton) {};
        FindPrefixWorker(const FindPrefixWorker &) = delete;
        FindPrefixWorker(FindPrefixWorker &&) = delete;
        FindPrefixWorker &operator=(const FindPrefixWorker &) = delete;
        FindPrefixWorker &operator=(FindPrefixWorker &&) = delete;
        ~FindPrefixWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FindPrefixBaton *baton;
    };
    Napi::Value FindPrefix(const Napi::CallbackInfo& info);
     Napi::Value GetByindex(const Napi::CallbackInfo& info);
     Napi::Value GetBypath(const Napi::CallbackInfo& info);
     Napi::Value HasConflicts(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_index * index_out;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:Create", cleanupHandles)
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
 
    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_index * index_out;
      const char * index_path;
     };
    class OpenWorker : public nodegit::AsyncWorker {
      public:
        OpenWorker(
            OpenBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:Open", cleanupHandles)
          , baton(_baton) {};
        OpenWorker(const OpenWorker &) = delete;
        OpenWorker(OpenWorker &&) = delete;
        OpenWorker &operator=(const OpenWorker &) = delete;
        OpenWorker &operator=(OpenWorker &&) = delete;
        ~OpenWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OpenBaton *baton;
    };
     static Napi::Value Open(const Napi::CallbackInfo& info);
     Napi::Value Path(const Napi::CallbackInfo& info);
 
    struct ReadBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      int force;
     };
    class ReadWorker : public nodegit::AsyncWorker {
      public:
        ReadWorker(
            ReadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:Read", cleanupHandles)
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
    Napi::Value Read(const Napi::CallbackInfo& info);
 
    struct ReadTreeBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const git_tree * tree;
     };
    class ReadTreeWorker : public nodegit::AsyncWorker {
      public:
        ReadTreeWorker(
            ReadTreeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:ReadTree", cleanupHandles)
          , baton(_baton) {};
        ReadTreeWorker(const ReadTreeWorker &) = delete;
        ReadTreeWorker(ReadTreeWorker &&) = delete;
        ReadTreeWorker &operator=(const ReadTreeWorker &) = delete;
        ReadTreeWorker &operator=(ReadTreeWorker &&) = delete;
        ~ReadTreeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ReadTreeBaton *baton;
    };
    Napi::Value ReadTree(const Napi::CallbackInfo& info);
 
    struct RemoveBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const char * path;
      int stage;
     };
    class RemoveWorker : public nodegit::AsyncWorker {
      public:
        RemoveWorker(
            RemoveBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:Remove", cleanupHandles)
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
    Napi::Value Remove(const Napi::CallbackInfo& info);
 
    struct RemoveAllBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const git_strarray * pathspec;
      git_index_matched_path_cb callback;
      void * payload;
     };
    class RemoveAllWorker : public nodegit::AsyncWorker {
      public:
        RemoveAllWorker(
            RemoveAllBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:RemoveAll", cleanupHandles)
          , baton(_baton) {};
        RemoveAllWorker(const RemoveAllWorker &) = delete;
        RemoveAllWorker(RemoveAllWorker &&) = delete;
        RemoveAllWorker &operator=(const RemoveAllWorker &) = delete;
        RemoveAllWorker &operator=(RemoveAllWorker &&) = delete;
        ~RemoveAllWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RemoveAllBaton *baton;
    };
    Napi::Value RemoveAll(const Napi::CallbackInfo& info);
 
    struct RemoveBypathBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const char * path;
     };
    class RemoveBypathWorker : public nodegit::AsyncWorker {
      public:
        RemoveBypathWorker(
            RemoveBypathBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:RemoveBypath", cleanupHandles)
          , baton(_baton) {};
        RemoveBypathWorker(const RemoveBypathWorker &) = delete;
        RemoveBypathWorker(RemoveBypathWorker &&) = delete;
        RemoveBypathWorker &operator=(const RemoveBypathWorker &) = delete;
        RemoveBypathWorker &operator=(RemoveBypathWorker &&) = delete;
        ~RemoveBypathWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RemoveBypathBaton *baton;
    };
    Napi::Value RemoveBypath(const Napi::CallbackInfo& info);
 
    struct RemoveDirectoryBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const char * dir;
      int stage;
     };
    class RemoveDirectoryWorker : public nodegit::AsyncWorker {
      public:
        RemoveDirectoryWorker(
            RemoveDirectoryBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:RemoveDirectory", cleanupHandles)
          , baton(_baton) {};
        RemoveDirectoryWorker(const RemoveDirectoryWorker &) = delete;
        RemoveDirectoryWorker(RemoveDirectoryWorker &&) = delete;
        RemoveDirectoryWorker &operator=(const RemoveDirectoryWorker &) = delete;
        RemoveDirectoryWorker &operator=(RemoveDirectoryWorker &&) = delete;
        ~RemoveDirectoryWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RemoveDirectoryBaton *baton;
    };
    Napi::Value RemoveDirectory(const Napi::CallbackInfo& info);
     Napi::Value SetCaps(const Napi::CallbackInfo& info);
     Napi::Value SetVersion(const Napi::CallbackInfo& info);
 
    struct UpdateAllBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const git_strarray * pathspec;
      git_index_matched_path_cb callback;
      void * payload;
     };
    class UpdateAllWorker : public nodegit::AsyncWorker {
      public:
        UpdateAllWorker(
            UpdateAllBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:UpdateAll", cleanupHandles)
          , baton(_baton) {};
        UpdateAllWorker(const UpdateAllWorker &) = delete;
        UpdateAllWorker(UpdateAllWorker &&) = delete;
        UpdateAllWorker &operator=(const UpdateAllWorker &) = delete;
        UpdateAllWorker &operator=(UpdateAllWorker &&) = delete;
        ~UpdateAllWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        UpdateAllBaton *baton;
    };
    Napi::Value UpdateAll(const Napi::CallbackInfo& info);
     Napi::Value Version(const Napi::CallbackInfo& info);
 
    struct WriteBaton {
      int error_code;
      const git_error* error;
      git_index * index;
     };
    class WriteWorker : public nodegit::AsyncWorker {
      public:
        WriteWorker(
            WriteBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:Write", cleanupHandles)
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
 
    struct WriteTreeBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_index * index;
     };
    class WriteTreeWorker : public nodegit::AsyncWorker {
      public:
        WriteTreeWorker(
            WriteTreeBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:WriteTree", cleanupHandles)
          , baton(_baton) {};
        WriteTreeWorker(const WriteTreeWorker &) = delete;
        WriteTreeWorker(WriteTreeWorker &&) = delete;
        WriteTreeWorker &operator=(const WriteTreeWorker &) = delete;
        WriteTreeWorker &operator=(WriteTreeWorker &&) = delete;
        ~WriteTreeWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        WriteTreeBaton *baton;
    };
    Napi::Value WriteTree(const Napi::CallbackInfo& info);
 
    struct WriteTreeToBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_index * index;
      git_repository * repo;
     };
    class WriteTreeToWorker : public nodegit::AsyncWorker {
      public:
        WriteTreeToWorker(
            WriteTreeToBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIndex:WriteTreeTo", cleanupHandles)
          , baton(_baton) {};
        WriteTreeToWorker(const WriteTreeToWorker &) = delete;
        WriteTreeToWorker(WriteTreeToWorker &&) = delete;
        WriteTreeToWorker &operator=(const WriteTreeToWorker &) = delete;
        WriteTreeToWorker &operator=(WriteTreeToWorker &&) = delete;
        ~WriteTreeToWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        WriteTreeToBaton *baton;
    };
    Napi::Value WriteTreeTo(const Napi::CallbackInfo& info);
 
    struct AddAll_globalPayload {
      Napi::FunctionReference * callback;

      AddAll_globalPayload() {
        callback = NULL;
      }

      AddAll_globalPayload(const AddAll_globalPayload &) = delete;
      AddAll_globalPayload(AddAll_globalPayload &&) = delete;
      AddAll_globalPayload &operator=(const AddAll_globalPayload &) = delete;
      AddAll_globalPayload &operator=(AddAll_globalPayload &&) = delete;

      ~AddAll_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };

    struct RemoveAll_globalPayload {
      Napi::FunctionReference * callback;

      RemoveAll_globalPayload() {
        callback = NULL;
      }

      RemoveAll_globalPayload(const RemoveAll_globalPayload &) = delete;
      RemoveAll_globalPayload(RemoveAll_globalPayload &&) = delete;
      RemoveAll_globalPayload &operator=(const RemoveAll_globalPayload &) = delete;
      RemoveAll_globalPayload &operator=(RemoveAll_globalPayload &&) = delete;

      ~RemoveAll_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };

    struct UpdateAll_globalPayload {
      Napi::FunctionReference * callback;

      UpdateAll_globalPayload() {
        callback = NULL;
      }

      UpdateAll_globalPayload(const UpdateAll_globalPayload &) = delete;
      UpdateAll_globalPayload(UpdateAll_globalPayload &&) = delete;
      UpdateAll_globalPayload &operator=(const UpdateAll_globalPayload &) = delete;
      UpdateAll_globalPayload &operator=(UpdateAll_globalPayload &&) = delete;

      ~UpdateAll_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };
};

#endif
