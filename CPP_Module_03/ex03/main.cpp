#include "DiamondTrap.hpp"

int main()
{
  DiamondTrap one("Herbert");
  DiamondTrap two;

  two = one;
  one.who_am_I();
  one.attack("Spaceship");
  two.ClapTrap::attack("Yoda");
  one.be_repaired(4);
  one.high_five_guys();
  two.high_five_guys();

  one.who_am_I();

  return EXIT_SUCCESS;
}
