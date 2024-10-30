#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <Point2D.h>

namespace Geometry {
    /**
    * @class Vector2D
    * @brief Represents vector in 2D space
    */
    class Vector2D : public Point2D {
    public:
        /**
        * @brief Calculates the length of a vector
        * @return Vector length
        */
        [[nodiscard]] double GetSize() const;

        /**
        * @brief Normalizes the vector
        */
        void Normalize();

        /**
        * @brief Computes a normalized vector
        * @return Normalized vector
        */
        [[nodiscard]] Vector2D GetNormal() const;

        Vector2D& operator*=(double rhs);
        friend Vector2D operator*(double lhs, const Vector2D& rhs);
        friend Vector2D operator*(const Vector2D& lhs, double rhs);

        Vector2D& operator/=(double rhs);
        friend Vector2D operator/(const Vector2D& lhs, double rhs);

        Vector2D& operator+=(const Vector2D& rhs);
        friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);

        Vector2D& operator-=(const Vector2D& rhs);
        friend Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);

        friend Point2D operator+(const Point2D& lhs, const Vector2D& rhs);
        friend Point2D operator+(const Vector2D& lhs, const Point2D& rhs);

        friend Point2D operator-(const Point2D& lhs, const Vector2D& rhs);
        friend Point2D operator-(const Vector2D& lhs, const Point2D& rhs);
    };
}

#endif
