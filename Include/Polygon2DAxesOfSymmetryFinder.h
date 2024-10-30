#ifndef POLYGONAXESOFSYMMETRYFINDER_H
#define POLYGONAXESOFSYMMETRYFINDER_H

#include <vector>

namespace Geometry {
    class Polygon2D;
    class Line2D;
}

namespace PolygonUtils {
    /**
    * @class Polygon2DAxesOfSymmetryFinder
    * @brief Implements the logic for finding all the symmetry axes of a polygon
    */
    class Polygon2DAxesOfSymmetryFinder {
    public:
        using TAxesOfSymmetryList = std::vector<Geometry::Line2D>;

        /**
        * @brief Finds all symmetry axes of a polygon
        * @param polygon Polygon for which you need to find the axes of symmetry
        * @return Polygon axis of symmetry list
        */
        static TAxesOfSymmetryList FindAxesOfSymmetry(const Geometry::Polygon2D& polygon);

    private:
        explicit Polygon2DAxesOfSymmetryFinder(const Geometry::Polygon2D& polygon);

        /**
        * @brief Finds all axes of symmetry for a m_polygon
        */
        void FindAxesOfSymmetryImpl();

        /**
        * @brief Generates possible symmetry axes for a m_polygon
        */
        void GeneratePossibleAxesOfSymmetry();

        /**
        * @brief Generates possible symmetry axes for a polygon with an odd number of vertices
        */
        void GeneratePossibleAxesOfSymmetryForOddNumOfVerticesPolygon();

        /**
        * @brief  Generates possible symmetry axes for a polygon with an even number of vertices
        */
        void GeneratePossibleAxesOfSymmetryForEvenNumOfVerticesPolygon();

        /**
        * @brief Adds the found symmetry axis to the list m_axesOfSymmetryList if it is not there yet
        */
        void PushLineToList(const Geometry::Line2D& axisOfSymmetry);

        const Geometry::Polygon2D* m_polygon = nullptr; /**< Polygon passed to the method FindAxesOfSymmetry */
        TAxesOfSymmetryList m_axesOfSymmetryList;       /**< All found axes of symmetry of the polygon */
        TAxesOfSymmetryList m_possibleAxesOfSymmetry;   /**< All possible axes of symmetry of a polygon */
    };
}

#endif
