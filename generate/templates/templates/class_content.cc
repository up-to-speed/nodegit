#include <napi.h>
#include <string.h>

extern "C" {
  #include <git2.h>
  {% each cDependencies as dependency %}
    #include <{{ dependency }}>
  {% endeach %}
}

#include "../include/bungit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/{{ filename }}.h"
#include "bungit_wrapper.cc"

{% each dependencies as dependency %}
  #include "{{ dependency }}"
{% endeach %}

#include <iostream>

using namespace std;

{% if cType %}
  {{ cppClassName }}::~{{ cppClassName }}() {
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
    {% each functions as function %}
      {% if not function.ignore %}
        {% each function.args as arg %}
          {% if arg.saveArg %}

      {{ function.cppFunctionName }}_{{ arg.name }}).Reset();

          {% endif %}
        {% endeach %}
      {% endif %}
    {% endeach %}
  }

  void {{ cppClassName }}::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);

    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    Napi::Function constructor_template = DefineClass(env, "{{ jsClassName }}", {
    {% each functions as function %}
      {% if not function.ignore %}
        {% if function.isPrototypeMethod %}
          InstanceMethod("{{ function.jsFunctionName }}", &{{ cppClassName }}::{{ function.cppFunctionName }}),
        {% else %}
          StaticMethod("{{ function.jsFunctionName }}", &{{ cppClassName }}::{{ function.cppFunctionName }}),
        {% endif %}
      {% endif %}
    {% endeach %}

    {% each fields as field %}
      {% if not field.ignore %}
        InstanceMethod("{{ field.jsFunctionName }}", &{{ cppClassName }}::{{ field.cppFunctionName }}),
      {% endif %}
    {% endeach %}
    });

    InitializeTemplate(constructor_template);

    nodegitContext->SaveToPersistent("{{ cppClassName }}::Template", constructor_template);
    target.Set(Napi::String::New(env, "{{ jsClassName }}"), constructor_template);
  }

{% else %}

  void {{ cppClassName }}::InitializeComponent(Napi::Object target, nodegit::Context *nodegitContext) {
    Napi::Env env = target.Env();
    Napi::HandleScope scope(env);
    Napi::External<void> nodegitExternal = Napi::External<void>::New(env, nodegitContext);

    {% if functions|hasFunctionOnRootProto %}
      Napi::Function object = Napi::Function::New(env, {{ functions|getCPPFunctionForRootProto }});
    {% else %}
      Napi::Object object = Napi::Object::New(env);
    {% endif %}

    {% each functions as function %}
      {% if not function.ignore %}
        object.Set("{{ function.jsFunctionName }}", Napi::Function::New(env, {{ function.cppFunctionName }}));
      {% endif %}
    {% endeach %}

    target.Set(
      Napi::String::New(env, "{{ jsClassName }}"),
      object
    );
  }

{% endif %}

{% each functions as function %}
  {% if not function.ignore %}
    {% if function.isManual %}
      {{= function.implementation =}}
    {% elsif function.isAsync %}
      {% partial asyncFunction function %}
    {% else %}
      {% partial syncFunction function %}
    {% endif %}
  {% endif %}
{% endeach %}

{% partial fields . %}

{%if cType %}
// force base class template instantiation, to make sure we get all the
// methods, statics, etc.
template class NodeGitWrapper<{{ cppClassName }}Traits>;
{% endif %}
