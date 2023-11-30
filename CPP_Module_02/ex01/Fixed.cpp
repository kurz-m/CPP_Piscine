#include "Fixed.hpp"

Fixed::Fixed() : fixed_format_(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : fixed_format_(i << fractal_bits_)
{
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
  : fixed_format_(roundf(f * static_cast<float>(1 << fractal_bits_)))
{
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) : fixed_format_(fixed.fixed_format_)
{
  std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs) {
    fixed_format_ = rhs.get_raw_bits();
  }
  return *this;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

int Fixed::get_raw_bits() const
{
  return fixed_format_;
}

void  Fixed::set_raw_bits(const int raw)
{
  fixed_format_ = raw;
}

float Fixed::to_float() const
{
  return static_cast<float>(fixed_format_) / static_cast<float>(1 << fractal_bits_);
}

int Fixed::to_int() const
{
  return fixed_format_ >> fractal_bits_;
}

std::ostream& operator<<(std::ostream& o, const Fixed& rhs)
{
  o << rhs.to_float();
  return o;
}
