#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include "Weapon.hpp"
#include <iostream>

class HumanA {
public:
  HumanA(std::string name, const Weapon& weapon);
  ~HumanA();

  void  attack() const;

private:
  const std::string name_;
  const Weapon& weapon_;
};

#endif
