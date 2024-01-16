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


void  test_robotomy_form()
{
  log_level("Intern creates robotomy form.", TEST);
  Intern  task_juggler;
  AForm*  form;
  Bureaucrat  manny("Manny", 4);

  form = task_juggler.make_form("robotomy request", "någon");
  manny.sign_form(*form);
  manny.execute_form(*form);
  delete form;
}

void  test_shrubbery_form()
{
  log_level("Intern creates shrubbery form.", TEST);
  Intern  task_juggler;
  AForm*  form;
  Bureaucrat  manny("Manny", 4);

  form = task_juggler.make_form("shrubbery creation", "någon");
  manny.sign_form(*form);
  manny.execute_form(*form);
  delete form;
}

void  test_non_existing_form()
{
  log_level("Intern tries to create non-existing form.", TEST);
  Intern  task_juggler;
  AForm*  form;
  Bureaucrat  manny("Manny", 4);

  try {
    form = task_juggler.make_form("do not know", "någon");
    manny.sign_form(*form);
    manny.execute_form(*form);
    delete form;
  }
  catch (const std::invalid_argument& e) {
    log_level(std::string("Intern says: ") + e.what(), ERROR);
  }
}

int main()
{
  test_president_form();

  test_robotomy_form();

  test_shrubbery_form();

  test_non_existing_form();

  return EXIT_SUCCESS;
}
