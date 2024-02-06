//key abstract class for Command pattern
#pragma once

class Actor;

class Command
{
public:
    Command() = default;
    virtual ~Command() = default;
    
    virtual void execute(Actor* instigator) = 0;
    virtual bool cancelTask() = 0;
};
