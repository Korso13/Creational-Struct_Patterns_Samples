#pragma once

#include "AbstractFactory.h"
#include "PCH.h"


class FactorySelector
{
public:

    FactorySelector() = default;
    SPTR<IAbstractFactory> getConcreteFactory(WorldObjectType _objectType);

private:
    
    std::map<WorldObjectType, SPTR<IAbstractFactory>> m_factoryCollection;    
};