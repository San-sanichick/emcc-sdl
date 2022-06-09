#pragma once

#ifndef BUILD_MAIN
    #ifdef __EMSCRIPTEN__
    #include <emscripten.h>
    #include <emscripten/bind.h>
    #endif
#else
    #ifdef __EMSCRIPTEN__
    #include <emscripten.h>
    #endif
#endif

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
    Benchmark(BenchSettings &settings);

    ~Benchmark();

    bool init();
    void render();
    void loop();

    void startLoop();

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

#ifndef BUILD_MAIN
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::value_object<BenchSettings>("BenchSettings")
        .field("rectangles", &BenchSettings::rectangles)
        .field("circles", &BenchSettings::circles)
        .field("textLabels", &BenchSettings::textLabels);

    emscripten::class_<Benchmark>("Benchmark")
        .constructor<BenchSettings>()
        .function("init", &Benchmark::init)
        .function("render", &Benchmark::render)
        .function("startLoop", &Benchmark::startLoop)
        .function("loop", &Benchmark::loop);
}
#endif
#endif