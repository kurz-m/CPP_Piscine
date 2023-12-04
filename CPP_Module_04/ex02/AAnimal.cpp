#include "AAnimal.hpp"

AAnimal::AAnimal() : type_("base")
{
  debug_print("AAnimal constructor called.", BLUE);
}

AAnimal::AAnimal(const std::string& type) : type_(type)
{
  debug_print("AAnimal string constructor called.", BLUE);
}

AAnimal::AAnimal(const AAnimal& rhs) : type_(rhs.type_)
{
  debug_print("AAnimal copy constructor called.", BLUE);
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
  debug_print("AAnimal copy assignment operator called.", BLUE);
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

AAnimal::~AAnimal()
{
  debug_print("AAnimal destructor called.", BLUE);
}

void  AAnimal::make_sound() const
{
  std::cout << "(arbitrary animal sound)" << std::endl;
}

std::string AAnimal::get_type() const
{
  return type_;
}
