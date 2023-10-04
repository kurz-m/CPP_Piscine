#pragma once

#include <iostream>
#include <string>

class Zombie {
public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie(void);

  void  set_name(std::string name);
  void  announce(void);

private:
  std::string name_;
};

Zombie  *zombieHorde(int N, std::string);
