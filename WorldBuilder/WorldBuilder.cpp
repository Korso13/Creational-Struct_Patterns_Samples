


#include <memory>

#include "sources/AbstractWorldObject.h"

class WorldBuilder
{
public:

    static WorldBuilder* Instance()
    {
        if(!WorldBuilderInstance)
            WorldBuilderInstance = new WorldBuilder();

        return WorldBuilderInstance;
    }

    std::shared_ptr<IAbstractWorldObject> createObject(WorldObjectType);

private:
    
    WorldBuilder() = default;
    
    static WorldBuilder* WorldBuilderInstance;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
