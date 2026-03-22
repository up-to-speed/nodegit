// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITOBJECT_H
#define GITOBJECT_H
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
#include "../include/repository.h"
#include "../include/buf.h"
// Forward declaration.
struct git_object {
};
class GitObject;
 
struct GitObjectTraits {
  typedef GitObject cppClass;
  typedef git_object cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_object **dest, git_object *src) {
     throw std::runtime_error("duplicate called on GitObject which cannot be duplicated");
   }

  static std::string className() { return "GitObject"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_object *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_object_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitObject : public
  NodeGitWrapper<GitObjectTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitObjectTraits>;
   public:
    GitObject(const GitObject &) = delete;
    GitObject(GitObject &&) = delete;
    GitObject &operator=(const GitObject &) = delete;
    GitObject &operator=(GitObject &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                GitObject(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitObjectTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitObject cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitObject();

  private:

     static Napi::Value Size(const Napi::CallbackInfo& info);
 
    struct DupBaton {
      int error_code;
      const git_error* error;
      git_object * dest;
      git_object * source;
     };
    class DupWorker : public nodegit::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitObject:Dup", cleanupHandles)
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
     Napi::Value Id(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_object * object;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
      git_object_t type;
     };
    class LookupWorker : public nodegit::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitObject:Lookup", cleanupHandles)
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
 
    struct LookupBypathBaton {
      int error_code;
      const git_error* error;
      git_object * out;
      const git_object * treeish;
      const char * path;
      git_object_t type;
     };
    class LookupBypathWorker : public nodegit::AsyncWorker {
      public:
        LookupBypathWorker(
            LookupBypathBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitObject:LookupBypath", cleanupHandles)
          , baton(_baton) {};
        LookupBypathWorker(const LookupBypathWorker &) = delete;
        LookupBypathWorker(LookupBypathWorker &&) = delete;
        LookupBypathWorker &operator=(const LookupBypathWorker &) = delete;
        LookupBypathWorker &operator=(LookupBypathWorker &&) = delete;
        ~LookupBypathWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        LookupBypathBaton *baton;
    };
    Napi::Value LookupBypath(const Napi::CallbackInfo& info);
 
    struct LookupPrefixBaton {
      int error_code;
      const git_error* error;
      git_object * object_out;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
      size_t len;
      git_object_t type;
     };
    class LookupPrefixWorker : public nodegit::AsyncWorker {
      public:
        LookupPrefixWorker(
            LookupPrefixBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitObject:LookupPrefix", cleanupHandles)
          , baton(_baton) {};
        LookupPrefixWorker(const LookupPrefixWorker &) = delete;
        LookupPrefixWorker(LookupPrefixWorker &&) = delete;
        LookupPrefixWorker &operator=(const LookupPrefixWorker &) = delete;
        LookupPrefixWorker &operator=(LookupPrefixWorker &&) = delete;
        ~LookupPrefixWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        LookupPrefixBaton *baton;
    };
     static Napi::Value LookupPrefix(const Napi::CallbackInfo& info);
     Napi::Value Owner(const Napi::CallbackInfo& info);
 
    struct PeelBaton {
      int error_code;
      const git_error* error;
      git_object * peeled;
      const git_object * object;
      git_object_t target_type;
     };
    class PeelWorker : public nodegit::AsyncWorker {
      public:
        PeelWorker(
            PeelBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitObject:Peel", cleanupHandles)
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
      static Napi::Value RawcontentIsValid(const Napi::CallbackInfo& info);
 
    struct ShortIdBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_object * obj;
     };
    class ShortIdWorker : public nodegit::AsyncWorker {
      public:
        ShortIdWorker(
            ShortIdBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitObject:ShortId", cleanupHandles)
          , baton(_baton) {};
        ShortIdWorker(const ShortIdWorker &) = delete;
        ShortIdWorker(ShortIdWorker &&) = delete;
        ShortIdWorker &operator=(const ShortIdWorker &) = delete;
        ShortIdWorker &operator=(ShortIdWorker &&) = delete;
        ~ShortIdWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ShortIdBaton *baton;
    };
    Napi::Value ShortId(const Napi::CallbackInfo& info);
      static Napi::Value String2type(const Napi::CallbackInfo& info);
     Napi::Value Type(const Napi::CallbackInfo& info);
      static Napi::Value Type2string(const Napi::CallbackInfo& info);
      static Napi::Value Typeisloose(const Napi::CallbackInfo& info);
 };

#endif
