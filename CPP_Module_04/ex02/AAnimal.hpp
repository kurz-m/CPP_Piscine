#ifndef AANIMAL_HPP_
# define AANIMAL_HPP_

#include <cstdlib>
#include <iostream>

#include "utils.hpp"

class AAnimal {
public:
  AAnimal();
  AAnimal(const std::string&);
  AAnimal(const AAnimal&);
  AAnimal& operator=(const AAnimal&);
  virtual ~AAnimal();

  virtual void  make_sound() const = 0;
  std::string get_type() const;


protected:
  std::string type_;
};

#endif
