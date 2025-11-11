#pragma once
#include "../math/Vector2D.h"
#include <cmath>

struct RayHit {
    bool hit = false;
    Vector2D position;
    Vector2D normal;
    float distance = 0.0f;
};

struct Ray2D {
    Vector2D origin;
    Vector2D direction;

    Ray2D(const Vector2D& o, const Vector2D& d)
        : origin(o), direction(d.normalized()) {}

    inline RayHit intersectSegment(const Vector2D& p1, const Vector2D& p2) const {
        RayHit hit;

        Vector2D v1 = origin - p1;
        Vector2D v2 = p2 - p1;
        Vector2D v3(-direction.y, direction.x);

        float dot = v2.dot(v3);
        if (std::abs(dot) < 1e-6f)
            return hit;

        float t1 = v2.cross(v1) / dot;
        float t2 = v1.dot(v3) / dot;

        if (t1 >= 0.0f && t2 >= 0.0f && t2 <= 1.0f) {
            hit.hit = true;
            hit.distance = t1;
            hit.position = origin + direction * t1;
        }

        return hit;
    }
};
