#include "RoomBloodFX.h"

RoomBloodFX::RoomBloodFX()
{
    //generates assets needed for the fx
}

void RoomBloodFX::draw()
{
    for(auto& component : m_childComponents)
        if(component)
            component->draw();

    //draws additional assets for "bloody effects in the room"
}

void RoomBloodFX::addComponent(LevelComponent* _childComp)
{
    m_childComponents.push_back(_childComp);
}

roomSize RoomBloodFX::getRoomSize() const
{
    for(auto& component : m_childComponents)
    {
        if(component->getRoomSize() != roomSize::NULL_SIZE)
            return component->getRoomSize();
    }

    return roomSize::NULL_SIZE;
}
