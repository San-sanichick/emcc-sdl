#pragma once

#include "Shape.h"

class Rect : public Shape {
public:
    Rect(int64_t x, int64_t y, int64_t w, int64_t h) 
    : Shape(x, y)
    {
        _w = w;
        _h = h;
    }

    void render(SDL_Renderer *renderer) {
        SDL_Rect rect = { 
            (int)(pos.getX()), 
            (int)(pos.getY()), 
            (int)(pos.getX() + _w),
            (int)(pos.getY() + _w) };
        

        SDL_SetRenderDrawColor(renderer, 200, 0, 0, 150);
        SDL_RenderFillRect(renderer, &rect);

        SDL_SetRenderDrawColor(renderer, 0, 150, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);
    }

private:
    int64_t _w;
    int64_t _h;
};