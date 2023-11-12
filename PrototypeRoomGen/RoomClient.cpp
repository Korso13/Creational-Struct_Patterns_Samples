#include "RoomClient.h"
#include "GenericRoom.h"

RoomClient::RoomClient(GenericRoom* _baseClassRef)
    :
m_baseClassRef(_baseClassRef)
{
}

GenericRoom* RoomClient::createInstance()
{
    if(!m_baseClassRef)
        return nullptr;
    return m_baseClassRef->clone();
}
