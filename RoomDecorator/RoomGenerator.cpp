#include "RoomGenerator.h"

#include "Decorator.h"
#include "Room.h"
#include "RoomBloodFX.h"
#include "RoomDistortion.h"

RoomGenerator* RoomGenerator::m_instance = nullptr;

LevelComponent* RoomGenerator::makeRoom(roomSize _size, bool _bHasDistortions, bool _bHasBloodFX) const
{
    LevelComponent* resultingRoom = new Room(_size);

    if(_bHasDistortions)
    {
        Decorator* decoratedRoom = new RoomDistortion();
        decoratedRoom->addComponent(resultingRoom);
        resultingRoom = decoratedRoom;
    }

    if(_bHasBloodFX)
    {
        Decorator* decoratedRoom = new RoomBloodFX();
        decoratedRoom->addComponent(resultingRoom);
        resultingRoom = decoratedRoom;
    }

    return resultingRoom;
}
