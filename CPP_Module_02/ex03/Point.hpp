#ifndef CLASS_POINT_HPP_
# define CLASS_POINT_HPP_

#include "Fixed.hpp"

class Point {
public:
  Point();
  Point(const float, const float);
  Point(const Point&);
  Point& operator=(const Point&);
  ~Point();

private:
  const Fixed x_;
  const Fixed y_;
};

#endif
