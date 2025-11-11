// Actor.h
#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include "../Components/Component.h"

class Actor {
    protected:
        std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

    public:
        virtual ~Actor() = default;

        template<typename T, typename... Args>
        T* AddComponent(Args&&... args) {
            static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");

            auto Comp = std::make_unique<T>(std::forward<Args>(args)...);
            Comp->Actor = this;
            Comp->OnAdd(*this);

            T* Ptr = Comp.get();
            components[std::type_index(typeid(T))] = std::move(Comp);
            return Ptr;
        }

        template<typename T>
        T* GetComponent() {
            auto It = components.find(std::type_index(typeid(T)));
            if (It != components.end())
                return dynamic_cast<T*>(It->second.get());
            return nullptr;
        }

        template<typename T>
        bool RemoveComponent() {
            auto It = components.find(std::type_index(typeid(T)));
            if (It != components.end()) {
                components.erase(It);
                return true;
            }
            return false;
        }

        std::vector<Component*> GetComponents() {
            std::vector<Component*> Result;
            Result.reserve(components.size());
            for (auto& [_, Comp] : components) {
                Result.push_back(Comp.get());
            }
            return Result;
        }
        virtual void Setup() {
            for (auto& [_, Comp] : components)
                Comp->OnAdd(*this);
        }
        virtual void Tick(float DeltaTime) {
            for (auto& [_, Comp] : components)
                Comp->Tick(DeltaTime);
        }
        virtual void OnDestroy() {
            components.clear();
        }
};
