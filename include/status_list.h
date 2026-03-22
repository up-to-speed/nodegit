// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITSTATUSLIST_H
#define GITSTATUSLIST_H
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

#include "../include/diff_perfdata.h"
#include "../include/repository.h"
#include "../include/status_options.h"
// Forward declaration.
struct git_status_list {
};
class GitStatusList;
 
struct GitStatusListTraits {
  typedef GitStatusList cppClass;
  typedef git_status_list cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_status_list **dest, git_status_list *src) {
     throw std::runtime_error("duplicate called on GitStatusList which cannot be duplicated");
   }

  static std::string className() { return "GitStatusList"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_status_list *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_status_list_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitStatusList : public
  NodeGitWrapper<GitStatusListTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitStatusListTraits>;
   public:
    GitStatusList(const GitStatusList &) = delete;
    GitStatusList(GitStatusList &&) = delete;
    GitStatusList &operator=(const GitStatusList &) = delete;
    GitStatusList &operator=(GitStatusList &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                 GitStatusList(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitStatusListTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitStatusList cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitStatusList();

  private:

    Napi::Value Entrycount(const Napi::CallbackInfo& info);
     Napi::Value GetPerfdata(const Napi::CallbackInfo& info);
 
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_status_list * out;
      git_repository * repo;
      const git_status_options * opts;
     };
    class CreateWorker : public nodegit::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitStatusList:Create", cleanupHandles)
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
 };

#endif
