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
  callback.Reset(info[info.Length() - 1].As<Napi::Function>());

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
