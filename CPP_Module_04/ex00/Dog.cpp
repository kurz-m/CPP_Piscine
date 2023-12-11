#include "Dog.hpp"
#include "utils.hpp"

Dog::Dog() : Animal("dog")
{
  debug_print("Dog constructor called.", CYAN);
}

Dog::Dog(const Dog& rhs) : Animal(rhs.type_)
{
  debug_print("Dog copy constructor called.", CYAN);
}

Dog& Dog::operator=(const Dog& rhs)
{
  debug_print("Dog copy assignment operator called.", CYAN);
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

Dog::~Dog()
{
  debug_print("Dog destructor called.", RED);
}

void  Dog::make_sound() const
{
  debug_print("Wuff wuff.", GREEN);
}
