#include "FactorySelector.h"
#include <memory>

#include "factoriesLibrary/DoorFactory.h"
#include "factoriesLibrary/FloorFactory.h"
#include "factoriesLibrary/WallFactory.h"

SPTR<IAbstractFactory> FactorySelector::getConcreteFactory(const WorldObjectType _objectType)
{
    if(m_factoryCollection.find(_objectType) == m_factoryCollection.end())
        instantiateFactory(_objectType);
    
    return m_factoryCollection[_objectType];
}

void FactorySelector::instantiateFactory(const WorldObjectType _objectType)
{
    switch (_objectType)
    {
    case WorldObjectType::NONE:
        m_factoryCollection.emplace(WorldObjectType::NONE, nullptr);
        break;
    case WorldObjectType::FLOOR:
        m_factoryCollection.emplace(WorldObjectType::FLOOR, std::make_shared<FloorFactory>());
        break;
    case WorldObjectType::WALL:
        m_factoryCollection.emplace(WorldObjectType::WALL, std::make_shared<WallFactory>());
        break;
    case WorldObjectType::DOOR:
        m_factoryCollection.emplace(WorldObjectType::DOOR, std::make_shared<DoorFactory>());
        break;
    default:
        m_factoryCollection.emplace(WorldObjectType::NONE, nullptr);
        break;
    }
}