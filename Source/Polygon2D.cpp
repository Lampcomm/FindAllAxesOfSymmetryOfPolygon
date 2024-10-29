#include <Polygon2D.h>
#include <Line2D.h>
#include <algorithm>
#include <stdexcept>

namespace Geometry {
    bool Polygon2D::IsSymmetric(const Line2D& axisOfSymmetry) const {
        return std::ranges::all_of(Vertices, [this, &axisOfSymmetry](const auto& vertex) {
            const auto reflectedPoint = axisOfSymmetry.ReflectPoint(vertex);
            const auto it = std::ranges::find(Vertices, reflectedPoint);
            return it != Vertices.cend();
        });
    }

    Polygon2D::TVertexIndex Polygon2D::GetOppositeVertexIndex(TVertexIndex vertexIndex) const {
        return (vertexIndex + Vertices.size() / 2) % Vertices.size();
    }

    Line2D Polygon2D::GetEdge(TVertexIndex edgeIndex) const {
        if (edgeIndex > Vertices.size() - 1)
            throw std::out_of_range("Edge index out of range");

        Line2D edge{};
        edge.P1 = Vertices[edgeIndex];
        edge.P2 = Vertices[(edgeIndex + 1) % Vertices.size()];
        return edge;
    }

}