#include <iostream>
#include "../include/promise_completion.h"

// initializes the persistent handles for PromiseCompletion
void PromiseCompletion::InitializeComponent(nodegit::Context *nodegitContext) {
  Napi::Env env = nodegitContext->GetEnv();

  Napi::Function func = DefineClass(env, "PromiseCompletion", {
    InstanceMethod("promiseFulfilled", &PromiseCompletion::PromiseFulfilled),
    InstanceMethod("promiseRejected", &PromiseCompletion::PromiseRejected),
  });

  nodegitContext->SaveToPersistent("PromiseCompletion::Template", func);
}

bool PromiseCompletion::ForwardIfPromise(Napi::Value result, nodegit::AsyncBaton *baton, Callback callback)
{
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  // check if the result is a promise
  if (!result.IsUndefined() && !result.IsNull() && result.IsObject()) {
    Napi::Object resultObj = result.As<Napi::Object>();
    Napi::Value thenProp = resultObj.Get("then");
    if (!thenProp.IsUndefined() && !thenProp.IsNull() && thenProp.IsFunction()) {
      // we can be reasonably certain that the result is a promise

      // create a new instance of PromiseCompletion
      nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
      Napi::Function constructor = nodegitContext->GetFromPersistent("PromiseCompletion::Template")
        .As<Napi::Function>();
      Napi::Object object = constructor.New({});

      // set up the native PromiseCompletion object
      PromiseCompletion *promiseCompletion = PromiseCompletion::Unwrap(object);
      promiseCompletion->Setup(thenProp.As<Napi::Function>(), result, baton, callback);

      return true;
    }
  }

  return false;
}

// constructor
PromiseCompletion::PromiseCompletion(const Napi::CallbackInfo &info)
  : Napi::ObjectWrap<PromiseCompletion>(info), callback(nullptr), baton(nullptr) {
}

// sets up a Promise to forward the promise result via the baton and callback
void PromiseCompletion::Setup(Napi::Function thenFn, Napi::Value result, nodegit::AsyncBaton *baton, Callback callback) {
  this->callback = callback;
  this->baton = baton;

  Napi::Env env = result.Env();
  Napi::Object promise = result.As<Napi::Object>();

  Napi::Object thisHandle = this->Value();
  Napi::Function promiseFulfilled = thisHandle.Get("promiseFulfilled").As<Napi::Function>();
  Napi::Function promiseRejected = thisHandle.Get("promiseRejected").As<Napi::Function>();

  Napi::Value boundFulfilled = Bind(env, promiseFulfilled, thisHandle);
  Napi::Value boundRejected = Bind(env, promiseRejected, thisHandle);

  // call the promise's .then method with resolve and reject callbacks
  thenFn.Call(promise, {boundFulfilled, boundRejected});
}

// binds an object to be the context of the function.
Napi::Value PromiseCompletion::Bind(Napi::Env env, Napi::Function function, Napi::Object object) {
  Napi::EscapableHandleScope scope(env);

  Napi::Function bind = function.Get("bind").As<Napi::Function>();
  Napi::Value bound = bind.Call(function, {object});

  return scope.Escape(bound);
}

// calls the callback stored in the PromiseCompletion, passing the baton that
// was provided in construction
void PromiseCompletion::CallCallback(bool isFulfilled, const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::Value resultOfPromise = env.Undefined();

  if (info.Length() > 0) {
    resultOfPromise = info[0];
  }

  PromiseCompletion *promiseCompletion = PromiseCompletion::Unwrap(info.This().As<Napi::Object>());

  (*promiseCompletion->callback)(isFulfilled, promiseCompletion->baton, resultOfPromise);
}

Napi::Value PromiseCompletion::PromiseFulfilled(const Napi::CallbackInfo &info) {
  CallCallback(true, info);
  return info.Env().Undefined();
}

Napi::Value PromiseCompletion::PromiseRejected(const Napi::CallbackInfo &info) {
  CallCallback(false, info);
  return info.Env().Undefined();
}
