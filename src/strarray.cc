// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/strarray.h"
#include "bungit_wrapper.cc"

  #include "../include/str_array_converter.h"
 
#include <iostream>

using namespace std;

  GitStrarray::~GitStrarray() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
       }

  void GitStrarray::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "Strarray", {
          InstanceMethod("copy", &GitStrarray::Copy, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
           InstanceMethod("strings", &GitStrarray::Strings, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
         InstanceMethod("count", &GitStrarray::Count, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod("getSelfFreeingInstanceCount", &GitStrarray::GetSelfFreeingInstanceCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
      StaticMethod("getNonSelfFreeingConstructedCount", &GitStrarray::GetNonSelfFreeingConstructedCount, static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitStrarray::Template", constructor_template);
    target.Set(Napi::String::New(env, "Strarray"), constructor_template);
  }

  
/*
   * @param Strarray src
     * @return Number  result    */
Napi::Value GitStrarray::Copy(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::EscapableHandleScope scope(env);

  if (info.Length() == 0 || !(info[0].ToBoolean().Value())) {
    Napi::Error::New(env, "Array, String Object, or string src is required.").ThrowAsJavaScriptException();
    return env.Undefined();
  }
// start convert_from_v8 block
  const git_strarray * from_src = NULL;

  from_src = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block

  git_error_clear();

  { // lock master scope start
    nodegit::LockMaster lockMaster(
      /*asyncAction: */false
            ,
              Napi::ObjectWrap<GitStrarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()
            ,
              from_src
    );

 int result =     git_strarray_copy(
          Napi::ObjectWrap<GitStrarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()
,          from_src
    );


      Napi::Value v8ConversionSlot;
// start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  result);
  // end convert_to_v8 block
        return scope.Escape(v8ConversionSlot);
  }
}
       // start field block
    Napi::Value GitStrarray::Strings(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            char **
           strings =
          Napi::ObjectWrap<GitStrarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()->strings;
 // start convert_to_v8 block
  if (strings){
      v8ConversionSlot = Napi::String::New(env, *strings);
   }
  else {
    v8ConversionSlot = env.Null();
  }

  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
     // start field block
    Napi::Value GitStrarray::Count(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();
      Napi::Value v8ConversionSlot;

            size_t
           count =
          Napi::ObjectWrap<GitStrarray>::Unwrap(info.This().As<Napi::Object>())->GetValue()->count;
 // start convert_to_v8 block
     v8ConversionSlot = Napi::Number::New(env,  count);
  // end convert_to_v8 block
      return v8ConversionSlot;
    }
    // end field block
  // force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<GitStrarrayTraits>;
 