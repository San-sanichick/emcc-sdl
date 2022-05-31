#include "Drawable.h"

class Shape : Drawable {
    Shape(int64_t x, int64_t y) {
        pos = { x, y }; 
    }

    void update(int64_t newX, int64_t newY) {
        pos = { newX, newY };
    }
};