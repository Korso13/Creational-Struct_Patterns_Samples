#pragma once
#include <map>

#include "KillDataRequester.h"

class Actor;

class ActorController : public KillDataRequester
{
public: 

    ActorController();
    
    bool requestKillData(KillData& data) override;
    
    void assignActor(Actor* actor);

private:

    std::map<Actor*, int> m_controlledActors; //actor and its id
};
