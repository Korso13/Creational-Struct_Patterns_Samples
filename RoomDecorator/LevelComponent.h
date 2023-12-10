#pragma once

enum class roomSize
{
    SINGLE,
    ROOM2X2,
    ROOM4X4,
    NULL_SIZE
};

class LevelComponent
{
public:
    virtual ~LevelComponent() = default;

    virtual void draw() = 0;
    virtual void addComponent(LevelComponent* _childComp) = 0;
    virtual roomSize getRoomSize() const = 0;
};
