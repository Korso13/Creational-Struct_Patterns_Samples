#pragma once
#include <map>
#include <string>

#include "DrawElement.h"

struct MeshAttachment
{
    DrawElement* attachedMesh = nullptr;
    int boneId = -1;
};

class Mesh3D : public DrawElement
{
public:
    Mesh3D(const std::string& assetName){}
    
    void draw() override;
    void enableDraw(bool _isEnabled) override;
    int addChild(DrawElement* _child) override;
    void removeChild(int _childId) override;

    void attachChildToBone(int _childId, int _boneId);
    
protected:
    std::map<int, MeshAttachment> m_children;
};
