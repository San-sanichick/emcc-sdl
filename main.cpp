#include <stdio.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <SDL2/SDL.h>

int main() {
    printf("hello world\n");

    SDL_Window*   win;
    SDL_Renderer* renderer;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(512, 512, 0, &win, &renderer);

    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Rect filledRectangle = { 20, 20, 320, 240 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &filledRectangle);

    SDL_RenderPresent(renderer);

#ifdef __EMSCRIPTEN__
    emscripten_sleep(10000);
#else
    SDL_Delay(10000);
#endif

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}