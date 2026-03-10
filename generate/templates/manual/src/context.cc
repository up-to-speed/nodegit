#include "../include/context.h"

namespace nodegit {
  std::map<napi_env, Context *> Context::contexts;
  thread_local Context *Context::currentThreadContext = nullptr;

  AsyncContextCleanupHandle::AsyncContextCleanupHandle(Napi::Env env, Context *context)
    : context(context)
  {
    napi_add_async_cleanup_hook(napi_env(env), AsyncCleanupContext, this, &handle);
  }

  AsyncContextCleanupHandle::~AsyncContextCleanupHandle() {
    delete context;
    napi_remove_async_cleanup_hook(handle);
  }

  void AsyncContextCleanupHandle::AsyncCleanupContext(napi_async_cleanup_hook_handle handle, void *data) {
    std::unique_ptr<AsyncContextCleanupHandle> cleanupHandle(static_cast<AsyncContextCleanupHandle *>(data));
    cleanupHandle->handle = handle;
    // the ordering of std::move and the call to Context::ShutdownThreadPool prohibits
    // us from referring to context on cleanupHandle if we're also intending to move
    // the unique_ptr into the method.
    Context *context = cleanupHandle->context;
    context->ShutdownThreadPool(std::move(cleanupHandle));
  }

  Context::Context(Napi::Env env)
    : env_(env)
    , threadPool(10, ({
        uv_loop_t *loop;
        napi_get_uv_event_loop(napi_env(env), &loop);
        loop;
      }), this, napi_env(env))
  {
    Napi::HandleScope scope(env);
    Napi::Object storage = Napi::Object::New(env);
    persistentStorage = Napi::Persistent(storage);
    contexts[napi_env(env)] = this;
    currentThreadContext = this;
    new AsyncContextCleanupHandle(env, this);
  }

  Context::~Context() {
    nodegit::TrackerWrap::DeleteFromList(&trackerList);
    if (currentThreadContext == this) {
      currentThreadContext = nullptr;
    }
    contexts.erase(env_);
  }

  std::shared_ptr<CleanupHandle> Context::GetCleanupHandle(std::string key) {
    return cleanupHandles[key];
  }

  Context *Context::GetCurrentContext(Napi::Env env) {
    return contexts[napi_env(env)];
  }

  Context *Context::GetCurrentContext() {
    // Prefer the context tracked by the thread pool on worker threads, then
    // the env associated with the current JS thread, and finally the single
    // loaded context for legacy single-env call sites.
    const Context *tpContext = ThreadPool::GetCurrentContext();
    if (tpContext) {
      return const_cast<Context *>(tpContext);
    }
    if (currentThreadContext) {
      return currentThreadContext;
    }
    if (contexts.size() == 1) {
      return contexts.begin()->second;
    }
    return nullptr;
  }

  Napi::Value Context::GetFromPersistent(std::string key) {
    Napi::EscapableHandleScope scope(env_);
    Napi::Object storage = persistentStorage.Value();
    Napi::Value value = storage.Get(key);
    return scope.Escape(value);
  }

  void Context::QueueWorker(nodegit::AsyncWorker *worker) {
    threadPool.QueueWorker(worker);
  }

  std::shared_ptr<CleanupHandle> Context::RemoveCleanupHandle(std::string key) {
    std::shared_ptr<CleanupHandle> cleanupItem = cleanupHandles[key];
    cleanupHandles.erase(key);
    return cleanupItem;
  }

  void Context::SaveToPersistent(std::string key, Napi::Value value) {
    Napi::HandleScope scope(env_);
    Napi::Object storage = persistentStorage.Value();
    storage.Set(key, value);
  }

  void Context::SaveCleanupHandle(std::string key, std::shared_ptr<CleanupHandle> cleanupItem) {
    cleanupHandles[key] = cleanupItem;
  }

  void Context::ShutdownThreadPool(std::unique_ptr<AsyncContextCleanupHandle> cleanupHandle) {
    threadPool.Shutdown(std::move(cleanupHandle));
  }
}
