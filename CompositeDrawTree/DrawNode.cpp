#include "DrawNode.h"

void DrawNode::draw()
{
    if(m_children.empty())
        return;

    for(auto& [id, child] : m_children)
    {
        child->draw();       
    }
}

void DrawNode::enableDraw(bool _isEnabled)
{
    if(m_children.empty())
        return;

    for(auto& [id, child] : m_children)
    {
        child->enableDraw(_isEnabled);       
    }
}

int DrawNode::addChild(DrawElement* _child)
{
    const int NewId = m_children.size();
    m_children.insert({NewId, _child});
    return NewId;
}

void DrawNode::removeChild(const int _childId)
{
    if(m_children.find(_childId) == m_children.end())
        return;

    m_children.erase(_childId);
}
