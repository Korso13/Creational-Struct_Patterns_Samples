#include "FloorFactory.h"
#include <memory>
#include "../objects_library/GlassFloor.h"

SPTR<IAbstractWorldObject> FloorFactory::createObject()
{
    if(m_defaultObjectSettings.objectColor == ObjectColor::TRANSPARENT)
    {
        return std::make_shared<GlassFloor>(m_defaultObjectSettings);
    }

    return std::make_shared<Floor>(m_defaultObjectSettings);
}
