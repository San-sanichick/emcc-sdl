#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <stdint.h>
#include <SDL2/SDL.h>

struct BenchSettings {
    uint16_t rectangles;
    uint16_t circles;
    uint16_t textLabels;
};

class Benchmark {
public:
    Benchmark();

    ~Benchmark();

    bool init();

    void render();

private:
    uint16_t width;
    uint16_t height;

    BenchSettings settings;

    SDL_Window   *window;
    SDL_Renderer *renderer;
};

#endif