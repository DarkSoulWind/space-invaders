#include <SDL2/SDL.h>
#include <Player.hpp>
#include <Math.hpp>
#include <RenderWindow.hpp>

/**
 * Constructor for the Player class
 *
 * @param pos The position of the player.
 * @param texture The spritesheet in the res folder.
 */
Player::Player(Vector2f pos, SDL_Texture *texture)
    : Entity(pos, texture), m_velocity(0, 0)
{
    updateSprite(PLAYER_SPRITE::IDLE);
}

void Player::update()
{
    // if (m_velocity.x != 0.f && m_velocity.y != 0.f)
    //     addForce(m_velocity.x > 0 ? -2.f : 2.f, m_velocity.y > 0 ? -2.f : 2.f);

    clamp(m_velocity.x, PLAYER_MAX_VELOCTIY, -PLAYER_MAX_VELOCTIY);
    clamp(m_velocity.y, PLAYER_MAX_VELOCTIY, -PLAYER_MAX_VELOCTIY);

    // std::cout << "Player velocity: " << m_velocity << std::endl;

    if (m_pos.x + m_velocity.x <= 0)
    {
        m_pos.x -= SDL_abs(m_velocity.x) - m_pos.x;
        m_velocity.x *= -1;
    }
    if (m_pos.x + m_velocity.x + (m_currentFrame.w * PLAYER_SCALE) >= WINDOW_WIDTH)
    {
        m_pos.x += (m_pos.x + m_velocity.x + (m_currentFrame.w * PLAYER_SCALE)) - WINDOW_WIDTH;
        m_velocity.x *= -1;
    }
    if (m_pos.y + m_velocity.y <= 0)
    {
        m_pos.y -= SDL_abs(m_velocity.y) - m_pos.y;
        m_velocity.y *= -1;
    }
    if (m_pos.y + m_velocity.y + (m_currentFrame.h * PLAYER_SCALE) >= WINDOW_HEIGHT)
    {
        m_pos.y += (m_pos.y + m_velocity.y + (m_currentFrame.h * PLAYER_SCALE)) - WINDOW_HEIGHT;
        m_velocity.y *= -1;
    }

    m_pos.x += m_velocity.x;
    m_pos.y += m_velocity.y;
}

void Player::addForce(float x, float y)
{
    m_velocity.x += x;
    m_velocity.y += y;
}

void Player::updateSprite(PLAYER_SPRITE sprite)
{
    switch (sprite)
    {
    case PLAYER_SPRITE::MOVING_LEFT:
        m_currentFrame.x = 9;
        m_currentFrame.y = 1;
        m_currentFrame.w = 7;
        m_currentFrame.h = 7;
        break;
    case PLAYER_SPRITE::MOVING_RIGHT:
        m_currentFrame.x = 17;
        m_currentFrame.y = 1;
        m_currentFrame.w = 7;
        m_currentFrame.h = 7;
        break;
    case PLAYER_SPRITE::IDLE:
        m_currentFrame.x = 0;
        m_currentFrame.y = 1;
        m_currentFrame.w = 8;
        m_currentFrame.h = 7;
        break;
    }
}