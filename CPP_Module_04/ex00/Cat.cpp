#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
  std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs.type_)
{
  std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
  std::cout << "Cat copy assignment operator called." << std::endl;
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

Cat::~Cat()
{
  std::cout << "Cat destructor called." << std::endl;
}

void  Cat::make_sound() const
{
  std::cout << "Miau miau." << std::endl;
}
