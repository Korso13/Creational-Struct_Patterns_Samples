#pragma once
#include "WorldBuilder.h"

struct LevelBuildSettings
{
    size_t maxRooms = 10;
    size_t minRoomSize = 3;
};

struct vec2
{
    int x = 0;
    int y = 0;
};

struct Room
{
    vec2 size = {1,3};
    vec2 worldCoordsAnchor = {0, 0};
    std::vector<vec2> doorCoords; //local room coords calculated from bottom left corner, for example: {{0, 0}, {0,2}}
    std::vector<std::pair<SPTR<IAbstractWorldObject>, vec2>> roomContents; //all objects that make up the room
};

struct Level
{
    std::vector<Room> levelStructure;
    std::vector<std::pair<SPTR<IAbstractWorldObject>, vec2>> levelObjects;
};

class LevelBuilder
{
public:
    static LevelBuilder* Instance()
    {
        if(!m_levelBuilderInstance)
            m_levelBuilderInstance = new LevelBuilder();

        return m_levelBuilderInstance;
    }
    
    void fillLevel(Level& _inLevel,
        const std::vector<WorldObjectType>& _inWorldComposition,
        const LevelBuildSettings& _inLevelSettings);

private:
    LevelBuilder() = default;
    void resetBuildValues();
    void recalculateMinimumRequiredObjects();
    void calculateAverageRoomSize();
    Room generateRoom(const bool _deadEndRoom = false, const bool _firstRoom = false);
    vec2 calculateNewRoomSize(bool& _lastRoom, bool& _hasAppendixFloor) const;
    bool checkIfNeedsDoor(vec2 _roomSize, int _x, int _y, const bool _hasAppendixFloor, const bool _deadEndRoom, const bool _firstRoom);
    std::pair<SPTR<IAbstractWorldObject>, vec2> generateRandomLevelObject();
    
protected:
    static LevelBuilder* m_levelBuilderInstance;
    size_t m_maxRooms = 10;
    size_t m_minRoomSize = 3;
    size_t m_averageRoomSize = 0;

    size_t m_roomsToMake = 1;
    size_t m_doorsToMake = 0;
    size_t m_wallsToMake = 0;
    size_t m_floorsToMake = 0;
};
