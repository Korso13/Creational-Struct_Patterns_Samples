#pragma once

#include "../AbstractWorldObject.h"
#include "../PCH.h"

class objectMesh;

class Floor : public IAbstractWorldObject
{
public:
    
    Floor(const AbstractObjectSettings& _settings)
        :IAbstractWorldObject(_settings)
    {
    }

    bool isEnabled() const override {return m_isEnabled;}
    void setEnabled(const bool _state) override {m_isEnabled = _state;}
    void destroy(const float _delay) override {m_mesh.reset();}

    //floor-specific logic

protected:
    bool m_isEnabled = true;
    SPTR<objectMesh> m_mesh;
};