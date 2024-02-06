//Sample Command heir. It should be in-turn be inherited from by concrete objects on map
#pragma once
#include "Command.h"
#include "defines.h"

class ClickableEnemy : public Command
{
public:
    ClickableEnemy() = default;

    void attack(Actor* player){}
    
    void execute(Actor* instigator) override;
    bool cancelTask() override;

private:
    bool m_isDead = false; //can be interacted with
    vec2 m_enemyLocation = {0.f, 0.f};
    delayedTask m_delayedTask;
};
