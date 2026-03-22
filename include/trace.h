// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITTRACE_H
#define GITTRACE_H
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


class GitTrace : public
  Napi::ObjectWrap<GitTrace>
{
   public:
    GitTrace(const GitTrace &) = delete;
    GitTrace(GitTrace &&) = delete;
    GitTrace &operator=(const GitTrace &) = delete;
    GitTrace &operator=(GitTrace &&) = delete;

    static void InitializeComponent (Napi::Object target, nodegit::Context *nodegitContext);

 
  private:

};

#endif
