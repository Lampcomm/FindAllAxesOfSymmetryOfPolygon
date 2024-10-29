#include <Polygon2DLoaderFromTxt.h>
#include <Polygon2D.h>
#include <fstream>
#include <sstream>

namespace PolygonUtils {
    Geometry::Polygon2D Polygon2DLoaderFromTxt::LoadPolygon(const std::string &path) {
        std::ifstream input(path);
        if (!input.is_open())
            throw std::invalid_argument("Could not open file at path " + path);

        Geometry::Polygon2D polygon;
        auto& vertices = polygon.Vertices;

        std::string line;
        while (std::getline(input, line)) {
            if (line.empty())
                continue;

            std::stringstream ss(line);
            Geometry::Point2D vertex{};
            ss >> vertex;

            vertices.emplace_back(vertex);
        }

        return polygon;
    }

}