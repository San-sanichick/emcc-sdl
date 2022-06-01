#include "Drawable.h"
#include <string>

class TextLabel : public Drawable {
public:
    TextLabel(int64_t x, int64_t y) {
        Vector2D tPos { x, y };
        pos = tPos;

        text = "Hello world";
    }

    void update(int64_t newX, int64_t newY) {
        Vector2D tPos { newX, newY };
        pos = tPos; 
    }

    Vector2D getPos() {
        return pos;
    }

    void render(SDL_Renderer *renderer) {
        // die
    }

private:
    std::string text;
};