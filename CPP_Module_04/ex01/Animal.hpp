#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

#include <cstdlib>
#include <iostream>

class Animal {
public:
  Animal();
  Animal(const std::string&);
  Animal(const Animal&);
  Animal& operator=(const Animal&);
  virtual ~Animal();

  virtual void  make_sound() const;
  std::string get_type() const;


protected:
  std::string type_;
};

#endif
