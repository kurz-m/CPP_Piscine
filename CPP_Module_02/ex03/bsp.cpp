#include "Point.hpp"
#include "Vector.hpp"

static const  Fixed get_determinant(const Point a, const Point b, const Point p1)
{
  const Vector v1 = Vector::calculate_vector(a, b);
  return v1.calculate_determinant(Vector::calculate_vector(a, p1));
}

bool  bsp(Point const a, Point const b, Point const c, Point const p1)
{
  const Fixed d1 = get_determinant(a, b, p1);
  const Fixed d2 = get_determinant(b, c, p1);
  const Fixed d3 = get_determinant(c, a, p1);

  return (d1 >= 0 && d2 >= 0 && d3 >= 0) || (d1 <= 0 && d2 <= 0 && d3 <= 0);
}
