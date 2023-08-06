#pragma once
#include <map>
#include <vector>

#include "AbstractWorldObject.h"

struct vec2
{
    int x = 0;
    int y = 0;
};

struct Level
{
    std::map<IAbstractWorldObject, vec2> levelStructure;
};

class LevelBuilder
{
public:
    static LevelBuilder* Instance()
    {
        if(!m_levelBuilderInstance)
            m_levelBuilderInstance = new LevelBuilder();

        return m_levelBuilderInstance;
    }
    
    void fillLevel(Level& _inLevel, std::vector<WorldObjectType> _inWorldComposition);

protected:
    LevelBuilder() = default;
    static LevelBuilder* m_levelBuilderInstance;
};
