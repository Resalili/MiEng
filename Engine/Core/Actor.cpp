
#include "Actor.h"
#include <unordered_map>


Actor::Actor() {
    OnCreate();
}

template<typename T>
bool Actor::HasComponent() {
    return components.find(typeid(T)) != components.end();
}

template<typename T>
T* Actor::GetComponent() {
    auto it = components.find(typeid(T));
    if (it != components.end())
        return static_cast<T*>(it->second.get());
    return nullptr;
}

template<typename T, typename... Args>
Actor::AddComponent(Args&&... args) {
    static_assert(std::is_base_of<Component, T>::value,
                  "T must derive from Component");

    auto component = std::make_unique<T>(std::forward<Args>(args)...);
    component->Actor = this;
    component->OnAdd(*this);

    T& ref = *component; // збережемо ref перед move

    components[typeid(T)] = std::move(component);
}


Actor::Tick(float DeltaTime) {
    for (auto& pair : components) {
        pair.second->Tick(DeltaTime);
    }
}





Actor::~Actor() {
    OnDestroy();
    components.clear();
}