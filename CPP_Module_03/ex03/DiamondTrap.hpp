#ifndef CLASS_DiamondTrap_HPP_
# define CLASS_DiamondTrap_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap();
  DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& rhs);
  DiamondTrap& operator=(const DiamondTrap& rhs);
  ~DiamondTrap();

  void  attack(const std::string& target);
  void  who_am_I();

private:
  std::string name_;
};

#endif
