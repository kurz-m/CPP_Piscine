#include "Animal.hpp"

Animal::Animal() : type_("base")
{
  std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const std::string& type) : type_(type)
{
  std::cout << "Animal string constructor called." << std::endl;
}

Animal::Animal(const Animal& rhs) : type_(rhs.type_)
{
  std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
  std::cout << "Animal copy assignment operator called." << std::endl;
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

Animal::~Animal()
{
  std::cout << "Animal destructor called." << std::endl;
}

void  Animal::make_sound() const
{
  std::cout << "What sound makes an arbitrary animal?" << std::endl;
}

std::string Animal::get_type() const
{
  return type_;
}
