#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie(void)
{
  std::cout << name_ << " died again." << std::endl;
  return;
}

void  Zombie::announce() const
{
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
