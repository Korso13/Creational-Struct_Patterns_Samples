#include "LootRoom.h"

LootRoom::LootRoom(int size, int enemies, int loot)
{
    m_roomData.enemies = enemies;
    m_roomData.loot = loot;
    m_roomData.size = size;
}

GenericRoom* LootRoom::clone()
{
    return new LootRoom(*this);
}

RoomClient* LootRoom::getClient()
{
    return new RoomClient(this);
}
