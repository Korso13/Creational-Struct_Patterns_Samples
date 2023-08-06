#include "WallFactory.h"

#include "../objects_library/Wall.h"

SPTR<IAbstractWorldObject> WallFactory::createObject()
{
    return std::make_shared<Wall>(m_defaultObjectSettings, m_defaultObjectSettings.objectColor);
}
