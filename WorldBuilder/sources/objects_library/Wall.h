#pragma once

#include "../AbstractWorldObject.h"
#include "../PCH.h"

class Wall : public IAbstractWorldObject
{
public:
    Wall(const AbstractObjectSettings& _settings,
        const ObjectColor _inColor)
    :IAbstractWorldObject(_settings),
    m_color(_inColor)
    {
        m_objectType = WorldObjectType::WALL;
    }

    bool isEnabled() const override {return m_isEnabled;}
    void setEnabled(const bool _state) override {m_isEnabled = _state;}
    void destroy(const float _delay) override {m_mesh.reset();}
    void setColor(const ObjectColor _inColor) {m_color = _inColor;}
    //wall-specific logic

    protected:
    bool m_isEnabled = true;
    ObjectColor m_color;
};
