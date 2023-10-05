#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>
#include <cstdlib>
#include <iostream>

class Weapon {
public:
  Weapon();
  Weapon(std::string type);
  ~Weapon();

  const std::string&  get_type() const;
  void  set_type(const std::string type);

private:
  std::string   type_;
};

#endif
