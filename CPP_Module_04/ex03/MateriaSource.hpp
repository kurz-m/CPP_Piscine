#ifndef MATERIASOURCE_HPP_
# define MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(const MateriaSource&);
  MateriaSource& operator=(const MateriaSource&);
  virtual ~MateriaSource();

  void  learn_materia(AMateria* materia);
  AMateria* create_materia(const std::string& type);

private:
  enum {max_templates_ = 4};
  AMateria* templates_[max_templates_];
};

#endif
