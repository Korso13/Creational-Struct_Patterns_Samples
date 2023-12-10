#include "RoomDistortion.h"

RoomDistortion::RoomDistortion()
{
    
}

void RoomDistortion::draw()
{
    roomSize rSize = roomSize::NULL_SIZE;
    for(auto& component : m_childComponents)
    {
        if(component)
        {
            component->draw();
            if(component->getRoomSize() != roomSize::NULL_SIZE)
                rSize = component->getRoomSize();
        }
    }

    //drawing different amount of distortions in different places depending on the size of the room
    //room is always at the end of the getRoomSize() querry, which goes through the entire chain of components
    switch (rSize)
    {
    case roomSize::SINGLE:
        break;
    case roomSize::ROOM2X2:
        break;
    case roomSize::ROOM4X4:
        break;
    case roomSize::NULL_SIZE:
        break;
    default:
        break;
    }
}

void RoomDistortion::addComponent(LevelComponent* _childComp)
{
    m_childComponents.push_back(_childComp);
}

RoomDistortion::~RoomDistortion()
{
}

roomSize RoomDistortion::getRoomSize() const
{
    for(auto& component : m_childComponents)
    {
        if(component->getRoomSize() != roomSize::NULL_SIZE)
            return component->getRoomSize();
    }

    return roomSize::NULL_SIZE;
}
