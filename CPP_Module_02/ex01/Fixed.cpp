#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : fixed_point_(i << fractal_bits_)
{
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : fixed_point_(roundf(f * (1 << fractal_bits_)))
{
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
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
  return fixed_point_;
}

void  Fixed::set_raw_bits(const int raw)
{
  fixed_point_ = raw;
}

float Fixed::to_float() const
{
  return (float)fixed_point_ / (float)(1 << fractal_bits_);
}

int Fixed::to_int() const
{
  return fixed_point_ >> fractal_bits_;
}

std::ostream& operator<<(std::ostream& o, const Fixed& rhs)
{
  o << rhs.to_float();
  return o;
}
