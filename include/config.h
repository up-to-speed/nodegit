// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCONFIG_H
#define GITCONFIG_H
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
#include "../include/buf.h"
#include "../include/config_entry.h"
#include "../include/transaction.h"
// Forward declaration.
struct git_config {
};
class GitConfig;
 
struct GitConfigTraits {
  typedef GitConfig cppClass;
  typedef git_config cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_config **dest, git_config *src) {
     throw std::runtime_error("duplicate called on GitConfig which cannot be duplicated");
   }

  static std::string className() { return "GitConfig"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_config *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_config_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitConfig : public
  NodeGitWrapper<GitConfigTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitConfigTraits>;
   public:
    GitConfig(const GitConfig &) = delete;
    GitConfig(GitConfig &&) = delete;
    GitConfig &operator=(const GitConfig &) = delete;
    GitConfig &operator=(GitConfig &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                                                                                                      GitConfig(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitConfigTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitConfig cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitConfig();

  private:

    Napi::Value DeleteEntry(const Napi::CallbackInfo& info);
     Napi::Value DeleteMultivar(const Napi::CallbackInfo& info);
 
    struct FindGlobalBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
     };
    class FindGlobalWorker : public nodegit::AsyncWorker {
      public:
        FindGlobalWorker(
            FindGlobalBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:FindGlobal", cleanupHandles)
          , baton(_baton) {};
        FindGlobalWorker(const FindGlobalWorker &) = delete;
        FindGlobalWorker(FindGlobalWorker &&) = delete;
        FindGlobalWorker &operator=(const FindGlobalWorker &) = delete;
        FindGlobalWorker &operator=(FindGlobalWorker &&) = delete;
        ~FindGlobalWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FindGlobalBaton *baton;
    };
     static Napi::Value FindGlobal(const Napi::CallbackInfo& info);
 
    struct FindProgramdataBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
     };
    class FindProgramdataWorker : public nodegit::AsyncWorker {
      public:
        FindProgramdataWorker(
            FindProgramdataBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:FindProgramdata", cleanupHandles)
          , baton(_baton) {};
        FindProgramdataWorker(const FindProgramdataWorker &) = delete;
        FindProgramdataWorker(FindProgramdataWorker &&) = delete;
        FindProgramdataWorker &operator=(const FindProgramdataWorker &) = delete;
        FindProgramdataWorker &operator=(FindProgramdataWorker &&) = delete;
        ~FindProgramdataWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FindProgramdataBaton *baton;
    };
     static Napi::Value FindProgramdata(const Napi::CallbackInfo& info);
 
    struct FindSystemBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
     };
    class FindSystemWorker : public nodegit::AsyncWorker {
      public:
        FindSystemWorker(
            FindSystemBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:FindSystem", cleanupHandles)
          , baton(_baton) {};
        FindSystemWorker(const FindSystemWorker &) = delete;
        FindSystemWorker(FindSystemWorker &&) = delete;
        FindSystemWorker &operator=(const FindSystemWorker &) = delete;
        FindSystemWorker &operator=(FindSystemWorker &&) = delete;
        ~FindSystemWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FindSystemBaton *baton;
    };
     static Napi::Value FindSystem(const Napi::CallbackInfo& info);
 
    struct FindXdgBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
     };
    class FindXdgWorker : public nodegit::AsyncWorker {
      public:
        FindXdgWorker(
            FindXdgBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:FindXdg", cleanupHandles)
          , baton(_baton) {};
        FindXdgWorker(const FindXdgWorker &) = delete;
        FindXdgWorker(FindXdgWorker &&) = delete;
        FindXdgWorker &operator=(const FindXdgWorker &) = delete;
        FindXdgWorker &operator=(FindXdgWorker &&) = delete;
        ~FindXdgWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        FindXdgBaton *baton;
    };
     static Napi::Value FindXdg(const Napi::CallbackInfo& info);
 
    struct GetBoolBaton {
      int error_code;
      const git_error* error;
      int * out;
      const git_config * cfg;
      const char * name;
     };
    class GetBoolWorker : public nodegit::AsyncWorker {
      public:
        GetBoolWorker(
            GetBoolBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:GetBool", cleanupHandles)
          , baton(_baton) {};
        GetBoolWorker(const GetBoolWorker &) = delete;
        GetBoolWorker(GetBoolWorker &&) = delete;
        GetBoolWorker &operator=(const GetBoolWorker &) = delete;
        GetBoolWorker &operator=(GetBoolWorker &&) = delete;
        ~GetBoolWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetBoolBaton *baton;
    };
    Napi::Value GetBool(const Napi::CallbackInfo& info);
 
    struct GetEntryBaton {
      int error_code;
      const git_error* error;
      git_config_entry * out;
      const git_config * cfg;
      const char * name;
     };
    class GetEntryWorker : public nodegit::AsyncWorker {
      public:
        GetEntryWorker(
            GetEntryBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:GetEntry", cleanupHandles)
          , baton(_baton) {};
        GetEntryWorker(const GetEntryWorker &) = delete;
        GetEntryWorker(GetEntryWorker &&) = delete;
        GetEntryWorker &operator=(const GetEntryWorker &) = delete;
        GetEntryWorker &operator=(GetEntryWorker &&) = delete;
        ~GetEntryWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetEntryBaton *baton;
    };
    Napi::Value GetEntry(const Napi::CallbackInfo& info);
 
    struct GetInt32Baton {
      int error_code;
      const git_error* error;
      int32_t * out;
      const git_config * cfg;
      const char * name;
     };
    class GetInt32Worker : public nodegit::AsyncWorker {
      public:
        GetInt32Worker(
            GetInt32Baton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:GetInt32", cleanupHandles)
          , baton(_baton) {};
        GetInt32Worker(const GetInt32Worker &) = delete;
        GetInt32Worker(GetInt32Worker &&) = delete;
        GetInt32Worker &operator=(const GetInt32Worker &) = delete;
        GetInt32Worker &operator=(GetInt32Worker &&) = delete;
        ~GetInt32Worker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetInt32Baton *baton;
    };
    Napi::Value GetInt32(const Napi::CallbackInfo& info);
 
    struct GetInt64Baton {
      int error_code;
      const git_error* error;
      int64_t * out;
      const git_config * cfg;
      const char * name;
     };
    class GetInt64Worker : public nodegit::AsyncWorker {
      public:
        GetInt64Worker(
            GetInt64Baton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:GetInt64", cleanupHandles)
          , baton(_baton) {};
        GetInt64Worker(const GetInt64Worker &) = delete;
        GetInt64Worker(GetInt64Worker &&) = delete;
        GetInt64Worker &operator=(const GetInt64Worker &) = delete;
        GetInt64Worker &operator=(GetInt64Worker &&) = delete;
        ~GetInt64Worker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetInt64Baton *baton;
    };
    Napi::Value GetInt64(const Napi::CallbackInfo& info);
 
    struct GetPathBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_config * cfg;
      const char * name;
     };
    class GetPathWorker : public nodegit::AsyncWorker {
      public:
        GetPathWorker(
            GetPathBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:GetPath", cleanupHandles)
          , baton(_baton) {};
        GetPathWorker(const GetPathWorker &) = delete;
        GetPathWorker(GetPathWorker &&) = delete;
        GetPathWorker &operator=(const GetPathWorker &) = delete;
        GetPathWorker &operator=(GetPathWorker &&) = delete;
        ~GetPathWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetPathBaton *baton;
    };
    Napi::Value GetPath(const Napi::CallbackInfo& info);
 
    struct GetStringBufBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_config * cfg;
      const char * name;
     };
    class GetStringBufWorker : public nodegit::AsyncWorker {
      public:
        GetStringBufWorker(
            GetStringBufBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:GetStringBuf", cleanupHandles)
          , baton(_baton) {};
        GetStringBufWorker(const GetStringBufWorker &) = delete;
        GetStringBufWorker(GetStringBufWorker &&) = delete;
        GetStringBufWorker &operator=(const GetStringBufWorker &) = delete;
        GetStringBufWorker &operator=(GetStringBufWorker &&) = delete;
        ~GetStringBufWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        GetStringBufBaton *baton;
    };
    Napi::Value GetStringBuf(const Napi::CallbackInfo& info);
 
    struct LockBaton {
      int error_code;
      const git_error* error;
      git_transaction * tx;
      git_config * cfg;
     };
    class LockWorker : public nodegit::AsyncWorker {
      public:
        LockWorker(
            LockBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:Lock", cleanupHandles)
          , baton(_baton) {};
        LockWorker(const LockWorker &) = delete;
        LockWorker(LockWorker &&) = delete;
        LockWorker &operator=(const LockWorker &) = delete;
        LockWorker &operator=(LockWorker &&) = delete;
        ~LockWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        LockBaton *baton;
    };
    Napi::Value Lock(const Napi::CallbackInfo& info);
 
    struct OpenDefaultBaton {
      int error_code;
      const git_error* error;
      git_config * out;
     };
    class OpenDefaultWorker : public nodegit::AsyncWorker {
      public:
        OpenDefaultWorker(
            OpenDefaultBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:OpenDefault", cleanupHandles)
          , baton(_baton) {};
        OpenDefaultWorker(const OpenDefaultWorker &) = delete;
        OpenDefaultWorker(OpenDefaultWorker &&) = delete;
        OpenDefaultWorker &operator=(const OpenDefaultWorker &) = delete;
        OpenDefaultWorker &operator=(OpenDefaultWorker &&) = delete;
        ~OpenDefaultWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OpenDefaultBaton *baton;
    };
     static Napi::Value OpenDefault(const Napi::CallbackInfo& info);
 
    struct OpenOndiskBaton {
      int error_code;
      const git_error* error;
      git_config * out;
      const char * path;
     };
    class OpenOndiskWorker : public nodegit::AsyncWorker {
      public:
        OpenOndiskWorker(
            OpenOndiskBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:OpenOndisk", cleanupHandles)
          , baton(_baton) {};
        OpenOndiskWorker(const OpenOndiskWorker &) = delete;
        OpenOndiskWorker(OpenOndiskWorker &&) = delete;
        OpenOndiskWorker &operator=(const OpenOndiskWorker &) = delete;
        OpenOndiskWorker &operator=(OpenOndiskWorker &&) = delete;
        ~OpenOndiskWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        OpenOndiskBaton *baton;
    };
     static Napi::Value OpenOndisk(const Napi::CallbackInfo& info);
 
    struct SetBoolBaton {
      int error_code;
      const git_error* error;
      git_config * cfg;
      const char * name;
      int value;
     };
    class SetBoolWorker : public nodegit::AsyncWorker {
      public:
        SetBoolWorker(
            SetBoolBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:SetBool", cleanupHandles)
          , baton(_baton) {};
        SetBoolWorker(const SetBoolWorker &) = delete;
        SetBoolWorker(SetBoolWorker &&) = delete;
        SetBoolWorker &operator=(const SetBoolWorker &) = delete;
        SetBoolWorker &operator=(SetBoolWorker &&) = delete;
        ~SetBoolWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetBoolBaton *baton;
    };
    Napi::Value SetBool(const Napi::CallbackInfo& info);
 
    struct SetInt32Baton {
      int error_code;
      const git_error* error;
      git_config * cfg;
      const char * name;
      int32_t value;
     };
    class SetInt32Worker : public nodegit::AsyncWorker {
      public:
        SetInt32Worker(
            SetInt32Baton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:SetInt32", cleanupHandles)
          , baton(_baton) {};
        SetInt32Worker(const SetInt32Worker &) = delete;
        SetInt32Worker(SetInt32Worker &&) = delete;
        SetInt32Worker &operator=(const SetInt32Worker &) = delete;
        SetInt32Worker &operator=(SetInt32Worker &&) = delete;
        ~SetInt32Worker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetInt32Baton *baton;
    };
    Napi::Value SetInt32(const Napi::CallbackInfo& info);
 
    struct SetInt64Baton {
      int error_code;
      const git_error* error;
      git_config * cfg;
      const char * name;
      int64_t value;
     };
    class SetInt64Worker : public nodegit::AsyncWorker {
      public:
        SetInt64Worker(
            SetInt64Baton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:SetInt64", cleanupHandles)
          , baton(_baton) {};
        SetInt64Worker(const SetInt64Worker &) = delete;
        SetInt64Worker(SetInt64Worker &&) = delete;
        SetInt64Worker &operator=(const SetInt64Worker &) = delete;
        SetInt64Worker &operator=(SetInt64Worker &&) = delete;
        ~SetInt64Worker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetInt64Baton *baton;
    };
    Napi::Value SetInt64(const Napi::CallbackInfo& info);
 
    struct SetMultivarBaton {
      int error_code;
      const git_error* error;
      git_config * cfg;
      const char * name;
      const char * regexp;
      const char * value;
     };
    class SetMultivarWorker : public nodegit::AsyncWorker {
      public:
        SetMultivarWorker(
            SetMultivarBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:SetMultivar", cleanupHandles)
          , baton(_baton) {};
        SetMultivarWorker(const SetMultivarWorker &) = delete;
        SetMultivarWorker(SetMultivarWorker &&) = delete;
        SetMultivarWorker &operator=(const SetMultivarWorker &) = delete;
        SetMultivarWorker &operator=(SetMultivarWorker &&) = delete;
        ~SetMultivarWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetMultivarBaton *baton;
    };
    Napi::Value SetMultivar(const Napi::CallbackInfo& info);
 
    struct SetStringBaton {
      int error_code;
      const git_error* error;
      git_config * cfg;
      const char * name;
      const char * value;
     };
    class SetStringWorker : public nodegit::AsyncWorker {
      public:
        SetStringWorker(
            SetStringBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:SetString", cleanupHandles)
          , baton(_baton) {};
        SetStringWorker(const SetStringWorker &) = delete;
        SetStringWorker(SetStringWorker &&) = delete;
        SetStringWorker &operator=(const SetStringWorker &) = delete;
        SetStringWorker &operator=(SetStringWorker &&) = delete;
        ~SetStringWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SetStringBaton *baton;
    };
    Napi::Value SetString(const Napi::CallbackInfo& info);
     Napi::Value SetWriteorder(const Napi::CallbackInfo& info);
 
    struct SnapshotBaton {
      int error_code;
      const git_error* error;
      git_config * out;
      git_config * config;
     };
    class SnapshotWorker : public nodegit::AsyncWorker {
      public:
        SnapshotWorker(
            SnapshotBaton *_baton,
            Napi::FunctionReference callback,
            std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles
        ) : nodegit::AsyncWorker(std::move(callback), "bungit:AsyncWorker:GitConfig:Snapshot", cleanupHandles)
          , baton(_baton) {};
        SnapshotWorker(const SnapshotWorker &) = delete;
        SnapshotWorker(SnapshotWorker &&) = delete;
        SnapshotWorker &operator=(const SnapshotWorker &) = delete;
        SnapshotWorker &operator=(SnapshotWorker &&) = delete;
        ~SnapshotWorker() {};
        void Execute();
        void HandleErrorCallback();
        void HandleOKCallback();
        nodegit::LockMaster AcquireLocks();

      private:
        SnapshotBaton *baton;
    };
    Napi::Value Snapshot(const Napi::CallbackInfo& info);
 };

#endif
