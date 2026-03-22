// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/merge.h"
#include "bungit_wrapper.cc"

  #include "../include/repository.h"
  #include "../include/annotated_commit.h"
  #include "../include/merge_options.h"
  #include "../include/checkout_options.h"
  #include "../include/reference.h"
  #include "../include/oid.h"
  #include "../include/oidarray.h"
  #include "../include/index.h"
  #include "../include/commit.h"
  #include "../include/tree.h"
 
#include <iostream>

using namespace std;

 
  void GitMerge::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

      Napi::Function object = Napi::Function::New(env, Merge);
         object.Set("merge", Napi::Function::New(env, Merge));
         object.Set("analysis", Napi::Function::New(env, Analysis));
         object.Set("analysisForRef", Napi::Function::New(env, AnalysisForRef));
         object.Set("base", Napi::Function::New(env, Base));
         object.Set("bases", Napi::Function::New(env, Bases));
         object.Set("commits", Napi::Function::New(env, Commits));
         object.Set("trees", Napi::Function::New(env, Trees));
  
    target.Set(
      Napi::String::New(env, "Merge"),
      object
    );
  }

 
/*
 * @param Repo repo
   * @param Array their_heads
   * @param Number their_heads_len
   * @param MergeOptions merge_opts
   * @param CheckoutOptions checkout_opts
     */
Napi::Value GitMerge::Merge(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repo repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Array their_heads is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number their_heads_len is required.").ThrowAsJavaScriptException();
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

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const git_annotated_commit ** from_their_heads = NULL;

  Napi::Array tmp_their_heads = info[1].As<Napi::Array>();
  from_their_heads = (const git_annotated_commit **)malloc(tmp_their_heads.Length() * sizeof(const git_annotated_commit *));
  for (unsigned int i = 0; i < tmp_their_heads.Length(); i++) {
    const Napi::Value arrayVal = tmp_their_heads.Get(i);
      from_their_heads[i] = Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(arrayVal.As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->their_heads = from_their_heads;
// start convert_from_v8 block
  size_t from_their_heads_len;
      from_their_heads_len = (size_t)   info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->their_heads_len = from_their_heads_len;
          if (info[3].IsNull() || info[3].IsUndefined()) {
            baton->merge_opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitMergeOptions::fromJavascript(nodegitContext, info[3]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["merge_opts"] = convertedObject;
            baton->merge_opts = convertedObject->GetValue();
          }
           if (info[4].IsNull() || info[4].IsUndefined()) {
            baton->checkout_opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitCheckoutOptions::fromJavascript(nodegitContext, info[4]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["checkout_opts"] = convertedObject;
            baton->checkout_opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  MergeWorker *worker = new MergeWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
              if (info[1].IsArray()) {
              worker->Reference<GitAnnotatedCommit>("their_heads", info[1].As<Napi::Array>());
            }
             worker->Reference("their_heads_len", info[2]);
            worker->Reference("merge_opts", info[3]);
            worker->Reference("checkout_opts", info[4]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMerge::MergeWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->merge_opts
          ,baton->checkout_opts
  );

  return lockMaster;
}

void GitMerge::MergeWorker::Execute() {
  git_error_clear();

    int result = git_merge(
baton->repo,baton->their_heads,baton->their_heads_len,baton->merge_opts,baton->checkout_opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitMerge::MergeWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.merge"));
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

void GitMerge::MergeWorker::HandleOKCallback() {
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
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.merge"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.merge"));
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
   * @param Array their_heads
   * @param Number their_heads_len
    * @param Number callback
  * @param Number callback
   */
Napi::Value GitMerge::Analysis(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Array their_heads is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number their_heads_len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AnalysisBaton* baton = new AnalysisBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->analysis_out = (git_merge_analysis_t *)malloc(sizeof(git_merge_analysis_t ));
      baton->preference_out = (git_merge_preference_t *)malloc(sizeof(git_merge_preference_t ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const git_annotated_commit ** from_their_heads = NULL;

  Napi::Array tmp_their_heads = info[1].As<Napi::Array>();
  from_their_heads = (const git_annotated_commit **)malloc(tmp_their_heads.Length() * sizeof(const git_annotated_commit *));
  for (unsigned int i = 0; i < tmp_their_heads.Length(); i++) {
    const Napi::Value arrayVal = tmp_their_heads.Get(i);
      from_their_heads[i] = Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(arrayVal.As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->their_heads = from_their_heads;
// start convert_from_v8 block
  size_t from_their_heads_len;
      from_their_heads_len = (size_t)   info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->their_heads_len = from_their_heads_len;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  AnalysisWorker *worker = new AnalysisWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
              if (info[1].IsArray()) {
              worker->Reference<GitAnnotatedCommit>("their_heads", info[1].As<Napi::Array>());
            }
             worker->Reference("their_heads_len", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMerge::AnalysisWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->analysis_out
          ,baton->preference_out
          ,baton->repo
  );

  return lockMaster;
}

void GitMerge::AnalysisWorker::Execute() {
  git_error_clear();

    int result = git_merge_analysis(
baton->analysis_out,baton->preference_out,baton->repo,baton->their_heads,baton->their_heads_len  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitMerge::AnalysisWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.analysis"));
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

void GitMerge::AnalysisWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
      Napi::Object result = Napi::Object::New(env);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->analysis_out);
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "analysis_out"), v8ConversionSlot);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->preference_out);
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "preference_out"), v8ConversionSlot);
           
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
        err = Napi::Error::New(env, "Method analysis has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.analysis"));
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
        Napi::Object err = Napi::Error::New(env, "Method analysis has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.analysis"));
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
   * @param Reference our_ref
   * @param Array their_heads
   * @param Number their_heads_len
    * @param Number callback
  * @param Number callback
   */
Napi::Value GitMerge::AnalysisForRef(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Reference our_ref is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Array their_heads is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsNumber()) {
    Napi::Error::New(env, "Number their_heads_len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AnalysisForRefBaton* baton = new AnalysisForRefBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->analysis_out = (git_merge_analysis_t *)malloc(sizeof(git_merge_analysis_t ));
      baton->preference_out = (git_merge_preference_t *)malloc(sizeof(git_merge_preference_t ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  git_reference * from_our_ref = NULL;
from_our_ref = Napi::ObjectWrap<GitRefs>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->our_ref = from_our_ref;
// start convert_from_v8 block
  const git_annotated_commit ** from_their_heads = NULL;

  Napi::Array tmp_their_heads = info[2].As<Napi::Array>();
  from_their_heads = (const git_annotated_commit **)malloc(tmp_their_heads.Length() * sizeof(const git_annotated_commit *));
  for (unsigned int i = 0; i < tmp_their_heads.Length(); i++) {
    const Napi::Value arrayVal = tmp_their_heads.Get(i);
      from_their_heads[i] = Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(arrayVal.As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->their_heads = from_their_heads;
// start convert_from_v8 block
  size_t from_their_heads_len;
      from_their_heads_len = (size_t)   info[3].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->their_heads_len = from_their_heads_len;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  AnalysisForRefWorker *worker = new AnalysisForRefWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitRefs>("our_ref", info[1]);
              if (info[2].IsArray()) {
              worker->Reference<GitAnnotatedCommit>("their_heads", info[2].As<Napi::Array>());
            }
             worker->Reference("their_heads_len", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMerge::AnalysisForRefWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->analysis_out
          ,baton->preference_out
          ,baton->repo
          ,baton->our_ref
  );

  return lockMaster;
}

void GitMerge::AnalysisForRefWorker::Execute() {
  git_error_clear();

    int result = git_merge_analysis_for_ref(
baton->analysis_out,baton->preference_out,baton->repo,baton->our_ref,baton->their_heads,baton->their_heads_len  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitMerge::AnalysisForRefWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.analysisForRef"));
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

void GitMerge::AnalysisForRefWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
      Napi::Object result = Napi::Object::New(env);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->analysis_out);
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "analysis_out"), v8ConversionSlot);
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env, * baton->preference_out);
  // end convert_to_v8 block
        result.Set(Napi::String::New(env, "preference_out"), v8ConversionSlot);
             
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
        err = Napi::Error::New(env, "Method analysisForRef has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.analysisForRef"));
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
        Napi::Object err = Napi::Error::New(env, "Method analysisForRef has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.analysisForRef"));
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
   * @param Oid one
   * @param Oid two
    * @param Oid callback
   */
Napi::Value GitMerge::Base(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid one is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 2
    || (!info[2].IsObject() && !info[2].IsString())) {
    Napi::Error::New(env, "Oid two is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  BaseBaton* baton = new BaseBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_oid *)malloc(sizeof(git_oid ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const git_oid * from_one = NULL;
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

    from_one = oidOut;
  }
  else {
from_one = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->one = from_one;
            baton->oneNeedsFree = info[1].IsString();
// start convert_from_v8 block
  const git_oid * from_two = NULL;
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

    from_two = oidOut;
  }
  else {
from_two = Napi::ObjectWrap<GitOid>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->two = from_two;
            baton->twoNeedsFree = info[2].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  BaseWorker *worker = new BaseWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitOid>("one", info[1]);
               worker->Reference<GitOid>("two", info[2]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMerge::BaseWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->repo
          ,baton->one
          ,baton->two
  );

  return lockMaster;
}

void GitMerge::BaseWorker::Execute() {
  git_error_clear();

    int result = git_merge_base(
baton->out,baton->repo,baton->one,baton->two  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitMerge::BaseWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.base"));
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

      if (baton->oneNeedsFree) {
        baton->oneNeedsFree = false;
        free((void *)baton->one);
      }
      if (baton->twoNeedsFree) {
        baton->twoNeedsFree = false;
        free((void *)baton->two);
      }

  delete baton;
}

void GitMerge::BaseWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method base has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.base"));
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
        Napi::Object err = Napi::Error::New(env, "Method base has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.base"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->oneNeedsFree) {
        baton->oneNeedsFree = false;
        free((void *)baton->one);
      }
      if (baton->twoNeedsFree) {
        baton->twoNeedsFree = false;
        free((void *)baton->two);
      }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Oid one
   * @param Oid two
    * @param Oidarray callback
   */
Napi::Value GitMerge::Bases(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid one is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 2
    || (!info[2].IsObject() && !info[2].IsString())) {
    Napi::Error::New(env, "Oid two is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  BasesBaton* baton = new BasesBaton();

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
  const git_oid * from_one = NULL;
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

    from_one = oidOut;
  }
  else {
from_one = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->one = from_one;
            baton->oneNeedsFree = info[1].IsString();
// start convert_from_v8 block
  const git_oid * from_two = NULL;
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

    from_two = oidOut;
  }
  else {
from_two = Napi::ObjectWrap<GitOid>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->two = from_two;
            baton->twoNeedsFree = info[2].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  BasesWorker *worker = new BasesWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitOid>("one", info[1]);
               worker->Reference<GitOid>("two", info[2]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMerge::BasesWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->repo
          ,baton->one
          ,baton->two
  );

  return lockMaster;
}

void GitMerge::BasesWorker::Execute() {
  git_error_clear();

    int result = git_merge_bases(
baton->out,baton->repo,baton->one,baton->two  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitMerge::BasesWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.bases"));
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

      git_oidarray_free(baton->out);
      if (baton->oneNeedsFree) {
        baton->oneNeedsFree = false;
        free((void *)baton->one);
      }
      if (baton->twoNeedsFree) {
        baton->twoNeedsFree = false;
        free((void *)baton->two);
      }

  delete baton;
}

void GitMerge::BasesWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitOidarray::New(
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
        err = Napi::Error::New(env, "Method bases has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.bases"));
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
        Napi::Object err = Napi::Error::New(env, "Method bases has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.bases"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_oidarray_free(baton->out);
  }

      if (baton->oneNeedsFree) {
        baton->oneNeedsFree = false;
        free((void *)baton->one);
      }
      if (baton->twoNeedsFree) {
        baton->twoNeedsFree = false;
        free((void *)baton->two);
      }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Commit our_commit
   * @param Commit their_commit
   * @param MergeOptions opts
    * @param Index callback
   */
Napi::Value GitMerge::Commits(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Commit our_commit is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Commit their_commit is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CommitsBaton* baton = new CommitsBaton();

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
  const git_commit * from_our_commit = NULL;
from_our_commit = Napi::ObjectWrap<GitCommit>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->our_commit = from_our_commit;
// start convert_from_v8 block
  const git_commit * from_their_commit = NULL;
from_their_commit = Napi::ObjectWrap<GitCommit>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->their_commit = from_their_commit;
          if (info[3].IsNull() || info[3].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitMergeOptions::fromJavascript(nodegitContext, info[3]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CommitsWorker *worker = new CommitsWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitCommit>("our_commit", info[1]);
               worker->Reference<GitCommit>("their_commit", info[2]);
             worker->Reference("opts", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMerge::CommitsWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->our_commit
          ,baton->their_commit
          ,baton->opts
  );

  return lockMaster;
}

void GitMerge::CommitsWorker::Execute() {
  git_error_clear();

    int result = git_merge_commits(
&baton->out,baton->repo,baton->our_commit,baton->their_commit,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitMerge::CommitsWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.commits"));
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

      git_index_free(baton->out);

  delete baton;
}

void GitMerge::CommitsWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
          owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_index_owner(baton->out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitIndex::New(
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
        err = Napi::Error::New(env, "Method commits has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.commits"));
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
        Napi::Object err = Napi::Error::New(env, "Method commits has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.commits"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_index_free(baton->out);
  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Tree ancestor_tree
   * @param Tree our_tree
   * @param Tree their_tree
   * @param MergeOptions opts
    * @param Index callback
   */
Napi::Value GitMerge::Trees(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Tree our_tree is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsObject()) {
    Napi::Error::New(env, "Tree their_tree is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  TreesBaton* baton = new TreesBaton();

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
  const git_tree * from_ancestor_tree = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsObject()) {
from_ancestor_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
  else {
    from_ancestor_tree = 0;
  }
// end convert_from_v8 block
          baton->ancestor_tree = from_ancestor_tree;
// start convert_from_v8 block
  const git_tree * from_our_tree = NULL;
from_our_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->our_tree = from_our_tree;
// start convert_from_v8 block
  const git_tree * from_their_tree = NULL;
from_their_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[3].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->their_tree = from_their_tree;
          if (info[4].IsNull() || info[4].IsUndefined()) {
            baton->opts = nullptr;
          } else
            {
            auto conversionResult = ConfigurableGitMergeOptions::fromJavascript(nodegitContext, info[4]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  TreesWorker *worker = new TreesWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitTree>("ancestor_tree", info[1]);
               worker->Reference<GitTree>("our_tree", info[2]);
               worker->Reference<GitTree>("their_tree", info[3]);
             worker->Reference("opts", info[4]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMerge::TreesWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->ancestor_tree
          ,baton->our_tree
          ,baton->their_tree
          ,baton->opts
  );

  return lockMaster;
}

void GitMerge::TreesWorker::Execute() {
  git_error_clear();

    int result = git_merge_trees(
&baton->out,baton->repo,baton->ancestor_tree,baton->our_tree,baton->their_tree,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitMerge::TreesWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.trees"));
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

      git_index_free(baton->out);

  delete baton;
}

void GitMerge::TreesWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
          owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_index_owner(baton->out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitIndex::New(
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
        err = Napi::Error::New(env, "Method trees has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.trees"));
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
        Napi::Object err = Napi::Error::New(env, "Method trees has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Merge.trees"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_index_free(baton->out);
  }


  delete baton;
}

     