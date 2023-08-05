#pragma once
#include "../AbstractFactory.h"

class FloorFactory : public IAbstractFactory
{
public:
    FloorFactory() : IAbstractFactory(){}
    
    SPTR<IAbstractWorldObject> createObject() override;
    void setDefaultAbstractObjectParams(const AbstractObjectSettings& _settings) override {m_defaultObjectSettings = _settings;}

private:
    AbstractObjectSettings m_defaultObjectSettings;
};
