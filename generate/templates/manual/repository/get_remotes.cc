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
