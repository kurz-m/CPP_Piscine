#ifndef ZOMBIE_CLASS_HPP_
#define ZOMBIE_CLASS_HPP_

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie {
public:
  Zombie(std::string name);
  ~Zombie(void);

  void announce() const;

private:
  const std::string name_;
};

const Zombie* newZombie(const std::string name);
void  randomChump(const std::string name);

#endif
