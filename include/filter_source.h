// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITFILTERSOURCE_H
#define GITFILTERSOURCE_H
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
#include <git2/sys/filter.h>
}

#include "../include/typedefs.h"

#include "../include/repository.h"
#include "../include/oid.h"
// Forward declaration.
struct git_filter_source {
};
class GitFilterSource;
 
struct GitFilterSourceTraits {
  typedef GitFilterSource cppClass;
  typedef git_filter_source cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_filter_source **dest, git_filter_source *src) {
     throw std::runtime_error("duplicate called on GitFilterSource which cannot be duplicated");
   }

  static std::string className() { return "GitFilterSource"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_filter_source *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitFilterSource : public
  NodeGitWrapper<GitFilterSourceTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitFilterSourceTraits>;
   public:
    GitFilterSource(const GitFilterSource &) = delete;
    GitFilterSource(GitFilterSource &&) = delete;
    GitFilterSource &operator=(const GitFilterSource &) = delete;
    GitFilterSource &operator=(GitFilterSource &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                        GitFilterSource(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitFilterSourceTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitFilterSource cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitFilterSource();

  private:


    struct RepoBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const git_filter_source * src;
     };
    class RepoWorker : public nodegit::AsyncWorker {
      public:
        RepoWorker(
            RepoBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitFilterSource:Repo", cleanupHandles)
          , baton(_baton) {};
        RepoWorker(const RepoWorker &) = delete;
        RepoWorker(RepoWorker &&) = delete;
        RepoWorker &operator=(const RepoWorker &) = delete;
        RepoWorker &operator=(RepoWorker &&) = delete;
        ~RepoWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        RepoBaton *baton;
    };
    Napi::Value Repo(const Napi::CallbackInfo& info);
     Napi::Value Path(const Napi::CallbackInfo& info);
     Napi::Value Filemode(const Napi::CallbackInfo& info);
     Napi::Value Id(const Napi::CallbackInfo& info);
     Napi::Value Mode(const Napi::CallbackInfo& info);
     Napi::Value Flags(const Napi::CallbackInfo& info);
 };

#endif
