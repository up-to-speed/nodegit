// This is a generated file, modify: generate/templates/templates/struct_header.h

// generated from struct_header.h
#ifndef GITPROXYOPTIONS_H
#define GITPROXYOPTIONS_H
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

  #include "../include/credential.h"
  #include "../include/cert.h"
 class GitProxyOptions;
class ConfigurableGitProxyOptions;
 
struct GitProxyOptionsTraits {
  typedef GitProxyOptions cppClass;
  typedef git_proxy_options cType;
  typedef ConfigurableGitProxyOptions configurableCppClass;
 
  static const bool isDuplicable = false;
  static void duplicate(git_proxy_options **dest, git_proxy_options *src) {
     throw std::runtime_error("duplicate called on GitProxyOptions which cannot be duplicated");
   }

  static std::string className() { return "GitProxyOptions"; };
  static const bool isSingleton = false;
  static const bool isFreeable = true;
  static void free(git_proxy_options *raw) {
    unsigned long referenceCount = 0;
     if (referenceCount == 0) {
      ::free(raw); // :: to avoid calling this free recursively
    }
   }
};
  
class ConfigurableGitProxyOptions : public nodegit::ConfigurableClassWrapper<GitProxyOptionsTraits> {
  friend class nodegit::ConfigurableClassWrapper<GitProxyOptionsTraits>;

public:
  static v8ConversionResult fromJavascript(nodegit::Context *nodegitContext, Napi::Value input);
  ~ConfigurableGitProxyOptions();

  ConfigurableGitProxyOptions(const ConfigurableGitProxyOptions &) = delete;
  ConfigurableGitProxyOptions(ConfigurableGitProxyOptions &&) = delete;
  ConfigurableGitProxyOptions &operator=(const ConfigurableGitProxyOptions &) = delete;
  ConfigurableGitProxyOptions &operator=(ConfigurableGitProxyOptions &&) = delete;

              static int credentials_cppCallback (
            git_credential ** credential
              ,
             const char * url
              ,
             const char * username_from_url
              ,
             unsigned int allowed_types
              ,
             void * payload
          );

        static void credentials_cancelAsync(void *baton);
        static void credentials_async(void *baton);
        static void credentials_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
           class CredentialsBaton : public nodegit::AsyncBatonWithResult<int> {
          public:
              git_credential ** credential;
              const char * url;
              const char * username_from_url;
              unsigned int allowed_types;
              void * payload;
 
            CredentialsBaton(const int &defaultResult)
              : nodegit::AsyncBatonWithResult<int>(defaultResult) {
              }
          };
         static ConfigurableGitProxyOptions * credentials_getInstanceFromBaton (
          CredentialsBaton *baton);
          static int certificateCheck_cppCallback (
            git_cert * cert
              ,
             int valid
              ,
             const char * host
              ,
             void * payload
          );

        static void certificateCheck_cancelAsync(void *baton);
        static void certificateCheck_async(void *baton);
        static void certificateCheck_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result);
           class CertificateCheckBaton : public nodegit::AsyncBatonWithResult<int> {
          public:
              git_cert * cert;
              int valid;
              const char * host;
              void * payload;
 
            CertificateCheckBaton(const int &defaultResult)
              : nodegit::AsyncBatonWithResult<int>(defaultResult) {
              }
          };
         static ConfigurableGitProxyOptions * certificateCheck_getInstanceFromBaton (
          CertificateCheckBaton *baton);
     
private:
  ConfigurableGitProxyOptions(nodegit::Context *nodegitContext);
  ConfigurableGitProxyOptions() = delete;
  Napi::Reference<Napi::Value> promiseError;

                  CallbackWrapper credentials;
             CallbackWrapper certificateCheck;
       
};

#endif
