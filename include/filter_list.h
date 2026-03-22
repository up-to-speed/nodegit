// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITFILTERLIST_H
#define GITFILTERLIST_H
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

#include "../include/git_buf_converter.h"
#include "../include/filter_registry.h"
#include "../include/buf.h"
#include "../include/blob.h"
#include "../include/repository.h"
// Forward declaration.
struct git_filter_list {
};
class GitFilterList;
 
struct GitFilterListTraits {
  typedef GitFilterList cppClass;
  typedef git_filter_list cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_filter_list **dest, git_filter_list *src) {
     throw std::runtime_error("duplicate called on GitFilterList which cannot be duplicated");
   }

  static std::string className() { return "GitFilterList"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_filter_list *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_filter_list_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitFilterList : public
  NodeGitWrapper<GitFilterListTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitFilterListTraits>;
   public:
    GitFilterList(const GitFilterList &) = delete;
    GitFilterList(GitFilterList &&) = delete;
    GitFilterList &operator=(const GitFilterList &) = delete;
    GitFilterList &operator=(GitFilterList &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                             GitFilterList(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitFilterListTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitFilterList cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitFilterList();

  private:


    struct ApplyToBlobBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_filter_list * filters;
      git_blob * blob;
     };
    class ApplyToBlobWorker : public nodegit::AsyncWorker {
      public:
        ApplyToBlobWorker(
            ApplyToBlobBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitFilterList:ApplyToBlob", cleanupHandles)
          , baton(_baton) {};
        ApplyToBlobWorker(const ApplyToBlobWorker &) = delete;
        ApplyToBlobWorker(ApplyToBlobWorker &&) = delete;
        ApplyToBlobWorker &operator=(const ApplyToBlobWorker &) = delete;
        ApplyToBlobWorker &operator=(ApplyToBlobWorker &&) = delete;
        ~ApplyToBlobWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ApplyToBlobBaton *baton;
    };
    Napi::Value ApplyToBlob(const Napi::CallbackInfo& info);
 
    struct ApplyToDataBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_filter_list * filters;
      git_buf * in;
     };
    class ApplyToDataWorker : public nodegit::AsyncWorker {
      public:
        ApplyToDataWorker(
            ApplyToDataBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitFilterList:ApplyToData", cleanupHandles)
          , baton(_baton) {};
        ApplyToDataWorker(const ApplyToDataWorker &) = delete;
        ApplyToDataWorker(ApplyToDataWorker &&) = delete;
        ApplyToDataWorker &operator=(const ApplyToDataWorker &) = delete;
        ApplyToDataWorker &operator=(ApplyToDataWorker &&) = delete;
        ~ApplyToDataWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ApplyToDataBaton *baton;
    };
    Napi::Value ApplyToData(const Napi::CallbackInfo& info);
 
    struct ApplyToFileBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_filter_list * filters;
      git_repository * repo;
      const char * path;
     };
    class ApplyToFileWorker : public nodegit::AsyncWorker {
      public:
        ApplyToFileWorker(
            ApplyToFileBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitFilterList:ApplyToFile", cleanupHandles)
          , baton(_baton) {};
        ApplyToFileWorker(const ApplyToFileWorker &) = delete;
        ApplyToFileWorker(ApplyToFileWorker &&) = delete;
        ApplyToFileWorker &operator=(const ApplyToFileWorker &) = delete;
        ApplyToFileWorker &operator=(ApplyToFileWorker &&) = delete;
        ~ApplyToFileWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ApplyToFileBaton *baton;
    };
    Napi::Value ApplyToFile(const Napi::CallbackInfo& info);
 
    struct LoadBaton {
      int error_code;
      const git_error* error;
      git_filter_list * filters;
      git_repository * repo;
      git_blob * blob;
      const char * path;
      git_filter_mode_t mode;
      uint32_t flags;
     };
    class LoadWorker : public nodegit::AsyncWorker {
      public:
        LoadWorker(
            LoadBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitFilterList:Load", cleanupHandles)
          , baton(_baton) {};
        LoadWorker(const LoadWorker &) = delete;
        LoadWorker(LoadWorker &&) = delete;
        LoadWorker &operator=(const LoadWorker &) = delete;
        LoadWorker &operator=(LoadWorker &&) = delete;
        ~LoadWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        LoadBaton *baton;
    };
     static Napi::Value Load(const Napi::CallbackInfo& info);
 };

#endif
