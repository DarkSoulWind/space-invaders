#pragma once
#include <SDL2/SDL_image.h>
#include <vector>
#include <memory>

#include <Player.hpp>
#include <Laser.hpp>
#include <Enemy.hpp>
#include <RenderWindow.hpp>
#include <Math.hpp>

class State
{
public:
    Player *player;
    RenderWindow *window;
    SDL_Texture *spriteSheetTexture;
    std::vector<Laser> lasers;
    std::vector<Enemy> enemies;
    bool gameRunning;
    double deltaTime;

    State();
    ~State();
    void createLaser();
    void createEnemy();
    void update();
    void render();
};
