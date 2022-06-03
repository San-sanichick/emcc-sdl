#include "Shape.h"

Shape::Shape(int64_t x, int64_t y) {
    pos = { x, y };
}

void Shape::update(int64_t newX, int64_t newY) {
    pos = { newX, newY }; 
}

Vector2D<int64_t> Shape::getPos() {
    return pos;
}