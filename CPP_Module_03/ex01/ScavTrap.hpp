#ifndef CLASS_SCAVTRAP_HPP_
# define CLASS_SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& rhs);
  ScavTrap& operator=(const ScavTrap& rhs);
  ~ScavTrap();

  void  attack(const std::string& target);
  void  guard_gate();

private:
  bool guard_state_;
};

#endif
