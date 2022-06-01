#include "bench/Benchmark.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

// void loop(void* arg) {
//     static_cast<Benchmark*>(arg)->loop();
// }

int main() {
    printf("hello world\n");

    BenchSettings settings {
        8000,
        0,
        0
    };

    Benchmark bench(settings);

    if (bench.init()) {
        bench.render();

#ifdef __EMSCRIPTEN__
        // we can't exactly use an infinite while loop in a browser, so we use this
        // emscripten_set_main_loop_arg(&loop, &bench, 0, 1);
#else
        while(true) {
            bench.update();
            bench.render();
            // SDL_Delay(100);
        }
#endif
    }

    return 0;
}