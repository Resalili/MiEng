#pragma once
#include <cmath>



struct Vector2D {
    float x, y;

    Vector2D(float x = float(0), float y = float(0)) : x(x), y(y) {}

    inline float mod() const {
        return std::sqrt(x * x + y * y);
    }

    inline Vector2D normalized() const {
        float length = this->mod();
        if (length == 0.0f) return Vector2D(0.0f, 0.0f);
        return Vector2D{x / static_cast<float>(length), y / static_cast<float>(length)};
    }

    inline static float cosAngle(const Vector2D& v1, const Vector2D& v2) {
        float denom = v1.mod() * v2.mod();
        if (denom == 0.0f) return 0.0f;
        return (v1 * v2) / denom;
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

    float operator*(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    Vector2D operator*(float scalar) const {
        return Vector2D{x * scalar, y * scalar};
    }

};
