#include "PresidentialPardonForm.hpp"
#include "utils.hpp"

PresidentialPardonForm::PresidentialPardonForm()
  : AForm("PresidentialPardonForm", false, 25, 5, "default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : AForm("PresidentialPardonForm", false, 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
  : AForm(rhs) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
  AForm::operator=(rhs);
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void  PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
  check_form_(executor);
  log_level(std::string(target_ + " has been pardoned by Zaphod Beeblebrox."), INFO);
}
