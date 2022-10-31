#pragma once
#include <Entity.hpp>
#include <Math.hpp>

#define PLAYER_VELOCTIY 2.f
#define PLAYER_MAX_VELOCTIY 5.f
#define PLAYER_SCALE 6

enum PLAYER_SPRITE
{
    IDLE,
    MOVING_LEFT,
    MOVING_RIGHT,
};

class Player : public Entity
{
private:
    Vector2f m_velocity;

public:
    Player(Vector2f pos, SDL_Texture *texture);
    void updateSprite(PLAYER_SPRITE sprite);
    void update();

    void addForce(float x, float y);
};