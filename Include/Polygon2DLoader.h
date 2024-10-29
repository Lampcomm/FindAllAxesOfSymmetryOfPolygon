#ifndef POLYGONLOADER_H
#define POLYGONLOADER_H

#include <string>

namespace Geometry {
    class Polygon2D;
}

namespace PolygonUtils {
    class Polygon2DLoader {
    public:
        virtual Geometry::Polygon2D LoadPolygon(const std::string& path) = 0;
        virtual ~Polygon2DLoader() = default;
    };
}

#endif
