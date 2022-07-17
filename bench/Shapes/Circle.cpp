#include "Circle.h"

void Circle::render(SDL_Renderer *renderer) {

    const int32_t diameter = (r * 2);
    int32_t x = (r - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    const int64_t centerX = this->getPos().x;
    const int64_t centerY = this->getPos().y;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 150);

    while (x >= y)
    {
        SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
        SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);

        if (error <= 0)
        {
            y++;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            x--;
            tx += 2;
            error += (tx - diameter);
        }
    }
    
}