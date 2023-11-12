#pragma once
#include "RoomClient.h"

struct roomInfo
{
    int size = 0;
    int enemies = 0;
    int loot = 0;
};

//interface for clonable class
class GenericRoom
{
    friend class RoomClient; //only RoomClient will have access to cloning functionality 

public:
    GenericRoom() = default;
    virtual ~GenericRoom(){}

    //creates client for clonning
    virtual RoomClient* getClient() = 0;
    roomInfo& getRoomInfo() {return m_roomData;}

private:
    //for cloning prototype
    virtual GenericRoom* clone() = 0;
    
protected:
    roomInfo m_roomData;
};
