#include <Line2D.h>
#include <GlobalConstants.h>
#include <cmath>

namespace Geometry {
    Point2D Line2D::GetMidPoint() const {
        const double midX = (P1.x + P2.x) / 2.;
        const double midY = (P1.y + P2.y) / 2.;
        return {midX, midY};
    }

    Vector2D Line2D::GetNormal() const {
        Vector2D normal{CalculateA(), CalculateB()};
        normal.Normalize();
        return normal;
    }

    double Line2D::GetDistanceToPoint(const Point2D &point) const {
        const double a = CalculateA();
        const double b = CalculateB();
        const double c = CalculateC();

        return (a * point.x + b * point.y + c) / std::sqrt(a * a + b * b);
    }

    Point2D Line2D::ReflectPoint(const Point2D &point) const {
        return point - 2 * GetDistanceToPoint(point) * GetNormal();
    }

    bool Line2D::operator==(const Line2D &line) const {
        return  GetDistanceToPoint(line.P1) < GlobalConstants::Epsilon &&
                GetDistanceToPoint(line.P2) < GlobalConstants::Epsilon;
    }

    double Line2D::CalculateA() const {
        return P2.y - P1.y;
    }

    double Line2D::CalculateB() const {
        return P1.x - P2.x;
    }

    double Line2D::CalculateC() const {
        return P1.y * P2.x - P1.x * P2.y;
    }

}