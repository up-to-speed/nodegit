// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/blame.h"
#include "bungit_wrapper.cc"

  #include "../include/blame_hunk.h"
  #include "../include/blame_line.h"
  #include "../include/repository.h"
  #include "../include/blame_options.h"
 
#include <iostream>

using namespace std;

  GitBlame::~GitBlame() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                            }

  void GitBlame::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Blame", {
          InstanceMethod("buffer", &GitBlame::Buffer, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getHunkByIndex", &GitBlame::GetHunkByindex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getHunkByLine", &GitBlame::GetHunkByline, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getHunkCount", &GitBlame::GetHunkCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("hunkByIndex", &GitBlame::HunkByindex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("hunkByLine", &GitBlame::HunkByline, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("hunkcount", &GitBlame::Hunkcount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("lineByIndex", &GitBlame::LineByindex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("linecount", &GitBlame::Linecount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("file", &GitBlame::File, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitBlame::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitBlame::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitBlame::Template", constructor_template);
    target.Set(Napi::String::New(env, "Blame"), constructor_template);
  }

 
/*
    * @param String buffer
   * @param Number buffer_len
    * @param Blame callback
   */
Napi::Value GitBlame::Buffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String buffer is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number buffer_len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  BufferBaton* baton = new BufferBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->base = Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_buffer = NULL;

  std::string buffer = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_buffer = (const char *) malloc(buffer.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_buffer, buffer.c_str(), buffer.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_buffer) + buffer.length()), 0, 1);
// end convert_from_v8 block
          baton->buffer = from_buffer;
// start convert_from_v8 block
  size_t from_buffer_len;
      from_buffer_len = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->buffer_len = from_buffer_len;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  BufferWorker *worker = new BufferWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitBlame>("base", info.This().As<Napi::Object>());
           worker->Reference("buffer", info[0]);
            worker->Reference("buffer_len", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitBlame::BufferWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->base
          ,baton->buffer
  );

  return lockMaster;
}

void GitBlame::BufferWorker::Execute() {
  git_error_clear();

    int result = git_blame_buffer(
&baton->out,baton->base,baton->buffer,baton->buffer_len  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitBlame::BufferWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Blame.buffer"));
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

      free(baton->out);

  delete baton;
}

void GitBlame::BufferWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("reference").As<Napi::Object>());
             v8ConversionSlot = GitBlame::New(
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
        err = Napi::Error::New(env, "Method buffer has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Blame.buffer"));
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
        Napi::Object err = Napi::Error::New(env, "Method buffer has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Blame.buffer"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        free(baton->out);
  }


  delete baton;
}

   
/*
   * @param Number index
     * @return BlameHunk  result    */
Napi::Value GitBlame::GetHunkByindex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  uint32_t from_index;
      from_index = (uint32_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_blame_hunk * result =     git_blame_get_hunk_byindex(
          Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_index
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitBlameHunk::New(
        env,
        result,
        false
          , owners
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
   * @param Number lineno
     * @return BlameHunk  result    */
Napi::Value GitBlame::GetHunkByline(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number lineno is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_lineno;
      from_lineno = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_blame_hunk * result =     git_blame_get_hunk_byline(
          Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_lineno
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitBlameHunk::New(
        env,
        result,
        false
          , owners
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
     * @return Number  result    */
Napi::Value GitBlame::GetHunkCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 uint32_t result =     git_blame_get_hunk_count(
          Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Number index
     * @return BlameHunk  result    */
Napi::Value GitBlame::HunkByindex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_index;
      from_index = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_blame_hunk * result =     git_blame_hunk_byindex(
          Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_index
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitBlameHunk::New(
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
   * @param Number lineno
     * @return BlameHunk  result    */
Napi::Value GitBlame::HunkByline(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number lineno is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  size_t from_lineno;
      from_lineno = (size_t)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_blame_hunk * result =     git_blame_hunk_byline(
          Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_lineno
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitBlameHunk::New(
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
     * @return Number  result    */
Napi::Value GitBlame::Hunkcount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_blame_hunkcount(
          Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param Number idx
     * @return BlameLine  result    */
Napi::Value GitBlame::LineByindex(const Napi::CallbackInfo& info) {
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
              Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_blame_line * result =     git_blame_line_byindex(
          Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_idx
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitBlameLine::New(
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
     * @return Number  result    */
Napi::Value GitBlame::Linecount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 size_t result =     git_blame_linecount(
          Napi::ObjectWrap<GitBlame>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
  * @param Repository repo
   * @param String path
   * @param BlameOptions options
    * @param Blame callback
   */
Napi::Value GitBlame::File(const Napi::CallbackInfo& info) {
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

  FileBaton* baton = new FileBaton();

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
          if (info[2].IsNull() || info[2].IsUndefined()) {
            baton->options = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitBlameOptions::fromJavascript(nodegitContext, info[2]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["options"] = convertedObject;
            baton->options = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FileWorker *worker = new FileWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("path", info[1]);
            worker->Reference("options", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitBlame::FileWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->path
          ,baton->options
  );

  return lockMaster;
}

void GitBlame::FileWorker::Execute() {
  git_error_clear();

    int result = git_blame_file(
&baton->out,baton->repo,baton->path,baton->options  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitBlame::FileWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Blame.file"));
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

      git_blame_free(baton->out);

  delete baton;
}

void GitBlame::FileWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitBlame::New(
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
        err = Napi::Error::New(env, "Method file has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Blame.file"));
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
        Napi::Object err = Napi::Error::New(env, "Method file has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Blame.file"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_blame_free(baton->out);
  }


  delete baton;
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitBlameTraits>;
 