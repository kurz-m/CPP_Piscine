#include "Vector.hpp"

Vector::Vector() : x_(0), y_(0) {}

Vector::Vector(const Fixed x, const Fixed y) : x_(x), y_(y) {}

Vector::Vector(const Vector& rhs) : x_(rhs.x_), y_(rhs.y_) {}

Vector::~Vector() {}

const Fixed Vector::calculate_determinant(const Vector& rhs) const
{
  return (x_ * rhs.y_) - (y_ * rhs.x_);
}

const Vector  Vector::calculate_vector(const Point& p1, const Point& p2)
{
  const Fixed diff_x = p2.get_x() - p1.get_x();
  const Fixed diff_y = p2.get_y() - p1.get_y();
  return Vector(diff_x, diff_y);
}
