#ifndef POLYGON2D_H
#define POLYGON2D_H

#include <vector>
#include <Point2D.h>
#include <Line2D.h>

namespace Geometry {
    class Polygon2D {
    public:
        using TVerticesList = std::vector<Point2D>;
        TVerticesList Vertices;

        [[nodiscard]] bool IsSymmetric(const Line2D& axisOfSymmetry);
    };
}

#endif
