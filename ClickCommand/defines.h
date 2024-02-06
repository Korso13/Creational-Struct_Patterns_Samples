#pragma once
#include <functional>

struct delayedTask
{
    float timeToOnset = 0.f;
    std::function<void()> delayedFunc;
};

struct vec2
{
    float x;
    float y;
};
