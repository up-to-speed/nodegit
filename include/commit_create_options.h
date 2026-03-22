// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCOMMITCREATEOPTIONS_H
#define GITCOMMITCREATEOPTIONS_H
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
class GitCommitCreateOptions;
 
struct GitCommitCreateOptionsTraits {
  typedef GitCommitCreateOptions cppClass;
  typedef git_commit_create_options cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_commit_create_options **dest, git_commit_create_options *src) {
     throw std::runtime_error("duplicate called on GitCommitCreateOptions which cannot be duplicated");
   }

  static std::string className() { return "GitCommitCreateOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = false;
  static void free(git_commit_create_options *raw) {
     throw std::runtime_error("free called on GitCommitCreateOptions which cannot be freed");
   }
};

class GitCommitCreateOptions : public
  NodeGitWrapper<GitCommitCreateOptionsTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCommitCreateOptionsTraits>;
   public:
    GitCommitCreateOptions(const GitCommitCreateOptions &) = delete;
    GitCommitCreateOptions(GitCommitCreateOptions &&) = delete;
    GitCommitCreateOptions &operator=(const GitCommitCreateOptions &) = delete;
    GitCommitCreateOptions &operator=(GitCommitCreateOptions &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitCommitCreateOptions(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCommitCreateOptionsTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCommitCreateOptions cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCommitCreateOptions();

  private:

    Napi::Value Version(const Napi::CallbackInfo& info);
    Napi::Value AllowEmptyCommit(const Napi::CallbackInfo& info);
    Napi::Value Author(const Napi::CallbackInfo& info);
    Napi::Value Committer(const Napi::CallbackInfo& info);
    Napi::Value MessageEncoding(const Napi::CallbackInfo& info);
};

#endif
