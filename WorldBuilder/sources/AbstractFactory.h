#pragma once

#include "AbstractWorldObject.h"
#include "PCH.h"

struct DefaultAbstractObjectSettings
{
    bool isUpdated = false;
    bool isDestructible = false;
    float defaultColliderSize = 1.f;
};

class IAbstractFactory
{
public:
    IAbstractFactory();
    virtual ~IAbstractFactory();
    virtual SPTR<IAbstractWorldObject> createObject() = 0;
    virtual void setDefaultAbstractObjectParams(const DefaultAbstractObjectSettings _settings) = 0;
};