#include "Dog.hpp"
#include "Cat.hpp"

// int main()
// {
//   Dog dog;
//   Dog dog2;
// 
//   dog.create_idea("Nothing");
//   dog.create_idea("Eat bone");
//   dog.list_ideas();
//   dog.print_addr();
//   dog2 = dog;
//   dog2.print_addr();
//   dog2.list_ideas();
//   return EXIT_SUCCESS;
// }

int main()
{
  Animal* horde[10];
  int i = 0;

  while (i < 5) {
    horde[i++] = new Dog;
  }

  while (i < 10) {
    horde[i++] = new Cat;
  }
  i = 0;
  while (i < 10) {
    horde[i]->make_sound();
    delete horde[i++];
  }

  return EXIT_SUCCESS;
}
