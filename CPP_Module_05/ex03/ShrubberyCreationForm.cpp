#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
  : AForm("ShrubberyCreationForm", false, 25, 5, "default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
  : AForm("ShrubberyCreationForm", false, 25, 5, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
  : AForm(rhs) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
  AForm::operator=(rhs);
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string ShrubberyCreationForm::tree_ = "    /\\\n"
                                                 "   /  \\\n"
                                                 "  /    \\\n"
                                                 " /      \\\n"
                                                 "/________\\\n"
                                                 "   ||||\n"
                                                 "   ||||\n"
                                                 "   ||||";


void  ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
  check_form_(executor);

  std::ofstream ostrm(std::string(target_ + "_shrubbery").c_str());
  if (ostrm.fail() == true) {
    std::cout << std::string("Could not open the file: " + target_) << std::endl;
    return;
  }
  ostrm << tree_ << std::endl;
  ostrm.close();
  log_level(std::string("Tree art is in " + target_ + "_shrubbery"), INFO);
}
