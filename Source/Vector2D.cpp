#include <Vector2D.h>
#include <cmath>

namespace Geometry {
    double Vector2D::GetSize() const {
        return std::sqrt(x * x + y * y);
    }

    void Vector2D::Normalize() {
        const auto size = GetSize();
        x /= size;
        y /= size;
    }

    Vector2D Vector2D::GetNormal() const {
        Vector2D result(*this);
        result.Normalize();
        return result;
    }

    Vector2D& Vector2D::operator*=(double rhs) {
        x *= rhs;
        y *= rhs;
        return *this;
    }

    Vector2D operator*(double lhs, const Vector2D &rhs) {
        Vector2D result(rhs);
        result *= lhs;
        return result;
    }

    Vector2D operator*(const Vector2D &lhs, double rhs) {
        Vector2D result(lhs);
        result *= rhs;
        return result;
    }

    Vector2D& Vector2D::operator/=(double rhs) {
        x /= rhs;
        y /= rhs;
        return *this;
    }

    Vector2D operator/(const Vector2D &lhs, double rhs) {
        Vector2D result(lhs);
        result /= rhs;
        return result;
    }

    Vector2D& Vector2D::operator+=(const Vector2D &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs) {
        Vector2D result(lhs);
        result += rhs;
        return result;
    }

    Vector2D &Vector2D::operator-=(const Vector2D &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs) {
        Vector2D result(lhs);
        result -= rhs;
        return result;
    }

}