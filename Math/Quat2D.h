#pragma once
#include "Vector2D.h"
#include <cmath>

/// @brief Структура для представлення 2D кватерніона (обертання в площині)
struct Quat2D {
    float cosTheta;
    float sinTheta;

    Quat2D(float angle = 0.0f)
        : cosTheta(std::cosf(angle / 2.0f)),
          sinTheta(std::sinf(angle / 2.0f)) {}

    Quat2D(float cosTheta, float sinTheta)
        : cosTheta(cosTheta), sinTheta(sinTheta) {}

    inline float angle() const {
        return 2.0f * std::atan2f(sinTheta, cosTheta);
    }

    inline Quat2D operator*(const Quat2D& other) const {
        return Quat2D{
            cosTheta * other.cosTheta - sinTheta * other.sinTheta,
            cosTheta * other.sinTheta + sinTheta * other.cosTheta
        };
    }

    inline Vector2D operator*(const Vector2D& vec) const {
        return Vector2D {
            vec.x * cosTheta - vec.y * sinTheta,
            vec.x * sinTheta + vec.y * cosTheta
        };
    }

    inline Quat2D operator*(float scalar) const {
        return Quat2D{cosTheta * scalar, sinTheta * scalar};
    }

    inline Quat2D invert() const {
        return Quat2D{cosTheta, -sinTheta};
    }
};
