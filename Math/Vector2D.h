#pragma once
#include <cmath>

template<typename T = float>
struct Vector2D {
    T x, y;

    Vector2D(T x = T(0), T y = T(0)) : x(x), y(y) {}

    inline T mod() const {
        return std::sqrt(x * x + y * y);
    }

    inline Vector2D normalized() const {
        T length = this->mod();
        if (length == 0) return Vector2D(0, 0);
        return Vector2D{x / length, y / length};
    }

    inline static float cosAngle(const Vector2D& v1, const Vector2D& v2) {
        return (v1 * v2) / (v1.mod() * v2.mod());
    }

    inline static float cross(const Vector2D& a, const Vector2D& b) {
        return a.x * b.y - a.y * b.x;
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D{x + other.x, y + other.y};
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D{x - other.x, y - other.y};
    }

    T operator*(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    Vector2D operator*(T scalar) const {
        return Vector2D{x * scalar, y * scalar};
    }
};
