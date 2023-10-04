#include "Zombie.class.hpp"

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie(void)
{
  std::cout << this->name_ << " died again." << std::endl;
  return;
}

void  Zombie::announce(void)
{
  std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
