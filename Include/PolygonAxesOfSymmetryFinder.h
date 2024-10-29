#ifndef POLYGONAXESOFSYMMETRYFINDER_H
#define POLYGONAXESOFSYMMETRYFINDER_H

#include <vector>

namespace Geometry {
    class Polygon2D;
    class Line2D;
}

namespace PolygonUtils {
    class PolygonAxesOfSymmetryFinder {
    public:
        using TAxesOfSymmetryList = std::vector<Geometry::Line2D>;

        static TAxesOfSymmetryList FindAxesOfSymmetry(const Geometry::Polygon2D& polygon);

    private:
        explicit PolygonAxesOfSymmetryFinder(const Geometry::Polygon2D& polygon);

        void FindAxesOfSymmetryImpl();
        void GeneratePossibleAxesOfSymmetry();
        void GeneratePossibleAxesOfSymmetryForOddNumOfVerticesPolygon();
        void GeneratePossibleAxesOfSymmetryForEvenNumOfVerticesPolygon();
        void PushLineToList(const Geometry::Line2D& axisOfSymmetry);

        const Geometry::Polygon2D* m_polygon = nullptr;
        TAxesOfSymmetryList m_axesOfSymmetryList;
        TAxesOfSymmetryList m_possibleAxesOfSymmetry;
    };
}

#endif
