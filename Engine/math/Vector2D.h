#pragma once
#include <cmath>
template<typename T = float >
/// @brief Структура для представлення 2D вектора
struct Vector2D
{
    T x,y;
    
    Vector2D(T x = T(0), T y = T(0)): x(x), y(y) {}
    /// @brief Обчислює довжину вектора
    inline T mod() const {
        return std::sqrt(x * x + y * y);
    }
    /// @brief Нормалізує вектор
    inline Vector2D normalized() const {
        return Vector2D{x / this().mod(), y / mod()};
    }
    /// @brief Обчислює кут між двома векторами в радіанах
    inline static float dot(const Vector2D& v1, const Vector2D& v2) {
        return v1 * v2 / (v1.mod() * v2.mod());
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


