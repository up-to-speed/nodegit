#ifndef NODEGIT_V8_HELPERS_H
#define NODEGIT_V8_HELPERS_H

#include <napi.h>

namespace nodegit {
  Napi::Value safeGetField(Napi::Object &containerObj, std::string fieldName);
}

#endif
