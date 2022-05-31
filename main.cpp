#include <stdio.h>
#include "bench/Benchmark.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

int main() {
    printf("hello world\n");
    Benchmark bench;

    bench.init();
    bench.render();

#ifdef __EMSCRIPTEN__
    emscripten_sleep(10000);
#else
    SDL_Delay(10000);
#endif

    return 0;
}