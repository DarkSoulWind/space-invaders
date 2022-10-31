#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <string>
#include <sstream>

// SDL Libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <imgui.h>
#include <imgui_impl_sdl.h>
#include <imgui_impl_sdlrenderer.h>

#include <RenderWindow.hpp>
#include <Entity.hpp>
#include <Math.hpp>
#include <Utils.hpp>
#include <State.hpp>
#include <Input.hpp>
#include <Player.hpp>

#define DEBUG

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

#ifdef DEBUG
    // INITIALISE IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer(globalState.window->getWindow(), globalState.window->getRenderer());
    ImGui_ImplSDLRenderer_Init(globalState.window->getRenderer());
#endif

    std::cout << "Refresh rate: " << globalState.window->getRefreshRate() << std::endl;

    SDL_Surface *windowIcon = IMG_Load("../res/sprites.png");
    SDL_SetWindowIcon(globalState.window->getWindow(), windowIcon);

    SDL_Event event;
    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

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
#ifdef DEBUG
            ImGui_ImplSDL2_ProcessEvent(&event);
#endif
            while (SDL_PollEvent(&event))
            {
                processInput(event, globalState);
            }
            accumulator -= timeStep;
        }

#ifdef DEBUG
        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

            std::ostringstream os;
            os << "Number of enemies: " << globalState.enemies.size() << std::endl;

            ImGui::Text("Number of enemies: %d", globalState.enemies.size()); // Display some text (you can use a format strings too)
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        SDL_SetRenderDrawColor(globalState.window->getRenderer(), (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
        SDL_RenderClear(globalState.window->getRenderer());
        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(globalState.window->getRenderer());
#endif

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

#ifdef DEBUG
    ImGui_ImplSDLRenderer_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
#endif

    SDL_FreeSurface(windowIcon);
    SDL_Quit();

    return EXIT_SUCCESS;
}