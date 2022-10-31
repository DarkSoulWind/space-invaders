#pragma once

#include <Entity.hpp>

class Laser : public Entity
{
private:
    bool m_remove;

public:
    Laser(Vector2f pos, SDL_Texture *texture);

    void update();

    inline const bool shouldBeRemoved() const { return m_remove; }
};