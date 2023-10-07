#include "Zombie.hpp"

int main(void) {
  const Zombie* heap_zombie_a;
  const Zombie* heap_zombie_b;

  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "         Creating zombies on the stack           " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  randomChump("Stack zombie 1");
  randomChump("Stack zombie 2");
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "         Creating a zombie on the heap           " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  heap_zombie_a = newZombie("First heap zombie");
  heap_zombie_a->announce();
  heap_zombie_b = newZombie("Second heap zombie");
  heap_zombie_b->announce();
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "         Deleting zombies on the heap            " << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  delete heap_zombie_a;
  delete heap_zombie_b;
  return EXIT_SUCCESS;
}
