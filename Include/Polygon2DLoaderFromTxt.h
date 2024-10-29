#ifndef POLYGON2DLOADERFROMTXT_H
#define POLYGON2DLOADERFROMTXT_H

#include <Polygon2DLoader.h>

namespace PolygonUtils {
    class Polygon2DLoaderFromTxt final : public Polygon2DLoader {
    public:
        Geometry::Polygon2D LoadPolygon(const std::string& path) override;
    };
}

#endif
