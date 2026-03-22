// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/clone.h"
#include "bungit_wrapper.cc"

  #include "../include/repository.h"
  #include "../include/clone_options.h"
 
#include <iostream>

using namespace std;

 
  void GitClone::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

      Napi::Function object = Napi::Function::New(env, Clone);
         object.Set("clone", Napi::Function::New(env, Clone));
  
    target.Set(
      Napi::String::New(env, "Clone"),
      object
    );
  }

       // NOTE you may need to occasionally rebuild this method by calling the generators
// if major changes are made to the templates / generator.

// Due to some file locking issues, we have the need to free a repository after it's cloned.
// We do not expose free functions to javascript, and so, we've moved the implementation of
// cloning, freeing the repo, and opening the repo into a custom template.

/*
 * @param String url
 * @param String local_path
 * @param CloneOptions options
 * @param Repository callback
 */
Napi::Value GitClone::Clone(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String url is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String local_path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CloneBaton *baton = new CloneBaton();
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

  if (info[2].IsNull() || info[2].IsUndefined()) {
    baton->options = nullptr;
  } else {
    auto conversionResult = ConfigurableGitCloneOptions::fromJavascript(nodegitContext, info[2]);
    if (!conversionResult.result) {
      Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
      return env.Undefined();
    }

    auto convertedObject = conversionResult.result;
    cleanupHandles["options"] = convertedObject;
    baton->options = convertedObject->GetValue();
  }

  baton->error_code = GIT_OK;
  baton->error = NULL;

  // start convert_from_v8 block
  const char *from_url = NULL;

  std::string url = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character
  // C-strings expect:
  from_url = (const char *)malloc(url.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead
  // of strdup or strcpy because nulls in the middle of strings are valid coming
  // from nodejs):
  memcpy((void *)from_url, url.c_str(), url.length());
  // ensure the final byte of our new string is null, extra casts added to
  // ensure compatibility with various C types used in the nodejs binding
  // generation:
  memset((void *)(((char *)from_url) + url.length()), 0, 1);
  // end convert_from_v8 block
  baton->url = from_url;
  // start convert_from_v8 block
  const char *from_local_path = NULL;

  std::string local_path = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character
  // C-strings expect:
  from_local_path = (const char *)malloc(local_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead
  // of strdup or strcpy because nulls in the middle of strings are valid coming
  // from nodejs):
  memcpy((void *)from_local_path, local_path.c_str(), local_path.length());
  // ensure the final byte of our new string is null, extra casts added to
  // ensure compatibility with various C types used in the nodejs binding
  // generation:
  memset((void *)(((char *)from_local_path) + local_path.length()), 0, 1);
  // end convert_from_v8 block
  baton->local_path = from_local_path;

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  CloneWorker *worker = new CloneWorker(baton, std::move(callback), cleanupHandles);

  worker->Reference("url", info[0]);
  worker->Reference("local_path", info[1]);

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitClone::CloneWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    true,
    baton->url,
    baton->local_path,
    baton->options
  );
  return lockMaster;
}

void GitClone::CloneWorker::Execute() {
  git_error_clear();

  git_repository *repo;
  int result =
      git_clone(&repo, baton->url, baton->local_path, baton->options);

  if (result == GIT_OK) {
    // This is required to clean up after the clone to avoid file locking
    // issues in Windows and potentially other issues we don't know about.
    git_repository_free(repo);

    // We want to provide a valid repository object, so reopen the repository
    // after clone and cleanup.
    result = git_repository_open(&baton->out, baton->local_path);
  }

  baton->error_code = result;

  if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitClone::CloneWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  git_repository_free(baton->out);

  free((void*)baton->url);
  free((void*)baton->local_path);

  delete baton;
}

void GitClone::CloneWorker::HandleOKCallback() {
  Napi::Env env = Env();
  if (baton->error_code == GIT_OK) {
    Napi::Value to;
    // start convert_to_v8 block

    if (baton->out != NULL) {
      // GitRepository baton->out
      to = GitRepository::New(env, baton->out, true);
    } else {
      to = env.Null();
    }

    // end convert_to_v8 block
    Napi::Value result = to;

    napi_value argv[2] = {env.Null(), result};
    callback.Call(env.Undefined(), 2, argv);
  } else {
    if (baton->error) {
      Napi::Object err;
      if (baton->error->message) {
        err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
      } else {
        err = Napi::Error::New(env, "Method clone has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set("errno", Napi::Number::New(env, baton->error_code));
      err.Set("errorFunction", Napi::String::New(env, "Clone.clone"));
      napi_value argv[1] = {err};
      callback.Call(env.Undefined(), 1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      bool callbackFired = false;
      if (!callbackErrorHandle.IsEmpty()) {
        Napi::Value maybeError = callbackErrorHandle.Value();
        if (!maybeError.IsNull() && !maybeError.IsUndefined()) {
          napi_value argv[1] = {
            maybeError
          };
          callback.Call(env.Undefined(), 1, argv);
          callbackFired = true;
        }
      }

      if (!callbackFired) {
        Napi::Object err = Napi::Error::New(env, "Method clone has thrown an error.").Value().As<Napi::Object>();
        err.Set("errno", Napi::Number::New(env, baton->error_code));
        err.Set("errorFunction", Napi::String::New(env, "Clone.clone"));
        napi_value argv[1] = {err};
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }
  }

  free((void*)baton->url);
  free((void*)baton->local_path);

  delete baton;
}

     