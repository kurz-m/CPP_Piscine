#include "RobotomyRequestForm.hpp"
#include "utils.hpp"

RobotomyRequestForm::RobotomyRequestForm()
  : AForm("RobotomyRequestForm", false, 72, 45, "default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
  : AForm("RobotomyRequestForm", false, 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
  : AForm(rhs) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
  AForm::operator=(rhs);
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void  RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
  std::srand(std::time(NULL));

  check_form_(executor);
  log_level("***whirr whirr, drr-drr-drr, clang-clang***", INFO);
  if (std::rand() % 2 == 1) {
    log_level(std::string(target_ + " has been robotomized."), INFO);
  }
  else {
    log_level("Robotomy has been failed.", INFO);
  }
}
