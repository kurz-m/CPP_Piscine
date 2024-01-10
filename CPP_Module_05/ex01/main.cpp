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

void  test_low_grade()
{
  log_level("Bureaucrat cannot sign form.", TEST);
  Bureaucrat  low("Narcissist", 100);
  Form  best("Form a1", false, 1, 1);

  std::cout << low;
  std::cout << best;
  low.sign_form(best);
}

void  test_wrong_low_form()
{
  Bureaucrat  generic("generic", 42);
  Form  wrong("Form e42", false, 170, 170);
}

void  test_wrong_high_form()
{
  Bureaucrat  generic("generic", 42);
  Form  wrong("Form e42", false, 0, 170);
}

int main()
{
  test_regular();

  test_low_grade();

  try {
    test_wrong_low_form();
  }
  catch (std::exception& e) {
    log_level("Caught form exception.", ERROR);
    std::cout << e.what() << std::endl;
  }

  try {
    test_wrong_high_form();
  }
  catch (std::exception& e) {
    log_level("Caught form exception.", ERROR);
    std::cout << e.what() << std::endl;
  }
//   try {
//     test_high_grade();
//   }
//   catch (std::exception& e) {
//     log_level("Caught exception.", ERROR);
//     std::cout << e.what() << std::endl;
//   }
//   try {
//     test_improve_grade();
//   }
//   catch (std::exception& e) {
//     log_level("Caught exception.", ERROR);
//     std::cout << e.what() << std::endl;
//   }
  return EXIT_SUCCESS;
}
