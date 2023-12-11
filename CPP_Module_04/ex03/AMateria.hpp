#ifndef AMATERIA_HPP_
# define AMATERIA_HPP_

#include <string>

class ICharacter;

class AMateria {
public:
  AMateria();
  AMateria(const std::string& type);
  AMateria(const AMateria&);
  AMateria& operator=(const AMateria&);
  virtual ~AMateria();

  const std::string get_type() const;
  virtual AMateria* clone() const = 0;
  virtual void  use(ICharacter& target);

protected:
  std::string type_;
};

#endif
