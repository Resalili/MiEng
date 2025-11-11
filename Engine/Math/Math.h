#pragma once

#include "Vector2D.h"
#include "Quat2D.h"
#include "Matrix3x3.h"

/// @brief Простір імен для математичних функцій у 2D
namespace Math {

    /// @brief Обчислює напрямок (нормалізований вектор) від точки `from` до `to`
    inline Vector2D<> DirectionTo(const Vector2D<>& from, const Vector2D<>& to) {
        return (to - from).normalized();
    }

    /// @brief Повертає евклідову відстань між точками `a` та `b`
    inline float Distance(const Vector2D<>& a, const Vector2D<>& b) {
        return (b - a).mod();
    }

    /// @brief Обчислює кут (в радіанах) між векторами `a` та `b`
    /// @note Повертає значення з діапазону [-π, π]
    inline float AngleBetween(const Vector2D<>& a, const Vector2D<>& b) {
        return std::atan2(Vector2D<>::cross(a, b), a * b); // atan2(cross, dot)
    }

    /// @brief Створює кватерніон для обертання з точки `from` у напрямку `to`
    inline Quat2D LookAt(const Vector2D<>& from, const Vector2D<>& to) {
        Vector2D<> dir = DirectionTo(from, to);
        return Quat2D(std::atan2(dir.y, dir.x));
    }

    /// @brief Обертає вектор `vec` на заданий кут `angle` (в радіанах)
    inline Vector2D<> Rotate(const Vector2D<>& vec, float angle) {
        return Quat2D(angle) * vec;
    }

    /// @brief Застосовує афінну трансформацію `mat` до вектора `vec`
    inline Vector2D<> Transform(const Vector2D<>& vec, const Matrix3x3& mat) {
        return mat.TransformPoint(vec);
    }

    /// @brief Створює матрицю трансформації з позиції, кута і масштабу
    inline Matrix3x3 Compose(const Vector2D<>& position, float angle, const Vector2D<>& scale = {1, 1}) {
        return Matrix3x3::Translate(position)
             * Matrix3x3::Rotate(angle)
             * Matrix3x3::Scale(scale);
    }

    /// @brief Повертає одиничну матрицю (без трансформацій)
    inline Matrix3x3 Identity() {
        return Matrix3x3::Identity();
    }

    /// @brief Лінійна інтерполяція між `a` та `b` за параметром `t` ∈ [0, 1]
    template<typename T>
    inline T Lerp(const T& a, const T& b, float t) {
        return a * (1.0f - t) + b * t;
    }

}
