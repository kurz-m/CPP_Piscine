#ifndef PRESIDENTIALPARDONFORM_HPP_
# define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string&);
  PresidentialPardonForm(const PresidentialPardonForm&);
  PresidentialPardonForm& operator=(const PresidentialPardonForm&);
  ~PresidentialPardonForm();

  void  execute(const Bureaucrat&) const;
};

#endif
