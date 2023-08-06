#include "Door.h"

bool Door::tryUnlock(const std::set<keyType>& _keys)
{
    if(_keys.find(m_requiredKey) != _keys.end())
        m_isLocked = false;

    return !m_isLocked;
}
