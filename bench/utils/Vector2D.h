#pragma once

#include <stdint.h>

template<class T>
class Vector2D {
public:
    Vector2D(): x(0), y(0) {};
    Vector2D(const T _x, const T _y): x(_x), y(_y) {};
    Vector2D(const Vector2D &v2): x(v2.x), y(v2.y) {};
    ~Vector2D() {};

    Vector2D<T>& operator+=(const Vector2D<T> &v2) {
        x += v2.x;
        y += v2.y;
        return *this;
    };
    Vector2D<T>& operator-=(const Vector2D<T> &v2) {
        x -= v2.x;
        y -= v2.y;
        return *this;
    };

    // Vector2D& operator=(Vector2D &o) = default;

public:
    T x;
    T y;
};

template<class T> Vector2D<T> operator+(Vector2D<T> v1, const Vector2D<T> &v2) {
    v1 += v2;
    return v1;
}

template<class T> Vector2D<T> operator-(Vector2D<T> v1, const Vector2D<T> &v2) {
    v1 -= v2;
    return v1;
}