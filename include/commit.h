// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCOMMIT_H
#define GITCOMMIT_H
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
#include "../include/tree.h"
#include "../include/mailmap.h"
#include "../include/repository.h"
#include "../include/buf.h"
#include "../include/commit_create_options.h"
// Forward declaration.
struct git_commit {
};
class GitCommit;
 
struct GitCommitTraits {
  typedef GitCommit cppClass;
  typedef git_commit cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_commit **dest, git_commit *src) {
     throw std::runtime_error("duplicate called on GitCommit which cannot be duplicated");
   }

  static std::string className() { return "GitCommit"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_commit *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_commit_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitCommit : public
  NodeGitWrapper<GitCommitTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCommitTraits>;
   public:
    GitCommit(const GitCommit &) = delete;
    GitCommit(GitCommit &&) = delete;
    GitCommit &operator=(const GitCommit &) = delete;
    GitCommit &operator=(GitCommit &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                                                                                                               GitCommit(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCommitTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCommit cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCommit();

  private:


    struct AmendBaton {
      int error_code;
      const git_error* error;
      git_oid * id;
      const git_commit * commit_to_amend;
      const char * update_ref;
      const git_signature * author;
      const git_signature * committer;
      const char * message_encoding;
      const char * message;
      const git_tree * tree;
     };
    class AmendWorker : public nodegit::AsyncWorker {
      public:
        AmendWorker(
            AmendBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:Amend", cleanupHandles)
          , baton(_baton) {};
        AmendWorker(const AmendWorker &) = delete;
        AmendWorker(AmendWorker &&) = delete;
        AmendWorker &operator=(const AmendWorker &) = delete;
        AmendWorker &operator=(AmendWorker &&) = delete;
        ~AmendWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AmendBaton *baton;
    };
    Napi::Value Amend(const Napi::CallbackInfo& info);
     Napi::Value Author(const Napi::CallbackInfo& info);
 
    struct AuthorWithMailmapBaton {
      int error_code;
      const git_error* error;
      git_signature * out;
      const git_commit * commit;
      const git_mailmap * mailmap;
     };
    class AuthorWithMailmapWorker : public nodegit::AsyncWorker {
      public:
        AuthorWithMailmapWorker(
            AuthorWithMailmapBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:AuthorWithMailmap", cleanupHandles)
          , baton(_baton) {};
        AuthorWithMailmapWorker(const AuthorWithMailmapWorker &) = delete;
        AuthorWithMailmapWorker(AuthorWithMailmapWorker &&) = delete;
        AuthorWithMailmapWorker &operator=(const AuthorWithMailmapWorker &) = delete;
        AuthorWithMailmapWorker &operator=(AuthorWithMailmapWorker &&) = delete;
        ~AuthorWithMailmapWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        AuthorWithMailmapBaton *baton;
    };
    Napi::Value AuthorWithMailmap(const Napi::CallbackInfo& info);
     Napi::Value Body(const Napi::CallbackInfo& info);
     Napi::Value Committer(const Napi::CallbackInfo& info);
 
    struct CommitterWithMailmapBaton {
      int error_code;
      const git_error* error;
      git_signature * out;
      const git_commit * commit;
      const git_mailmap * mailmap;
     };
    class CommitterWithMailmapWorker : public nodegit::AsyncWorker {
      public:
        CommitterWithMailmapWorker(
            CommitterWithMailmapBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:CommitterWithMailmap", cleanupHandles)
          , baton(_baton) {};
        CommitterWithMailmapWorker(const CommitterWithMailmapWorker &) = delete;
        CommitterWithMailmapWorker(CommitterWithMailmapWorker &&) = delete;
        CommitterWithMailmapWorker &operator=(const CommitterWithMailmapWorker &) = delete;
        CommitterWithMailmapWorker &operator=(CommitterWithMailmapWorker &&) = delete;
        ~CommitterWithMailmapWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CommitterWithMailmapBaton *baton;
    };
    Napi::Value CommitterWithMailmap(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_oid * id;
      git_repository * repo;
      const char * update_ref;
      const git_signature * author;
      const git_signature * committer;
      const char * message_encoding;
      const char * message;
      const git_tree * tree;
      size_t parent_count;
      const git_commit ** parents;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:Create", cleanupHandles)
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
 
    struct CreateBufferBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_repository * repo;
      const git_signature * author;
      const git_signature * committer;
      const char * message_encoding;
      const char * message;
      const git_tree * tree;
      size_t parent_count;
      const git_commit ** parents;
     };
    class CreateBufferWorker : public nodegit::AsyncWorker {
      public:
        CreateBufferWorker(
            CreateBufferBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:CreateBuffer", cleanupHandles)
          , baton(_baton) {};
        CreateBufferWorker(const CreateBufferWorker &) = delete;
        CreateBufferWorker(CreateBufferWorker &&) = delete;
        CreateBufferWorker &operator=(const CreateBufferWorker &) = delete;
        CreateBufferWorker &operator=(CreateBufferWorker &&) = delete;
        ~CreateBufferWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateBufferBaton *baton;
    };
     static Napi::Value CreateBuffer(const Napi::CallbackInfo& info);
      static Napi::Value CreateFromStage(const Napi::CallbackInfo& info);
      static Napi::Value CreateV(const Napi::CallbackInfo& info);
 
    struct CreateWithSignatureBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const char * commit_content;
      const char * signature;
      const char * signature_field;
     };
    class CreateWithSignatureWorker : public nodegit::AsyncWorker {
      public:
        CreateWithSignatureWorker(
            CreateWithSignatureBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:CreateWithSignature", cleanupHandles)
          , baton(_baton) {};
        CreateWithSignatureWorker(const CreateWithSignatureWorker &) = delete;
        CreateWithSignatureWorker(CreateWithSignatureWorker &&) = delete;
        CreateWithSignatureWorker &operator=(const CreateWithSignatureWorker &) = delete;
        CreateWithSignatureWorker &operator=(CreateWithSignatureWorker &&) = delete;
        ~CreateWithSignatureWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateWithSignatureBaton *baton;
    };
     static Napi::Value CreateWithSignature(const Napi::CallbackInfo& info);
 
    struct DupBaton {
      int error_code;
      const git_error* error;
      git_commit * out;
      git_commit * source;
     };
    class DupWorker : public nodegit::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:Dup", cleanupHandles)
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
 
    struct ExtractSignatureBaton {
      int error_code;
      const git_error* error;
      git_buf signature;
      git_buf signed_data;
      git_repository * repo;
      git_oid * commit_id;
      bool commit_idNeedsFree;
      char * field;
     };
    class ExtractSignatureWorker : public nodegit::AsyncWorker {
      public:
        ExtractSignatureWorker(
            ExtractSignatureBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:ExtractSignature", cleanupHandles)
          , baton(_baton) {};
        ExtractSignatureWorker(const ExtractSignatureWorker &) = delete;
        ExtractSignatureWorker(ExtractSignatureWorker &&) = delete;
        ExtractSignatureWorker &operator=(const ExtractSignatureWorker &) = delete;
        ExtractSignatureWorker &operator=(ExtractSignatureWorker &&) = delete;
        ~ExtractSignatureWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ExtractSignatureBaton *baton;
    };
     static Napi::Value ExtractSignature(const Napi::CallbackInfo& info);
 
    struct HeaderFieldBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_commit * commit;
      const char * field;
     };
    class HeaderFieldWorker : public nodegit::AsyncWorker {
      public:
        HeaderFieldWorker(
            HeaderFieldBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:HeaderField", cleanupHandles)
          , baton(_baton) {};
        HeaderFieldWorker(const HeaderFieldWorker &) = delete;
        HeaderFieldWorker(HeaderFieldWorker &&) = delete;
        HeaderFieldWorker &operator=(const HeaderFieldWorker &) = delete;
        HeaderFieldWorker &operator=(HeaderFieldWorker &&) = delete;
        ~HeaderFieldWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        HeaderFieldBaton *baton;
    };
    Napi::Value HeaderField(const Napi::CallbackInfo& info);
     Napi::Value Id(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_commit * commit;
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
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:Lookup", cleanupHandles)
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
      git_commit * commit;
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
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:LookupPrefix", cleanupHandles)
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
     Napi::Value MessageEncoding(const Napi::CallbackInfo& info);
     Napi::Value MessageRaw(const Napi::CallbackInfo& info);
 
    struct NthGenAncestorBaton {
      int error_code;
      const git_error* error;
      git_commit * ancestor;
      const git_commit * commit;
      unsigned int n;
     };
    class NthGenAncestorWorker : public nodegit::AsyncWorker {
      public:
        NthGenAncestorWorker(
            NthGenAncestorBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:NthGenAncestor", cleanupHandles)
          , baton(_baton) {};
        NthGenAncestorWorker(const NthGenAncestorWorker &) = delete;
        NthGenAncestorWorker(NthGenAncestorWorker &&) = delete;
        NthGenAncestorWorker &operator=(const NthGenAncestorWorker &) = delete;
        NthGenAncestorWorker &operator=(NthGenAncestorWorker &&) = delete;
        ~NthGenAncestorWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        NthGenAncestorBaton *baton;
    };
    Napi::Value NthGenAncestor(const Napi::CallbackInfo& info);
     Napi::Value Owner(const Napi::CallbackInfo& info);
 
    struct ParentBaton {
      int error_code;
      const git_error* error;
      git_commit * out;
      const git_commit * commit;
      unsigned int n;
     };
    class ParentWorker : public nodegit::AsyncWorker {
      public:
        ParentWorker(
            ParentBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCommit:Parent", cleanupHandles)
          , baton(_baton) {};
        ParentWorker(const ParentWorker &) = delete;
        ParentWorker(ParentWorker &&) = delete;
        ParentWorker &operator=(const ParentWorker &) = delete;
        ParentWorker &operator=(ParentWorker &&) = delete;
        ~ParentWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ParentBaton *baton;
    };
    Napi::Value Parent(const Napi::CallbackInfo& info);
     Napi::Value ParentId(const Napi::CallbackInfo& info);
     Napi::Value Parentcount(const Napi::CallbackInfo& info);
     Napi::Value RawHeader(const Napi::CallbackInfo& info);
     Napi::Value Summary(const Napi::CallbackInfo& info);
     Napi::Value Time(const Napi::CallbackInfo& info);
     Napi::Value TimeOffset(const Napi::CallbackInfo& info);
     Napi::Value Tree(const Napi::CallbackInfo& info);
     Napi::Value TreeId(const Napi::CallbackInfo& info);
 };

#endif
