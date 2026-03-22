// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/filter.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/filter_source.h"
#include "bungit_wrapper.cc"

  #include "../include/repository.h"
  #include "../include/oid.h"
 
#include <iostream>

using namespace std;

  GitFilterSource::~GitFilterSource() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                      }

  void GitFilterSource::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "FilterSource", {
          InstanceMethod("repo", &GitFilterSource::Repo, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("path", &GitFilterSource::Path, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("filemode", &GitFilterSource::Filemode, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("id", &GitFilterSource::Id, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("mode", &GitFilterSource::Mode, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("flags", &GitFilterSource::Flags, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitFilterSource::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitFilterSource::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitFilterSource::Template", constructor_template);
    target.Set(Napi::String::New(env, "FilterSource"), constructor_template);
  }

       // NOTE you may need to occasionally rebuild this method by calling the generators
// if major changes are made to the templates / generator.

// Due to some garbage collection issues related to submodules and git_filters, we need to clone the repository
// pointer before giving it to a user.

/*
 * @param Repository callback
 */
Napi::Value GitFilterSource::Repo(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  RepoBaton *baton = new RepoBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->src = GitFilterSource::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  RepoWorker *worker = new RepoWorker(baton, std::move(callback), cleanupHandles);

  worker->Reference<GitFilterSource>("src", info.This().As<Napi::Object>());

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitFilterSource::RepoWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->src);
  return lockMaster;
}

void GitFilterSource::RepoWorker::Execute() {
  git_error_clear();

  git_repository *repo = git_filter_source_repo(baton->src);
  baton->error_code = git_repository_open(&repo, git_repository_path(repo));

  if (baton->error_code == GIT_OK) {
    baton->out = repo;
  } else if (git_error_last()->klass != GIT_ERROR_NONE) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitFilterSource::RepoWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  git_repository_free(baton->out);

  delete baton;
}

void GitFilterSource::RepoWorker::HandleOKCallback() {
  Napi::Env env = Env();
  if (baton->error_code == GIT_OK) {
    Napi::Value to;

    if (baton->out != NULL) {
      to = GitRepository::New(env, baton->out, true);
    } else {
      to = env.Null();
    }

    napi_value argv[2] = {env.Null(), to};
    callback.Call(env.Undefined(), 2, argv);
  } else {
    if (baton->error) {
      Napi::Object err;
      if (baton->error->message) {
        err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
      } else {
        err = Napi::Error::New(env, "Method repo has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set("errno", Napi::Number::New(env, baton->error_code));
      err.Set("errorFunction", Napi::String::New(env, "FilterSource.repo"));
      napi_value argv[1] = {err};
      callback.Call(env.Undefined(), 1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      Napi::Object err = Napi::Error::New(env, "Method repo has thrown an error.").Value().As<Napi::Object>();
      err.Set("errno", Napi::Number::New(env, baton->error_code));
      err.Set("errorFunction", Napi::String::New(env, "FilterSource.repo"));
      napi_value argv[1] = {err};
      callback.Call(env.Undefined(), 1, argv);
    } else {
      callback.Call({});
    }
  }

  delete baton;
}

   
/*
     * @return String  result    */
Napi::Value GitFilterSource::Path(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_filter_source_path(
          Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return Number  result    */
Napi::Value GitFilterSource::Filemode(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 uint16_t result =     git_filter_source_filemode(
          Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
     * @return Oid  result    */
Napi::Value GitFilterSource::Id(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_filter_source_id(
          Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
          v8ConversionSlot = GitOid::New(
        env,
        result,
        true
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
Napi::Value GitFilterSource::Mode(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 git_filter_mode_t result =     git_filter_source_mode(
          Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
Napi::Value GitFilterSource::Flags(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 uint32_t result =     git_filter_source_flags(
          Napi::ObjectWrap<GitFilterSource>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitFilterSourceTraits>;
 