#ifndef NODEGIT_CONTEXT
#define NODEGIT_CONTEXT

#include <map>
#include <memory>
#include <napi.h>
#include <string>
#include <uv.h>

#include "async_worker.h"
#include "cleanup_handle.h"
#include "thread_pool.h"
#include "tracker_wrap.h"

namespace nodegit {
  class AsyncContextCleanupHandle;
  class Context {
  public:
    Context(Napi::Env env);
    Context(const Context &) = delete;
    Context(Context &&) = delete;
    Context &operator=(const Context &) = delete;
    Context &operator=(Context &&) = delete;

    ~Context();

    static Context *GetCurrentContext(Napi::Env env);
    static Context *GetCurrentContext();

    Napi::Value GetFromPersistent(std::string key);

    void QueueWorker(nodegit::AsyncWorker *worker);

    void SaveToPersistent(std::string key, Napi::Value value);

    void SaveCleanupHandle(std::string key, std::shared_ptr<nodegit::CleanupHandle> cleanupHandle);

    std::shared_ptr<nodegit::CleanupHandle> GetCleanupHandle(std::string key);

    std::shared_ptr<nodegit::CleanupHandle> RemoveCleanupHandle(std::string key);

    void ShutdownThreadPool(std::unique_ptr<AsyncContextCleanupHandle> cleanupHandle);

    void MarkWorkerCleanup() { isWorkerCleanup_ = true; }

    inline void LinkTrackerList(nodegit::TrackerWrap::TrackerList *list) {
      list->Link(&trackerList);
    }

    inline int TrackerListSize() {
      return nodegit::TrackerWrap::SizeFromList(&trackerList);
    }

    inline Napi::Env GetEnv() const {
      return Napi::Env(env_);
    }

  private:
    napi_env env_;

    ThreadPool threadPool;

    // This map contains persistent handles that need to be cleaned up
    // after the context has been torn down.
    // Often this is used as a context-aware storage cell for `*::InitializeComponent`
    // to store function templates on them.
    Napi::ObjectReference persistentStorage;

    std::map<std::string, std::shared_ptr<CleanupHandle>> cleanupHandles;

    nodegit::TrackerWrap::TrackerList trackerList;
    bool isWorkerCleanup_ = false;

    static std::map<napi_env, Context *> contexts;
    static thread_local Context *currentThreadContext;
  };

  class AsyncContextCleanupHandle {
    public:
      AsyncContextCleanupHandle(const AsyncContextCleanupHandle &) = delete;
      AsyncContextCleanupHandle(AsyncContextCleanupHandle &&) = delete;
      AsyncContextCleanupHandle &operator=(const AsyncContextCleanupHandle &) = delete;
      AsyncContextCleanupHandle &operator=(AsyncContextCleanupHandle &&) = delete;
      ~AsyncContextCleanupHandle();

    private:
      static void AsyncCleanupContext(napi_async_cleanup_hook_handle handle, void *data);

      friend class Context;
      AsyncContextCleanupHandle(Napi::Env env, Context *context);
      Context *context;
      napi_async_cleanup_hook_handle handle;
  };
}

#endif
