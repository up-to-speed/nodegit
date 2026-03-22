// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/index_conflict_iterator.h"
#include "bungit_wrapper.cc"

  #include "../include/index.h"
  #include "../include/index_entry.h"
 
#include <iostream>

using namespace std;

  GitIndexConflictIterator::~GitIndexConflictIterator() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
             }

  void GitIndexConflictIterator::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "IndexConflictIterator", {
           StaticMethod("create", &GitIndexConflictIterator::Create, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("next", &GitIndexConflictIterator::Next, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitIndexConflictIterator::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitIndexConflictIterator::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitIndexConflictIterator::Template", constructor_template);
    target.Set(Napi::String::New(env, "IndexConflictIterator"), constructor_template);
  }

 
/*
  * @param Index index
    * @param IndexConflictIterator callback
   */
Napi::Value GitIndexConflictIterator::Create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Index index is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CreateBaton* baton = new CreateBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_index * from_index = NULL;
from_index = Napi::ObjectWrap<GitIndex>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->index = from_index;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CreateWorker *worker = new CreateWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitIndex>("index", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitIndexConflictIterator::CreateWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->index
  );

  return lockMaster;
}

void GitIndexConflictIterator::CreateWorker::Execute() {
  git_error_clear();

    int result = git_index_conflict_iterator_new(
&baton->iterator_out,baton->index  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitIndexConflictIterator::CreateWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexConflictIterator.create"));
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

      git_index_conflict_iterator_free(baton->iterator_out);

  delete baton;
}

void GitIndexConflictIterator::CreateWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->iterator_out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
            owners.Set(Napi::Number::New(env, owners.Length()), this->GetFromPersistent("index").As<Napi::Object>());
             v8ConversionSlot = GitIndexConflictIterator::New(
        env,
        baton->iterator_out,
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
        err = Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexConflictIterator.create"));
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
        Napi::Object err = Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "IndexConflictIterator.create"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_index_conflict_iterator_free(baton->iterator_out);
  }


  delete baton;
}

   
/*
        * @return IndexEntry ancestor_out    * @return IndexEntry our_out    * @return IndexEntry their_out    */
Napi::Value GitIndexConflictIterator::Next(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

      const git_index_entry * ancestor_out = 0;
      const git_index_entry * our_out = 0;
      const git_index_entry * their_out = 0;

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitIndexConflictIterator>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_index_conflict_next(
&          ancestor_out
,&          our_out
,&          their_out
,          Napi::ObjectWrap<GitIndexConflictIterator>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
        Napi::Object toReturn = Napi::Object::New(env);
// start convert_to_v8 block
    if (ancestor_out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitIndexEntry::New(
        env,
        ancestor_out,
        false
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "ancestor_out"), v8ConversionSlot);
// start convert_to_v8 block
    if (our_out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitIndexEntry::New(
        env,
        our_out,
        false
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "our_out"), v8ConversionSlot);
// start convert_to_v8 block
    if (their_out != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
         owners.Set(owners.Length(), info.This());
          v8ConversionSlot = GitIndexEntry::New(
        env,
        their_out,
        false
          , owners
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "their_out"), v8ConversionSlot);
        return scope.Escape(toReturn);
  }
}
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitIndexConflictIteratorTraits>;
 