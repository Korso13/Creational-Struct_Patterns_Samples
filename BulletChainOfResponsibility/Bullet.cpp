#include "Bullet.h"

Bullet::Bullet(KillDataRequester* parent)
    : KillDataRequester(parent)
{
}

bool Bullet::requestKillData(KillData& data)
{
    if(m_parentKDR)
    {
        return m_parentKDR->requestKillData(data);
    }
    else
        return false;
}
