#ifndef POLYGONLOADER_H
#define POLYGONLOADER_H

#include <string>

namespace Geometry {
    class Polygon2D;
}

namespace PolygonUtils {
    /**
    * @class Polygon2DLoader
    * @brief Interface of the 2D polygon loader from a file
    */
    class Polygon2DLoader {
    public:
        /**
        * @brief Loads 2D polygon from the specified file
        * @param path Path to file with polygon vertices
        * @return Loaded polygon
        */
        virtual Geometry::Polygon2D LoadPolygon(const std::string& path) = 0;

        virtual ~Polygon2DLoader() = default;
    };
}

#endif
