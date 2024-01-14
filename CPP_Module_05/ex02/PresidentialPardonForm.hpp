#ifndef PRESIDENTIALPARDONFORM_HPP_
# define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string&, bool, unsigned int, unsigned int);
  PresidentialPardonForm(const PresidentialPardonForm&);
  PresidentialPardonForm& operator=(const PresidentialPardonForm&);
  ~PresidentialPardonForm();

private:
  const std::string target_;
};

#endif
