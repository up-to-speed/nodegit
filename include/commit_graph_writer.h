// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCOMMITGRAPHWRITER_H
#define GITCOMMITGRAPHWRITER_H
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
struct git_commit_graph_writer {
};
class GitCommitGraphWriter;
 
struct GitCommitGraphWriterTraits {
  typedef GitCommitGraphWriter cppClass;
  typedef git_commit_graph_writer cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_commit_graph_writer **dest, git_commit_graph_writer *src) {
     throw std::runtime_error("duplicate called on GitCommitGraphWriter which cannot be duplicated");
   }

  static std::string className() { return "GitCommitGraphWriter"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_commit_graph_writer *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitCommitGraphWriter : public
  NodeGitWrapper<GitCommitGraphWriterTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitCommitGraphWriterTraits>;
   public:
    GitCommitGraphWriter(const GitCommitGraphWriter &) = delete;
    GitCommitGraphWriter(GitCommitGraphWriter &&) = delete;
    GitCommitGraphWriter &operator=(const GitCommitGraphWriter &) = delete;
    GitCommitGraphWriter &operator=(GitCommitGraphWriter &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitCommitGraphWriter(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitCommitGraphWriterTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitCommitGraphWriter cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitCommitGraphWriter();

  private:

};

#endif
