// This is a generated file, modify: generate/templates/templates/struct_content.cc

// generated from struct_content.cc
#include <napi.h>
#include <string.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

extern "C" {
  #include <git2.h>
 }

#include <iostream>
#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/diff_patchid_options.h"
#include "bungit_wrapper.cc"

 
using namespace std;

 
ConfigurableGitDiffPatchidOptions::ConfigurableGitDiffPatchidOptions(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitDiffPatchidOptionsTraits>(nodegitContext)
{
     git_diff_patchid_options  wrappedValue = GIT_DIFF_PATCHID_OPTIONS_INIT;
    this->raw = (git_diff_patchid_options*) malloc(sizeof(git_diff_patchid_options ));
    memcpy(this->raw, &wrappedValue, sizeof(git_diff_patchid_options ));
 }

ConfigurableGitDiffPatchidOptions::~ConfigurableGitDiffPatchidOptions() {
   }

nodegit::ConfigurableClassWrapper<GitDiffPatchidOptionsTraits>::v8ConversionResult ConfigurableGitDiffPatchidOptions::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitDiffPatchidOptions"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitDiffPatchidOptions> output(new ConfigurableGitDiffPatchidOptions(nodegitContext));

  // unpack the data into the correct fields
         {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "version");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to version"
              };
            }

            output->raw->version = static_cast<unsigned int>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

   
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitDiffPatchidOptionsTraits>;
