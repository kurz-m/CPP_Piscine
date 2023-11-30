#ifndef CLASS_FIXED_HPP_
# define CLASS_FIXED_HPP_

#include <iostream>
#include <cmath>
#include <cstdlib>

class Fixed {
public:
  Fixed();
  Fixed(const int);
  Fixed(const float);
  Fixed(const Fixed&);
  Fixed& operator=(const Fixed&);
  ~Fixed();

  int get_raw_bits() const;
  void  set_raw_bits(const int raw);
  float to_float() const;
  int to_int() const;

private:
  int fixed_format_;
  static const int  fractal_bits_ = 8;
};

std::ostream& operator<<(std::ostream&, const Fixed& rhs);

#endif
