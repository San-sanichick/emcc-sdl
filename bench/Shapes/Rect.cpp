#include "Rect.h"

void Rect::render(SDL_Renderer *renderer) {
        SDL_Rect rect = { 
            (int)(pos.x), 
            (int)(pos.y), 
            (int)(pos.x + w),
            (int)(pos.y + w) };
        

        SDL_SetRenderDrawColor(renderer, 200, 0, 0, 150);
        SDL_RenderFillRect(renderer, &rect);

        SDL_SetRenderDrawColor(renderer, 0, 150, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);
    }