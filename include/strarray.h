// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITSTRARRAY_H
#define GITSTRARRAY_H
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

#include "../include/str_array_converter.h"
class GitStrarray;
 
struct GitStrarrayTraits {
  typedef GitStrarray cppClass;
  typedef git_strarray cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_strarray **dest, git_strarray *src) {
     throw std::runtime_error("duplicate called on GitStrarray which cannot be duplicated");
   }

  static std::string className() { return "GitStrarray"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_strarray *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_strarray_dispose(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitStrarray : public
  NodeGitWrapper<GitStrarrayTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitStrarrayTraits>;
   public:
    GitStrarray(const GitStrarray &) = delete;
    GitStrarray(GitStrarray &&) = delete;
    GitStrarray &operator=(const GitStrarray &) = delete;
    GitStrarray &operator=(GitStrarray &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

         GitStrarray(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitStrarrayTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitStrarray cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitStrarray();

  private:

    Napi::Value Strings(const Napi::CallbackInfo& info);
    Napi::Value Count(const Napi::CallbackInfo& info);
    Napi::Value Copy(const Napi::CallbackInfo& info);
 };

#endif
