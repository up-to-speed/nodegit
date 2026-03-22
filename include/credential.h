// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCREDENTIAL_H
#define GITCREDENTIAL_H
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

class GitCredential;
 
struct GitCredentialTraits {
  typedef GitCredential cppClass;
  typedef git_credential cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_credential **dest, git_credential *src) {
     throw std::runtime_error("duplicate called on GitCredential which cannot be duplicated");
   }

  static std::string className() { return "GitCredential"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_credential *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_credential_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitCredential : public
  NodeGitWrapper<GitCredentialTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCredentialTraits>;
   public:
    GitCredential(const GitCredential &) = delete;
    GitCredential(GitCredential &&) = delete;
    GitCredential &operator=(const GitCredential &) = delete;
    GitCredential &operator=(GitCredential &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                         GitCredential(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCredentialTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCredential cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCredential();

  private:

     static Napi::Value DefaultNew(const Napi::CallbackInfo& info);
     Napi::Value GetUsername(const Napi::CallbackInfo& info);
     Napi::Value HasUsername(const Napi::CallbackInfo& info);
      static Napi::Value SshKeyFromAgent(const Napi::CallbackInfo& info);
 
    struct SshKeyMemoryNewBaton {
      int error_code;
      const git_error* error;
      git_credential * out;
      const char * username;
      const char * publickey;
      const char * privatekey;
      const char * passphrase;
     };
    class SshKeyMemoryNewWorker : public nodegit::AsyncWorker {
      public:
        SshKeyMemoryNewWorker(
            SshKeyMemoryNewBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCredential:SshKeyMemoryNew", cleanupHandles)
          , baton(_baton) {};
        SshKeyMemoryNewWorker(const SshKeyMemoryNewWorker &) = delete;
        SshKeyMemoryNewWorker(SshKeyMemoryNewWorker &&) = delete;
        SshKeyMemoryNewWorker &operator=(const SshKeyMemoryNewWorker &) = delete;
        SshKeyMemoryNewWorker &operator=(SshKeyMemoryNewWorker &&) = delete;
        ~SshKeyMemoryNewWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SshKeyMemoryNewBaton *baton;
    };
     static Napi::Value SshKeyMemoryNew(const Napi::CallbackInfo& info);
      static Napi::Value SshKeyNew(const Napi::CallbackInfo& info);
 
    struct UsernameNewBaton {
      int error_code;
      const git_error* error;
      git_credential * out;
      const char * username;
     };
    class UsernameNewWorker : public nodegit::AsyncWorker {
      public:
        UsernameNewWorker(
            UsernameNewBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitCredential:UsernameNew", cleanupHandles)
          , baton(_baton) {};
        UsernameNewWorker(const UsernameNewWorker &) = delete;
        UsernameNewWorker(UsernameNewWorker &&) = delete;
        UsernameNewWorker &operator=(const UsernameNewWorker &) = delete;
        UsernameNewWorker &operator=(UsernameNewWorker &&) = delete;
        ~UsernameNewWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        UsernameNewBaton *baton;
    };
     static Napi::Value UsernameNew(const Napi::CallbackInfo& info);
      static Napi::Value UserpassPlaintextNew(const Napi::CallbackInfo& info);
 };

#endif
