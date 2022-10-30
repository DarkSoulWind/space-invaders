#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Math.hpp>

class Entity
{
protected:
    Vector2f m_pos;
    SDL_Rect m_currentFrame;
    SDL_Texture *m_texture;

public:
    Entity(Vector2f pos, SDL_Texture *texture);
    Vector2f &getPos();
    SDL_Texture *getTexture();
    SDL_Rect getCurrentFrame();
};