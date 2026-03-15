// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/filter_list.h"
#include "bungit_wrapper.cc"

  #include "../include/git_buf_converter.h"
  #include "../include/filter_registry.h"
  #include "../include/buf.h"
  #include "../include/blob.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;

  GitFilterList::~GitFilterList() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                           }

  void GitFilterList::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "FilterList", {
          InstanceMethod("applyToBlob", &GitFilterList::ApplyToBlob, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("applyToData", &GitFilterList::ApplyToData, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("applyToFile", &GitFilterList::ApplyToFile, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("load", &GitFilterList::Load, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitFilterList::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitFilterList::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitFilterList::Template", constructor_template);
    target.Set(Napi::String::New(env, "FilterList"), constructor_template);
  }

 
/*
    * @param Blob blob
    * @param Buf callback
   */
Napi::Value GitFilterList::ApplyToBlob(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Blob blob is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ApplyToBlobBaton* baton = new ApplyToBlobBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->reserved = 0;
        baton->filters = Napi::ObjectWrap<GitFilterList>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  git_blob * from_blob = NULL;
from_blob = Napi::ObjectWrap<GitBlob>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->blob = from_blob;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ApplyToBlobWorker *worker = new ApplyToBlobWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitFilterList>("filters", info.This().As<Napi::Object>());
             worker->Reference<GitBlob>("blob", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitFilterList::ApplyToBlobWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->filters
          ,baton->blob
  );

  return lockMaster;
}

void GitFilterList::ApplyToBlobWorker::Execute() {
  git_error_clear();

    int result = git_filter_list_apply_to_blob(
baton->out,baton->filters,baton->blob  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitFilterList::ApplyToBlobWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "FilterList.applyToBlob"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }

  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

        git_buf_dispose(baton->out);
        free((void *)baton->out);

  delete baton;
}

void GitFilterList::ApplyToBlobWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
   if (baton->out) {
    v8ConversionSlot = Napi::String::New(env, baton->out->ptr, baton->out->size);
  }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
      Napi::Value result = v8ConversionSlot;
       
    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  } else {
    if (baton->error) {
      Napi::Object err;
      if (baton->error->message) {
        err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
      } else {
        err = Napi::Error::New(env, "Method applyToBlob has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "FilterList.applyToBlob"));
      napi_value argv[1] = {
        err
      };
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
        Napi::Object err = Napi::Error::New(env, "Method applyToBlob has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "FilterList.applyToBlob"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

        git_buf_dispose(baton->out);
        free((void *)baton->out);

  delete baton;
}

  
/*
    * @param Buf in
    * @param Buf callback
   */
Napi::Value GitFilterList::ApplyToData(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Buf in is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ApplyToDataBaton* baton = new ApplyToDataBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->reserved = 0;
        baton->filters = Napi::ObjectWrap<GitFilterList>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  git_buf * from_in = NULL;

  from_in = GitBufConverter::Convert(info[0]);
// end convert_from_v8 block
          baton->in = from_in;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ApplyToDataWorker *worker = new ApplyToDataWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitFilterList>("filters", info.This().As<Napi::Object>());
           worker->Reference("in", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitFilterList::ApplyToDataWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->filters
          ,baton->in
  );

  return lockMaster;
}

void GitFilterList::ApplyToDataWorker::Execute() {
  git_error_clear();

    int result = git_filter_list_apply_to_data(
baton->out,baton->filters,baton->in  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitFilterList::ApplyToDataWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "FilterList.applyToData"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }

  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

        git_buf_dispose(baton->out);
        free((void *)baton->out);
        git_buf_dispose(baton->in);
        free((void *)baton->in);

  delete baton;
}

void GitFilterList::ApplyToDataWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
   if (baton->out) {
    v8ConversionSlot = Napi::String::New(env, baton->out->ptr, baton->out->size);
  }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
      Napi::Value result = v8ConversionSlot;
       
    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  } else {
    if (baton->error) {
      Napi::Object err;
      if (baton->error->message) {
        err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
      } else {
        err = Napi::Error::New(env, "Method applyToData has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "FilterList.applyToData"));
      napi_value argv[1] = {
        err
      };
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
        Napi::Object err = Napi::Error::New(env, "Method applyToData has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "FilterList.applyToData"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

        git_buf_dispose(baton->out);
        free((void *)baton->out);
        git_buf_dispose(baton->in);
        free((void *)baton->in);

  delete baton;
}

  
/*
    * @param Repository repo
   * @param String path
    * @param Buf callback
   */
Napi::Value GitFilterList::ApplyToFile(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ApplyToFileBaton* baton = new ApplyToFileBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->reserved = 0;
        baton->filters = Napi::ObjectWrap<GitFilterList>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_path = (const char *) malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_path, path.c_str(), path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
// end convert_from_v8 block
          baton->path = from_path;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ApplyToFileWorker *worker = new ApplyToFileWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitFilterList>("filters", info.This().As<Napi::Object>());
             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("path", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitFilterList::ApplyToFileWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->filters
          ,baton->repo
          ,baton->path
  );

  return lockMaster;
}

void GitFilterList::ApplyToFileWorker::Execute() {
  git_error_clear();

    int result = git_filter_list_apply_to_file(
baton->out,baton->filters,baton->repo,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitFilterList::ApplyToFileWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "FilterList.applyToFile"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }

  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

        git_buf_dispose(baton->out);
        free((void *)baton->out);

  delete baton;
}

void GitFilterList::ApplyToFileWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
   if (baton->out) {
    // Return a Buffer to preserve raw bytes — filter output may contain
    // non-UTF-8 content (e.g. high bytes after CRLF normalization).
    v8ConversionSlot = Napi::Buffer<char>::Copy(env, baton->out->ptr, baton->out->size);
  }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
      Napi::Value result = v8ConversionSlot;
         
    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  } else {
    if (baton->error) {
      Napi::Object err;
      if (baton->error->message) {
        err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
      } else {
        err = Napi::Error::New(env, "Method applyToFile has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "FilterList.applyToFile"));
      napi_value argv[1] = {
        err
      };
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
        Napi::Object err = Napi::Error::New(env, "Method applyToFile has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "FilterList.applyToFile"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

        git_buf_dispose(baton->out);
        free((void *)baton->out);

  delete baton;
}

        // NOTE you may need to occasionally rebuild this method by calling the generators
// if major changes are made to the templates / generator.

// git_filter_list_load has a more complex ownership pattern than is currently available
// in the generator. This is because it not only has to get the repo as an owner,
// but it also needs to discover which custom filters, a git_filter, it is bound to, if any.
// We must enforce that the custom filters are not freed before a git_filter_list is freed,
// but a git_filter_list also has pointers to the repo in it.

// TODO In the future, it would be awesome if we could instead of writing a manual method like this, provide
// custom ownership methods that can be injected into the HandleOKCallback.

/*
 * @param Repository repo
 * @param Blob blob
 * @param String path
 * @param Number mode
 * @param Number flags
 * @param FilterList callback
 */
Napi::Value GitFilterList::Load(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsNumber()) {
    Napi::Error::New(env, "Number mode is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4 || !info[4].IsNumber()) {
    Napi::Error::New(env, "Number flags is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  LoadBaton *baton = new LoadBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

  // start convert_from_v8 block
  git_repository *from_repo = NULL;
  from_repo =
      GitRepository::Unwrap(info[0].As<Napi::Object>())->GetValue();
  // end convert_from_v8 block
  baton->repo = from_repo;
  // start convert_from_v8 block
  git_blob *from_blob = NULL;
  if (info[1].IsObject()) {
    from_blob =
        GitBlob::Unwrap(info[1].As<Napi::Object>())->GetValue();
  } else {
    from_blob = 0;
  }
  // end convert_from_v8 block
  baton->blob = from_blob;
  // start convert_from_v8 block
  const char *from_path = NULL;

  std::string path = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character
  // C-strings expect:
  from_path = (const char *)malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead
  // of strdup or strcpy because nulls in the middle of strings are valid coming
  // from nodejs):
  memcpy((void *)from_path, path.c_str(), path.length());
  // ensure the final byte of our new string is null, extra casts added to
  // ensure compatibility with various C types used in the nodejs binding
  // generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
  // end convert_from_v8 block
  baton->path = from_path;
  // start convert_from_v8 block
  git_filter_mode_t from_mode;
  from_mode = (git_filter_mode_t)(int)info[3].As<Napi::Number>().DoubleValue();
  // end convert_from_v8 block
  baton->mode = from_mode;
  // start convert_from_v8 block
  uint32_t from_flags;
  from_flags = (uint32_t)info[4].As<Napi::Number>().DoubleValue();
  // end convert_from_v8 block
  baton->flags = from_flags;

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  LoadWorker *worker = new LoadWorker(baton, std::move(callback), cleanupHandles);

  worker->Reference<GitRepository>("repo", info[0]);
  worker->Reference<GitBlob>("blob", info[1]);

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitFilterList::LoadWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    true,
    baton->repo,
    baton->blob,
    baton->path
  );
  return lockMaster;
}

void GitFilterList::LoadWorker::Execute() {
  git_error_clear();

  int result = git_filter_list_load(&baton->filters, baton->repo, baton->blob,
                                    baton->path, baton->mode, baton->flags);

  baton->error_code = result;

  if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitFilterList::LoadWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  git_filter_list_free(baton->filters);

  free((void *)baton->path);

  delete baton;
}

void GitFilterList::LoadWorker::HandleOKCallback() {
  Napi::Env env = Env();
  if (baton->error_code == GIT_OK) {
    Napi::Value to;
    // start convert_to_v8 block

    if (baton->filters != NULL) {
      // GitFilterList baton->filters
      Napi::Array owners = Napi::Array::New(env, 0);
      nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();

      owners.Set((uint32_t)0, this->GetFromPersistent("repo").As<Napi::Object>());

      to = GitFilterList::New(env, baton->filters, true, owners.As<Napi::Object>());
      auto filterListWrapper = GitFilterList::Unwrap(to.As<Napi::Object>());
      auto filterRegistryCleanupHandles = static_pointer_cast<nodegit::FilterRegistryCleanupHandles>(nodegit::Context::GetCurrentContext()->GetCleanupHandle("filterRegistry"));
      std::for_each(
        filterRegistryCleanupHandles->registeredFilters.begin(),
        filterRegistryCleanupHandles->registeredFilters.end(),
        [this, &filterListWrapper](std::pair<std::string, std::shared_ptr<nodegit::CleanupHandle>> filterCleanupHandle) {
          if (git_filter_list_contains(baton->filters, filterCleanupHandle.first.c_str())) {
            filterListWrapper->SaveCleanupHandle(filterCleanupHandle.second);
          }
        }
      );
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
        err = Napi::Error::New(env, "Method load has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set("errno", Napi::Number::New(env, baton->error_code));
      err.Set("errorFunction", Napi::String::New(env, "FilterList.load"));
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
        Napi::Object err = Napi::Error::New(env, "Method load has thrown an error.").Value().As<Napi::Object>();
        err.Set("errno", Napi::Number::New(env, baton->error_code));
        err.Set("errorFunction", Napi::String::New(env, "FilterList.load"));
        napi_value argv[1] = {err};
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }
  }

  free((void *)baton->path);

  delete baton;
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitFilterListTraits>;
 