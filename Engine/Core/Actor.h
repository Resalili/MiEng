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

        AddComponent(Args&&... args) {


        T GetComponent()
    
        bool RemoveComponent() 

        bool HasComponent()
       
        virtual void Tick(float DeltaTime)

        virtual void OnDestroy()

        virtual void OnCreate()
        
        v
};
