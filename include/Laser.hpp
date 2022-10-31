#pragma once

#include <Entity.hpp>

class Laser : public Entity
{
private:
public:
    Laser(Vector2f pos, SDL_Texture *texture);

    void update();
};