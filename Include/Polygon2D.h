#ifndef POLYGON2D_H
#define POLYGON2D_H

#include <vector>
#include <Point2D.h>

namespace Geometry {
    class Line2D;

    /**
    * @class Polygon2D
    * @brief Represents polygon in 2D space
    */
    class Polygon2D {
    public:
        using TVerticesList = std::vector<Point2D>;
        using TVertexIndex = TVerticesList::size_type;

        TVerticesList Vertices; /**< List of polygon vertices */

        /**
        * @brief Checks if a polygon is symmetrical about a line
        * @param axisOfSymmetry Сhecked axis of symmetry
        * @return True if the polygon is symmetrical about the given axis. False otherwise
        */
        [[nodiscard]] bool IsSymmetric(const Line2D& axisOfSymmetry) const;

        /**
        * @brief Calculates the index of vertex opposite to the given one
        * @param vertexIndex Index of the vertex for which the opposite must be calculated
        * @return Index of vertex opposite 
        */
        [[nodiscard]] TVertexIndex GetOppositeVertexIndex(TVertexIndex vertexIndex) const;

        /**
        * @brief Returns the edge of a polygon
        * @param edgeIndex Polygon edge index
        * @return Polygon edge
        */
        [[nodiscard]] Line2D GetEdge(TVertexIndex edgeIndex) const;
    };
}

#endif
