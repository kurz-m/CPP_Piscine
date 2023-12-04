#include "Dog.hpp"

Dog::Dog() : Animal("dog"), brain_(new Brain())
{
  debug_print("Dog constructor called.", CYAN);
}

Dog::Dog(const Dog& rhs) : Animal(rhs.type_)
{
  debug_print("Dog copy constructor called.", CYAN);
  brain_ = new Brain(*(rhs.brain_));
}

Dog& Dog::operator=(const Dog& rhs)
{
  debug_print("Dog copy assignment operator called.", CYAN);
  if (this != &rhs) {
    *brain_ = *(rhs.brain_);
    type_ = rhs.type_;
  }
  return *this;
}

Dog::~Dog()
{
  delete brain_;
  debug_print("Dog destructor called.", CYAN);
}

void  Dog::make_sound() const
{
  std::cout << "Wuff wuff." << std::endl;
}

void  Dog::create_idea(const std::string& idea)
{
  brain_->create_idea(idea);
}

void  Dog::list_ideas() const
{
  brain_->list_ideas();
}
