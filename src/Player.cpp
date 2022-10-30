#include <SDL2/SDL.h>
#include <Player.hpp>
#include <Math.hpp>

/**
 * It's a constructor for the Player class
 *
 * @param pos The position of the player.
 * @param texture The spritesheet in the res folder.
 */
Player::Player(Vector2f pos, SDL_Texture *texture)
    : Entity(pos, texture)
{
    m_currentFrame.x = 0;
    m_currentFrame.y = 1;
    m_currentFrame.w = 8;
    m_currentFrame.h = 7;
}

void Player::update()
{
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
    default:
        m_currentFrame.x = 0;
        m_currentFrame.y = 1;
        m_currentFrame.w = 8;
        m_currentFrame.h = 7;
        break;
    }
}

void Player::render(SDL_Renderer *renderer)
{

    SDL_Rect srcQuad;
    srcQuad.x = m_currentFrame.x;
    srcQuad.y = m_currentFrame.y;
    srcQuad.w = m_currentFrame.w;
    srcQuad.h = m_currentFrame.h;

    SDL_Rect destQuad;
    destQuad.x = m_pos.x;
    destQuad.y = m_pos.y;
    destQuad.w = m_currentFrame.w * 6;
    destQuad.h = m_currentFrame.h * 6;

    SDL_RenderCopy(renderer, m_texture, &srcQuad, &destQuad);
}

// void RenderWindow::render(Entity &entity)
// {

// SDL_Rect srcQuad;
// srcQuad.x = entity.getCurrentFrame().x;
// srcQuad.y = entity.getCurrentFrame().y;
// srcQuad.w = entity.getCurrentFrame().w;
// srcQuad.h = entity.getCurrentFrame().h;

// SDL_Rect destQuad;
// destQuad.x = entity.getPos().x;
// destQuad.y = entity.getPos().y;
// destQuad.w = entity.getCurrentFrame().w;
// destQuad.h = entity.getCurrentFrame().h;

// SDL_RenderCopy(renderer, entity.getTexture(), &srcQuad, &destQuad);
// }