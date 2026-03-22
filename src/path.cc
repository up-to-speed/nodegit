// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/path.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/path.h"
#include "bungit_wrapper.cc"

 
#include <iostream>

using namespace std;

 
  void GitPath::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

       Napi::Object object = Napi::Object::New(env);
         object.Set("isGitfile", Napi::Function::New(env, IsGitfile));
  
    target.Set(
      Napi::String::New(env, "Path"),
      object
    );
  }

  
/*
 * @param String path
   * @param Number pathlen
   * @param Number gitfile
   * @param Number fs
     * @return Number  result    */
Napi::Value GitPath::IsGitfile(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !info[0].IsString()) {
    Napi::Error::New(env, "String path is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 1 || !info[1].IsNumber()) {
    Napi::Error::New(env, "Number pathlen is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 2 || !info[2].IsNumber()) {
    Napi::Error::New(env, "Number gitfile is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (info.Length() == 3 || !info[3].IsNumber()) {
    Napi::Error::New(env, "Number fs is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }

// start convert_from_v8 block
  const char * from_path = NULL;

  std::string path = info[0].As<Napi::String>().Utf8Value();
  // malloc with one extra byte so we can add the terminating null character C-strings expect:
  from_path = (const char *) malloc(path.length() + 1);
  // copy the characters from the nodejs string into our C-string (used instead of strdup or strcpy because nulls in
  // the middle of strings are valid coming from nodejs):
  memcpy((void *)from_path, path.c_str(), path.length());
  // ensure the final byte of our new string is null, extra casts added to ensure compatibility with various C types
  // used in the nodejs binding generation:
  memset((void *)(((char *)from_path) + path.length()), 0, 1);
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_pathlen;
      from_pathlen = (size_t)   info[1].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
// start convert_from_v8 block
  git_path_gitfile from_gitfile;
      from_gitfile = (git_path_gitfile)  (int) info[2].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block
// start convert_from_v8 block
  git_path_fs from_fs;
      from_fs = (git_path_fs)  (int) info[3].As<Napi::Number>().DoubleValue ();
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              from_path
    );

 int result =     git_path_is_gitfile(
          from_path
,          from_pathlen
,          from_gitfile
,          from_fs
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
     