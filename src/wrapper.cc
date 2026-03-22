#include <napi.h>
#include <string>
#include <cstring>

#include "../include/wrapper.h"

Wrapper::Wrapper(const Napi::CallbackInfo &info)
  : Napi::ObjectWrap<Wrapper>(info) {
  Napi::Env env = info.Env();
  if (info.Length() == 0 || !info[0].IsExternal()) {
    Napi::Error::New(env, "void * is required.").ThrowAsJavaScriptException();
    raw = nullptr;
    return;
  }
  raw = info[0].As<Napi::External<void>>().Data();
}

Napi::Object Wrapper::InitializeComponent(Napi::Env env, Napi::Object target, nodegit::Context *nodegitContext) {
  Napi::Function func = DefineClass(env, "Wrapper", {
    InstanceMethod("toBuffer", &Wrapper::ToBuffer, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
  });
  nodegitContext->SaveToPersistent("Wrapper::Template", func);
  target.Set("Wrapper", func);
  return target;
}

Napi::Value Wrapper::New(Napi::Env env, const void *raw) {
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  Napi::Function constructor = nodegitContext->GetFromPersistent("Wrapper::Template").As<Napi::Function>();
  return constructor.New({Napi::External<void>::New(env, const_cast<void *>(raw))});
}

void *Wrapper::GetValue() {
  return this->raw;
}

Napi::Value Wrapper::ToBuffer(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  if (info.Length() == 0 || !info[0].IsNumber()) {
    Napi::Error::New(env, "Number is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  int len = info[0].As<Napi::Number>().Int32Value();
  auto buf = Napi::Buffer<char>::Copy(env, static_cast<char *>(this->raw), len);
  return buf;
}
