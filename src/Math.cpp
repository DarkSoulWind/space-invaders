#include <SDL2/SDL.h>
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

/**
 * If any of the sides from A are outside of B, then there is no collision
 *
 * @param a The first rectangle to check.
 * @param b The rectangle to check against
 *
 * @return A boolean value.
 */
bool checkCollision(SDL_Rect a, SDL_Rect b)
{
    // The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    // Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    // Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    // If any of the sides from A are outside of B
    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    std::cout << "we good to go bros" << std::endl;

    // If none of the sides from A are outside B
    return true;
}