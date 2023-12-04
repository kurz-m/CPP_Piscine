#ifndef DOG_HPP_
# define DOG_HPP_

#include <cstdlib>
#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "utils.hpp"

class Dog : public AAnimal {
public:
  Dog();
  Dog(const Dog&);
  Dog& operator=(const Dog&);
  ~Dog();

  virtual void  make_sound() const;
  void  create_idea(const std::string&);
  void  list_ideas() const;
  void  print_addr() const;

private:
  Brain*  brain_;
};

#endif
