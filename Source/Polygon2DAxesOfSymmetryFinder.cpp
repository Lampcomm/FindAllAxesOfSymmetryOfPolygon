#include <Polygon2DAxesOfSymmetryFinder.h>
#include <Line2D.h>
#include <Polygon2D.h>
#include <algorithm>

namespace {
    using TVerticesListSize = Geometry::Polygon2D::TVertexIndex;
}

namespace PolygonUtils {
    Polygon2DAxesOfSymmetryFinder::TAxesOfSymmetryList
    Polygon2DAxesOfSymmetryFinder::FindAxesOfSymmetry(const Geometry::Polygon2D &polygon) {
        Polygon2DAxesOfSymmetryFinder finder(polygon);
        finder.FindAxesOfSymmetryImpl();

        return finder.m_axesOfSymmetryList;
    }

    Polygon2DAxesOfSymmetryFinder::Polygon2DAxesOfSymmetryFinder(const Geometry::Polygon2D &polygon)
        : m_polygon(&polygon)
    {
    }

    void Polygon2DAxesOfSymmetryFinder::FindAxesOfSymmetryImpl() {
        GeneratePossibleAxesOfSymmetry();
        for (const auto& possibleAxisOfSymmetry : m_possibleAxesOfSymmetry)
            if (m_polygon->IsSymmetric(possibleAxisOfSymmetry))
                PushLineToList(possibleAxisOfSymmetry);
    }

    void Polygon2DAxesOfSymmetryFinder::GeneratePossibleAxesOfSymmetry() {
        if (m_polygon->Vertices.size() % 2 == 0)
            GeneratePossibleAxesOfSymmetryForEvenNumOfVerticesPolygon();
        else
            GeneratePossibleAxesOfSymmetryForOddNumOfVerticesPolygon();
    }

    void Polygon2DAxesOfSymmetryFinder::GeneratePossibleAxesOfSymmetryForEvenNumOfVerticesPolygon() {
        const auto& vertices = m_polygon->Vertices;
        for (TVerticesListSize i = 0; i < vertices.size(); ++i) {
            const auto oppositeVertexIndex = m_polygon->GetOppositeVertexIndex(i);
            m_possibleAxesOfSymmetry.emplace_back(vertices[i], vertices[oppositeVertexIndex]);

            const auto edge = m_polygon->GetEdge(i);
            const auto oppositeEdge = m_polygon->GetEdge(oppositeVertexIndex);
            m_possibleAxesOfSymmetry.emplace_back(edge.GetMidPoint(), oppositeEdge.GetMidPoint());
        }
    }

    void Polygon2DAxesOfSymmetryFinder::GeneratePossibleAxesOfSymmetryForOddNumOfVerticesPolygon() {
        const auto& vertices = m_polygon->Vertices;
        for (TVerticesListSize i = 0; i < vertices.size(); ++i) {
            const auto oppositeVertexIndex = m_polygon->GetOppositeVertexIndex(i);
            const auto oppositeEdge = m_polygon->GetEdge(oppositeVertexIndex);

            m_possibleAxesOfSymmetry.emplace_back(vertices[i], oppositeEdge.GetMidPoint());
        }
    }

    void Polygon2DAxesOfSymmetryFinder::PushLineToList(const Geometry::Line2D &axisOfSymmetry) {
        const auto it = std::ranges::find(m_axesOfSymmetryList, axisOfSymmetry);
        if (it == m_axesOfSymmetryList.end())
            m_axesOfSymmetryList.emplace_back(axisOfSymmetry);
    }
}