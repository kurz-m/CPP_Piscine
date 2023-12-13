#include "Cure.hpp"
#include "utils.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& rhs) : AMateria(rhs) {}

Cure&  Cure::operator=(const Cure&) { return *this; }

Cure::~Cure() {}

Cure*  Cure::clone() const
{
  return new Cure();
}

void  Cure::use(ICharacter& target)
{
  std::string str("* heals " + target.get_name() + "'s wounds *");
  std::cout << GREEN << str << RESET << std::endl;
}
