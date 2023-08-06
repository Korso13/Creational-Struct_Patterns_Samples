#pragma once
#include "../AbstractFactory.h"

class WallFactory : public IAbstractFactory
{
public:
    WallFactory() : IAbstractFactory(){}
    
    SPTR<IAbstractWorldObject> createObject() override;
    void setDefaultAbstractObjectParams(const AbstractObjectSettings& _settings) override {m_defaultObjectSettings = _settings;}

private:
    AbstractObjectSettings m_defaultObjectSettings;
};