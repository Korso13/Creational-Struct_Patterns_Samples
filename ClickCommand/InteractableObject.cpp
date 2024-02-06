#include "InteractableObject.h"
#include "Actor.h"

void InteractableObject::execute(Actor* instigator)
{
    if(!instigator || !m_isAvailable)
        return;

    instigator->moveToLocation(m_objectLocation);
    delayedTrigger(1.f);
}

bool InteractableObject::cancelTask()
{
    m_delayedTask.delayedFunc = nullptr;
    m_delayedTask.timeToOnset = 0.f;
    return true;
}

void InteractableObject::delayedTrigger(float delay)
{
    m_delayedTask.timeToOnset = delay;
    m_delayedTask.delayedFunc = [this](){trigger();};
}
