#pragma once
#include "../AbstractFactory.h"
#include "../objects_library/Door.h"

class DoorFactory: public IAbstractFactory
{
public:
    DoorFactory() : IAbstractFactory(){}
    
    SPTR<IAbstractWorldObject> createObject() override;
    void setDefaultAbstractObjectParams(const AbstractObjectSettings& _settings) override {m_defaultObjectSettings = _settings;}
    void setDoorParams(const DoorSettings& _inSettings) {m_defaultDoorSettings = _inSettings;}
    
private:
    AbstractObjectSettings m_defaultObjectSettings;
    DoorSettings m_defaultDoorSettings;
};
