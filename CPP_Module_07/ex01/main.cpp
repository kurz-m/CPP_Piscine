#include "iter.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include "utils.hpp"

void  to_upper(std::string& s)
{
  std::string::iterator   it;

  for (it = s.begin(); it != s.end(); it++) {
    *it = std::toupper(static_cast<unsigned char>(*it));
  }
}

void  times_two(int& n)
{
  n <<= 1;
}

void  rotone(char& c)
{
  if (std::isalpha(c) != 0) {
    (c >= 'A' && c < 'Z') || (c >= 'a' && c < 'z') ?
      c += 1 : (c == 'Z' || c == 'z') ? c -= 25 : c;
  }
}

void  test_with_strings()
{
  std::string array[] = {
    "SoMething wEird",
    "test",
    "Numbers!",
  };

  log_level("std::string with to_upper function.", TEST);
  log_level("Before using function:", INFO);

  for (size_t i = 0; i < 3; ++i) {
    std::cout << array[i] << "\n";
  }


  iter(array, 3, to_upper);

  log_level("After using function:", INFO);

  for (size_t i = 0; i < 3; ++i) {
    std::cout << array[i] << "\n";
  }
}

void  test_times_two()
{
  int array[] = {
    4,
    1,
    25,
  };

  log_level("int with square function.", TEST);
  log_level("Before using function:", INFO);

  for (size_t i = 0; i < 3; ++i) {
    std::cout << array[i] << "\n";
  }

  iter(array, 3, times_two);

  log_level("After using function:", INFO);

  for (size_t i = 0; i < 3; ++i) {
    std::cout << array[i] << "\n";
  }
}

void  test_rotone()
{
  char array[] = {
    'a',
    'z',
    '5',
  };

  log_level("char with rotone function.", TEST);
  log_level("Before using function", INFO);

  for (size_t i = 0; i < 3; ++i) {
    std::cout << array[i] << "\n";
  }


  iter(array, 3, rotone);

  log_level("After using function:", INFO);

  for (size_t i = 0; i < 3; ++i) {
    std::cout << array[i] << "\n";
  }
}

int main()
{
  test_with_strings();

  test_times_two();

  test_rotone();

  return EXIT_SUCCESS;
}
