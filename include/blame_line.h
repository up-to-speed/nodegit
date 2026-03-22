// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITBLAMELINE_H
#define GITBLAMELINE_H
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

class GitBlameLine;
 
struct GitBlameLineTraits {
  typedef GitBlameLine cppClass;
  typedef git_blame_line cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_blame_line **dest, git_blame_line *src) {
     throw std::runtime_error("duplicate called on GitBlameLine which cannot be duplicated");
   }

  static std::string className() { return "GitBlameLine"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_blame_line *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitBlameLine : public
  NodeGitWrapper<GitBlameLineTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitBlameLineTraits>;
   public:
    GitBlameLine(const GitBlameLine &) = delete;
    GitBlameLine(GitBlameLine &&) = delete;
    GitBlameLine &operator=(const GitBlameLine &) = delete;
    GitBlameLine &operator=(GitBlameLine &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitBlameLine(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitBlameLineTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitBlameLine cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitBlameLine();

  private:

    Napi::Value Ptr(const Napi::CallbackInfo& info);
    Napi::Value Len(const Napi::CallbackInfo& info);
};

#endif
