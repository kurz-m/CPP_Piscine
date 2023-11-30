#include "Fixed.hpp"

Fixed::Fixed() : fixed_format_(0)
{
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int32_t i) : fixed_format_(i << fractal_bits_)
{
  // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
  : fixed_format_(roundf(f * static_cast<float>(1 << fractal_bits_)))
{
  // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) : fixed_format_(fixed.fixed_format_)
{
  // std::cout << "Copy constructor called" << std::endl;
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
  // std::cout << "Destructor called" << std::endl;
}

int32_t Fixed::get_raw_bits() const
{
  return fixed_format_;
}

void  Fixed::set_raw_bits(const int32_t raw)
{
  fixed_format_ = raw;
}

float Fixed::to_float() const
{
  return static_cast<float>(fixed_format_) / static_cast<float>(1 << fractal_bits_);
}

int32_t Fixed::to_int() const
{
  return fixed_format_ >> fractal_bits_;
}

bool Fixed::operator>(const Fixed& rhs) const
{
  return fixed_format_ > rhs.get_raw_bits();
}

bool Fixed::operator<(const Fixed& rhs) const
{
  return fixed_format_ < rhs.get_raw_bits();
}

bool Fixed::operator>=(const Fixed& rhs) const
{
  return fixed_format_ >= rhs.get_raw_bits();
}

bool Fixed::operator<=(const Fixed& rhs) const
{
  return fixed_format_ <= rhs.get_raw_bits();
}

bool Fixed::operator==(const Fixed& rhs) const
{
  return fixed_format_ == rhs.get_raw_bits();
}

bool Fixed::operator!=(const Fixed& rhs) const
{
  return fixed_format_ != rhs.get_raw_bits();
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
  return Fixed::from_raw_bits(fixed_format_ + rhs.get_raw_bits());
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
  return Fixed::from_raw_bits(fixed_format_ - rhs.get_raw_bits());
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
  int64_t raw = static_cast<int64_t>(fixed_format_)
              * static_cast<int64_t>(rhs.get_raw_bits());
  return Fixed::from_raw_bits(static_cast<int32_t>(raw >> fractal_bits_));
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
  int64_t raw = (static_cast<int64_t>(fixed_format_) << fractal_bits_)
              / static_cast<int64_t>(rhs.get_raw_bits());
  return Fixed::from_raw_bits(raw);
}

Fixed&  Fixed::operator++()
{
  ++fixed_format_;
  return *this;
}

Fixed  Fixed::operator++(int)
{
  Fixed tmp(*this);
  ++fixed_format_;
  return tmp;
}

Fixed&  Fixed::operator--()
{
  --fixed_format_;
  return *this;
}

Fixed  Fixed::operator--(int)
{
  Fixed tmp(*this);
  --fixed_format_;
  return tmp;
}

Fixed&  Fixed::min(Fixed& lhs, Fixed& rhs)
{
  return lhs < rhs ? lhs : rhs;
}

const Fixed&  Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
  return lhs < rhs ? lhs : rhs;
}

Fixed&  Fixed::max(Fixed& lhs, Fixed& rhs)
{
  return lhs > rhs ? lhs : rhs;
}

const Fixed&  Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
  return lhs > rhs ? lhs : rhs;
}

Fixed Fixed::from_raw_bits(int32_t raw)
{
  Fixed pre;
  pre.fixed_format_ = raw;
  return pre;
}

std::ostream& operator<<(std::ostream& o, const Fixed& rhs)
{
  o << rhs.to_float();
  return o;
}
