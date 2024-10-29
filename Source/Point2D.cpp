#include <Point2D.h>
#include <GlobalConstants.h>
#include <valarray>

namespace Geometry {
    bool Point2D::operator==(const Point2D& rhs) const {
        return  std::abs(X - rhs.X) < GlobalConstants::Epsilon &&
                std::abs(Y - rhs.Y) < GlobalConstants::Epsilon;
    }

    std::ostream& operator<<(std::ostream& os, const Point2D& rhs) {
        os << rhs.X << " " << rhs.Y;
        return os;
    }
}
