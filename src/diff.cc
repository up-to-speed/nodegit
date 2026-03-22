// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/diff.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff.h"
#include "bungit_wrapper.cc"

  #include "../include/blob.h"
  #include "../include/diff_options.h"
  #include "../include/diff_delta.h"
  #include "../include/diff_binary.h"
  #include "../include/diff_hunk.h"
  #include "../include/diff_line.h"
  #include "../include/diff_find_options.h"
  #include "../include/diff_stats.h"
  #include "../include/repository.h"
  #include "../include/index.h"
  #include "../include/oid.h"
  #include "../include/diff_patchid_options.h"
  #include "../include/buf.h"
  #include "../include/tree.h"
  #include "../include/diff_perfdata.h"
 
#include <iostream>

using namespace std;

  GitDiff::~GitDiff() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                }

  void GitDiff::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Diff", {
           StaticMethod("blobToBuffer", &GitDiff::BlobToBuffer, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("findSimilar", &GitDiff::FindSimilar, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("fromBuffer", &GitDiff::FromBuffer, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getDelta", &GitDiff::GetDelta, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getStats", &GitDiff::GetStats, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("indexToIndex", &GitDiff::IndexToIndex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("indexToWorkdir", &GitDiff::IndexToWorkdir, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("isSortedIcase", &GitDiff::IsSortedIcase, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("merge", &GitDiff::Merge, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("numDeltas", &GitDiff::NumDeltas, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("patchid", &GitDiff::Patchid, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("toBuf", &GitDiff::ToBuf, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("treeToIndex", &GitDiff::TreeToIndex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("treeToTree", &GitDiff::TreeToTree, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("treeToWorkdir", &GitDiff::TreeToWorkdir, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("treeToWorkdirWithIndex", &GitDiff::TreeToWorkdirWithIndex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getPerfdata", &GitDiff::GetPerfdata, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitDiff::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitDiff::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitDiff::Template", constructor_template);
    target.Set(Napi::String::New(env, "Diff"), constructor_template);
  }

 
/*
 * @param Blob old_blob
   * @param String old_as_path
   * @param String buffer
   * @param Number buffer_len
   * @param String buffer_as_path
   * @param DiffOptions options
   * @param DiffFileCb file_cb
   * @param DiffBinaryCb binary_cb
   * @param DiffHunkCb hunk_cb
   * @param DiffLineCb line_cb
   * @param Void payload
     */
Napi::Value GitDiff::BlobToBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  BlobToBufferBaton* baton = new BlobToBufferBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

      BlobToBuffer_globalPayload* globalPayload = new BlobToBuffer_globalPayload;

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const git_blob * from_old_blob = NULL;
    if ((info.Length() - 1) > 0 && info[0].IsObject()) {
from_old_blob = Napi::ObjectWrap<GitBlob>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
  else {
    from_old_blob = 0;
  }
// end convert_from_v8 block
          baton->old_blob = from_old_blob;
// start convert_from_v8 block
  const char * from_old_as_path = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsString()) {

  std::string old_as_path = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_old_as_path = (const char *) malloc(old_as_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_old_as_path, old_as_path.c_str(), old_as_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_old_as_path) + old_as_path.length()), 0, 1);
  }
  else {
    from_old_as_path = 0;
  }
// end convert_from_v8 block
          baton->old_as_path = from_old_as_path;
// start convert_from_v8 block
  const char * from_buffer = NULL;
    if ((info.Length() - 1) > 2 && info[2].IsString()) {

  std::string buffer = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_buffer = (const char *) malloc(buffer.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_buffer, buffer.c_str(), buffer.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_buffer) + buffer.length()), 0, 1);
  }
  else {
    from_buffer = 0;
  }
// end convert_from_v8 block
          baton->buffer = from_buffer;
// start convert_from_v8 block
  size_t from_buffer_len;
    if ((info.Length() - 1) > 3 && info[3].IsNumber()) {
      from_buffer_len = (size_t)   info[3].As<Napi::Number>().DoubleValue ();
  }
  else {
    from_buffer_len = 0;
  }
// end convert_from_v8 block
          baton->buffer_len = from_buffer_len;
// start convert_from_v8 block
  const char * from_buffer_as_path = NULL;
    if ((info.Length() - 1) > 4 && info[4].IsString()) {

  std::string buffer_as_path = info[4].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_buffer_as_path = (const char *) malloc(buffer_as_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_buffer_as_path, buffer_as_path.c_str(), buffer_as_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_buffer_as_path) + buffer_as_path.length()), 0, 1);
  }
  else {
    from_buffer_as_path = 0;
  }
// end convert_from_v8 block
          baton->buffer_as_path = from_buffer_as_path;
          if (info[5].IsNull() || info[5].IsUndefined()) {
            baton->options = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitDiffOptions::fromJavascript(nodegitContext, info[5]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["options"] = convertedObject;
            baton->options = convertedObject->GetValue();
          }
         if (!info[6].IsFunction()) {
          baton->file_cb = NULL;
          globalPayload->file_cb = NULL;
        }
        else {
          baton->file_cb = BlobToBuffer_file_cb_cppCallback;
            globalPayload->file_cb = new Napi::FunctionReference();
            *(globalPayload->file_cb) = Napi::Persistent(info[6].As<Napi::Function>());
        }
        if (!info[7].IsFunction()) {
          baton->binary_cb = NULL;
          globalPayload->binary_cb = NULL;
        }
        else {
          baton->binary_cb = BlobToBuffer_binary_cb_cppCallback;
            globalPayload->binary_cb = new Napi::FunctionReference();
            *(globalPayload->binary_cb) = Napi::Persistent(info[7].As<Napi::Function>());
        }
        if (!info[8].IsFunction()) {
          baton->hunk_cb = NULL;
          globalPayload->hunk_cb = NULL;
        }
        else {
          baton->hunk_cb = BlobToBuffer_hunk_cb_cppCallback;
            globalPayload->hunk_cb = new Napi::FunctionReference();
            *(globalPayload->hunk_cb) = Napi::Persistent(info[8].As<Napi::Function>());
        }
        if (!info[9].IsFunction()) {
          baton->line_cb = NULL;
          globalPayload->line_cb = NULL;
        }
        else {
          baton->line_cb = BlobToBuffer_line_cb_cppCallback;
            globalPayload->line_cb = new Napi::FunctionReference();
            *(globalPayload->line_cb) = Napi::Persistent(info[9].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  BlobToBufferWorker *worker = new BlobToBufferWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitBlob>("old_blob", info[0]);
             worker->Reference("old_as_path", info[1]);
            worker->Reference("buffer", info[2]);
            worker->Reference("buffer_len", info[3]);
            worker->Reference("buffer_as_path", info[4]);
            worker->Reference("options", info[5]);
            worker->Reference("payload", info[10]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::BlobToBufferWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->old_blob
          ,baton->old_as_path
          ,baton->buffer
          ,baton->buffer_as_path
          ,baton->options
          ,baton->payload
  );

  return lockMaster;
}

void GitDiff::BlobToBufferWorker::Execute() {
  git_error_clear();

    int result = git_diff_blob_to_buffer(
baton->old_blob,baton->old_as_path,baton->buffer,baton->buffer_len,baton->buffer_as_path,baton->options,baton->file_cb,baton->binary_cb,baton->hunk_cb,baton->line_cb,baton->payload  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::BlobToBufferWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.blobToBuffer"));
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

      delete (BlobToBuffer_globalPayload*)baton->payload;

  delete baton;
}

void GitDiff::BlobToBufferWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value result = env.Undefined();
                        
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
        err = Napi::Error::New(env, "Method blobToBuffer has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.blobToBuffer"));
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
        Napi::Object err = Napi::Error::New(env, "Method blobToBuffer has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.blobToBuffer"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      delete (BlobToBuffer_globalPayload*)baton->payload;

  delete baton;
}


int GitDiff::BlobToBuffer_file_cb_cppCallback (
    const git_diff_delta * delta,     float progress,     void * payload  ) {
  BlobToBuffer_FileCbBaton baton(1);

    baton.delta = delta;
    baton.progress = progress;
    baton.payload = payload;
 
  return baton.ExecuteAsync(BlobToBuffer_file_cb_async, BlobToBuffer_file_cb_cancelAsync);
}

void GitDiff::BlobToBuffer_file_cb_cancelAsync(void *untypedBaton) {
  BlobToBuffer_FileCbBaton* baton = static_cast<BlobToBuffer_FileCbBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitDiff::BlobToBuffer_file_cb_async(void *untypedBaton) {
  BlobToBuffer_FileCbBaton* baton = static_cast<BlobToBuffer_FileCbBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((BlobToBuffer_globalPayload*)baton->payload)->file_cb;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         GitDiffDelta::New(env, baton->delta, false)
 ,           Napi::Number::New(env, baton->progress)
    };

  Napi::Value result;
  bool callSucceeded = false;
  try {
    napi_value napi_argv[2];
    for (int _i = 0; _i < 2; _i++) {
      napi_argv[_i] = argv[_i];
    }
    result = callback->Call(env.Undefined(), 2, napi_argv);
    callSucceeded = !result.IsEmpty();
  } catch (const Napi::Error& e) {
    // exception occurred — result is invalid, don't forward
  }

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, BlobToBuffer_file_cb_promiseCompleted)) {
    return;
  }

    if (result.IsUndefined() || result.IsNull()) {
      baton->result = baton->defaultResult;
    }
    else if (!result.IsNull() && !result.IsUndefined()) {
       if (result.IsNumber()) {
        baton->result = result.As<Napi::Number>().Int32Value();
      }
      else {
        baton->result = baton->defaultResult;
      }
     }
    else {
      baton->result = baton->defaultResult;
    }
 
  baton->Done();
}

void GitDiff::BlobToBuffer_file_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  BlobToBuffer_FileCbBaton* baton = static_cast<BlobToBuffer_FileCbBaton*>(_baton);

  if (isFulfilled) {
      if (result.IsUndefined() || result.IsNull()) {
        baton->result = baton->defaultResult;
      }
      else if (!result.IsNull() && !result.IsUndefined()) {
         if (result.IsNumber()) {
          baton->result = result.As<Napi::Number>().Int32Value();
        }
        else {
          baton->result = baton->defaultResult;
        }
       }
      else {
        baton->result = baton->defaultResult;
      }
   }
  else {
    // promise was rejected
    GitDiff* instance = static_cast<GitDiff*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitDiff>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}

int GitDiff::BlobToBuffer_binary_cb_cppCallback (
    const git_diff_delta * delta,     const git_diff_binary * binary,     void * payload  ) {
  BlobToBuffer_BinaryCbBaton baton(0);

    baton.delta = delta;
    baton.binary = binary;
    baton.payload = payload;
 
  return baton.ExecuteAsync(BlobToBuffer_binary_cb_async, BlobToBuffer_binary_cb_cancelAsync);
}

void GitDiff::BlobToBuffer_binary_cb_cancelAsync(void *untypedBaton) {
  BlobToBuffer_BinaryCbBaton* baton = static_cast<BlobToBuffer_BinaryCbBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitDiff::BlobToBuffer_binary_cb_async(void *untypedBaton) {
  BlobToBuffer_BinaryCbBaton* baton = static_cast<BlobToBuffer_BinaryCbBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((BlobToBuffer_globalPayload*)baton->payload)->binary_cb;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         GitDiffDelta::New(env, baton->delta, false)
 ,          GitDiffBinary::New(env, baton->binary, false)
    };

  Napi::Value result;
  bool callSucceeded = false;
  try {
    napi_value napi_argv[2];
    for (int _i = 0; _i < 2; _i++) {
      napi_argv[_i] = argv[_i];
    }
    result = callback->Call(env.Undefined(), 2, napi_argv);
    callSucceeded = !result.IsEmpty();
  } catch (const Napi::Error& e) {
    // exception occurred — result is invalid, don't forward
  }

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, BlobToBuffer_binary_cb_promiseCompleted)) {
    return;
  }

    if (result.IsUndefined() || result.IsNull()) {
      baton->result = baton->defaultResult;
    }
    else if (!result.IsNull() && !result.IsUndefined()) {
       if (result.IsNumber()) {
        baton->result = result.As<Napi::Number>().Int32Value();
      }
      else {
        baton->result = baton->defaultResult;
      }
     }
    else {
      baton->result = baton->defaultResult;
    }
 
  baton->Done();
}

void GitDiff::BlobToBuffer_binary_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  BlobToBuffer_BinaryCbBaton* baton = static_cast<BlobToBuffer_BinaryCbBaton*>(_baton);

  if (isFulfilled) {
      if (result.IsUndefined() || result.IsNull()) {
        baton->result = baton->defaultResult;
      }
      else if (!result.IsNull() && !result.IsUndefined()) {
         if (result.IsNumber()) {
          baton->result = result.As<Napi::Number>().Int32Value();
        }
        else {
          baton->result = baton->defaultResult;
        }
       }
      else {
        baton->result = baton->defaultResult;
      }
   }
  else {
    // promise was rejected
    GitDiff* instance = static_cast<GitDiff*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitDiff>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}

int GitDiff::BlobToBuffer_hunk_cb_cppCallback (
    const git_diff_delta * delta,     const git_diff_hunk * hunk,     void * payload  ) {
  BlobToBuffer_HunkCbBaton baton(1);

    baton.delta = delta;
    baton.hunk = hunk;
    baton.payload = payload;
 
  return baton.ExecuteAsync(BlobToBuffer_hunk_cb_async, BlobToBuffer_hunk_cb_cancelAsync);
}

void GitDiff::BlobToBuffer_hunk_cb_cancelAsync(void *untypedBaton) {
  BlobToBuffer_HunkCbBaton* baton = static_cast<BlobToBuffer_HunkCbBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitDiff::BlobToBuffer_hunk_cb_async(void *untypedBaton) {
  BlobToBuffer_HunkCbBaton* baton = static_cast<BlobToBuffer_HunkCbBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((BlobToBuffer_globalPayload*)baton->payload)->hunk_cb;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         GitDiffDelta::New(env, baton->delta, false)
 ,          GitDiffHunk::New(env, baton->hunk, false)
    };

  Napi::Value result;
  bool callSucceeded = false;
  try {
    napi_value napi_argv[2];
    for (int _i = 0; _i < 2; _i++) {
      napi_argv[_i] = argv[_i];
    }
    result = callback->Call(env.Undefined(), 2, napi_argv);
    callSucceeded = !result.IsEmpty();
  } catch (const Napi::Error& e) {
    // exception occurred — result is invalid, don't forward
  }

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, BlobToBuffer_hunk_cb_promiseCompleted)) {
    return;
  }

    if (result.IsUndefined() || result.IsNull()) {
      baton->result = baton->defaultResult;
    }
    else if (!result.IsNull() && !result.IsUndefined()) {
       if (result.IsNumber()) {
        baton->result = result.As<Napi::Number>().Int32Value();
      }
      else {
        baton->result = baton->defaultResult;
      }
     }
    else {
      baton->result = baton->defaultResult;
    }
 
  baton->Done();
}

void GitDiff::BlobToBuffer_hunk_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  BlobToBuffer_HunkCbBaton* baton = static_cast<BlobToBuffer_HunkCbBaton*>(_baton);

  if (isFulfilled) {
      if (result.IsUndefined() || result.IsNull()) {
        baton->result = baton->defaultResult;
      }
      else if (!result.IsNull() && !result.IsUndefined()) {
         if (result.IsNumber()) {
          baton->result = result.As<Napi::Number>().Int32Value();
        }
        else {
          baton->result = baton->defaultResult;
        }
       }
      else {
        baton->result = baton->defaultResult;
      }
   }
  else {
    // promise was rejected
    GitDiff* instance = static_cast<GitDiff*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitDiff>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}

int GitDiff::BlobToBuffer_line_cb_cppCallback (
    const git_diff_delta * delta,     const git_diff_hunk * hunk,     const git_diff_line * line,     void * payload  ) {
  BlobToBuffer_LineCbBaton baton(1);

    baton.delta = delta;
    baton.hunk = hunk;
    baton.line = line;
    baton.payload = payload;
 
  return baton.ExecuteAsync(BlobToBuffer_line_cb_async, BlobToBuffer_line_cb_cancelAsync);
}

void GitDiff::BlobToBuffer_line_cb_cancelAsync(void *untypedBaton) {
  BlobToBuffer_LineCbBaton* baton = static_cast<BlobToBuffer_LineCbBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitDiff::BlobToBuffer_line_cb_async(void *untypedBaton) {
  BlobToBuffer_LineCbBaton* baton = static_cast<BlobToBuffer_LineCbBaton*>(untypedBaton);

     Napi::FunctionReference* callback = ((BlobToBuffer_globalPayload*)baton->payload)->line_cb;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[3] = {
         GitDiffDelta::New(env, baton->delta, false)
 ,          GitDiffHunk::New(env, baton->hunk, false)
 ,          GitDiffLine::New(env, baton->line, false)
    };

  Napi::Value result;
  bool callSucceeded = false;
  try {
    napi_value napi_argv[3];
    for (int _i = 0; _i < 3; _i++) {
      napi_argv[_i] = argv[_i];
    }
    result = callback->Call(env.Undefined(), 3, napi_argv);
    callSucceeded = !result.IsEmpty();
  } catch (const Napi::Error& e) {
    // exception occurred — result is invalid, don't forward
  }

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, BlobToBuffer_line_cb_promiseCompleted)) {
    return;
  }

    if (result.IsUndefined() || result.IsNull()) {
      baton->result = baton->defaultResult;
    }
    else if (!result.IsNull() && !result.IsUndefined()) {
       if (result.IsNumber()) {
        baton->result = result.As<Napi::Number>().Int32Value();
      }
      else {
        baton->result = baton->defaultResult;
      }
     }
    else {
      baton->result = baton->defaultResult;
    }
 
  baton->Done();
}

void GitDiff::BlobToBuffer_line_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  BlobToBuffer_LineCbBaton* baton = static_cast<BlobToBuffer_LineCbBaton*>(_baton);

  if (isFulfilled) {
      if (result.IsUndefined() || result.IsNull()) {
        baton->result = baton->defaultResult;
      }
      else if (!result.IsNull() && !result.IsUndefined()) {
         if (result.IsNumber()) {
          baton->result = result.As<Napi::Number>().Int32Value();
        }
        else {
          baton->result = baton->defaultResult;
        }
       }
      else {
        baton->result = baton->defaultResult;
      }
   }
  else {
    // promise was rejected
    GitDiff* instance = static_cast<GitDiff*>(baton->   payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitDiff>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
  
/*
   * @param DiffFindOptions options
     */
Napi::Value GitDiff::FindSimilar(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FindSimilarBaton* baton = new FindSimilarBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->diff = Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue();
          if (info[0].IsNull() || info[0].IsUndefined()) {
            baton->options = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitDiffFindOptions::fromJavascript(nodegitContext, info[0]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["options"] = convertedObject;
            baton->options = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FindSimilarWorker *worker = new FindSimilarWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitDiff>("diff", info.This().As<Napi::Object>());
           worker->Reference("options", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::FindSimilarWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->diff
          ,baton->options
  );

  return lockMaster;
}

void GitDiff::FindSimilarWorker::Execute() {
  git_error_clear();

    int result = git_diff_find_similar(
baton->diff,baton->options  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::FindSimilarWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.findSimilar"));
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


  delete baton;
}

void GitDiff::FindSimilarWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value result = env.Undefined();
      
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
        err = Napi::Error::New(env, "Method findSimilar has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.findSimilar"));
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
        Napi::Object err = Napi::Error::New(env, "Method findSimilar has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.findSimilar"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }


  delete baton;
}

  
/*
  * @param String content
   * @param Number content_len
    * @param Diff callback
   */
Napi::Value GitDiff::FromBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String content is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number content_len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FromBufferBaton* baton = new FromBufferBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const char * from_content = NULL;

  std::string content = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_content = (const char *) malloc(content.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_content, content.c_str(), content.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_content) + content.length()), 0, 1);
// end convert_from_v8 block
          baton->content = from_content;
// start convert_from_v8 block
  size_t from_content_len;
      from_content_len = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->content_len = from_content_len;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FromBufferWorker *worker = new FromBufferWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("content", info[0]);
            worker->Reference("content_len", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::FromBufferWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->content
  );

  return lockMaster;
}

void GitDiff::FromBufferWorker::Execute() {
  git_error_clear();

    int result = git_diff_from_buffer(
&baton->out,baton->content,baton->content_len  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::FromBufferWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.fromBuffer"));
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

      git_diff_free(baton->out);

  delete baton;
}

void GitDiff::FromBufferWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitDiff::New(
        env,
        baton->out,
        true
       );
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
        err = Napi::Error::New(env, "Method fromBuffer has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.fromBuffer"));
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
        Napi::Object err = Napi::Error::New(env, "Method fromBuffer has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.fromBuffer"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_diff_free(baton->out);
  }


  delete baton;
}

   
/*
   * @param Number idx
     * @return DiffDelta  result    */
Napi::Value GitDiff::GetDelta(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number idx is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_idx;
      from_idx = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_diff_delta * result =     git_diff_get_delta(
          Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_idx
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitDiffDelta::New(
        env,
        result,
        false
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
     * @param DiffStats callback
   */
Napi::Value GitDiff::GetStats(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  GetStatsBaton* baton = new GetStatsBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->diff = Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  GetStatsWorker *worker = new GetStatsWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitDiff>("diff", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::GetStatsWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->diff
  );

  return lockMaster;
}

void GitDiff::GetStatsWorker::Execute() {
  git_error_clear();

    int result = git_diff_get_stats(
&baton->out,baton->diff  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::GetStatsWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.getStats"));
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


  delete baton;
}

void GitDiff::GetStatsWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("diff").As<Napi::Object>());
             v8ConversionSlot = GitDiffStats::New(
        env,
        baton->out,
        true
          , owners
       );
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
        err = Napi::Error::New(env, "Method getStats has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.getStats"));
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
        Napi::Object err = Napi::Error::New(env, "Method getStats has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.getStats"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Index old_index
   * @param Index new_index
   * @param DiffOptions opts
    * @param Diff callback
   */
Napi::Value GitDiff::IndexToIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Index old_index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Index new_index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsObject()) {
    Napi::Error::New(env, "DiffOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  IndexToIndexBaton* baton = new IndexToIndexBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  git_index * from_old_index = NULL;
from_old_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->old_index = from_old_index;
// start convert_from_v8 block
  git_index * from_new_index = NULL;
from_new_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->new_index = from_new_index;
            {
            auto conversionResult = ConfigurableGitDiffOptions::fromJavascript(nodegitContext, info[3]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  IndexToIndexWorker *worker = new IndexToIndexWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitIndex>("old_index", info[1]);
               worker->Reference<GitIndex>("new_index", info[2]);
             worker->Reference("opts", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::IndexToIndexWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->old_index
          ,baton->new_index
          ,baton->opts
  );

  return lockMaster;
}

void GitDiff::IndexToIndexWorker::Execute() {
  git_error_clear();

    int result = git_diff_index_to_index(
&baton->diff,baton->repo,baton->old_index,baton->new_index,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::IndexToIndexWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.indexToIndex"));
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

      git_diff_free(baton->diff);

  delete baton;
}

void GitDiff::IndexToIndexWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->diff != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitDiff::New(
        env,
        baton->diff,
        true
          , owners
       );
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
        err = Napi::Error::New(env, "Method indexToIndex has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.indexToIndex"));
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
        Napi::Object err = Napi::Error::New(env, "Method indexToIndex has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.indexToIndex"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_diff_free(baton->diff);
  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Index index
   * @param DiffOptions opts
    * @param Diff callback
   */
Napi::Value GitDiff::IndexToWorkdir(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  IndexToWorkdirBaton* baton = new IndexToWorkdirBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  git_index * from_index = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsObject()) {
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
  else {
    from_index = 0;
  }
// end convert_from_v8 block
          baton->index = from_index;
          if (info[2].IsNull() || info[2].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitDiffOptions::fromJavascript(nodegitContext, info[2]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  IndexToWorkdirWorker *worker = new IndexToWorkdirWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitIndex>("index", info[1]);
             worker->Reference("opts", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::IndexToWorkdirWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->index
          ,baton->opts
  );

  return lockMaster;
}

void GitDiff::IndexToWorkdirWorker::Execute() {
  git_error_clear();

    int result = git_diff_index_to_workdir(
&baton->diff,baton->repo,baton->index,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::IndexToWorkdirWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.indexToWorkdir"));
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

      git_diff_free(baton->diff);

  delete baton;
}

void GitDiff::IndexToWorkdirWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->diff != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitDiff::New(
        env,
        baton->diff,
        true
          , owners
       );
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
        err = Napi::Error::New(env, "Method indexToWorkdir has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.indexToWorkdir"));
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
        Napi::Object err = Napi::Error::New(env, "Method indexToWorkdir has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.indexToWorkdir"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_diff_free(baton->diff);
  }


  delete baton;
}

   
/*
     * @return Number  result    */
Napi::Value GitDiff::IsSortedIcase(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_diff_is_sorted_icase(
          Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
   * @param Diff from
     */
Napi::Value GitDiff::Merge(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Diff from is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  MergeBaton* baton = new MergeBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->onto = Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_diff * from_from = NULL;
from_from = Napi::ObjectWrap<GitDiff>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->from = from_from;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  MergeWorker *worker = new MergeWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitDiff>("onto", info.This().As<Napi::Object>());
             worker->Reference<GitDiff>("from", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::MergeWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->onto
          ,baton->from
  );

  return lockMaster;
}

void GitDiff::MergeWorker::Execute() {
  git_error_clear();

    int result = git_diff_merge(
baton->onto,baton->from  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::MergeWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.merge"));
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


  delete baton;
}

void GitDiff::MergeWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value result = env.Undefined();
     
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
        err = Napi::Error::New(env, "Method merge has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.merge"));
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
        Napi::Object err = Napi::Error::New(env, "Method merge has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.merge"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }


  delete baton;
}

   
/*
     * @return Number  result    */
Napi::Value GitDiff::NumDeltas(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_diff_num_deltas(
          Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
    * @param DiffPatchidOptions opts
    * @param Oid callback
   */
Napi::Value GitDiff::Patchid(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "DiffPatchidOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  PatchidBaton* baton = new PatchidBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_oid *)malloc(sizeof(git_oid ));
        baton->diff = Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue();
            {
            auto conversionResult = ConfigurableGitDiffPatchidOptions::fromJavascript(nodegitContext, info[0]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  PatchidWorker *worker = new PatchidWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitDiff>("diff", info.This().As<Napi::Object>());
           worker->Reference("opts", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::PatchidWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->diff
          ,baton->opts
  );

  return lockMaster;
}

void GitDiff::PatchidWorker::Execute() {
  git_error_clear();

    int result = git_diff_patchid(
baton->out,baton->diff,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::PatchidWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.patchid"));
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


  delete baton;
}

void GitDiff::PatchidWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        baton->out,
        true
       );
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
        err = Napi::Error::New(env, "Method patchid has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.patchid"));
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
        Napi::Object err = Napi::Error::New(env, "Method patchid has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.patchid"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }


  delete baton;
}

  
/*
    * @param Number format
    * @param Buf callback
   */
Napi::Value GitDiff::ToBuf(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number format is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ToBufBaton* baton = new ToBufBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->reserved = 0;
        baton->diff = Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  git_diff_format_t from_format;
      from_format = (git_diff_format_t)  (int) info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->format = from_format;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ToBufWorker *worker = new ToBufWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitDiff>("diff", info.This().As<Napi::Object>());
           worker->Reference("format", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::ToBufWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->diff
  );

  return lockMaster;
}

void GitDiff::ToBufWorker::Execute() {
  git_error_clear();

    int result = git_diff_to_buf(
baton->out,baton->diff,baton->format  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::ToBufWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.toBuf"));
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

void GitDiff::ToBufWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method toBuf has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.toBuf"));
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
        Napi::Object err = Napi::Error::New(env, "Method toBuf has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.toBuf"));
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
  * @param Repository repo
   * @param Tree old_tree
   * @param Index index
   * @param DiffOptions opts
    * @param Diff callback
   */
Napi::Value GitDiff::TreeToIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  TreeToIndexBaton* baton = new TreeToIndexBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  git_tree * from_old_tree = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsObject()) {
from_old_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
  else {
    from_old_tree = 0;
  }
// end convert_from_v8 block
          baton->old_tree = from_old_tree;
// start convert_from_v8 block
  git_index * from_index = NULL;
    if ((info.Length() - 1) > 2 && info[2].IsObject()) {
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
  else {
    from_index = 0;
  }
// end convert_from_v8 block
          baton->index = from_index;
          if (info[3].IsNull() || info[3].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitDiffOptions::fromJavascript(nodegitContext, info[3]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  TreeToIndexWorker *worker = new TreeToIndexWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitTree>("old_tree", info[1]);
               worker->Reference<GitIndex>("index", info[2]);
             worker->Reference("opts", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::TreeToIndexWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->old_tree
          ,baton->index
          ,baton->opts
  );

  return lockMaster;
}

void GitDiff::TreeToIndexWorker::Execute() {
  git_error_clear();

    int result = git_diff_tree_to_index(
&baton->diff,baton->repo,baton->old_tree,baton->index,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::TreeToIndexWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToIndex"));
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

      git_diff_free(baton->diff);

  delete baton;
}

void GitDiff::TreeToIndexWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->diff != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitDiff::New(
        env,
        baton->diff,
        true
          , owners
       );
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
        err = Napi::Error::New(env, "Method treeToIndex has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToIndex"));
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
        Napi::Object err = Napi::Error::New(env, "Method treeToIndex has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToIndex"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_diff_free(baton->diff);
  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Tree old_tree
   * @param Tree new_tree
   * @param DiffOptions opts
    * @param Diff callback
   */
Napi::Value GitDiff::TreeToTree(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  TreeToTreeBaton* baton = new TreeToTreeBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  git_tree * from_old_tree = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsObject()) {
from_old_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
  else {
    from_old_tree = 0;
  }
// end convert_from_v8 block
          baton->old_tree = from_old_tree;
// start convert_from_v8 block
  git_tree * from_new_tree = NULL;
    if ((info.Length() - 1) > 2 && info[2].IsObject()) {
from_new_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
  else {
    from_new_tree = 0;
  }
// end convert_from_v8 block
          baton->new_tree = from_new_tree;
          if (info[3].IsNull() || info[3].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitDiffOptions::fromJavascript(nodegitContext, info[3]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  TreeToTreeWorker *worker = new TreeToTreeWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitTree>("old_tree", info[1]);
               worker->Reference<GitTree>("new_tree", info[2]);
             worker->Reference("opts", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::TreeToTreeWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->old_tree
          ,baton->new_tree
          ,baton->opts
  );

  return lockMaster;
}

void GitDiff::TreeToTreeWorker::Execute() {
  git_error_clear();

    int result = git_diff_tree_to_tree(
&baton->diff,baton->repo,baton->old_tree,baton->new_tree,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::TreeToTreeWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToTree"));
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

      git_diff_free(baton->diff);

  delete baton;
}

void GitDiff::TreeToTreeWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->diff != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitDiff::New(
        env,
        baton->diff,
        true
          , owners
       );
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
        err = Napi::Error::New(env, "Method treeToTree has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToTree"));
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
        Napi::Object err = Napi::Error::New(env, "Method treeToTree has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToTree"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_diff_free(baton->diff);
  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Tree old_tree
   * @param DiffOptions opts
    * @param Diff callback
   */
Napi::Value GitDiff::TreeToWorkdir(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  TreeToWorkdirBaton* baton = new TreeToWorkdirBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  git_tree * from_old_tree = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsObject()) {
from_old_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
  else {
    from_old_tree = 0;
  }
// end convert_from_v8 block
          baton->old_tree = from_old_tree;
          if (info[2].IsNull() || info[2].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitDiffOptions::fromJavascript(nodegitContext, info[2]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  TreeToWorkdirWorker *worker = new TreeToWorkdirWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitTree>("old_tree", info[1]);
             worker->Reference("opts", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::TreeToWorkdirWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->old_tree
          ,baton->opts
  );

  return lockMaster;
}

void GitDiff::TreeToWorkdirWorker::Execute() {
  git_error_clear();

    int result = git_diff_tree_to_workdir(
&baton->diff,baton->repo,baton->old_tree,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::TreeToWorkdirWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToWorkdir"));
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

      git_diff_free(baton->diff);

  delete baton;
}

void GitDiff::TreeToWorkdirWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->diff != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitDiff::New(
        env,
        baton->diff,
        true
          , owners
       );
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
        err = Napi::Error::New(env, "Method treeToWorkdir has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToWorkdir"));
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
        Napi::Object err = Napi::Error::New(env, "Method treeToWorkdir has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToWorkdir"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_diff_free(baton->diff);
  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Tree old_tree
   * @param DiffOptions opts
    * @param Diff callback
   */
Napi::Value GitDiff::TreeToWorkdirWithIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  TreeToWorkdirWithIndexBaton* baton = new TreeToWorkdirWithIndexBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  git_tree * from_old_tree = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsObject()) {
from_old_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
  else {
    from_old_tree = 0;
  }
// end convert_from_v8 block
          baton->old_tree = from_old_tree;
          if (info[2].IsNull() || info[2].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitDiffOptions::fromJavascript(nodegitContext, info[2]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  TreeToWorkdirWithIndexWorker *worker = new TreeToWorkdirWithIndexWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitTree>("old_tree", info[1]);
             worker->Reference("opts", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitDiff::TreeToWorkdirWithIndexWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->old_tree
          ,baton->opts
  );

  return lockMaster;
}

void GitDiff::TreeToWorkdirWithIndexWorker::Execute() {
  git_error_clear();

    int result = git_diff_tree_to_workdir_with_index(
&baton->diff,baton->repo,baton->old_tree,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitDiff::TreeToWorkdirWithIndexWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToWorkdirWithIndex"));
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

      git_diff_free(baton->diff);

  delete baton;
}

void GitDiff::TreeToWorkdirWithIndexWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->diff != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitDiff::New(
        env,
        baton->diff,
        true
          , owners
       );
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
        err = Napi::Error::New(env, "Method treeToWorkdirWithIndex has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToWorkdirWithIndex"));
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
        Napi::Object err = Napi::Error::New(env, "Method treeToWorkdirWithIndex has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Diff.treeToWorkdirWithIndex"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_diff_free(baton->diff);
  }


  delete baton;
}

   
/*
      * @return DiffPerfdata out    */
Napi::Value GitDiff::GetPerfdata(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

      git_diff_perfdata *out = (git_diff_perfdata *)malloc(sizeof(git_diff_perfdata));

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_diff_get_perfdata(
          out
,          Napi::ObjectWrap<GitDiff>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

      if (result != GIT_OK) {
          free(out);

        if (git_error_last()->klass != GIT_ERROR_NONE) {
          Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
          return env.Undefined();
        } else {
          Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
          return env.Undefined();
        }
      } // lock master scope end

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (out != NULL) {
        v8ConversionSlot = GitDiffPerfdata::New(
        env,
        out,
        true
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitDiffTraits>;
 