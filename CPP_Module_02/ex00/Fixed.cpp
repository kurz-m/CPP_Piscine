#include "Fixed.hpp"

Fixed::Fixed() : raw_bits_(0)
{
  std::cout << "Default constructor called" << std::endl;
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
    raw_bits_ = rhs.get_raw_bits();
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
  return raw_bits_;
}

void  Fixed::set_raw_bits(const int raw)
{
  std::cout << "set_raw_bits member function called" << std::endl;
  raw_bits_ = raw;
}
