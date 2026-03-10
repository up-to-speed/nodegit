{% each fields|fieldsInfo as field %}
  {% if not field.ignore %}
    Napi::Value {{ cppClassName }}::Get{{ field.cppFunctionName }}(const Napi::CallbackInfo& info) {
      Napi::Env env = info.Env();

      {{ cppClassName }} *wrapper = Napi::ObjectWrap<{{ cppClassName }}>::Unwrap(info.This().As<Napi::Object>());

      {% if field.isEnum %}
        return Napi::Number::New(env, (int)wrapper->GetValue()->{{ field.name }});

      {% elsif field.isLibgitType %}
        return wrapper->{{ field.name }}.Value();

      {% elsif field.cppClassName == 'String' %}
        if (wrapper->GetValue()->{{ field.name }}) {
          return Napi::String::New(env, wrapper->GetValue()->{{ field.name }});
        }
        else {
          return env.Undefined();
        }

      {% elsif field.cppClassName|isV8Value %}
        return Napi::Number::New(env, wrapper->GetValue()->{{ field.name }});
      {% endif %}
    }

    void {{ cppClassName }}::Set{{ field.cppFunctionName }}(const Napi::CallbackInfo& info, const Napi::Value& value) {
      Napi::Env env = info.Env();
      {{ cppClassName }} *wrapper = Napi::ObjectWrap<{{ cppClassName }}>::Unwrap(info.This().As<Napi::Object>());

      {% if field.isEnum %}
        if (value.IsNumber()) {
          wrapper->GetValue()->{{ field.name }} = ({{ field.cType }}) value.As<Napi::Number>().Int32Value();
        }

      {% elsif field.isLibgitType %}
        Napi::Object {{ field.name }}(value.As<Napi::Object>());

        wrapper->{{ field.name }}.Reset({{ field.name }});

        {% if field.cppClassName == 'GitStrarray' %}
          wrapper->raw->{{ field.name }} = {% if not field.cType | isPointer %}*{% endif %}StrArrayConverter::Convert({{ field.name }});
        {% else %}
          auto wrappedObject = Napi::ObjectWrap<{{ field.cppClassName }}>::Unwrap({{ field.name }});
          wrapper->raw->{{ field.name }} = {% if not field.cType | isPointer %}*{% endif %}wrappedObject->GetValue();
          {%-- We are assuming that users are responsible enough to not replace fields on their structs mid-operation, and would rather build out code to prevent that than be smarter here --%}
          wrapper->AddReferenceCallbacks(
            {{ field.index }},
            [wrappedObject]() {
              wrappedObject->Reference();
            },
            [wrappedObject]() {
              wrappedObject->Unreference();
            }
          );
        {% endif %}

      {% elsif field.cppClassName == 'String' %}
        if (wrapper->GetValue()->{{ field.name }}) {
        }

        std::string str = value.As<Napi::String>().Utf8Value();
        wrapper->GetValue()->{{ field.name }} = strdup(str.c_str());

      {% elsif field.isCppClassIntType %}
        if (value.IsNumber()) {
          wrapper->GetValue()->{{ field.name }} = value.As<Napi::Number>().{{field.cppClassName}}Value();
        }

      {% else %}
        if (value.IsNumber()) {
          wrapper->GetValue()->{{ field.name }} = ({{ field.cType }}) value.As<Napi::Number>().Int32Value();
        }
      {% endif %}
    }
  {% endif %}
{% endeach %}
