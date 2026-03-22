// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREVPARSE_H
#define GITREVPARSE_H
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

#include "../include/object.h"
#include "../include/reference.h"
#include "../include/repository.h"

class GitRevparse : public
  Napi::ObjectWrap<GitRevparse>
{
   public:
    GitRevparse(const GitRevparse &) = delete;
    GitRevparse(GitRevparse &&) = delete;
    GitRevparse &operator=(const GitRevparse &) = delete;
    GitRevparse &operator=(GitRevparse &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

            
  private:

     static Napi::Value Ext(const Napi::CallbackInfo& info);
 
    struct SingleBaton {
      int error_code;
      const git_error* error;
      git_object * out;
      git_repository * repo;
      const char * spec;
     };
    class SingleWorker : public nodegit::AsyncWorker {
      public:
        SingleWorker(
            SingleBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRevparse:Single", cleanupHandles)
          , baton(_baton) {};
        SingleWorker(const SingleWorker &) = delete;
        SingleWorker(SingleWorker &&) = delete;
        SingleWorker &operator=(const SingleWorker &) = delete;
        SingleWorker &operator=(SingleWorker &&) = delete;
        ~SingleWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SingleBaton *baton;
    };
     static Napi::Value Single(const Napi::CallbackInfo& info);
 };

#endif
