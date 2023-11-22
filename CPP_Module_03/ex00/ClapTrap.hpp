#ifndef CLASS_CLAPTRAP_HPP_
# define CLASS_CLAPTRAP_HPP_

#include <iostream>
#include <cstdlib>

#define NO_ENERGY 0
#define NO_HIT 1

class ClapTrap {
public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& rhs);
  ClapTrap& operator=(const ClapTrap& rhs);
  ~ClapTrap();

  void  attack(const std::string& target);
  void  take_damage(unsigned int amount);
  void  be_repaired(unsigned int amount);


private:
  std::string name_;
  int32_t hit_points_;
  int32_t energy_points_;
  int32_t attack_dmg_;
};

#endif
