#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"

void  test_president_form()
{
  log_level("Intern creates presidential form.", TEST);
  Intern  task_juggler;
  AForm*  form;
  Bureaucrat  manny("Manny", 4);

  form = task_juggler.make_form("presidential pardon", "någon");
  manny.sign_form(*form);
  manny.execute_form(*form);
  delete form;
}

int main()
{
  test_president_form();

  return EXIT_SUCCESS;
}
