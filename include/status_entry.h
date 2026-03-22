// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITSTATUSENTRY_H
#define GITSTATUSENTRY_H
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

#include "../include/diff_delta.h"
class GitStatusEntry;
 
struct GitStatusEntryTraits {
  typedef GitStatusEntry cppClass;
  typedef git_status_entry cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_status_entry **dest, git_status_entry *src) {
     throw std::runtime_error("duplicate called on GitStatusEntry which cannot be duplicated");
   }

  static std::string className() { return "GitStatusEntry"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_status_entry *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitStatusEntry : public
  NodeGitWrapper<GitStatusEntryTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitStatusEntryTraits>;
   public:
    GitStatusEntry(const GitStatusEntry &) = delete;
    GitStatusEntry(GitStatusEntry &&) = delete;
    GitStatusEntry &operator=(const GitStatusEntry &) = delete;
    GitStatusEntry &operator=(GitStatusEntry &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitStatusEntry(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitStatusEntryTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitStatusEntry cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitStatusEntry();

  private:

    Napi::Value Status(const Napi::CallbackInfo& info);
    Napi::Value HeadToIndex(const Napi::CallbackInfo& info);
    Napi::Value IndexToWorkdir(const Napi::CallbackInfo& info);
};

#endif
