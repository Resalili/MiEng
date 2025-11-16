#pragma once
#include "Vector2D.h"
#include <cmath>
#define PI 3.1415

/// @brief 2D-кватерніон (еквівалент комплексного числа для обертання)
struct Quat2D {
    float cosTheta;
    float sinTheta;

    /// @brief Створює обертання з кута (у градусах)
    Quat2D(float angle = 0.0f) {
        angle = angle * (PI / 180.0f); // конвертація в радіани
        float half = angle * 0.5f;
        cosTheta = std::cosf(half);
        sinTheta = std::sinf(half);
        normalize(); // гарантуємо точність
    }

    /// @brief Створює кватерніон з компонентів
    Quat2D(float c, float s)
        : cosTheta(c), sinTheta(s) {
        normalize();
    }

    /// @brief Нормалізація (для стабільного обертання)
    inline void normalize() {
        float inv = 1.0f / std::sqrt(cosTheta*cosTheta + sinTheta*sinTheta);
        cosTheta *= inv;
        sinTheta *= inv;
    }

    /// @brief Повертає повний кут обертання (радіани)
    inline float angle() const {
        return 2.0f * std::atan2f(sinTheta, cosTheta);
    }

    /// @brief Множення двох 2D-кватерніонів (додавання кутів)
    inline Quat2D operator*(const Quat2D& other) const {
        Quat2D q{
            cosTheta * other.cosTheta - sinTheta * other.sinTheta,
            cosTheta * other.sinTheta + sinTheta * other.cosTheta
        };
        q.normalize();
        return q;
    }

    /// @brief Обертання 2D-вектора цим кватерніоном
    inline Vector2D operator*(const Vector2D& vec) const {
        // обчислюємо повний cos(angle) і sin(angle)
        float c = cosTheta*cosTheta - sinTheta*sinTheta; // cos(angle)
        float s = 2.0f * cosTheta * sinTheta;            // sin(angle)

        return Vector2D{
            vec.x * c - vec.y * s,
            vec.x * s + vec.y * c
        };
    }

    /// @brief Масштабування параметрів (рідко потрібно)
    inline Quat2D operator*(float scalar) const {
        return Quat2D{cosTheta * scalar, sinTheta * scalar};
    }

    /// @brief Інверсія обертання
    inline Quat2D invert() const {
        return Quat2D{cosTheta, -sinTheta};
    }
};
