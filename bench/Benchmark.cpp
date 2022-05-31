#include "Benchmark.h"
#include <iostream>
#include "Shapes/Rect.h"
#include "utils/MarhUtils.h"

Benchmark::Benchmark() {
    _settings = BenchSettings {
        0,
        0,
        0
    };

    width  = 800;
    height = 800;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
}

Benchmark::Benchmark(BenchSettings &settings) {
    _settings = settings;

    width  = 800;
    height = 800;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
}

Benchmark::~Benchmark()  {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

bool Benchmark::init() {
    for (int i = 0; i < _settings.rectangles; i++) {
        std::shared_ptr<Rect> r (new Rect(
            randomInRange(0, width), 
            randomInRange(0, height), 
            randomInRange(10, 50),
            randomInRange(10, 50)
        ));

        _drawables.push_back(r);
    }

    initSDL();

    return true;
}

bool Benchmark::initSDL() {
    return (SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND) != -1);
}

void Benchmark::update() {
    for (auto ePtr : _drawables) {
        ePtr.get()->update(
            randomInRange(-2, 2),
            randomInRange(-2, 2)
        );
    }
}

void Benchmark::render() {
    // clear screen
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    for (int i = 0; i < _drawables.size(); i++) {
        _drawables[i].get()->render(renderer);
    }

    SDL_RenderPresent(renderer);
    std::cout << "Rendering" << std::endl;
}