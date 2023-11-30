#include "FragTrap.hpp"

int main()
{
  {
    FragTrap part = FragTrap("Dieter");
    FragTrap assignee;

    assignee = part;

    assignee.attack("omg Dieter");
    assignee.take_damage(110);
    assignee.be_repaired(20);

    part.attack("HP");
    part.take_damage(30);
    part.be_repaired(4);
    part.attack("Forest");
    part.take_damage(74);
    part.attack("Nothing");
  }

  {

  }



  return EXIT_SUCCESS;
}
