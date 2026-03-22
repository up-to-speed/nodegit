// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/graph.h"
#include "bungit_wrapper.cc"

  #include "../include/repository.h"
  #include "../include/oid.h"
 
#include <iostream>

using namespace std;

 
  void GitGraph::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

       Napi::Object object = Napi::Object::New(env);
         object.Set("aheadBehind", Napi::Function::New(env, AheadBehind));
         object.Set("descendantOf", Napi::Function::New(env, DescendantOf));
         object.Set("reachableFromAny", Napi::Function::New(env, ReachableFromAny));
  
    target.Set(
      Napi::String::New(env, "Graph"),
      object
    );
  }

 
/*
   * @param Repository repo
   * @param Oid local
   * @param Oid upstream
    * @param Number callback
  * @param Number callback
   */
Napi::Value GitGraph::AheadBehind(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid local is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 2
    || (!info[2].IsObject() && !info[2].IsString())) {
    Napi::Error::New(env, "Oid upstream is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AheadBehindBaton* baton = new AheadBehindBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->ahead = (size_t *)malloc(sizeof(size_t ));
      baton->behind = (size_t *)malloc(sizeof(size_t ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const git_oid * from_local = NULL;
  if (info[1].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[1].As<Napi::String>().Utf8Value();
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(oidString.c_str())) != GIT_OK) {
      free(oidOut);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }

    from_local = oidOut;
  }
  else {
from_local = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->local = from_local;
            baton->localNeedsFree = info[1].IsString();
// start convert_from_v8 block
  const git_oid * from_upstream = NULL;
  if (info[2].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[2].As<Napi::String>().Utf8Value();
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(oidString.c_str())) != GIT_OK) {
      free(oidOut);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }

    from_upstream = oidOut;
  }
  else {
from_upstream = Napi::ObjectWrap<GitOid>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->upstream = from_upstream;
            baton->upstreamNeedsFree = info[2].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  AheadBehindWorker *worker = new AheadBehindWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitOid>("local", info[1]);
               worker->Reference<GitOid>("upstream", info[2]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitGraph::AheadBehindWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->ahead
          ,baton->behind
          ,baton->repo
          ,baton->local
          ,baton->upstream
  );

  return lockMaster;
}

void GitGraph::AheadBehindWorker::Execute() {
  git_error_clear();

    int result = git_graph_ahead_behind(
baton->ahead,baton->behind,baton->repo,baton->local,baton->upstream  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitGraph::AheadBehindWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Graph.aheadBehind"));
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

      if (baton->localNeedsFree) {
        baton->localNeedsFree = false;
        free((void *)baton->local);
      }
      if (baton->upstreamNeedsFree) {
        baton->upstreamNeedsFree = false;
        free((void *)baton->upstream);
      }

  delete baton;
}

void GitGraph::AheadBehindWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
      Napi::Object result = Napi::Object::New(env);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->ahead);
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "ahead"), v8ConversionSlot);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->behind);
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "behind"), v8ConversionSlot);
           
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
        err = Napi::Error::New(env, "Method aheadBehind has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Graph.aheadBehind"));
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
        Napi::Object err = Napi::Error::New(env, "Method aheadBehind has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Graph.aheadBehind"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->localNeedsFree) {
        baton->localNeedsFree = false;
        free((void *)baton->local);
      }
      if (baton->upstreamNeedsFree) {
        baton->upstreamNeedsFree = false;
        free((void *)baton->upstream);
      }

  delete baton;
}

  
/*
 * @param Repository repo
   * @param Oid commit
   * @param Oid ancestor
    * @param Number callback
   */
Napi::Value GitGraph::DescendantOf(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid commit is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 2
    || (!info[2].IsObject() && !info[2].IsString())) {
    Napi::Error::New(env, "Oid ancestor is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  DescendantOfBaton* baton = new DescendantOfBaton();

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
  const git_oid * from_commit = NULL;
  if (info[1].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[1].As<Napi::String>().Utf8Value();
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(oidString.c_str())) != GIT_OK) {
      free(oidOut);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }

    from_commit = oidOut;
  }
  else {
from_commit = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->commit = from_commit;
            baton->commitNeedsFree = info[1].IsString();
// start convert_from_v8 block
  const git_oid * from_ancestor = NULL;
  if (info[2].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[2].As<Napi::String>().Utf8Value();
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(oidString.c_str())) != GIT_OK) {
      free(oidOut);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }

    from_ancestor = oidOut;
  }
  else {
from_ancestor = Napi::ObjectWrap<GitOid>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->ancestor = from_ancestor;
            baton->ancestorNeedsFree = info[2].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  DescendantOfWorker *worker = new DescendantOfWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitOid>("commit", info[1]);
               worker->Reference<GitOid>("ancestor", info[2]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitGraph::DescendantOfWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->commit
          ,baton->ancestor
  );

  return lockMaster;
}

void GitGraph::DescendantOfWorker::Execute() {
  git_error_clear();

    int result = git_graph_descendant_of(
baton->repo,baton->commit,baton->ancestor  );

      baton->error_code = result;
      if (result < GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitGraph::DescendantOfWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Graph.descendantOf"));
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

      if (baton->commitNeedsFree) {
        baton->commitNeedsFree = false;
        free((void *)baton->commit);
      }
      if (baton->ancestorNeedsFree) {
        baton->ancestorNeedsFree = false;
        free((void *)baton->ancestor);
      }

  delete baton;
}

void GitGraph::DescendantOfWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code >= GIT_OK) {
    Napi::Value result = Napi::Number::New(env, baton->error_code);

       
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
        err = Napi::Error::New(env, "Method descendantOf has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Graph.descendantOf"));
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
        Napi::Object err = Napi::Error::New(env, "Method descendantOf has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Graph.descendantOf"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->commitNeedsFree) {
        baton->commitNeedsFree = false;
        free((void *)baton->commit);
      }
      if (baton->ancestorNeedsFree) {
        baton->ancestorNeedsFree = false;
        free((void *)baton->ancestor);
      }

  delete baton;
}

  
/*
 * @param Repository repo
   * @param Oid commit
   * @param Array descendant_array
   * @param Number length
    * @param Number callback
   */
Napi::Value GitGraph::ReachableFromAny(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid commit is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Array descendant_array is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsNumber()) {
    Napi::Error::New(env, "Number length is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ReachableFromAnyBaton* baton = new ReachableFromAnyBaton();

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
  const git_oid * from_commit = NULL;
  if (info[1].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[1].As<Napi::String>().Utf8Value();
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(oidString.c_str())) != GIT_OK) {
      free(oidOut);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }

    from_commit = oidOut;
  }
  else {
from_commit = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->commit = from_commit;
            baton->commitNeedsFree = info[1].IsString();
// start convert_from_v8 block
  git_oid * from_descendant_array = NULL;

  Napi::Array tmp_descendant_array = info[2].As<Napi::Array>();
  from_descendant_array = (git_oid *)malloc(tmp_descendant_array.Length() * sizeof(git_oid));
  for (unsigned int i = 0; i < tmp_descendant_array.Length(); i++) {
    const Napi::Value arrayVal = tmp_descendant_array.Get(i);
      if (arrayVal.IsString()) {
        // Try and parse in a string to a git_oid
        std::string oidString = arrayVal.As<Napi::String>().Utf8Value();

        if (git_oid_fromstr(&from_descendant_array[i], (const char *) strdup(oidString.c_str())) != GIT_OK) {
          Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
          return env.Undefined();
        }
      }
      else {
        git_oid_cpy(&from_descendant_array[i], Napi::ObjectWrap<GitOid>::Unwrap(arrayVal.As<Napi::Object>())->GetValue());
      }
  }
// end convert_from_v8 block
          baton->descendant_array = from_descendant_array;
// start convert_from_v8 block
  size_t from_length;
      from_length = (size_t)   info[3].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->length = from_length;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ReachableFromAnyWorker *worker = new ReachableFromAnyWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitOid>("commit", info[1]);
              if (info[2].IsArray()) {
              worker->Reference<GitOid>("descendant_array", info[2].As<Napi::Array>());
            }
             worker->Reference("length", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitGraph::ReachableFromAnyWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->commit
          ,baton->descendant_array
  );

  return lockMaster;
}

void GitGraph::ReachableFromAnyWorker::Execute() {
  git_error_clear();

    int result = git_graph_reachable_from_any(
baton->repo,baton->commit,baton->descendant_array,baton->length  );

      baton->error_code = result;
      if (result < GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitGraph::ReachableFromAnyWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Graph.reachableFromAny"));
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

        free((void*)baton->descendant_array);
      if (baton->commitNeedsFree) {
        baton->commitNeedsFree = false;
        free((void *)baton->commit);
      }

  delete baton;
}

void GitGraph::ReachableFromAnyWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code >= GIT_OK) {
    Napi::Value result = Napi::Number::New(env, baton->error_code);

         
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
        err = Napi::Error::New(env, "Method reachableFromAny has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Graph.reachableFromAny"));
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
        Napi::Object err = Napi::Error::New(env, "Method reachableFromAny has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Graph.reachableFromAny"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

          free((void*)baton->descendant_array);
  }

      if (baton->commitNeedsFree) {
        baton->commitNeedsFree = false;
        free((void *)baton->commit);
      }

  delete baton;
}

     