#include "Actor.h"

#include "Bullet.h"
#include "Defines.h"

Actor::Actor(KillDataRequester* parent)
    : KillDataRequester(parent)
{
    
}

bool Actor::requestKillData(KillData& data)
{
    if(data.killer == this)
    {
        data.killerName = m_name;
    }
    else if(data.victim == this)
    {
        data.victimName = m_name;
    }
    
    if(m_parentKDR)
    {
        return m_parentKDR->requestKillData(data);
    }
    else
        return false;
}

void Actor::shoot()
{
    Bullet* bullet = new Bullet(this);
}

//Chain of responsibility in action!!
void Actor::onDeath(Bullet& killerBullet)
{
    KillData killDataSheet;
    killDataSheet.victim = this;
    //CoR can start from any bit of chain
    const bool victimDataCollected = requestKillData(killDataSheet);

    //CoR helps assemble data from several objects in the chain
    const bool killerDataCollected = killerBullet.requestKillData(killDataSheet);

    if(!victimDataCollected)
        printError("Failed to fill victim data!");
    if(!killerDataCollected)
        printError("Failed to fill killer data!");
}
