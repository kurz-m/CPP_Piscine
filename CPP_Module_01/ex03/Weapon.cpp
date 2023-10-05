#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type) : type_(type) {}

Weapon::~Weapon(void) {}

const std::string&    Weapon::get_type() const
{
  return type_;
}

void    Weapon::set_type(std::string type)
{
  type_ = type;
}
