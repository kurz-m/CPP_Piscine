#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
  : name_("default"),
    hit_points_(10),
    energy_points_(10),
    attack_dmg_(0)
{
  std::cout << "ClapTrap default constructor called: " << name_ << std::endl; 
}

ClapTrap::ClapTrap(const std::string& name)
  : name_(name),
    hit_points_(10),
    energy_points_(10),
    attack_dmg_(0)
{
  std::cout << "ClapTrap string constructor called: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
  : name_(rhs.name_),
    hit_points_(rhs.hit_points_),
    energy_points_(rhs.energy_points_),
    attack_dmg_(rhs.attack_dmg_)
{
  std::cout << "ClapTrap copy constructor called: " << rhs.name_ << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
  std::cout << "ClapTrap copy assignment operator called: " << rhs.name_ << std::endl;
  if (this != &rhs) {
    name_ = rhs.name_;
    hit_points_ = rhs.hit_points_;
    energy_points_ = rhs.energy_points_;
    attack_dmg_ = rhs.attack_dmg_;
  }
  return *this;
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap destructor called: " << name_ << std::endl;
}

void  ClapTrap::attack(const std::string &target)
{
  unsigned short check = hit_points_ <= 0 ? 0 : energy_points_ <= 0 ? 1 : 2;

  switch (check) {
  case 0:
    std::cout << "ClapTrap " << name_
              << " wants to attack, but"
              << " does not live anymore.\n";
    break;
  case 1:
    std::cout << "ClapTrap " << name_
              << " has no energy left to attack.\n";
    break;
  default:
    --energy_points_;
    std::cout << "ClapTrap " << name_ << " attacks " << target
              << " causing " << attack_dmg_ << " dmg.\n"
              << name_ << " has " << energy_points_ << " energy left.\n"
              << std::endl;
    break;
  }
}

void  ClapTrap::take_damage(unsigned int amount)
{
  std::cout << name_ << " takes " << amount <<" dmg\n";
  hit_points_ -= amount;

  unsigned short check = hit_points_ <= 0 ? 0 : 1;

  switch (check) {
  case 0:
    std::cout << "ClapTrap " << name_ << " has no hitpoints left.\n"
              << std::endl;
    break;
  case 1:
    std::cout << "ClapTrap " << name_ << " has " << hit_points_
              << " hit points left." << std::endl;
    break;
  }
}

void  ClapTrap::be_repaired(unsigned int amount)
{
  unsigned short check = hit_points_ <= 0 ? 0 : energy_points_ <= 0 ? 1 : 2;

  switch (check) {
  case 0:
  std::cout << "ClapTrap " << name_
            << " wants to attack, but"
            << " does not live anymore.\n";
  break;
  case 1:
    std::cout << "ClapTrap " << name_
              << " has no energy left to repair itself.\n";
    break;
  default:
    --energy_points_;
    hit_points_ += amount;
    std::cout << "ClapTrap " << name_ << " repairs itself for "
              << amount << " points.\n" << "It now has " << hit_points_
              << " hit points and " << energy_points_ << " energy left.\n"
              << std::endl;
    break;
  }
}
