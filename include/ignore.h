// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITIGNORE_H
#define GITIGNORE_H
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

class GitIgnore : public
  Napi::ObjectWrap<GitIgnore>
{
   public:
    GitIgnore(const GitIgnore &) = delete;
    GitIgnore(GitIgnore &&) = delete;
    GitIgnore &operator=(const GitIgnore &) = delete;
    GitIgnore &operator=(GitIgnore &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

             
  private:

     static Napi::Value AddRule(const Napi::CallbackInfo& info);
      static Napi::Value ClearInternalRules(const Napi::CallbackInfo& info);
 
    struct PathIsIgnoredBaton {
      int error_code;
      const git_error* error;
      int * ignored;
      git_repository * repo;
      const char * path;
     };
    class PathIsIgnoredWorker : public nodegit::AsyncWorker {
      public:
        PathIsIgnoredWorker(
            PathIsIgnoredBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitIgnore:PathIsIgnored", cleanupHandles)
          , baton(_baton) {};
        PathIsIgnoredWorker(const PathIsIgnoredWorker &) = delete;
        PathIsIgnoredWorker(PathIsIgnoredWorker &&) = delete;
        PathIsIgnoredWorker &operator=(const PathIsIgnoredWorker &) = delete;
        PathIsIgnoredWorker &operator=(PathIsIgnoredWorker &&) = delete;
        ~PathIsIgnoredWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        PathIsIgnoredBaton *baton;
    };
     static Napi::Value PathIsIgnored(const Napi::CallbackInfo& info);
 };

#endif
