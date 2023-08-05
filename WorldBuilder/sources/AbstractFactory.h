#pragma once
#include "AbstractWorldObject.h"
#include <memory>

struct DefaultAbstractObjectSettings
{
    bool isUpdated = false;
    bool isDestructible = false;
    float defaultColliderSize = 1.f;
};

class IAbstractFactory
{
public:
    virtual std::shared_ptr<IAbstractWorldObject> createObject() = 0;
    virtual void setDefaultAbstractObjectParams(const DefaultAbstractObjectSettings _settings) = 0;
};