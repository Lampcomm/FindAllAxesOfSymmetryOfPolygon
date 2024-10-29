#include <PolygonAxesOfSymmetryFinder.h>
#include <Line2D.h>
#include <Polygon2D.h>
#include <algorithm>
#include <memory>

namespace {
    using TVerticesListSize = Geometry::Polygon2D::TVertexIndex;
}

namespace PolygonUtils {
    PolygonAxesOfSymmetryFinder::TAxesOfSymmetryList
    PolygonAxesOfSymmetryFinder::FindAxesOfSymmetry(const Geometry::Polygon2D &polygon) {
        std::unique_ptr<PolygonAxesOfSymmetryFinder> finder(new PolygonAxesOfSymmetryFinder(polygon));
        finder->FindAxesOfSymmetryImpl();

        return finder->m_axesOfSymmetryList;
    }

    PolygonAxesOfSymmetryFinder::PolygonAxesOfSymmetryFinder(const Geometry::Polygon2D &polygon)
        : m_polygon(&polygon)
    {
    }

    void PolygonAxesOfSymmetryFinder::FindAxesOfSymmetryImpl() {
        GeneratePossibleAxesOfSymmetry();
        for (const auto& possibleAxisOfSymmetry : m_possibleAxesOfSymmetry)
            if (m_polygon->IsSymmetric(possibleAxisOfSymmetry))
                PushLineToList(possibleAxisOfSymmetry);
    }

    void PolygonAxesOfSymmetryFinder::GeneratePossibleAxesOfSymmetry() {
        return  m_polygon->Vertices.size() % 2 == 0 ?
                GeneratePossibleAxesOfSymmetryForEvenNumOfVerticesPolygon() :
                GeneratePossibleAxesOfSymmetryForOddNumOfVerticesPolygon();
    }

    void PolygonAxesOfSymmetryFinder::GeneratePossibleAxesOfSymmetryForEvenNumOfVerticesPolygon() {
        const auto& vertices = m_polygon->Vertices;
        for (TVerticesListSize i = 0; i < vertices.size(); ++i) {
            const auto oppositeVertexIndex = m_polygon->GetOppositeVertexIndex(i);
            m_possibleAxesOfSymmetry.emplace_back(vertices[i], vertices[oppositeVertexIndex]);

            const auto edge = m_polygon->GetEdge(i);
            const auto oppositeEdge = m_polygon->GetEdge(oppositeVertexIndex);
            m_possibleAxesOfSymmetry.emplace_back(edge.GetMidPoint(), oppositeEdge.GetMidPoint());
        }
    }

    void PolygonAxesOfSymmetryFinder::GeneratePossibleAxesOfSymmetryForOddNumOfVerticesPolygon() {
        const auto& vertices = m_polygon->Vertices;
        for (TVerticesListSize i = 0; i < vertices.size(); ++i) {
            const auto oppositeVertexIndex = m_polygon->GetOppositeVertexIndex(i);
            const auto oppositeEdge = m_polygon->GetEdge(oppositeVertexIndex);

            m_possibleAxesOfSymmetry.emplace_back(vertices[i], oppositeEdge.GetMidPoint());
        }
    }

    void PolygonAxesOfSymmetryFinder::PushLineToList(const Geometry::Line2D &axisOfSymmetry) {
        const auto it = std::ranges::find(m_axesOfSymmetryList, axisOfSymmetry);
        if (it == m_axesOfSymmetryList.end())
            m_axesOfSymmetryList.emplace_back(axisOfSymmetry);
    }
}