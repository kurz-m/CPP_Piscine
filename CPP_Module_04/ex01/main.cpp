#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
  Dog dog;

  dog.create_idea("Nothing");
  dog.create_idea("Eat bone");
  dog.list_ideas();
  return EXIT_SUCCESS;
}
