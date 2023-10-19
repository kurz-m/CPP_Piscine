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
  ~Fixed();

  int get_raw_bits() const;
  void  set_raw_bits(const int raw);
  float to_float() const;
  int to_int() const;
  static Fixed& min(Fixed& lhs, Fixed& rhs);
  static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
  static Fixed& max(Fixed& lhs, Fixed& rhs);
  static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

  Fixed& operator=(const Fixed&);
  bool  operator>(const Fixed&) const;
  bool  operator<(const Fixed&) const;
  bool  operator>=(const Fixed&) const;
  bool  operator<=(const Fixed&) const;
  bool  operator==(const Fixed&) const;
  bool  operator!=(const Fixed&) const;
  Fixed operator+(const Fixed&) const;
  Fixed operator-(const Fixed&) const;
  Fixed operator*(const Fixed&) const;
  Fixed operator/(const Fixed&) const;


private:
  int fixed_point_;
  static const int  fractal_bits_ = 8;
};

std::ostream& operator<<(std::ostream&, const Fixed& rhs);

#endif
