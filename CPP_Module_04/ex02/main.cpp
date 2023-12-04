#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
  Dog dog;
  Dog dog2;

  dog.create_idea("Nothing");
  dog.create_idea("Eat bone");
  dog.list_ideas();
  dog.print_addr();
  dog2 = dog;
  dog2.print_addr();
  dog2.list_ideas();
  return EXIT_SUCCESS;
}
