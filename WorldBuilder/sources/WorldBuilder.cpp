#include "WorldBuilder.h"
#include <random>
#include <stdlib.h>
#include <chrono>
#include "factoriesLibrary/DoorFactory.h"

WorldBuilder* WorldBuilder::WorldBuilderInstance = nullptr;

SPTR<IAbstractWorldObject> WorldBuilder::createObject(const WorldObjectType _objectType, const AbstractObjectSettings& _settings)
{
    if(!m_factorySelector)
        return nullptr;

    const auto factory = m_factorySelector->getConcreteFactory(_objectType);
    factory->setDefaultAbstractObjectParams(_settings);

    //specifyBehavior for specific objects
    switch (_objectType)
    {
        case WorldObjectType::NONE:
            break;
        case WorldObjectType::FLOOR:
            break;
        case WorldObjectType::WALL:
            break;
        case WorldObjectType::DOOR:
            dynamic_cast<DoorFactory*>(factory.get())->setDoorParams(calculateDoorParams());
            break;
        default:
            break;
    }
    
    return factory->createObject();
}

int32_t getRandomNum(int32_t min, int32_t max);

DoorSettings WorldBuilder::calculateDoorParams()
{
    DoorSettings params;
    params.isLocked = static_cast<bool>(getRandomNum(0, 1));
    if(params.isLocked)
        params.requiredKeyType = static_cast<keyType>(getRandomNum(1,MAX_KEY_TYPES));
    
    return params;
}

int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}