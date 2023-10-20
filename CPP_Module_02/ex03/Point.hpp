#ifndef CLASS_POINT_HPP_
# define CLASS_POINT_HPP_

#include "Fixed.hpp"

class Point {
public:
  Point();
  Point(const float, const float);
  Point(const Fixed, const Fixed);
  Point(const Point&);
  Point& operator=(const Point&);
  ~Point();

  Fixed get_x() const;
  Fixed get_y() const;

private:
  const Fixed x_;
  const Fixed y_;
};

bool  bsp(Point const a, Point const b, Point const c, Point const point);

#endif
