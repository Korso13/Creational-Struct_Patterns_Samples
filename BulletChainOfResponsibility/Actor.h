#pragma once
#include <string>

#include "KillDataRequester.h"

class ActorController;
class Bullet;

class Actor : public KillDataRequester
{
public:

    Actor(KillDataRequester* parent);

    void setNewParent(KillDataRequester* parent){m_parentKDR = parent;}
    bool requestKillData(KillData& data) override;
    
    void shoot();
    
private:

    void onDeath(Bullet& killerBullet);

private:
    
    std::string m_name;
};
