#ifndef ZOMBIE_CLASS_HPP_
#define ZOMBIE_CLASS_HPP_

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie {
public:
  Zombie(std::string name);
  ~Zombie(void);

  void  announce(void);

private:
  std::string  name_;
};

Zombie* newZombie(std::string name);
void  randomChump(std::string name);

#endif
