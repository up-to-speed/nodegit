// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITERROR_H
#define GITERROR_H
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

class GitError;
 
struct GitErrorTraits {
  typedef GitError cppClass;
  typedef git_error cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_error **dest, git_error *src) {
     throw std::runtime_error("duplicate called on GitError which cannot be duplicated");
   }

  static std::string className() { return "GitError"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_error *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitError : public
  NodeGitWrapper<GitErrorTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitErrorTraits>;
   public:
    GitError(const GitError &) = delete;
    GitError(GitError &&) = delete;
    GitError &operator=(const GitError &) = delete;
    GitError &operator=(GitError &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

       GitError(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitErrorTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitError cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitError();

  private:

    Napi::Value Message(const Napi::CallbackInfo& info);
    Napi::Value Klass(const Napi::CallbackInfo& info);
    Napi::Value Last(const Napi::CallbackInfo& info);
 };

#endif
