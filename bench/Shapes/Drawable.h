#pragma once

#include "../utils/Vector2D.h"
#include <SDL2/SDL.h>

class Drawable {
public:
    Drawable() {};
    virtual ~Drawable() {};
    virtual void update(int64_t newX, int64_t newY) = 0;
    virtual void render(SDL_Renderer *renderer) = 0;

    virtual Vector2D getPos() = 0;

protected:
    Vector2D pos;
};