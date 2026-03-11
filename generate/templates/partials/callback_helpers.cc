{%each args as cbFunction %}
  {%if cbFunction.isCallbackFunction %}

{{ cbFunction.return.type }} {{ cppClassName }}::{{ cppFunctionName }}_{{ cbFunction.name }}_cppCallback (
  {% each cbFunction.args|argsInfo as arg %}
    {{ arg.cType }} {{ arg.name}}{% if not arg.lastArg %},{% endif %}
  {% endeach %}
) {
  {{ cppFunctionName }}_{{ cbFunction.name|titleCase }}Baton baton({{ cbFunction.return.noResults }});

  {% each cbFunction.args|argsInfo as arg %}
    baton.{{ arg.name }} = {{ arg.name }};
  {% endeach %}

  return baton.ExecuteAsync({{ cppFunctionName }}_{{ cbFunction.name }}_async, {{ cppFunctionName }}_{{ cbFunction.name }}_cancelAsync);
}

void {{ cppClassName }}::{{ cppFunctionName }}_{{ cbFunction.name }}_cancelAsync(void *untypedBaton) {
  {{ cppFunctionName }}_{{ cbFunction.name|titleCase }}Baton* baton = static_cast<{{ cppFunctionName }}_{{ cbFunction.name|titleCase }}Baton*>(untypedBaton);
  baton->result = {{ cbFunction.return.cancel }};
  baton->Done();
}

void {{ cppClassName }}::{{ cppFunctionName }}_{{ cbFunction.name }}_async(void *untypedBaton) {
  {{ cppFunctionName }}_{{ cbFunction.name|titleCase }}Baton* baton = static_cast<{{ cppFunctionName }}_{{ cbFunction.name|titleCase }}Baton*>(untypedBaton);

  {% each cbFunction.args|argsInfo as arg %}
    {% if arg | isPayload %}
      {% if cbFunction.payload.globalPayload %}
  Napi::FunctionReference* callback = (({{ cppFunctionName }}_globalPayload*)baton->{{ arg.name }})->{{ cbFunction.name }};
      {% else %}
  Napi::FunctionReference* callback = (Napi::FunctionReference *)baton->{{ arg.name }};
      {% endif %}
    {% endif %}
  {% endeach %}

  Napi::Env env = nodegit::Context::GetCurrentContext()->GetEnv();
  Napi::HandleScope scope(env);

  Napi::Value argv[{{ cbFunction.args|callbackArgsCount }}] = {
    {% each cbFunction.args|callbackArgsInfo as arg %}
      {% if not arg.firstArg %}, {% endif %}
      {% if arg.isEnum %}
        Napi::Number::New(env, (int)baton->{{ arg.name }})
      {% elsif arg.isLibgitType %}
        {{ arg.cppClassName }}::New(env, baton->{{ arg.name }}, false)
      {% elsif arg.cType == "size_t" %}
        // HACK: size_t needs explicit cast
        Napi::Number::New(env, (unsigned int)baton->{{ arg.name }})
      {% elsif arg.cppClassName == 'String' %}
        Napi::String::New(env, baton->{{ arg.name }})
      {% else %}
        Napi::Number::New(env, baton->{{ arg.name }})
      {% endif %}
    {% endeach %}
  };

  Napi::Value result;
  bool callSucceeded = false;
  try {
    napi_value napi_argv[{{ cbFunction.args|callbackArgsCount }}];
    for (int _i = 0; _i < {{ cbFunction.args|callbackArgsCount }}; _i++) {
      napi_argv[_i] = argv[_i];
    }
    result = callback->Call(env.Undefined(), {{ cbFunction.args|callbackArgsCount }}, napi_argv);
    callSucceeded = !result.IsEmpty();
  } catch (const Napi::Error& e) {
    // exception occurred — result is invalid, don't forward
  }

  if(callSucceeded && PromiseCompletion::ForwardIfPromise(result, baton, {{ cppFunctionName }}_{{ cbFunction.name }}_promiseCompleted)) {
    return;
  }

  {% each cbFunction|returnsInfo false true as _return %}
    if (result.IsUndefined() || result.IsNull()) {
      baton->result = baton->defaultResult;
    }
    else if (!result.IsNull() && !result.IsUndefined()) {
      {% if _return.isOutParam %}
      {{ _return.cppClassName }}* wrapper = Napi::ObjectWrap<{{ _return.cppClassName }}>::Unwrap(result.As<Napi::Object>());
      wrapper->selfFreeing = false;

      *baton->{{ _return.name }} = wrapper->GetValue();
      baton->result = {{ cbFunction.return.success }};
      {% else %}
      if (result.IsNumber()) {
        baton->result = result.As<Napi::Number>().Int32Value();
      }
      else {
        baton->result = baton->defaultResult;
      }
      {% endif %}
    }
    else {
      baton->result = baton->defaultResult;
    }
  {% endeach %}

  baton->Done();
}

void {{ cppClassName }}::{{ cppFunctionName }}_{{ cbFunction.name }}_promiseCompleted(bool isFulfilled, nodegit::AsyncBaton *_baton, Napi::Value result) {
  Napi::Env env = result.Env();
  Napi::HandleScope scope(env);

  {{ cppFunctionName }}_{{ cbFunction.name|titleCase }}Baton* baton = static_cast<{{ cppFunctionName }}_{{ cbFunction.name|titleCase }}Baton*>(_baton);

  if (isFulfilled) {
    {% each cbFunction|returnsInfo false true as _return %}
      if (result.IsUndefined() || result.IsNull()) {
        baton->result = baton->defaultResult;
      }
      else if (!result.IsNull() && !result.IsUndefined()) {
        {% if _return.isOutParam %}
        {{ _return.cppClassName }}* wrapper = Napi::ObjectWrap<{{ _return.cppClassName }}>::Unwrap(result.As<Napi::Object>());
        wrapper->selfFreeing = false;

        *baton->{{ _return.name }} = wrapper->GetValue();
        baton->result = {{ cbFunction.return.success }};
        {% else %}
        if (result.IsNumber()) {
          baton->result = result.As<Napi::Number>().Int32Value();
        }
        else {
          baton->result = baton->defaultResult;
        }
        {% endif %}
      }
      else {
        baton->result = baton->defaultResult;
      }
    {% endeach %}
  }
  else {
    // promise was rejected
    {{ cppClassName }}* instance = static_cast<{{ cppClassName }}*>(baton->{% each cbFunction.args|argsInfo as arg %}
      {% if arg.payload == true %}{{arg.name}}{% elsif arg.lastArg %}{{arg.name}}{% endif %}
    {% endeach %});
    Napi::Object parent = static_cast<Napi::ObjectWrap<{{ cppClassName }}>*>(instance)->Value();
    SetPrivate(parent, Napi::String::New(env, "NodeGitPromiseError"), result);

    baton->result = {{ cbFunction.return.error }};
  }
  baton->Done();
}
  {%endif%}
{%endeach%}
