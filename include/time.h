// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITTIME_H
#define GITTIME_H
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

class GitTime;
 
struct GitTimeTraits {
  typedef GitTime cppClass;
  typedef git_time cType;
 
  static const bool isDuplicable = true;
  static void duplicate(git_time **dest, git_time *src) {
    git_time_dup(dest, src);
   }

  static std::string className() { return "GitTime"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_time *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitTime : public
  NodeGitWrapper<GitTimeTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitTimeTraits>;
   public:
    GitTime(const GitTime &) = delete;
    GitTime(GitTime &&) = delete;
    GitTime &operator=(const GitTime &) = delete;
    GitTime &operator=(GitTime &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitTime(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitTimeTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitTime cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitTime();

  private:

    Napi::Value Time(const Napi::CallbackInfo& info);
    Napi::Value Offset(const Napi::CallbackInfo& info);
    Napi::Value Sign(const Napi::CallbackInfo& info);
};

#endif
