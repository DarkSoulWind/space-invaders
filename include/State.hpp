#pragma once
#include <SDL2/SDL_image.h>
#include <vector>
#include <memory>

#include <Player.hpp>
#include <Laser.hpp>
#include <RenderWindow.hpp>
#include <Math.hpp>

class State
{
public:
    Player *player;
    RenderWindow *window;
    SDL_Texture *spriteSheetTexture;
    std::vector<Laser> lasers;
    bool gameRunning;
    double deltaTime;

    State();
    ~State();
    void createLaser();
};
