#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <iostream>
#include <string>

class Zombie {
public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie(void);

  void  set_name(std::string name);
  void  announce(void) const;

private:
  std::string name_;
};

Zombie  *zombieHorde(int N, std::string);

#endif
