#include <stdint.h>
#include <algorithm>

class Vector2D {
public:
    Vector2D() {
        _x = 0;
        _y = 0;
    }

    Vector2D(int64_t x, int64_t y) {
        _x = x;
        _y = y;
    }

    Vector2D(const Vector2D &v2) {
        _x = v2._x;
        _y = v2._y;
    }

    Vector2D& operator+=(const Vector2D &v2) {
        _x + v2._x;
        _y + v2._y;
        return *this;
    }

    Vector2D& operator-=(const Vector2D &v2) {
        _x - v2._x;
        _y - v2._y;
        return *this;
    }

    Vector2D& operator=(Vector2D o) {
        using std::swap;

        swap(*this, o);
        return *this;
    }

    Vector2D& operator=(int64_t *args) {
        _x = args[0];
        _y = args[1];

        return *this;
    }

    int64_t getX() {
        return _x;
    }

    int64_t getY() {
        return _y;
    }

    void setX(uint64_t &x) {
        _x = x;
    }

    void setY(uint64_t &y) {
        _y = y;
    }

private:
    int64_t _x;
    int64_t _y;
};

Vector2D operator+(Vector2D v1, const Vector2D &v2) {
    v1 += v2;
    return v1;
}

Vector2D operator-(Vector2D v1, const Vector2D &v2) {
    v1 -= v2;
    return v1;
}