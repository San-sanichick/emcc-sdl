#include "Drawable.h"
#include <string>

class TextLabel : public Drawable {
public:
    TextLabel(int64_t x, int64_t y) {
        pos = { x, y };

        text = "Hello world";
    }

    void update(int64_t newX, int64_t newY) {
        pos = { newX, newY }; 
    }

    Vector2D<int64_t> getPos() {
        return pos;
    }

    void render(SDL_Renderer *renderer) {
        // die
    }

private:
    std::string text;
};