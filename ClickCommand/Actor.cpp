#include "Actor.h"
#include "Command.h"

void Actor::click()
{
    auto castResult = screenCast();
    
    if(castResult.clickableObject)
    {
        //Command pattern logic call
        //Different world objects will trigger different actions
        castResult.clickableObject->execute(this);
        m_lastClickableObject = castResult.clickableObject;
    }
    else
    {
        if(m_lastClickableObject)
        {
            if(m_lastClickableObject->cancelTask()) //cancels last task
                m_lastClickableObject = nullptr;
            else //task can't be cancelled
            {
                return;
            }
        }
        
        moveToLocation(castResult.clickLocation);
    }

}

raycastData Actor::screenCast()
{
    raycastData result = {nullptr, vec2{0.f, 0.f}};
    //raycasting logic that can detect Command objects in the world and writes to result variable
    
    return result;
}
