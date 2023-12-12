#include "Ice.hpp"
#include "utils.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& rhs) : AMateria(rhs) {}

Ice&  Ice::operator=(const Ice&) { return *this; }

Ice::~Ice() {}

Ice*  Ice::clone() const
{
  return new Ice();
}

void  Ice::use(ICharacter& target)
{
  std::string str("* shoots an ice bolt at " + target.get_name() + " *");
  std::cout << BLUE << str << RESET << std::endl;
}
