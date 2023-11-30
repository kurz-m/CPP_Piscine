#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), guard_state_(0)
{
  hit_points_ = 100;
  energy_points_ = 50;
  attack_dmg_ = 20;
  std::cout << "ScavTrap constructor called: " << name_ << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), guard_state_(0)
{
  hit_points_ = 100;
  energy_points_ = 50;
  attack_dmg_ = 20;
  std::cout << "ScavTrap constructor called: " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
  std::cout << "ScavTrap copy assignment operator called: " << rhs.name_ << std::endl;
  if (this != &rhs) {
    name_ = rhs.name_;
    hit_points_ = rhs.hit_points_;
    energy_points_ = rhs.energy_points_;
    attack_dmg_ = rhs.attack_dmg_;
  }
  return *this;
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap destructor called: " << name_ << std::endl;
}

void  ScavTrap::attack(const std::string &target)
{
  unsigned short check = hit_points_ <= 0 || energy_points_ <= 0;
  switch (check) {
    case 1:
      std::cout << "ScavTrap " << name_
                << " has no energy left to attack.\n";
      break;
    default:
      --energy_points_;
      std::cout << "ScavTrap " << name_ << " attacks " << target
                << " causing " << attack_dmg_ << " dmg.\n"
                << name_ << " has " << energy_points_ << " energy left.\n"
                << std::endl;
  }
}

void  ScavTrap::guard_gate()
{
  guard_state_ = 1;
  std::cout << "ScavTrap " << name_ << " is now in gate keeper mode\n";
}