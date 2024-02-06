//Sample Command heir. It should be in-turn be inherited from by concrete objects on map
#pragma once
#include "Command.h"
#include "defines.h"

class PickableObject : public Command
{
public:
    PickableObject() = default;

    void execute(Actor* instigator) override;
    bool cancelTask() override;

private:
    vec2 m_objectLocation = {0.f, 0.f};
    delayedTask m_delayedTask;
};
