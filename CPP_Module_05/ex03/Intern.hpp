#ifndef INTERN_HPP_
# define INTERN_HPP_

#include "AForm.hpp"

class Intern {
public:
  Intern();
  Intern(const Intern&);
  Intern& operator=(const Intern&);
  ~Intern();

  AForm*  make_form(const std::string&, const std::string&);
};

#endif
