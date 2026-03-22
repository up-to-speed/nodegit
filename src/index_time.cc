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
#include "../include/index_time.h"
#include "bungit_wrapper.cc"

 
using namespace std;

  GitIndexTime::GitIndexTime(const Napi::CallbackInfo &info)
   : NodeGitWrapper<GitIndexTimeTraits>(info)
  {
    if (info.Length() == 0 || !info[0].IsExternal()) {
      // Default construction: initialize with default values
      this->raw = new git_index_time;
       this->selfFreeing = true;
    }
    this->ConstructFields();
  }

  GitIndexTime::~GitIndexTime() {
         }

  void GitIndexTime::ConstructFields() {
    Napi::Env env = this->Env();
         }

  void GitIndexTime::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "IndexTime", {
        InstanceAccessor("seconds", &GitIndexTime::GetSeconds, &GitIndexTime::SetSeconds),
          InstanceAccessor("nanoseconds", &GitIndexTime::GetNanoseconds, &GitIndexTime::SetNanoseconds),
       });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitIndexTime::Template", constructor_template);
    target.Set(Napi::String::New(env, "IndexTime"), constructor_template);
  }

    Napi::Value GitIndexTime::GetSeconds(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexTime *wrapper = Napi::ObjectWrap<GitIndexTime>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->seconds);
     }

    void GitIndexTime::SetSeconds(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexTime *wrapper = Napi::ObjectWrap<GitIndexTime>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->seconds = (int32_t) value.As<Napi::Number>().Int32Value();
        }
     }
     Napi::Value GitIndexTime::GetNanoseconds(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexTime *wrapper = Napi::ObjectWrap<GitIndexTime>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->nanoseconds);
     }

    void GitIndexTime::SetNanoseconds(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexTime *wrapper = Napi::ObjectWrap<GitIndexTime>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->nanoseconds = (uint32_t) value.As<Napi::Number>().Int32Value();
        }
     }
  
  // force base class template instantiation, to make sure we get all the
  // methods, statics, etc.
  template class NodeGitWrapper<GitIndexTimeTraits>;

 
ConfigurableGitIndexTime::ConfigurableGitIndexTime(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitIndexTimeTraits>(nodegitContext)
{
    this->raw = (git_index_time*) malloc(sizeof(git_index_time));
 }

ConfigurableGitIndexTime::~ConfigurableGitIndexTime() {
     }

nodegit::ConfigurableClassWrapper<GitIndexTimeTraits>::v8ConversionResult ConfigurableGitIndexTime::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitIndexTime"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitIndexTime> output(new ConfigurableGitIndexTime(nodegitContext));

  // unpack the data into the correct fields
         {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "seconds");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to seconds"
              };
            }

            output->raw->seconds = static_cast<int32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "nanoseconds");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to nanoseconds"
              };
            }

            output->raw->nanoseconds = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
    
  return {
    output
  };
}

     
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitIndexTimeTraits>;
