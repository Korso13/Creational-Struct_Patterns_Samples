#pragma once
#include <string>

#include "DrawElement.h"

class Mesh : public DrawElement
{
public:
    Mesh(const std::string& assetName){}

    void draw() override;
    void enableDraw(bool _isEnabled) override;
    int addChild(DrawElement* _child) override {return -1;}
    void removeChild(int _childId) override {}
};
