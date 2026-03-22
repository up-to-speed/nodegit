// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/repository.h"
#include "bungit_wrapper.cc"

  #include "git2/sys/repository.h"
  #include "../include/commit.h"
  #include "../include/submodule.h"
  #include "../include/remote.h"
  #include "../include/commitarray.h"
  #include "../include/config.h"
  #include "../include/buf.h"
  #include "../include/oid.h"
  #include "../include/reference.h"
  #include "../include/index.h"
  #include "../include/repository_init_options.h"
  #include "../include/odb.h"
  #include "../include/worktree.h"
  #include "../include/refdb.h"
  #include "../include/annotated_commit.h"
 
#include <iostream>

using namespace std;

  GitRepository::~GitRepository() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                                                                                                             }

  void GitRepository::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Repository", {
          InstanceMethod("commitParents", &GitRepository::CommitParents, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("commondir", &GitRepository::Commondir, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("config", &GitRepository::Config, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("detachHead", &GitRepository::DetachHead, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("discover", &GitRepository::Discover, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("fetchheadForeach", &GitRepository::FetchheadForeach, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getNamespace", &GitRepository::GetNamespace, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("hashfile", &GitRepository::Hashfile, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("head", &GitRepository::Head, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("headDetached", &GitRepository::HeadDetached, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("headDetachedForWorktree", &GitRepository::HeadDetachedForWorktree, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("headForWorktree", &GitRepository::HeadForWorktree, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("headUnborn", &GitRepository::HeadUnborn, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("ident", &GitRepository::Ident, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("index", &GitRepository::Index, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("init", &GitRepository::Init, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("initExt", &GitRepository::InitExt, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("isBare", &GitRepository::IsBare, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("isEmpty", &GitRepository::IsEmpty, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("isShallow", &GitRepository::IsShallow, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("isWorktree", &GitRepository::IsWorktree, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("itemPath", &GitRepository::ItemPath, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("mergeheadForeach", &GitRepository::MergeheadForeach, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("messageRemove", &GitRepository::MessageRemove, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("odb", &GitRepository::Odb, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("oidType", &GitRepository::OidType, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("open", &GitRepository::Open, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("openBare", &GitRepository::OpenBare, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("openExt", &GitRepository::OpenExt, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("openFromWorktree", &GitRepository::OpenFromWorktree, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("path", &GitRepository::Path, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("refdb", &GitRepository::Refdb, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setHead", &GitRepository::SetHead, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setHeadDetached", &GitRepository::SetHeadDetached, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setHeadDetachedFromAnnotated", &GitRepository::SetHeadDetachedFromAnnotated, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setIdent", &GitRepository::SetIdent, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setNamespace", &GitRepository::SetNamespace, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setWorkdir", &GitRepository::SetWorkdir, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("state", &GitRepository::State, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("stateCleanup", &GitRepository::StateCleanup, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("workdir", &GitRepository::Workdir, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("wrapOdb", &GitRepository::WrapOdb, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("cleanup", &GitRepository::Cleanup, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getReferences", &GitRepository::GetReferences, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getSubmodules", &GitRepository::GetSubmodules, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("getRemotes", &GitRepository::GetRemotes, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("refreshReferences", &GitRepository::RefreshReferences, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("setIndex", &GitRepository::SetIndex, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("statistics", &GitRepository::Statistics, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("submoduleCacheAll", &GitRepository::SubmoduleCacheAll, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("submoduleCacheClear", &GitRepository::SubmoduleCacheClear, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitRepository::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitRepository::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitRepository::Template", constructor_template);
    target.Set(Napi::String::New(env, "Repository"), constructor_template);
  }

 
/*
     * @param Array callback
   */
Napi::Value GitRepository::CommitParents(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CommitParentsBaton* baton = new CommitParentsBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->commits = (git_commitarray *)malloc(sizeof(git_commitarray ));
        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CommitParentsWorker *worker = new CommitParentsWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::CommitParentsWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->commits
          ,baton->repo
  );

  return lockMaster;
}

void GitRepository::CommitParentsWorker::Execute() {
  git_error_clear();

    int result = git_repository_commit_parents(
baton->commits,baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::CommitParentsWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.commitParents"));
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

        free((void*)baton->commits);

  delete baton;
}

void GitRepository::CommitParentsWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    Napi::Array tmpArray = Napi::Array::New(env, baton->commits->count);
    for (unsigned int i = 0; i < baton->commits->count; i++) {
      Napi::Value element;
        element = GitCommit::New(
          env,
          baton->commits->commits[i],
          true
         );
       tmpArray.Set(Napi::Number::New(env, i), element);
    }
 
  v8ConversionSlot = tmpArray;
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
        err = Napi::Error::New(env, "Method commitParents has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.commitParents"));
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
        Napi::Object err = Napi::Error::New(env, "Method commitParents has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.commitParents"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

          free((void*)baton->commits);
  }


  delete baton;
}

   
/*
     * @return String  result    */
Napi::Value GitRepository::Commondir(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_repository_commondir(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
  if (result){
       v8ConversionSlot = Napi::String::New(env, result);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
     * @param Config callback
   */
Napi::Value GitRepository::Config(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ConfigBaton* baton = new ConfigBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ConfigWorker *worker = new ConfigWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::ConfigWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
  );

  return lockMaster;
}

void GitRepository::ConfigWorker::Execute() {
  git_error_clear();

    int result = git_repository_config(
&baton->out,baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::ConfigWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.config"));
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

      git_config_free(baton->out);

  delete baton;
}

void GitRepository::ConfigWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitConfig::New(
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
        err = Napi::Error::New(env, "Method config has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.config"));
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
        Napi::Object err = Napi::Error::New(env, "Method config has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.config"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_config_free(baton->out);
  }


  delete baton;
}

   
/*
     * @return Number  result    */
Napi::Value GitRepository::DetachHead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_detach_head(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
  * @param String start_path
   * @param Number across_fs
   * @param String ceiling_dirs
    * @param Buf callback
   */
Napi::Value GitRepository::Discover(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String start_path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number across_fs is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  DiscoverBaton* baton = new DiscoverBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->reserved = 0;
// start convert_from_v8 block
  const char * from_start_path = NULL;

  std::string start_path = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_start_path = (const char *) malloc(start_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_start_path, start_path.c_str(), start_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_start_path) + start_path.length()), 0, 1);
// end convert_from_v8 block
          baton->start_path = from_start_path;
// start convert_from_v8 block
  int from_across_fs;
      from_across_fs = (int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->across_fs = from_across_fs;
// start convert_from_v8 block
  const char * from_ceiling_dirs = NULL;
    if ((info.Length() - 1) > 2 && info[2].IsString()) {

  std::string ceiling_dirs = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_ceiling_dirs = (const char *) malloc(ceiling_dirs.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_ceiling_dirs, ceiling_dirs.c_str(), ceiling_dirs.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_ceiling_dirs) + ceiling_dirs.length()), 0, 1);
  }
  else {
    from_ceiling_dirs = 0;
  }
// end convert_from_v8 block
          baton->ceiling_dirs = from_ceiling_dirs;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  DiscoverWorker *worker = new DiscoverWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("start_path", info[0]);
            worker->Reference("across_fs", info[1]);
            worker->Reference("ceiling_dirs", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::DiscoverWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->start_path
          ,baton->ceiling_dirs
  );

  return lockMaster;
}

void GitRepository::DiscoverWorker::Execute() {
  git_error_clear();

    int result = git_repository_discover(
baton->out,baton->start_path,baton->across_fs,baton->ceiling_dirs  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::DiscoverWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.discover"));
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

void GitRepository::DiscoverWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method discover has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.discover"));
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
        Napi::Object err = Napi::Error::New(env, "Method discover has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.discover"));
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
   * @param RepositoryFetchheadForeachCb callback
   * @param Void payload
     */
Napi::Value GitRepository::FetchheadForeach(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsFunction()) {
    Napi::Error::New(env, "RepositoryFetchheadForeachCb callback is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  FetchheadForeachBaton* baton = new FetchheadForeachBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

      FetchheadForeach_globalPayload* globalPayload = new FetchheadForeach_globalPayload;

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();
        if (!info[0].IsFunction()) {
          baton->callback = NULL;
          globalPayload->callback = NULL;
        }
        else {
          baton->callback = FetchheadForeach_callback_cppCallback;
            globalPayload->callback = new Napi::FunctionReference();
            *(globalPayload->callback) = Napi::Persistent(info[0].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  FetchheadForeachWorker *worker = new FetchheadForeachWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
           worker->Reference("payload", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::FetchheadForeachWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->payload
  );

  return lockMaster;
}

void GitRepository::FetchheadForeachWorker::Execute() {
  git_error_clear();

    int result = git_repository_fetchhead_foreach(
baton->repo,baton->callback,baton->payload  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::FetchheadForeachWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.fetchheadForeach"));
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

      delete (FetchheadForeach_globalPayload*)baton->payload;

  delete baton;
}

void GitRepository::FetchheadForeachWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method fetchheadForeach has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.fetchheadForeach"));
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
        Napi::Object err = Napi::Error::New(env, "Method fetchheadForeach has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.fetchheadForeach"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      delete (FetchheadForeach_globalPayload*)baton->payload;

  delete baton;
}


int GitRepository::FetchheadForeach_callback_cppCallback (
    const char * refname,     const char * remote_url,     const git_oid * oid,     unsigned int is_merge,     void * payload  ) {
  FetchheadForeach_CallbackBaton baton(0);

    baton.refname = refname;
    baton.remote_url = remote_url;
    baton.oid = oid;
    baton.is_merge = is_merge;
    baton.payload = payload;
 
  return baton.ExecuteAsync(FetchheadForeach_callback_async, FetchheadForeach_callback_cancelAsync);
}

void GitRepository::FetchheadForeach_callback_cancelAsync(void *untypedBaton) {
  FetchheadForeach_CallbackBaton* baton = static_cast<FetchheadForeach_CallbackBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitRepository::FetchheadForeach_callback_async(void *untypedBaton) {
  FetchheadForeach_CallbackBaton* baton = static_cast<FetchheadForeach_CallbackBaton*>(untypedBaton);

      Napi::FunctionReference* callback = ((FetchheadForeach_globalPayload*)baton->payload)->callback;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[4] = {
         Napi::String::New(env, baton->refname)
 ,          Napi::String::New(env, baton->remote_url)
 ,          GitOid::New(env, baton->oid, false)
 ,           Napi::Number::New(env, baton->is_merge)
    };

  Napi::Value result;
  bool callSucceeded = false;
  try {
    napi_value napi_argv[4];
    for (int _i = 0; _i < 4; _i++) {
      napi_argv[_i] = argv[_i];
    }
    result = callback->Call(env.Undefined(), 4, napi_argv);
    callSucceeded = !result.IsEmpty();
  } catch (const Napi::Error& e) {
    // exception occurred — result is invalid, don't forward
  }

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, FetchheadForeach_callback_promiseCompleted)) {
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

void GitRepository::FetchheadForeach_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  FetchheadForeach_CallbackBaton* baton = static_cast<FetchheadForeach_CallbackBaton*>(_baton);

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
    GitRepository* instance = static_cast<GitRepository*>(baton->    payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitRepository>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
   
/*
     * @return String  result    */
Napi::Value GitRepository::GetNamespace(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_repository_get_namespace(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
  if (result){
       v8ConversionSlot = Napi::String::New(env, result);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
    * @param String path
   * @param Number type
   * @param String as_path
    * @param Oid callback
   */
Napi::Value GitRepository::Hashfile(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number type is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  HashfileBaton* baton = new HashfileBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_oid *)malloc(sizeof(git_oid ));
        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
// start convert_from_v8 block
  git_object_t from_type;
      from_type = (git_object_t)  (int) info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->type = from_type;
// start convert_from_v8 block
  const char * from_as_path = NULL;
    if ((info.Length() - 1) > 2 && info[2].IsString()) {

  std::string as_path = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_as_path = (const char *) malloc(as_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_as_path, as_path.c_str(), as_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_as_path) + as_path.length()), 0, 1);
  }
  else {
    from_as_path = 0;
  }
// end convert_from_v8 block
          baton->as_path = from_as_path;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  HashfileWorker *worker = new HashfileWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
           worker->Reference("path", info[0]);
            worker->Reference("type", info[1]);
            worker->Reference("as_path", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::HashfileWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->repo
          ,baton->path
          ,baton->as_path
  );

  return lockMaster;
}

void GitRepository::HashfileWorker::Execute() {
  git_error_clear();

    int result = git_repository_hashfile(
baton->out,baton->repo,baton->path,baton->type,baton->as_path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::HashfileWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.hashfile"));
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

void GitRepository::HashfileWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method hashfile has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.hashfile"));
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
        Napi::Object err = Napi::Error::New(env, "Method hashfile has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.hashfile"));
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
     * @param Reference callback
   */
Napi::Value GitRepository::Head(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  HeadBaton* baton = new HeadBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  HeadWorker *worker = new HeadWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::HeadWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
  );

  return lockMaster;
}

void GitRepository::HeadWorker::Execute() {
  git_error_clear();

    int result = git_repository_head(
&baton->out,baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::HeadWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.head"));
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

      git_reference_free(baton->out);

  delete baton;
}

void GitRepository::HeadWorker::HandleOKCallback() {
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
            git_reference_owner(baton->out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitRefs::New(
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
        err = Napi::Error::New(env, "Method head has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.head"));
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
        Napi::Object err = Napi::Error::New(env, "Method head has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.head"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_reference_free(baton->out);
  }


  delete baton;
}

   
/*
     * @return Number  result    */
Napi::Value GitRepository::HeadDetached(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_head_detached(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String name
     * @return Number  result    */
Napi::Value GitRepository::HeadDetachedForWorktree(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_name = NULL;

  std::string name = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, name.c_str(), name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_name
    );

 int result =     git_repository_head_detached_for_worktree(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_name
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
    * @param String name
    * @param Reference callback
   */
Napi::Value GitRepository::HeadForWorktree(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  HeadForWorktreeBaton* baton = new HeadForWorktreeBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_name = NULL;

  std::string name = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, name.c_str(), name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
          baton->name = from_name;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  HeadForWorktreeWorker *worker = new HeadForWorktreeWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
           worker->Reference("name", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::HeadForWorktreeWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->name
  );

  return lockMaster;
}

void GitRepository::HeadForWorktreeWorker::Execute() {
  git_error_clear();

    int result = git_repository_head_for_worktree(
&baton->out,baton->repo,baton->name  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::HeadForWorktreeWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.headForWorktree"));
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

      git_reference_free(baton->out);

  delete baton;
}

void GitRepository::HeadForWorktreeWorker::HandleOKCallback() {
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
            git_reference_owner(baton->out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitRefs::New(
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
        err = Napi::Error::New(env, "Method headForWorktree has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.headForWorktree"));
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
        Napi::Object err = Napi::Error::New(env, "Method headForWorktree has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.headForWorktree"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_reference_free(baton->out);
  }


  delete baton;
}

   
/*
     * @return Number  result    */
Napi::Value GitRepository::HeadUnborn(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_head_unborn(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
       * @return String name    * @return String email    */
Napi::Value GitRepository::Ident(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

      const char * name = 0;
      const char * email = 0;

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_ident(
&          name
,&          email
,          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
        Napi::Object toReturn = Napi::Object::New(env);
// start convert_to_v8 block
  if (name){
       v8ConversionSlot = Napi::String::New(env, name);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "name"), v8ConversionSlot);
// start convert_to_v8 block
  if (email){
       v8ConversionSlot = Napi::String::New(env, email);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "email"), v8ConversionSlot);
        return scope.Escape(toReturn);
  }
}
  
/*
     * @param Index callback
   */
Napi::Value GitRepository::Index(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  IndexBaton* baton = new IndexBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  IndexWorker *worker = new IndexWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::IndexWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
  );

  return lockMaster;
}

void GitRepository::IndexWorker::Execute() {
  git_error_clear();

    int result = git_repository_index(
&baton->out,baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::IndexWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.index"));
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

void GitRepository::IndexWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method index has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.index"));
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
        Napi::Object err = Napi::Error::New(env, "Method index has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.index"));
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
  * @param String path
   * @param Number is_bare
    * @param Repository callback
   */
Napi::Value GitRepository::Init(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number is_bare is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  InitBaton* baton = new InitBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
// start convert_from_v8 block
  unsigned int from_is_bare;
      from_is_bare = (unsigned int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->is_bare = from_is_bare;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  InitWorker *worker = new InitWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("path", info[0]);
            worker->Reference("is_bare", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::InitWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->path
  );

  return lockMaster;
}

void GitRepository::InitWorker::Execute() {
  git_error_clear();

    int result = git_repository_init(
&baton->out,baton->path,baton->is_bare  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::InitWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.init"));
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

      git_repository_free(baton->out);

  delete baton;
}

void GitRepository::InitWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitRepository::New(
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
        err = Napi::Error::New(env, "Method init has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.init"));
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
        Napi::Object err = Napi::Error::New(env, "Method init has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.init"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_repository_free(baton->out);
  }


  delete baton;
}

  
/*
  * @param String repo_path
   * @param RepositoryInitOptions opts
    * @param Repository callback
   */
Napi::Value GitRepository::InitExt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String repo_path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "RepositoryInitOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  InitExtBaton* baton = new InitExtBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const char * from_repo_path = NULL;

  std::string repo_path = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_repo_path = (const char *) malloc(repo_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_repo_path, repo_path.c_str(), repo_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_repo_path) + repo_path.length()), 0, 1);
// end convert_from_v8 block
          baton->repo_path = from_repo_path;
            {
            auto conversionResult = ConfigurableGitRepositoryInitOptions::fromJavascript(nodegitContext, info[1]);
            if (!conversionResult.result) {
              Napi::Error::New(env, conversionResult.error).ThrowAsJavaScriptException();
              return env.Undefined();
            }

            auto convertedObject = conversionResult.result;
            cleanupHandles["opts"] = convertedObject;
            baton->opts = convertedObject->GetValue();
          }
 
  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  InitExtWorker *worker = new InitExtWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("repo_path", info[0]);
            worker->Reference("opts", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::InitExtWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo_path
          ,baton->opts
  );

  return lockMaster;
}

void GitRepository::InitExtWorker::Execute() {
  git_error_clear();

    int result = git_repository_init_ext(
&baton->out,baton->repo_path,baton->opts  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::InitExtWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.initExt"));
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

      git_repository_free(baton->out);

  delete baton;
}

void GitRepository::InitExtWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitRepository::New(
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
        err = Napi::Error::New(env, "Method initExt has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.initExt"));
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
        Napi::Object err = Napi::Error::New(env, "Method initExt has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.initExt"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_repository_free(baton->out);
  }


  delete baton;
}

   
/*
     * @return Number  result    */
Napi::Value GitRepository::IsBare(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_is_bare(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitRepository::IsEmpty(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_is_empty(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitRepository::IsShallow(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_is_shallow(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitRepository::IsWorktree(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_is_worktree(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
    * @param Number item
    * @param Buf callback
   */
Napi::Value GitRepository::ItemPath(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number item is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ItemPathBaton* baton = new ItemPathBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  git_repository_item_t from_item;
      from_item = (git_repository_item_t)  (int) info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->item = from_item;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ItemPathWorker *worker = new ItemPathWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
           worker->Reference("item", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::ItemPathWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->repo
  );

  return lockMaster;
}

void GitRepository::ItemPathWorker::Execute() {
  git_error_clear();

    int result = git_repository_item_path(
baton->out,baton->repo,baton->item  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::ItemPathWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.itemPath"));
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

void GitRepository::ItemPathWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method itemPath has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.itemPath"));
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
        Napi::Object err = Napi::Error::New(env, "Method itemPath has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.itemPath"));
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
   * @param RepositoryMergeheadForeachCb callback
   * @param Void payload
     */
Napi::Value GitRepository::MergeheadForeach(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsFunction()) {
    Napi::Error::New(env, "RepositoryMergeheadForeachCb callback is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  MergeheadForeachBaton* baton = new MergeheadForeachBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

      MergeheadForeach_globalPayload* globalPayload = new MergeheadForeach_globalPayload;

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();
        if (!info[0].IsFunction()) {
          baton->callback = NULL;
          globalPayload->callback = NULL;
        }
        else {
          baton->callback = MergeheadForeach_callback_cppCallback;
            globalPayload->callback = new Napi::FunctionReference();
            *(globalPayload->callback) = Napi::Persistent(info[0].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  MergeheadForeachWorker *worker = new MergeheadForeachWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
           worker->Reference("payload", info[1]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::MergeheadForeachWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->payload
  );

  return lockMaster;
}

void GitRepository::MergeheadForeachWorker::Execute() {
  git_error_clear();

    int result = git_repository_mergehead_foreach(
baton->repo,baton->callback,baton->payload  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::MergeheadForeachWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.mergeheadForeach"));
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

      delete (MergeheadForeach_globalPayload*)baton->payload;

  delete baton;
}

void GitRepository::MergeheadForeachWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method mergeheadForeach has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.mergeheadForeach"));
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
        Napi::Object err = Napi::Error::New(env, "Method mergeheadForeach has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.mergeheadForeach"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      delete (MergeheadForeach_globalPayload*)baton->payload;

  delete baton;
}


int GitRepository::MergeheadForeach_callback_cppCallback (
    const git_oid * oid,     void * payload  ) {
  MergeheadForeach_CallbackBaton baton(0);

    baton.oid = oid;
    baton.payload = payload;
 
  return baton.ExecuteAsync(MergeheadForeach_callback_async, MergeheadForeach_callback_cancelAsync);
}

void GitRepository::MergeheadForeach_callback_cancelAsync(void *untypedBaton) {
  MergeheadForeach_CallbackBaton* baton = static_cast<MergeheadForeach_CallbackBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitRepository::MergeheadForeach_callback_async(void *untypedBaton) {
  MergeheadForeach_CallbackBaton* baton = static_cast<MergeheadForeach_CallbackBaton*>(untypedBaton);

   Napi::FunctionReference* callback = ((MergeheadForeach_globalPayload*)baton->payload)->callback;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[1] = {
         GitOid::New(env, baton->oid, false)
    };

  Napi::Value result;
  bool callSucceeded = false;
  try {
    napi_value napi_argv[1];
    for (int _i = 0; _i < 1; _i++) {
      napi_argv[_i] = argv[_i];
    }
    result = callback->Call(env.Undefined(), 1, napi_argv);
    callSucceeded = !result.IsEmpty();
  } catch (const Napi::Error& e) {
    // exception occurred — result is invalid, don't forward
  }

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, MergeheadForeach_callback_promiseCompleted)) {
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

void GitRepository::MergeheadForeach_callback_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  MergeheadForeach_CallbackBaton* baton = static_cast<MergeheadForeach_CallbackBaton*>(_baton);

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
    GitRepository* instance = static_cast<GitRepository*>(baton-> payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitRepository>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
   
/*
     * @return Number  result    */
Napi::Value GitRepository::MessageRemove(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_message_remove(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
     * @param Odb callback
   */
Napi::Value GitRepository::Odb(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  OdbBaton* baton = new OdbBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  OdbWorker *worker = new OdbWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::OdbWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
  );

  return lockMaster;
}

void GitRepository::OdbWorker::Execute() {
  git_error_clear();

    int result = git_repository_odb(
&baton->out,baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::OdbWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.odb"));
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

      git_odb_free(baton->out);

  delete baton;
}

void GitRepository::OdbWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitOdb::New(
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
        err = Napi::Error::New(env, "Method odb has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.odb"));
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
        Napi::Object err = Napi::Error::New(env, "Method odb has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.odb"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_odb_free(baton->out);
  }


  delete baton;
}

   
/*
     * @return Number  result    */
Napi::Value GitRepository::OidType(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 git_oid_t result =     git_repository_oid_type(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
  * @param String path
    * @param Repository callback
   */
Napi::Value GitRepository::Open(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  OpenBaton* baton = new OpenBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
  OpenWorker *worker = new OpenWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("path", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::OpenWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->path
  );

  return lockMaster;
}

void GitRepository::OpenWorker::Execute() {
  git_error_clear();

    int result = git_repository_open(
&baton->out,baton->path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::OpenWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.open"));
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

      git_repository_free(baton->out);

  delete baton;
}

void GitRepository::OpenWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitRepository::New(
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
        err = Napi::Error::New(env, "Method open has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.open"));
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
        Napi::Object err = Napi::Error::New(env, "Method open has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.open"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_repository_free(baton->out);
  }


  delete baton;
}

  
/*
  * @param String bare_path
    * @param Repository callback
   */
Napi::Value GitRepository::OpenBare(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String bare_path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  OpenBareBaton* baton = new OpenBareBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const char * from_bare_path = NULL;

  std::string bare_path = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_bare_path = (const char *) malloc(bare_path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_bare_path, bare_path.c_str(), bare_path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_bare_path) + bare_path.length()), 0, 1);
// end convert_from_v8 block
          baton->bare_path = from_bare_path;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  OpenBareWorker *worker = new OpenBareWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("bare_path", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::OpenBareWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->bare_path
  );

  return lockMaster;
}

void GitRepository::OpenBareWorker::Execute() {
  git_error_clear();

    int result = git_repository_open_bare(
&baton->out,baton->bare_path  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::OpenBareWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.openBare"));
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

      git_repository_free(baton->out);

  delete baton;
}

void GitRepository::OpenBareWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitRepository::New(
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
        err = Napi::Error::New(env, "Method openBare has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.openBare"));
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
        Napi::Object err = Napi::Error::New(env, "Method openBare has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.openBare"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_repository_free(baton->out);
  }


  delete baton;
}

  
/*
  * @param String path
   * @param Number flags
   * @param String ceiling_dirs
    * @param Repository callback
   */
Napi::Value GitRepository::OpenExt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number flags is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String ceiling_dirs is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  OpenExtBaton* baton = new OpenExtBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
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
// start convert_from_v8 block
  unsigned int from_flags;
      from_flags = (unsigned int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->flags = from_flags;
// start convert_from_v8 block
  const char * from_ceiling_dirs = NULL;

  std::string ceiling_dirs = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_ceiling_dirs = (const char *) malloc(ceiling_dirs.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_ceiling_dirs, ceiling_dirs.c_str(), ceiling_dirs.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_ceiling_dirs) + ceiling_dirs.length()), 0, 1);
// end convert_from_v8 block
          baton->ceiling_dirs = from_ceiling_dirs;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  OpenExtWorker *worker = new OpenExtWorker(baton, std::move(callback), cleanupHandles);

           worker->Reference("path", info[0]);
            worker->Reference("flags", info[1]);
            worker->Reference("ceiling_dirs", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::OpenExtWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->path
          ,baton->ceiling_dirs
  );

  return lockMaster;
}

void GitRepository::OpenExtWorker::Execute() {
  git_error_clear();

    int result = git_repository_open_ext(
&baton->out,baton->path,baton->flags,baton->ceiling_dirs  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::OpenExtWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.openExt"));
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

      git_repository_free(baton->out);

  delete baton;
}

void GitRepository::OpenExtWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitRepository::New(
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
        err = Napi::Error::New(env, "Method openExt has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.openExt"));
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
        Napi::Object err = Napi::Error::New(env, "Method openExt has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.openExt"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_repository_free(baton->out);
  }


  delete baton;
}

  
/*
  * @param Worktree wt
    * @param Repository callback
   */
Napi::Value GitRepository::OpenFromWorktree(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Worktree wt is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  OpenFromWorktreeBaton* baton = new OpenFromWorktreeBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_worktree * from_wt = NULL;
from_wt = Napi::ObjectWrap<GitWorktree>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->wt = from_wt;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  OpenFromWorktreeWorker *worker = new OpenFromWorktreeWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitWorktree>("wt", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::OpenFromWorktreeWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->wt
  );

  return lockMaster;
}

void GitRepository::OpenFromWorktreeWorker::Execute() {
  git_error_clear();

    int result = git_repository_open_from_worktree(
&baton->out,baton->wt  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::OpenFromWorktreeWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.openFromWorktree"));
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

      git_repository_free(baton->out);

  delete baton;
}

void GitRepository::OpenFromWorktreeWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitRepository::New(
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
        err = Napi::Error::New(env, "Method openFromWorktree has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.openFromWorktree"));
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
        Napi::Object err = Napi::Error::New(env, "Method openFromWorktree has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.openFromWorktree"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_repository_free(baton->out);
  }


  delete baton;
}

   
/*
     * @return String  result    */
Napi::Value GitRepository::Path(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_repository_path(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
  if (result){
       v8ConversionSlot = Napi::String::New(env, result);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
     * @param Refdb callback
   */
Napi::Value GitRepository::Refdb(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  RefdbBaton* baton = new RefdbBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  RefdbWorker *worker = new RefdbWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::RefdbWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
  );

  return lockMaster;
}

void GitRepository::RefdbWorker::Execute() {
  git_error_clear();

    int result = git_repository_refdb(
&baton->out,baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::RefdbWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.refdb"));
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

      git_refdb_free(baton->out);

  delete baton;
}

void GitRepository::RefdbWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("repo").As<Napi::Object>());
             v8ConversionSlot = GitRefdb::New(
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
        err = Napi::Error::New(env, "Method refdb has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.refdb"));
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
        Napi::Object err = Napi::Error::New(env, "Method refdb has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.refdb"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_refdb_free(baton->out);
  }


  delete baton;
}

  
/*
   * @param String refname
     */
Napi::Value GitRepository::SetHead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String refname is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  SetHeadBaton* baton = new SetHeadBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_refname = NULL;

  std::string refname = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_refname = (const char *) malloc(refname.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_refname, refname.c_str(), refname.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_refname) + refname.length()), 0, 1);
// end convert_from_v8 block
          baton->refname = from_refname;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  SetHeadWorker *worker = new SetHeadWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
           worker->Reference("refname", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::SetHeadWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->refname
  );

  return lockMaster;
}

void GitRepository::SetHeadWorker::Execute() {
  git_error_clear();

    int result = git_repository_set_head(
baton->repo,baton->refname  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::SetHeadWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.setHead"));
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

void GitRepository::SetHeadWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method setHead has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.setHead"));
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
        Napi::Object err = Napi::Error::New(env, "Method setHead has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.setHead"));
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
   * @param Oid committish
     * @return Number  result    */
Napi::Value GitRepository::SetHeadDetached(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid committish is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
// start convert_from_v8 block
  const git_oid * from_committish = NULL;
  if (info[0].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[0].As<Napi::String>().Utf8Value();
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

    from_committish = oidOut;
  }
  else {
from_committish = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_committish
    );

 int result =     git_repository_set_head_detached(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_committish
    );

      if (info[0].IsString()) {
        free((void *)from_committish);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param AnnotatedCommit committish
     * @return Number  result    */
Napi::Value GitRepository::SetHeadDetachedFromAnnotated(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "AnnotatedCommit committish is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const git_annotated_commit * from_committish = NULL;
from_committish = Napi::ObjectWrap<GitAnnotatedCommit>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_committish
    );

 int result =     git_repository_set_head_detached_from_annotated(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_committish
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String name
   * @param String email
     * @return Number  result    */
Napi::Value GitRepository::SetIdent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String name is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String email is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_name = NULL;

  std::string name = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_name = (const char *) malloc(name.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_name, name.c_str(), name.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_name) + name.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_email = NULL;

  std::string email = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_email = (const char *) malloc(email.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_email, email.c_str(), email.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_email) + email.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_name
            ,
              from_email
    );

 int result =     git_repository_set_ident(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_name
,          from_email
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String nmspace
     * @return Number  result    */
Napi::Value GitRepository::SetNamespace(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String nmspace is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_nmspace = NULL;

  std::string nmspace = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_nmspace = (const char *) malloc(nmspace.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_nmspace, nmspace.c_str(), nmspace.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_nmspace) + nmspace.length()), 0, 1);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_nmspace
    );

 int result =     git_repository_set_namespace(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_nmspace
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
   * @param String workdir
   * @param Number update_gitlink
     * @return Number  result    */
Napi::Value GitRepository::SetWorkdir(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String workdir is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number update_gitlink is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_workdir = NULL;

  std::string workdir = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_workdir = (const char *) malloc(workdir.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_workdir, workdir.c_str(), workdir.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_workdir) + workdir.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  int from_update_gitlink;
      from_update_gitlink = (int)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_workdir
    );

 int result =     git_repository_set_workdir(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_workdir
,          from_update_gitlink
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitRepository::State(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_state(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Number  result    */
Napi::Value GitRepository::StateCleanup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_state_cleanup(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return String  result    */
Napi::Value GitRepository::Workdir(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_repository_workdir(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
  if (result){
       v8ConversionSlot = Napi::String::New(env, result);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
  * @param Odb odb
    * @param Repository callback
   */
Napi::Value GitRepository::WrapOdb(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Odb odb is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  WrapOdbBaton* baton = new WrapOdbBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_odb * from_odb = NULL;
from_odb = Napi::ObjectWrap<GitOdb>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->odb = from_odb;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  WrapOdbWorker *worker = new WrapOdbWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitOdb>("odb", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::WrapOdbWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->odb
  );

  return lockMaster;
}

void GitRepository::WrapOdbWorker::Execute() {
  git_error_clear();

    int result = git_repository_wrap_odb(
&baton->out,baton->odb  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::WrapOdbWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.wrapOdb"));
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

      git_repository_free(baton->out);

  delete baton;
}

void GitRepository::WrapOdbWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitRepository::New(
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
        err = Napi::Error::New(env, "Method wrapOdb has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.wrapOdb"));
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
        Napi::Object err = Napi::Error::New(env, "Method wrapOdb has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.wrapOdb"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_repository_free(baton->out);
  }


  delete baton;
}

  
/*
     */
Napi::Value GitRepository::Cleanup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CleanupBaton* baton = new CleanupBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->repo = Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CleanupWorker *worker = new CleanupWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::CleanupWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
  );

  return lockMaster;
}

void GitRepository::CleanupWorker::Execute() {
  git_error_clear();

    int result = git_repository__cleanup(
baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitRepository::CleanupWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.cleanup"));
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

void GitRepository::CleanupWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method cleanup has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.cleanup"));
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
        Napi::Object err = Napi::Error::New(env, "Method cleanup has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Repository.cleanup"));
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

        Napi::Value GitRepository::GetReferences(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  GetReferencesBaton* baton = new GetReferencesBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->out = new std::vector<git_reference *>;
  baton->repo = GitRepository::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  GetReferencesWorker *worker = new GetReferencesWorker(baton, std::move(callback), cleanupHandles);
  worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::GetReferencesWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->repo);
  return lockMaster;
}

void GitRepository::GetReferencesWorker::Execute()
{
  giterr_clear();

  git_repository *repo = baton->repo;

  git_strarray reference_names;
  baton->error_code = git_reference_list(&reference_names, repo);

  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }
    delete baton->out;
    baton->out = NULL;
    return;
  }

  for (size_t reference_index = 0; reference_index < reference_names.count; ++reference_index) {
    git_reference *reference;
    baton->error_code = git_reference_lookup(&reference, repo, reference_names.strings[reference_index]);

    // stop execution and return if there is an error
    if (baton->error_code != GIT_OK) {
      if (giterr_last() != NULL) {
        baton->error = git_error_dup(giterr_last());
      }

      // unwind and return
      while (baton->out->size()) {
        git_reference *referenceToFree = baton->out->back();
        baton->out->pop_back();
        git_reference_free(referenceToFree);
      }

      git_strarray_free(&reference_names);
      delete baton->out;
      baton->out = NULL;
      return;
    }

    if (git_reference_type(reference) == GIT_REF_SYMBOLIC) {
      git_reference *resolved_reference;
      int resolve_result = git_reference_resolve(&resolved_reference, reference);
      git_reference_free(reference);

      // if we can't resolve the ref, then just ignore it
      if (resolve_result == GIT_OK) {
        baton->out->push_back(resolved_reference);
      }
    } else {
      baton->out->push_back(reference);
    }
  }

  git_strarray_free(&reference_names);
}

void GitRepository::GetReferencesWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  while (baton->out->size()) {
    git_reference *referenceToFree = baton->out->back();
    baton->out->pop_back();
    git_reference_free(referenceToFree);
  }

  delete baton->out;

  delete baton;
}

void GitRepository::GetReferencesWorker::HandleOKCallback()
{
  Napi::Env env = Env();
  if (baton->out != NULL)
  {
    unsigned int size = baton->out->size();
    Napi::Array result = Napi::Array::New(env, size);
    for (unsigned int i = 0; i < size; i++) {
      git_reference *reference = baton->out->at(i);
      result.Set(
        i,
        GitRefs::New(
          env,
          reference,
          true,
          GitRepository::New(env, git_reference_owner(reference), true).As<Napi::Object>()
        )
      );
    }

    delete baton->out;

    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  }
  else if (baton->error)
  {
    napi_value argv[1] = {
      Napi::Error::New(env, baton->error->message).Value()
    };
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
    {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }
  else if (baton->error_code < 0)
  {
    Napi::Object err = Napi::Error::New(env, "Repository getReferences has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Repository.getReferences"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }
  else
  {
    callback.Call({});
  }

  delete baton;
}

        Napi::Value GitRepository::GetSubmodules(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  GetSubmodulesBaton* baton = new GetSubmodulesBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->out = new std::vector<git_submodule *>;
  baton->repo = GitRepository::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  GetSubmodulesWorker *worker = new GetSubmodulesWorker(baton, std::move(callback), cleanupHandles);
  worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

struct submodule_foreach_payload {
  git_repository *repo;
  std::vector<git_submodule *> *out;
};

int foreachSubmoduleCB(git_submodule *submodule, const char *name, void *void_payload) {
  submodule_foreach_payload *payload = (submodule_foreach_payload *)void_payload;
  git_submodule *out;

  int result = git_submodule_lookup(&out, payload->repo, name);
  if (result == GIT_OK) {
    payload->out->push_back(out);
  }

  return result;
}

nodegit::LockMaster GitRepository::GetSubmodulesWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->repo);
  return lockMaster;
}

void GitRepository::GetSubmodulesWorker::Execute()
{
  giterr_clear();

  submodule_foreach_payload payload { baton->repo, baton->out };
  baton->error_code = git_submodule_foreach(baton->repo, foreachSubmoduleCB, (void *)&payload);

  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

    while (baton->out->size()) {
      git_submodule_free(baton->out->back());
      baton->out->pop_back();
    }
    delete baton->out;
    baton->out = NULL;
  }
}

void GitRepository::GetSubmodulesWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  while (baton->out->size()) {
    git_submodule_free(baton->out->back());
    baton->out->pop_back();
  }

  delete baton->out;

  delete baton;
}

void GitRepository::GetSubmodulesWorker::HandleOKCallback()
{
  Napi::Env env = Env();
  if (baton->out != NULL)
  {
    unsigned int size = baton->out->size();
    Napi::Array result = Napi::Array::New(env, size);
    for (unsigned int i = 0; i < size; i++) {
      git_submodule *submodule = baton->out->at(i);
      result.Set(
        i,
        GitSubmodule::New(
          env,
          submodule,
          true,
          GitRepository::New(env, git_submodule_owner(submodule), true).As<Napi::Object>()
        )
      );
    }

    delete baton->out;

    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  }
  else if (baton->error)
  {
    napi_value argv[1] = {
      Napi::Error::New(env, baton->error->message).Value()
    };
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
    {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }
  else if (baton->error_code < 0)
  {
    Napi::Object err = Napi::Error::New(env, "Repository getSubmodules has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Repository.getSubmodules"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }
  else
  {
    callback.Call({});
  }

  delete baton;
}

        Napi::Value GitRepository::GetRemotes(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  GetRemotesBaton* baton = new GetRemotesBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->out = new std::vector<git_remote *>;
  baton->repo = GitRepository::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  GetRemotesWorker *worker = new GetRemotesWorker(baton, std::move(callback), cleanupHandles);
  worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::GetRemotesWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true);
  return lockMaster;
}

void GitRepository::GetRemotesWorker::Execute()
{
  giterr_clear();

  git_repository *repo = baton->repo;

  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }
    delete baton->out;
    baton->out = NULL;
    return;
  }

  git_strarray remote_names;
  baton->error_code = git_remote_list(&remote_names, repo);

  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }

    delete baton->out;
    baton->out = NULL;
    return;
  }

  for (size_t remote_index = 0; remote_index < remote_names.count; ++remote_index) {
    git_remote *remote;
    baton->error_code = git_remote_lookup(&remote, repo, remote_names.strings[remote_index]);

    // stop execution and return if there is an error
    if (baton->error_code != GIT_OK) {
      if (giterr_last() != NULL) {
        baton->error = git_error_dup(giterr_last());
      }

      // unwind and return
      while (baton->out->size()) {
        git_remote *remoteToFree = baton->out->back();
        baton->out->pop_back();
        git_remote_free(remoteToFree);
      }

      git_strarray_free(&remote_names);
      delete baton->out;
      baton->out = NULL;
      return;
    }

    baton->out->push_back(remote);
  }

  git_strarray_free(&remote_names);
}

void GitRepository::GetRemotesWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  while (baton->out->size()) {
    git_remote *remoteToFree = baton->out->back();
    baton->out->pop_back();
    git_remote_free(remoteToFree);
  }

  delete baton->out;

  delete baton;
}

void GitRepository::GetRemotesWorker::HandleOKCallback()
{
  Napi::Env env = Env();
  if (baton->out != NULL)
  {
    unsigned int size = baton->out->size();
    Napi::Array result = Napi::Array::New(env, size);
    for (unsigned int i = 0; i < size; i++) {
      git_remote *remote = baton->out->at(i);
      result.Set(
        i,
        GitRemote::New(
          env,
          remote,
          true,
          GitRepository::New(env, git_remote_owner(remote), true).As<Napi::Object>()
        )
      );
    }

    delete baton->out;

    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  }
  else if (baton->error)
  {
    napi_value argv[1] = {
      Napi::Error::New(env, baton->error->message).Value()
    };
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
    {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }
  else if (baton->error_code < 0)
  {
    Napi::Object err = Napi::Error::New(env, "Repository refreshRemotes has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Repository.refreshRemotes"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }
  else
  {
    callback.Call({});
  }

  delete baton;
}

        int getOidOfReferenceCommit(git_oid *commitOid, git_reference *ref) {
  git_object *commitObject;
  int result = git_reference_peel(&commitObject, ref, GIT_OBJ_COMMIT);

  if (result != GIT_OK) {
    return result;
  }

  git_oid_cpy(commitOid, git_object_id(commitObject));
  git_object_free(commitObject);
  return result;
}

int asDirectReference(git_reference **out, git_reference *ref) {
  if (git_reference_type(ref) != GIT_REF_SYMBOLIC) {
    return git_reference_dup(out, ref);
  }

  int error = git_reference_resolve(out, ref);
  if (error != GIT_OK) {
    *out = NULL;
  }

  return GIT_OK;
}

int lookupDirectReferenceByShorthand(git_reference **out, git_repository *repo, const char *shorthand) {
  git_reference *ref = NULL;
  int result = git_reference_dwim(&ref, repo, shorthand);

  if (result != GIT_OK) {
    return result;
  }

  result = asDirectReference(out, ref);
  git_reference_free(ref);
  return result;
}

int lookupDirectReferenceByFullName(git_reference **out, git_repository *repo, const char *fullName) {
  git_reference *ref = NULL;
  int result = git_reference_lookup(&ref, repo, fullName);

  if (result != GIT_OK) {
    return result;
  }

  result = asDirectReference(out, ref);
  git_reference_free(ref);
  return result;
}

char *getRemoteNameOfReference(git_reference *remoteReference) {
  return strtok(strdup(git_reference_shorthand(remoteReference)), "/");
}

bool gitStrArrayContains(git_strarray *strarray, const char *string) {
  for (size_t i = 0; i < strarray->count; ++i) {
    if (strcmp(strarray->strings[i], string) == 0) {
      return true;
    }
  }
  return false;
}

class RefreshedRefModel {
public:
  RefreshedRefModel(git_reference *ref):
    fullName(strdup(git_reference_name(ref))),
    message(NULL),
    sha(new char[GIT_OID_HEXSZ + 1]),
    shorthand(strdup(git_reference_shorthand(ref))),
    tagOdbBuffer(NULL),
    tagOdbBufferLength(0),
    type(NULL)
  {
    if (git_reference_is_branch(ref)) {
      type = "branch";
    } else if (git_reference_is_remote(ref)) {
      type = "remote";
    } else {
      type = "tag";
    }
  }

  RefreshedRefModel(const RefreshedRefModel &) = delete;
  RefreshedRefModel(RefreshedRefModel &&) = delete;
  RefreshedRefModel &operator=(const RefreshedRefModel &) = delete;
  RefreshedRefModel &operator=(RefreshedRefModel &&) = delete;

  static int fromReference(RefreshedRefModel **out, git_reference *ref, git_odb *odb) {
    RefreshedRefModel *refModel = new RefreshedRefModel(ref);
    const git_oid *referencedTargetOid = git_reference_target(ref);

    if (!git_reference_is_tag(ref)) {
      git_oid_tostr(refModel->sha, GIT_OID_HEXSZ + 1, referencedTargetOid);

      *out = refModel;
      return GIT_OK;
    }
    git_repository *repo = git_reference_owner(ref);

    git_tag *referencedTag;
    if (git_tag_lookup(&referencedTag, repo, referencedTargetOid) == GIT_OK) {
      const char *tagMessage = git_tag_message(referencedTag);
      refModel->message = tagMessage ? strdup(tagMessage) : NULL;

      git_odb_object *tagOdbObject;
      if (git_odb_read(&tagOdbObject, odb, git_tag_id(referencedTag)) == GIT_OK) {
        refModel->tagOdbBufferLength = git_odb_object_size(tagOdbObject);
        refModel->tagOdbBuffer = new char[refModel->tagOdbBufferLength];
        std::memcpy(refModel->tagOdbBuffer, git_odb_object_data(tagOdbObject), refModel->tagOdbBufferLength);
        git_odb_object_free(tagOdbObject);
      }

      git_tag_free(referencedTag);
    }

    git_oid peeledReferencedTargetOid;
    int error = getOidOfReferenceCommit(&peeledReferencedTargetOid, ref);
    if (error != GIT_OK) {
      delete refModel;
      return error;
    }

    git_oid_tostr(refModel->sha, GIT_OID_HEXSZ + 1, &peeledReferencedTargetOid);

    *out = refModel;
    return GIT_OK;
  }

  static void ensureSignatureRegexes(Napi::Env env) {
    if (!signatureRegexesBySignatureType.IsEmpty()) {
      return;
    }

    Napi::Array gpgsigArray = Napi::Array::New(env, 2);
    Napi::Array x509Array = Napi::Array::New(env, 1);

    // Build regexes using JavaScript's RegExp constructor
    Napi::Function RegExpCtor = env.Global().Get("RegExp").As<Napi::Function>();

    gpgsigArray.Set((uint32_t)0,
      RegExpCtor.New({
        Napi::String::New(env, "-----BEGIN PGP SIGNATURE-----[\\s\\S]+?-----END PGP SIGNATURE-----"),
        Napi::String::New(env, "gm")
      })
    );

    gpgsigArray.Set((uint32_t)1,
      RegExpCtor.New({
        Napi::String::New(env, "-----BEGIN PGP MESSAGE-----[\\s\\S]+?-----END PGP MESSAGE-----"),
        Napi::String::New(env, "gm")
      })
    );

    x509Array.Set((uint32_t)0,
      RegExpCtor.New({
        Napi::String::New(env, "-----BEGIN SIGNED MESSAGE-----[\\s\\S]+?-----END SIGNED MESSAGE-----"),
        Napi::String::New(env, "gm")
      })
    );

    Napi::Object result = Napi::Object::New(env);
    result.Set("gpgsig", gpgsigArray);
    result.Set("x509", x509Array);

    signatureRegexesBySignatureType.Reset(result);
  }

  Napi::Object toJavascript(Napi::Env env, Napi::String signatureType) {
    Napi::Object result = Napi::Object::New(env);

    Napi::Value jsFullName;
    if (fullName == NULL) {
      jsFullName = env.Null();
    } else {
      jsFullName = Napi::String::New(env, fullName);
    }
    result.Set("fullName", jsFullName);

    Napi::Value jsMessage;
    if (message == NULL) {
      jsMessage = env.Null();
    } else {
      jsMessage = Napi::String::New(env, message);
    }
    result.Set("message", jsMessage);

    result.Set("sha", Napi::String::New(env, sha));

    Napi::Value jsShorthand;
    if (shorthand == NULL) {
      jsShorthand = env.Null();
    } else {
      jsShorthand = Napi::String::New(env, shorthand);
    }
    result.Set("shorthand", jsShorthand);

    Napi::Value jsTagSignature = env.Null();
    if (tagOdbBuffer != NULL && tagOdbBufferLength != 0) {
      Napi::Buffer<char> buffer = Napi::Buffer<char>::Copy(env, tagOdbBuffer, tagOdbBufferLength);
      // Call buffer.toString() to get string representation
      Napi::Value toStringProp = buffer.Get("toString");
      Napi::Value jsTagOdbObjectString = toStringProp.As<Napi::Function>().Call(buffer, {});

      Napi::Object _signatureRegexesBySignatureType = signatureRegexesBySignatureType.Value().As<Napi::Object>();
      Napi::Array signatureRegexes = _signatureRegexesBySignatureType.Get(signatureType).As<Napi::Array>();

      for (uint32_t i = 0; i < signatureRegexes.Length(); ++i) {
        Napi::Value regex = signatureRegexes.Get(i);

        Napi::Value matchProp = jsTagOdbObjectString.As<Napi::Object>().Get("match");
        Napi::Value match = matchProp.As<Napi::Function>().Call(jsTagOdbObjectString, { regex });
        if (match.IsArray()) {
          jsTagSignature = match.As<Napi::Object>().Get((uint32_t)0);
          break;
        }
      }
    }
    result.Set("tagSignature", jsTagSignature);

    Napi::Value jsType;
    if (type == NULL) {
      jsType = env.Null();
    } else {
      jsType = Napi::String::New(env, type);
    }
    result.Set("type", jsType);

    return result;
  }

  ~RefreshedRefModel() {
    if (fullName != NULL) { free(fullName); }
    if (message != NULL) { free(message); }
    delete[] sha;
    if (shorthand != NULL) { free(shorthand); }
    if (tagOdbBuffer != NULL) { delete[] tagOdbBuffer; }
  }

  char *fullName, *message, *sha, *shorthand, *tagOdbBuffer;
  size_t tagOdbBufferLength;
  const char *type;
  static Napi::Reference<Napi::Object> signatureRegexesBySignatureType;
};

Napi::Reference<Napi::Object> RefreshedRefModel::signatureRegexesBySignatureType;

class UpstreamModel {
public:
  UpstreamModel(const char *inputDownstreamFullName, const char *inputUpstreamFullName):
    downstreamFullName((char *)strdup(inputDownstreamFullName)),
    upstreamFullName((char *)strdup(inputUpstreamFullName)),
    ahead(0),
    behind(0) {}

  UpstreamModel(const UpstreamModel &) = delete;
  UpstreamModel(UpstreamModel &&) = delete;
  UpstreamModel &operator=(const UpstreamModel &) = delete;
  UpstreamModel &operator=(UpstreamModel &&) = delete;

  static bool fromReference(UpstreamModel **out, git_reference *ref) {
    if (!git_reference_is_branch(ref)) {
      return false;
    }

    git_reference *upstream;
    int result = git_branch_upstream(&upstream, ref);
    if (result != GIT_OK) {
      return false;
    }

    UpstreamModel *upstreamModel = new UpstreamModel(
      git_reference_name(ref),
      git_reference_name(upstream)
    );

    git_oid localCommitOid;
    result = getOidOfReferenceCommit(&localCommitOid, ref);
    if (result != GIT_OK) {
      delete upstreamModel;
      return false;
    }

    git_oid upstreamCommitOid;
    result = getOidOfReferenceCommit(&upstreamCommitOid, upstream);
    if (result != GIT_OK) {
      delete upstreamModel;
      return false;
    }

    result = git_graph_ahead_behind(
      &upstreamModel->ahead,
      &upstreamModel->behind,
      git_reference_owner(ref),
      &localCommitOid,
      &upstreamCommitOid
    );

    if (result != GIT_OK) {
      delete upstreamModel;
      return false;
    }

    *out = upstreamModel;
    return true;
  }

  Napi::Object toJavascript(Napi::Env env) {
    Napi::Object result = Napi::Object::New(env);

    Napi::Value jsDownstreamFullName;
    if (downstreamFullName == NULL) {
      jsDownstreamFullName = env.Null();
    } else {
      jsDownstreamFullName = Napi::String::New(env, downstreamFullName);
    }
    result.Set("downstreamFullName", jsDownstreamFullName);

    Napi::Value jsUpstreamFullName;
    if (upstreamFullName == NULL) {
      jsUpstreamFullName = env.Null();
    } else {
      jsUpstreamFullName = Napi::String::New(env, upstreamFullName);
    }
    result.Set("upstreamFullName", jsUpstreamFullName);

    result.Set("ahead", Napi::Number::New(env, ahead));
    result.Set("behind", Napi::Number::New(env, behind));
    return result;
  }

  ~UpstreamModel() {
    if (downstreamFullName != NULL) { free(downstreamFullName); }
    if (upstreamFullName != NULL) { free(upstreamFullName); }
  }

  char *downstreamFullName;
  char *upstreamFullName;
  size_t ahead;
  size_t behind;
};

class RefreshReferencesData {
public:
  RefreshReferencesData():
    headRefFullName(NULL),
    cherrypick(NULL),
    merge(NULL) {}

  RefreshReferencesData(const RefreshReferencesData &) = delete;
  RefreshReferencesData(RefreshReferencesData &&) = delete;
  RefreshReferencesData &operator=(const RefreshReferencesData &) = delete;
  RefreshReferencesData &operator=(RefreshReferencesData &&) = delete;

  ~RefreshReferencesData() {
    while(refs.size()) {
      delete refs.back();
      refs.pop_back();
    }
    while(upstreamInfo.size()) {
      delete upstreamInfo.back();
      upstreamInfo.pop_back();
    }
    if (headRefFullName != NULL) { free(headRefFullName); }
    if (cherrypick != NULL) { delete cherrypick; }
    if (merge != NULL) { delete merge; }
  }

  std::vector<RefreshedRefModel *> refs;
  std::vector<UpstreamModel *> upstreamInfo;
  char *headRefFullName;
  RefreshedRefModel *cherrypick;
  RefreshedRefModel *merge;
};

Napi::Value GitRepository::RefreshReferences(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();
  Napi::String signatureType;
  if (info.Length() == 2) {
    if (!info[0].IsString()) {
      Napi::Error::New(env, "Signature type must be \"gpgsig\" or \"x509\".").ThrowAsJavaScriptException();
      return env.Undefined();
    }

    Napi::String signatureTypeParam = info[0].As<Napi::String>();
    std::string sigTypeStr = signatureTypeParam.Utf8Value();
    if (sigTypeStr != "gpgsig" && sigTypeStr != "x509") {
      Napi::Error::New(env, "Signature type must be \"gpgsig\" or \"x509\".").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    signatureType = signatureTypeParam;
  } else {
    signatureType = Napi::String::New(env, "gpgsig");
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  RefreshReferencesBaton* baton = new RefreshReferencesBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->out = (void *)new RefreshReferencesData();
  baton->repo = GitRepository::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  RefreshReferencesWorker *worker = new RefreshReferencesWorker(baton, std::move(callback), cleanupHandles);
  worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
  worker->Reference("signatureType", signatureType);
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::RefreshReferencesWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->repo);
  return lockMaster;
}

void GitRepository::RefreshReferencesWorker::Execute()
{
  giterr_clear();

  git_repository *repo = baton->repo;
  RefreshReferencesData *refreshData = (RefreshReferencesData *)baton->out;
  git_odb *odb;

  baton->error_code = git_repository_odb(&odb, repo);
  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }
    delete refreshData;
    baton->out = NULL;
    return;
  }

  // START Refresh HEAD
  git_reference *headRef = NULL;
  baton->error_code = lookupDirectReferenceByShorthand(&headRef, repo, "HEAD");

  if (baton->error_code != GIT_OK || headRef == NULL) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }
    git_odb_free(odb);
    delete refreshData;
    baton->out = NULL;
    return;
  }

  RefreshedRefModel *headModel;
  baton->error_code = RefreshedRefModel::fromReference(&headModel, headRef, odb);
  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }
    git_odb_free(odb);
    git_reference_free(headRef);
    delete refreshData;
    baton->out = NULL;
    return;
  }
  refreshData->refs.push_back(headModel);

  refreshData->headRefFullName = strdup(git_reference_name(headRef));
  git_reference_free(headRef);
  // END Refresh HEAD

  // START Refresh CHERRY_PICK_HEAD
  git_reference *cherrypickRef = NULL;
  if (lookupDirectReferenceByShorthand(&cherrypickRef, repo, "CHERRY_PICK_HEAD") == GIT_OK && cherrypickRef != NULL) {
    baton->error_code = RefreshedRefModel::fromReference(&refreshData->cherrypick, cherrypickRef, odb);
    git_reference_free(cherrypickRef);
  } else {
    cherrypickRef = NULL;
  }
  // END Refresh CHERRY_PICK_HEAD

  // START Refresh MERGE_HEAD
  git_reference *mergeRef = NULL;
  // fall through if cherry pick failed
  if (baton->error_code == GIT_OK && lookupDirectReferenceByShorthand(&mergeRef, repo, "MERGE_HEAD") == GIT_OK && mergeRef != NULL) {
    baton->error_code = RefreshedRefModel::fromReference(&refreshData->merge, mergeRef, odb);
    git_reference_free(mergeRef);
  } else {
    mergeRef = NULL;
  }
  // END Refresh MERGE_HEAD

  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }
    git_odb_free(odb);
    delete refreshData;
    baton->out = NULL;
    return;
  }

  // Retrieve reference models and upstream info for each reference
  git_strarray referenceNames;
  baton->error_code = git_reference_list(&referenceNames, repo);

  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }
    git_odb_free(odb);
    delete refreshData;
    baton->out = NULL;
    return;
  }

  git_strarray remoteNames;
  baton->error_code = git_remote_list(&remoteNames, repo);

  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }
    git_odb_free(odb);
    git_strarray_free(&referenceNames);
    delete refreshData;
    baton->out = NULL;
    return;
  }

  for (size_t referenceIndex = 0; referenceIndex < referenceNames.count; ++referenceIndex) {
    git_reference *reference;
    baton->error_code = lookupDirectReferenceByFullName(&reference, repo, referenceNames.strings[referenceIndex]);

    if (baton->error_code != GIT_OK) {
      break;
    }
    if (reference == NULL) {
      // lookup found the reference but failed to resolve it directly
      continue;
    }

    UpstreamModel *upstreamModel;
    if (UpstreamModel::fromReference(&upstreamModel, reference)) {
      refreshData->upstreamInfo.push_back(upstreamModel);
    }

    bool isBranch = git_reference_is_branch(reference);
    bool isRemote = git_reference_is_remote(reference);
    bool isTag = git_reference_is_tag(reference);
    if (
      strcmp(referenceNames.strings[referenceIndex], headModel->fullName) == 0
      || (!isBranch && !isRemote && !isTag)
    ) {
      git_reference_free(reference);
      continue;
    }

    if (isRemote) {
      char *remoteNameOfRef = getRemoteNameOfReference(reference);
      bool isFromExistingRemote = gitStrArrayContains(&remoteNames, remoteNameOfRef);
      free(remoteNameOfRef);
      if (!isFromExistingRemote) {
        git_reference_free(reference);
        continue;
      }
    }

    RefreshedRefModel *refreshedRefModel;
    baton->error_code = RefreshedRefModel::fromReference(&refreshedRefModel, reference, odb);
    git_reference_free(reference);

    if (baton->error_code == GIT_OK) {
      refreshData->refs.push_back(refreshedRefModel);
    } else {
      baton->error_code = GIT_OK;
    }
  }

  git_odb_free(odb);
  git_strarray_free(&remoteNames);
  git_strarray_free(&referenceNames);

  if (baton->error_code != GIT_OK) {
    if (giterr_last() != NULL) {
      baton->error = git_error_dup(giterr_last());
    }
    delete refreshData;
    baton->out = NULL;
    return;
  }
}

void GitRepository::RefreshReferencesWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  RefreshReferencesData *refreshData = (RefreshReferencesData *)baton->out;
  delete refreshData;

  delete baton;
}

void GitRepository::RefreshReferencesWorker::HandleOKCallback()
{
  Napi::Env env = Env();
  if (baton->out != NULL)
  {
    RefreshedRefModel::ensureSignatureRegexes(env);
    auto refreshData = (RefreshReferencesData *)baton->out;
    Napi::Object result = Napi::Object::New(env);

    result.Set(
      "headRefFullName",
      Napi::String::New(env, refreshData->headRefFullName)
    );

    Napi::String signatureType = GetFromPersistent("signatureType").As<Napi::String>();

    unsigned int numRefs = refreshData->refs.size();
    Napi::Array refs = Napi::Array::New(env, numRefs);
    for (unsigned int i = 0; i < numRefs; ++i) {
      RefreshedRefModel *refreshedRefModel = refreshData->refs[i];
      refs.Set(i, refreshedRefModel->toJavascript(env, signatureType));
    }
    result.Set("refs", refs);

    unsigned int numUpstreamInfo = refreshData->upstreamInfo.size();
    Napi::Array upstreamInfo = Napi::Array::New(env, numUpstreamInfo);
    for (unsigned int i = 0; i < numUpstreamInfo; ++i) {
      UpstreamModel *upstreamModel = refreshData->upstreamInfo[i];
      upstreamInfo.Set(i, upstreamModel->toJavascript(env));
    }
    result.Set("upstreamInfo", upstreamInfo);

    if (refreshData->cherrypick != NULL) {
      result.Set(
        "cherrypick",
        refreshData->cherrypick->toJavascript(env, signatureType)
      );
    } else {
      result.Set("cherrypick", env.Null());
    }

    if (refreshData->merge != NULL) {
      result.Set(
        "merge",
        refreshData->merge->toJavascript(env, signatureType)
      );
    } else {
      result.Set("merge", env.Null());
    }

    delete refreshData;

    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  }
  else if (baton->error)
  {
    napi_value argv[1] = {
      Napi::Error::New(env, baton->error->message).Value()
    };
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
    {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }
  else if (baton->error_code < 0)
  {
    Napi::Object err = Napi::Error::New(env, "Repository refreshReferences has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Repository.refreshReferences"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }
  else
  {
    callback.Call({});
  }

  delete baton;
}

   
/*
   * @param Index index
     */
Napi::Value GitRepository::SetIndex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

// start convert_from_v8 block
  git_index * from_index = NULL;
    if ((info.Length() - 1) > 0 && info[0].IsObject()) {
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
  else {
    from_index = 0;
  }
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_index
    );

 int result =     git_repository_set_index(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_index
    );

      if (result != GIT_OK) {

        if (git_error_last()->klass != GIT_ERROR_NONE) {
          Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
          return env.Undefined();
        } else {
          Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
          return env.Undefined();
        }
      } // lock master scope end
      return scope.Escape(env.Undefined());
  }
}
        /**
 * \struct CommitsGraphNode
 */
struct CommitsGraphNode
{
  CommitsGraphNode(uint32_t aParentsLeft) : parentsLeft(aParentsLeft) {}
  CommitsGraphNode() = default;
  ~CommitsGraphNode() = default;
  CommitsGraphNode(const CommitsGraphNode &other) = delete;
  CommitsGraphNode(CommitsGraphNode &&other) = delete;
  CommitsGraphNode& operator=(const CommitsGraphNode &other) = delete;
  CommitsGraphNode& operator=(CommitsGraphNode &&other) = delete;

  std::vector<CommitsGraphNode *> children {};
  uint32_t parentsLeft {0}; // used when calculating the maximum history depth
};

/**
 * \class CommitsGraph
 */
class CommitsGraph
{
public:
  CommitsGraph() = default;
  ~CommitsGraph() = default;
  CommitsGraph(const CommitsGraph &other) = delete;
  CommitsGraph(CommitsGraph &&other) = delete;
  CommitsGraph& operator=(const CommitsGraph &other) = delete;
  CommitsGraph& operator=(CommitsGraph &&other) = delete;

  using CommitsGraphMap = std::unordered_map<std::string, std::unique_ptr<CommitsGraphNode>>;

  void AddNode(const std::string &oidStr, const std::vector<std::string> &parents);
  uint32_t CalculateMaxDepth();

private:
  void addParentNode(const std::string &oidParentStr, CommitsGraphNode *child);

  CommitsGraphMap m_mapOidNode {};
  std::vector<CommitsGraphNode *> m_roots {};
};

/**
 * CommitsGraph::AddNode
 * 
 * \param oidStr oid of the commit object to add.
 * \param parents oids of the commit's parents.
 */
void CommitsGraph::AddNode(const std::string &oidStr, const std::vector<std::string> &parents)
{
  const uint32_t numParents = static_cast<uint32_t>(parents.size());

  auto emplacePair = m_mapOidNode.emplace(std::make_pair(
    oidStr, std::make_unique<CommitsGraphNode>(numParents)));

  CommitsGraphMap::iterator itNode = emplacePair.first;

  // if this node already added by a child, update its parentsLeft
  if (emplacePair.second == false) {
    itNode->second.get()->parentsLeft = numParents;
  }

  // set roots
  if (numParents == 0) {
    m_roots.emplace_back(itNode->second.get());
  }

  // add parents
  for (unsigned int i = 0; i < numParents; ++i) {
    addParentNode(parents.at(i), itNode->second.get());
  }
}

/**
 * CommitsGraph::CalculateMaxDepth
 * \return Calculated maximum depth of the tree.
 * 
 * Uses iterative algorithm to count levels.
 * Considers multiple initial commits.
 * Considers that children of one level can have multiple parents, hence we insert unique children
 * at each level.
 * Considers that same child can be in different levels. Here to prevent counting the same child
 * multiple times, we only add a child when the last parent (parentsLeft) inserts it. This is
 * actually what makes the algorithm fast.
 * Recursive algorithm avoided to prevent stack overflow in case of excessive levels in the tree.
 * 
 * Explanation of the algorithm:
 * once the graph is built with the commit history, `CalculateMaxDepth()` counts the maximum number
 * of levels from any of the roots to any of the leaves, which gives us the maximum depth
 * (`historyStructure.maxDepth` in the final result).
 * Inside `CalculateMaxDepth()`, to count levels, we add in an iterative way for each level and
 * starting at the roots level, all the children from that level, but only if each child is the last
 * time we'll consider it in the algorithm (for example if a child node 'C' has 2 parents 'P1' and
 * 'P2', and 'P1' has already been considered before in the algorithm as parent of 'C', and now we are
 * processing 'C' as a child from 'P2', which will be the last time, as 'C' has no more parents left).
 * This way we prevent counting 'C' multiple times.
 */
uint32_t CommitsGraph::CalculateMaxDepth()
{
  uint32_t maxDepth {0};
  std::unordered_set<CommitsGraphNode *> parents {};
  std::unordered_set<CommitsGraphNode *> children {};

  // start from the root commmits
  for (CommitsGraphNode *root : m_roots) {
    children.insert(root);
  }

  while (!children.empty()) {
    ++maxDepth;
    parents = std::move(children);

    // add unique children of next level, and only if from the last parent
    for (CommitsGraphNode *parent : parents) {
      for (CommitsGraphNode *child : parent->children) {
        if (--child->parentsLeft == 0) {
          children.insert(child);
        }
      }
    }
  }

  return maxDepth;
}

/**
 * CommitsGraph::addParentNode
 * 
 * \param oidParentStr oid of the parent commit to add.
 * \param child Child of the parent commit being added.
 */
void CommitsGraph::addParentNode(const std::string &oidParentStr, CommitsGraphNode *child)
{
  CommitsGraphMap::iterator itParentNode = m_mapOidNode.emplace(std::make_pair(
    oidParentStr, std::make_unique<CommitsGraphNode>())).first;

  // add child to parent
  itParentNode->second->children.emplace_back(child);
}

/**
 * \struct TreeStatistics
 *  Structure to store statistics for a git tree object.
 */
struct TreeStatistics
{
  TreeStatistics() = default;
  ~TreeStatistics() = default;
  TreeStatistics(const TreeStatistics &other) = delete;
  TreeStatistics(TreeStatistics &&other) = default;
  TreeStatistics& operator=(const TreeStatistics &other) = delete;
  TreeStatistics& operator=(TreeStatistics &&other) = default;

  size_t numDirectories{0};
  size_t maxPathDepth {0};
  size_t maxPathLength {0};
  size_t numFiles {0};
  size_t totalFileSize {0};
  size_t numSymlinks {0};
  size_t numSubmodules {0};
};

/**
 * \struct Statistics
 * Stores statistics of the analyzed repository.
 */
struct Statistics
{
  Statistics() = default;
  ~Statistics() = default;
  Statistics(const Statistics &other) = delete;
  Statistics(Statistics &&other) = delete;
  Statistics& operator=(const Statistics &other) = delete;
  Statistics& operator=(Statistics &&other) = delete;

  struct {
    struct { size_t count {0}; size_t size {0}; } commits;
    struct { size_t count {0}; size_t size {0}; size_t entries {0}; } trees;
    struct { size_t count {0}; size_t size {0}; } blobs;
    struct { size_t count {0}; } annotatedTags;
    struct { size_t count {0}; } references;
  } repositorySize {};

  struct {
    struct { size_t maxSize {0}; size_t maxParents {0}; } commits;
    struct { size_t maxEntries {0}; } trees;
    struct { size_t maxSize {0}; } blobs;
  } biggestObjects {};

  struct {
    uint32_t maxDepth {0};
    uint32_t maxTagDepth {0};
  } historyStructure {};

  TreeStatistics biggestCheckouts {};
};

/**
 * \struct OdbObjectsData
 * Structure to store, for each object read from the repository:
 * - its information (size, parents for a commit, etc.)
 * - different data needed to obtain the resulting statistics
 */
struct OdbObjectsData
{
  static constexpr uint32_t kUnreachable = 0;

  struct CommitInfo {
    std::string oidTree {};
    size_t size {0};
    std::vector<std::string> parents {};
    // number of sources from which a commit can be reached:
    // a child commit, a tag, or a direct git reference
    uint32_t reachability {kUnreachable};
  };

  struct TreeInfoAndStats {
    size_t size {0};
    size_t numEntries {0};
    std::vector<std::string> entryBlobs {};
    std::vector< std::pair<std::string, size_t> > entryTreesNameLen {};
    // number of sources from which a tree can be reached:
    // a commit, another tree's entry, or a tag
    uint32_t reachability {kUnreachable};
    TreeStatistics stats {};
    bool statsDone {false};
  };

  struct BlobInfo {
    size_t size {0};
    // number of sources from which a blob can be reached:
    // a tree's entry, or a tag
    uint32_t reachability {kUnreachable};
  };

  struct TagInfo {
    static constexpr uint32_t kUnsetDepth = 0;

    std::string oidTarget {};
    git_object_t typeTarget {GIT_OBJECT_INVALID};
    uint32_t depth {kUnsetDepth};
    // number of sources from which a tag can be reached:
    // a reference, or another tag
    uint32_t reachability {kUnreachable};
  };

  OdbObjectsData() = default;
  ~OdbObjectsData() = default;
  OdbObjectsData(const OdbObjectsData &other) = delete;
  OdbObjectsData(OdbObjectsData &&other) = delete;
  OdbObjectsData& operator=(const OdbObjectsData &other) = delete;
  OdbObjectsData& operator=(OdbObjectsData &&other) = delete;

  struct {
    std::unordered_map<std::string, CommitInfo> info {};
    std::unordered_set<std::string> unreachables {};
    // Tree of commits (graph) to be built after having read the object
    // database, and pruned unreachable objects.
    // Used to calculate the maximum history depth.
    CommitsGraph graph {};
    size_t totalSize {0};
    size_t maxSize {0};
    size_t maxParents {0};
  } commits {};

  struct {
    std::unordered_map<std::string, TreeInfoAndStats> info;
    std::unordered_set<std::string> unreachables {};
    size_t totalSize {0};
    size_t totalEntries {0};
    size_t maxEntries {0};
  } trees {};

  struct {
    std::unordered_map<std::string, BlobInfo> info {};
    std::unordered_set<std::string> unreachables {};
    size_t totalSize {0};
    size_t maxSize {0};
  } blobs {};

  struct {
    std::unordered_map<std::string, TagInfo> info;
    std::unordered_set<std::string> unreachables {};
  } tags {};

  struct {
    std::mutex commits {};
    std::mutex trees {};
    std::mutex blobs {};
    std::mutex tags {};
  } infoMutex;

  using iterCommitInfo = std::unordered_map<std::string, CommitInfo>::iterator;
  using iterUnreachable = std::unordered_set<std::string>::iterator;
  using iterTreeInfo = std::unordered_map<std::string, TreeInfoAndStats>::iterator;
  using iterBlobInfo = std::unordered_map<std::string, BlobInfo>::iterator;
  using iterTagInfo = std::unordered_map<std::string, TagInfo>::iterator;
};

/**
 * \class WorkItemOid
 * WorkItem storing odb oids for the WorkPool.
 */
class WorkItemOid : public WorkItem {
public:
  WorkItemOid(const git_oid &oid)
    : m_oid(oid) {}
  ~WorkItemOid() = default;
  WorkItemOid(const WorkItemOid &other) = delete;
  WorkItemOid(WorkItemOid &&other) = delete;
  WorkItemOid& operator=(const WorkItemOid &other) = delete;
  WorkItemOid& operator=(WorkItemOid &&other) = delete;
  
  const git_oid& GetOid() const { return m_oid; }

private:
  git_oid m_oid {};
};

/**
 * \class WorkerStoreOdbData
 * Worker for the WorkPool to store odb object data.
 */
class WorkerStoreOdbData : public IWorker
{
public:
  WorkerStoreOdbData(const std::string &repoPath, OdbObjectsData *odbObjectsData)
    : m_repoPath(repoPath), m_odbObjectsData(odbObjectsData) {}
  ~WorkerStoreOdbData();
  WorkerStoreOdbData(const WorkerStoreOdbData &other) = delete;
  WorkerStoreOdbData(WorkerStoreOdbData &&other) = delete;
  WorkerStoreOdbData& operator=(const WorkerStoreOdbData &other) = delete;
  WorkerStoreOdbData& operator=(WorkerStoreOdbData &&other) = delete;

  bool Initialize();
  bool Execute(std::unique_ptr<WorkItem> &&work);

private:
  OdbObjectsData::TreeInfoAndStats thisTreeInfoAndStats(const git_tree *tree, size_t size, size_t numEntries);

  std::string m_repoPath {};
  git_repository *m_repo {nullptr};
  git_odb *m_odb {nullptr};
  OdbObjectsData *m_odbObjectsData {nullptr};
};

/**
 * WorkerStoreOdbData::~WorkerStoreOdbData
 */
WorkerStoreOdbData::~WorkerStoreOdbData() {
  if (m_odb) {
    git_odb_free(m_odb);
  }
  if (m_repo) {
    git_repository_free(m_repo);
  }
}

/**
 * WorkerStoreOdbData::Initialize
 */
bool WorkerStoreOdbData::Initialize() {
  if (m_repo != nullptr) { // if already initialized
    return true;
  }

  return !m_repoPath.empty() &&
    git_repository_open(&m_repo, m_repoPath.c_str()) == GIT_OK &&
    git_repository_odb(&m_odb, m_repo) == GIT_OK;
}

/**
 * WorkerStoreOdbData::Execute
 */
bool WorkerStoreOdbData::Execute(std::unique_ptr<WorkItem> &&work)
{
  std::unique_ptr<WorkItemOid> wi {static_cast<WorkItemOid*>(work.release())};
  const git_oid &oid = wi->GetOid();

  // NOTE about PERFORMANCE (May 2021):
  // git_object_lookup() is as expensive as git_odb_read().
  // They give access to different information from the libgit2 API.
  // Try to call only one of them if possible.

  git_object *target {nullptr};
  if (git_object_lookup(&target, m_repo, &oid, GIT_OBJECT_ANY) != GIT_OK) {
    return false;
  }

  switch (git_object_type(target))
  {
    case GIT_OBJECT_COMMIT:
    {
      git_commit *commit = (git_commit*)target;
      // NOTE about PERFORMANCE (May 2021):
      // calling git_odb_object_size() was slightly faster than calculating header size + message size + 1 with GK repo

      // obtain size
      git_odb_object *obj {nullptr};
      if (git_odb_read(&obj, m_odb, &oid) != GIT_OK) {
        git_object_free(target);
        return false;
      }
      const size_t size = git_odb_object_size(obj);
      git_odb_object_free(obj);

      // obtain CommitInfo
      const unsigned int numParents = git_commit_parentcount(commit);
      std::vector<std::string> parents {};
      for (unsigned int i = 0; i < numParents; ++i) {
        parents.emplace_back(reinterpret_cast<const char *>(git_commit_parent_id(commit, i)->id),
          GIT_OID_RAWSZ);
      }

      OdbObjectsData::CommitInfo commitInfo {
        std::string(reinterpret_cast<const char *>(git_commit_tree_id(commit)->id), GIT_OID_RAWSZ),
        size,
        std::move(parents),
        OdbObjectsData::kUnreachable};

      { // lock
        std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.commits);

        m_odbObjectsData->commits.info.emplace(std::make_pair(
          std::string(reinterpret_cast<const char *>(oid.id), GIT_OID_RAWSZ),
          std::move(commitInfo)));
      }
    }
      break;

    case GIT_OBJECT_TREE:
    {
      git_tree *tree = (git_tree*)target;

      // do not count empty trees, like git's empty tree "4b825dc642cb6eb9a060e54bf8d69288fbee4904"
      const size_t numEntries = git_tree_entrycount(tree);
      if (numEntries == 0) {
        git_object_free(target);
        return true;
      }

      // obtain size
      git_odb_object *obj {nullptr};
      if (git_odb_read(&obj, m_odb, &oid) != GIT_OK) {
        git_object_free(target);
        return false;
      }
      const size_t size = git_odb_object_size(obj);
      git_odb_object_free(obj);

      // obtain tree data and calculate statistics for only this tree (not recursively)
      OdbObjectsData::TreeInfoAndStats treeInfoAndStats = thisTreeInfoAndStats(tree, size, numEntries);
     
      { // lock
        std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.trees);

        m_odbObjectsData->trees.info.emplace(std::make_pair(
          std::string(reinterpret_cast<const char *>(oid.id), GIT_OID_RAWSZ),
          std::move(treeInfoAndStats)));
      }
    }
      break;

    case GIT_OBJECT_BLOB:
    {
      git_blob *blob = (git_blob*)target;
      const size_t size = git_blob_rawsize(blob);
      OdbObjectsData::BlobInfo blobInfo {size, OdbObjectsData::kUnreachable};

      { // lock
        std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.blobs);

        m_odbObjectsData->blobs.info.emplace(std::make_pair(
          std::string(reinterpret_cast<const char *>(oid.id), GIT_OID_RAWSZ),
          std::move(blobInfo)));
      }
    }
      break;

    case GIT_OBJECT_TAG:
    {
      // obtain TagInfo
      git_tag *tag = (git_tag*)target;
      const git_oid *oid_target = git_tag_target_id(tag);
      OdbObjectsData::TagInfo tagInfo {
        std::string(reinterpret_cast<const char *>(oid_target->id), GIT_OID_RAWSZ),
        git_tag_target_type(tag),
        OdbObjectsData::TagInfo::kUnsetDepth,
        OdbObjectsData::kUnreachable};

      { // lock
        std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.tags);
        m_odbObjectsData->tags.info.emplace(std::make_pair(
            std::string(reinterpret_cast<const char *>(oid.id), GIT_OID_RAWSZ),
            std::move(tagInfo)));
      }
    }
      break;

    default:
      break;
  }

  git_object_free(target);

  return true;
}

/**
 * WorkerStoreOdbData::thisTreeInfoAndStats
 * 
 * Obtain tree data and calculate the part of this tree's statistics that each thread can do.
 * 
 * \param tree tree to get data from and calculate partial statistics of.
 * \param size tree size, to be added to the final result.
 * \param numEntries number of entries of this tree.
 * \return this tree's data and partial statistics.
  */
OdbObjectsData::TreeInfoAndStats WorkerStoreOdbData::thisTreeInfoAndStats(const git_tree *tree, size_t size,
  size_t numEntries)
{
  OdbObjectsData::TreeInfoAndStats treeInfoAndStats {};
  treeInfoAndStats.size = size;
  treeInfoAndStats.numEntries = numEntries;

  for (size_t i = 0; i < numEntries; ++i)
  {
    const git_tree_entry *te = git_tree_entry_byindex(tree, i);
    if (te == nullptr) {
      continue;
    }
    const git_object_t te_type = git_tree_entry_type(te);
    const char *teName {nullptr};
    size_t teNameLen {0};
    const git_oid *te_oid {nullptr};

    switch (te_type)
    {
      // count submodules
      case GIT_OBJECT_COMMIT:
        if (git_tree_entry_filemode(te) == GIT_FILEMODE_COMMIT) {
          ++treeInfoAndStats.stats.numSubmodules;
        }
        break;

      case GIT_OBJECT_BLOB:
      {
        // count symbolic links, but don't add them as blob entries
        if (git_tree_entry_filemode(te) == GIT_FILEMODE_LINK) {
          ++treeInfoAndStats.stats.numSymlinks;
        }
        else {
          ++treeInfoAndStats.stats.numFiles;
          teName = git_tree_entry_name(te);
          teNameLen = std::char_traits<char>::length(teName);
          treeInfoAndStats.stats.maxPathLength =
            std::max<size_t>(treeInfoAndStats.stats.maxPathLength, teNameLen);
        }
        // store both types of files (symbolic links and non symbolic links) as entryBlob
        te_oid = git_tree_entry_id(te);
        treeInfoAndStats.entryBlobs.emplace_back(
          reinterpret_cast<const char *>(te_oid->id), GIT_OID_RAWSZ);
      }
        break;
        
      case GIT_OBJECT_TREE:
      {
        // We store tree's name length to compare in posterior stage, after threads work
        teName = git_tree_entry_name(te);
        teNameLen = std::char_traits<char>::length(teName);

        te_oid = git_tree_entry_id(te);
        treeInfoAndStats.entryTreesNameLen.emplace_back(std::make_pair(
          std::string(reinterpret_cast<const char *>(te_oid->id), GIT_OID_RAWSZ),
          teNameLen));
      }
        break;
        
      default:
        break;
    }
  }

  return treeInfoAndStats;
}

/**
 * \class WorkItemOidStrType
 * WorkItem storing pointers to object info structs for the WorkPool.
 */
class WorkItemOidStrType : public WorkItem {
public:
  WorkItemOidStrType(void *objectInfo, git_object_t type)
    : m_objectInfo(objectInfo), m_oid_type(type) {}
  ~WorkItemOidStrType() = default;
  WorkItemOidStrType(const WorkItemOidStrType &other) = delete;
  WorkItemOidStrType(WorkItemOidStrType &&other) = delete;
  WorkItemOidStrType& operator=(const WorkItemOidStrType &other) = delete;
  WorkItemOidStrType& operator=(WorkItemOidStrType &&other) = delete;
  
  void* GetObjectInfo() const { return m_objectInfo; }
  const git_object_t& GetOidType() const { return m_oid_type; }

private:
  void *m_objectInfo {nullptr};
  git_object_t m_oid_type {};
};

/**
 * \class WorkerReachCounter
 * Worker for the WorkPool to count reachability of each object.
 */
class WorkerReachCounter : public IWorker
{
public:
  WorkerReachCounter(OdbObjectsData *odbObjectsData)
    : m_odbObjectsData(odbObjectsData) {}
  ~WorkerReachCounter() = default;
  WorkerReachCounter(const WorkerReachCounter &other) = delete;
  WorkerReachCounter(WorkerReachCounter &&other) = delete;
  WorkerReachCounter& operator=(const WorkerReachCounter &other) = delete;
  WorkerReachCounter& operator=(WorkerReachCounter &&other) = delete;

  bool Initialize() { return true; }
  bool Execute(std::unique_ptr<WorkItem> &&work);

private:
  void setReachabilityFromTags(void *objectInfo);
  void setReachabilityFromCommits(void *objectInfo);
  void setReachabilityFromTrees(void *objectInfo);

  OdbObjectsData *m_odbObjectsData {nullptr};
};

/**
 * WorkerReachCounter::Execute
 */
bool WorkerReachCounter::Execute(std::unique_ptr<WorkItem> &&work)
{
  std::unique_ptr<WorkItemOidStrType> wi {static_cast<WorkItemOidStrType*>(work.release())};
  void *objectInfo = wi->GetObjectInfo();
  const git_object_t &oid_type = wi->GetOidType();

  switch (oid_type) {
    case GIT_OBJECT_TAG:
      setReachabilityFromTags(objectInfo);
      break;
    case GIT_OBJECT_COMMIT:
      setReachabilityFromCommits(objectInfo);
      break;
    case GIT_OBJECT_TREE:
      setReachabilityFromTrees(objectInfo);
      break;
    case GIT_OBJECT_BLOB:
      // do not process blobs in this stage
      break;
    default:
      break;
  }

  return true;
}

/**
 * WorkerReachCounter::setReachabilityFromTags
 * Adds reachability counter where tags point (any type of object).
 */
void WorkerReachCounter::setReachabilityFromTags(void *objectInfo)
{
  const OdbObjectsData::TagInfo *tagInfo = static_cast<const OdbObjectsData::TagInfo *>(objectInfo);

  switch (tagInfo->typeTarget) {
    case GIT_OBJECT_COMMIT:
    {
      OdbObjectsData::iterCommitInfo itCommitInfo =
      m_odbObjectsData->commits.info.find(tagInfo->oidTarget);
    
      if (itCommitInfo != m_odbObjectsData->commits.info.end()) {
        { // lock
          std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.commits);
          ++itCommitInfo->second.reachability;
        }
      }
    }
      break;

    case GIT_OBJECT_TREE:
    {
      OdbObjectsData::iterTreeInfo itTreeInfo =
      m_odbObjectsData->trees.info.find(tagInfo->oidTarget);
    
      if (itTreeInfo != m_odbObjectsData->trees.info.end()) {
        { // lock
          std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.trees);
          ++itTreeInfo->second.reachability;
        }
      }
    }

    case GIT_OBJECT_BLOB:
    {
      OdbObjectsData::iterBlobInfo itBlobInfo =
      m_odbObjectsData->blobs.info.find(tagInfo->oidTarget);
    
      if (itBlobInfo != m_odbObjectsData->blobs.info.end()) {
        { // lock
          std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.blobs);
          ++itBlobInfo->second.reachability;
        }
      }
    }

    case GIT_OBJECT_TAG:
    {
      OdbObjectsData::iterTagInfo itTargetTagInfo =
      m_odbObjectsData->tags.info.find(tagInfo->oidTarget);
    
      if (itTargetTagInfo != m_odbObjectsData->tags.info.end()) {
        { // lock
          std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.tags);
          ++itTargetTagInfo->second.reachability;
        }
      }
    }
    default:
      break;
  }
}

/**
 * WorkerReachCounter::setReachabilityFromCommits
 * Adds reachability counter where commits point (parents and tree).
 */
void WorkerReachCounter::setReachabilityFromCommits(void *objectInfo)
{
  const OdbObjectsData::CommitInfo *commitInfo =
    static_cast<const OdbObjectsData::CommitInfo *>(objectInfo);
  const size_t numParents = commitInfo->parents.size();

  // set parents' reachability
  for (size_t i = 0; i < numParents; ++i) {
    OdbObjectsData::iterCommitInfo itParentCommitInfo =
      m_odbObjectsData->commits.info.find(commitInfo->parents.at(i));
    
    if (itParentCommitInfo != m_odbObjectsData->commits.info.end()) {
      { // lock
        std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.commits);
        ++itParentCommitInfo->second.reachability;
      }
    }
  }

  // add 1 to its tree's reachability
  OdbObjectsData::iterTreeInfo itCommitTreeInfo =
    m_odbObjectsData->trees.info.find(commitInfo->oidTree);
  
  if (itCommitTreeInfo != m_odbObjectsData->trees.info.end()) {
    { // lock
      std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.trees);
      ++itCommitTreeInfo->second.reachability;
    }
  }
}

/**
 * WorkerReachCounter::setReachabilityFromTrees
 * Adds reachability counter where tree entries point (blobs and other trees).
 */
void WorkerReachCounter::setReachabilityFromTrees(void *objectInfo)
{
  const OdbObjectsData::TreeInfoAndStats *treeInfo =
    static_cast<const OdbObjectsData::TreeInfoAndStats *>(objectInfo);

  // set entry blobs' reachability
  for (auto &blob : treeInfo->entryBlobs) {
    OdbObjectsData::iterBlobInfo itBlobInfo = m_odbObjectsData->blobs.info.find(blob);
    
    if (itBlobInfo != m_odbObjectsData->blobs.info.end()) {
      { // lock
        std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.blobs);
        ++itBlobInfo->second.reachability;
      }
    }
  }

  // set entry trees' reachability
  for (auto &treeNameLen : treeInfo->entryTreesNameLen) {
    OdbObjectsData::iterTreeInfo itTreeInfo = m_odbObjectsData->trees.info.find(treeNameLen.first);
    
    if (itTreeInfo != m_odbObjectsData->trees.info.end()) {
      { // lock
        std::lock_guard<std::mutex> lock(m_odbObjectsData->infoMutex.trees);
        ++itTreeInfo->second.reachability;
      }
    }
  }
}

/**
 * forEachOdbCb. Callback for git_odb_foreach.
 * Returns GIT_OK on success; GIT_EUSER otherwise
 */
static int forEachOdbCb(const git_oid *oid, void *payloadToCast)
{
  WorkerPool<WorkerStoreOdbData,WorkItemOid> *workerPool =
    static_cast<WorkerPool<WorkerStoreOdbData,WorkItemOid>*>(payloadToCast);

  // Must insert copies of oid, since the pointers might not survive until worker thread picks it up
  workerPool->InsertWork(std::make_unique<WorkItemOid>(*oid));

  // check there were no problems inserting work
  if (workerPool->Status() != WPStatus::kOk) {
    return GIT_EUSER;
  }

  return GIT_OK;
}

/**
 * \class RepoAnalysis
 * Class to analyse and hold repository statistics
 */
class RepoAnalysis
{
public:
  static constexpr unsigned int kMinThreads = 4;

  explicit RepoAnalysis(git_repository *repo)
    : m_repo(repo) {}
  ~RepoAnalysis() = default;
  RepoAnalysis(const RepoAnalysis &other) = delete;
  RepoAnalysis(RepoAnalysis &&other) = delete;
  RepoAnalysis& operator=(const RepoAnalysis &other) = delete;
  RepoAnalysis& operator=(RepoAnalysis &&other) = delete;

  int Analyze();
  Napi::Object StatisticsToJS(Napi::Env env) const;

private:
  // stage 1 methods: store data from repository (with threads)
  int storeObjectsInfo();
  int storeAndCountRefs();
  // stage 2 methods: count reachability of each object (with threads)
  // NOTE: we need this stage, since so far libgit2 doesn't provide unreachable objects
  bool setObjectsReachability();
  void setReachabilityFromRefs();
  void setUnreachables();
  // stage 3 methods: prune unreachable oids
  void pruneUnreachables();
  void pruneUnreachableTags();
  void pruneUnreachableCommits();
  void pruneUnreachableTrees();
  void pruneUnreachableBlobs();
  // stage 4 methods: repositorySize and biggestObjects
  void statsCountAndMax();
  // stage 5 methods: historyStructure and biggestCheckouts
  bool statsHistoryAndBiggestCheckouts();
  bool calculateBiggestCheckouts();
  OdbObjectsData::iterTreeInfo calculateTreeStatistics(const std::string &oidTree);
  bool calculateMaxTagDepth();
  OdbObjectsData::iterTagInfo calculateTagDepth(const std::string &oidTag);
  // methods to return the statistics calculated
  void fillOutStatistics();
  Napi::Object repositorySizeToJS(Napi::Env env) const;
  Napi::Object biggestObjectsToJS(Napi::Env env) const;
  Napi::Object historyStructureToJS(Napi::Env env) const;
  Napi::Object biggestCheckoutsToJS(Napi::Env env) const;

  git_repository *m_repo {nullptr};
  Statistics m_statistics {};
  // odb objects info to build while reading the object database by each thread
  OdbObjectsData m_odbObjectsData {};
  // oid and type of peeled references
  std::unordered_map<std::string, git_object_t> m_peeledRefs {};
};

/**
 * RepoAnalysis::Analyze
 * To obtain the final result, the whole process is run in different stages.
 * If a stage leverages threads via a worker pool, the worker pool is created
 * and we wait until all the threads are done to continue with the next stage.
 */
int RepoAnalysis::Analyze()
{
  int errorCode {GIT_OK};

  // stage 1
  if ((errorCode = storeObjectsInfo() != GIT_OK)) {
    return errorCode;
  }

  // stage 2
  if (!setObjectsReachability()) {
    return GIT_EUSER;
  }

  // stage 3
  pruneUnreachables();

  // stage 4
  statsCountAndMax();

  // stage 5
  if (!statsHistoryAndBiggestCheckouts()) {
    return GIT_EUSER;
  }

  fillOutStatistics();

  return errorCode;
}

/**
 * RepoAnalysis::StatisticsToJS
 */
Napi::Object RepoAnalysis::StatisticsToJS(Napi::Env env) const
{
  Napi::Object result = Napi::Object::New(env);

  Napi::Object repositorySize = repositorySizeToJS(env);
  result.Set("repositorySize", repositorySize);

  Napi::Object biggestObjects = biggestObjectsToJS(env);
  result.Set("biggestObjects", biggestObjects);

  Napi::Object historyStructure = historyStructureToJS(env);
  result.Set("historyStructure", historyStructure);

  Napi::Object biggestCheckouts = biggestCheckoutsToJS(env);
  result.Set("biggestCheckouts", biggestCheckouts);

  return result;
}

/**
 * RepoAnalysis::storeObjectsInfo
 * Store information from read odb objects.
 * Starts building a container which eventually will hold only reachable objects.
 * Leverages threads via a worker pool <WorkerStoreOdbData,WorkItemOid>.
 */
int RepoAnalysis::storeObjectsInfo()
{
  int errorCode {GIT_OK};

  // get the objects database
  git_odb *odb {nullptr};
  if ((errorCode = git_repository_odb(&odb, m_repo)) != GIT_OK) {
    return errorCode;
  }

  // initialize workers for the worker pool
  const std::string repoPath = git_repository_path(m_repo);
  const unsigned int numThreads =
    std::max<unsigned int>(std::thread::hardware_concurrency(), static_cast<unsigned int>(kMinThreads));

  std::vector< std::shared_ptr<WorkerStoreOdbData> > workers {};
  for (unsigned int i = 0; i < numThreads; ++i) {
    workers.emplace_back(std::make_shared<WorkerStoreOdbData>(repoPath, &m_odbObjectsData));
  }

  // initialize worker pool
  WorkerPool<WorkerStoreOdbData,WorkItemOid> workerPool {};  
  workerPool.Init(workers);

  if ((errorCode = git_odb_foreach(odb, forEachOdbCb, &workerPool)) != GIT_OK) {
    workerPool.Shutdown();
    git_odb_free(odb);
    return errorCode;
  }

  // main thread will work on the refs while waiting for the threads to finish
  if ((errorCode = storeAndCountRefs() != GIT_OK)) {
    workerPool.Shutdown();
    git_odb_free(odb);
    return errorCode;
  }

  // wait for the threads to finish and shutdown the work pool
  workerPool.Shutdown();

  // check there were no problems during execution
  if (workerPool.Status() != WPStatus::kOk) {
    git_odb_free(odb);
    return GIT_EUSER;
  }

  git_odb_free(odb);

  return errorCode;
}

/**
 * RepoAnalysis::storeAndCountRefs
 * Stores the oid and type of peeled references.
 * Also counts total references.
 */
int RepoAnalysis::storeAndCountRefs()
{
  int errorCode {GIT_OK};
  git_strarray ref_list;

  // count refs
  if ((errorCode = git_reference_list(&ref_list, m_repo)) != GIT_OK) {
    return errorCode;
  }
  m_statistics.repositorySize.references.count = ref_list.count;

  // store refs info
  for (size_t i = 0; i < ref_list.count; ++i)
  {
    // lookup ref
    git_reference *ref {nullptr};
    const int refLookupError = git_reference_lookup(&ref, m_repo, ref_list.strings[i]);
    if (refLookupError == GIT_ENOTFOUND || refLookupError == GIT_EINVALIDSPEC) {
      continue;
    }
    else if (refLookupError != GIT_OK) {
      git_strarray_dispose(&ref_list);
      return refLookupError;
    }

    // obtain peeled oid of the reference
    bool found_oid = false;
    git_oid oid_ref;
    switch (git_reference_type(ref))
    {
      case GIT_REFERENCE_DIRECT:
        git_oid_cpy(&oid_ref, git_reference_target(ref));
        found_oid = true;
        break;

      case GIT_REFERENCE_SYMBOLIC:
      {
        git_reference *ref_resolved {nullptr};
        if ((errorCode = git_reference_resolve(&ref_resolved, ref)) != GIT_OK) {
          git_reference_free(ref);
          git_strarray_dispose(&ref_list);
          return errorCode;
        }
        git_oid_cpy(&oid_ref, git_reference_target(ref_resolved));
        found_oid = true;
        git_reference_free(ref_resolved);
      }
        break;

      default:
        break;
    }

    // store object's oid and type
    if (found_oid)
    {
      git_object *target {nullptr};
      if ((errorCode = git_object_lookup(&target, m_repo, &oid_ref, GIT_OBJECT_ANY)) != GIT_OK) {
        git_reference_free(ref);
        git_strarray_dispose(&ref_list);
        return errorCode;
      }

      m_peeledRefs.emplace(std::make_pair(
        std::string(reinterpret_cast<const char *>(oid_ref.id), GIT_OID_RAWSZ),
        git_object_type(target)));

      git_object_free(target);
    }
    git_reference_free(ref);
  }
  git_strarray_dispose(&ref_list);

  return errorCode;
}

/**
 * RepoAnalysis::setObjectsReachability
 * Leverages threads via a worker pool <WorkerReachCounter,WorkItemOidStrType> to
 * set reachability from tags, commits, and trees.
 * NOTE: the worker pool leveraged in this method runs at a different stage than the
 * worker pool leveraged in previous stages, meaning they do not run at the same time, hence
 * access to 'm_odbObjectsData->....info' won't suffer from a data race.
 * NOTE: performance didn't improve leveraging threads for adding objects to unreachables container.
 * \return false if the workerPool finished with errors; true otherwise
 */
bool RepoAnalysis::setObjectsReachability()
{
  // references are not objects, hence they won't be sent to the worker threads
  setReachabilityFromRefs();

  const unsigned int numThreads =
    std::max<unsigned int>(std::thread::hardware_concurrency(), static_cast<unsigned int>(kMinThreads));
  std::vector< std::shared_ptr<WorkerReachCounter> > workers {};
  for (unsigned int i = 0; i < numThreads; ++i) {
    workers.emplace_back(std::make_shared<WorkerReachCounter>(&m_odbObjectsData));
  }

  // initialize worker pool
  WorkerPool<WorkerReachCounter,WorkItemOidStrType> workerPool {};  
  workerPool.Init(workers);

  // NOTE: avoid queueing same type of objects in a row, so that different mutex can be used concurrently
  uint8_t workInserted {0};
  OdbObjectsData::iterTagInfo itTagInfo = m_odbObjectsData.tags.info.begin();
  OdbObjectsData::iterCommitInfo itCommitInfo = m_odbObjectsData.commits.info.begin();
  OdbObjectsData::iterTreeInfo itTreeInfo = m_odbObjectsData.trees.info.begin();
  do {
    workInserted = 0;
    // insert tag
    if (itTagInfo != m_odbObjectsData.tags.info.end()) {
      workerPool.InsertWork(std::make_unique<WorkItemOidStrType>(&itTagInfo->second, GIT_OBJECT_TAG));
      ++itTagInfo;
      ++workInserted;
    }
    // insert commmit
    if (itCommitInfo != m_odbObjectsData.commits.info.end()) {
      workerPool.InsertWork(std::make_unique<WorkItemOidStrType>(&itCommitInfo->second, GIT_OBJECT_COMMIT));
      ++itCommitInfo;
      ++workInserted;
    }
    // insert tree
    if (itTreeInfo != m_odbObjectsData.trees.info.end()) {
      workerPool.InsertWork(std::make_unique<WorkItemOidStrType>(&itTreeInfo->second, GIT_OBJECT_TREE));
      ++itTreeInfo;
      ++workInserted;
    }
    // blobs do not reach to any other object, hence no need to process them
  } while (workInserted);

  // wait for the threads to finish and shutdown the work pool
  workerPool.Shutdown();

  // check there were no problems during execution
  if (workerPool.Status() != WPStatus::kOk) {
    return false;
  }

  setUnreachables();

  return true;
}

/**
 * RepoAnalysis::setReachabilityFromRefs
 * Adds reachability counter where peeled refs point (normally a commit or a tag).
  */
void RepoAnalysis::setReachabilityFromRefs()
{
  for (const auto &ref : m_peeledRefs) {
    switch (ref.second) {
      case GIT_OBJECT_COMMIT:
      {
        OdbObjectsData::iterCommitInfo itCommitInfo =
        m_odbObjectsData.commits.info.find(ref.first);
      
        if (itCommitInfo != m_odbObjectsData.commits.info.end()) {
          ++itCommitInfo->second.reachability;
        }
      }
        break;
      case GIT_OBJECT_TREE:
      {
        OdbObjectsData::iterTreeInfo itTreeInfo =
        m_odbObjectsData.trees.info.find(ref.first);
      
        if (itTreeInfo != m_odbObjectsData.trees.info.end()) {
          ++itTreeInfo->second.reachability;
        }
      }
        break;
      case GIT_OBJECT_BLOB:
      {
        OdbObjectsData::iterBlobInfo itBlobInfo =
        m_odbObjectsData.blobs.info.find(ref.first);
      
        if (itBlobInfo != m_odbObjectsData.blobs.info.end()) {
          ++itBlobInfo->second.reachability;
        }
      }
        break;
      case GIT_OBJECT_TAG:
      {
        OdbObjectsData::iterTagInfo itTagInfo =
        m_odbObjectsData.tags.info.find(ref.first);
      
        if (itTagInfo != m_odbObjectsData.tags.info.end()) {
          ++itTagInfo->second.reachability;
        }
      }
        break;
      default:
        break;
    }
  }
}

/**
 * RepoAnalysis::setUnreachables
 * After setting reachability, we add the unreached objects to their unreachables container.
 */
void RepoAnalysis::setUnreachables()
{
  for (const auto &tag : m_odbObjectsData.tags.info) {
    if (!tag.second.reachability) {
      m_odbObjectsData.tags.unreachables.emplace(tag.first);
    }
  }
  for (const auto &commit : m_odbObjectsData.commits.info) {
    if (!commit.second.reachability) {
      m_odbObjectsData.commits.unreachables.emplace(commit.first);
    }
  }
  for (const auto &tree : m_odbObjectsData.trees.info) {
    if (!tree.second.reachability) {
      m_odbObjectsData.trees.unreachables.emplace(tree.first);
    }
  }
  for (const auto &blob : m_odbObjectsData.blobs.info) {
    if (!blob.second.reachability) {
      m_odbObjectsData.blobs.unreachables.emplace(blob.first);
    }
  }
}

/**
 * RepoAnalysis::pruneUnreachables
 * Removes from their containers the unreachable objects.
 * Decreases reachability of the objects they can reach.
  */
void RepoAnalysis::pruneUnreachables()
{
  // NOTE: order is important here, since each method prunes its own objects, but
  // only decreases reachability of the objects connected to it; and those
  // connected objects will be checked and pruned afterwards.
  pruneUnreachableTags();
  pruneUnreachableCommits();
  pruneUnreachableTrees();
  pruneUnreachableBlobs();
}

/**
 * RepoAnalysis::pruneUnreachableTags
 * Prune tags and their chained tags if they become unreachable.
 * Also decreases reachability of targets.
  */
void RepoAnalysis::pruneUnreachableTags()
{
  while (!m_odbObjectsData.tags.unreachables.empty()) {
    std::unordered_set<std::string> newUnreachables {};

    // erase unreachable tags
    for (OdbObjectsData::iterUnreachable itTagUnrch = m_odbObjectsData.tags.unreachables.begin();
      itTagUnrch != m_odbObjectsData.tags.unreachables.end(); ++itTagUnrch)
    {
      OdbObjectsData::iterTagInfo itTagInfo = m_odbObjectsData.tags.info.find(*itTagUnrch);
    
      if (itTagInfo != m_odbObjectsData.tags.info.end()) {
        const std::string &oidTarget = itTagInfo->second.oidTarget;
        switch (itTagInfo->second.typeTarget) {
          case GIT_OBJECT_TAG:
          {
            // if target is another tag, add it to newUnreachables
            OdbObjectsData::iterTagInfo itTargetTagInfo = m_odbObjectsData.tags.info.find(oidTarget);
            if (itTargetTagInfo != m_odbObjectsData.tags.info.end()) {
              if (--itTargetTagInfo->second.reachability == OdbObjectsData::kUnreachable) {
                newUnreachables.emplace(itTargetTagInfo->first);
              }
            }
          }
            break;
          case GIT_OBJECT_COMMIT:
          {
            OdbObjectsData::iterCommitInfo itCommitInfo = m_odbObjectsData.commits.info.find(oidTarget);
            if (itCommitInfo != m_odbObjectsData.commits.info.end()) {
              if (--itCommitInfo->second.reachability == OdbObjectsData::kUnreachable) {
                m_odbObjectsData.commits.unreachables.emplace(itCommitInfo->first);
              }
            }
          }
            break;
          case GIT_OBJECT_TREE:
          {
            OdbObjectsData::iterTreeInfo itTreeInfo = m_odbObjectsData.trees.info.find(oidTarget);
            if (itTreeInfo != m_odbObjectsData.trees.info.end()) {
              if (--itTreeInfo->second.reachability == OdbObjectsData::kUnreachable) {
                m_odbObjectsData.trees.unreachables.emplace(itTreeInfo->first);
              }
            }
          }
            break;
          case GIT_OBJECT_BLOB:
          {
            OdbObjectsData::iterBlobInfo itBlobInfo = m_odbObjectsData.blobs.info.find(oidTarget);
            if (itBlobInfo != m_odbObjectsData.blobs.info.end()) {
              if (--itBlobInfo->second.reachability == OdbObjectsData::kUnreachable) {
                m_odbObjectsData.blobs.unreachables.emplace(itBlobInfo->first);
              }
            }
          }
            break;
          default:
            break;
        }
        // erase tag from the tag's container
        m_odbObjectsData.tags.info.erase(itTagInfo);
      }
    }
    // set new unreachable tags
    m_odbObjectsData.tags.unreachables = std::move(newUnreachables);
  }
}

/**
 * RepoAnalysis::pruneUnreachableCommits
 * Prune commits and decrease reachability of their associated trees.
  */
void RepoAnalysis::pruneUnreachableCommits()
{
  while (!m_odbObjectsData.commits.unreachables.empty()) {
    std::unordered_set<std::string> newUnreachables {};

    // erase unreachable commits
    for (OdbObjectsData::iterUnreachable itCommitUnrch = m_odbObjectsData.commits.unreachables.begin();
      itCommitUnrch != m_odbObjectsData.commits.unreachables.end(); ++itCommitUnrch)
    {
      OdbObjectsData::iterCommitInfo itCommitInfo = m_odbObjectsData.commits.info.find(*itCommitUnrch);
    
      if (itCommitInfo != m_odbObjectsData.commits.info.end())
      {
        // decrease commit's parents reachability and add them as newUnreachable
        const size_t numParents = itCommitInfo->second.parents.size();
        for (size_t i = 0; i < numParents; ++i) {
          OdbObjectsData::iterCommitInfo itParentCommitInfo =
            m_odbObjectsData.commits.info.find(itCommitInfo->second.parents.at(i));
          
          if (itParentCommitInfo != m_odbObjectsData.commits.info.end()) {
            if (--itParentCommitInfo->second.reachability == OdbObjectsData::kUnreachable) {
              newUnreachables.emplace(itParentCommitInfo->first);
            }
          }
        }
        // decrease reachability of the commit's tree
        OdbObjectsData::iterTreeInfo itTreeInfo =
          m_odbObjectsData.trees.info.find(itCommitInfo->second.oidTree);
        if (itTreeInfo != m_odbObjectsData.trees.info.end()) {
          if (--itTreeInfo->second.reachability == OdbObjectsData::kUnreachable) {
            m_odbObjectsData.trees.unreachables.emplace(itTreeInfo->first);
          }
        }
        // erase commit from the commit's container
        m_odbObjectsData.commits.info.erase(itCommitInfo);
      }
    }
    // set new unreachable commits
    m_odbObjectsData.commits.unreachables = std::move(newUnreachables);
  }
}

/**
 * RepoAnalysis::pruneUnreachableTrees
 * Prune unreachable trees and decrement reachability of their entries.
  */
void RepoAnalysis::pruneUnreachableTrees()
{
  while (!m_odbObjectsData.trees.unreachables.empty()) {
    std::unordered_set<std::string> newUnreachables {};

    // erase unreachable trees
    for (OdbObjectsData::iterUnreachable itTreeUnrch = m_odbObjectsData.trees.unreachables.begin();
      itTreeUnrch != m_odbObjectsData.trees.unreachables.end(); ++itTreeUnrch)
    {
      OdbObjectsData::iterTreeInfo itTreeInfo = m_odbObjectsData.trees.info.find(*itTreeUnrch);
    
      if (itTreeInfo != m_odbObjectsData.trees.info.end()) {
        // decrease reachability of the entry blobs
        for (auto &blob : itTreeInfo->second.entryBlobs) {
          OdbObjectsData::iterBlobInfo itEntryBlobInfo = m_odbObjectsData.blobs.info.find(blob);
          if (itEntryBlobInfo != m_odbObjectsData.blobs.info.end()) {
            if (--itEntryBlobInfo->second.reachability == OdbObjectsData::kUnreachable) {
              m_odbObjectsData.blobs.unreachables.emplace(blob);
            }
          }
        }
        // decrease reachability of the entry trees and add them as newUnreachables
        for (auto &treeNameLen : itTreeInfo->second.entryTreesNameLen) {
          OdbObjectsData::iterTreeInfo itEntryTreeInfo =
            m_odbObjectsData.trees.info.find(treeNameLen.first);
          if (itEntryTreeInfo != m_odbObjectsData.trees.info.end()) {
            if (--itEntryTreeInfo->second.reachability == OdbObjectsData::kUnreachable) {
              newUnreachables.emplace(treeNameLen.first);
            }
          }
        }
        // erase tree from the tree's container
        m_odbObjectsData.trees.info.erase(itTreeInfo);
      }
    }
    // set new unreachable trees
    m_odbObjectsData.trees.unreachables = std::move(newUnreachables);
  }
}

/**
 * RepoAnalysis::pruneUnreachableBlobs
 * Rremoves unreachable blobs from their container.
  */
void RepoAnalysis::pruneUnreachableBlobs()
{
  for (OdbObjectsData::iterUnreachable itBlobUnrch = m_odbObjectsData.blobs.unreachables.begin();
    itBlobUnrch != m_odbObjectsData.blobs.unreachables.end(); ++itBlobUnrch)
  {
    m_odbObjectsData.blobs.info.erase(*itBlobUnrch);
  }
}

/**
 * RepoAnalysis::statsCountAndMax
 * Statistics for repositorySize (count objects) and biggestObjects (get maximum of them).
 * Also builds the commits graph.
 * NOTE: better results achieved not leveraging threads.
 */
void RepoAnalysis::statsCountAndMax()
{
  // commits
  for (auto &info : m_odbObjectsData.commits.info) {
    OdbObjectsData::CommitInfo &commitInfo = info.second;
    const size_t objectSize = commitInfo.size;

    m_odbObjectsData.commits.totalSize += objectSize;
    m_odbObjectsData.commits.maxSize = std::max<size_t>(m_odbObjectsData.commits.maxSize, objectSize);
    m_odbObjectsData.commits.maxParents = std::max<size_t>(
      m_odbObjectsData.commits.maxParents, commitInfo.parents.size());

    // build commit's graph
    m_odbObjectsData.commits.graph.AddNode(info.first, commitInfo.parents);
  }
  // trees
  for (auto &info : m_odbObjectsData.trees.info) {
    OdbObjectsData::TreeInfoAndStats &treeInfo = info.second;
    const size_t numEntries = treeInfo.numEntries;
    const size_t objectSize = treeInfo.size;

    m_odbObjectsData.trees.totalSize += objectSize;
    m_odbObjectsData.trees.totalEntries += numEntries;
    m_odbObjectsData.trees.maxEntries = std::max<size_t>(m_odbObjectsData.trees.maxEntries, numEntries);
  }
  // blobs
  for (auto &info : m_odbObjectsData.blobs.info) {
    OdbObjectsData::BlobInfo &blobInfo = info.second;
    const size_t objectSize = blobInfo.size;

    m_odbObjectsData.blobs.totalSize += objectSize;
    m_odbObjectsData.blobs.maxSize = std::max<size_t>(m_odbObjectsData.blobs.maxSize, objectSize);
  }
  // no need to process tags here (we already have the count)
}

/**
 * RepoAnalysis::statsHistoryAndBiggestCheckouts
 * Statistics for historyStructure and biggestCheckouts.
 * \return true if success; false if something went wrong.
 */
bool RepoAnalysis::statsHistoryAndBiggestCheckouts()
{
  if (!calculateBiggestCheckouts()) {
    return false;
  }

  if (!calculateMaxTagDepth()) {
    return false;
  }

  // calculate max commit history depth
  m_statistics.historyStructure.maxDepth = m_odbObjectsData.commits.graph.CalculateMaxDepth();

  return true;
}

/**
 * RepoAnalysis::calculateBiggestCheckouts
 * 
 * Once threads have collected data from objects and unreachable objects
 * have been pruned, biggest checkouts can be calculated.
 * Threads have already collected partial non-recursive tree statistics.
 * \return true if success; false if something went wrong.
 */
bool RepoAnalysis::calculateBiggestCheckouts()
{
  for (auto &commitInfo : m_odbObjectsData.commits.info)
  {
    // calculate this commit's data
    const std::string &commitOidTree = commitInfo.second.oidTree;

    OdbObjectsData::iterTreeInfo itTreeInfo {};
    if ((itTreeInfo = calculateTreeStatistics(commitOidTree)) == m_odbObjectsData.trees.info.end()) {
      return false;
    }

    // update biggestCheckouts data
    OdbObjectsData::TreeInfoAndStats &treeInfoAndStats = itTreeInfo->second;
    m_statistics.biggestCheckouts.numDirectories = std::max<size_t>(
      m_statistics.biggestCheckouts.numDirectories, treeInfoAndStats.stats.numDirectories);
    m_statistics.biggestCheckouts.totalFileSize = std::max<size_t>(
      m_statistics.biggestCheckouts.totalFileSize, treeInfoAndStats.stats.totalFileSize);
    m_statistics.biggestCheckouts.maxPathDepth = std::max<size_t>(
      m_statistics.biggestCheckouts.maxPathDepth, treeInfoAndStats.stats.maxPathDepth);
    m_statistics.biggestCheckouts.numFiles = std::max<size_t>(
      m_statistics.biggestCheckouts.numFiles, treeInfoAndStats.stats.numFiles);
    m_statistics.biggestCheckouts.maxPathLength = std::max<size_t>(
      m_statistics.biggestCheckouts.maxPathLength, treeInfoAndStats.stats.maxPathLength);
    m_statistics.biggestCheckouts.numSymlinks = std::max<size_t>(
      m_statistics.biggestCheckouts.numSymlinks, treeInfoAndStats.stats.numSymlinks);
    m_statistics.biggestCheckouts.numSubmodules = std::max<size_t>(
      m_statistics.biggestCheckouts.numSubmodules, treeInfoAndStats.stats.numSubmodules);
  }

  return true;
}

/**
 * RepoAnalysis::calculateTreeStatistics
 * 
 * Calculates tree statistics recursively, considering individual tree's statistics
 * have already been calculated.
 * The maximum number of recursive calls depend directly on the maximum path depth of
 * the repository. For instance, the linux repository have a maximum path depth of 13,
 * so it should be safe against stack overflow.
 * Returns an iterator to the tree info container, or to end if something went wrong.
 */
OdbObjectsData::iterTreeInfo RepoAnalysis::calculateTreeStatistics(const std::string &oidTree)
{
  OdbObjectsData::iterTreeInfo itTreeInfo = m_odbObjectsData.trees.info.find(oidTree);
  if (itTreeInfo == m_odbObjectsData.trees.info.end()) {
    return itTreeInfo;
  }

  OdbObjectsData::TreeInfoAndStats &treeInfoAndStats = itTreeInfo->second;

  // prune recursivity
  if (treeInfoAndStats.statsDone) {
    return itTreeInfo;
  }

  ++treeInfoAndStats.stats.numDirectories;
  ++treeInfoAndStats.stats.maxPathDepth;
  // the following partial statistics have also been calculated in previous stage with threads:
  // - treeInfoAndStats.stats.numFiles
  // - treeInfoAndStats.stats.maxPathLength
  // - treeInfoAndStats.stats.numSymLinks
  // - treeInfoAndStats.stats.numSubmodules

  // totalFileSize
  OdbObjectsData::iterBlobInfo itBlobInfo {};
  for (auto &oidBlob : treeInfoAndStats.entryBlobs)
  {
    if ((itBlobInfo = m_odbObjectsData.blobs.info.find(oidBlob)) == m_odbObjectsData.blobs.info.end()) {
      return m_odbObjectsData.trees.info.end(); // to let the caller know that something went wrong
    }

    treeInfoAndStats.stats.totalFileSize += itBlobInfo->second.size;
  }

  // recursively into subtrees
  for (const auto &subTreeNameLen : treeInfoAndStats.entryTreesNameLen)
  {
    OdbObjectsData::iterTreeInfo itSubTreeInfo {};
    if ((itSubTreeInfo = calculateTreeStatistics(subTreeNameLen.first)) ==
      m_odbObjectsData.trees.info.end()) {
      return itSubTreeInfo;
    }

    OdbObjectsData::TreeInfoAndStats &subTreeInfoAndStats = itSubTreeInfo->second;
    treeInfoAndStats.stats.numDirectories += subTreeInfoAndStats.stats.numDirectories;
    treeInfoAndStats.stats.maxPathDepth = std::max<size_t>(treeInfoAndStats.stats.maxPathDepth,
      subTreeInfoAndStats.stats.maxPathDepth + 1);
    treeInfoAndStats.stats.maxPathLength = std::max<size_t>(treeInfoAndStats.stats.maxPathLength,
      subTreeNameLen.second + 1 + subTreeInfoAndStats.stats.maxPathLength);
    treeInfoAndStats.stats.numFiles += subTreeInfoAndStats.stats.numFiles;
    treeInfoAndStats.stats.totalFileSize += subTreeInfoAndStats.stats.totalFileSize;
    treeInfoAndStats.stats.numSymlinks += subTreeInfoAndStats.stats.numSymlinks;
    treeInfoAndStats.stats.numSubmodules += subTreeInfoAndStats.stats.numSubmodules;
  }

  treeInfoAndStats.statsDone = true;

  return itTreeInfo;
}

/**
 * RepoAnalysis::calculateMaxTagDepth
 * \return true if success; false if something went wrong.
 */
bool RepoAnalysis::calculateMaxTagDepth()
{
  for (auto &tag : m_odbObjectsData.tags.info)
  {
    OdbObjectsData::iterTagInfo itTagInfo {};
    if ((itTagInfo = calculateTagDepth(tag.first)) == m_odbObjectsData.tags.info.end()) {
      return false;
    }

    // update maxTagDepth
    OdbObjectsData::TagInfo &tagInfo = itTagInfo->second;
    m_statistics.historyStructure.maxTagDepth = std::max<uint32_t>(
      m_statistics.historyStructure.maxTagDepth, tagInfo.depth);
  }

  return true;
}

/**
 * RepoAnalysis::calculateTagDepth
 * 
 * Calculates recursively the tag depth of the oidTag passed as a parameter.
 * Returns an iterator to the tag info container, or to end if something went wrong.
 */
OdbObjectsData::iterTagInfo RepoAnalysis::calculateTagDepth(const std::string &oidTag)
{
  OdbObjectsData::iterTagInfo itTagInfo = m_odbObjectsData.tags.info.find(oidTag);
  if (itTagInfo == m_odbObjectsData.tags.info.end()) {
    return itTagInfo;
  }

  OdbObjectsData::TagInfo &tagInfo = itTagInfo->second;

  // prune recursivity
  if (tagInfo.depth != OdbObjectsData::TagInfo::kUnsetDepth) {
    return itTagInfo;
  }

  ++tagInfo.depth;

  if (tagInfo.typeTarget == GIT_OBJECT_TAG)
  {
    OdbObjectsData::iterTagInfo itChainedTagInfo {};
    if ((itChainedTagInfo = calculateTagDepth(tagInfo.oidTarget)) == m_odbObjectsData.tags.info.end()) {
      return itChainedTagInfo;
    }

    OdbObjectsData::TagInfo &chainedTagInfo = itChainedTagInfo->second;
    tagInfo.depth += chainedTagInfo.depth;
  }

  return itTagInfo;
}

/**
 * RepoAnalysis::fillOutStatistics
 */
void RepoAnalysis::fillOutStatistics()
{
  m_statistics.repositorySize.commits.count = m_odbObjectsData.commits.info.size();
  m_statistics.repositorySize.commits.size = m_odbObjectsData.commits.totalSize;
  m_statistics.repositorySize.trees.count = m_odbObjectsData.trees.info.size();
  m_statistics.repositorySize.trees.size = m_odbObjectsData.trees.totalSize;
  m_statistics.repositorySize.trees.entries = m_odbObjectsData.trees.totalEntries;
  m_statistics.repositorySize.blobs.count = m_odbObjectsData.blobs.info.size();
  m_statistics.repositorySize.blobs.size = m_odbObjectsData.blobs.totalSize;
  m_statistics.repositorySize.annotatedTags.count = m_odbObjectsData.tags.info.size();

  m_statistics.biggestObjects.commits.maxSize = m_odbObjectsData.commits.maxSize;
  m_statistics.biggestObjects.commits.maxParents = m_odbObjectsData.commits.maxParents;
  m_statistics.biggestObjects.trees.maxEntries = m_odbObjectsData.trees.maxEntries;
  m_statistics.biggestObjects.blobs.maxSize = m_odbObjectsData.blobs.maxSize;

  // m_statistics.biggestCheckouts have already been filled out while running
}

/**
 * RepoAnalysis::repositorySizeToJS
 */
Napi::Object RepoAnalysis::repositorySizeToJS(Napi::Env env) const
{
  Napi::Object commits = Napi::Object::New(env);
  commits.Set("count", Napi::Number::New(env, m_statistics.repositorySize.commits.count));
  commits.Set("size", Napi::Number::New(env, m_statistics.repositorySize.commits.size));

  Napi::Object trees = Napi::Object::New(env);
  trees.Set("count", Napi::Number::New(env, m_statistics.repositorySize.trees.count));
  trees.Set("size", Napi::Number::New(env, m_statistics.repositorySize.trees.size));
  trees.Set("entries", Napi::Number::New(env, m_statistics.repositorySize.trees.entries));

  Napi::Object blobs = Napi::Object::New(env);
  blobs.Set("count", Napi::Number::New(env, m_statistics.repositorySize.blobs.count));
  blobs.Set("size", Napi::Number::New(env, m_statistics.repositorySize.blobs.size));

  Napi::Object annotatedTags = Napi::Object::New(env);
  annotatedTags.Set("count", Napi::Number::New(env, m_statistics.repositorySize.annotatedTags.count));

  Napi::Object references = Napi::Object::New(env);
  references.Set("count", Napi::Number::New(env, m_statistics.repositorySize.references.count));

  Napi::Object result = Napi::Object::New(env);
  result.Set("commits", commits);
  result.Set("trees", trees);
  result.Set("blobs", blobs);
  result.Set("annotatedTags", annotatedTags);
  result.Set("references", references);

  return result;
}

/**
 * RepoAnalysis::biggestObjectsToJS
 */
Napi::Object RepoAnalysis::biggestObjectsToJS(Napi::Env env) const
{
  Napi::Object commits = Napi::Object::New(env);
  commits.Set("maxSize", Napi::Number::New(env, m_statistics.biggestObjects.commits.maxSize));
  commits.Set("maxParents", Napi::Number::New(env, m_statistics.biggestObjects.commits.maxParents));

  Napi::Object trees = Napi::Object::New(env);
  trees.Set("maxEntries", Napi::Number::New(env, m_statistics.biggestObjects.trees.maxEntries));

  Napi::Object blobs = Napi::Object::New(env);
  blobs.Set("maxSize", Napi::Number::New(env, m_statistics.biggestObjects.blobs.maxSize));

  Napi::Object result = Napi::Object::New(env);
  result.Set("commits", commits);
  result.Set("trees", trees);
  result.Set("blobs", blobs);

  return result;
}

/**
 * RepoAnalysis::historyStructureToJS
 */
Napi::Object RepoAnalysis::historyStructureToJS(Napi::Env env) const
{
  Napi::Object result = Napi::Object::New(env);
  result.Set("maxDepth", Napi::Number::New(env, m_statistics.historyStructure.maxDepth));
  result.Set("maxTagDepth", Napi::Number::New(env, m_statistics.historyStructure.maxTagDepth));

  return result;
}

/**
 * RepoAnalysis::biggestCheckoutsToJS
 */
Napi::Object RepoAnalysis::biggestCheckoutsToJS(Napi::Env env) const
{
  Napi::Object result = Napi::Object::New(env);
  result.Set("numDirectories", Napi::Number::New(env, m_statistics.biggestCheckouts.numDirectories));
  result.Set("maxPathDepth", Napi::Number::New(env, m_statistics.biggestCheckouts.maxPathDepth));
  result.Set("maxPathLength", Napi::Number::New(env, m_statistics.biggestCheckouts.maxPathLength));
  result.Set("numFiles", Napi::Number::New(env, m_statistics.biggestCheckouts.numFiles));
  result.Set("totalFileSize", Napi::Number::New(env, m_statistics.biggestCheckouts.totalFileSize));
  result.Set("numSymlinks", Napi::Number::New(env, m_statistics.biggestCheckouts.numSymlinks));
  result.Set("numSubmodules", Napi::Number::New(env, m_statistics.biggestCheckouts.numSubmodules));

  return result;
}

Napi::Value GitRepository::Statistics(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  StatisticsBaton* baton = new StatisticsBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->repo = GitRepository::Unwrap(info.This().As<Napi::Object>())->GetValue();
  baton->out = static_cast<void *>(new RepoAnalysis(baton->repo));

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  StatisticsWorker *worker = new StatisticsWorker(baton, std::move(callback), cleanupHandles);
  worker->Reference<GitRepository>("repo", info.This().As<Napi::Object>());
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitRepository::StatisticsWorker::AcquireLocks()
{
  nodegit::LockMaster lockMaster(true, baton->repo);

  return lockMaster;
}

void GitRepository::StatisticsWorker::Execute()
{
  git_error_clear();

  RepoAnalysis *repoAnalysis = static_cast<RepoAnalysis *>(baton->out);
  if ((baton->error_code = repoAnalysis->Analyze()) != GIT_OK)
  {
    if (git_error_last()->klass != GIT_ERROR_NONE) {
      baton->error = git_error_dup(git_error_last());
    }

    delete repoAnalysis;
    baton->out = nullptr;
  }
}

void GitRepository::StatisticsWorker::HandleErrorCallback()
{
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  RepoAnalysis *repoAnalysis = static_cast<RepoAnalysis *>(baton->out);
  if (repoAnalysis) {
    delete repoAnalysis;
  }

  delete baton;
}

void GitRepository::StatisticsWorker::HandleOKCallback()
{
  Napi::Env env = Env();

  if (baton->out != NULL)
  {
    RepoAnalysis *repoAnalysis = static_cast<RepoAnalysis *>(baton->out);
    Napi::Object result = repoAnalysis->StatisticsToJS(env);

    delete repoAnalysis;

    napi_value argv[2] = {
      env.Null(),
      result
    };
    callback.Call(env.Undefined(), 2, argv);
  }
  else if (baton->error)
  {
    Napi::Object err;

    if (baton->error->message) {
      err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
    } else {
      err = Napi::Error::New(env, "Method statistics has thrown an error.").Value().As<Napi::Object>();
    }
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "GitRepository.statistics"));
    napi_value argv[1] = {
      err
    };

    callback.Call(env.Undefined(), 1, argv);

    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }
  else if (baton->error_code < 0)
  {
    Napi::Object err = Napi::Error::New(env, "Method statistics has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "GitRepository.statistics"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }
  else
  {
    callback.Call({});
  }

  delete baton;
}
   
/*
     */
Napi::Value GitRepository::SubmoduleCacheAll(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_submodule_cache_all(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

      if (result != GIT_OK) {

        if (git_error_last()->klass != GIT_ERROR_NONE) {
          Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
          return env.Undefined();
        } else {
          Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
          return env.Undefined();
        }
      } // lock master scope end
      return scope.Escape(env.Undefined());
  }
}
   
/*
     */
Napi::Value GitRepository::SubmoduleCacheClear(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_repository_submodule_cache_clear(
          Napi::ObjectWrap<GitRepository>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

      if (result != GIT_OK) {

        if (git_error_last()->klass != GIT_ERROR_NONE) {
          Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
          return env.Undefined();
        } else {
          Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
          return env.Undefined();
        }
      } // lock master scope end
      return scope.Escape(env.Undefined());
  }
}
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitRepositoryTraits>;
 