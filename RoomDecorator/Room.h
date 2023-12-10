#pragma once
#include "LevelComponent.h"

class Room : public LevelComponent
{
public:
    Room(roomSize _size);

    ~Room() override {}

    void draw() override;
    void addComponent(LevelComponent* _childComp) override {} //does not support child components, can only be component itself
    roomSize getRoomSize() const override {return m_size;}

protected:
    roomSize m_size;
};
