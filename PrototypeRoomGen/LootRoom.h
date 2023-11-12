#pragma once
#include "GenericRoom.h"

class LootRoom : public GenericRoom
{
public:
    LootRoom(int size, int enemies, int loot);
    LootRoom(const LootRoom& prototype) = default; //deep cloning constructor

    RoomClient* getClient() override;

private:
    GenericRoom* clone() override;
};
