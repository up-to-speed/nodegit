// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITTAG_H
#define GITTAG_H
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
#include "../include/oid.h"
#include "../include/repository.h"
#include "../include/object.h"
#include "../include/signature.h"
#include "../include/strarray.h"
// Forward declaration.
struct git_tag {
};
class GitTag;
 
struct GitTagTraits {
  typedef GitTag cppClass;
  typedef git_tag cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_tag **dest, git_tag *src) {
     throw std::runtime_error("duplicate called on GitTag which cannot be duplicated");
   }

  static std::string className() { return "GitTag"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_tag *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_tag_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitTag : public
  NodeGitWrapper<GitTagTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitTagTraits>;
   public:
    GitTag(const GitTag &) = delete;
    GitTag(GitTag &&) = delete;
    GitTag &operator=(const GitTag &) = delete;
    GitTag &operator=(GitTag &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                                                GitTag(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitTagTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitTag cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitTag();

  private:


    struct AnnotationCreateBaton {
      int error_code;
      const git_error* error;
      git_oid * oid;
      git_repository * repo;
      const char * tag_name;
      const git_object * target;
      const git_signature * tagger;
      const char * message;
     };
    class AnnotationCreateWorker : public nodegit::AsyncWorker {
      public:
        AnnotationCreateWorker(
            AnnotationCreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:AnnotationCreate", cleanupHandles)
          , baton(_baton) {};
        AnnotationCreateWorker(const AnnotationCreateWorker &) = delete;
        AnnotationCreateWorker(AnnotationCreateWorker &&) = delete;
        AnnotationCreateWorker &operator=(const AnnotationCreateWorker &) = delete;
        AnnotationCreateWorker &operator=(AnnotationCreateWorker &&) = delete;
        ~AnnotationCreateWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AnnotationCreateBaton *baton;
    };
     static Napi::Value AnnotationCreate(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_oid * oid;
      git_repository * repo;
      const char * tag_name;
      const git_object * target;
      const git_signature * tagger;
      const char * message;
      int force;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:Create", cleanupHandles)
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
 
    struct CreateFromBufferBaton {
      int error_code;
      const git_error* error;
      git_oid * oid;
      git_repository * repo;
      const char * buffer;
      int force;
     };
    class CreateFromBufferWorker : public nodegit::AsyncWorker {
      public:
        CreateFromBufferWorker(
            CreateFromBufferBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:CreateFromBuffer", cleanupHandles)
          , baton(_baton) {};
        CreateFromBufferWorker(const CreateFromBufferWorker &) = delete;
        CreateFromBufferWorker(CreateFromBufferWorker &&) = delete;
        CreateFromBufferWorker &operator=(const CreateFromBufferWorker &) = delete;
        CreateFromBufferWorker &operator=(CreateFromBufferWorker &&) = delete;
        ~CreateFromBufferWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateFromBufferBaton *baton;
    };
     static Napi::Value CreateFromBuffer(const Napi::CallbackInfo& info);
 
    struct CreateLightweightBaton {
      int error_code;
      const git_error* error;
      git_oid * oid;
      git_repository * repo;
      const char * tag_name;
      const git_object * target;
      int force;
     };
    class CreateLightweightWorker : public nodegit::AsyncWorker {
      public:
        CreateLightweightWorker(
            CreateLightweightBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:CreateLightweight", cleanupHandles)
          , baton(_baton) {};
        CreateLightweightWorker(const CreateLightweightWorker &) = delete;
        CreateLightweightWorker(CreateLightweightWorker &&) = delete;
        CreateLightweightWorker &operator=(const CreateLightweightWorker &) = delete;
        CreateLightweightWorker &operator=(CreateLightweightWorker &&) = delete;
        ~CreateLightweightWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateLightweightBaton *baton;
    };
     static Napi::Value CreateLightweight(const Napi::CallbackInfo& info);
 
    struct DeleteBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * tag_name;
     };
    class DeleteWorker : public nodegit::AsyncWorker {
      public:
        DeleteWorker(
            DeleteBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:Delete", cleanupHandles)
          , baton(_baton) {};
        DeleteWorker(const DeleteWorker &) = delete;
        DeleteWorker(DeleteWorker &&) = delete;
        DeleteWorker &operator=(const DeleteWorker &) = delete;
        DeleteWorker &operator=(DeleteWorker &&) = delete;
        ~DeleteWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        DeleteBaton *baton;
    };
     static Napi::Value Delete(const Napi::CallbackInfo& info);
 
    struct DupBaton {
      int error_code;
      const git_error* error;
      git_tag * out;
      git_tag * source;
     };
    class DupWorker : public nodegit::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:Dup", cleanupHandles)
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
 
    struct ListBaton {
      int error_code;
      const git_error* error;
      git_strarray * tag_names;
      git_repository * repo;
     };
    class ListWorker : public nodegit::AsyncWorker {
      public:
        ListWorker(
            ListBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:List", cleanupHandles)
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
 
    struct ListMatchBaton {
      int error_code;
      const git_error* error;
      git_strarray * tag_names;
      const char * pattern;
      git_repository * repo;
     };
    class ListMatchWorker : public nodegit::AsyncWorker {
      public:
        ListMatchWorker(
            ListMatchBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:ListMatch", cleanupHandles)
          , baton(_baton) {};
        ListMatchWorker(const ListMatchWorker &) = delete;
        ListMatchWorker(ListMatchWorker &&) = delete;
        ListMatchWorker &operator=(const ListMatchWorker &) = delete;
        ListMatchWorker &operator=(ListMatchWorker &&) = delete;
        ~ListMatchWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ListMatchBaton *baton;
    };
     static Napi::Value ListMatch(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_tag * out;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
     };
    class LookupWorker : public nodegit::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:Lookup", cleanupHandles)
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
 
    struct LookupPrefixBaton {
      int error_code;
      const git_error* error;
      git_tag * out;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
      size_t len;
     };
    class LookupPrefixWorker : public nodegit::AsyncWorker {
      public:
        LookupPrefixWorker(
            LookupPrefixBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:LookupPrefix", cleanupHandles)
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
     Napi::Value Message(const Napi::CallbackInfo& info);
     Napi::Value Name(const Napi::CallbackInfo& info);
      static Napi::Value NameIsValid(const Napi::CallbackInfo& info);
     Napi::Value Owner(const Napi::CallbackInfo& info);
 
    struct PeelBaton {
      int error_code;
      const git_error* error;
      git_object * tag_target_out;
      const git_tag * tag;
     };
    class PeelWorker : public nodegit::AsyncWorker {
      public:
        PeelWorker(
            PeelBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:Peel", cleanupHandles)
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
     Napi::Value Tagger(const Napi::CallbackInfo& info);
 
    struct TargetBaton {
      int error_code;
      const git_error* error;
      git_object * target_out;
      const git_tag * tag;
     };
    class TargetWorker : public nodegit::AsyncWorker {
      public:
        TargetWorker(
            TargetBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitTag:Target", cleanupHandles)
          , baton(_baton) {};
        TargetWorker(const TargetWorker &) = delete;
        TargetWorker(TargetWorker &&) = delete;
        TargetWorker &operator=(const TargetWorker &) = delete;
        TargetWorker &operator=(TargetWorker &&) = delete;
        ~TargetWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        TargetBaton *baton;
    };
    Napi::Value Target(const Napi::CallbackInfo& info);
     Napi::Value TargetId(const Napi::CallbackInfo& info);
     Napi::Value TargetType(const Napi::CallbackInfo& info);
 };

#endif
