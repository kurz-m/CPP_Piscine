#ifndef SHRUBBERYCREATIONFORM_HPP_
# define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
public:
  ShrubberyCreationForm(const std::string&);
  ShrubberyCreationForm(const ShrubberyCreationForm&);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
  ~ShrubberyCreationForm();

  void  execute(const Bureaucrat&) const;

private:
  ShrubberyCreationForm();

  static const std::string  tree_;
};

#endif
