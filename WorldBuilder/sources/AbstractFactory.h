#pragma once

#include "AbstractWorldObject.h"
#include "PCH.h"

class IAbstractFactory
{
public:
    IAbstractFactory() = default;
    virtual ~IAbstractFactory()  = default;
    virtual SPTR<IAbstractWorldObject> createObject() = 0;
    virtual void setDefaultAbstractObjectParams(const AbstractObjectSettings& _settings) = 0;
};