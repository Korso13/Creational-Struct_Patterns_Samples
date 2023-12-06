#pragma once
#include <map>

#include "DrawElement.h"

class DrawNode  : public DrawElement
{
public:
    DrawNode() = default;
    
    void draw() override;
    void enableDraw(bool _isEnabled) override;
    int addChild(DrawElement* _child) override;
    void removeChild(const int _childId) override;

protected:
    std::map<int, DrawElement*> m_children;
};
