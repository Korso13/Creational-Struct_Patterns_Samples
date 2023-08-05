#pragma once
#include "Floor.h"

class GlassFloor : public Floor
{
public:
    GlassFloor(const AbstractObjectSettings& _settings)
    : Floor(_settings)
    {}

    //Glass floor-specific logic
};
