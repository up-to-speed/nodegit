// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITDESCRIBEFORMATOPTIONS_H
#define GITDESCRIBEFORMATOPTIONS_H
#include <napi.h>
#include <string>
#include <utility>

#include "async_baton.h"
#include "async_worker.h"
#include "callback_wrapper.h"
#include "context.h"
#include "reference_counter.h"
#include "bungit_wrapper.h"
#include "configurable_class_wrapper.h"
#include "v8_helpers.h"

extern "C" {
  #include <git2.h>
  #include <git2/sys/errors.h>
 }

 class GitDescribeFormatOptions;
class ConfigurableGitDescribeFormatOptions;
 
struct GitDescribeFormatOptionsTraits {
  typedef GitDescribeFormatOptions cppClass;
  typedef git_describe_format_options cType;
  typedef ConfigurableGitDescribeFormatOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_describe_format_options **dest, git_describe_format_options *src) {
     throw std::runtime_error("duplicate called on GitDescribeFormatOptions which cannot be duplicated");
   }

  static std::string className() { return "GitDescribeFormatOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_describe_format_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitDescribeFormatOptions : public nodegit::ConfigurableClassWrapper<GitDescribeFormatOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitDescribeFormatOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitDescribeFormatOptions();

  ConfigurableGitDescribeFormatOptions(const ConfigurableGitDescribeFormatOptions &) = delete;
  ConfigurableGitDescribeFormatOptions(ConfigurableGitDescribeFormatOptions &&) = delete;
  ConfigurableGitDescribeFormatOptions &operator=(const ConfigurableGitDescribeFormatOptions &) = delete;
  ConfigurableGitDescribeFormatOptions &operator=(ConfigurableGitDescribeFormatOptions &&) = delete;

         
private:
  ConfigurableGitDescribeFormatOptions(nodegit::Context *nodegitContext);
  ConfigurableGitDescribeFormatOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

             
};

#endif
