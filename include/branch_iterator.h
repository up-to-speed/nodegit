// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITBRANCHITERATOR_H
#define GITBRANCHITERATOR_H
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
struct git_branch_iterator {
};
class GitBranchIterator;
 
struct GitBranchIteratorTraits {
  typedef GitBranchIterator cppClass;
  typedef git_branch_iterator cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_branch_iterator **dest, git_branch_iterator *src) {
     throw std::runtime_error("duplicate called on GitBranchIterator which cannot be duplicated");
   }

  static std::string className() { return "GitBranchIterator"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_branch_iterator *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitBranchIterator : public
  NodeGitWrapper<GitBranchIteratorTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitBranchIteratorTraits>;
   public:
    GitBranchIterator(const GitBranchIterator &) = delete;
    GitBranchIterator(GitBranchIterator &&) = delete;
    GitBranchIterator &operator=(const GitBranchIterator &) = delete;
    GitBranchIterator &operator=(GitBranchIterator &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitBranchIterator(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitBranchIteratorTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitBranchIterator cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitBranchIterator();

  private:

};

#endif
