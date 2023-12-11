#include "AMateria.hpp"
#include "utils.hpp"

AMateria::AMateria() : type_("default") {}

AMateria::AMateria(const std::string& type) : type_(type) {}

AMateria::AMateria(const AMateria& rhs) : type_(rhs.type_) {}

AMateria& AMateria::operator=(const AMateria& rhs)
{
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

AMateria::~AMateria() {}

const std::string AMateria::get_type() const
{
  return type_;
}

void  AMateria::use(ICharacter&)
{
  log_level("Cannot use abstract 'use' function", RED, ERROR);
}
