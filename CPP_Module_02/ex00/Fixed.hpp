#ifndef CLASS_FIXED_HPP_
# define CLASS_FIXED_HPP_

#include <iostream>
#include <cstdlib>

class Fixed {
public:
  Fixed();
  Fixed(const Fixed&);
  Fixed& operator=(const Fixed&);
  ~Fixed();

  int get_raw_bits() const;
  void  set_raw_bits(const int raw);

private:
  int raw_bits_;
  static const int  fractal_bits_ = 8;
};

#endif
