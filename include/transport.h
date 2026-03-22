// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITTRANSPORT_H
#define GITTRANSPORT_H
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
#include <git2/sys/transport.h>
}

#include "../include/typedefs.h"

class GitTransport;
 
struct GitTransportTraits {
  typedef GitTransport cppClass;
  typedef git_transport cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_transport **dest, git_transport *src) {
     throw std::runtime_error("duplicate called on GitTransport which cannot be duplicated");
   }

  static std::string className() { return "GitTransport"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_transport *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitTransport : public
  NodeGitWrapper<GitTransportTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitTransportTraits>;
   public:
    GitTransport(const GitTransport &) = delete;
    GitTransport(GitTransport &&) = delete;
    GitTransport &operator=(const GitTransport &) = delete;
    GitTransport &operator=(GitTransport &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

     GitTransport(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitTransportTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitTransport cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitTransport();

  private:

};

#endif
