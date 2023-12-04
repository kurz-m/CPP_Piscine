#ifndef CAT_HPP_
# define CAT_HPP_

#include <cstdlib>
#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "utils.hpp"

class Cat : public AAnimal {
public:
  Cat();
  Cat(const Cat&);
  Cat& operator=(const Cat&);
  ~Cat();

  virtual void  make_sound() const;
  void  create_idea(const std::string&);
  void  list_ideas() const;

private:
  Brain*  brain_;
};

#endif
