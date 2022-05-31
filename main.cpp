#include "bench/Benchmark.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

void doLoop(void *voidFnPtr) {
    auto *fnPtr = reinterpret_cast<std::function<void()>*>(voidFnPtr);

    if (fnPtr) {
        auto &fn = *fnPtr;
        fn(); 
    }
}

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

    auto loop = [&bench]() {
        bench.update();
        bench.render();
    };

#ifdef __EMSCRIPTEN__
    // emscripten_sleep(10000);
    emscripten_set_main_loop_arg(doLoop, &loop, 0, 1);
#else
    SDL_Delay(10000);
#endif

    return 0;
}