// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCOMMITGRAPH_H
#define GITCOMMITGRAPH_H
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

// Forward declaration.
struct git_commit_graph {
};
class GitCommitGraph;
 
struct GitCommitGraphTraits {
  typedef GitCommitGraph cppClass;
  typedef git_commit_graph cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_commit_graph **dest, git_commit_graph *src) {
     throw std::runtime_error("duplicate called on GitCommitGraph which cannot be duplicated");
   }

  static std::string className() { return "GitCommitGraph"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_commit_graph *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitCommitGraph : public
  NodeGitWrapper<GitCommitGraphTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCommitGraphTraits>;
   public:
    GitCommitGraph(const GitCommitGraph &) = delete;
    GitCommitGraph(GitCommitGraph &&) = delete;
    GitCommitGraph &operator=(const GitCommitGraph &) = delete;
    GitCommitGraph &operator=(GitCommitGraph &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitCommitGraph(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCommitGraphTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCommitGraph cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCommitGraph();

  private:

};

#endif
