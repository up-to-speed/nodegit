#ifndef PROMISE_COMPLETION
#define PROMISE_COMPLETION

#include <napi.h>

#include "async_baton.h"
#include "context.h"

class PromiseCompletion : public Napi::ObjectWrap<PromiseCompletion>
{
  typedef void (*Callback) (bool isFulfilled, nodegit::AsyncBaton *baton, Napi::Value resultOfPromise);

  PromiseCompletion(const Napi::CallbackInfo &info);

  Napi::Value PromiseFulfilled(const Napi::CallbackInfo &info);
  Napi::Value PromiseRejected(const Napi::CallbackInfo &info);

  static Napi::Value Bind(Napi::Env env, Napi::Function method, Napi::Object object);
  static void CallCallback(bool isFulfilled, const Napi::CallbackInfo &info);

  Callback callback;
  nodegit::AsyncBaton *baton;

  void Setup(Napi::Function thenFn, Napi::Value result, nodegit::AsyncBaton *baton, Callback callback);
public:
  static bool ForwardIfPromise(Napi::Value result, nodegit::AsyncBaton *baton, Callback callback);

  static void InitializeComponent(nodegit::Context *nodegitContext);

  friend class Napi::ObjectWrap<PromiseCompletion>;
};

#endif
