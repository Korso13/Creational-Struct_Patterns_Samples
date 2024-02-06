//Sample player class that reacts to user clicks on 2D map via Command pattern
#pragma once
#include "defines.h"

class ClickableEnemy;
class Command;


struct raycastData
{
    Command* clickableObject;
    vec2     clickLocation;
};

class PickableObject;

class Actor
{
public:
    Actor() = default;

    void click();
    
    //placeholder methods
    void moveToLocation(vec2 targetLoc){}
    void pickObject(PickableObject* object){}
    void attackEnemy(ClickableEnemy* _enemy){}

private:

    raycastData screenCast();

private:
    
    Command* m_lastClickableObject = nullptr;
};

