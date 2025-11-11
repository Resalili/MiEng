#pragma once
#include "../math/Vector2D.h"
#include "../math/Quat2D.h"
#include "../math/Matrix3x3.h"
class Transform{
    public:
        Vector2D position;
        Quat2D rotation;


        Transform(const Vector2D& position = Vector2D{}, const Quat2D& rotation = Quat2D{}): position(position), rotation(rotation) {}
        
        /// @brief Конвертує Transform в матрицю 3x3
        inline Matrix3x3 toMatrix() const {
            Matrix3x3 translationMat = Matrix3x3::Translate(position);
            Matrix3x3 rotationMat = Matrix3x3::Rotate(rotation.angle());
            return translationMat * rotationMat;
        }
}