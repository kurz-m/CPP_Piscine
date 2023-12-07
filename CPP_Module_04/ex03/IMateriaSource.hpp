#ifndef IMATERIASOURCE_HPP_
# define IMATERIASOURCE_HPP_

#include <string>
#include "AMateria.hpp"

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  virtual void  learn_materia(AMateria*) = 0;
  virtual AMateria* create_materia(const std::string& type) = 0;
};

#endif
