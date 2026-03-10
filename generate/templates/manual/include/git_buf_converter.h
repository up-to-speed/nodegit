#ifndef GIT_BUF_CONVERTER_H
#define GIT_BUF_CONVERTER_H

#include <napi.h>
#include "git2/buffer.h"

class GitBufConverter {
  public:
    static git_buf *Convert(Napi::Value val);
};

#endif
