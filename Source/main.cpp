#include <iostream>
#include <Line2D.h>
#include <memory>
#include <PolygonAxesOfSymmetryFinder.h>
#include <Point2D.h>
#include <Polygon2DLoaderFromTxt.h>
#include <Polygon2D.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const std::unique_ptr<PolygonUtils::Polygon2DLoader> loader(new PolygonUtils::Polygon2DLoaderFromTxt);

    const auto polygon = loader->LoadPolygon(argv[1]);
    const auto axesOfSymmetry = PolygonUtils::PolygonAxesOfSymmetryFinder::FindAxesOfSymmetry(polygon);

    if (axesOfSymmetry.empty())
        std::cout << "non-symmetric\n";
    else
        for (const auto& axis : axesOfSymmetry)
            std::cout << axis.P1 << " - " << axis.P2 << '\n';

    return 0;
}
