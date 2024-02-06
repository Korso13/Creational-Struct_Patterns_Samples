//Sample Command heir. It should be in-turn be inherited from by concrete objects on map
#pragma once
#include "defines.h"
#include "Command.h"

class Actor;

class InteractableObject : public Command
{
public:
    InteractableObject() = default;
    
    void execute(Actor* instigator) override;
    bool cancelTask() override;

private:

    void delayedTrigger(float delay);
    void trigger(){} //map object functionality
    
private:

    bool m_isAvailable = true; //can be interacted with
    vec2 m_objectLocation = {0.f, 0.f};
    delayedTask m_delayedTask;
};
