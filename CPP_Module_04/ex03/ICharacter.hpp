#ifndef ICHARACTER_HPP_
# define ICHARACTER_HPP_

#include <string>
#include "AMateria.hpp"

class ICharacter {
public:
  virtual ~ICharacter() {}
  virtual const std::string& get_name() const = 0;
  virtual void  equip(AMateria* m) = 0;
  virtual void  unequip(int idx) = 0;
  virtual void  use(int idx, ICharacter& target) = 0;
};

#endif
