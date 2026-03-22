// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCLONE_H
#define GITCLONE_H
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
#include "../include/clone_options.h"

class GitClone : public
  Napi::ObjectWrap<GitClone>
{
   public:
    GitClone(const GitClone &) = delete;
    GitClone(GitClone &&) = delete;
    GitClone &operator=(const GitClone &) = delete;
    GitClone &operator=(GitClone &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

       
  private:


    struct CloneBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * url;
      const char * local_path;
      const git_clone_options * options;
     };
    class CloneWorker : public nodegit::AsyncWorker {
      public:
        CloneWorker(
            CloneBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitClone:Clone", cleanupHandles)
          , baton(_baton) {};
        CloneWorker(const CloneWorker &) = delete;
        CloneWorker(CloneWorker &&) = delete;
        CloneWorker &operator=(const CloneWorker &) = delete;
        CloneWorker &operator=(CloneWorker &&) = delete;
        ~CloneWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        CloneBaton *baton;
    };
     static Napi::Value Clone(const Napi::CallbackInfo& info);
 };

#endif
