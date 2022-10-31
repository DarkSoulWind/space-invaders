#pragma once
#include <iostream>

struct Vector2f
{
    Vector2f()
        : x(0.0f), y(0.0f)
    {
    }

    Vector2f(float x, float y)
        : x(x), y(y)
    {
    }

    float x, y;

    friend std::ostream &operator<<(std::ostream &, const Vector2f &);
};

std::ostream &operator<<(std::ostream &, const Vector2f &);

void clamp(float &x, float max, float min);
