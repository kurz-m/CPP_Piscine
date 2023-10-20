#ifndef CLASS_VECTOR_HPP_
# define CLASS_VECTOR_HPP_

#include "Point.hpp"
#include "Fixed.hpp"

class Vector {
public:
  Vector();
  Vector(const Fixed, const Fixed);
  Vector(const Vector&);
  ~Vector();

  const Fixed calculate_determinant(const Vector&) const;
  static const  Vector  calculate_vector(const Point&, const Point&);

private:
  const Fixed x_;
  const Fixed y_;
};

#endif
