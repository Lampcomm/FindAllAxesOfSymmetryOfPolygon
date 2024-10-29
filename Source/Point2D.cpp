#include <Point2D.h>
#include <GlobalConstants.h>
#include <valarray>

namespace Geometry {
    bool Point2D::operator==(const Point2D& rhs) const {
        return  std::abs(x - rhs.x) < GlobalConstants::Epsilon &&
                std::abs(y - rhs.y) < GlobalConstants::Epsilon;
    }

    std::ostream& operator<<(std::ostream& os, const Point2D& rhs) {
        os << rhs.x << " " << rhs.y;
        return os;
    }
}
