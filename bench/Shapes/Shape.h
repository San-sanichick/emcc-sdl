#pragma once

#include "Drawable.h"

class Shape : public Drawable {
public:
    Shape(int64_t x, int64_t y);

    void update(int64_t newX, int64_t newY);

    Vector2D<int64_t> getPos() override;
};