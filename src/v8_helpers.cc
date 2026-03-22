#include "../include/v8_helpers.h"

namespace nodegit {
  Napi::Value safeGetField(Napi::Object &containerObject, std::string field) {
    Napi::Env env = containerObject.Env();
    Napi::Value result = containerObject.Get(field);
    if (result.IsUndefined()) {
      return env.Undefined();
    }
    return result;
  }
}
