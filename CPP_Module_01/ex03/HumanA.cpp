#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon& weapon) 
  : name_(name), weapon_(weapon) {}

HumanA::~HumanA() {}

void    HumanA::attack() const
{
  std::cout << name_ << " attacks with their " << weapon_.get_type() << std::endl;
}
