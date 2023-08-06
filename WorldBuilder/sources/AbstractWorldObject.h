#pragma once
#include "PCH.h"

enum class WorldObjectType
{
    NONE,
    FLOOR,
    WALL,
    DOOR
};

enum ObjectColor
{
    RED,
    BLUE,
    TRANSPARENT
};

struct AbstractObjectSettings
{
    bool isUpdated = false;
    bool isDestructible = false;
    float defaultColliderSize = 1.f;

    ObjectColor objectColor = ObjectColor::RED;
};


class IAbstractWorldObject
{
public:
    explicit IAbstractWorldObject(const AbstractObjectSettings& _settings)
        : m_isUpdated(_settings.isUpdated),
          m_isDestructible(_settings.isDestructible),
          m_defaultColliderSize(_settings.defaultColliderSize)
    {
    }

    virtual ~IAbstractWorldObject() = default;

    virtual bool isEnabled() const = 0;
    virtual void setEnabled(const bool _state) = 0;
    virtual void destroy(const float _delay = 0.f) = 0; 
    
    WorldObjectType identifyObjectType() const {return m_objectType;}

    virtual bool isUpdated() const { return m_isUpdated; }
    virtual void setUpdated(const bool _isUpdated) { m_isUpdated = _isUpdated; }
    virtual bool isDestructible() const { return m_isDestructible; }
    virtual void setDestructible(const bool _isDestructible) { m_isDestructible = _isDestructible; }
    virtual float getDefaultColliderSize() const { return m_defaultColliderSize; }
    virtual void setDefaultColliderSize(const float _defaultColliderSize){m_defaultColliderSize = _defaultColliderSize;}
    
protected:
    bool m_isUpdated = false;
    bool m_isDestructible = false;
    float m_defaultColliderSize = 1.f;
    SPTR<objectMesh> m_mesh;
    WorldObjectType m_objectType = WorldObjectType::NONE;
};
