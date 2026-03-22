// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITODBOBJECT_H
#define GITODBOBJECT_H
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

#include "../include/wrapper.h"
#include "node_buffer.h"
#include "../include/oid.h"
// Forward declaration.
struct git_odb_object {
};
class GitOdbObject;
 
struct GitOdbObjectTraits {
  typedef GitOdbObject cppClass;
  typedef git_odb_object cType;
 
  static const bool isDuplicable = false;
  static void duplicate(git_odb_object **dest, git_odb_object *src) {
     throw std::runtime_error("duplicate called on GitOdbObject which cannot be duplicated");
   }

  static std::string className() { return "GitOdbObject"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_odb_object *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::git_odb_object_free(raw); // :: to avoid calling this free recursively
    }
   }
};

class GitOdbObject : public
  NodeGitWrapper<GitOdbObjectTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitOdbObjectTraits>;
   public:
    GitOdbObject(const GitOdbObject &) = delete;
    GitOdbObject(GitOdbObject &&) = delete;
    GitOdbObject &operator=(const GitOdbObject &) = delete;
    GitOdbObject &operator=(GitOdbObject &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                 GitOdbObject(const Napi::CallbackInfo &info)
      : NodeGitWrapper<GitOdbObjectTraits>(info)
    {
      if (info.Length() == 0 || !info[0].IsExternal()) {
        Napi::TypeError::New(info.Env(), "GitOdbObject cannot be instantiated directly").ThrowAsJavaScriptException();
      }
    }
    ~GitOdbObject();

  private:

    Napi::Value Data(const Napi::CallbackInfo& info);
     Napi::Value Id(const Napi::CallbackInfo& info);
     Napi::Value Size(const Napi::CallbackInfo& info);
     Napi::Value Type(const Napi::CallbackInfo& info);
 };

#endif
