#include "Zombie.hpp"

void  randomChump(std::string name)
{
  Zombie stack_zombie = Zombie(name);
  stack_zombie.announce();
  return;
}
