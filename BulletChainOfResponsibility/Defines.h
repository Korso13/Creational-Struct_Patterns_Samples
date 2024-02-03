#pragma once
#include <string>

#include "Actor.h"

struct KillData
{
    Actor* killer = nullptr;
    Actor* victim = nullptr;
    std::string killerName;
    std::string victimName;
    int victimId = -1;
    int killerId = -1;
};

void printError(std:: string error)
{
    
}