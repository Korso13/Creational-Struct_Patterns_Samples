#pragma once

#include "../AbstractWorldObject.h"
#include "../PCH.h"

#define MAX_KEY_TYPES 2
enum class keyType : int32_t
{ 
    NONE = 0,
    DOORKEY_1 = 1,
    DOORKEY_2 = 2
};

struct DoorSettings
{
    keyType requiredKeyType = keyType::NONE;
    bool isLocked = false;
};

class Door : public IAbstractWorldObject
{
public: 
    Door(const AbstractObjectSettings& _settings,
        const DoorSettings& _doorSettings,
        const ObjectColor _inColor)
        :IAbstractWorldObject(_settings),
        m_isLocked(_doorSettings.isLocked),
        m_requiredKey(_doorSettings.requiredKeyType),
        m_color(_inColor)
    {
        m_objectType = WorldObjectType::DOOR;
    }

    bool isEnabled() const override {return m_isEnabled;}
    void setEnabled(const bool _state) override {m_isEnabled = _state;}
    void destroy(const float _delay) override {m_mesh.reset();}

    //door-specific logic
    bool tryOpen() const {return !m_isLocked;}
    bool tryUnlock(const std::set<keyType>& _keys);

protected:
    bool m_isEnabled = true;
    bool m_isLocked = false;
    keyType m_requiredKey = keyType::NONE;
    ObjectColor m_color;
};
