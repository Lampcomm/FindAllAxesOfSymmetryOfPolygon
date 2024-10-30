#include <Line2D.h>
#include <GlobalConstants.h>
#include <cmath>

namespace Geometry {
    Point2D Line2D::GetMidPoint() const {
        const double midX = (P1.X + P2.X) / 2.;
        const double midY = (P1.Y + P2.Y) / 2.;
        return {midX, midY};
    }

    Vector2D Line2D::GetNormal() const {
        Vector2D normal{CalculateA(), CalculateB()};
        normal.Normalize();
        return normal;
    }

    double Line2D::CalculateDistanceToPoint(const Point2D &point) const {
        const double a = CalculateA();
        const double b = CalculateB();
        const double c = CalculateC();

        return (a * point.X + b * point.Y + c) / std::sqrt(a * a + b * b);
    }

    Point2D Line2D::ReflectPoint(const Point2D &point) const {
        return point - 2 * CalculateDistanceToPoint(point) * GetNormal();
    }

    bool Line2D::operator==(const Line2D &line) const {
        return  CalculateDistanceToPoint(line.P1) < GlobalConstants::Epsilon &&
                CalculateDistanceToPoint(line.P2) < GlobalConstants::Epsilon;
    }

    double Line2D::CalculateA() const {
        return P2.Y - P1.Y;
    }

    double Line2D::CalculateB() const {
        return P1.X - P2.X;
    }

    double Line2D::CalculateC() const {
        return P1.Y * P2.X - P1.X * P2.Y;
    }

}