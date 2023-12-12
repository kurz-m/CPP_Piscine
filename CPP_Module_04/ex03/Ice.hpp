#ifndef ICE_HPP_
# define ICE_HPP_

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const std::string& type);
  Ice(const Ice&);
  Ice& operator=(const Ice&);
  virtual ~Ice();

  virtual Ice* clone() const;
  virtual void  use(ICharacter& target);
};

#endif
