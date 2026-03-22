// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREVSPEC_H
#define GITREVSPEC_H
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

#include "../include/object.h"
class GitRevspec;
 
struct GitRevspecTraits {
  typedef GitRevspec cppClass;
  typedef git_revspec cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_revspec **dest, git_revspec *src) {
     throw std::runtime_error("duplicate called on GitRevspec which cannot be duplicated");
   }

  static std::string className() { return "GitRevspec"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_revspec *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitRevspec : public
  NodeGitWrapper<GitRevspecTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitRevspecTraits>;
   public:
    GitRevspec(const GitRevspec &) = delete;
    GitRevspec(GitRevspec &&) = delete;
    GitRevspec &operator=(const GitRevspec &) = delete;
    GitRevspec &operator=(GitRevspec &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitRevspec(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitRevspecTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitRevspec cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitRevspec();

  private:

    Napi::Value From(const Napi::CallbackInfo& info);
    Napi::Value To(const Napi::CallbackInfo& info);
    Napi::Value Flags(const Napi::CallbackInfo& info);
};

#endif
