#include "ActorController.h"

#include "Defines.h"

ActorController::ActorController()
    : KillDataRequester(nullptr)
{
    
}

void ActorController::assignActor(Actor* actor)
{
    m_controlledActors.insert({actor, m_controlledActors.size() });
    actor->setNewParent(this);
}

bool ActorController::requestKillData(KillData& data)
{
    if(m_controlledActors.find(data.killer) != m_controlledActors.end())
    {
        data.killerId = m_controlledActors.at(data.killer);
        return true;
    }
    else if(m_controlledActors.find(data.victim) != m_controlledActors.end())
    {
        data.victimId = m_controlledActors.at(data.victim);
        return true;
    }
    else
    {
        return false;
    }
}
