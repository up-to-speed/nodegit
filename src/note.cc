// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/note.h"
#include "bungit_wrapper.cc"

  #include "../include/signature.h"
  #include "../include/oid.h"
  #include "../include/repository.h"
  #include "../include/commit.h"
  #include "../include/note_iterator.h"
  #include "../include/buf.h"
 
#include <iostream>

using namespace std;

  GitNote::~GitNote() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                             }

  void GitNote::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Note", {
          InstanceMethod("author", &GitNote::Author, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("commitCreate", &GitNote::CommitCreate, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("commitIteratorNew", &GitNote::CommitIteratorNew, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("commitRead", &GitNote::CommitRead, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("commitRemove", &GitNote::CommitRemove, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("committer", &GitNote::Committer, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("create", &GitNote::Create, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("defaultRef", &GitNote::DefaultRef, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("foreach", &GitNote::Foreach, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("id", &GitNote::Id, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("message", &GitNote::Message, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("read", &GitNote::Read, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("remove", &GitNote::Remove, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitNote::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitNote::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitNote::Template", constructor_template);
    target.Set(Napi::String::New(env, "Note"), constructor_template);
  }

  
/*
     * @return Signature  result    */
Napi::Value GitNote::Author(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitNote>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_signature * result =     git_note_author(
          Napi::ObjectWrap<GitNote>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
          v8ConversionSlot = GitSignature::New(
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
   * @param Repository repo
   * @param Commit parent
   * @param Signature author
   * @param Signature committer
   * @param Oid oid
   * @param String note
   * @param Number allow_note_overwrite
     * @return Oid notes_commit_out    * @return Oid notes_blob_out    */
Napi::Value GitNote::CommitCreate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Commit parent is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Signature author is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsObject()) {
    Napi::Error::New(env, "Signature committer is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4
    || (!info[4].IsObject() && !info[4].IsString())) {
    Napi::Error::New(env, "Oid oid is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 5 || !info[5].IsString()) {
    Napi::Error::New(env, "String note is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 6 || !info[6].IsNumber()) {
    Napi::Error::New(env, "Number allow_note_overwrite is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

      git_oid *notes_commit_out = (git_oid *)malloc(sizeof(git_oid));
      git_oid *notes_blob_out = (git_oid *)malloc(sizeof(git_oid));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  git_commit * from_parent = NULL;
from_parent = Napi::ObjectWrap<GitCommit>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Napi::ObjectWrap<GitSignature>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Napi::ObjectWrap<GitSignature>::Unwrap(info[3].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_oid * from_oid = NULL;
  if (info[4].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[4].As<Napi::String>().Utf8Value();
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

    from_oid = oidOut;
  }
  else {
from_oid = Napi::ObjectWrap<GitOid>::Unwrap(info[4].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_note = NULL;

  std::string note = info[5].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_note = (const char *) malloc(note.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_note, note.c_str(), note.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_note) + note.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  int from_allow_note_overwrite;
      from_allow_note_overwrite = (int)   info[6].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_repo
            ,
              from_parent
            ,
              from_author
            ,
              from_committer
            ,
              from_oid
            ,
              from_note
    );

 int result =     git_note_commit_create(
          notes_commit_out
,          notes_blob_out
,          from_repo
,          from_parent
,          from_author
,          from_committer
,          from_oid
,          from_note
,          from_allow_note_overwrite
    );

      if (info[4].IsString()) {
        free((void *)from_oid);
      }

      Napi::Value v8ConversionSlot;
        Napi::Object toReturn = Napi::Object::New(env);
// start convert_to_v8 block
    if (notes_commit_out != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        notes_commit_out,
        true
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "notes_commit_out"), v8ConversionSlot);
// start convert_to_v8 block
    if (notes_blob_out != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        notes_blob_out,
        true
       );
   }
  else {
    v8ConversionSlot = env.Null();
  }
  // end convert_to_v8 block
          toReturn.Set(Napi::String::New(env, "notes_blob_out"), v8ConversionSlot);
        return scope.Escape(toReturn);
  }
}
  
/*
  * @param Commit notes_commit
    * @param NoteIterator callback
   */
Napi::Value GitNote::CommitIteratorNew(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Commit notes_commit is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CommitIteratorNewBaton* baton = new CommitIteratorNewBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_commit * from_notes_commit = NULL;
from_notes_commit = Napi::ObjectWrap<GitCommit>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->notes_commit = from_notes_commit;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CommitIteratorNewWorker *worker = new CommitIteratorNewWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitCommit>("notes_commit", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitNote::CommitIteratorNewWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->notes_commit
  );

  return lockMaster;
}

void GitNote::CommitIteratorNewWorker::Execute() {
  git_error_clear();

    int result = git_note_commit_iterator_new(
&baton->out,baton->notes_commit  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitNote::CommitIteratorNewWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.commitIteratorNew"));
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

void GitNote::CommitIteratorNewWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitNoteIterator::New(
        env,
        baton->out,
        false
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
        err = Napi::Error::New(env, "Method commitIteratorNew has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.commitIteratorNew"));
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
        Napi::Object err = Napi::Error::New(env, "Method commitIteratorNew has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.commitIteratorNew"));
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
   * @param Commit notes_commit
   * @param Oid oid
    * @param Note callback
   */
Napi::Value GitNote::CommitRead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Commit notes_commit is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2
    || (!info[2].IsObject() && !info[2].IsString())) {
    Napi::Error::New(env, "Oid oid is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CommitReadBaton* baton = new CommitReadBaton();

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
  git_commit * from_notes_commit = NULL;
from_notes_commit = Napi::ObjectWrap<GitCommit>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->notes_commit = from_notes_commit;
// start convert_from_v8 block
  const git_oid * from_oid = NULL;
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

    from_oid = oidOut;
  }
  else {
from_oid = Napi::ObjectWrap<GitOid>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->oid = from_oid;
            baton->oidNeedsFree = info[2].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CommitReadWorker *worker = new CommitReadWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitCommit>("notes_commit", info[1]);
               worker->Reference<GitOid>("oid", info[2]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitNote::CommitReadWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->notes_commit
          ,baton->oid
  );

  return lockMaster;
}

void GitNote::CommitReadWorker::Execute() {
  git_error_clear();

    int result = git_note_commit_read(
&baton->out,baton->repo,baton->notes_commit,baton->oid  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitNote::CommitReadWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.commitRead"));
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
      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

void GitNote::CommitReadWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitNote::New(
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
        err = Napi::Error::New(env, "Method commitRead has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.commitRead"));
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
        Napi::Object err = Napi::Error::New(env, "Method commitRead has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.commitRead"));
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

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Commit notes_commit
   * @param Signature author
   * @param Signature committer
   * @param Oid oid
    * @param Oid callback
   */
Napi::Value GitNote::CommitRemove(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Commit notes_commit is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Signature author is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsObject()) {
    Napi::Error::New(env, "Signature committer is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4
    || (!info[4].IsObject() && !info[4].IsString())) {
    Napi::Error::New(env, "Oid oid is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CommitRemoveBaton* baton = new CommitRemoveBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->notes_commit_out = (git_oid *)malloc(sizeof(git_oid ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  git_commit * from_notes_commit = NULL;
from_notes_commit = Napi::ObjectWrap<GitCommit>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->notes_commit = from_notes_commit;
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Napi::ObjectWrap<GitSignature>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->author = from_author;
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Napi::ObjectWrap<GitSignature>::Unwrap(info[3].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->committer = from_committer;
// start convert_from_v8 block
  const git_oid * from_oid = NULL;
  if (info[4].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[4].As<Napi::String>().Utf8Value();
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

    from_oid = oidOut;
  }
  else {
from_oid = Napi::ObjectWrap<GitOid>::Unwrap(info[4].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->oid = from_oid;
            baton->oidNeedsFree = info[4].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CommitRemoveWorker *worker = new CommitRemoveWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitCommit>("notes_commit", info[1]);
               worker->Reference<GitSignature>("author", info[2]);
               worker->Reference<GitSignature>("committer", info[3]);
               worker->Reference<GitOid>("oid", info[4]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitNote::CommitRemoveWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->notes_commit_out
          ,baton->repo
          ,baton->notes_commit
          ,baton->author
          ,baton->committer
          ,baton->oid
  );

  return lockMaster;
}

void GitNote::CommitRemoveWorker::Execute() {
  git_error_clear();

    int result = git_note_commit_remove(
baton->notes_commit_out,baton->repo,baton->notes_commit,baton->author,baton->committer,baton->oid  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitNote::CommitRemoveWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.commitRemove"));
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

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

void GitNote::CommitRemoveWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->notes_commit_out != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        baton->notes_commit_out,
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
        err = Napi::Error::New(env, "Method commitRemove has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.commitRemove"));
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
        Napi::Object err = Napi::Error::New(env, "Method commitRemove has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.commitRemove"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

   
/*
     * @return Signature  result    */
Napi::Value GitNote::Committer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitNote>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_signature * result =     git_note_committer(
          Napi::ObjectWrap<GitNote>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitSignature::New(
        env,
        result,
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
  
/*
  * @param Repository repo
   * @param String notes_ref
   * @param Signature author
   * @param Signature committer
   * @param Oid oid
   * @param String note
   * @param Number force
    * @param Oid callback
   */
Napi::Value GitNote::Create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String notes_ref is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Signature author is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsObject()) {
    Napi::Error::New(env, "Signature committer is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4
    || (!info[4].IsObject() && !info[4].IsString())) {
    Napi::Error::New(env, "Oid oid is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 5 || !info[5].IsString()) {
    Napi::Error::New(env, "String note is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 6 || !info[6].IsNumber()) {
    Napi::Error::New(env, "Number force is required.").ThrowAsJavaScriptException();
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

      baton->out = (git_oid *)malloc(sizeof(git_oid ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_notes_ref = NULL;

  std::string notes_ref = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_notes_ref = (const char *) malloc(notes_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_notes_ref, notes_ref.c_str(), notes_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_notes_ref) + notes_ref.length()), 0, 1);
// end convert_from_v8 block
          baton->notes_ref = from_notes_ref;
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Napi::ObjectWrap<GitSignature>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->author = from_author;
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Napi::ObjectWrap<GitSignature>::Unwrap(info[3].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->committer = from_committer;
// start convert_from_v8 block
  const git_oid * from_oid = NULL;
  if (info[4].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[4].As<Napi::String>().Utf8Value();
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

    from_oid = oidOut;
  }
  else {
from_oid = Napi::ObjectWrap<GitOid>::Unwrap(info[4].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->oid = from_oid;
            baton->oidNeedsFree = info[4].IsString();
// start convert_from_v8 block
  const char * from_note = NULL;

  std::string note = info[5].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_note = (const char *) malloc(note.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_note, note.c_str(), note.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_note) + note.length()), 0, 1);
// end convert_from_v8 block
          baton->note = from_note;
// start convert_from_v8 block
  int from_force;
      from_force = (int)   info[6].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->force = from_force;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CreateWorker *worker = new CreateWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("notes_ref", info[1]);
              worker->Reference<GitSignature>("author", info[2]);
               worker->Reference<GitSignature>("committer", info[3]);
               worker->Reference<GitOid>("oid", info[4]);
             worker->Reference("note", info[5]);
            worker->Reference("force", info[6]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitNote::CreateWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->repo
          ,baton->notes_ref
          ,baton->author
          ,baton->committer
          ,baton->oid
          ,baton->note
  );

  return lockMaster;
}

void GitNote::CreateWorker::Execute() {
  git_error_clear();

    int result = git_note_create(
baton->out,baton->repo,baton->notes_ref,baton->author,baton->committer,baton->oid,baton->note,baton->force  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitNote::CreateWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.create"));
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

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

void GitNote::CreateWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.create"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.create"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

  
/*
  * @param Repository repo
    * @param Buf callback
   */
Napi::Value GitNote::DefaultRef(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  DefaultRefBaton* baton = new DefaultRefBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  DefaultRefWorker *worker = new DefaultRefWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitNote::DefaultRefWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->repo
  );

  return lockMaster;
}

void GitNote::DefaultRefWorker::Execute() {
  git_error_clear();

    int result = git_note_default_ref(
baton->out,baton->repo  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitNote::DefaultRefWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.defaultRef"));
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

void GitNote::DefaultRefWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
   if (baton->out) {
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
        err = Napi::Error::New(env, "Method defaultRef has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.defaultRef"));
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
        Napi::Object err = Napi::Error::New(env, "Method defaultRef has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.defaultRef"));
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
   * @param String notes_ref
   * @param NoteForeachCb note_cb
   * @param Void payload
     */
Napi::Value GitNote::Foreach(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String notes_ref is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsFunction()) {
    Napi::Error::New(env, "NoteForeachCb note_cb is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ForeachBaton* baton = new ForeachBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;

      Foreach_globalPayload* globalPayload = new Foreach_globalPayload;

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_notes_ref = NULL;

  std::string notes_ref = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_notes_ref = (const char *) malloc(notes_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_notes_ref, notes_ref.c_str(), notes_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_notes_ref) + notes_ref.length()), 0, 1);
// end convert_from_v8 block
          baton->notes_ref = from_notes_ref;
        if (!info[2].IsFunction()) {
          baton->note_cb = NULL;
          globalPayload->note_cb = NULL;
        }
        else {
          baton->note_cb = Foreach_note_cb_cppCallback;
            globalPayload->note_cb = new Napi::FunctionReference();
            *(globalPayload->note_cb) = Napi::Persistent(info[2].As<Napi::Function>());
        }
          baton->payload = globalPayload;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ForeachWorker *worker = new ForeachWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("notes_ref", info[1]);
            worker->Reference("payload", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitNote::ForeachWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->notes_ref
          ,baton->payload
  );

  return lockMaster;
}

void GitNote::ForeachWorker::Execute() {
  git_error_clear();

    int result = git_note_foreach(
baton->repo,baton->notes_ref,baton->note_cb,baton->payload  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitNote::ForeachWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.foreach"));
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

      delete (Foreach_globalPayload*)baton->payload;

  delete baton;
}

void GitNote::ForeachWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method foreach has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.foreach"));
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
        Napi::Object err = Napi::Error::New(env, "Method foreach has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.foreach"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      delete (Foreach_globalPayload*)baton->payload;

  delete baton;
}


int GitNote::Foreach_note_cb_cppCallback (
    const git_oid * blob_id,     const git_oid * annotated_object_id,     void * payload  ) {
  Foreach_NoteCbBaton baton(0);

    baton.blob_id = blob_id;
    baton.annotated_object_id = annotated_object_id;
    baton.payload = payload;
 
  return baton.ExecuteAsync(Foreach_note_cb_async, Foreach_note_cb_cancelAsync);
}

void GitNote::Foreach_note_cb_cancelAsync(void *untypedBaton) {
  Foreach_NoteCbBaton* baton = static_cast<Foreach_NoteCbBaton*>(untypedBaton);
  baton->result = -1;
  baton->Done();
}

void GitNote::Foreach_note_cb_async(void *untypedBaton) {
  Foreach_NoteCbBaton* baton = static_cast<Foreach_NoteCbBaton*>(untypedBaton);

    Napi::FunctionReference* callback = ((Foreach_globalPayload*)baton->payload)->note_cb;
   
  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[2] = {
         GitOid::New(env, baton->blob_id, false)
 ,          GitOid::New(env, baton->annotated_object_id, false)
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

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, Foreach_note_cb_promiseCompleted)) {
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

void GitNote::Foreach_note_cb_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  Foreach_NoteCbBaton* baton = static_cast<Foreach_NoteCbBaton*>(_baton);

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
    GitNote* instance = static_cast<GitNote*>(baton->  payload  );
    Napi::Object parent = static_cast<Napi::ObjectWrap<GitNote>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = -1;
  }
  baton->Done();
}
   
/*
     * @return Oid  result    */
Napi::Value GitNote::Id(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitNote>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_note_id(
          Napi::ObjectWrap<GitNote>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return String  result    */
Napi::Value GitNote::Message(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitNote>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_note_message(
          Napi::ObjectWrap<GitNote>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
  * @param Repository repo
   * @param String notes_ref
   * @param Oid oid
    * @param Note callback
   */
Napi::Value GitNote::Read(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String notes_ref is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2
    || (!info[2].IsObject() && !info[2].IsString())) {
    Napi::Error::New(env, "Oid oid is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ReadBaton* baton = new ReadBaton();

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
  const char * from_notes_ref = NULL;

  std::string notes_ref = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_notes_ref = (const char *) malloc(notes_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_notes_ref, notes_ref.c_str(), notes_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_notes_ref) + notes_ref.length()), 0, 1);
// end convert_from_v8 block
          baton->notes_ref = from_notes_ref;
// start convert_from_v8 block
  const git_oid * from_oid = NULL;
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

    from_oid = oidOut;
  }
  else {
from_oid = Napi::ObjectWrap<GitOid>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->oid = from_oid;
            baton->oidNeedsFree = info[2].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ReadWorker *worker = new ReadWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("notes_ref", info[1]);
              worker->Reference<GitOid>("oid", info[2]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitNote::ReadWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->notes_ref
          ,baton->oid
  );

  return lockMaster;
}

void GitNote::ReadWorker::Execute() {
  git_error_clear();

    int result = git_note_read(
&baton->out,baton->repo,baton->notes_ref,baton->oid  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitNote::ReadWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.read"));
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

      git_note_free(baton->out);
      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

void GitNote::ReadWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitNote::New(
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
        err = Napi::Error::New(env, "Method read has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.read"));
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
        Napi::Object err = Napi::Error::New(env, "Method read has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.read"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_note_free(baton->out);
  }

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

  
/*
 * @param Repository repo
   * @param String notes_ref
   * @param Signature author
   * @param Signature committer
   * @param Oid oid
     */
Napi::Value GitNote::Remove(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String notes_ref is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Signature author is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsObject()) {
    Napi::Error::New(env, "Signature committer is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4
    || (!info[4].IsObject() && !info[4].IsString())) {
    Napi::Error::New(env, "Oid oid is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  RemoveBaton* baton = new RemoveBaton();

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
  const char * from_notes_ref = NULL;

  std::string notes_ref = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_notes_ref = (const char *) malloc(notes_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_notes_ref, notes_ref.c_str(), notes_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_notes_ref) + notes_ref.length()), 0, 1);
// end convert_from_v8 block
          baton->notes_ref = from_notes_ref;
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Napi::ObjectWrap<GitSignature>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->author = from_author;
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Napi::ObjectWrap<GitSignature>::Unwrap(info[3].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->committer = from_committer;
// start convert_from_v8 block
  const git_oid * from_oid = NULL;
  if (info[4].IsString()) {
    // Try and parse in a string to a git_oid
    std::string oidString = info[4].As<Napi::String>().Utf8Value();
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

    from_oid = oidOut;
  }
  else {
from_oid = Napi::ObjectWrap<GitOid>::Unwrap(info[4].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->oid = from_oid;
            baton->oidNeedsFree = info[4].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  RemoveWorker *worker = new RemoveWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("notes_ref", info[1]);
              worker->Reference<GitSignature>("author", info[2]);
               worker->Reference<GitSignature>("committer", info[3]);
               worker->Reference<GitOid>("oid", info[4]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitNote::RemoveWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->notes_ref
          ,baton->author
          ,baton->committer
          ,baton->oid
  );

  return lockMaster;
}

void GitNote::RemoveWorker::Execute() {
  git_error_clear();

    int result = git_note_remove(
baton->repo,baton->notes_ref,baton->author,baton->committer,baton->oid  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitNote::RemoveWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.remove"));
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

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

void GitNote::RemoveWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method remove has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.remove"));
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
        Napi::Object err = Napi::Error::New(env, "Method remove has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Note.remove"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

  }

      if (baton->oidNeedsFree) {
        baton->oidNeedsFree = false;
        free((void *)baton->oid);
      }

  delete baton;
}

    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitNoteTraits>;
 