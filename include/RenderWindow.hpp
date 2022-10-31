#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <type_traits>
#include <memory>

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
    void display();
    SDL_Window *getWindow() { return window; }
    SDL_Renderer *getRenderer() { return renderer; }

    template <class T_Entity>
    inline void render(T_Entity *entity, float xscale = 1.f, float yscale = 1.f)
    {
        static_assert(std::is_base_of<Entity, T_Entity>::value, "Must be of type Entity or subclass of Entity.");

        SDL_Rect srcQuad;
        srcQuad.x = entity->getCurrentFrame().x;
        srcQuad.y = entity->getCurrentFrame().y;
        srcQuad.w = entity->getCurrentFrame().w;
        srcQuad.h = entity->getCurrentFrame().h;

        SDL_Rect destQuad;
        destQuad.x = entity->getPos().x;
        destQuad.y = entity->getPos().y;
        destQuad.w = entity->getCurrentFrame().w * xscale;
        destQuad.h = entity->getCurrentFrame().h * yscale;

        SDL_RenderCopy(renderer, entity->getTexture(), &srcQuad, &destQuad);
    }

    template <class T_Entity>
    inline void render(std::shared_ptr<T_Entity> entity, float xscale = 1.f, float yscale = 1.f)
    {
        static_assert(std::is_base_of<Entity, T_Entity>::value, "Must be of type Entity or subclass of Entity.");

        SDL_Rect srcQuad;
        srcQuad.x = entity->getCurrentFrame().x;
        srcQuad.y = entity->getCurrentFrame().y;
        srcQuad.w = entity->getCurrentFrame().w;
        srcQuad.h = entity->getCurrentFrame().h;

        SDL_Rect destQuad;
        destQuad.x = entity->getPos().x;
        destQuad.y = entity->getPos().y;
        destQuad.w = entity->getCurrentFrame().w * xscale;
        destQuad.h = entity->getCurrentFrame().h * yscale;

        SDL_RenderCopy(renderer, entity->getTexture(), &srcQuad, &destQuad);
    }
};