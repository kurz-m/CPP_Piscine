#ifndef HUMANB_HPP_
#define HUMANB_HPP_

#include "Weapon.hpp"
#include <iostream>

class HumanB {
public:
  HumanB(std::string name);
  ~HumanB();

  void  attack();
  void  set_weapon(const Weapon& weapon);

private:
  std::string   name_;
  const Weapon* weapon_;
};

#endif
