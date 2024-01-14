#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

const std::string Intern::form_specifiers_[NUM_FORMS] = {
  "presidential pardon",
  "robotomy request",
  "shrubbery creation"
};

const Intern::FormCreator Intern::creation_functions_[NUM_FORMS] = {
  &Intern::create_presidential_form_,
  &Intern::create_robotomy_form_,
  &Intern::create_shrubbery_form_
};

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&)
{
  return *this;
}

Intern::~Intern() {}

AForm* Intern::make_form(const std::string& name,
    const std::string& target) const
{
  for (int i = 0; i < NUM_FORMS; i++) {
    if (name == form_specifiers_[i]) {
      return creation_functions_[i](target);
    }
  }
  throw std::invalid_argument("You wanted coffee?");
}

AForm*  Intern::create_presidential_form_(const std::string& target)
{
  return new PresidentialPardonForm(target);
}

AForm*  Intern::create_robotomy_form_(const std::string& target)
{
  return new RobotomyRequestForm(target);
}

AForm*  Intern::create_shrubbery_form_(const std::string& target)
{
  return new ShrubberyCreationForm(target);
}
