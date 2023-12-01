#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
  std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs.type_)
{
  std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
  std::cout << "Dog copy assignment operator called." << std::endl;
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

Dog::~Dog()
{
  std::cout << "Dog destructor called." << std::endl;
}

void  Dog::make_sound() const
{
  std::cout << "Wuff wuff." << std::endl;
}
