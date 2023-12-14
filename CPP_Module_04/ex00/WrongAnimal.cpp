#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("wrong_base")
{
  std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type_(type)
{
  std::cout << "WrongAnimal string constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) : type_(rhs.type_)
{
  std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
  std::cout << "WrongAnimal copy assignment operator called." << std::endl;
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

WrongAnimal::~WrongAnimal()
{
  std::cout << "WrongAnimal destructor called." << std::endl;
}

void  WrongAnimal::make_sound() const
{
  std::cout << "(arbitrary wrong animal sound)" << std::endl;
}

std::string WrongAnimal::get_type() const
{
  return type_;
}
