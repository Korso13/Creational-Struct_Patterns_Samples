#pragma once
#include "LevelComponent.h"

class LevelComponent;

//Room factory
class RoomGenerator
{
public:

    static RoomGenerator* getInstance()
    {
        if(!m_instance)
            m_instance = new RoomGenerator();

        return m_instance;
    }
    LevelComponent* makeRoom(roomSize _size, bool _bHasDistortions = false, bool _bHasBloodFX = false) const;

private:
    RoomGenerator() = default;

    static RoomGenerator* m_instance = nullptr;
};
