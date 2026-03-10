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
  callback.Reset(info[info.Length() - 1].As<Napi::Function>());
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
