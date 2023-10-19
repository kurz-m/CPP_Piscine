#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) : fixed_point_(fixed.fixed_point_)
{
  std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs) {
    fixed_point_ = rhs.get_raw_bits();
  }
  return *this;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

int Fixed::get_raw_bits() const
{
  std::cout << "get_raw_bits member function called" << std::endl;
  return fixed_point_;
}

void  Fixed::set_raw_bits(const int raw)
{
  std::cout << "set_raw_bits member function called" << std::endl;
  fixed_point_ = raw;
}
