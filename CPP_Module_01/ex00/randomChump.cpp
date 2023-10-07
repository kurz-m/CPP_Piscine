#include "Zombie.hpp"

void  randomChump(const std::string name)
{
  const Zombie stack_zombie = Zombie(name);
  stack_zombie.announce();
  return;
}
