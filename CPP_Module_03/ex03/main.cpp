#include "DiamondTrap.hpp"

int main()
{
  DiamondTrap one = DiamondTrap("Herbert");
  DiamondTrap two;

  two = one;
  one.attack("Spaceship");
  two.ClapTrap::attack("Yoda");
  one.be_repaired(4);

  return EXIT_SUCCESS;
}
