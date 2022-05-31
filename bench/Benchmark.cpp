#include "Benchmark.h"
#include <iostream>

Benchmark::Benchmark() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(512, 512, 0, &window, &renderer);
}

Benchmark::~Benchmark()  {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

bool Benchmark::init() {
    std::cout << "Lol" << std::endl;
    return true;
}

void Benchmark::render() {
    // clear screen
    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // draw a rectangle
    SDL_Rect filledRectangle = { 20, 20, 320, 240 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &filledRectangle);

    SDL_RenderPresent(renderer);
    std::cout << "Rendering" << std::endl;
}