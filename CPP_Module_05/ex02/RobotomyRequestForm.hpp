#ifndef ROBOTOMYREQUESTFORM_HPP_
# define ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string&);
  RobotomyRequestForm(const RobotomyRequestForm&);
  RobotomyRequestForm& operator=(const RobotomyRequestForm&);
  ~RobotomyRequestForm();

  void  execute(const Bureaucrat&) const;
};

#endif
