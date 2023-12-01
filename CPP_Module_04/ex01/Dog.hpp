#ifndef DOG_HPP_
# define DOG_HPP_

#include <cstdlib>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog&);
  Dog& operator=(const Dog&);
  ~Dog();

  virtual void  make_sound() const;
};

#endif
