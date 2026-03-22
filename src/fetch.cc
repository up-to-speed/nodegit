// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/fetch.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

 
  void GitFetch::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

       Napi::Object object = Napi::Object::New(env);
  
    target.Set(
      Napi::String::New(env, "Fetch"),
      object
    );
  }

    