#pragma once
#include "Component.h"
#include <../Math/Vector2D.h>

class RBody : public Component {
    public:
    
        Vector2D velocity; 
        Vector2D acceleration;
        float mass;
        bool isStatic;
        bool useGravity;

        RBody(float mass = 1.0f, bool isStatic = false, bool useGravity = true)
            : mass(mass), isStatic(isStatic), useGravity(useGravity), velocity(0,0), acceleration(0,0) {}
        void addForse(const Vector2D& force) {
            if(!isStatic){
                acceleration  = force / mass;
            }
        }
        
        void Tick(float DeltaTime) override {
            if(isStatic) return;
            if (useGravity) {
                acceleration = acceleration + Vector2D(0, -9.81f); // Додаємо гравітацію
            }
            velocity = velocity + acceleration * DeltaTime;
            if (auto tr = Actor->GetComponent<Transform>()) {
                tr->position = tr->position += velocity * DeltaTime;
            }
            // Reset acceleration after each tick
            acceleration = Vector2D(0, 0);
        }
    };