#pragma once
#include "Ray2D.h"

namespace Physics {
    inline RayHit Raycast(const Vector2D& origin,
                          const Vector2D& direction,
                          float maxDistance,
                          uint32_t mask = 0xFFFFFFFF) {
        return Ray2D(origin, direction).cast(maxDistance, mask);
    }
}
