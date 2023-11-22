#ifndef CLASS_SCAVTRAP_HPP_
# define CLASS_SCAVTRAP_HPP_

#include <iostream>
#include <cstdlib>

class ScavTrap {
public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& rhs);
  ScavTrap& operator=(const ScavTrap& rhs);
  ~ScavTrap();

  void  attack(const std::string& target);
  void  take_damage(unsigned int amount);
  void  be_repaired(unsigned int amount);


private:
  std::string name_;
  int hit_points_;
  int energy_points_;
  int attack_dmg_;
};

#endif

