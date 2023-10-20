#include "Fixed.hpp"
#include "Vector.hpp"
#include "Point.hpp"
#include <iostream>

int main() {
  // a-c points for the triangle
  const Point a(Fixed(4), Fixed(1));
  const Point b(Fixed(10), Fixed(4));
  const Point c(Fixed(6), Fixed(13));

  // p1-p3 points to check for
  const Point p1(2.4f, 3.7f);
  const Point p2(1.2f, 0.4f);
  const Point p3(5.1f, 5.3f);

  if (bsp(a, b, c, p1) == true) {
    std::cout << "p1 is inside the triangle" << std::endl;
  }
  else {
    std::cout << "p1 is outside the triangle" << std::endl;
  }

  if (bsp(a, b, c, p2) == true) {
    std::cout << "p2 is inside the triangle" << std::endl;
  }
  else {
    std::cout << "p2 is outside the triangle" << std::endl;
  }

  if (bsp(a, b, c, p3) == true) {
    std::cout << "p3 is inside the triangle" << std::endl;
  }
  else {
    std::cout << "p3 is outside the triangle" << std::endl;
  }

  return EXIT_SUCCESS;
}
