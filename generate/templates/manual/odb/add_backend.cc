// Manual binding for git_odb_add_backend, exposed as Odb.prototype.addMempackBackend()
// The first argument (backend) must be a Mempack object wrapping a git_odb_backend*.

Napi::Value GitOdb::AddMempackBackend(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 3) {
    Napi::Error::New(env, "Backend, priority, and callback arguments are required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[info.Length() - 1].IsFunction()) {
    Napi::Error::New(env, "Callback is required and must be a Function.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  AddMempackBackendBaton *baton = new AddMempackBackendBaton();
  baton->error_code = GIT_OK;
  baton->error = NULL;
  baton->odb = Napi::ObjectWrap<GitOdb>::Unwrap(info.This().As<Napi::Object>())->GetValue();

  // Validate and extract git_odb_backend* from the Mempack wrapper
  if (!info[0].IsObject() || info[0].IsNull() || info[0].IsUndefined()) {
    delete baton;
    Napi::TypeError::New(env, "First argument must be a Mempack object.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  baton->backend = Napi::ObjectWrap<GitMempack>::Unwrap(info[0].As<Napi::Object>())->GetValue();

  // Priority is required and must be a number
  if (!info[1].IsNumber()) {
    delete baton;
    Napi::TypeError::New(env, "Second argument (priority) must be a number.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  baton->priority = info[1].As<Napi::Number>().Int32Value();

  Napi::FunctionReference callback;
  callback = Napi::Persistent(info[info.Length() - 1].As<Napi::Function>());
  std::map<std::string, std::shared_ptr<nodegit::CleanupHandle>> cleanupHandles;
  AddMempackBackendWorker *worker = new AddMempackBackendWorker(baton, std::move(callback), cleanupHandles);

  worker->Reference<GitOdb>("odb", info.This().As<Napi::Object>());
  worker->Reference("backend", info[0]);

  // Store a reference from the backend to the ODB to prevent the ODB from
  // being garbage-collected while the backend is alive. This is critical
  // because after git_odb_add_backend, libgit2 owns the backend pointer and
  // will free it when the ODB is freed. If the ODB is GC'd first, the
  // backend's pointer becomes dangling.
  info[0].As<Napi::Object>().Set(
    Napi::String::New(env, "_parentOdb"), info.This());

  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  nodegitContext->QueueWorker(worker);
  return env.Undefined();
}

nodegit::LockMaster GitOdb::AddMempackBackendWorker::AcquireLocks() {
  nodegit::LockMaster lockMaster(true, baton->odb, baton->backend);
  return lockMaster;
}

void GitOdb::AddMempackBackendWorker::Execute() {
  git_error_clear();

  baton->error_code = git_odb_add_backend(baton->odb, baton->backend, baton->priority);

  if (baton->error_code != GIT_OK && git_error_last() != NULL && git_error_last()->klass != GIT_ERROR_NONE) {
    baton->error = git_error_dup(git_error_last());
  }
}

void GitOdb::AddMempackBackendWorker::HandleErrorCallback() {
  if (baton->error) {
    if (baton->error->message) {
      free((void *)baton->error->message);
    }

    free((void *)baton->error);
  }

  delete baton;
}

void GitOdb::AddMempackBackendWorker::HandleOKCallback() {
  Napi::Env env = Env();

  if (baton->error_code == GIT_OK) {
    napi_value argv[2] = {env.Null(), Napi::Number::New(env, baton->error_code)};
    callback.Call(env.Undefined(), 2, argv);
  } else if (baton->error) {
    Napi::Object err;
    if (baton->error->message) {
      err = Napi::Error::New(env, baton->error->message).Value().As<Napi::Object>();
    } else {
      err = Napi::Error::New(env, "Method addMempackBackend has thrown an error.").Value().As<Napi::Object>();
    }
    err.Set(Napi::String::New(env, "errno"), Napi::Number::New(env, baton->error_code));
    err.Set(Napi::String::New(env, "errorFunction"),
             Napi::String::New(env, "Odb.addMempackBackend"));
    napi_value argv[1] = {err};
    callback.Call(env.Undefined(), 1, argv);
    if (baton->error->message)
      free((void *)baton->error->message);
    free((void *)baton->error);
  } else if (baton->error_code < 0) {
    Napi::Object err =
        Napi::Error::New(env, "Method addMempackBackend has thrown an error.").Value().As<Napi::Object>();
    err.Set(Napi::String::New(env, "errno"),
             Napi::Number::New(env, baton->error_code));
    err.Set(Napi::String::New(env, "errorFunction"),
             Napi::String::New(env, "Odb.addMempackBackend"));
    napi_value argv[1] = {err};
    callback.Call(env.Undefined(), 1, argv);
  } else {
    callback.Call({});
  }

  delete baton;
}
