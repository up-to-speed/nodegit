#ifndef NODEGIT_ASYNC_WORKER
#define NODEGIT_ASYNC_WORKER

#include <napi.h>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "lock_master.h"
#include "cleanup_handle.h"

namespace nodegit {
  class AsyncWorker {
  public:
    AsyncWorker(Napi::FunctionReference &&callback, const char *resourceName, std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &cleanupHandles);
    AsyncWorker(Napi::FunctionReference &&callback, const char *resourceName);
    AsyncWorker(const AsyncWorker &) = delete;
    AsyncWorker(AsyncWorker &&) = delete;
    AsyncWorker &operator=(const AsyncWorker &) = delete;
    AsyncWorker &operator=(AsyncWorker &&) = delete;
    virtual ~AsyncWorker();

    // This must be implemented by every async worker
    // so that the thread pool can lock separately
    // from the execute method in the AsyncWorker
    virtual nodegit::LockMaster AcquireLocks() = 0;

    virtual void Execute() = 0;

    virtual void HandleOKCallback();
    virtual void HandleErrorCallback();

    void WorkComplete();

    // Ensure that the `HandleErrorCallback` will be called
    // when the AsyncWork is complete
    void Cancel();

    Napi::Reference<Napi::Value> *GetCallbackErrorHandle();

    bool GetIsCancelled() const;

    void Destroy();

    void RegisterCleanupCall(std::function<void()> cleanupCall);

    void SetErrorMessage(const char *msg);
    const char *ErrorMessage() const;

    void SaveToPersistent(const char *label, Napi::Value value);
    Napi::Value GetFromPersistent(const char *label);

    template<class NodeGitWrapperT>
    void Reference(Napi::Value item) {
      if (item.IsFunction() || item.IsString() || item.IsNull() || item.IsUndefined()) {
        return;
      }

      auto objectWrapPointer = NodeGitWrapperT::Unwrap(item.As<Napi::Object>());
      objectWrapPointer->Reference();
      RegisterCleanupCall([objectWrapPointer]() {
        objectWrapPointer->Unreference();
      });
    }

    template<class NodeGitWrapperT>
    inline void Reference(const char *label, Napi::Value item) {
      SaveToPersistent(label, item);
      Reference<NodeGitWrapperT>(item);
    }

    template<class NodeGitWrapperT>
    inline void Reference(const char *label, Napi::Object item) {
      SaveToPersistent(label, item);
      Reference<NodeGitWrapperT>(item);
    }

    template<class NodeGitWrapperT>
    inline void Reference(const char *label, Napi::Array array) {
      SaveToPersistent(label, array);
      for (uint32_t i = 0; i < array.Length(); ++i) {
        Reference<NodeGitWrapperT>(array.Get(i));
      }
    }

    inline void Reference(const char *label, Napi::Value item) {
      SaveToPersistent(label, item);
    }

    Napi::Env Env() const { return Napi::Env(env_); }

    Napi::FunctionReference callback;
    napi_env env_;

  protected:
    std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
    Napi::Reference<Napi::Value> callbackErrorHandle;

  private:
    std::map<std::string, Napi::Reference<Napi::Value>> persistentHandles;
    std::vector<std::function<void()>> cleanupCalls;
    bool isCancelled = false;
    std::string errorMessage;

  };
}

#endif
