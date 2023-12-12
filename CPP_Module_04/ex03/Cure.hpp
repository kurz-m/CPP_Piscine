#ifndef CURE_HPP_
# define CURE_HPP_

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const std::string& type);
  Cure(const Cure&);
  Cure& operator=(const Cure&);
  virtual ~Cure();

  virtual Cure* clone() const;
  virtual void  use(ICharacter& target);
};

#endif
