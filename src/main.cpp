#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

// SDL Libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <RenderWindow.hpp>
#include <Entity.hpp>
#include <Math.hpp>
#include <Utils.hpp>
#include <State.hpp>
#include <Input.hpp>

#define NUM_RECTS 50

State globalState;

template <typename T>
void printArray(T values[], std::size_t size)
{
    std::cout << "[ ";
    for (int i = 0; i < size; ++i)
    {
        if (i != 0)
            std::cout << ", ";
        std::cout << values[i];
    }
    std::cout << " ]";
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    // INITIALISE SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        std::cout << "SDL_Init failed with error: " << SDL_GetError() << std::endl;
        return -1;
    }

    std::cout << "Refresh rate: " << globalState.window->getRefreshRate() << std::endl;

    SDL_Surface *windowIcon = IMG_Load("assets/grass_block.png");
    SDL_SetWindowIcon(globalState.window->getWindow(), windowIcon);

    SDL_Event event;
    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    // MAIN GAME LOOP
    while (globalState.gameRunning)
    {
        int startTicks = SDL_GetTicks64();
        Uint64 start = SDL_GetPerformanceCounter();
        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;
        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                processInput(event, globalState);
            }
            // if (SDL_PollEvent(&event) == NULL)
            // {
            //     globalState.player->updateSprite(PLAYER_SPRITE::IDLE);
            // }
            accumulator -= timeStep;
        }

        accumulator = accumulator / timeStep;

        globalState.window->clear();

        // update entities

        // render entities
        globalState.player->render(globalState.window->getRenderer());
        globalState.window->display();

        // get it display at vsync
        int frameTicks = SDL_GetTicks() - startTicks;
        if (frameTicks < 1000 / globalState.window->getRefreshRate())
        {
            SDL_Delay((1000 / globalState.window->getRefreshRate()) - frameTicks);
        }
    }

    SDL_FreeSurface(windowIcon);
    SDL_Quit();

    return EXIT_SUCCESS;
}