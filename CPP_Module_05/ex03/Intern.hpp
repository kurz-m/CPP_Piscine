#ifndef INTERN_HPP_
# define INTERN_HPP_

#include "AForm.hpp"

class Intern {
public:
  Intern();
  Intern(const Intern&);
  Intern& operator=(const Intern&);
  ~Intern();

  AForm*  make_form(const std::string&, const std::string&) const;

private:
  enum form_type {
    PRESIDENT,
    ROBOTOMY,
    SHRUBBERY,
    NUM_FORMS
  };

  typedef AForm*  (*FormCreator)(const std::string&);
  static AForm* create_presidential_form_(const std::string& target);
  static AForm* create_robotomy_form_(const std::string& target);
  static AForm* create_shrubbery_form_(const std::string& target);

  static const std::string form_specifiers_[NUM_FORMS];
  static const FormCreator creation_functions_[NUM_FORMS];
};

#endif
