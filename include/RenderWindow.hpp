#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Entity.hpp>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 600

class RenderWindow
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    RenderWindow(const char *title, int width, int height);
    SDL_Texture *loadTexture(const char *path);
    virtual ~RenderWindow();
    int getRefreshRate();
    void clear();
    void render(Entity &entity);
    void display();
    SDL_Window *getWindow() { return window; }
    SDL_Renderer *getRenderer() { return renderer; }
};