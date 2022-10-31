#include <SDL2/SDL.h>
#include <State.hpp>
#include <Player.hpp>

inline void processInput(SDL_Event &event, State &state)
{

    switch (event.type)
    {

    case SDL_QUIT:
        state.gameRunning = false;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            state.gameRunning = false;
            break;
        case SDLK_a:
            state.player->addForce(-PLAYER_VELOCTIY, 0);
            state.player->updateSprite(PLAYER_SPRITE::MOVING_LEFT);
            break;
        case SDLK_w:
            state.player->addForce(0, -PLAYER_VELOCTIY);
            break;
        case SDLK_s:
            state.player->addForce(0, PLAYER_VELOCTIY);
            break;
        case SDLK_d:
            state.player->updateSprite(PLAYER_SPRITE::MOVING_RIGHT);
            state.player->addForce(PLAYER_VELOCTIY, 0);
            break;
        case SDLK_m:
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "shush", "you need to shush", state.window->getWindow());
            break;
        case SDLK_SPACE:
            state.createLaser();
            break;
        default:
            state.player->updateSprite(PLAYER_SPRITE::IDLE);
            break;
        }
        break;

    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_a:
            state.player->updateSprite(PLAYER_SPRITE::IDLE);
            break;
        case SDLK_d:
            state.player->updateSprite(PLAYER_SPRITE::IDLE);
            break;
        }
        break;
    }
}