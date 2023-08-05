#pragma once

#include "AbstractFactory.h"
#include "PCH.h"


class FactorySelector
{
public:

    FactorySelector() = default;
    SPTR<IAbstractFactory> getConcreteFactory(const WorldObjectType _objectType);

private:

    void instantiateFactory(const WorldObjectType _objectType);
    
    std::map<WorldObjectType, SPTR<IAbstractFactory>> m_factoryCollection;    
};