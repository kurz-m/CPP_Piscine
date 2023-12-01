#ifndef CAT_HPP_
# define CAT_HPP_

#include <cstdlib>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat&);
  Cat& operator=(const Cat&);
  ~Cat();

  virtual void  make_sound() const;
};

#endif
