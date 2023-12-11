#include "Cat.hpp"
#include "utils.hpp"

Cat::Cat() : Animal("cat")
{
  debug_print("Cat constructor called.", MAGENTA);
}

Cat::Cat(const Cat& rhs) : Animal(rhs.type_)
{
  debug_print("Cat copy constructor called.", MAGENTA);
}

Cat& Cat::operator=(const Cat& rhs)
{
  debug_print("Cat copy assignment operator called.", MAGENTA);
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

Cat::~Cat()
{
  debug_print("Cat destructor called.", RED);
}

void  Cat::make_sound() const
{
  debug_print("Miau miau.", GREEN);
}
