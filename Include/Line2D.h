#ifndef LINE2D_H
#define LINE2D_H

#include <Point2D.h>
#include <Vector2D.h>

namespace Geometry {
    class Line2D {
    public:
        Point2D P1;
        Point2D P2;

        [[nodiscard]] Point2D GetMidPoint() const;
        [[nodiscard]] Vector2D GetNormal() const;
        [[nodiscard]] double GetDistanceToPoint(const Point2D& point) const;
        [[nodiscard]] Point2D ReflectPoint(const Point2D& point) const;

        bool operator==(const Line2D& line) const;

    private:
        [[nodiscard]] double CalculateA() const;
        [[nodiscard]] double CalculateB() const;
        [[nodiscard]] double CalculateC() const;
    };
}

#endif
