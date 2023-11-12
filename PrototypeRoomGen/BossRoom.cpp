#include "BossRoom.h"

BossRoom::BossRoom(int size, int loot)
{
    m_roomData.enemies = 1;
    m_roomData.loot = loot;
    m_roomData.size = size;
}

GenericRoom* BossRoom::clone()
{
    return new BossRoom(*this);
}

RoomClient* BossRoom::getClient()
{
    return new RoomClient(this);
}
