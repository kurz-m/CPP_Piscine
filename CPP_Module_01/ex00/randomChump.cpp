#include "Zombie.class.hpp"

void  randomChump(std::string name)
{
  Zombie stack_zombie = Zombie(name);
  stack_zombie.announce();
  return;
}
