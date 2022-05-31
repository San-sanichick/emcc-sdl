#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <stdint.h>
#include <vector>
#include <SDL2/SDL.h>
#include "Shapes/Drawable.h"

struct BenchSettings {
    BenchSettings() {
        rectangles = 0;
        circles    = 0;
        textLabels = 0;
    }

    BenchSettings(uint16_t _rectangles, uint16_t _circles, uint16_t _textlabels) {
        rectangles = _rectangles;
        circles    = _circles;
        textLabels = _textlabels;
    }

    uint16_t rectangles;
    uint16_t circles;
    uint16_t textLabels;
};

class Benchmark {
public:
    Benchmark();
    Benchmark(BenchSettings &settings);

    ~Benchmark();

    bool init();

    void render();

private:
    uint16_t width;
    uint16_t height;

    BenchSettings _settings;

    SDL_Window   *window;
    SDL_Renderer *renderer;

    std::vector<std::shared_ptr<Drawable>> _drawables;
};

#endif