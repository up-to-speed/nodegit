// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITBLOB_H
#define GITBLOB_H
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

#include "../include/wrapper.h"
#include "node_buffer.h"
#include "../include/oid.h"
#include "../include/repository.h"
#include "../include/buf.h"
#include "../include/blob_filter_options.h"
// Forward declaration.
struct git_blob {
};
class GitBlob;
 
struct GitBlobTraits {
  typedef GitBlob cppClass;
  typedef git_blob cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_blob **dest, git_blob *src) {
     throw std::runtime_error("duplicate called on GitBlob which cannot be duplicated");
   }

  static std::string className() { return "GitBlob"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_blob *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_blob_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitBlob : public
  NodeGitWrapper<GitBlobTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitBlobTraits>;
   public:
    GitBlob(const GitBlob &) = delete;
    GitBlob(GitBlob &&) = delete;
    GitBlob &operator=(const GitBlob &) = delete;
    GitBlob &operator=(GitBlob &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                   GitBlob(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitBlobTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitBlob cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitBlob();

  private:


    struct CreateFromBufferBaton {
      int error_code;
      const git_error* error;
      git_oid * id;
      git_repository * repo;
      const void * buffer;
      size_t len;
     };
    class CreateFromBufferWorker : public nodegit::AsyncWorker {
      public:
        CreateFromBufferWorker(
            CreateFromBufferBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlob:CreateFromBuffer", cleanupHandles)
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
 
    struct CreateFromDiskBaton {
      int error_code;
      const git_error* error;
      git_oid * id;
      git_repository * repo;
      const char * path;
     };
    class CreateFromDiskWorker : public nodegit::AsyncWorker {
      public:
        CreateFromDiskWorker(
            CreateFromDiskBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlob:CreateFromDisk", cleanupHandles)
          , baton(_baton) {};
        CreateFromDiskWorker(const CreateFromDiskWorker &) = delete;
        CreateFromDiskWorker(CreateFromDiskWorker &&) = delete;
        CreateFromDiskWorker &operator=(const CreateFromDiskWorker &) = delete;
        CreateFromDiskWorker &operator=(CreateFromDiskWorker &&) = delete;
        ~CreateFromDiskWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateFromDiskBaton *baton;
    };
     static Napi::Value CreateFromDisk(const Napi::CallbackInfo& info);
 
    struct CreateFromWorkdirBaton {
      int error_code;
      const git_error* error;
      git_oid * id;
      git_repository * repo;
      const char * relative_path;
     };
    class CreateFromWorkdirWorker : public nodegit::AsyncWorker {
      public:
        CreateFromWorkdirWorker(
            CreateFromWorkdirBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlob:CreateFromWorkdir", cleanupHandles)
          , baton(_baton) {};
        CreateFromWorkdirWorker(const CreateFromWorkdirWorker &) = delete;
        CreateFromWorkdirWorker(CreateFromWorkdirWorker &&) = delete;
        CreateFromWorkdirWorker &operator=(const CreateFromWorkdirWorker &) = delete;
        CreateFromWorkdirWorker &operator=(CreateFromWorkdirWorker &&) = delete;
        ~CreateFromWorkdirWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CreateFromWorkdirBaton *baton;
    };
     static Napi::Value CreateFromWorkdir(const Napi::CallbackInfo& info);
      static Napi::Value DataIsBinary(const Napi::CallbackInfo& info);
 
    struct DupBaton {
      int error_code;
      const git_error* error;
      git_blob * out;
      git_blob * source;
     };
    class DupWorker : public nodegit::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlob:Dup", cleanupHandles)
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
 
    struct FilterBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_blob * blob;
      const char * as_path;
      git_blob_filter_options * opts;
     };
    class FilterWorker : public nodegit::AsyncWorker {
      public:
        FilterWorker(
            FilterBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlob:Filter", cleanupHandles)
          , baton(_baton) {};
        FilterWorker(const FilterWorker &) = delete;
        FilterWorker(FilterWorker &&) = delete;
        FilterWorker &operator=(const FilterWorker &) = delete;
        FilterWorker &operator=(FilterWorker &&) = delete;
        ~FilterWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FilterBaton *baton;
    };
    Napi::Value Filter(const Napi::CallbackInfo& info);
 
    struct FilteredContentBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_blob * blob;
      const char * as_path;
      int check_for_binary_data;
     };
    class FilteredContentWorker : public nodegit::AsyncWorker {
      public:
        FilteredContentWorker(
            FilteredContentBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlob:FilteredContent", cleanupHandles)
          , baton(_baton) {};
        FilteredContentWorker(const FilteredContentWorker &) = delete;
        FilteredContentWorker(FilteredContentWorker &&) = delete;
        FilteredContentWorker &operator=(const FilteredContentWorker &) = delete;
        FilteredContentWorker &operator=(FilteredContentWorker &&) = delete;
        ~FilteredContentWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FilteredContentBaton *baton;
    };
     static Napi::Value FilteredContent(const Napi::CallbackInfo& info);
     Napi::Value Id(const Napi::CallbackInfo& info);
     Napi::Value IsBinary(const Napi::CallbackInfo& info);
 
    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_blob * blob;
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
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlob:Lookup", cleanupHandles)
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
      git_blob * blob;
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
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitBlob:LookupPrefix", cleanupHandles)
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
     Napi::Value Rawcontent(const Napi::CallbackInfo& info);
     Napi::Value Rawsize(const Napi::CallbackInfo& info);
 };

#endif
