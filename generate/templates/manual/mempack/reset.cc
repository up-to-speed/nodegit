// Manual binding for git_mempack_reset, exposed as Mempack.prototype.reset()

Napi::Value GitMempack::Reset(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  ResetBaton *baton = new ResetBaton();
  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->backend = Napi::ObjectWrap<GitMempack>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  Napi::FunctionReference callback;
  callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  ResetWorker *worker = new ResetWorker(baton, std::move(callback), cleanupHandles);

  worker->Reference<GitMempack>("backend", info.This().As<Napi::Object>());

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMempack::ResetWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->backend);
  return lockMaster;
}

void GitMempack::ResetWorker::Execute() {
  git_error_clear();

  baton->error_code = git_mempack_reset(baton->backend);

  if (baton->error_code != GIT_OK && git_error_last() != NULL && git_error_last()->klass != GIT_ERROR_NONE) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitMempack::ResetWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  delete baton;
}

void GitMempack::ResetWorker::HandleOKCallback() {
  Napi::Env env = Env();
  napi_value argv[1] = {env.Null()};
  callback.Call(env.Undefined(), 1, argv);

  delete baton;
}
