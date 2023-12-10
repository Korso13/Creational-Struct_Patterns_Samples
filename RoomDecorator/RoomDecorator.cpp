
#include <vector>

#include "LevelComponent.h"
#include "RoomGenerator.h"

static std::vector<LevelComponent*> roomUpdateList;

void onUpdate()
{
    for(const auto& room : roomUpdateList)
    {
        room->draw(); //all rooms will be drawn along with decorator modifiers
    }
}

int main(int argc, char* argv[])
{

    LevelComponent* room1 = RoomGenerator::getInstance()->makeRoom(roomSize::SINGLE);
    LevelComponent* room2 = RoomGenerator::getInstance()->makeRoom(roomSize::ROOM2X2, true, false);
    LevelComponent* room3 = RoomGenerator::getInstance()->makeRoom(roomSize::ROOM2X2, true, true);


    roomUpdateList.push_back(room1);
    roomUpdateList.push_back(room2);
    roomUpdateList.push_back(room3);
    
    return 0;
}
