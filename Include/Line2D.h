#ifndef LINE2D_H
#define LINE2D_H

#include <Point2D.h>
#include <Vector2D.h>

namespace Geometry {
    /**
    * @class Line2D
    * @brief Represents line in 2D space
    */
    class Line2D {
    public:
        Point2D P1; /**< First point through which the line passes */
        Point2D P2; /**< Second point through which the line passes */

        /**
        * @brief Calculates the point located between points P1 and P2
        * @return Midpoint between points P1 and P2
        */
        [[nodiscard]] Point2D GetMidPoint() const;

        /**
        * @brief Calculates the normal to a line
        * @return Normal to a line
        */
        [[nodiscard]] Vector2D GetNormal() const;

        /**
        * @brief Calculates the distance from point to line
        * @param point The point from which the distance needs to be calculated
        * @return Distance from point to line
        */
        [[nodiscard]] double CalculateDistanceToPoint(const Point2D& point) const;

        /**
        * @brief Calculates the reflection of point about line
        * @param point The point to be reflected
        * @return Reflected point
        */
        [[nodiscard]] Point2D ReflectPoint(const Point2D& point) const;

        bool operator==(const Line2D& line) const;

    private:
        /**
        * @brief Calculates the line parameter a
        * @return Line parameter a
        */
        [[nodiscard]] double CalculateA() const;

        /**
        * @brief Calculates the line parameter b
        * @return Line parameter b
        */
        [[nodiscard]] double CalculateB() const;

        /**
        * @brief Calculates the line parameter c
        * @return Line parameter c
        */
        [[nodiscard]] double CalculateC() const;
    };
}

#endif
