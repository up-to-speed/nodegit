// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITFETCH_H
#define GITFETCH_H
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


class GitFetch : public
  Napi::ObjectWrap<GitFetch>
{
   public:
    GitFetch(const GitFetch &) = delete;
    GitFetch(GitFetch &&) = delete;
    GitFetch &operator=(const GitFetch &) = delete;
    GitFetch &operator=(GitFetch &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

 
  private:

};

#endif
