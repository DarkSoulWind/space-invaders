#include <iostream>
#include <Math.hpp>

std::ostream &operator<<(std::ostream &os, const Vector2f &v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}