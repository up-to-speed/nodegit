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
#include "../include/index_entry.h"
#include "bungit_wrapper.cc"

  #include "../include/index_time.h"
  #include "../include/oid.h"
 
using namespace std;

  GitIndexEntry::GitIndexEntry(const Napi::CallbackInfo &info)
   : NodeGitWrapper<GitIndexEntryTraits>(info)
  {
    if (info.Length() == 0 || !info[0].IsExternal()) {
      // Default construction: initialize with default values
      this->raw = new git_index_entry;
       this->selfFreeing = true;
    }
    this->ConstructFields();
  }

  GitIndexEntry::~GitIndexEntry() {
            this->ctime.Reset();
               this->mtime.Reset();
                                 this->id.Reset();
               }

  void GitIndexEntry::ConstructFields() {
    Napi::Env env = this->Env();
            Napi::Object ctimeTemp = GitIndexTime::New(
              env,
&this->raw->ctime,
              false
            ).As<Napi::Object>();
            this->ctime.Reset(ctimeTemp);
               Napi::Object mtimeTemp = GitIndexTime::New(
              env,
&this->raw->mtime,
              false
            ).As<Napi::Object>();
            this->mtime.Reset(mtimeTemp);
                                 Napi::Object idTemp = GitOid::New(
              env,
&this->raw->id,
              false
            ).As<Napi::Object>();
            this->id.Reset(idTemp);
               }

  void GitIndexEntry::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "IndexEntry", {
        InstanceAccessor("ctime", &GitIndexEntry::GetCtime, &GitIndexEntry::SetCtime),
          InstanceAccessor("mtime", &GitIndexEntry::GetMtime, &GitIndexEntry::SetMtime),
          InstanceAccessor("dev", &GitIndexEntry::GetDev, &GitIndexEntry::SetDev),
          InstanceAccessor("ino", &GitIndexEntry::GetIno, &GitIndexEntry::SetIno),
          InstanceAccessor("mode", &GitIndexEntry::GetMode, &GitIndexEntry::SetMode),
          InstanceAccessor("uid", &GitIndexEntry::GetUid, &GitIndexEntry::SetUid),
          InstanceAccessor("gid", &GitIndexEntry::GetGid, &GitIndexEntry::SetGid),
          InstanceAccessor("fileSize", &GitIndexEntry::GetFileSize, &GitIndexEntry::SetFileSize),
          InstanceAccessor("id", &GitIndexEntry::GetId, &GitIndexEntry::SetId),
          InstanceAccessor("flags", &GitIndexEntry::GetFlags, &GitIndexEntry::SetFlags),
          InstanceAccessor("flagsExtended", &GitIndexEntry::GetFlagsExtended, &GitIndexEntry::SetFlagsExtended),
          InstanceAccessor("path", &GitIndexEntry::GetPath, &GitIndexEntry::SetPath),
       });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("GitIndexEntry::Template", constructor_template);
    target.Set(Napi::String::New(env, "IndexEntry"), constructor_template);
  }

    Napi::Value GitIndexEntry::GetCtime(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return wrapper->ctime.Value();

     }

    void GitIndexEntry::SetCtime(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        Napi::Object ctime(value.As<Napi::Object>());

        wrapper->ctime.Reset(ctime);

           auto wrappedObject = Napi::ObjectWrap<GitIndexTime>::Unwrap(ctime);
          wrapper->raw->ctime = * wrappedObject->GetValue();
          wrapper->AddReferenceCallbacks(
            0,
            [wrappedObject]() {
              wrappedObject->Reference();
            },
            [wrappedObject]() {
              wrappedObject->Unreference();
            }
          );
      }
     Napi::Value GitIndexEntry::GetMtime(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return wrapper->mtime.Value();

     }

    void GitIndexEntry::SetMtime(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        Napi::Object mtime(value.As<Napi::Object>());

        wrapper->mtime.Reset(mtime);

           auto wrappedObject = Napi::ObjectWrap<GitIndexTime>::Unwrap(mtime);
          wrapper->raw->mtime = * wrappedObject->GetValue();
          wrapper->AddReferenceCallbacks(
            1,
            [wrappedObject]() {
              wrappedObject->Reference();
            },
            [wrappedObject]() {
              wrappedObject->Unreference();
            }
          );
      }
     Napi::Value GitIndexEntry::GetDev(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->dev);
     }

    void GitIndexEntry::SetDev(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->dev = (uint32_t) value.As<Napi::Number>().Int32Value();
        }
     }
     Napi::Value GitIndexEntry::GetIno(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->ino);
     }

    void GitIndexEntry::SetIno(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->ino = (uint32_t) value.As<Napi::Number>().Int32Value();
        }
     }
     Napi::Value GitIndexEntry::GetMode(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->mode);
     }

    void GitIndexEntry::SetMode(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->mode = (uint32_t) value.As<Napi::Number>().Int32Value();
        }
     }
     Napi::Value GitIndexEntry::GetUid(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->uid);
     }

    void GitIndexEntry::SetUid(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->uid = (uint32_t) value.As<Napi::Number>().Int32Value();
        }
     }
     Napi::Value GitIndexEntry::GetGid(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->gid);
     }

    void GitIndexEntry::SetGid(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->gid = (uint32_t) value.As<Napi::Number>().Int32Value();
        }
     }
     Napi::Value GitIndexEntry::GetFileSize(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->file_size);
     }

    void GitIndexEntry::SetFileSize(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->file_size = (uint32_t) value.As<Napi::Number>().Int32Value();
        }
     }
     Napi::Value GitIndexEntry::GetId(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return wrapper->id.Value();

     }

    void GitIndexEntry::SetId(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        Napi::Object id(value.As<Napi::Object>());

        wrapper->id.Reset(id);

           auto wrappedObject = Napi::ObjectWrap<GitOid>::Unwrap(id);
          wrapper->raw->id = * wrappedObject->GetValue();
          wrapper->AddReferenceCallbacks(
            8,
            [wrappedObject]() {
              wrappedObject->Reference();
            },
            [wrappedObject]() {
              wrappedObject->Unreference();
            }
          );
      }
     Napi::Value GitIndexEntry::GetFlags(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->flags);
     }

    void GitIndexEntry::SetFlags(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->flags = (uint16_t) value.As<Napi::Number>().Int32Value();
        }
     }
     Napi::Value GitIndexEntry::GetFlagsExtended(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        return Napi::Number::New(env, wrapper->GetValue()->flags_extended);
     }

    void GitIndexEntry::SetFlagsExtended(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

         if (value.IsNumber()) {
          wrapper->GetValue()->flags_extended = (uint16_t) value.As<Napi::Number>().Int32Value();
        }
     }
     Napi::Value GitIndexEntry::GetPath(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        if (wrapper->GetValue()->path) {
          return Napi::String::New(env, wrapper->GetValue()->path);
        }
        else {
          return env.Undefined();
        }

     }

    void GitIndexEntry::SetPath(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      GitIndexEntry *wrapper = Napi::ObjectWrap<GitIndexEntry>::Unwrap(info.This().As<Napi::Object>());

        if (wrapper->GetValue()->path) {
        }

        std::string str = value.As<Napi::String>().Utf8Value();
        wrapper->GetValue()->path = strdup(str.c_str());

     }
  
  // force base class template instantiation, to make sure we get all the
  // methods, statics, etc.
  template class NodeGitWrapper<GitIndexEntryTraits>;

 
ConfigurableGitIndexEntry::ConfigurableGitIndexEntry(nodegit::Context *nodegitContext)
  : nodegit::ConfigurableClassWrapper<GitIndexEntryTraits>(nodegitContext)
{
    this->raw = (git_index_entry*) malloc(sizeof(git_index_entry));
 }

ConfigurableGitIndexEntry::~ConfigurableGitIndexEntry() {
                              free((void*)this->raw->path);
   }

nodegit::ConfigurableClassWrapper<GitIndexEntryTraits>::v8ConversionResult ConfigurableGitIndexEntry::fromJavascript(nodegit::Context *nodegitContext, Napi::Value input) {
  if (!input.IsObject()) {
    return {
      "Must pass object for ConfigurableGitIndexEntry"
    };
  }

  Napi::Env env = input.Env();
  Napi::HandleScope scope(env);
  Napi::Object inputObj = input.As<Napi::Object>();
  std::shared_ptr<ConfigurableGitIndexEntry> output(new ConfigurableGitIndexEntry(nodegitContext));

  // unpack the data into the correct fields
        {
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "ctime");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitIndexTime::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set ctime: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->ctime = *child->GetValue();
          }
        }
          {
          Napi::Value maybeNestedObject = nodegit::safeGetField(inputObj, "mtime");
          if (!maybeNestedObject.IsUndefined() && !maybeNestedObject.IsNull()) {
            auto conversionResult = ConfigurableGitIndexTime::fromJavascript(nodegitContext, maybeNestedObject);
            if (!conversionResult.result) {
              std::string error = "Failed to set mtime: ";
              error += conversionResult.error;
              return {
                error
              };
            }

            auto child = conversionResult.result;
            output->childCleanupVector.push_back(child);
            output->raw->mtime = *child->GetValue();
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "dev");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to dev"
              };
            }

            output->raw->dev = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "ino");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to ino"
              };
            }

            output->raw->ino = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "mode");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to mode"
              };
            }

            output->raw->mode = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "uid");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to uid"
              };
            }

            output->raw->uid = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "gid");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to gid"
              };
            }

            output->raw->gid = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "fileSize");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to fileSize"
              };
            }

            output->raw->file_size = static_cast<uint32_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
            {
            Napi::Value maybeOid = nodegit::safeGetField(inputObj, "id");
            if (!maybeOid.IsUndefined() && !maybeOid.IsNull()) {
              if (maybeOid.IsString()) {
                std::string oidString = maybeOid.As<Napi::String>().Utf8Value();
                if (git_oid_fromstr(&output->raw->id, oidString.c_str()) != GIT_OK) {
                  return {
                    git_error_last()->message
                  };
                }
              } else if (maybeOid.IsObject()) {
                if (git_oid_cpy(&output->raw->id, Napi::ObjectWrap<GitOid>::Unwrap(maybeOid.As<Napi::Object>())->GetValue()) != GIT_OK) {
                  return {
                    git_error_last()->message
                  };
                }
              } else {
                return {
                  "Must pass String or NodeGit.Oid to id"
                };
              }
            }
          }
            {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "flags");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to flags"
              };
            }

            output->raw->flags = static_cast<uint16_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
           {
          Napi::Value maybeNumber = nodegit::safeGetField(inputObj, "flagsExtended");
          if (!maybeNumber.IsUndefined() && !maybeNumber.IsNull()) {
            if (!maybeNumber.IsNumber()) {
              return {
                "Must pass Int32 to flagsExtended"
              };
            }

            output->raw->flags_extended = static_cast<uint16_t>(maybeNumber.As<Napi::Number>().Int32Value());
          }
        }
          output->raw->path = nullptr;
        {
          Napi::Value maybeString = nodegit::safeGetField(inputObj, "path");
          if (!maybeString.IsUndefined() && !maybeString.IsNull()) {
            if (!maybeString.IsString()) {
              return {
                "Must pass string to path"
              };
            }

            std::string utf8String = maybeString.As<Napi::String>().Utf8Value();
            output->raw->path = strdup(utf8String.c_str());
          }
        }
    
  return {
    output
  };
}

                         
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class nodegit::ConfigurableClassWrapper<GitIndexEntryTraits>;
