#pragma once

class GenericRoom;

class RoomClient
{
public:
    RoomClient(GenericRoom* _baseClassRef);

    GenericRoom* createInstance();
    
protected:
    GenericRoom* m_baseClassRef = nullptr;
};
