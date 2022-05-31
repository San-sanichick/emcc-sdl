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

    BenchSettings(uint32_t _rectangles, uint32_t _circles, uint32_t _textlabels) {
        rectangles = _rectangles;
        circles    = _circles;
        textLabels = _textlabels;
    }

    uint32_t rectangles;
    uint32_t circles;
    uint32_t textLabels;
};

class Benchmark {
public:
    Benchmark();
    Benchmark(BenchSettings &settings);

    ~Benchmark();

    bool init();
    void render();
    void loop();

private:
    bool initSDL();
    void update();
    // void renderFPS(uint16_t frameTime);

private:
    uint16_t width;
    uint16_t height;

    BenchSettings _settings;

    SDL_Window   *window;
    SDL_Renderer *renderer;

    std::vector<std::shared_ptr<Drawable>> _drawables;
};

#endif