#include <SDL2/SDL.h>

#include <Laser.hpp>
#include <Math.hpp>
#include <Entity.hpp>

Laser::Laser(Vector2f pos, SDL_Texture *texture) : Entity(pos, texture), m_remove(false)
{
    m_currentFrame.x = 1;
    m_currentFrame.y = 25;
    m_currentFrame.w = 6;
    m_currentFrame.h = 6;
}

void Laser::update()
{
    m_pos.y -= 10;

    // if laser goes off the screen then it should be removed
    if (m_pos.y < -m_currentFrame.h)
    {
        m_remove = true;
    }
}