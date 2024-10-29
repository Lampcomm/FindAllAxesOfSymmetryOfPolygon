#include <Polygon2D.h>
#include <algorithm>

namespace Geometry {
    bool Polygon2D::IsSymmetric(const Line2D& axisOfSymmetry) {
        return std::ranges::all_of(Vertices, [this, &axisOfSymmetry](const auto& vertex) {
            const auto reflectedPoint = axisOfSymmetry.ReflectPoint(vertex);
            const auto it = std::ranges::find(Vertices, reflectedPoint);
            return it != Vertices.cend();
        });
    }
}