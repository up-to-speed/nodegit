// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREFSPEC_H
#define GITREFSPEC_H
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

// Forward declaration.
struct git_refspec {
};
class GitRefspec;
 
struct GitRefspecTraits {
  typedef GitRefspec cppClass;
  typedef git_refspec cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_refspec **dest, git_refspec *src) {
     throw std::runtime_error("duplicate called on GitRefspec which cannot be duplicated");
   }

  static std::string className() { return "GitRefspec"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_refspec *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_refspec_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRefspec : public
  NodeGitWrapper<GitRefspecTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRefspecTraits>;
   public:
    GitRefspec(const GitRefspec &) = delete;
    GitRefspec(GitRefspec &&) = delete;
    GitRefspec &operator=(const GitRefspec &) = delete;
    GitRefspec &operator=(GitRefspec &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                     GitRefspec(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRefspecTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRefspec cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRefspec();

  private:

    Napi::Value Direction(const Napi::CallbackInfo& info);
     Napi::Value Dst(const Napi::CallbackInfo& info);
     Napi::Value DstMatches(const Napi::CallbackInfo& info);
     Napi::Value Force(const Napi::CallbackInfo& info);
 
    struct ParseBaton {
      int error_code;
      const git_error* error;
      git_refspec * refspec;
      const char * input;
      int is_fetch;
     };
    class ParseWorker : public nodegit::AsyncWorker {
      public:
        ParseWorker(
            ParseBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitRefspec:Parse", cleanupHandles)
          , baton(_baton) {};
        ParseWorker(const ParseWorker &) = delete;
        ParseWorker(ParseWorker &&) = delete;
        ParseWorker &operator=(const ParseWorker &) = delete;
        ParseWorker &operator=(ParseWorker &&) = delete;
        ~ParseWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        ParseBaton *baton;
    };
     static Napi::Value Parse(const Napi::CallbackInfo& info);
     Napi::Value Src(const Napi::CallbackInfo& info);
     Napi::Value SrcMatches(const Napi::CallbackInfo& info);
     Napi::Value SrcMatchesNegative(const Napi::CallbackInfo& info);
     Napi::Value String(const Napi::CallbackInfo& info);
 };

#endif
