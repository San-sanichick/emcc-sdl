#include "utils/Vector2D.h"

class Drawable {
public:
    Drawable();
    virtual ~Drawable();
    virtual void update(int64_t newX, int64_t newY) = 0;
    virtual void render() = 0;

protected:
    Vector2D pos;
};