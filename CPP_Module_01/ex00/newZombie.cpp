#include "Zombie.hpp"

const Zombie* newZombie(const std::string name) {
  const Zombie*  heap_zombie = new Zombie(name);
  return heap_zombie;
};
