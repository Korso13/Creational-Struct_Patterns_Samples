#pragma once
#include "GenericRoom.h"

class BossRoom : public GenericRoom
{
public:
    BossRoom(int size, int loot);
    BossRoom(const BossRoom& prototype) = default; //deep cloning constructor

    RoomClient* getClient() override;

private:
    GenericRoom* clone() override;
};
