#include "WorldBuilder.h"

SPTR<IAbstractWorldObject> WorldBuilder::createObject(const WorldObjectType _objectType, const AbstractObjectSettings& _settings)
{
    if(!m_factorySelector)
        return nullptr;

    const auto factory = m_factorySelector->getConcreteFactory(_objectType);
    factory->setDefaultAbstractObjectParams(_settings);

    return factory->createObject();
}