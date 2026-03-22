// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITPATHSPECMATCHLIST_H
#define GITPATHSPECMATCHLIST_H
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
// Forward declaration.
struct git_pathspec_match_list {
};
class GitPathspecMatchList;
 
struct GitPathspecMatchListTraits {
  typedef GitPathspecMatchList cppClass;
  typedef git_pathspec_match_list cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_pathspec_match_list **dest, git_pathspec_match_list *src) {
     throw std::runtime_error("duplicate called on GitPathspecMatchList which cannot be duplicated");
   }

  static std::string className() { return "GitPathspecMatchList"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_pathspec_match_list *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_pathspec_match_list_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitPathspecMatchList : public
  NodeGitWrapper<GitPathspecMatchListTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitPathspecMatchListTraits>;
   public:
    GitPathspecMatchList(const GitPathspecMatchList &) = delete;
    GitPathspecMatchList(GitPathspecMatchList &&) = delete;
    GitPathspecMatchList &operator=(const GitPathspecMatchList &) = delete;
    GitPathspecMatchList &operator=(GitPathspecMatchList &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                       GitPathspecMatchList(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitPathspecMatchListTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitPathspecMatchList cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitPathspecMatchList();

  private:

    Napi::Value DiffEntry(const Napi::CallbackInfo& info);
     Napi::Value Entry(const Napi::CallbackInfo& info);
     Napi::Value Entrycount(const Napi::CallbackInfo& info);
     Napi::Value FailedEntry(const Napi::CallbackInfo& info);
     Napi::Value FailedEntrycount(const Napi::CallbackInfo& info);
 };

#endif
