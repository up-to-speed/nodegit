// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREFDB_H
#define GITREFDB_H
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
// Forward declaration.
struct git_refdb {
};
class GitRefdb;
 
struct GitRefdbTraits {
  typedef GitRefdb cppClass;
  typedef git_refdb cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_refdb **dest, git_refdb *src) {
     throw std::runtime_error("duplicate called on GitRefdb which cannot be duplicated");
   }

  static std::string className() { return "GitRefdb"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_refdb *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_refdb_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRefdb : public
  NodeGitWrapper<GitRefdbTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRefdbTraits>;
   public:
    GitRefdb(const GitRefdb &) = delete;
    GitRefdb(GitRefdb &&) = delete;
    GitRefdb &operator=(const GitRefdb &) = delete;
    GitRefdb &operator=(GitRefdb &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

            GitRefdb(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRefdbTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRefdb cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRefdb();

  private:

    Napi::Value Compress(const Napi::CallbackInfo& info);
 
    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_refdb * out;
      git_repository * repo;
     };
    class OpenWorker : public nodegit::AsyncWorker {
      public:
        OpenWorker(
            OpenBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefdb:Open", cleanupHandles)
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
 };

#endif
