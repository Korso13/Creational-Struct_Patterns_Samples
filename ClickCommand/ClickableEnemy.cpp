#include "ClickableEnemy.h"
#include "Actor.h"

void ClickableEnemy::execute(Actor* instigator)
{
    if(!instigator || m_isDead)
        return;

    instigator->moveToLocation(m_enemyLocation);
    m_delayedTask.timeToOnset = 1.f; //voluntary movement time
    m_delayedTask.delayedFunc = [this, instigator]()
    {
        attack(instigator);
        instigator->attackEnemy(this);
    };
}

bool ClickableEnemy::cancelTask()
{
    return false; //task can't be cancelled
}
