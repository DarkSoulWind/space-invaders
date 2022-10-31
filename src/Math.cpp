#include <iostream>
#include <Math.hpp>

std::ostream &operator<<(std::ostream &os, const Vector2f &v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

/**
 * If x is greater than max, set x to max. If x is less than min, set x to min.
 *
 * @param x the value to clamp
 * @param max The maximum value that x can be.
 * @param min The minimum value that the variable can be.
 */
void clamp(float &x, float max, float min)
{
    if (x >= max)
        x = max;
    else if (x <= min)
        x = min;
}