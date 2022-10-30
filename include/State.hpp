#pragma once
#include <SDL2/SDL_image.h>

#include <Player.hpp>
#include <RenderWindow.hpp>
#include <Math.hpp>

class State
{
public:
    Player *player;
    RenderWindow *window;
    bool gameRunning;

    State() : gameRunning(true)
    {
        window = new RenderWindow("Space Invaders", WINDOW_WIDTH, WINDOW_HEIGHT);

        SDL_Surface *playerSurface = IMG_Load("../res/sprites.png");
        SDL_Texture *playerTexture = SDL_CreateTextureFromSurface(window->getRenderer(), playerSurface);

        Vector2f startPos(0, 0);
        player = new Player(startPos, playerTexture);
    }

    ~State()
    {
        delete player;
        delete window;
    }
};