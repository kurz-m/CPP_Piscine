#ifndef CLASS_FIXED_HPP_
# define CLASS_FIXED_HPP_

#include <iostream>
#include <cmath>
#include <cstdlib>

class Fixed {
public:
  Fixed();
  Fixed(const int32_t);
  Fixed(const float);
  Fixed(const Fixed&);
  ~Fixed();

  int32_t get_raw_bits() const;
  void  set_raw_bits(const int32_t raw);
  float to_float() const;
  int32_t to_int() const;
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
  Fixed&  operator++();
  Fixed  operator++(int);
  Fixed&  operator--();
  Fixed  operator--(int);

private:
  static Fixed from_raw_bits_(int32_t bits);

  int32_t fixed_format_;
  static const int32_t  fractal_bits_ = 8;
};

std::ostream& operator<<(std::ostream&, const Fixed& rhs);

#endif
