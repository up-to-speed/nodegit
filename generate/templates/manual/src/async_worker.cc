#include "../include/async_worker.h"

namespace nodegit {
  AsyncWorker::AsyncWorker(Napi::FunctionReference &&_callback, const char *resourceName, std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> &_cleanupHandles)
    : callback(std::move(_callback)), env_(callback.Env()), cleanupHandles(_cleanupHandles)
  {}

  AsyncWorker::AsyncWorker(Napi::FunctionReference &&_callback, const char *resourceName)
    : callback(std::move(_callback)), env_(callback.Env())
  {}

  AsyncWorker::~AsyncWorker() {}

  void AsyncWorker::Cancel() {
    isCancelled = true;

    // Trigger `HandleErrorCallback` for cancellation of AsyncWork
    errorMessage = "SHUTTING DOWN";
  }

  Napi::Reference<Napi::Value> *AsyncWorker::GetCallbackErrorHandle() {
    return &callbackErrorHandle;
  }

  bool AsyncWorker::GetIsCancelled() const {
    return isCancelled;
  }

  void AsyncWorker::Destroy() {
    std::for_each(cleanupCalls.begin(), cleanupCalls.end(), [](std::function<void()> cleanupCall) {
      cleanupCall();
    });
    persistentHandles.clear();
    callback.Reset();
    callbackErrorHandle.Reset();
  }

  void AsyncWorker::RegisterCleanupCall(std::function<void()> cleanupCall) {
    cleanupCalls.push_back(cleanupCall);
  }

  void AsyncWorker::SetErrorMessage(const char *msg) {
    errorMessage = msg;
  }

  const char *AsyncWorker::ErrorMessage() const {
    if (errorMessage.empty()) {
      return nullptr;
    }
    return errorMessage.c_str();
  }

  void AsyncWorker::SaveToPersistent(const char *label, Napi::Value value) {
    persistentHandles[label] = Napi::Reference<Napi::Value>::New(value, 1);
  }

  Napi::Value AsyncWorker::GetFromPersistent(const char *label) {
    auto it = persistentHandles.find(label);
    if (it != persistentHandles.end()) {
      return it->second.Value();
    }
    return Napi::Env(env_).Undefined();
  }

  void AsyncWorker::WorkComplete() {
    if (!errorMessage.empty()) {
      HandleErrorCallback();
    } else {
      HandleOKCallback();
    }
  }

  void AsyncWorker::HandleOKCallback() {
    if (!callback.IsEmpty()) {
      callback.Call({Napi::Env(env_).Null()});
    }
  }

  void AsyncWorker::HandleErrorCallback() {
    if (!callback.IsEmpty()) {
      callback.Call({Napi::Error::New(env_, errorMessage).Value()});
    }
  }
}
