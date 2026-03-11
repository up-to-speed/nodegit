#include <napi.h>
#include <string>

#include "../include/git_buf_converter.h"
#include "git2/buffer.h"

git_buf *GitBufConverter::Convert(Napi::Value val) {
  // Handle String objects (new String("...")) by extracting the primitive value.
  // N-API's IsString() only returns true for string primitives, not String objects.
  if (!val.IsString() && val.IsObject()) {
    Napi::Object obj = val.As<Napi::Object>();
    Napi::Value toString = obj.Get("toString");
    if (toString.IsFunction()) {
      val = toString.As<Napi::Function>().Call(obj, {});
    }
  }
  if (val.IsString()) {
    std::string v8String = val.As<Napi::String>().Utf8Value();

    const size_t size = sizeof(git_buf);
    uint8_t* memory = reinterpret_cast<uint8_t *>(malloc(size));
    git_buf *result = reinterpret_cast<git_buf *>(memory);
    size_t stringLength = v8String.length();

    memory = reinterpret_cast<uint8_t *>(malloc(stringLength));

    memcpy(memory, v8String.c_str(), stringLength);

    result->reserved = stringLength;
    result->size = stringLength;
    result->ptr = reinterpret_cast<char *>(memory);
    return result;
  } else {
    return NULL;
  }
}
