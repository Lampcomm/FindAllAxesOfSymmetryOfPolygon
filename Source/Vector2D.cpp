#include <Vector2D.h>
#include <cmath>

namespace Geometry {
    double Vector2D::GetSize() const {
        return std::sqrt(X * X + Y * Y);
    }

    void Vector2D::Normalize() {
        const auto size = GetSize();
        X /= size;
        Y /= size;
    }

    Vector2D Vector2D::GetNormal() const {
        Vector2D result(*this);
        result.Normalize();
        return result;
    }

    Vector2D& Vector2D::operator*=(double rhs) {
        X *= rhs;
        Y *= rhs;
        return *this;
    }

    Vector2D operator*(double lhs, const Vector2D &rhs) {
        Vector2D result(rhs);
        result *= lhs;
        return result;
    }

    Vector2D operator*(const Vector2D &lhs, double rhs) {
        return rhs * lhs;
    }

    Vector2D& Vector2D::operator/=(double rhs) {
        X /= rhs;
        Y /= rhs;
        return *this;
    }

    Vector2D operator/(const Vector2D &lhs, double rhs) {
        Vector2D result(lhs);
        result /= rhs;
        return result;
    }

    Vector2D& Vector2D::operator+=(const Vector2D &rhs) {
        X += rhs.X;
        Y += rhs.Y;
        return *this;
    }

    Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs) {
        Vector2D result(lhs);
        result += rhs;
        return result;
    }

    Vector2D &Vector2D::operator-=(const Vector2D &rhs) {
        X -= rhs.X;
        Y -= rhs.Y;
        return *this;
    }

    Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs) {
        Vector2D result(lhs);
        result -= rhs;
        return result;
    }

    Point2D operator+(const Point2D& lhs, const Vector2D& rhs) {
        Point2D result(lhs);
        result.X += rhs.X;
        result.Y += rhs.Y;
        return result;
    }

    Point2D operator+(const Vector2D& lhs, const Point2D& rhs) {
        return rhs + lhs;
    }

    Point2D operator-(const Point2D& lhs, const Vector2D& rhs) {
        Point2D result(lhs);
        result.X -= rhs.X;
        result.Y -= rhs.Y;
        return result;
    }

    Point2D operator-(const Vector2D& lhs, const Point2D& rhs) {
        return rhs - lhs;
    }
}