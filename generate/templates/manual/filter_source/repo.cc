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
