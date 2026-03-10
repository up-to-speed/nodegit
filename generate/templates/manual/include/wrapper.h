#ifndef WRAPPER_H
#define WRAPPER_H

#include <napi.h>
#include "context.h"

class Wrapper : public Napi::ObjectWrap<Wrapper> {
  public:
    static Napi::Object InitializeComponent(Napi::Env env, Napi::Object target, nodegit::Context *nodegitContext);

    void *GetValue();
    static Napi::Value New(Napi::Env env, const void *raw);

    Wrapper(const Napi::CallbackInfo &info);

    Napi::Value ToBuffer(const Napi::CallbackInfo &info);

  private:
    void *raw;
};

#endif
