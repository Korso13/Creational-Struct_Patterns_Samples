#pragma once

enum class WorldObjectType
{
    NONE,
    FLOOR,
    WALL,
    DOOR
};

class IAbstractWorldObject
{
public:

    virtual bool isEnabled() = 0;
    virtual void setEnabled(bool _state) = 0;
    virtual void destroy(float _delay = 0.f) = 0; 
    
    WorldObjectType identifyObjectType() const {return m_objectType;}

protected:
    bool m_isUpdated = false;
    bool m_isDestructible = false;
    float m_defaultColliderSize = 1.f;
    
private:
    WorldObjectType m_objectType = WorldObjectType::NONE;
};
