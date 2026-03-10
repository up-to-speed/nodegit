// Manual binding for git_mempack_new, exposed as Mempack.create()

Napi::Value GitMempack::Create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  CreateBaton *baton = new CreateBaton();
  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->out = NULL;

  Napi::FunctionReference callback;
  callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  CreateWorker *worker = new CreateWorker(baton, std::move(callback), cleanupHandles);

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitMempack::CreateWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true);
  return lockMaster;
}

void GitMempack::CreateWorker::Execute() {
  git_error_clear();

  baton->error_code = git_mempack_new(&baton->out);

  if (baton->error_code != GIT_OK && git_error_last() != NULL && git_error_last()->klass != GIT_ERROR_NONE) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitMempack::CreateWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  delete baton;
}

void GitMempack::CreateWorker::HandleOKCallback() {
  Napi::Env env = Env();

  if (baton->error_code == GIT_OK) {
    if (baton->out == NULL) {
      // This should never happen if error_code == GIT_OK
      napi_value argv[1] = {Napi::Error::New(env, "Mempack creation returned OK but produced no backend.").Value()};
      callback.Call(env.Undefined(), 1, argv);
      delete baton;
      return;
    }

    Napi::Value to = GitMempack::New(env, baton->out, false);
    napi_value argv[2] = {env.Null(), to};
    callback.Call(env.Undefined(), 2, argv);
  } else if (baton->error) {
    Napi::Object err;
    if (baton->error->message) {
      err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
    } else {
      err = Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
    }
    err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
    err.Set(Napi::String::New(env, "errorFunction"),
             Napi::String::New(env, "Mempack.create"));
    napi_value argv[1] = {err};
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
      free((void *)baton->error->message);
    free((void *)baton->error);
  } else if (baton->error_code < 0) {
    Napi::Object err =
        Napi::Error::New(env, "Method create has thrown an error.").Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errno"),
             Napi::Number::New(env, baton->error_code));
    err.Set(Napi::String::New(env, "errorFunction"),
             Napi::String::New(env, "Mempack.create"));
    napi_value argv[1] = {err};
    callback.Call(env.Undefined(), 1, argv);
  } else {
    callback.Call({});
  }

  delete baton;
}
