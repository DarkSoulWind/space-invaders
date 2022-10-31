#pragma once

#include <Entity.hpp>

#define ENEMY_SCALE 5

enum ENEMY_SPRITE
{
    GREEN,
    ORANGE,
    RED,
    YELLOW,
    PINK,
    BLUE
};

class Enemy : public Entity
{
private:
    int m_timer;
    int m_spriteFrame;
    bool m_remove;
    ENEMY_SPRITE m_type;

public:
    Enemy(Vector2f pos, SDL_Texture *texture);

    inline const bool shouldBeRemoved() const { return m_remove; }

    void update();
    void updateSprite();
};