#include "Animal.hpp"

Animal::Animal() : type_("base")
{
  debug_print("Animal constructor called.", BLUE);
}

Animal::Animal(const std::string& type) : type_(type)
{
  debug_print("Animal string constructor called.", BLUE);
}

Animal::Animal(const Animal& rhs) : type_(rhs.type_)
{
  debug_print("Animal copy constructor called.", BLUE);
}

Animal& Animal::operator=(const Animal& rhs)
{
  debug_print("Animal copy assignment operator called.", BLUE);
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

Animal::~Animal()
{
  debug_print("Animal destructor called.", BLUE);
}

void  Animal::make_sound() const
{
  std::cout << "(arbitrary animal sound)" << std::endl;
}

std::string Animal::get_type() const
{
  return type_;
}
