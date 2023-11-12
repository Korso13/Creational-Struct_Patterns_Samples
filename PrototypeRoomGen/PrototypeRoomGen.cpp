
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "BossRoom.h"
#include "GenericRoom.h"
#include "LootRoom.h"
#include "RoomClient.h"

enum roomType
{
    Loot = 0,
    Boss = 1
};

void printRoomData(GenericRoom* inRoom)
{
    std::cout << "This room is size " << inRoom->getRoomInfo().size
    << ", has " << inRoom->getRoomInfo().enemies << " enemies and "
    << inRoom->getRoomInfo().loot << " loot items!" <<std::endl;
}

void generateClients(std::map<roomType, RoomClient*>& _clientsContainer, std::vector<GenericRoom*>& _prototypes)
{
    _clientsContainer.insert({roomType::Loot, _prototypes[0]->getClient()});
    _clientsContainer.insert({roomType::Boss, _prototypes[1]->getClient()});
}

int main(int argc, char* argv[])
{
    std::string userInput;
    std::vector<GenericRoom*> prototypes;
    std::vector<GenericRoom*> generatedRooms;
    std::map<roomType, RoomClient*> roomClients;

    //created prototypes
    prototypes.push_back(new LootRoom(2, 2, 3));
    prototypes.push_back(new BossRoom(3, 1));

    //created clients for creating new instances of prototypes
    generateClients(roomClients, prototypes);
    
    while( userInput != "exit")
    {
        userInput.clear();
        std::cout << "Enter command or 'exit' to quit" << std::endl;
        std::cin >> userInput;

        if(userInput == "create")
        {
            userInput.clear();
            std::cout << "What type of room to create?" << std::endl;
            std::cin >> userInput;
            if(userInput == "Loot")
            {
                generatedRooms.push_back(roomClients[roomType::Loot]->createInstance());
                std::cout << "Created loot room, id: " << generatedRooms.size()-1 << std::endl;
                continue;
            }
            if(userInput == "Boss")
            {
                generatedRooms.push_back(roomClients[roomType::Boss]->createInstance());
                std::cout << "Created loot room, id: " << generatedRooms.size()-1 << std::endl;
                continue;
            }
            else
               continue;
        }
        if(userInput == "settings")
        {
            userInput.clear();
            std::cout << "Which room should I modify?" << std::endl;
            std::cin >> userInput;
            int RoomID = std::stoi(userInput);
            userInput.clear();
            std::cout << "What size?" << std::endl;
            std::cin >> userInput;
            int RoomSize = std::stoi(userInput);
            userInput.clear();
            std::cout << "How many enemies?" << std::endl;
            std::cin >> userInput;
            int RoomEnemies = std::stoi(userInput);
            userInput.clear();
            std::cout << "How many loot items?" << std::endl;
            std::cin >> userInput;
            int RoomLoot = std::stoi(userInput);

            auto& roomInfo = generatedRooms[RoomID]->getRoomInfo();
            roomInfo.enemies = RoomEnemies;
            roomInfo.loot = RoomLoot;
            roomInfo.size = RoomSize;
        }
        if(userInput == "info")
        {
            userInput.clear();
            std::cout << "Which room info?" << std::endl;
            std::cin >> userInput;
            int RoomID = std::stoi(userInput);
            printRoomData(generatedRooms[RoomID]);
        }

    }

    std::cout << "Loot room prototype data: " << std::endl;
    printRoomData(prototypes[0]);
    std::cout << "Boss room prototype data: " << std::endl;
    printRoomData(prototypes[1]);
    
    return 0;
}
