// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITWRITESTREAM_H
#define GITWRITESTREAM_H
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

class GitWritestream;
 
struct GitWritestreamTraits {
  typedef GitWritestream cppClass;
  typedef git_writestream cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_writestream **dest, git_writestream *src) {
     throw std::runtime_error("duplicate called on GitWritestream which cannot be duplicated");
   }

  static std::string className() { return "GitWritestream"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_writestream *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitWritestream : public
  NodeGitWrapper<GitWritestreamTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitWritestreamTraits>;
   public:
    GitWritestream(const GitWritestream &) = delete;
    GitWritestream(GitWritestream &&) = delete;
    GitWritestream &operator=(const GitWritestream &) = delete;
    GitWritestream &operator=(GitWritestream &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitWritestream(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitWritestreamTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitWritestream cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitWritestream();

  private:

};

#endif
