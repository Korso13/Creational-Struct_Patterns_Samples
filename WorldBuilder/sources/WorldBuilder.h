#pragma once

#include "FactorySelector.h"

struct DoorSettings;

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

protected:
    
    WorldBuilder()
    {
        m_factorySelector = std::make_shared<FactorySelector>();
    }

    DoorSettings calculateDoorParams();

private:
    static WorldBuilder* WorldBuilderInstance;
    SPTR<FactorySelector> m_factorySelector;
};
