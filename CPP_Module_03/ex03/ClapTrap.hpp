#ifndef CLASS_CLAPTRAP_HPP_
# define CLASS_CLAPTRAP_HPP_

#include <iostream>
#include <cstdlib>

class ClapTrap {
public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const std::string& name, int, int, int);
  ClapTrap(const ClapTrap& rhs);
  ClapTrap& operator=(const ClapTrap& rhs);
  ~ClapTrap();

  void  attack(const std::string& target);
  void  take_damage(unsigned int amount);
  void  be_repaired(unsigned int amount);

protected:
  std::string name_;
  int hit_points_;
  int energy_points_;
  int attack_dmg_;
};

#endif
