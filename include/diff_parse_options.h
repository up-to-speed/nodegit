// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITDIFFPARSEOPTIONS_H
#define GITDIFFPARSEOPTIONS_H
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

class GitDiffParseOptions;
 
struct GitDiffParseOptionsTraits {
  typedef GitDiffParseOptions cppClass;
  typedef git_diff_parse_options cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_diff_parse_options **dest, git_diff_parse_options *src) {
     throw std::runtime_error("duplicate called on GitDiffParseOptions which cannot be duplicated");
   }

  static std::string className() { return "GitDiffParseOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_diff_parse_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitDiffParseOptions : public
  NodeGitWrapper<GitDiffParseOptionsTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitDiffParseOptionsTraits>;
   public:
    GitDiffParseOptions(const GitDiffParseOptions &) = delete;
    GitDiffParseOptions(GitDiffParseOptions &&) = delete;
    GitDiffParseOptions &operator=(const GitDiffParseOptions &) = delete;
    GitDiffParseOptions &operator=(GitDiffParseOptions &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitDiffParseOptions(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitDiffParseOptionsTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitDiffParseOptions cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitDiffParseOptions();

  private:

    Napi::Value Version(const Napi::CallbackInfo& info);
    Napi::Value OidType(const Napi::CallbackInfo& info);
};

#endif
