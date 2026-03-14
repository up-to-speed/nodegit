#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
}

#include "../include/bungit.h"
#include "../include/cleanup_handle.h"
#include "../include/context.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/filter_registry.h"
#include "bungit_wrapper.cc"

#include "../include/filter.h"

using namespace std;

void GitFilterRegistry::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
  Napi::Env env = target.Env();

  Napi::Object filterRegistry = Napi::Object::New(env);

  filterRegistry.Set("register", Napi::Function::New(env, GitFilterRegister));
  filterRegistry.Set("unregister", Napi::Function::New(env, GitFilterUnregister));

  target.Set("FilterRegistry", filterRegistry);
  nodegitContext->SaveToPersistent("FilterRegistry", filterRegistry);
  std::shared_ptr<nodegit::FilterRegistryCleanupHandles> filterRegistryCleanupHandles(new nodegit::FilterRegistryCleanupHandles);
  nodegitContext->SaveCleanupHandle("filterRegistry", filterRegistryCleanupHandles);
}

Napi::Value GitFilterRegistry::GitFilterRegister(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Filter filter is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number priority is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FilterRegisterBaton *baton = new FilterRegisterBaton();
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

  {
    auto conversionResult = ConfigurableGitFilter::fromJavascript(nodegitContext, info[1]);
    if (!conversionResult.result) {
      delete baton;
      Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
      return env.Undefined();
    }

    auto convertedObject = conversionResult.result;
    cleanupHandles["filter"] = convertedObject;
    baton->filter = convertedObject->GetValue();
  }

  std::string name = info[0].As<Napi::String>().Utf8Value();

  baton->filter_name = (char *)malloc(name.length() + 1);
  memcpy((void *)baton->filter_name, name.c_str(), name.length());
  memset((void *)(((char *)baton->filter_name) + name.length()), 0, 1);

  baton->error_code = GIT_OK;
  baton->filter_priority = info[2].As<Napi::Number>().Int32Value();

  Napi::FunctionReference callback;
  callback.Reset(info[3].As<Napi::Function>(), 1);
  RegisterWorker *worker = new RegisterWorker(baton, std::move(callback), cleanupHandles);

  worker->Reference("filter_name", info[0]);
  worker->Reference("filter_priority", info[2]);

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitFilterRegistry::RegisterWorker::AcquireLocks() {
  return nodegit::LockMaster(true, baton->filter_name, baton->filter);
}

void GitFilterRegistry::RegisterWorker::Execute() {
  git_error_clear();

  {
    int result = git_filter_register(baton->filter_name, baton->filter, baton->filter_priority);
    baton->error_code = result;

    if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
      baton->error = git_error_dup(git_error_last());
    }
  }
}

void GitFilterRegistry::RegisterWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  free(baton->filter_name);

  delete baton;
}

void GitFilterRegistry::RegisterWorker::HandleOKCallback() {
  Napi::Env env = Env();
  if (baton->error_code == GIT_OK) {
    static_pointer_cast<nodegit::FilterRegistryCleanupHandles>(nodegit::Context::GetCurrentContext()->GetCleanupHandle("filterRegistry"))->registeredFilters[baton->filter_name] = cleanupHandles["filter"];
    Napi::Value result = Napi::Number::New(env, baton->error_code);
    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  }
  else if (baton->error) {
    Napi::Object err;
    if (baton->error->message) {
      err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
    } else {
      err = Napi::Error::New(env, "Method register has thrown an error.").Value().As<Napi::Object>();
    }
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "FilterRegistry.register"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
      free((void *)baton->error->message);
    free((void *)baton->error);
  }
  else if (baton->error_code < 0) {
    Napi::Object err = Napi::Error::New(env, "Method register has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "FilterRegistry.register"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }
  else {
    callback.Call({});
  }

  free(baton->filter_name);

  delete baton;
}

Napi::Value GitFilterRegistry::GitFilterUnregister(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FilterUnregisterBaton *baton = new FilterUnregisterBaton();
  std::string name = info[0].As<Napi::String>().Utf8Value();

  baton->filter_name = (char *)malloc(name.length() + 1);
  memcpy((void *)baton->filter_name, name.c_str(), name.length());
  memset((void *)(((char *)baton->filter_name) + name.length()), 0, 1);

  baton->error_code = GIT_OK;

  /* Setting up Async Worker */
  Napi::FunctionReference callback;
  callback.Reset(info[1].As<Napi::Function>(), 1);
  UnregisterWorker *worker = new UnregisterWorker(baton, std::move(callback));

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitFilterRegistry::UnregisterWorker::AcquireLocks() {
  return nodegit::LockMaster(true, baton->filter_name);
}

void GitFilterRegistry::UnregisterWorker::Execute() {
  git_error_clear();

  {
    int result = git_filter_unregister(baton->filter_name);
    baton->error_code = result;

    if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
      baton->error = git_error_dup(git_error_last());
    }
  }
}

void GitFilterRegistry::UnregisterWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  free(baton->filter_name);

  delete baton;
}

void GitFilterRegistry::UnregisterWorker::HandleOKCallback() {
  Napi::Env env = Env();
  if (baton->error_code == GIT_OK) {
    static_pointer_cast<nodegit::FilterRegistryCleanupHandles>(nodegit::Context::GetCurrentContext()->GetCleanupHandle("filterRegistry"))->registeredFilters.erase(baton->filter_name);
    Napi::Value result = Napi::Number::New(env, baton->error_code);
    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  }
  else if (baton->error) {
    Napi::Object err;
    if (baton->error->message) {
      err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
    } else {
      err = Napi::Error::New(env, "Method register has thrown an error.").Value().As<Napi::Object>();
    }
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "FilterRegistry.unregister"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
      free((void *)baton->error->message);
    free((void *)baton->error);
  }
  else if (baton->error_code < 0) {
    Napi::Object err = Napi::Error::New(env, "Method unregister has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "FilterRegistry.unregister"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }
  else {
    callback.Call({});
  }

  free(baton->filter_name);

  delete baton;
}
