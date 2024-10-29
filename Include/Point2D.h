#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

namespace Geometry {
     class Point2D {
     public:
          double x;
          double y;

          bool operator==(const Point2D &p) const;
          friend std::ostream& operator<<(std::ostream& os, const Point2D &p);
     };
}

#endif
