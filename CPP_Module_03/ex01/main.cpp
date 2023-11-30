#include "ScavTrap.hpp"

int main()
{
  {
    ScavTrap part = ScavTrap("Dieter");

    part.attack("HP");
    part.take_damage(30);
    part.be_repaired(4);
    part.attack("Forest");
    part.guard_gate();
    part.take_damage(74);
    part.attack("Nothing");
  }

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
}



  return EXIT_SUCCESS;
}
