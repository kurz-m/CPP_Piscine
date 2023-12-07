#include "Fixed.hpp"
#include "utils.hpp"

Fixed::Fixed() : fixed_format_(0)
{
  debug_print("Default constructor called", CYAN);
}

Fixed::Fixed(const Fixed& fixed) : fixed_format_(fixed.fixed_format_)
{
  debug_print("Copy constructor called", CYAN);
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
  debug_print("Copy assignment operator called", CYAN);
  if (this != &rhs) {
    fixed_format_ = rhs.get_raw_bits();
  }
  return *this;
}

Fixed::~Fixed()
{
  debug_print("Destructor called", RED);
}

int Fixed::get_raw_bits() const
{
  debug_print("get_raw_bits member function called", GREEN);
  return fixed_format_;
}

void  Fixed::set_raw_bits(const int raw)
{
  debug_print("set_raw_bits member function called", GREEN);
  fixed_format_ = raw;
}
