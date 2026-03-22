// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/commit.h"
#include "bungit_wrapper.cc"

  #include "../include/oid.h"
  #include "../include/signature.h"
  #include "../include/tree.h"
  #include "../include/mailmap.h"
  #include "../include/repository.h"
  #include "../include/buf.h"
  #include "../include/commit_create_options.h"
 
#include <iostream>

using namespace std;

  GitCommit::~GitCommit() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                                                             }

  void GitCommit::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Commit", {
          InstanceMethod("amend", &GitCommit::Amend, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("author", &GitCommit::Author, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("authorWithMailmap", &GitCommit::AuthorWithMailmap, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("body", &GitCommit::Body, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("committer", &GitCommit::Committer, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("committerWithMailmap", &GitCommit::CommitterWithMailmap, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("create", &GitCommit::Create, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("createBuffer", &GitCommit::CreateBuffer, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("createFromStage", &GitCommit::CreateFromStage, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("createV", &GitCommit::CreateV, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("createWithSignature", &GitCommit::CreateWithSignature, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("dup", &GitCommit::Dup, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("extractSignature", &GitCommit::ExtractSignature, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("headerField", &GitCommit::HeaderField, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("id", &GitCommit::Id, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("lookup", &GitCommit::Lookup, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
             StaticMethod("lookupPrefix", &GitCommit::LookupPrefix, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("message", &GitCommit::Message, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("messageEncoding", &GitCommit::MessageEncoding, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("messageRaw", &GitCommit::MessageRaw, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("nthGenAncestor", &GitCommit::NthGenAncestor, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("owner", &GitCommit::Owner, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("parent", &GitCommit::Parent, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("parentId", &GitCommit::ParentId, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("parentcount", &GitCommit::Parentcount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("rawHeader", &GitCommit::RawHeader, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("summary", &GitCommit::Summary, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("time", &GitCommit::Time, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("timeOffset", &GitCommit::TimeOffset, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("tree", &GitCommit::Tree, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
            InstanceMethod("treeId", &GitCommit::TreeId, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
          StaticMethod("getSelfFreeingInstanceCount", &GitCommit::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitCommit::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitCommit::Template", constructor_template);
    target.Set(Napi::String::New(env, "Commit"), constructor_template);
  }

 
/*
    * @param String update_ref
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
    * @param Oid callback
   */
Napi::Value GitCommit::Amend(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AmendBaton* baton = new AmendBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->id = (git_oid *)malloc(sizeof(git_oid ));
        baton->commit_to_amend = Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_update_ref = NULL;
    if ((info.Length() - 1) > 0 && info[0].IsString()) {

  std::string update_ref = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_update_ref = (const char *) malloc(update_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_update_ref, update_ref.c_str(), update_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_update_ref) + update_ref.length()), 0, 1);
  }
  else {
    from_update_ref = 0;
  }
// end convert_from_v8 block
          baton->update_ref = from_update_ref;
// start convert_from_v8 block
  const git_signature * from_author = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsObject()) {
from_author = Napi::ObjectWrap<GitSignature>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
  else {
    from_author = 0;
  }
// end convert_from_v8 block
          baton->author = from_author;
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
    if ((info.Length() - 1) > 2 && info[2].IsObject()) {
from_committer = Napi::ObjectWrap<GitSignature>::Unwrap(info[2].As<Napi::Object>())->GetValue();
  }
  else {
    from_committer = 0;
  }
// end convert_from_v8 block
          baton->committer = from_committer;
// start convert_from_v8 block
  const char * from_message_encoding = NULL;
    if ((info.Length() - 1) > 3 && info[3].IsString()) {

  std::string message_encoding = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message_encoding = (const char *) malloc(message_encoding.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message_encoding, message_encoding.c_str(), message_encoding.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message_encoding) + message_encoding.length()), 0, 1);
  }
  else {
    from_message_encoding = 0;
  }
// end convert_from_v8 block
          baton->message_encoding = from_message_encoding;
// start convert_from_v8 block
  const char * from_message = NULL;
    if ((info.Length() - 1) > 4 && info[4].IsString()) {

  std::string message = info[4].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message = (const char *) malloc(message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message, message.c_str(), message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message) + message.length()), 0, 1);
  }
  else {
    from_message = 0;
  }
// end convert_from_v8 block
          baton->message = from_message;
// start convert_from_v8 block
  const git_tree * from_tree = NULL;
    if ((info.Length() - 1) > 5 && info[5].IsObject()) {
from_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[5].As<Napi::Object>())->GetValue();
  }
  else {
    from_tree = 0;
  }
// end convert_from_v8 block
          baton->tree = from_tree;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  AmendWorker *worker = new AmendWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitCommit>("commit_to_amend", info.This().As<Napi::Object>());
           worker->Reference("update_ref", info[0]);
              worker->Reference<GitSignature>("author", info[1]);
               worker->Reference<GitSignature>("committer", info[2]);
             worker->Reference("message_encoding", info[3]);
            worker->Reference("message", info[4]);
              worker->Reference<GitTree>("tree", info[5]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::AmendWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->id
          ,baton->commit_to_amend
          ,baton->update_ref
          ,baton->author
          ,baton->committer
          ,baton->message_encoding
          ,baton->message
          ,baton->tree
  );

  return lockMaster;
}

void GitCommit::AmendWorker::Execute() {
  git_error_clear();

    int result = git_commit_amend(
baton->id,baton->commit_to_amend,baton->update_ref,baton->author,baton->committer,baton->message_encoding,baton->message,baton->tree  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::AmendWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.amend"));
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

void GitCommit::AmendWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->id != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        baton->id,
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
        err = Napi::Error::New(env, "Method amend has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.amend"));
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
        Napi::Object err = Napi::Error::New(env, "Method amend has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.amend"));
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
     * @return Signature  result    */
Napi::Value GitCommit::Author(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_signature * result =     git_commit_author(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
    * @param Mailmap mailmap
    * @param Signature callback
   */
Napi::Value GitCommit::AuthorWithMailmap(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Mailmap mailmap is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AuthorWithMailmapBaton* baton = new AuthorWithMailmapBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->commit = Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_mailmap * from_mailmap = NULL;
from_mailmap = Napi::ObjectWrap<GitMailmap>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->mailmap = from_mailmap;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  AuthorWithMailmapWorker *worker = new AuthorWithMailmapWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitCommit>("commit", info.This().As<Napi::Object>());
             worker->Reference<GitMailmap>("mailmap", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::AuthorWithMailmapWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->commit
          ,baton->mailmap
  );

  return lockMaster;
}

void GitCommit::AuthorWithMailmapWorker::Execute() {
  git_error_clear();

    int result = git_commit_author_with_mailmap(
&baton->out,baton->commit,baton->mailmap  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::AuthorWithMailmapWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.authorWithMailmap"));
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

void GitCommit::AuthorWithMailmapWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitSignature::New(
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
        err = Napi::Error::New(env, "Method authorWithMailmap has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.authorWithMailmap"));
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
        Napi::Object err = Napi::Error::New(env, "Method authorWithMailmap has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.authorWithMailmap"));
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
     * @return String  result    */
Napi::Value GitCommit::Body(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_commit_body(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return Signature  result    */
Napi::Value GitCommit::Committer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_signature * result =     git_commit_committer(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
    * @param Mailmap mailmap
    * @param Signature callback
   */
Napi::Value GitCommit::CommitterWithMailmap(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Mailmap mailmap is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CommitterWithMailmapBaton* baton = new CommitterWithMailmapBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->commit = Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const git_mailmap * from_mailmap = NULL;
from_mailmap = Napi::ObjectWrap<GitMailmap>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->mailmap = from_mailmap;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CommitterWithMailmapWorker *worker = new CommitterWithMailmapWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitCommit>("commit", info.This().As<Napi::Object>());
             worker->Reference<GitMailmap>("mailmap", info[0]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::CommitterWithMailmapWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->commit
          ,baton->mailmap
  );

  return lockMaster;
}

void GitCommit::CommitterWithMailmapWorker::Execute() {
  git_error_clear();

    int result = git_commit_committer_with_mailmap(
&baton->out,baton->commit,baton->mailmap  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::CommitterWithMailmapWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.committerWithMailmap"));
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

void GitCommit::CommitterWithMailmapWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->out != NULL) {
        v8ConversionSlot = GitSignature::New(
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
        err = Napi::Error::New(env, "Method committerWithMailmap has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.committerWithMailmap"));
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
        Napi::Object err = Napi::Error::New(env, "Method committerWithMailmap has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.committerWithMailmap"));
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
   * @param String update_ref
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
   * @param Number parent_count
   * @param Array parents
    * @param Oid callback
   */
Napi::Value GitCommit::Create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
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

  if (info.Length() == 5 || !info[5].IsString()) {
    Napi::Error::New(env, "String message is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 6 || !info[6].IsObject()) {
    Napi::Error::New(env, "Tree tree is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 7 || !info[7].IsNumber()) {
    Napi::Error::New(env, "Number parent_count is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 8 || !info[8].IsObject()) {
    Napi::Error::New(env, "Array parents is required.").ThrowAsJavaScriptException();
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

      baton->id = (git_oid *)malloc(sizeof(git_oid ));
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_update_ref = NULL;
    if ((info.Length() - 1) > 1 && info[1].IsString()) {

  std::string update_ref = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_update_ref = (const char *) malloc(update_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_update_ref, update_ref.c_str(), update_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_update_ref) + update_ref.length()), 0, 1);
  }
  else {
    from_update_ref = 0;
  }
// end convert_from_v8 block
          baton->update_ref = from_update_ref;
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
  const char * from_message_encoding = NULL;
    if ((info.Length() - 1) > 4 && info[4].IsString()) {

  std::string message_encoding = info[4].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message_encoding = (const char *) malloc(message_encoding.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message_encoding, message_encoding.c_str(), message_encoding.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message_encoding) + message_encoding.length()), 0, 1);
  }
  else {
    from_message_encoding = 0;
  }
// end convert_from_v8 block
          baton->message_encoding = from_message_encoding;
// start convert_from_v8 block
  const char * from_message = NULL;

  std::string message = info[5].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message = (const char *) malloc(message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message, message.c_str(), message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message) + message.length()), 0, 1);
// end convert_from_v8 block
          baton->message = from_message;
// start convert_from_v8 block
  const git_tree * from_tree = NULL;
from_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[6].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->tree = from_tree;
// start convert_from_v8 block
  size_t from_parent_count;
      from_parent_count = (size_t)   info[7].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->parent_count = from_parent_count;
// start convert_from_v8 block
  const git_commit ** from_parents = NULL;

  Napi::Array tmp_parents = info[8].As<Napi::Array>();
  from_parents = (const git_commit **)malloc(tmp_parents.Length() * sizeof(const git_commit *));
  for (unsigned int i = 0; i < tmp_parents.Length(); i++) {
    const Napi::Value arrayVal = tmp_parents.Get(i);
      from_parents[i] = Napi::ObjectWrap<GitCommit>::Unwrap(arrayVal.As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->parents = from_parents;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CreateWorker *worker = new CreateWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("update_ref", info[1]);
              worker->Reference<GitSignature>("author", info[2]);
               worker->Reference<GitSignature>("committer", info[3]);
             worker->Reference("message_encoding", info[4]);
            worker->Reference("message", info[5]);
              worker->Reference<GitTree>("tree", info[6]);
             worker->Reference("parent_count", info[7]);
             if (info[8].IsArray()) {
              worker->Reference<GitCommit>("parents", info[8].As<Napi::Array>());
            }
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::CreateWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->id
          ,baton->repo
          ,baton->update_ref
          ,baton->author
          ,baton->committer
          ,baton->message_encoding
          ,baton->message
          ,baton->tree
  );

  return lockMaster;
}

void GitCommit::CreateWorker::Execute() {
  git_error_clear();

    int result = git_commit_create(
baton->id,baton->repo,baton->update_ref,baton->author,baton->committer,baton->message_encoding,baton->message,baton->tree,baton->parent_count,baton->parents  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::CreateWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.create"));
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

void GitCommit::CreateWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->id != NULL) {
        v8ConversionSlot = GitOid::New(
        env,
        baton->id,
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
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.create"));
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
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.create"));
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
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
   * @param Number parent_count
   * @param Array parents
    * @param Buffer callback
   */
Napi::Value GitCommit::CreateBuffer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Signature author is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsObject()) {
    Napi::Error::New(env, "Signature committer is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4 || !info[4].IsString()) {
    Napi::Error::New(env, "String message is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 5 || !info[5].IsObject()) {
    Napi::Error::New(env, "Tree tree is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 6 || !info[6].IsNumber()) {
    Napi::Error::New(env, "Number parent_count is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 7 || !info[7].IsObject()) {
    Napi::Error::New(env, "Array parents is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CreateBufferBaton* baton = new CreateBufferBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->reserved = 0;
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->repo = from_repo;
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Napi::ObjectWrap<GitSignature>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->author = from_author;
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Napi::ObjectWrap<GitSignature>::Unwrap(info[2].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->committer = from_committer;
// start convert_from_v8 block
  const char * from_message_encoding = NULL;
    if ((info.Length() - 1) > 3 && info[3].IsString()) {

  std::string message_encoding = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message_encoding = (const char *) malloc(message_encoding.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message_encoding, message_encoding.c_str(), message_encoding.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message_encoding) + message_encoding.length()), 0, 1);
  }
  else {
    from_message_encoding = 0;
  }
// end convert_from_v8 block
          baton->message_encoding = from_message_encoding;
// start convert_from_v8 block
  const char * from_message = NULL;

  std::string message = info[4].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message = (const char *) malloc(message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message, message.c_str(), message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message) + message.length()), 0, 1);
// end convert_from_v8 block
          baton->message = from_message;
// start convert_from_v8 block
  const git_tree * from_tree = NULL;
from_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[5].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
          baton->tree = from_tree;
// start convert_from_v8 block
  size_t from_parent_count;
      from_parent_count = (size_t)   info[6].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->parent_count = from_parent_count;
// start convert_from_v8 block
  const git_commit ** from_parents = NULL;

  Napi::Array tmp_parents = info[7].As<Napi::Array>();
  from_parents = (const git_commit **)malloc(tmp_parents.Length() * sizeof(const git_commit *));
  for (unsigned int i = 0; i < tmp_parents.Length(); i++) {
    const Napi::Value arrayVal = tmp_parents.Get(i);
      from_parents[i] = Napi::ObjectWrap<GitCommit>::Unwrap(arrayVal.As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->parents = from_parents;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CreateBufferWorker *worker = new CreateBufferWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitSignature>("author", info[1]);
               worker->Reference<GitSignature>("committer", info[2]);
             worker->Reference("message_encoding", info[3]);
            worker->Reference("message", info[4]);
              worker->Reference<GitTree>("tree", info[5]);
             worker->Reference("parent_count", info[6]);
             if (info[7].IsArray()) {
              worker->Reference<GitCommit>("parents", info[7].As<Napi::Array>());
            }
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::CreateBufferWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->repo
          ,baton->author
          ,baton->committer
          ,baton->message_encoding
          ,baton->message
          ,baton->tree
  );

  return lockMaster;
}

void GitCommit::CreateBufferWorker::Execute() {
  git_error_clear();

    int result = git_commit_create_buffer(
baton->out,baton->repo,baton->author,baton->committer,baton->message_encoding,baton->message,baton->tree,baton->parent_count,baton->parents  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::CreateBufferWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.createBuffer"));
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

void GitCommit::CreateBufferWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method createBuffer has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.createBuffer"));
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
        Napi::Object err = Napi::Error::New(env, "Method createBuffer has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.createBuffer"));
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
 * @param Oid id
   * @param Repository repo
   * @param String message
   * @param CommitCreateOptions opts
     * @return Number  result    */
Napi::Value GitCommit::CreateFromStage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String message is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsObject()) {
    Napi::Error::New(env, "CommitCreateOptions opts is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_oid * from_id = NULL;
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

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message = NULL;

  std::string message = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message = (const char *) malloc(message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message, message.c_str(), message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message) + message.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_commit_create_options * from_opts = NULL;
from_opts = Napi::ObjectWrap<GitCommitCreateOptions>::Unwrap(info[3].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_id
            ,
              from_repo
            ,
              from_message
            ,
              from_opts
    );

 int result =     git_commit_create_from_stage(
          from_id
,          from_repo
,          from_message
,          from_opts
    );

      if (info[0].IsString()) {
        free((void *)from_id);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
 * @param Oid id
   * @param Repository repo
   * @param String update_ref
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
   * @param Number parent_count
     * @return Number  result    */
Napi::Value GitCommit::CreateV(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0
    || (!info[0].IsObject() && !info[0].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 1 || !info[1].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String update_ref is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsObject()) {
    Napi::Error::New(env, "Signature author is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 4 || !info[4].IsObject()) {
    Napi::Error::New(env, "Signature committer is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 5 || !info[5].IsString()) {
    Napi::Error::New(env, "String message_encoding is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 6 || !info[6].IsString()) {
    Napi::Error::New(env, "String message is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 7 || !info[7].IsObject()) {
    Napi::Error::New(env, "Tree tree is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 8 || !info[8].IsNumber()) {
    Napi::Error::New(env, "Number parent_count is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_oid * from_id = NULL;
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

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[0].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  git_repository * from_repo = NULL;
from_repo = Napi::ObjectWrap<GitRepository>::Unwrap(info[1].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_update_ref = NULL;

  std::string update_ref = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_update_ref = (const char *) malloc(update_ref.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_update_ref, update_ref.c_str(), update_ref.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_update_ref) + update_ref.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_author = NULL;
from_author = Napi::ObjectWrap<GitSignature>::Unwrap(info[3].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_committer = NULL;
from_committer = Napi::ObjectWrap<GitSignature>::Unwrap(info[4].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message_encoding = NULL;

  std::string message_encoding = info[5].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message_encoding = (const char *) malloc(message_encoding.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message_encoding, message_encoding.c_str(), message_encoding.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message_encoding) + message_encoding.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message = NULL;

  std::string message = info[6].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_message = (const char *) malloc(message.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_message, message.c_str(), message.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_message) + message.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_tree * from_tree = NULL;
from_tree = Napi::ObjectWrap<GitTree>::Unwrap(info[7].As<Napi::Object>())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_parent_count;
      from_parent_count = (size_t)   info[8].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_id
            ,
              from_repo
            ,
              from_update_ref
            ,
              from_author
            ,
              from_committer
            ,
              from_message_encoding
            ,
              from_message
            ,
              from_tree
    );

 int result =     git_commit_create_v(
          from_id
,          from_repo
,          from_update_ref
,          from_author
,          from_committer
,          from_message_encoding
,          from_message
,          from_tree
,          from_parent_count
    );

      if (info[0].IsString()) {
        free((void *)from_id);
      }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
  
/*
  * @param Repository repo
   * @param String commit_content
   * @param String signature
   * @param String signature_field
    * @param Oid callback
   */
Napi::Value GitCommit::CreateWithSignature(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsString()) {
    Napi::Error::New(env, "String commit_content is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsString()) {
    Napi::Error::New(env, "String signature is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsString()) {
    Napi::Error::New(env, "String signature_field is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CreateWithSignatureBaton* baton = new CreateWithSignatureBaton();

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
  const char * from_commit_content = NULL;

  std::string commit_content = info[1].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_commit_content = (const char *) malloc(commit_content.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_commit_content, commit_content.c_str(), commit_content.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_commit_content) + commit_content.length()), 0, 1);
// end convert_from_v8 block
          baton->commit_content = from_commit_content;
// start convert_from_v8 block
  const char * from_signature = NULL;

  std::string signature = info[2].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_signature = (const char *) malloc(signature.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_signature, signature.c_str(), signature.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_signature) + signature.length()), 0, 1);
// end convert_from_v8 block
          baton->signature = from_signature;
// start convert_from_v8 block
  const char * from_signature_field = NULL;

  std::string signature_field = info[3].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_signature_field = (const char *) malloc(signature_field.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_signature_field, signature_field.c_str(), signature_field.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_signature_field) + signature_field.length()), 0, 1);
// end convert_from_v8 block
          baton->signature_field = from_signature_field;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  CreateWithSignatureWorker *worker = new CreateWithSignatureWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
             worker->Reference("commit_content", info[1]);
            worker->Reference("signature", info[2]);
            worker->Reference("signature_field", info[3]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::CreateWithSignatureWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->repo
          ,baton->commit_content
          ,baton->signature
          ,baton->signature_field
  );

  return lockMaster;
}

void GitCommit::CreateWithSignatureWorker::Execute() {
  git_error_clear();

    int result = git_commit_create_with_signature(
baton->out,baton->repo,baton->commit_content,baton->signature,baton->signature_field  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::CreateWithSignatureWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.createWithSignature"));
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

void GitCommit::CreateWithSignatureWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method createWithSignature has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.createWithSignature"));
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
        Napi::Object err = Napi::Error::New(env, "Method createWithSignature has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.createWithSignature"));
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
     * @param Commit callback
   */
Napi::Value GitCommit::Dup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  DupBaton* baton = new DupBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->source = Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  DupWorker *worker = new DupWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitCommit>("source", info.This().As<Napi::Object>());

  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::DupWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->source
  );

  return lockMaster;
}

void GitCommit::DupWorker::Execute() {
  git_error_clear();

    int result = git_commit_dup(
&baton->out,baton->source  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::DupWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.dup"));
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

void GitCommit::DupWorker::HandleOKCallback() {
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
            git_commit_owner(baton->out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitCommit::New(
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
        err = Napi::Error::New(env, "Method dup has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.dup"));
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
        Napi::Object err = Napi::Error::New(env, "Method dup has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.dup"));
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

        Napi::Value GitCommit::ExtractSignature(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid commit_id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() >= 4 && !info[2].IsString() && !info[2].IsUndefined() && !info[2].IsNull()) {
    Napi::Error::New(env, "String signature_field must be a string or undefined/null.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ExtractSignatureBaton* baton = new ExtractSignatureBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->signature = GIT_BUF_INIT_CONST(NULL, 0);
  baton->signed_data = GIT_BUF_INIT_CONST(NULL, 0);
  baton->repo = GitRepository::Unwrap(info[0].As<Napi::Object>())->GetValue();

  // baton->commit_id
  if (info[1].IsString()) {
    std::string oidString = info[1].As<Napi::String>().Utf8Value();
    baton->commit_id = (git_oid *)malloc(sizeof(git_oid));
    if (git_oid_fromstr(baton->commit_id, (const char *)strdup(oidString.c_str())) != GIT_OK) {
      free(baton->commit_id);

      if (git_error_last()->klass != GIT_ERROR_NONE) {
        Napi::Error::New(env, git_error_last()->message).ThrowAsJavaScriptException();
        return env.Undefined();
      } else {
        Napi::Error::New(env, "Unknown Error").ThrowAsJavaScriptException();
        return env.Undefined();
      }
    }
  } else {
    baton->commit_id = GitOid::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }

  // baton->field
  if (info[2].IsString()) {
    std::string field = info[2].As<Napi::String>().Utf8Value();
    baton->field = (char *)malloc(field.length() + 1);
    memcpy((void *)baton->field, field.c_str(), field.length());
    baton->field[field.length()] = 0;
  } else {
    baton->field = NULL;
  }

  Napi::FunctionReference callback;
  callback.Reset(info[info.Length() - 1].As<Napi::Function>(), 1);

  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  ExtractSignatureWorker *worker = new ExtractSignatureWorker(baton, std::move(callback), cleanupHandles);
  worker->Reference<GitRepository>("repo", info[0]);
  worker->Reference<GitOid>("commit_id", info[1]);
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext();
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::ExtractSignatureWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->repo);
  return lockMaster;
}

void GitCommit::ExtractSignatureWorker::Execute()
{
  git_error_clear();

  baton->error_code = git_commit_extract_signature(
    &baton->signature,
    &baton->signed_data,
    baton->repo,
    baton->commit_id,
    (const char *)baton->field
  );

  if (baton->error_code != GIT_OK) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitCommit::ExtractSignatureWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  git_buf_dispose(&baton->signature);
  git_buf_dispose(&baton->signed_data);

  free(baton->field);

  delete baton;
}

void GitCommit::ExtractSignatureWorker::HandleOKCallback()
{
  Napi::Env env = Env();
  if (baton->error_code == GIT_OK)
  {
    Napi::Object result = Napi::Object::New(env);
    result.Set(
      "signature",
      Napi::String::New(env, baton->signature.ptr, baton->signature.size)
    );
    result.Set(
      "signedData",
      Napi::String::New(env, baton->signed_data.ptr, baton->signed_data.size)
    );

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
    Napi::Object err = Napi::Error::New(env, "Extract Signature has thrown an error.").Value().As<Napi::Object>();
    err.Set("errno", Napi::Number::New(env, baton->error_code));
    err.Set("errorFunction", Napi::String::New(env, "Commit.extractSignature"));
    napi_value argv[1] = {
      err
    };
    callback.Call(env.Undefined(), 1, argv);
  }
  else
  {
    callback.Call({});
  }

  git_buf_dispose(&baton->signature);
  git_buf_dispose(&baton->signed_data);

  if (baton->field != NULL) {
    free((void *)baton->field);
  }

  delete baton;
}

  
/*
    * @param String field
    * @param Buf callback
   */
Napi::Value GitCommit::HeaderField(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String field is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  HeaderFieldBaton* baton = new HeaderFieldBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));
        baton->out->ptr = NULL;
        baton->out->size = baton->out->reserved = 0;
        baton->commit = Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  const char * from_field = NULL;

  std::string field = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_field = (const char *) malloc(field.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_field, field.c_str(), field.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_field) + field.length()), 0, 1);
// end convert_from_v8 block
          baton->field = from_field;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  HeaderFieldWorker *worker = new HeaderFieldWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitCommit>("commit", info.This().As<Napi::Object>());
           worker->Reference("field", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::HeaderFieldWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->out
          ,baton->commit
          ,baton->field
  );

  return lockMaster;
}

void GitCommit::HeaderFieldWorker::Execute() {
  git_error_clear();

    int result = git_commit_header_field(
baton->out,baton->commit,baton->field  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::HeaderFieldWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.headerField"));
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

void GitCommit::HeaderFieldWorker::HandleOKCallback() {
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
        err = Napi::Error::New(env, "Method headerField has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.headerField"));
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
        Napi::Object err = Napi::Error::New(env, "Method headerField has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.headerField"));
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
     * @return Oid  result    */
Napi::Value GitCommit::Id(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_commit_id(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
  * @param Repository repo
   * @param Oid id
    * @param Commit callback
   */
Napi::Value GitCommit::Lookup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  LookupBaton* baton = new LookupBaton();

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
  const git_oid * from_id = NULL;
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

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->id = from_id;
            baton->idNeedsFree = info[1].IsString();

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  LookupWorker *worker = new LookupWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitOid>("id", info[1]);
  
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::LookupWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->id
  );

  return lockMaster;
}

void GitCommit::LookupWorker::Execute() {
  git_error_clear();

    int result = git_commit_lookup(
&baton->commit,baton->repo,baton->id  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::LookupWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.lookup"));
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

      git_commit_free(baton->commit);
      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

void GitCommit::LookupWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->commit != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
          owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_commit_owner(baton->commit),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitCommit::New(
        env,
        baton->commit,
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
        err = Napi::Error::New(env, "Method lookup has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.lookup"));
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
        Napi::Object err = Napi::Error::New(env, "Method lookup has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.lookup"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_commit_free(baton->commit);
  }

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Oid id
   * @param Number len
    * @param Commit callback
   */
Napi::Value GitCommit::LookupPrefix(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Repository repo is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1
    || (!info[1].IsObject() && !info[1].IsString())) {
    Napi::Error::New(env, "Oid id is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number len is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  LookupPrefixBaton* baton = new LookupPrefixBaton();

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
  const git_oid * from_id = NULL;
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

    from_id = oidOut;
  }
  else {
from_id = Napi::ObjectWrap<GitOid>::Unwrap(info[1].As<Napi::Object>())->GetValue();
  }
// end convert_from_v8 block
          baton->id = from_id;
            baton->idNeedsFree = info[1].IsString();
// start convert_from_v8 block
  size_t from_len;
      from_len = (size_t)   info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->len = from_len;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  LookupPrefixWorker *worker = new LookupPrefixWorker(baton, std::move(callback), cleanupHandles);

             worker->Reference<GitRepository>("repo", info[0]);
               worker->Reference<GitOid>("id", info[1]);
             worker->Reference("len", info[2]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::LookupPrefixWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->repo
          ,baton->id
  );

  return lockMaster;
}

void GitCommit::LookupPrefixWorker::Execute() {
  git_error_clear();

    int result = git_commit_lookup_prefix(
&baton->commit,baton->repo,baton->id,baton->len  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::LookupPrefixWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.lookupPrefix"));
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

      git_commit_free(baton->commit);
      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

void GitCommit::LookupPrefixWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->commit != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
          owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_commit_owner(baton->commit),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitCommit::New(
        env,
        baton->commit,
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
        err = Napi::Error::New(env, "Method lookupPrefix has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.lookupPrefix"));
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
        Napi::Object err = Napi::Error::New(env, "Method lookupPrefix has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.lookupPrefix"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_commit_free(baton->commit);
  }

      if (baton->idNeedsFree) {
        baton->idNeedsFree = false;
        free((void *)baton->id);
      }

  delete baton;
}

   
/*
     * @return String  result    */
Napi::Value GitCommit::Message(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_commit_message(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return String  result    */
Napi::Value GitCommit::MessageEncoding(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_commit_message_encoding(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return String  result    */
Napi::Value GitCommit::MessageRaw(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_commit_message_raw(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
    * @param Number n
    * @param Commit callback
   */
Napi::Value GitCommit::NthGenAncestor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number n is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  NthGenAncestorBaton* baton = new NthGenAncestorBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->commit = Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  unsigned int from_n;
      from_n = (unsigned int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->n = from_n;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  NthGenAncestorWorker *worker = new NthGenAncestorWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitCommit>("commit", info.This().As<Napi::Object>());
           worker->Reference("n", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::NthGenAncestorWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->commit
  );

  return lockMaster;
}

void GitCommit::NthGenAncestorWorker::Execute() {
  git_error_clear();

    int result = git_commit_nth_gen_ancestor(
&baton->ancestor,baton->commit,baton->n  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::NthGenAncestorWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.nthGenAncestor"));
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

      git_commit_free(baton->ancestor);

  delete baton;
}

void GitCommit::NthGenAncestorWorker::HandleOKCallback() {
  Napi::Env env = Env();

    if (baton->error_code == GIT_OK) {
    Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (baton->ancestor != NULL) {
      Napi::Array owners = Napi::Array::New(env, 0);
          owners.Set(
          Napi::Number::New(env, owners.Length()),
          GitRepository::New(
            env,
            git_commit_owner(baton->ancestor),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitCommit::New(
        env,
        baton->ancestor,
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
        err = Napi::Error::New(env, "Method nthGenAncestor has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.nthGenAncestor"));
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
        Napi::Object err = Napi::Error::New(env, "Method nthGenAncestor has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.nthGenAncestor"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_commit_free(baton->ancestor);
  }


  delete baton;
}

   
/*
     * @return Repository  result    */
Napi::Value GitCommit::Owner(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 git_repository * result =     git_commit_owner(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

        // null checks on pointers
        if (!result) {
          return scope.Escape(env.Undefined());
        }

      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
    if (result != NULL) {
        v8ConversionSlot = GitRepository::New(
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
    * @param Number n
    * @param Commit callback
   */
Napi::Value GitCommit::Parent(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number n is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ParentBaton* baton = new ParentBaton();

  baton->error_code = GIT_OK;
  baton->error = NULL;


  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;

        baton->commit = Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue();
// start convert_from_v8 block
  unsigned int from_n;
      from_n = (unsigned int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
          baton->n = from_n;

  Napi::FunctionReference callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  ParentWorker *worker = new ParentWorker(baton, std::move(callback), cleanupHandles);

        worker->Reference<GitCommit>("commit", info.This().As<Napi::Object>());
           worker->Reference("n", info[0]);
 
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitCommit::ParentWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(
    /*asyncAction: */true
          ,baton->commit
  );

  return lockMaster;
}

void GitCommit::ParentWorker::Execute() {
  git_error_clear();

    int result = git_commit_parent(
&baton->out,baton->commit,baton->n  );

      baton->error_code = result;

      if (result != GIT_OK && git_error_last()->klass != GIT_ERROR_NONE) {
        baton->error = git_error_dup(git_error_last());
      }

}

void GitCommit::ParentWorker::HandleErrorCallback() {
  if (!GetIsCancelled()) {
    Napi::Env env = Env();
    Napi::Object err = Napi::Error::New(env, ErrorMessage()).Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.parent"));
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

      git_commit_free(baton->out);

  delete baton;
}

void GitCommit::ParentWorker::HandleOKCallback() {
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
            git_commit_owner(baton->out),
            true
          ).As<Napi::Object>()
        );
         v8ConversionSlot = GitCommit::New(
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
        err = Napi::Error::New(env, "Method parent has thrown an error.").Value().As<Napi::Object>();
      }
      err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
      err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.parent"));
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
        Napi::Object err = Napi::Error::New(env, "Method parent has thrown an error.").Value().As<Napi::Object>();
        err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
        err.Set(Napi::String::New(env, "errorFunction"), Napi::String::New(env, "Commit.parent"));
        napi_value argv[1] = {
          err
        };
        callback.Call(env.Undefined(), 1, argv);
      }
    } else {
      callback.Call({});
    }

        git_commit_free(baton->out);
  }


  delete baton;
}

   
/*
   * @param Number n
     * @return Oid  result    */
Napi::Value GitCommit::ParentId(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number n is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  unsigned int from_n;
      from_n = (unsigned int)   info[0].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_commit_parent_id(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_n
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
Napi::Value GitCommit::Parentcount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 unsigned int result =     git_commit_parentcount(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
Napi::Value GitCommit::RawHeader(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_commit_raw_header(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
     * @return String  result    */
Napi::Value GitCommit::Summary(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const char * result =     git_commit_summary(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
Napi::Value GitCommit::Time(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 git_time_t result =     git_commit_time(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
Napi::Value GitCommit::TimeOffset(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_commit_time_offset(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
   
/*
 * @param Tree tree_out
       * @return Number  result    */
Napi::Value GitCommit::Tree(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsObject()) {
    Napi::Error::New(env, "Tree tree_out is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  git_tree ** from_tree_out = NULL;
*from_tree_out = Napi::ObjectWrap<GitTree>::Unwrap(info[0].As<Napi::Object>())->GetValue();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_tree_out
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 int result =     git_commit_tree(
          from_tree_out
,          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
Napi::Value GitCommit::TreeId(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);


  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
    );

 const git_oid * result =     git_commit_tree_id(
          Napi::ObjectWrap<GitCommit>::Unwrap(info.This().As<Napi::Object>())->GetValue()
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
    // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitCommitTraits>;
 