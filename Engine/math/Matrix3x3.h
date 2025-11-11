#pragma once
#include <cmath>
#include "Vector2D.h"

struct Matrix3x3 {
    float m[3][3];
    
    inline float* operator[](int row) {
        return m[row]; 
    }

    inline const float* operator[](int row) const {
        return m[row];
    }

    inline static Matrix3x3 Identity() {
        return { {
            { 1, 0, 0 },
            { 0, 1, 0 },
            { 0, 0, 1 }
        } };
    }
    /// @brief Створює матрицю трансляції
    inline static Matrix3x3 Translate(const Vector2D& pos) {
        Matrix3x3 result = Identity();
        result.m[0][2] = pos.x;
        result.m[1][2] = pos.y;
        return result;
    }
    /// @brief Створює матрицю обертання
    inline static Matrix3x3 Rotate(float angle) {
        Matrix3x3 result = Identity();
        float c = std::cos(angle);
        float s = std::sin(angle);
        result.m[0][0] = c;
        result.m[0][1] = -s;
        result.m[1][0] = s;
        result.m[1][1] = c;
        return result;
    }
    /// @brief Створює матрицю масштабування
    inline static Matrix3x3 Scale(const Vector2D& scale) {
        Matrix3x3 result = Identity();
        result.m[0][0] = scale.x;
        result.m[1][1] = scale.y;
        return result;
    }

    inline Matrix3x3 operator*(const Matrix3x3& other) const {
        Matrix3x3 result{};
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                result.m[row][col] =
                    m[row][0] * other.m[0][col] +
                    m[row][1] * other.m[1][col] +
                    m[row][2] * other.m[2][col];
            }
        }
        return result;
    }
    /// @brief Применяє трансформацію до вектора
    inline Vector2D TransformPoint(const Vector2D& v) const {
        return {
            m[0][0] * v.x + m[0][1] * v.y + m[0][2],
            m[1][0] * v.x + m[1][1] * v.y + m[1][2]
        };
    }
};
