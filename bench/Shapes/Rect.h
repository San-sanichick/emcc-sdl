#pragma once

#include "Shape.h"

class Rect : public Shape {
public:
    Rect(int64_t x, int64_t y, int64_t _w, int64_t _h) 
    : Shape(x, y)
    , w(_w)
    , h(_h)
    {
    }

    void render(SDL_Renderer *renderer) override;

private:
    int64_t w;
    int64_t h;
};