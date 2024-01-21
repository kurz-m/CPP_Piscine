#include "easyfind.hpp"
#include <vector>
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
            << " was found at position " << pos
            << " of the vector v.\n\n";
}

void  test_not_found()
{
  print_test_name("Number not found in vector.");
  int nums[] = {8, 4, 5, 9};
  std::vector<int>::iterator  result;
  std::vector<int> v(nums, nums + sizeof(nums) / sizeof(nums[0]));

  try {
    result = easyfind(v, 42);
  }
  catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n\n";
  }
}

int main()
{
  test_find_vector();

  test_not_found();
  return EXIT_SUCCESS;
}
