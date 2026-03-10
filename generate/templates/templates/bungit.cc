#include <napi.h>

#include <git2.h>
#include <map>
#include <algorithm>
#include <set>
#include <openssl/crypto.h>
#include <mutex>

#include "../include/init_ssh2.h"
#include "../include/lock_master.h"
#include "../include/bungit.h"
#include "../include/context.h"
#include "../include/wrapper.h"
#include "../include/promise_completion.h"
#include "../include/functions/copy.h"
{% each %}
  {% if type != "enum" %}
    #include "../include/{{ filename }}.h"
  {% endif %}
{% endeach %}
#include "../include/convenient_patch.h"
#include "../include/convenient_hunk.h"
#include "../include/filter_registry.h"

Napi::Value GetPrivate(Napi::Object object, Napi::String key) {
  Napi::Value value = object.Get(key);
  if (value.IsUndefined() || value.IsNull())
    return Napi::Value();
  return value;
}

void SetPrivate(Napi::Object object, Napi::String key, Napi::Value value) {
  if (value.IsUndefined())
    return;
  object.Set(key, value);
}

static uv_mutex_t *opensslMutexes;

void OpenSSL_LockingCallback(int mode, int type, const char *, int) {
  if (mode & CRYPTO_LOCK) {
    uv_mutex_lock(&opensslMutexes[type]);
  } else {
    uv_mutex_unlock(&opensslMutexes[type]);
  }
}

void OpenSSL_IDCallback(CRYPTO_THREADID *id) {
  CRYPTO_THREADID_set_numeric(id, (unsigned long)uv_thread_self());
}

void OpenSSL_ThreadSetup() {
  opensslMutexes=(uv_mutex_t *)malloc(CRYPTO_num_locks() * sizeof(uv_mutex_t));

  for (int i=0; i<CRYPTO_num_locks(); i++) {
    uv_mutex_init(&opensslMutexes[i]);
  }

  CRYPTO_set_locking_callback(OpenSSL_LockingCallback);
  CRYPTO_THREADID_set_callback(OpenSSL_IDCallback);
}

// diagnostic function
Napi::Value GetNumberOfTrackedObjects(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  nodegit::Context *currentNodeGitContext = nodegit::Context::GetCurrentContext();
  assert (currentNodeGitContext != nullptr);
  return Napi::Number::New(env, currentNodeGitContext->TrackerListSize());
}

static std::once_flag libraryInitializedFlag;
static std::mutex libraryInitializationMutex;

Napi::Object Init(Napi::Env env, Napi::Object target) {
  {
    // We only want to do initialization logic once, and we also want to prevent any thread from completely loading
    // the module until initialization has occurred.
    // All of this initialization logic ends up being shared.
    const std::lock_guard<std::mutex> lock(libraryInitializationMutex);
    std::call_once(libraryInitializedFlag, []() {
      // Initialize thread safety in openssl and libssh2
      OpenSSL_ThreadSetup();
      init_ssh2();
      // Initialize libgit2.
      git_libgit2_init();

      // Register thread pool with libgit2
      nodegit::ThreadPool::InitializeGlobal();
    });
  }

  // Exports function 'getNumberOfTrackedObjects'
  target.Set(
    Napi::String::New(env, "getNumberOfTrackedObjects"),
    Napi::Function::New(env, GetNumberOfTrackedObjects)
  );

  Napi::HandleScope scope(env);
  nodegit::Context *nodegitContext = new nodegit::Context(env);

  Wrapper::InitializeComponent(env, target, nodegitContext);
  PromiseCompletion::InitializeComponent(nodegitContext);
  {% each %}
    {% if type == 'class' %}
      {{ cppClassName }}::InitializeComponent(target, nodegitContext);
    {% elsif type == 'struct' %}
    {% if isReturnable %}
      {{ cppClassName }}::InitializeComponent(target, nodegitContext);
    {% endif %}
    {% endif %}
  {% endeach %}

  ConvenientHunk::InitializeComponent(target, nodegitContext);
  ConvenientPatch::InitializeComponent(target, nodegitContext);
  GitFilterRegistry::InitializeComponent(target, nodegitContext);

  nodegit::LockMaster::InitializeContext();

  return target;
}

NODE_API_MODULE(bungit, Init)
