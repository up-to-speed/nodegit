// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITFILTEROPTIONS_H
#define GITFILTEROPTIONS_H
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

#include "../include/oid.h"
class GitFilterOptions;
 
struct GitFilterOptionsTraits {
  typedef GitFilterOptions cppClass;
  typedef git_filter_options cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_filter_options **dest, git_filter_options *src) {
     throw std::runtime_error("duplicate called on GitFilterOptions which cannot be duplicated");
   }

  static std::string className() { return "GitFilterOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_filter_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitFilterOptions : public
  NodeGitWrapper<GitFilterOptionsTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitFilterOptionsTraits>;
   public:
    GitFilterOptions(const GitFilterOptions &) = delete;
    GitFilterOptions(GitFilterOptions &&) = delete;
    GitFilterOptions &operator=(const GitFilterOptions &) = delete;
    GitFilterOptions &operator=(GitFilterOptions &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitFilterOptions(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitFilterOptionsTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitFilterOptions cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitFilterOptions();

  private:

    Napi::Value Version(const Napi::CallbackInfo& info);
    Napi::Value Flags(const Napi::CallbackInfo& info);
    Napi::Value CommitId(const Napi::CallbackInfo& info);
    Napi::Value AttrCommitId(const Napi::CallbackInfo& info);
};

#endif
