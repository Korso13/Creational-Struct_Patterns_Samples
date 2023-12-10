#pragma once
#include <vector>

#include "LevelComponent.h"

class Decorator : public LevelComponent
{
public:
    virtual ~Decorator() = default;

    virtual std::vector<LevelComponent*>& getAllChildComponents() = 0;
};
