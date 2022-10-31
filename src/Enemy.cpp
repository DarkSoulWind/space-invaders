#include <SDL2/SDL.h>

#include <Enemy.hpp>
#include <Entity.hpp>
#include <Math.hpp>
#include <RenderWindow.hpp>

Enemy::Enemy(Vector2f pos, SDL_Texture *texture) : Entity(pos, texture), m_timer(0), m_type(static_cast<ENEMY_SPRITE>(rand() % 6)), m_spriteFrame(0)
{
    updateSprite();
}

void Enemy::update()
{
    m_pos.y += 2;
    m_timer++;
    if (m_timer >= 40)
    {
        m_timer = 0;
        m_spriteFrame = m_spriteFrame == 0 ? 1 : 0;
        updateSprite();
    }

    // if laser goes off the screen then it should be removed
    if (m_pos.y > WINDOW_HEIGHT)
    {
        m_remove = true;
    }
}

void Enemy::updateSprite()
{
    switch (m_type)
    {
    case ENEMY_SPRITE::GREEN:
        m_currentFrame.x = 24;
        m_currentFrame.y = m_spriteFrame * 8;
        m_currentFrame.w = 8;
        m_currentFrame.h = 8;
        break;
    case ENEMY_SPRITE::ORANGE:
        m_currentFrame.x = 33;
        m_currentFrame.y = m_spriteFrame * 8;
        m_currentFrame.w = 6;
        m_currentFrame.h = 8;
        break;
    case ENEMY_SPRITE::RED:
        m_currentFrame.x = 40;
        m_currentFrame.y = m_spriteFrame * 8;
        m_currentFrame.w = 8;
        m_currentFrame.h = 8;
        break;
    case ENEMY_SPRITE::YELLOW:
        m_currentFrame.x = 56;
        m_currentFrame.y = m_spriteFrame * 8;
        m_currentFrame.w = 8;
        m_currentFrame.h = 8;
        break;
    case ENEMY_SPRITE::PINK:
        m_currentFrame.x = 64;
        m_currentFrame.y = m_spriteFrame * 8;
        m_currentFrame.w = 8;
        m_currentFrame.h = 8;
        break;
    case ENEMY_SPRITE::BLUE:
        m_currentFrame.x = 80;
        m_currentFrame.y = m_spriteFrame * 8;
        m_currentFrame.w = 8;
        m_currentFrame.h = 8;
        break;
    }
}