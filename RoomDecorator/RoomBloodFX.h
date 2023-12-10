#pragma once
#include "Decorator.h"

class RoomBloodFX : public Decorator
{
public:
    RoomBloodFX();
    ~RoomBloodFX() override {}

    void draw() override;
    void addComponent(LevelComponent* _childComp) override;
    std::vector<LevelComponent*>& getAllChildComponents() override {return m_childComponents;}
    roomSize getRoomSize() const override;

protected:
    std::vector<LevelComponent*> m_childComponents;
};
