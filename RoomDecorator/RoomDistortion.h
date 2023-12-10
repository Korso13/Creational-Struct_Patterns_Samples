#pragma once
#include "Decorator.h"

class RoomDistortion : public Decorator
{
public:
    RoomDistortion();
    
    void draw() override;
    void addComponent(LevelComponent* _childComp) override;
    ~RoomDistortion() override;

    std::vector<LevelComponent*>& getAllChildComponents() override {return m_childComponents;}
    roomSize getRoomSize() const override;

protected:
    std::vector<LevelComponent*> m_childComponents;
};
