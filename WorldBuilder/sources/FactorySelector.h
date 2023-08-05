#pragma once

#include <map>
#include <memory>
#include "AbstractFactory.h"
#include "objects_library/Floor.h"

enum class WorldObjectType
{
    NONE,
    FLOOR,
    WALL,
    DOOR
};

class FactorySelector
{
public:

    static FactorySelector* Instance()
    {
        if(!FactorySelectorInstance)
            FactorySelectorInstance = new FactorySelector();

        return FactorySelectorInstance;
    }

    std::shared_ptr<IAbstractFactory> getConcreteFactory(WorldObjectType _objectType);

private:
    FactorySelector() = default;
    static FactorySelector* FactorySelectorInstance;
    
    std::map<WorldObjectType, std::shared_ptr<IAbstractFactory>> m_factoryCollection;    
};