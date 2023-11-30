#ifndef CLASS_FRAGTRAP_HPP_
# define CLASS_FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& rhs);
  FragTrap& operator=(const FragTrap& rhs);
  ~FragTrap();

  void  high_five_guys();

};

#endif
