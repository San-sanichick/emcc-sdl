#ifndef SHAPE_H
#define SHAPE_H

#include "Drawable.h"

class Shape : public Drawable {
public:
    Shape(int64_t x, int64_t y) {
        Vector2D tPos { x, y };
        pos = tPos; 
    }

    void update(int64_t newX, int64_t newY) {
        Vector2D tPos { newX, newY };
        pos = tPos; 
    }

    Vector2D getPos() {
        return pos;
    }
};

#endif /* SHAPE_H */