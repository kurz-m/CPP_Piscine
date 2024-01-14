#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"

void  test_president_regular()
{
  log_level("Successful pardoning.", TEST);
  PresidentialPardonForm  p_form("Billy");
  Bureaucrat  president("Nixon", 4);

  president.sign_form(p_form);
  president.execute_form(p_form);
}

void  test_president_unsigned()
{
  log_level("Not signed pardoning.", TEST);
  PresidentialPardonForm  p_form("Alien");
  Bureaucrat  president("Trump", 15);

  president.execute_form(p_form);
}

void  test_robotomy_regular()
{
  log_level("Signed robotomy.", TEST);
  RobotomyRequestForm  r_form("C3PO");
  Bureaucrat  luke("Luke", 4);

  luke.sign_form(r_form);
  luke.execute_form(r_form);
}

void  test_robotomy_unsigned()
{
  log_level("Signed robotomy.", TEST);
  RobotomyRequestForm  r_form("R2D2");
  Bureaucrat  jabba("Jabba", 10);

  jabba.execute_form(r_form);
}

void  test_shrubbery_regular()
{
  log_level("Successful shrubbery.", TEST);
  ShrubberyCreationForm  s_form("Tree");
  Bureaucrat  builder("Builder", 4);

  builder.sign_form(s_form);
  builder.execute_form(s_form);
}

void  test_shrubbery_unsigned()
{
  log_level("Not signed shrubbery.", TEST);
  ShrubberyCreationForm  s_form("Stud");
  Bureaucrat  president("Trump", 50);

  president.execute_form(s_form);
}


int main()
{
  test_president_regular();

  test_president_unsigned();

  test_robotomy_regular();

  test_robotomy_unsigned();

  test_shrubbery_regular();

  test_shrubbery_unsigned();

  return EXIT_SUCCESS;
}
