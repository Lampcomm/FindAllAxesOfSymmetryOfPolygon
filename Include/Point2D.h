#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <istream>

namespace Geometry {
     class Point2D {
     public:
          double X;
          double Y;

          bool operator==(const Point2D &p) const;
          friend std::ostream& operator<<(std::ostream& os, const Point2D &p);
          friend std::istream& operator>>(std::istream& is, Point2D &p);
     };
}

#endif
