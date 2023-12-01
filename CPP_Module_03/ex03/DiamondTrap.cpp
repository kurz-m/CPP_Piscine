#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
  : ClapTrap(), ScavTrap(), FragTrap()
{
  hit_points_ = FragTrap::hit_points_;
  energy_points_ = ScavTrap::energy_points_;
  attack_dmg_ = FragTrap::attack_dmg_;
  std::cout << "DiamondTrap default constructor called: " << name_
            << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
  : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
  hit_points_ = FragTrap::hit_points_;
  energy_points_ = ScavTrap::energy_points_;
  attack_dmg_ = FragTrap::attack_dmg_;
  name_ = name;
  ClapTrap::name_ = name + "_clap_name";
  std::cout << "DiamondTrap string constructor called: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
  : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
  *this = rhs;
  std::cout << "DiamondTrap copy constructor called: " << rhs.name_ << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
  std::cout << "DiamondTrap copy assignment operator called: "
            << rhs.name_ << std::endl;
  if (this != &rhs) {
    hit_points_ = rhs.hit_points_;
    energy_points_ = rhs.energy_points_;
    attack_dmg_ = rhs.attack_dmg_;
    name_ = rhs.name_;
    ClapTrap::name_ = rhs.ClapTrap::name_;
  }
  return *this;
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap destructor called: " << name_ << std::endl;
}

void  DiamondTrap::who_am_I()
{
  std::cout << "My real name is " << name_ << ".\n"
            << "ClapTrap's name is " << ClapTrap::name_ << "." <<  std::endl;
}