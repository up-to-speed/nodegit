// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITREFLOGENTRY_H
#define GITREFLOGENTRY_H
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

#include "../include/signature.h"
#include "../include/oid.h"
// Forward declaration.
struct git_reflog_entry {
};
class GitReflogEntry;
 
struct GitReflogEntryTraits {
  typedef GitReflogEntry cppClass;
  typedef git_reflog_entry cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_reflog_entry **dest, git_reflog_entry *src) {
     throw std::runtime_error("duplicate called on GitReflogEntry which cannot be duplicated");
   }

  static std::string className() { return "GitReflogEntry"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_reflog_entry *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitReflogEntry : public
  NodeGitWrapper<GitReflogEntryTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitReflogEntryTraits>;
   public:
    GitReflogEntry(const GitReflogEntry &) = delete;
    GitReflogEntry(GitReflogEntry &&) = delete;
    GitReflogEntry &operator=(const GitReflogEntry &) = delete;
    GitReflogEntry &operator=(GitReflogEntry &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                 GitReflogEntry(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitReflogEntryTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitReflogEntry cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitReflogEntry();

  private:

    Napi::Value Committer(const Napi::CallbackInfo& info);
     Napi::Value IdNew(const Napi::CallbackInfo& info);
     Napi::Value IdOld(const Napi::CallbackInfo& info);
     Napi::Value Message(const Napi::CallbackInfo& info);
 };

#endif
