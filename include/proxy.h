// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITPROXY_H
#define GITPROXY_H
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


class GitProxy : public
  Napi::ObjectWrap<GitProxy>
{
   public:
    GitProxy(const GitProxy &) = delete;
    GitProxy(GitProxy &&) = delete;
    GitProxy &operator=(const GitProxy &) = delete;
    GitProxy &operator=(GitProxy &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

 
  private:

};

#endif
