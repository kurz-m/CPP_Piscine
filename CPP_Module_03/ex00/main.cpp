#include "ClapTrap.hpp"

int main()
{
  ClapTrap trap = ClapTrap("Herbert");
  ClapTrap part = ClapTrap("NoDMG");

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

  part.take_damage(10);
  part.attack("what");

  return EXIT_SUCCESS;
}
