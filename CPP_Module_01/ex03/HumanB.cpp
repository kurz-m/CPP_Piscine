#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}

HumanB::~HumanB() {}

void    HumanB::attack() const
{
  std::cout << name_ << " attacks with their " << weapon_->get_type() << std::endl;
}

void    HumanB::set_weapon(const Weapon& weapon)
{
  weapon_ = &weapon;
}
