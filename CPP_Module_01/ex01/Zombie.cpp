#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie(void)
{
  std::cout << name_ << " died." << std::endl;
  return;
}

void  Zombie::announce(void)
{
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void  Zombie::set_name(std::string name)
{
  name_ = name;
  return;
}
