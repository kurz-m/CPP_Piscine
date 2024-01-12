#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "utils.hpp"

void  test_regular()
{
  log_level("Just a regular bureaucrat.", TEST);
  Bureaucrat  mand("regular bureaucrat", 10);
  Form  yep("Form t20", false, 20, 20);

  std::cout << yep;
  std::cout << mand;
  try {
    yep.be_signed(mand);
  }
  catch (std::exception &e) {
    log_level("Caught exception.", ERROR);
    std::cout << e.what() << std::endl;
  }
  log_level("Signing form.", INFO);
  std::cout << yep;
}

void  test_bureaucrat_signing()
{
  log_level("Bureaucrat member function 'sign_form'.", TEST);
  Bureaucrat  norm("Narcissist", 10);
  Form  generic("Form g42", false, 10, 10);

  std::cout << norm;
  std::cout << generic;
  norm.sign_form(generic);
  std::cout << generic;
}

void  test_low_grade()
{
  log_level("Bureaucrat cannot sign form.", TEST);
  Bureaucrat  low("Narcissist", 100);
  Form  best("Form a1", false, 1, 1);

  std::cout << low;
  std::cout << best;
  low.sign_form(best);
}

void  test_low_sign_form()
{
  log_level("Sign grade of Form is to low.", TEST);
  Bureaucrat  generic("generic", 42);
  Form  wrong("Form e42", false, 170, 42);
}

void  test_high_sign_form()
{
  log_level("Sign grade of Form is to high.", TEST);
  Bureaucrat  generic("generic", 42);
  Form  wrong("Form e42", false, 0, 42);
}

void  test_low_execution_form()
{
  log_level("Sign grade of Form is to low.", TEST);
  Bureaucrat  generic("generic", 42);
  Form  wrong("Form e42", false, 42, 170);
}

void  test_high_execution_form()
{
  log_level("Execution grade of Form is to high", TEST);
  Bureaucrat  generic("generic", 42);
  Form  wrong("Form e42", false, 42, 0);
}

int main()
{
  log_level_color("Start testing!\n", MAGENTA, INFO);
  test_regular();

  test_low_grade();

  test_bureaucrat_signing();

  try {
    test_low_sign_form();
  }
  catch (std::exception& e) {
    log_level("Caught form exception.", ERROR);
    std::cout << e.what() << std::endl;
  }

  try {
    test_high_sign_form();
  }
  catch (std::exception& e) {
    log_level("Caught form exception.", ERROR);
    std::cout << e.what() << std::endl;
  }

  try {
    test_low_execution_form();
  }
  catch (std::exception& e) {
    log_level("Caught form exception.", ERROR);
    std::cout << e.what() << std::endl;
  }

  try {
    test_high_execution_form();
  }
  catch (std::exception& e) {
    log_level("Caught form exception.", ERROR);
    std::cout << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
