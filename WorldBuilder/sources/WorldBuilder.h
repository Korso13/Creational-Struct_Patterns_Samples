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

    SPTR<IAbstractWorldObject> createObject(WorldObjectType);

private:
    
    WorldBuilder()
    {
        m_factorySelector = std::make_shared<FactorySelector>();
    }

    SPTR<FactorySelector> m_factorySelector;
    
    static WorldBuilder* WorldBuilderInstance;
};