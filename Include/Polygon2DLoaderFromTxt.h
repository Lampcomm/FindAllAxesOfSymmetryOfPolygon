#ifndef POLYGON2DLOADERFROMTXT_H
#define POLYGON2DLOADERFROMTXT_H

#include <Polygon2DLoader.h>

namespace PolygonUtils {
    /**
    * @class Polygon2DLoaderFromTxt
    * @brief 2D polygon loader from text file
    */
    class Polygon2DLoaderFromTxt final : public Polygon2DLoader {
    public:
        /**
        * @brief Loads 2D polygon from the specified text file
        * @param path Path to file with polygon vertices
        * @return Loaded polygon
        */
        Geometry::Polygon2D LoadPolygon(const std::string& path) override;
    };
}

#endif
