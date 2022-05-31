#include <stdio.h>
#include "bench/Benchmark.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

int main() {
    printf("hello world\n");

    BenchSettings settings {
        (uint16_t)100,
        (uint16_t)0,
        (uint16_t)0
    };

    Benchmark bench(settings);

    if (bench.init()) {
        bench.render();
    }

#ifdef __EMSCRIPTEN__
    emscripten_sleep(10000);
#else
    SDL_Delay(10000);
#endif

    return 0;
}