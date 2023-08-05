#pragma once

#include "FactorySelector.h"

class WorldBuilder
{
public:

    static WorldBuilder* Instance()
    {
        if(!WorldBuilderInstance)
            WorldBuilderInstance = new WorldBuilder();

        return WorldBuilderInstance;
    }

    SPTR<IAbstractWorldObject> createObject(const WorldObjectType _objectType, const AbstractObjectSettings& _settings = AbstractObjectSettings());

private:
    
    WorldBuilder()
    {
        m_factorySelector = std::make_shared<FactorySelector>();
    }

    SPTR<FactorySelector> m_factorySelector;
    
    static WorldBuilder* WorldBuilderInstance;
};