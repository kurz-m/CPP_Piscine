#include "templates.hpp"
#include <iostream>
#include "utils.hpp"

void test_swap_int()
{
  log_level("Swapping integers", TEST);
  int a = -42;
  int b = 125;

  log_level(std::string(
        "Before: a = " + std::to_string(a)
        + ", b = " + std::to_string(b) + "."),
      INFO);

  swap<int>(a, b);

  log_level(std::string(
        "After: a = " + std::to_string(a)
        + ", b = " + std::to_string(b) + "."),
      INFO);

}

void test_min_max_int()
{

  log_level("Test min and max function for integers", TEST);
  int a = -42;
  int b = 125;

  log_level(std::string(
        "Values: a = " + std::to_string(a)
        + ", b = " + std::to_string(b) + "."),
      INFO);

  log_level(std::string( "min(a,b) => " + std::to_string(min(a,b))), INFO);
  log_level(std::string( "max(a,b) => " + std::to_string(max(a,b))), INFO);
}

void test_swap_string()
{
  log_level("Swapping strings", TEST);

  std::string a = "chaine1";
  std::string b = "chaine2";

  log_level(std::string(
        "Before: a = " + a
        + ", b = " + b + "."),
      INFO);

  swap(a, b);

  log_level(std::string(
        "After: a = " + a
        + ", b = " + b + "."),
      INFO);
}

void test_min_max_string()
{

  log_level("Test min and max function for strings", TEST);
  std::string a = "chaine1";
  std::string b = "chaine2";

  log_level(std::string(
        "Values: a = " + a
        + ", b = " + b + "."),
      INFO);

  log_level(std::string( "min(a,b) => " + ::min(a,b)), INFO);
  log_level(std::string( "max(a,b) => " + ::max(a,b)), INFO);
}

int main( void )
{
  test_swap_int();

  test_min_max_int();

  test_swap_string();

  test_min_max_string();

  return 0;
}
