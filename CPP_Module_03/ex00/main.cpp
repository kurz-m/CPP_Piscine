#include "ClapTrap.hpp"

int main()
{
  ClapTrap trap = ClapTrap("Herbert");

  trap.attack("Brunhilde");
  trap.take_damage(3);
  trap.be_repaired(1);
  trap.be_repaired(2);

  trap.attack("Thor");
  trap.take_damage(3);
  trap.be_repaired(1);
  trap.be_repaired(2);

  trap.attack("Backdoor");
  trap.take_damage(3);
  trap.be_repaired(1);
  trap.be_repaired(2);

  trap.attack("Trapdoor");
  trap.take_damage(3);
  trap.be_repaired(1);
  trap.be_repaired(2);

  trap.take_damage(8);

  return EXIT_SUCCESS;
}
