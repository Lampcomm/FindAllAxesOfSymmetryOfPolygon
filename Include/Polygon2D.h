#ifndef POLYGON2D_H
#define POLYGON2D_H

#include <vector>
#include <Point2D.h>

namespace Geometry {
    class Line2D;

    class Polygon2D {
    public:
        using TVerticesList = std::vector<Point2D>;
        using TVertexIndex = TVerticesList::size_type;

        TVerticesList Vertices;

        [[nodiscard]] bool IsSymmetric(const Line2D& axisOfSymmetry) const;
        [[nodiscard]] TVertexIndex GetOppositeVertexIndex(TVertexIndex vertexIndex) const;
        [[nodiscard]] Line2D GetEdge(TVertexIndex edgeIndex) const;
    };
}

#endif
