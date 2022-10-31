#include <Entity.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Math.hpp>

Entity::Entity(Vector2f pos, SDL_Texture *texture)
    : m_pos(pos), m_texture(texture)
{
    m_currentFrame.x = 0;
    m_currentFrame.y = 0;
    m_currentFrame.w = 32;
    m_currentFrame.h = 32;
}

Vector2f &Entity::getPos()
{
    return m_pos;
}

SDL_Texture *Entity::getTexture()
{
    return m_texture;
}

SDL_Rect &Entity::getCurrentFrame()
{
    return m_currentFrame;
}

SDL_Rect Entity::getPosRect()
{
    SDL_Rect pos;
    pos.h = m_currentFrame.h;
    pos.w = m_currentFrame.w;
    pos.x = m_pos.x;
    pos.y = m_pos.y;
    return pos;
}