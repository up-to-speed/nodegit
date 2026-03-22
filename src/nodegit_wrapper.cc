template<typename Traits>
NodeGitWrapper<Traits>::NodeGitWrapper(const Napi::CallbackInfo &info)
  : Napi::ObjectWrap<cppClass>(info), nodegitContext(nodegit::Context::GetCurrentContext(info.Env())) {
  nodegitContext->LinkTrackerList(this);

  if (info.Length() == 0 || !info[0].IsExternal()) {
    // Default construction case — the derived class default constructor
    // will handle initialization. Set defaults here.
    selfFreeing = false;
    raw = NULL;
    return;
  }

  cType *rawArg = static_cast<cType *>(info[0].As<Napi::External<void>>().Data());
  bool selfFreeingArg = info[1].As<Napi::Boolean>().Value();
  Napi::Object ownerArg;
  if (info.Length() >= 3 && !info[2].IsEmpty() && info[2].IsObject()) {
    ownerArg = info[2].As<Napi::Object>();
  }

  if (Traits::isSingleton) {
    ReferenceCounter::incrementCountForPointer((void *)rawArg);
    this->raw = rawArg;
  } else if (!ownerArg.IsEmpty()) {
    // if we have an owner, it could mean 2 things:
    //  1. We are borrowed memory from another struct and should not be freed. We will keep a handle to the owner
    //     so that the owner isn't gc'd while we are using its memory.
    //  2. We are borrowed memory from another struct and can be duplicated, so we should duplicate
    //     and become selfFreeing.
    //  3. We are cached memory, potentially on the repo or config.
    //     Even though we have a handle in another objects cache, we are expected to call free,
    //     otherwise we are leaking memory. Cached objects are reference counted in libgit2, but will be leaked
    //     even if the cache is cleared if we haven't freed them. We will keep a handle on the owner, even though it
    //     is probably safe as we're reference counted. This should at worst just ensure that the cache owner is the
    //     last thing to be freed, and that is more safety than anything else.
    if (Traits::isDuplicable) {
      Traits::duplicate(&this->raw, rawArg);
      selfFreeingArg = true;
    } else {
      SetNativeOwners(ownerArg);
      this->owner = Napi::Persistent(ownerArg);
      this->raw = rawArg;
    }
  } else {
    this->raw = rawArg;
  }
  this->selfFreeing = selfFreeingArg;

  if (selfFreeingArg) {
    SelfFreeingInstanceCount++;
  } else {
    NonSelfFreeingConstructedCount++;
  }
}

template<typename Traits>
NodeGitWrapper<Traits>::~NodeGitWrapper() {
  Unlink();
  if (Traits::isFreeable && selfFreeing) {
    Traits::free(raw);
    SelfFreeingInstanceCount--;
    raw = NULL;
  }
  else if (!selfFreeing) {
    --NonSelfFreeingConstructedCount;
  }
}

template<typename Traits>
void NodeGitWrapper<Traits>::SetNativeOwners(Napi::Object owners) {
  assert(owners.IsArray() || owners.IsObject());
  std::unique_ptr< std::vector<nodegit::TrackerWrap*> > trackerOwners =
    std::make_unique< std::vector<nodegit::TrackerWrap*> >();

  if (owners.IsArray()) {
    const Napi::Array ownersArray = owners.As<Napi::Array>();
    const uint32_t numOwners = ownersArray.Length();

    for (uint32_t i = 0; i < numOwners; ++i) {
      Napi::Value value = ownersArray.Get(i);
      Napi::Object object = value.As<Napi::Object>();
      void *wrapper = nullptr;
      napi_status status = napi_unwrap(object.Env(), object, &wrapper);
      assert(status == napi_ok && wrapper != nullptr);
      trackerOwners->push_back(static_cast<nodegit::TrackerWrap*>(wrapper));
    }
  }
  else if (owners.IsObject()) {
    void *wrapper = nullptr;
    napi_status status = napi_unwrap(owners.Env(), owners, &wrapper);
    assert(status == napi_ok && wrapper != nullptr);
    trackerOwners->push_back(static_cast<nodegit::TrackerWrap*>(wrapper));
  }

  SetTrackerWrapOwners(std::move(trackerOwners));
}

template<typename Traits>
Napi::Value NodeGitWrapper<Traits>::New(Napi::Env env, const typename Traits::cType *raw, bool selfFreeing, Napi::Object owner) {
  Napi::EscapableHandleScope scope(env);
  nodegit::Context *nodegitContext = nodegit::Context::GetCurrentContext(env);
  Napi::Function constructor = nodegitContext->GetFromPersistent(
    std::string(Traits::className()) + "::Template"
  ).As<Napi::Function>();

  Napi::Value instance;
  if (owner.IsEmpty()) {
    instance = constructor.New({
      Napi::External<void>::New(env, (void *)raw),
      Napi::Boolean::New(env, selfFreeing)
    });
  } else {
    instance = constructor.New({
      Napi::External<void>::New(env, (void *)raw),
      Napi::Boolean::New(env, selfFreeing),
      owner
    });
  }

  return scope.Escape(instance);
}

template<typename Traits>
typename Traits::cType *NodeGitWrapper<Traits>::GetValue() {
  return raw;
}

template<typename Traits>
void NodeGitWrapper<Traits>::ClearValue() {
  raw = NULL;
}

template<typename Traits>
thread_local int NodeGitWrapper<Traits>::SelfFreeingInstanceCount;

template<typename Traits>
thread_local int NodeGitWrapper<Traits>::NonSelfFreeingConstructedCount;

template<typename Traits>
Napi::Value NodeGitWrapper<Traits>::GetSelfFreeingInstanceCount(const Napi::CallbackInfo &info) {
  return Napi::Number::New(info.Env(), SelfFreeingInstanceCount);
}

template<typename Traits>
Napi::Value NodeGitWrapper<Traits>::GetNonSelfFreeingConstructedCount(const Napi::CallbackInfo &info) {
  return Napi::Number::New(info.Env(), NonSelfFreeingConstructedCount);
}

template<typename Traits>
void NodeGitWrapper<Traits>::InitializeTemplate(Napi::Function &tpl) {
  // getSelfFreeingInstanceCount and getNonSelfFreeingConstructedCount
  // are now registered via DefineClass in the generated code as static methods.
}

template<typename Traits>
void NodeGitWrapper<Traits>::Reference() {
  Ref();
  for (auto &i : referenceCallbacks) {
    i.second();
  }
}

template<typename Traits>
void NodeGitWrapper<Traits>::Unreference() {
  Unref();
  for (auto &i : unreferenceCallbacks) {
    i.second();
  }
}

template<typename Traits>
void NodeGitWrapper<Traits>::AddReferenceCallbacks(size_t fieldIndex, std::function<void()> refCb, std::function<void()> unrefCb) {
  referenceCallbacks[fieldIndex] = refCb;
  unreferenceCallbacks[fieldIndex] = unrefCb;
}

template<typename Traits>
void NodeGitWrapper<Traits>::SaveCleanupHandle(std::shared_ptr<nodegit::CleanupHandle> cleanupHandle) {
  childCleanupVector.push_back(cleanupHandle);
}
