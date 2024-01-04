#include "Bureaucrat.hpp"
#include "utils.hpp"

void  test_regular()
{
  log_level("Just a regular bureaucrat.", TEST);
  Bureaucrat  mand("perfect bureaucrat", 10);

  std::cout << mand;
}

void  test_low_grade()
{
  log_level("Instantiate a bureaucrat with a too low grade.", TEST);
  Bureaucrat  low("low grade", 160);

  std::cout << low;
}

void  test_high_grade()
{
  log_level("Instantiate a bureaucrat with a too high grade.", TEST);
  Bureaucrat  high("high grade", 0);

  std::cout << high;
}

void  test_improve_grade()
{
  log_level("Improve the grade of the bureaucrat.", TEST);
  Bureaucrat  regular("narcissimus", 2);

  std::cout << regular;
  regular.improve_grade();
  std::cout << regular;
  regular.improve_grade();
}

int main()
{
  test_regular();
  try {
    test_low_grade();
  }
  catch (std::exception& e) {
    log_level("Caught exception.", ERROR);
    std::cout << e.what() << std::endl;
  }
  try {
    test_high_grade();
  }
  catch (std::exception& e) {
    log_level("Caught exception.", ERROR);
    std::cout << e.what() << std::endl;
  }
  try {
    test_improve_grade();
  }
  catch (std::exception& e) {
    log_level("Caught exception.", ERROR);
    std::cout << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
