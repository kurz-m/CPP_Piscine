#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("wrong_cat")
{
  std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs.type_)
{
  std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
  std::cout << "WrongCat copy assignment operator called." << std::endl;
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

WrongCat::~WrongCat()
{
  std::cout << "WrongCat destructor called." << std::endl;
}

void  WrongCat::make_sound() const
{
  std::cout << "Miau miau." << std::endl;
}
