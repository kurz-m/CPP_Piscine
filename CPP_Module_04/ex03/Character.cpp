#include "Character.hpp"
#include "utils.hpp"

Character::Character() : name_("Yoda"), trash_idx_(0)
{
  for (int i = 0; i < bag_size_; i++) {
    bag_[i] = NULL;
    trash_[i] = NULL;
  }
}

Character::Character(const std::string& name) : name_(name), trash_idx_(0)
{
  for (int i = 0; i < bag_size_; i++) {
    bag_[i] = NULL;
    trash_[i] = NULL;
  }
}

Character::Character(const Character& rhs)
{
  for (int i = 0; i < bag_size_; i++) {
    bag_[i] = NULL;
    trash_[i] = NULL;
  }
  *this = rhs;
}

Character& Character::operator=(const Character& rhs)
{
  if (this != &rhs) {
    name_ = rhs.name_;
    trash_idx_ = rhs.trash_idx_;
    for (int i = 0; i < bag_size_; i++) {
      if (bag_[i] != NULL) {
        delete bag_[i];
        bag_[i] = NULL;
      }
      if (rhs.bag_[i] != NULL) {
        bag_[i] = rhs.bag_[i]->clone();
      }
    }
  }
  return *this;
}

Character::~Character()
{
  for (int i = 0; i < bag_size_; i++) {
    if (bag_[i] != NULL) {
      delete bag_[i];
    }
    if (trash_[i] != NULL) {
      delete trash_[i];
    }
  }
}

const std::string& Character::get_name() const
{
  return name_;
}

void  Character::equip(AMateria *materia)
{
  if (materia == NULL) {
    log_level("Materia is NULL.", RED, ERROR);
    return;
  }
  for (int i = 0; i < bag_size_; i++) {
    if (bag_[i] == NULL) {
      bag_[i] = materia;
      return;
    }
  }
  log_level("Bag is full!", MAGENTA, DEBUG);
}

void  Character::unequip(int idx)
{
  if (idx > bag_size_ - 1 || idx < 0) {
    log_level("Not a valid index!", MAGENTA, DEBUG);
    return;
  }
  if (bag_[idx] != NULL) {
    discard_materia_(bag_[idx]);
    bag_[idx] = NULL;
  }
}

void  Character::discard_materia_(AMateria* materia)
{
  if (trash_idx_ < bag_size_) {
    trash_[trash_idx_++] = materia;
    return;
  }
  trash_idx_ = 0;
  delete trash_[trash_idx_];
  trash_[trash_idx_] = materia;

}

void  Character::use(int idx, ICharacter& target)
{
  if (idx > bag_size_ - 1 || idx < 0) {
    log_level("Not a valid index!", MAGENTA, DEBUG);
    return;
  }
  if (bag_[idx] != NULL) {
    bag_[idx]->use(target);
  }
}
