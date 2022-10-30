#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <RenderWindow.hpp>
#include <Entity.hpp>
#include <iostream>

/**
 * Create a window and a renderer
 *
 * @param title The title of the window
 * @param width The width of the window in pixels.
 * @param height The height of the window
 */
RenderWindow::RenderWindow(const char *title, int width, int height)
    : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_METAL);

    if (window == NULL)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

/**
 * Loads an image from the file path specified and returns a pointer to the texture
 *
 * @param path The path to the image file.
 *
 * @return A pointer to an SDL_Texture object.
 */
SDL_Texture *RenderWindow::loadTexture(const char *path)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, path);

    if (texture == NULL)
    {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }

    return texture;
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

/**
 * Get the refresh rate of the display that the window is on
 *
 * @return The refresh rate of the display.
 */
int RenderWindow::getRefreshRate()
{
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);
    return mode.refresh_rate;
}

/**
 * It clears the renderer
 */
void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity &entity)
{

    SDL_Rect srcQuad;
    srcQuad.x = entity.getCurrentFrame().x;
    srcQuad.y = entity.getCurrentFrame().y;
    srcQuad.w = entity.getCurrentFrame().w;
    srcQuad.h = entity.getCurrentFrame().h;

    SDL_Rect destQuad;
    destQuad.x = entity.getPos().x;
    destQuad.y = entity.getPos().y;
    destQuad.w = entity.getCurrentFrame().w;
    destQuad.h = entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, entity.getTexture(), &srcQuad, &destQuad);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}