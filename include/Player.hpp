#pragma once
#include <Entity.hpp>

#define PLAYER_VELOCTIY 20.f

enum PLAYER_SPRITE
{
    IDLE,
    MOVING_LEFT,
    MOVING_RIGHT,
};

class Player : public Entity
{
private:
public:
    Player(Vector2f pos, SDL_Texture *texture);
    void render(SDL_Renderer *renderer);
    void updateSprite(PLAYER_SPRITE sprite);
    void update();

    inline void changePos(float x, float y)
    {
        m_pos.x += x;
        m_pos.y += y;
    }
};