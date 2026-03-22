// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITMIDXWRITER_H
#define GITMIDXWRITER_H
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
struct git_midx_writer {
};
class GitMidxWriter;
 
struct GitMidxWriterTraits {
  typedef GitMidxWriter cppClass;
  typedef git_midx_writer cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_midx_writer **dest, git_midx_writer *src) {
     throw std::runtime_error("duplicate called on GitMidxWriter which cannot be duplicated");
   }

  static std::string className() { return "GitMidxWriter"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_midx_writer *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitMidxWriter : public
  NodeGitWrapper<GitMidxWriterTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitMidxWriterTraits>;
   public:
    GitMidxWriter(const GitMidxWriter &) = delete;
    GitMidxWriter(GitMidxWriter &&) = delete;
    GitMidxWriter &operator=(const GitMidxWriter &) = delete;
    GitMidxWriter &operator=(GitMidxWriter &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitMidxWriter(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitMidxWriterTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitMidxWriter cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitMidxWriter();

  private:

};

#endif
