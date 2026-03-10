#ifndef BUNGIT_H
#define BUNGIT_H

#include <napi.h>

Napi::Value GetPrivate(Napi::Object object, Napi::String key);

void SetPrivate(Napi::Object object, Napi::String key, Napi::Value value);

#endif
