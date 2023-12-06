#include "Mesh3d.h"

void Mesh3D::draw()
{
    for(auto& [id, child] : m_children)
    {
        child.attachedMesh->draw();
        //optionally call translation setter method for child.attachedMesh based on bone id
    }
    //Calling renderer draw methods here for 3d mesh
}

void Mesh3D::enableDraw(bool _isEnabled)
{
    for(auto& [id, child] : m_children)
    {
        child.attachedMesh->enableDraw(_isEnabled);       
    }
    //setting relevant shader uniform to enable/disable render on draw() for 3d mesh
}

int Mesh3D::addChild(DrawElement* _child)
{
    const int newID = m_children.size();
    MeshAttachment newAttachment = {_child, -1};
    m_children.insert({newID, newAttachment});
    return newID;
}

void Mesh3D::removeChild(int _childId)
{
    if(m_children.find(_childId) == m_children.end())
        return;

    m_children.erase(_childId);
}

void Mesh3D::attachChildToBone(int _childId, int _boneId)
{
    if(_childId == -1 || _boneId == -1 || m_children.find(_childId) == m_children.end())
        return;

    m_children[_childId].boneId = _boneId;
    //call translation setter method for DrawElement at m_children[_childId]
}
