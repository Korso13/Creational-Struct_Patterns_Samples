#include "LevelBuilder.h"

#include "objects_library/Wall.h"

typedef std::pair<SPTR<IAbstractWorldObject>, vec2> levelObject;

void LevelBuilder::fillLevel(
    Level& _inLevel,
    const std::vector<WorldObjectType>& _inWorldComposition,
    const LevelBuildSettings& _inLevelSettings)
{
    resetBuildValues();
    m_maxRooms = _inLevelSettings.maxRooms;
    m_minRoomSize = _inLevelSettings.minRoomSize;

    for (const auto element : _inWorldComposition)
    {
        switch (element)
        {
        case WorldObjectType::NONE:
            break;
        case WorldObjectType::FLOOR:
            m_floorsToMake++;
            break;
        case WorldObjectType::WALL:
            m_wallsToMake++;
            break;
        case WorldObjectType::DOOR:
            m_doorsToMake++;
            m_roomsToMake++;
            if(m_roomsToMake > m_maxRooms)
                m_roomsToMake = m_maxRooms;
            break;
        default:
            break;
        }
    }

    recalculateMinimumRequiredObjects();

    for (size_t i = 0; i < m_roomsToMake; i++)
    {
        _inLevel.levelStructure.push_back(generateRoom());
    }

    //some elaborate code for filling rooms with stuff
     for(size_t i = 0; i < m_roomsToMake * 2; i++)
     {
        _inLevel.levelObjects.push_back(generateRandomLevelObject());
     }
  
}

void LevelBuilder::resetBuildValues()
{
    m_roomsToMake = 1;
    m_doorsToMake = 0;
    m_wallsToMake = 0;
    m_floorsToMake = 0;
    m_averageRoomSize = 0;
}

void LevelBuilder::recalculateMinimumRequiredObjects()
{
    if(m_roomsToMake * m_minRoomSize > m_floorsToMake)
        m_floorsToMake = m_roomsToMake * m_minRoomSize;

    const int ThreeWallsSectionsMode = (m_minRoomSize == 3) ? (2) : 1;
    const bool rectangleRooms = (m_floorsToMake / m_roomsToMake) % 2 == 0;
    size_t minWallsNeeded;
    if(rectangleRooms)
    {
        minWallsNeeded = m_floorsToMake * 2 - m_doorsToMake;
    }
    else
    {
        minWallsNeeded = (m_floorsToMake - 1 * ThreeWallsSectionsMode * 2) * 2 + (1 * ThreeWallsSectionsMode * 2) * 3; //very approximate for simplicity reasons 
    }

    if(m_wallsToMake < minWallsNeeded)
        m_wallsToMake = minWallsNeeded;
}

void LevelBuilder::calculateAverageRoomSize()
{
    size_t denominator_decrease;
    if(m_floorsToMake % m_roomsToMake != 0 && m_floorsToMake % m_roomsToMake < m_minRoomSize)
    {
        denominator_decrease = m_floorsToMake % m_roomsToMake + m_minRoomSize;
    }
    else
    {
        denominator_decrease = m_floorsToMake % m_roomsToMake;
    }
    m_averageRoomSize = (m_floorsToMake - denominator_decrease) / m_roomsToMake;
}

Room LevelBuilder::generateRoom(const bool _deadEndRoom, const bool _firstRoom)
{
    if(m_averageRoomSize == 0)
        calculateAverageRoomSize();
    
    Room new_room;
    
    bool hasAppendixFloor;
    bool lastRoom = false;
    new_room.size = calculateNewRoomSize(lastRoom, hasAppendixFloor);

    //for countdown of remaining tiles
    int floorTilesLeft = (!hasAppendixFloor) ? (new_room.size.x * new_room.size.y) : ((lastRoom) ? m_floorsToMake : m_averageRoomSize);

    //main double cycle for filling the room contents
    for (int x = 0; x < new_room.size.x; x++)
    {
        for (int y = 0; y < new_room.size.x; y++)
        {
            if(floorTilesLeft == 0)
                break;

            auto floorTile = WorldBuilder::Instance()->createObject(WorldObjectType::FLOOR);
            vec2 tile_coords;
            tile_coords.x = x;
            tile_coords.y = y;
            new_room.roomContents.emplace_back(floorTile, tile_coords);
            m_floorsToMake--;
            
            //adding walls
            for (int i = 0; i < ((floorTilesLeft == 1) ? 3 : 2); i++)
            {
                new_room.roomContents.emplace_back(
                    WorldBuilder::Instance()->createObject(WorldObjectType::WALL), tile_coords
                );
                m_wallsToMake--;
            }
            
            //adding doors
            const bool needs_door = checkIfNeedsDoor(new_room.size, x, y, hasAppendixFloor, _deadEndRoom, _firstRoom);

            if(needs_door)
            {
                new_room.roomContents.emplace_back(
                    WorldBuilder::Instance()->createObject(WorldObjectType::DOOR), tile_coords
                );
                new_room.doorCoords.emplace_back(tile_coords);
                m_doorsToMake--;
            }
            
            floorTilesLeft--;
            
        }
    }
    
    return new_room;
}

vec2 LevelBuilder::calculateNewRoomSize(bool& _lastRoom, bool& _hasAppendixFloor) const
{
    vec2 room_size;
    if(m_floorsToMake > m_averageRoomSize && (m_floorsToMake - m_averageRoomSize) > m_minRoomSize)
    {
        if(m_averageRoomSize % 2 == 0)
        {
            room_size.x = m_averageRoomSize / 2;
            room_size.y = room_size.x;
            _hasAppendixFloor = false;
        }
        else
        {
            room_size.x = static_cast<int>(m_averageRoomSize / 2 + 0.5);
            room_size.y = static_cast<int>(m_averageRoomSize / 2 - 0.5);
            _hasAppendixFloor = true;
        }
    }
    else
    {
        _lastRoom = true;
        if(m_floorsToMake % 2 == 0)
        {
            room_size.x = m_floorsToMake / 2;
            room_size.y = room_size.x;
            _hasAppendixFloor = false;
        }
        else
        {
            room_size.x = static_cast<int>(m_floorsToMake / 2 + 0.5);
            room_size.y = static_cast<int>(m_floorsToMake / 2 - 0.5);
            _hasAppendixFloor = true;
        }
    }

    return room_size;
}

bool LevelBuilder::checkIfNeedsDoor(const vec2 _roomSize, const int _x, const int _y, const bool _hasAppendixFloor, const bool _deadEndRoom,
                                    const bool _firstRoom)
{
    bool needs_door = false;
    if(_deadEndRoom)
    {
        //first we divide by current x position and then adjust according to what type of room this is
        if(_roomSize.x % 2 == 0 && _x == static_cast<int>(_roomSize.x / 2))
        {
            if (_firstRoom && _y == _roomSize.y && !_hasAppendixFloor)
                needs_door = true;
            else if (!_firstRoom && _y == 0)
                needs_door = true;
        }
        else if (static_cast<int>(_roomSize.x / 2 - 0.5) == _x)
        {
            if(_firstRoom && _y == _roomSize.y && !_hasAppendixFloor)
                needs_door = true;
            else if(!_firstRoom && _y == 0)
                needs_door = true;
        }
        else if (_firstRoom && _hasAppendixFloor && _y == _roomSize.y && _x == 0)
            needs_door = true;
        else if (_hasAppendixFloor && _y == _roomSize.y && _x == 0)
            needs_door = true;
    }
    else
    {
        //first we divide by current x position and then adjust according to what type of room this is
        if(_roomSize.x % 2 == 0 && _x == static_cast<int>(_roomSize.x / 2))
        {
            if(_y == _roomSize.y && !_hasAppendixFloor)
                needs_door = true;
            else if(_y == 0)
                needs_door = true;
        }
        else if (static_cast<int>(_roomSize.x / 2 - 0.5) == _x)
        {
            if(_y == _roomSize.y && !_hasAppendixFloor)
                needs_door = true;
            else if(_y == 0)
                needs_door = true;
        }
        else if (_hasAppendixFloor && _y == _roomSize.y && _x == 0)
            needs_door = true;
    }

    return needs_door;
}

std::pair<SPTR<IAbstractWorldObject>, vec2> LevelBuilder::generateRandomLevelObject()
{

    //not filling this as not essential for Builder pattern practice
    return std::pair<SPTR<IAbstractWorldObject>, vec2>{std::make_shared<Wall>(AbstractObjectSettings(), ObjectColor::RED), vec2()};
}
