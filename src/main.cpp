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
#include <Player.hpp>

State globalState;

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

    SDL_Surface *windowIcon = IMG_Load("../res/sprites.png");
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
            accumulator -= timeStep;
        }

        accumulator = accumulator / timeStep;
        // std::cout << "Accumulator: " << accumulator << std::endl;

        globalState.window->clear();

        // UPDATE ENTITIES
        globalState.update();

        // RENDER ENTITIES
        globalState.render();

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