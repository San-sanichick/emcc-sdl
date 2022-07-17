#pragma once

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(int64_t x, int64_t y, uint32_t r)
    : Shape(x, y)
    , r(r)
    {
    }

    void render(SDL_Renderer * renderer) override;

private:
    uint32_t r;
};