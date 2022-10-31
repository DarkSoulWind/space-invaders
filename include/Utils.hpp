#pragma once
#include <SDL2/SDL.h>

namespace utils
{
    // Getting the time in seconds.
    inline float hireTimeInSeconds()
    {
        float t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }
}