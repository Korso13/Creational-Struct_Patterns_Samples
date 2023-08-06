#include "DoorFactory.h"

SPTR<IAbstractWorldObject> DoorFactory::createObject()
{
    return std::make_shared<Door>(
        m_defaultObjectSettings,
        m_defaultDoorSettings,
        m_defaultObjectSettings.objectColor
        );
}
