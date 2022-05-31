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

void Benchmark::loop() {
    // uint64_t oldTime = SDL_GetTicks64();

    update();
    render();

    // uint64_t elapsed = (SDL_GetTicks64() - oldTime);
    // float fps = (elapsed > 0) ? (1000.0f / elapsed) : 0.0f;

    // std::cout << "elapsed: " << elapsed << ", fps: " << (int)fps << std::endl;
}

bool Benchmark::initSDL() {
    return (SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND) != -1);
}

void Benchmark::update() {
    for (auto ePtr : _drawables) {
        ePtr.get()->update(
            ePtr.get()->getPos().getX() + randomInRange(-2, 2),
            ePtr.get()->getPos().getY() + randomInRange(-2, 2)
        );
    }
}

void Benchmark::render() {
    // clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < _drawables.size(); i++) {
        _drawables[i].get()->render(renderer);
    }

    SDL_RenderPresent(renderer);
}

// void Benchmark::renderFPS(uint16_t frameTime) {
    
// }