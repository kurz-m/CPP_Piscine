#include "iter.hpp"
#include <iostream>
#include <string>
#include <cmath>

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

  std::cout << "[TEST] std::string with to_upper function.\n";
  std::cout << "[INFO] Before using function.\n";

  for (size_t i = 0; i < 3; ++i) {
    std::cout << array[i] << "\n";
  }


  iter(array, 3, to_upper);

  std::cout << "\n[INFO] After using function.\n";

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

  std::cout << "\n[TEST] int with square function.\n";
  std::cout << "[INFO] Before using function.\n";

  for (size_t i = 0; i < 3; ++i) {
    std::cout << array[i] << "\n";
  }

  iter(array, 3, times_two);

  std::cout << "\n[INFO] After using function.\n";

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

  std::cout << "\n[TEST] char with rotone function.\n";
  std::cout << "[INFO] Before using function.\n";

  for (size_t i = 0; i < 3; ++i) {
    std::cout << array[i] << "\n";
  }


  iter(array, 3, rotone);

  std::cout << "\n[INFO] After using function.\n";

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
