#include <vector>
#include "Actor.h"

struct Scene
{
    std::vector<Actor*> actors;
    Actor* CreateActor() {
        Actor* NewActor = new Actor();
        actors.push_back(NewActor);
        return NewActor;
    }
    
    ~Scene() {
        for (Actor* actor : actors) {
            delete actor;
        }
    }
};
