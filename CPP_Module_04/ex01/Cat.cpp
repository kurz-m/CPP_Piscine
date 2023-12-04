#include "Cat.hpp"

Cat::Cat() : Animal("cat"), brain_(new Brain())
{
  debug_print("Cat constructor called.", MAGENTA);
}

Cat::Cat(const Cat& rhs) : Animal(rhs.type_)
{
  brain_ = new Brain(*(rhs.brain_));
  debug_print("Cat copy constructor called.", MAGENTA);
}

Cat& Cat::operator=(const Cat& rhs)
{
  debug_print("Cat copy assignment operator called.", MAGENTA);
  if (this != &rhs) {
    *brain_ = *(rhs.brain_);
    type_ = rhs.type_;
  }
  return *this;
}

Cat::~Cat()
{
  delete brain_;
  debug_print("Cat destructor called.", MAGENTA);
}

void  Cat::make_sound() const
{
  std::cout << "Miau miau." << std::endl;
}

void  Cat::create_idea(const std::string& idea)
{
  brain_->create_idea(idea);
}

void  Cat::list_ideas() const
{
  brain_->list_ideas();
}
