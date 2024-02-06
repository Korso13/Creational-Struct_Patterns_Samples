#include "PickableObject.h"
#include "Actor.h"

void PickableObject::execute(Actor* instigator)
{
    if(!instigator)
        return;

    instigator->moveToLocation(m_objectLocation);
    m_delayedTask.timeToOnset = 1.f; //voluntary movement time
    m_delayedTask.delayedFunc = [this, instigator](){instigator->pickObject(this);};
}

bool PickableObject::cancelTask()
{
    m_delayedTask.delayedFunc = nullptr;
    m_delayedTask.timeToOnset = 0.f;
    return true;
}
