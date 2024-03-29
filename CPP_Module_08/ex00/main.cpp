#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <string>

void  print_test_name(const std::string& test_name)
{
  std::cout << "[TEST] " << test_name << "\n";
}

void  test_find_vector()
{
  print_test_name("Find number in vector.");
  int nums[] = {8, 4, 5, 9};
  std::vector<int>::iterator  result;
  std::vector<int> v(nums, nums + sizeof(nums) / sizeof(nums[0]));

  result = easyfind(v, 5);
  int pos = std::distance(v.begin(), result);

  std::cout << "Number " << *result
            << " was found at position " << pos + 1
            << " of the vector v: ";

  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << "\n\n";
}

void  test_not_found_vector()
{
  print_test_name("Number not found in vector.");
  int nums[] = {8, 4, 5, 9};
  std::vector<int>::iterator  result;
  std::vector<int> v(nums, nums + sizeof(nums) / sizeof(nums[0]));

  std::cout << "Try to find number 42 in the vector v: ";
  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << "\n";
  try {
    result = easyfind(v, 42);
  }
  catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n\n";
  }
}

void  test_find_list()
{
  print_test_name("Find number in list.");
  int nums[] = {42, 4, 5, 9};
  std::list<int>::iterator  result;
  std::list<int> l(nums, nums + sizeof(nums) / sizeof(nums[0]));

  result = easyfind(l, 42);
  int pos = std::distance(l.begin(), result);

  std::cout << "Number " << *result
            << " was found at position " << pos + 1
            << " of the list l: ";
  
  for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << "\n\n";
}

void  test_not_found_list()
{
  print_test_name("Number not found in list.");
  int nums[] = {8, 4, 5, 9};
  std::list<int>::iterator  result;
  std::list<int> l(nums, nums + sizeof(nums) / sizeof(nums[0]));

  std::cout << "Try to find number 42 in the list l: ";
  for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << "\n";
  try {
    result = easyfind(l, 42);
  }
  catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n\n";
  }
}

int main()
{
  test_find_vector();

  test_not_found_vector();

  test_find_list();

  test_not_found_list();

  return EXIT_SUCCESS;
}
