#include "WorldManager.h"

WorldManager* WorldManager::sInstance = nullptr;
 
WorldManager* WorldManager::GetInstnance()
{
    if (!sInstance)
    {
        sInstance = new WorldManager();
    }
    return sInstance;
}

WorldManager::WorldManager()
{
}
