#pragma once
#include "Vector2D.h"

struct Ray2D
{
    Vector2D origin;
    Vector2D direction;

    Ray2D(const Vector2D& origin, const Vector2D& direction)
        : origin(origin), direction(direction.normalized()) {}
        
};