#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(Fixed(x)), y_(Fixed(y)) {}

Point::Point(const Fixed x, const Fixed y) : x_(x), y_(y) {}

Point::Point(const Point& rhs) : x_(rhs.x_), y_(rhs.y_) {}

Point::~Point() {}

Point&  Point::operator=(const Point& rhs)
{
  if (this != &rhs) {
    *const_cast<Fixed*>(&x_) = rhs.x_;
    *const_cast<Fixed*>(&y_) = rhs.y_;
  }
  return *this;
}

Fixed Point::get_x() const
{
  return x_;
}

Fixed Point::get_y() const
{
  return y_;
}
