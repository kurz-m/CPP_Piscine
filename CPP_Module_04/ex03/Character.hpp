#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character();
  Character(const std::string&);
  Character(const Character&);
  Character&  operator=(const Character&);
  ~Character();

  const std::string& get_name() const;
  void  equip(AMateria* materia);
  void  unequip(int idx);
  void  use(int idx, Character& target);

private:
  enum {bag_size_ = 4};

  void  discard_materia_(AMateria* materia);

  std::string name_;
  AMateria* bag_[bag_size_];
  AMateria* trash_[bag_size_];
  int trash_idx_;
};

#endif
