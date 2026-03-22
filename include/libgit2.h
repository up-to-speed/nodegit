// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITLIBGIT2_H
#define GITLIBGIT2_H
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


class GitLibgit2 : public
  Napi::ObjectWrap<GitLibgit2>
{
   public:
    GitLibgit2(const GitLibgit2 &) = delete;
    GitLibgit2(GitLibgit2 &&) = delete;
    GitLibgit2 &operator=(const GitLibgit2 &) = delete;
    GitLibgit2 &operator=(GitLibgit2 &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

                    
  private:

     static Napi::Value FeatureBackend(const Napi::CallbackInfo& info);
      static Napi::Value Features(const Napi::CallbackInfo& info);
      static Napi::Value Init(const Napi::CallbackInfo& info);
      static Napi::Value Opts(const Napi::CallbackInfo& info);
      static Napi::Value Prerelease(const Napi::CallbackInfo& info);
      static Napi::Value Shutdown(const Napi::CallbackInfo& info);
      static Napi::Value Version(const Napi::CallbackInfo& info);
 };

#endif
