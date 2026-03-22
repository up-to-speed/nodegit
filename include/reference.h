// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREFS_H
#define GITREFS_H
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

#include "../include/repository.h"
#include "../include/oid.h"
#include "../include/strarray.h"
#include "../include/object.h"
// Forward declaration.
struct git_reference {
};
class GitRefs;
 
struct GitRefsTraits {
  typedef GitRefs cppClass;
  typedef git_reference cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_reference **dest, git_reference *src) {
     throw std::runtime_error("duplicate called on GitRefs which cannot be duplicated");
   }

  static std::string className() { return "GitRefs"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_reference *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_reference_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRefs : public
  NodeGitWrapper<GitRefsTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRefsTraits>;
   public:
    GitRefs(const GitRefs &) = delete;
    GitRefs(GitRefs &&) = delete;
    GitRefs &operator=(const GitRefs &) = delete;
    GitRefs &operator=(GitRefs &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                                                                                                           GitRefs(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRefsTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRefs cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRefs();

  private:

    Napi::Value Cmp(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
      const git_oid * id;
      bool idNeedsFree;
      int force;
      const char * log_message;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:Create", cleanupHandles)
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
 
    struct CreateMatchingBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
      const git_oid * id;
      bool idNeedsFree;
      int force;
      const git_oid * current_id;
      bool current_idNeedsFree;
      const char * log_message;
     };
    class CreateMatchingWorker : public nodegit::AsyncWorker {
      public:
        CreateMatchingWorker(
            CreateMatchingBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:CreateMatching", cleanupHandles)
          , baton(_baton) {};
        CreateMatchingWorker(const CreateMatchingWorker &) = delete;
        CreateMatchingWorker(CreateMatchingWorker &&) = delete;
        CreateMatchingWorker &operator=(const CreateMatchingWorker &) = delete;
        CreateMatchingWorker &operator=(CreateMatchingWorker &&) = delete;
        ~CreateMatchingWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateMatchingBaton *baton;
    };
     static Napi::Value CreateMatching(const Napi::CallbackInfo& info);
     Napi::Value Delete(const Napi::CallbackInfo& info);
 
    struct DupBaton {
      int error_code;
      const git_error* error;
      git_reference * dest;
      git_reference * source;
     };
    class DupWorker : public nodegit::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:Dup", cleanupHandles)
          , baton(_baton) {};
        DupWorker(const DupWorker &) = delete;
        DupWorker(DupWorker &&) = delete;
        DupWorker &operator=(const DupWorker &) = delete;
        DupWorker &operator=(DupWorker &&) = delete;
        ~DupWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DupBaton *baton;
    };
    Napi::Value Dup(const Napi::CallbackInfo& info);
 
    struct DwimBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * shorthand;
     };
    class DwimWorker : public nodegit::AsyncWorker {
      public:
        DwimWorker(
            DwimBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:Dwim", cleanupHandles)
          , baton(_baton) {};
        DwimWorker(const DwimWorker &) = delete;
        DwimWorker(DwimWorker &&) = delete;
        DwimWorker &operator=(const DwimWorker &) = delete;
        DwimWorker &operator=(DwimWorker &&) = delete;
        ~DwimWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DwimBaton *baton;
    };
     static Napi::Value Dwim(const Napi::CallbackInfo& info);
      static Napi::Value EnsureLog(const Napi::CallbackInfo& info);
      static Napi::Value HasLog(const Napi::CallbackInfo& info);
     Napi::Value IsBranch(const Napi::CallbackInfo& info);
     Napi::Value IsNote(const Napi::CallbackInfo& info);
     Napi::Value IsRemote(const Napi::CallbackInfo& info);
     Napi::Value IsTag(const Napi::CallbackInfo& info);
      static Napi::Value IsValidName(const Napi::CallbackInfo& info);
 
    struct ListBaton {
      int error_code;
      const git_error* error;
      git_strarray * array;
      git_repository * repo;
     };
    class ListWorker : public nodegit::AsyncWorker {
      public:
        ListWorker(
            ListBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:List", cleanupHandles)
          , baton(_baton) {};
        ListWorker(const ListWorker &) = delete;
        ListWorker(ListWorker &&) = delete;
        ListWorker &operator=(const ListWorker &) = delete;
        ListWorker &operator=(ListWorker &&) = delete;
        ~ListWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ListBaton *baton;
    };
     static Napi::Value List(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
     };
    class LookupWorker : public nodegit::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:Lookup", cleanupHandles)
          , baton(_baton) {};
        LookupWorker(const LookupWorker &) = delete;
        LookupWorker(LookupWorker &&) = delete;
        LookupWorker &operator=(const LookupWorker &) = delete;
        LookupWorker &operator=(LookupWorker &&) = delete;
        ~LookupWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        LookupBaton *baton;
    };
     static Napi::Value Lookup(const Napi::CallbackInfo& info);
     Napi::Value Name(const Napi::CallbackInfo& info);
      static Napi::Value NameIsValid(const Napi::CallbackInfo& info);
 
    struct NameToIdBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const char * name;
     };
    class NameToIdWorker : public nodegit::AsyncWorker {
      public:
        NameToIdWorker(
            NameToIdBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:NameToId", cleanupHandles)
          , baton(_baton) {};
        NameToIdWorker(const NameToIdWorker &) = delete;
        NameToIdWorker(NameToIdWorker &&) = delete;
        NameToIdWorker &operator=(const NameToIdWorker &) = delete;
        NameToIdWorker &operator=(NameToIdWorker &&) = delete;
        ~NameToIdWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        NameToIdBaton *baton;
    };
     static Napi::Value NameToId(const Napi::CallbackInfo& info);
      static Napi::Value NormalizeName(const Napi::CallbackInfo& info);
     Napi::Value Owner(const Napi::CallbackInfo& info);
 
    struct PeelBaton {
      int error_code;
      const git_error* error;
      git_object * out;
      const git_reference * ref;
      git_object_t type;
     };
    class PeelWorker : public nodegit::AsyncWorker {
      public:
        PeelWorker(
            PeelBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:Peel", cleanupHandles)
          , baton(_baton) {};
        PeelWorker(const PeelWorker &) = delete;
        PeelWorker(PeelWorker &&) = delete;
        PeelWorker &operator=(const PeelWorker &) = delete;
        PeelWorker &operator=(PeelWorker &&) = delete;
        ~PeelWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        PeelBaton *baton;
    };
    Napi::Value Peel(const Napi::CallbackInfo& info);
      static Napi::Value Remove(const Napi::CallbackInfo& info);
 
    struct RenameBaton {
      int error_code;
      const git_error* error;
      git_reference * new_ref;
      git_reference * ref;
      const char * new_name;
      int force;
      const char * log_message;
     };
    class RenameWorker : public nodegit::AsyncWorker {
      public:
        RenameWorker(
            RenameBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:Rename", cleanupHandles)
          , baton(_baton) {};
        RenameWorker(const RenameWorker &) = delete;
        RenameWorker(RenameWorker &&) = delete;
        RenameWorker &operator=(const RenameWorker &) = delete;
        RenameWorker &operator=(RenameWorker &&) = delete;
        ~RenameWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RenameBaton *baton;
    };
    Napi::Value Rename(const Napi::CallbackInfo& info);
 
    struct ResolveBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      const git_reference * ref;
     };
    class ResolveWorker : public nodegit::AsyncWorker {
      public:
        ResolveWorker(
            ResolveBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:Resolve", cleanupHandles)
          , baton(_baton) {};
        ResolveWorker(const ResolveWorker &) = delete;
        ResolveWorker(ResolveWorker &&) = delete;
        ResolveWorker &operator=(const ResolveWorker &) = delete;
        ResolveWorker &operator=(ResolveWorker &&) = delete;
        ~ResolveWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ResolveBaton *baton;
    };
    Napi::Value Resolve(const Napi::CallbackInfo& info);
 
    struct SetTargetBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_reference * ref;
      const git_oid * id;
      bool idNeedsFree;
      const char * log_message;
     };
    class SetTargetWorker : public nodegit::AsyncWorker {
      public:
        SetTargetWorker(
            SetTargetBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:SetTarget", cleanupHandles)
          , baton(_baton) {};
        SetTargetWorker(const SetTargetWorker &) = delete;
        SetTargetWorker(SetTargetWorker &&) = delete;
        SetTargetWorker &operator=(const SetTargetWorker &) = delete;
        SetTargetWorker &operator=(SetTargetWorker &&) = delete;
        ~SetTargetWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetTargetBaton *baton;
    };
    Napi::Value SetTarget(const Napi::CallbackInfo& info);
     Napi::Value Shorthand(const Napi::CallbackInfo& info);
 
    struct SymbolicCreateBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
      const char * target;
      int force;
      const char * log_message;
     };
    class SymbolicCreateWorker : public nodegit::AsyncWorker {
      public:
        SymbolicCreateWorker(
            SymbolicCreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:SymbolicCreate", cleanupHandles)
          , baton(_baton) {};
        SymbolicCreateWorker(const SymbolicCreateWorker &) = delete;
        SymbolicCreateWorker(SymbolicCreateWorker &&) = delete;
        SymbolicCreateWorker &operator=(const SymbolicCreateWorker &) = delete;
        SymbolicCreateWorker &operator=(SymbolicCreateWorker &&) = delete;
        ~SymbolicCreateWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SymbolicCreateBaton *baton;
    };
     static Napi::Value SymbolicCreate(const Napi::CallbackInfo& info);
 
    struct SymbolicCreateMatchingBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
      const char * target;
      int force;
      const char * current_value;
      const char * log_message;
     };
    class SymbolicCreateMatchingWorker : public nodegit::AsyncWorker {
      public:
        SymbolicCreateMatchingWorker(
            SymbolicCreateMatchingBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:SymbolicCreateMatching", cleanupHandles)
          , baton(_baton) {};
        SymbolicCreateMatchingWorker(const SymbolicCreateMatchingWorker &) = delete;
        SymbolicCreateMatchingWorker(SymbolicCreateMatchingWorker &&) = delete;
        SymbolicCreateMatchingWorker &operator=(const SymbolicCreateMatchingWorker &) = delete;
        SymbolicCreateMatchingWorker &operator=(SymbolicCreateMatchingWorker &&) = delete;
        ~SymbolicCreateMatchingWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SymbolicCreateMatchingBaton *baton;
    };
     static Napi::Value SymbolicCreateMatching(const Napi::CallbackInfo& info);
 
    struct SymbolicSetTargetBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_reference * ref;
      const char * target;
      const char * log_message;
     };
    class SymbolicSetTargetWorker : public nodegit::AsyncWorker {
      public:
        SymbolicSetTargetWorker(
            SymbolicSetTargetBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefs:SymbolicSetTarget", cleanupHandles)
          , baton(_baton) {};
        SymbolicSetTargetWorker(const SymbolicSetTargetWorker &) = delete;
        SymbolicSetTargetWorker(SymbolicSetTargetWorker &&) = delete;
        SymbolicSetTargetWorker &operator=(const SymbolicSetTargetWorker &) = delete;
        SymbolicSetTargetWorker &operator=(SymbolicSetTargetWorker &&) = delete;
        ~SymbolicSetTargetWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SymbolicSetTargetBaton *baton;
    };
    Napi::Value SymbolicSetTarget(const Napi::CallbackInfo& info);
     Napi::Value SymbolicTarget(const Napi::CallbackInfo& info);
     Napi::Value Target(const Napi::CallbackInfo& info);
     Napi::Value TargetPeel(const Napi::CallbackInfo& info);
     Napi::Value Type(const Napi::CallbackInfo& info);
 };

#endif
