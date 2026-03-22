// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITBUF_H
#define GITBUF_H
#include <napi.h>
#include <string>
#include <utility>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <sstream>

#include "async_baton.h"
#include "async_worker.h"
#include "cleanup_handle.h"
#include "context.h"
#include "lock_master.h"
#include "bungit_wrapper.h"
#include "promise_completion.h"
#include "reference_counter.h"
#include "worker_pool.h"

extern "C" {
#include <git2.h>
#include <git2/sys/errors.h>
}

#include "../include/typedefs.h"

#include "../include/git_buf_converter.h"
class GitBuf;
 
struct GitBufTraits {
  typedef GitBuf cppClass;
  typedef git_buf cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_buf **dest, git_buf *src) {
     throw std::runtime_error("duplicate called on GitBuf which cannot be duplicated");
   }

  static std::string className() { return "GitBuf"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_buf *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_buf_dispose(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitBuf : public
  NodeGitWrapper<GitBufTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitBufTraits>;
   public:
    GitBuf(const GitBuf &) = delete;
    GitBuf(GitBuf &&) = delete;
    GitBuf &operator=(const GitBuf &) = delete;
    GitBuf &operator=(GitBuf &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                       GitBuf(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitBufTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitBuf cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitBuf();

  private:

    Napi::Value Ptr(const Napi::CallbackInfo& info);
    Napi::Value Reserved(const Napi::CallbackInfo& info);
    Napi::Value Size(const Napi::CallbackInfo& info);
    Napi::Value ContainsNul(const Napi::CallbackInfo& info);
     Napi::Value Dispose(const Napi::CallbackInfo& info);
     Napi::Value Grow(const Napi::CallbackInfo& info);
     Napi::Value IsBinary(const Napi::CallbackInfo& info);
     Napi::Value Set(const Napi::CallbackInfo& info);
 };

#endif
