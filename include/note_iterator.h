// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITNOTEITERATOR_H
#define GITNOTEITERATOR_H
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

class GitNoteIterator;
 
struct GitNoteIteratorTraits {
  typedef GitNoteIterator cppClass;
  typedef git_note_iterator cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_note_iterator **dest, git_note_iterator *src) {
     throw std::runtime_error("duplicate called on GitNoteIterator which cannot be duplicated");
   }

  static std::string className() { return "GitNoteIterator"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_note_iterator *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitNoteIterator : public
  NodeGitWrapper<GitNoteIteratorTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitNoteIteratorTraits>;
   public:
    GitNoteIterator(const GitNoteIterator &) = delete;
    GitNoteIterator(GitNoteIterator &&) = delete;
    GitNoteIterator &operator=(const GitNoteIterator &) = delete;
    GitNoteIterator &operator=(GitNoteIterator &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitNoteIterator(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitNoteIteratorTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitNoteIterator cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitNoteIterator();

  private:

};

#endif
