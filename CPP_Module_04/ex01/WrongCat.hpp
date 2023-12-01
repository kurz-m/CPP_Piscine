#ifndef WRONGCAT_HPP_
# define WRONGCAT_HPP_

#include <cstdlib>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat&);
  WrongCat& operator=(const WrongCat&);
  ~WrongCat();

  void  make_sound() const;
};

#endif
