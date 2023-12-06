#pragma once

class DrawElement
{
public:
    DrawElement() = default;
    virtual ~DrawElement() = default;

    //common methods
    virtual void draw() = 0;
    virtual void enableDraw(bool _isEnabled) = 0;

    //container methods
    virtual int addChild(DrawElement* _child) = 0;
    virtual void removeChild(int _childId) = 0;
};
