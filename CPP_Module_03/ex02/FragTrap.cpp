#include "FragTrap.hpp"

FragTrap::FragTrap()
  : ClapTrap("default", 100, 100, 30)
{
  std::cout << "FragTrap default constructor called: " << name_ << std::endl;
}

FragTrap::FragTrap(const std::string& name)
  : ClapTrap(name, 100, 100, 30)
{
  std::cout << "FragTrap string constructor called: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs)
{
  hit_points_ = 100;
  energy_points_ = 100;
  attack_dmg_ = 30;
  std::cout << "FragTrap copy constructor called: " << name_ << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
  std::cout << "FragTrap copy assignment operator called: " << rhs.name_ << std::endl;
  if (this != &rhs) {
    name_ = rhs.name_;
    hit_points_ = rhs.hit_points_;
    energy_points_ = rhs.energy_points_;
    attack_dmg_ = rhs.attack_dmg_;
  }
  return *this;
}

FragTrap::~FragTrap()
{
  std::cout << "FragTrap destructor called: " << name_ << std::endl;
}

void  FragTrap::high_five_guys()
{
  std::cout << "FragTrap " << name_ << " is in desparate need of a high five.\n";
}
