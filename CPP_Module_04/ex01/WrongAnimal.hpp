#ifndef WRONGANIMAL_HPP_
# define WRONGANIMAL_HPP_

#include <cstdlib>
#include <iostream>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const std::string&);
  WrongAnimal(const WrongAnimal&);
  WrongAnimal& operator=(const WrongAnimal&);
  ~WrongAnimal();

  void  make_sound() const;
  std::string get_type() const;


protected:
  std::string type_;
};

#endif
